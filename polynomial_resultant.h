//VAMOS CRIAR UM PROGRAMA PARA COMPUTAR RESULTANTES E DETERMINANTES DE POLINÔMIOS USANDO AS MATRIZES DE SYLVESTER

/*
PARA MAIORES INFORMAÇÕES: A Course In Computational Algebraic Number Theory by Henri Cohen

*/


//******************************************************************************************************
//CABEÇALHO
#ifndef POLYNOMIAL_RESULTANT_H
#define POLYNOMIAL_RESULTANT_H
#include"determinant_gauss_barreis.h"
#include"polynomial_root.h"

//******************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
T polynomial_resultant(polynomial<T>&, polynomial<T>&);

//******************************************************************************************************
//FUNÇÕES
//Função que calcula o discriminante de dois polinômios usando matrizes de Sylvester
template<typename T>
T polynomial_resultant(polynomial<T>& p1, polynomial<T>& p2){

  //Variáveis locais
  Matrix<T> sylvester_matrix;
  T result;
  int64_t c1=p1.polynomial_coefficients.size(), c2=p2.polynomial_coefficients.size(), z1=0, z2=0;
  int64_t sylvester_matrix_size=(p1.degree+p2.degree);
  int64_t i, j, k;

  //Procedimentos
    //Ajuste do tamanho da matriz de Sylvester
    sylvester_matrix.reshape(sylvester_matrix_size, sylvester_matrix_size);

    //Ajuste dos coeficientes da matrizes usando coeficientes do primeiro polinômio
    for(i=0; i<sylvester_matrix_size; ++i){//Linhas
  
      //Condição que determina o fim do preenchimento dos coefiecientes da matriz
      if(z1+c1>sylvester_matrix_size) break;
      k=0;
      
      for(j=0; j<sylvester_matrix_size; ++j){//Colunas
        
        if(j<z1){
          sylvester_matrix.matrix[i][j]=0;
          continue;
        }
        else if(k>=c1) sylvester_matrix.matrix[i][j]=0;  
        else sylvester_matrix.matrix[i][j]=p1.polynomial_coefficients[k];
        ++k;

      }

      //Atualizando variáveis para a próxima iteração
      z1++;

    }


    //Ajuste dos coeficientes da matrizes usando coeficientes do segundo polinômio
    for(; i<sylvester_matrix_size; ++i){//Linhas
  
      //Condição que determina o fim do preenchimento dos coefiecientesda matriz
      if(z2+c2>sylvester_matrix_size) break;
      k=0;
      
      for(j=0; j<sylvester_matrix_size; ++j){//Colunas
        
        if(j<z2){
          sylvester_matrix.matrix[i][j]=0;
          continue;
        }
        else if(k>=c2) sylvester_matrix.matrix[i][j]=0;  
        else sylvester_matrix.matrix[i][j]=p2.polynomial_coefficients[k];
        ++k;

      }

      //Atualizando variáveis para a próxima iteração
      z2++;

    }


    /*Caso se queira mostrar a estrutura da matriz de Sylvester basta remover os símbolos de comentários da linha abaixo*/
    //std::cout<<"\n...\n";   sylvester_matrix.print_matrix(); std::cout<<"\n...\n";


    //Calculando o determinante  da matriz de Sylvester
    result = determinant_gauss_barreis<T>(sylvester_matrix);

  //Resultado
  return result;

};


//******************************************************************************************************
//FIM DO HEADER
#endif
