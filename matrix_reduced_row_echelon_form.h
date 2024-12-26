//VAMOS CRIAR UM PROGRAMA QUE REDUZ UMA MATRIZ A SUA FORMA ESCALONADA REDUZIDA

/*

PARA MAIORES REFERÊNCIAS: https://en.wikipedia.org/wiki/Row_echelon_form#

*/


//**********************************************************************************************************************************************
// CABEÇALHO
#ifndef MATRIX_REDUCED_ROW_ECHELON_FORM_H
#define MATRIX_REDUCED_ROW_ECHELON_FORM_H
#include"matrix_echelon_form_double.h"


//**********************************************************************************************************************************************
// DECLARAÇÃO DE FUNÇÕES
template<typename T>
Matrix<T> reduced_echelon_form(Matrix<T>&, int64_t&);

//**********************************************************************************************************************************************
//FUNÇÕES
//Função que escreve uma matriz em sua forma escalonada reduzida
/*
NOTA: Ao usar variáveis do tipo float point nativos de C/C++, erros podem ocorrer
      devido a representação apenas aproximada de números reais.
*/
template<typename T>
Matrix<T> reduced_echelon_form(Matrix<T>& m1, int64_t& row_changes){

  //Variáveis locais
  Matrix<double> floating_point_matrix = matrix_cast<T, double>(m1);
  Matrix<double> echelon_matrix = echelon_row_form<double>(floating_point_matrix, row_changes);
  double pivot, ratio;
  int64_t pivot_row=(m1.rows-1), pivot_column=0;
  int64_t i, j, k, l;


  //Procedimentos
    //Encontrando o pivot da matriz
    for(j=0; j<m1.columns; ++j){
      pivot = echelon_matrix.matrix[pivot_row][j];
      if(pivot!=0){
        pivot_column=j;
        if(pivot>1){
          for(l=pivot_column; l<m1.columns; ++l) echelon_matrix.matrix[pivot_row][l]=echelon_matrix.matrix[pivot_row][l]/pivot;
        }
        break;
      }
    };


    //Loop principal reverso
    while(1){
      
      //Fim do loop principal
      if(pivot_row==0 || pivot_column==0) break;

      //Checando se os elementos acima do pivot são nulos
      for(i=(pivot_row-1); i>=0; --i){
        if(echelon_matrix.matrix[i][pivot_column]==0) continue;
        else{
          ratio=echelon_matrix.matrix[i][pivot_column]*(-1);
          for(j=0; j<m1.columns; ++j) echelon_matrix.matrix[i][j]=echelon_matrix.matrix[i][j]+(ratio*echelon_matrix.matrix[pivot_row][j]);
          
        }

      }

      //Atualizando variáveis para a próxima iteração
      pivot_row--; pivot_column--;
      while(echelon_matrix.matrix[pivot_row][pivot_column]==0) pivot_column--;


    };//Fim do loop principal

    

  //Resultdo
  Matrix<T> result=matrix_cast<double, T>(echelon_matrix);
  return result;

};


//**********************************************************************************************************************************************
//FIM DO HEADER
#endif
