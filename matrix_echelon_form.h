//VAMOS CRIAR UM PROGRAMA QUE REDUZ UMA MATRIZ A SUA FORMA ESCALONADA

//*************************************************************************************************************************************
//CABEÇALHO
#ifndef MATRIX_ECHELON_FORM_H 
#define MATRIX_ECHELON_FORM_H
#include"matrix_cast.h"

//*************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
Matrix<T> type2_row_change(Matrix<T>&, int64_t, T);
template<typename T>
Matrix<T> type3_row_change(Matrix<T>&, int64_t, int64_t, T);
template<typename T>
Matrix<T> echelon_row_form(Matrix<T>&, int64_t&);



//*************************************************************************************************************************************
//FUNÇÕES
/*
NOTA: Transformações do tipo 1 permuta de elementos de uma matriz, são realizados por meio da função membro .permute_rows(int1, int2) na
classe de matrizes. Só será necessário implementar transformações do tipo 2, que consiste na multiplicação/divisão de uma linha por um
escalar e transformações do tipo 3 que consiste na combinação linear de linhas. Essas transformações serão embutidas no algoritmo
principal, porém implmentações independentes são providas aqui pois são subrotinas uteis em outros algoritmos de manipulação de matrizes.

*/

//Função que realiza uma transformação do tipo 2: reduz o elemento pivotal a 1
template<typename T>
Matrix<T> type2_row_change(Matrix<T>& m1, int64_t row, T pivot){

 //Variáveis locais
 Matrix<T> result=m1;

 //Procedimentos
 for(int64_t i=0; i<m1.columns; ++i){
  if(result.matrix[row][i]>0)
   result.matrix[row][i]=m1.matrix[row][i]/pivot;
                                    };

 //Resultado
 return result;
                                                               };
 

//Função que realiza uma transformação do tipo 3: combinação linear de linhas em uma matriz
template<typename T>
Matrix<T> type3_row_change(Matrix<T>& m1, int64_t row1, int64_t row2, T ratio){

 //Variáveis locais
 Matrix<T> result=m1;

 //Procedimentos
 for(int64_t i=0; i<m1.columns; ++i)
  result.matrix[row2][i]=result.matrix[row2][i]+(result.matrix[row1][i]*ratio);


 //Resultado
 return result;                                   
                                                                              };



//Função que reduz uma matriz a sua forma escalonada reduzida usando a eliminação de Gauss-Jordan
template<typename T>
Matrix<T> echelon_row_form(Matrix<T>& m1, int64_t& row_changes){

 //Variáveis locais
 Matrix<double> temp=matrix_cast<T, double>(m1);//Usaremos casting para double para evitar problemas envolvendo floating numbers
 double pivot=0.0, ratio;
 int64_t pivot_row=0, pivot_column=0, i, j;
 int64_t row_index=0, column_index=0;


 //Procedimentos
  //Loop principal
  while(true){
    pivot_search:
    //Etapa 1: encontrando o pivot da matriz
    for(i=row_index; i<temp.rows; ++i){

     if(temp.matrix[i][column_index]>0){
      pivot_row=i;
      pivot_column=column_index;
      pivot=temp.matrix[pivot_row][pivot_column];
      
      //Condição que determina se será necessário permutar linhas da matriz a ser escalonada
      if(pivot_row!=row_index){

       row_changes++;
      
       //Permutando as linhas da matriz e atualizando as coordendas do pivot da matriz
       temp.permute_rows(pivot_row, row_index);
       pivot_row=row_index;
      
                              };
    
      break;
                                       }

                                      };

      

        //TESTE USE UM /**/ APÓS O MESMO
        /*std::cout<<"Etapa 1:\n";
        std::cout<<"Pivot: "<<pivot<< " Pivot row: "<<pivot_row<< " Pivot column: "<<pivot_row<<'\n';
        temp.print_matrix();*/


    //Etapa 2: reduzindo os elementos da coluna da matriz pelo pivot
    line_reduction:
    for(i=pivot_column; i<temp.columns; ++i)
     temp.matrix[pivot_row][i]=temp.matrix[pivot_row][i]/pivot;



        //TESTE USE UM /**/ APÓS O MESMO
        /*std::cout<<"Etapa 2:\n";
        temp.print_matrix();*/



    //Condição que determina se a matriz está em sua forma escalonada
    if(column_index==(temp.columns-1) || row_index==(temp.rows-1))
     goto yield_result;       

    //Etapa 3: checando se os elementos abaixo do pivot são todos nulos
    column_reduction_step:

    for(i=(pivot_row+1);  i<=(temp.rows-1); ++i){

        ratio=temp.matrix[i][pivot_column];//Fator de redução a ser aplicado na combinação linear de linhas da matriz


        //TESTE USE UM /**/ APÓS O MESMO
        /*std::cout<<"Ratio: "<<ratio<<'\n';*/



        for(j=pivot_column; j<temp.columns; ++j)
         temp.matrix[i][j]=temp.matrix[i][j]-(temp.matrix[pivot_row][j]*ratio);
                                       
                                               };



        //TESTE USE UM /**/ APÓS O MESMO
        /*td::cout<<"Etapa 3:\n";
        temp.print_matrix();*/

    

    //Atualizando variáveis para a próxima iteração
    next_iteration:
     row_index++;
     column_index++;      

             };//Fim do loop principal


 //Resultado da execução do  algoritmo
 yield_result:
 Matrix<T> result=matrix_cast<double, T>(temp);
 return result;
    
                                                               };





//*************************************************************************************************************************************
//FIM DO HEADER
#endif
