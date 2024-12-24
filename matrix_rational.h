//VAMOS CRIAR UM PROGRAMA  PARA OPERAR COM MNATRIZES DE FRAÇÕES

/*
O PRESENTE ŔOGRAMA CONTERÁ ROTINAS PARA SEREM USADOS COMO SUBROTINAS EM
OUTROS ALGORITMOS ENVOVENDO MATRZES COM ENTRADAS INTEIRAS. DESTA FORMA
PODEMOS OBTER RESULTADOS EXATOS NESTES CASOS.

*/




//***************************************************************************
//CABEÇALHO
#ifndef MATRIX_RATIONAL_H
#define MATRIX_RATIONAL_H
#include"matrix.h"
#include"rational_number_class.h"



//***************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
Matrix<rational_number<T>> generate_rational_matrix(Matrix<T>&);

template<typename T>
Matrix<T> generate_number_matrix(Matrix<rational_number<T>>&);

template<typename T>
void print_rational_matrix(Matrix<rational_number<T>>&);

//***************************************************************************
//FUNÇÕES
//Função que converte uma matriz de números (inteiros) em uma matriz de frações
template<typename T>
Matrix<rational_number<T>> generate_rational_matrix(Matrix<T>& m1){

  //Variáveis locais
  Matrix<rational_number<T>> result;
  rational_number<T> matrix_element;


  //Procedimentos
    //Ajustando o tamanho da matriz
    result.rows=m1.rows; result.columns=m1.columns;
    result.reshape(result.rows, result.columns);


    //Definindo as entradas da matriz
    for(int64_t i=0; i<result.rows; ++i){
      for(int64_t j=0; j<result.columns; ++j){
        matrix_element=to_rational<T, T>(m1.matrix[i][j]);
        result.matrix[i][j]=matrix_element;
                                             }
    }

  //Resultado
  return result;

};


//Função que converte uma matriz de frações em uma matriz númerica 
template<typename T>
Matrix<T> generate_number_matrix(Matrix<rational_number<T>>& m1){

  //Variáveis locais
  Matrix<T> result;
  T matrix_element;


  //Procedimentos
    //Ajustando o tamanho da matriz
    result.rows=m1.rows; result.columns=m1.columns;
    result.reshape(result.rows, result.columns);


    //Definindo as entradas da matriz
    for(int64_t i=0; i<result.rows; ++i){
      for(int64_t j=0; j<result.columns; ++j){
        matrix_element=to_number<T, T>(m1.matrix[i][j]);
        result.matrix[i][j]=matrix_element;
                                             }
    }

  //Resultado
  return result;

};


//Função que exibe uma matriz de frações
template<typename T>
void print_rational_matrix(Matrix<rational_number<T>>& m1){

  //Exibindo as entradas da matriz
  for(int64_t i=0; i<m1.rows; ++i){
    for(int64_t j=0; j<m1.columns; ++j){
      std::cout<<(m1.matrix[i][j]).algebraic()<<" ";
      
                                           }
    std::cout<<'\n';
  }
  std::cout<<'\n';

};

//***************************************************************************
//FIM DO HEADER
#endif
