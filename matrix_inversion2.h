//VAMOS CRIAR UM PROGRAMA PARA CALCULAR MATRIZES INVERSAS USANDO UMA VERSÃO MODIFICADA DO ALGORITMO DE FADDEEV-LEVERRIER


/*

PARA MAIORES INFORMAÇÕES: https://github.com/eremidio/ALGEBRA-FACILITIES/blob/main/matrix_characteristic_polynomial.h

*/ 


//******************************************************************************************
//CABEÇALHO
#ifndef MATRIX_INVERSION2_H
#define MATRIX_INVERSION2_H
#include"determinant_gauss_barreis.h"
#include"matrix_characteristic_polynomial.h"

//******************************************************************************************
//DECLARAÇÕES DE FUNÇÕES
template<typename T>
Matrix<T> matrix_adjugate_inversion_algorithm(Matrix<T>&);

//******************************************************************************************
//FUNÇÕES
//Função que calcula a inversa de uma matriz usando uma versão modificada do algoritmo de Faddeev-LeVerrier
template<typename T>
Matrix<T> matrix_adjugate_inversion_algorithm(Matrix<T>& m1){

  //Restrição
  assert(m1.rows==m1.columns);

  //Variáveis locais
  Matrix<T> I(m1.rows, Identity), Ic, Mk(m1.rows, Zero), M;
  T matrix_determinant=determinant_gauss_barreis<T>(m1);
  T c=1;
  
  //Procedimentos
    //Loop principal: Cálculo recursivo das matrizes adjugadas
    for(int64_t k=1; k<=m1.rows; k++){

      //Cálculo da Matriz adjugada
      Matrix<T> temp1=Mk*m1;
      Ic=I.scalar_multiplication(c);
      Mk= temp1+Ic;

      //Cálculo do coeficiente do polinômio característico
      M=Mk*m1;
      c=((-1)*matrix_trace<T>(M))/static_cast<T>(k); 
  
    }

    //Cálculo da paridade do determinante da matriz
    if(((m1.rows-1)&1)) matrix_determinant*=(-1);

    //Ajuste dos coeficieente da matriz inversa
    for(int64_t i=0; i<m1.rows; i++){
      for(int64_t j=0; j<m1.rows; j++){
        Mk.matrix[i][j]/=matrix_determinant;
      }
    }


  //Resultado
  return Mk;

};

//******************************************************************************************
//FIM DO HEADER
#endif
