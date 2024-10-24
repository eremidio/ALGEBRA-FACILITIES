//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO DE GAUSS-BARREIS PARA CALCULAR O DETERMINANTE DE MATRIZES

/*
O ALGORITMO DE GAUSS-BARREIS É UM EFICIENTE ALGORITMO PARA CALCULAR O DETERMINANTE DE MATRIZES COM
VALORES NÚMERICOS OU PARA SE DETERMINAR A MATRIZ EM SUA FORMA ESCALONADA. COMPARADO COM OUTROS
ALGORITMOS SIMILARES O ALGORITMO DE BARREIS (QUE PODE SER CONSIDERADO UMA VARIANTE DA ELIMINAÇÃO
GAUSSIANA) TEM A VANTAGEM DE PERMANECER RESTRITO AO DOMÍNIO DE DEFINIÇÃO DOS COEFICIENTES DA MATRIZ
SENDO PARTICULARMENTE ÚTEIS PARA MATRIZES COM COEFICIENTES INTEIROS. PARA MATRIZES COM COEFICIENTES
REAIS (VALORES APROXIMADOS PARA A ENTRADA) O MÉTODO TEM A VANTAGEM DE NÃO INTRODUZIR ERROS DE
APROXIMAÇÃO.

PARA MAIORES INFORMAÇÕES: A Course In Computational Algebraic Number Theory by Henri Cohen
                          https://en.wikipedia.org/wiki/Bareiss_algorithm
                          https://en.wikipedia.org/wiki/Hadamard%27s_inequality

*/


//******************************************************************************************************************
//CABEÇALHO
#ifndef DETERMINANT_GAUSS_BARREIS_H
#define DETERMINANT_GAUSS_BARREIS_H
#include"matrix.h"

//******************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
T determinant_gauss_barreis(Matrix<T>&);

//******************************************************************************************************************
//FUNÇÕES
//Função que calcula o determinante de uma matriz usando o algoritmo de Gauss-Barreis
template<typename T>
T determinant_gauss_barreis(Matrix<T>& m1){

  //REstrição a matrizes quadradas
  assert(m1.rows= m1.columns);

  //Variáveis locais
  Matrix<T> m2=m1;
  T c=1, p=1, t;
  int64_t k=(-1), s=1, i, j, l;


  //Procedimentos
    //Loop principal: cálculo dos determinantes das submatrizes
    while(k<m1.rows){
    
      //Atualizando variáveis para a próxima iteração    
      k++;

      if(k==(m1.rows-1)) break;
      p=m2.matrix[k][k];
      if(p!=0) goto main_step;


      //Ajuste da Matriz dos coeficientes
      for(l=(k+1); l<k; l++){
        t=m2.matrix[l][k]; //l indexa os elementos a serem invertidos
        if(t!=0) break;
      }

      if(t==0) return 0;//Condição que identfica que duas linhas  da matriz são linearmente dependentes entre si
    
      for(j=k; j<m1.rows; j++){//Invertendo os elementos das duas linhas matriz
        T temp=m2.matrix[l][j];
        m2.matrix[l][j]=m2.matrix[k][j];
        m2.matrix[k][j]=temp;
      }

      s*=(-1);//Permutação de linhas
      p=m2.matrix[k][k];
      
    
      //Cálculo dos elementos das reduzidas da matriz
      main_step:
      
      for(i=(k+1); i<m1.rows; ++i){
        for(j=(k+1); j<m1.rows; ++j){
          t=(p*m2.matrix[i][j])-(m2.matrix[i][k]*m2.matrix[k][j]);
          m2.matrix[i][j]=t/c;

        }    
      }

    //Atualizando variável para a próxima iteração
    c=p;

    }
  

  //Resultado
  return s*m2.matrix[m1.rows-1][m1.rows-1];



};

//******************************************************************************************************************
//FIM DO HEADER
#endif
