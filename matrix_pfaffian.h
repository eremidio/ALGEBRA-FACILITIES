//VAMOS CRIAR UM PROGRAMA QUE CALCULA O PFAFFIANO DE MATRIZES ANTISSÍMÉTRICAS

/*
O PFAFFIANO DE UMA MATRIZ ANTISSIMNÉTRICA É UM POLINÔMIO DAS ENTRADAS DESTA
MATRIZ  E É DENOTADO pf(A). A SEGUINTE RELAÇÃO É VÁLIDA PARA UMA MATRIZ
ANTISSIMÉTRICA A: {pf(A)}²=det(A).

PFAFFIANOS SÃO MUITOS UTÉIS EM PROBLEMAS DE ANÁLISE COMBINATÓRIA, TEORIA DE
GRAFOS E GEOMETRIA DIFERENCIAL.


PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Pfaffian#Applications
                          https://en.wikipedia.org/wiki/Heaviside_step_function
                          https://www.sciencedirect.com/science/article/pii/S0001870885710298?via%3Dihub
                          https://math.stackexchange.com/questions/2133221/numerical-calculation-of-pfaffian


*/


//******************************************************************************
//CABEÇALHO
#ifndef MATRIX_PFAFFIAN_H
#define MATRIX_PFAFFIAN_H
#include"matrix.h"


//******************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
bool is_skew_symetric(Matrix<T>&);

int heaviside_step_function_s64(int64_t);

template<typename T>
T matrix_pfaffian(Matrix<T>&);

template<typename T>
T antisymetric_matrix_determinant(Matrix<T>&);

//******************************************************************************
//FUNÇÕES
//Função que determina se uma matriz é antissimétrica
template<typename T>
bool is_skew_symetric(Matrix<T>& m1){

  //Restrição a matrizes quadradas
  if(m1.rows!=m1.columns) return false;

  //Caso base:
  if(m1.rows==1 && m1.columns==1) return true;

  //Procedimentos
    //Loop sobre os elementos da matriz
    for(int64_t i=0; i< m1.rows; ++i){
      for(int64_t j=i; j< m1.rows; ++j){
        if(i==j){
          if(m1.matrix[i][j]!=0) return false;
          continue;
        }

        if(m1.matrix[i][j]!=(m1.matrix[j][i]*(-1))) return false;


      }
    }

  //Resultado
  return true;

};


//Função que computa a função degrau de Heaviside para inteiros de 64 bits
int heaviside_step_function_s64(int64_t n){

  if(n>=0) return 1;
  else return 0;

};


//Função que computa o Pfaffiano de uma matriz antissimétrica usando recursão
template<typename T>
T matrix_pfaffian(Matrix<T>& m1){

  //Casos bases
  if(m1.rows==1) return 1;
  if(m1.rows==2) return m1.matrix[0][1];
  if(m1.rows&1) return 0;  


  //Variáveis locais
  Matrix<T> first_reduced_matrix=m1.comatrix(0,0);
  T pfaffian=0;
  short parity;


  //Procedimento    
    //Loop sobre os elementos da Matrizes reduzidas removendo-se a 1ª e a j-ésima linha e coluna
    for(int64_t j=1; j<m1.rows; ++j){

      parity=((j+1)&1);
      Matrix<T> second_reduced_matrix=first_reduced_matrix.comatrix((j-1), (j-1));
      if(parity==0){
        pfaffian=pfaffian+(m1.matrix[0][j]*matrix_pfaffian(second_reduced_matrix));
        continue;   
      }
      else pfaffian=pfaffian-(m1.matrix[0][j]*matrix_pfaffian(second_reduced_matrix));

    }


  //Resultado
  return pfaffian;

};

//Função que computa o determinante de uma matriz antissimétrica usando o seu Pfaffiano
template<typename T>
T antisymetric_matrix_determinant(Matrix<T>& m1){

  //Variáveis locais
  T m1_pfaffian=matrix_pfaffian(m1);

  //Resultado
  return (m1_pfaffian*m1_pfaffian);

};

//******************************************************************************
//FIM DO HEADER
#endif
