//VAMOS CRIAR UM PROGRAMA QUE REDUZ UMA MATRIZ A SUA FORMA ESCALONADA

//*************************************************************************************************************************************
//CABEÇALHO
#ifndef MATRIX_ECHELON_FORM_DOUBLE_H 
#define MATRIX_ECHELON_FORM_DOUBLE_H
#include"matrix_cast.h"

//*************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
Matrix<T> echelon_row_form(Matrix<T>&, int64_t&);


//*************************************************************************************************************************************
//FUNÇÕES
//Função que reduz uma matriz a sua forma escalonada
template<typename T>
Matrix<T> echelon_row_form(Matrix<T>& m1, int64_t& row_changes){

  //Variáveis locais
  Matrix<double> float_point_matrix=matrix_cast<T, double>(m1);
  double pivot, ratio;
  int64_t pivot_row=0, pivot_column=0;
  int64_t i, j, k, l;

  //Procedimento
    //Loop principal
    while(1){

      //Etapa 1: encontrando o pivot da matriz
      pivot_search:
      k=pivot_row;
      pivot=float_point_matrix.matrix[pivot_row][pivot_column];


      if(pivot==0){

        if(pivot_row==(m1.rows-1)){
          l=pivot_column;
          while(pivot==0){
            l++;
            if(l>=m1.columns) goto yield_result;
          }
            pivot=float_point_matrix.matrix[k][l];
            pivot_row=k;
            pivot_column=l;
            goto line_reduction;
    
        }  


        while(pivot==0){
          k++;
          pivot=float_point_matrix.matrix[k][pivot_column];
          
          //Permutando as linhas da matriz
          if(pivot!=0) float_point_matrix.permute_rows(k, pivot_row);  
          row_changes++;  
        
        } 
      };


      //Etapa 2: reduzindo os elementos da matriz
      line_reduction:
      for(j=pivot_column; j<m1.columns; ++j) float_point_matrix.matrix[pivot_row][j]=float_point_matrix.matrix[pivot_row][j]/pivot;

      //Condição que determina o fim do loop
      if(pivot_row==(m1.rows-1) || pivot_column==(m1.columns-1)) break;


      //Etapa 3: reduzindo os elementos abaixo coluna dopivot da matriz
      for(i=(pivot_row+1); i<m1.rows; ++i){
        if(float_point_matrix.matrix[i][pivot_column]==0) continue;
        else{
          ratio=float_point_matrix.matrix[i][pivot_column]*(-1);
          for(j=0; j<m1.columns; ++j) float_point_matrix.matrix[i][j]=float_point_matrix.matrix[i][j]+(ratio*float_point_matrix.matrix[pivot_row][j]);

        }

      }


      //Atualizando variáveis para a próxima iteração
      pivot_row++;
      pivot_column++;
    
    

    };//Fim do loop principal


  //Resultado
  yield_result:
  Matrix<T> result=matrix_cast<double, T>(float_point_matrix);
  return result;

};





//*************************************************************************************************************************************
//FIM DO HEADER
#endif
