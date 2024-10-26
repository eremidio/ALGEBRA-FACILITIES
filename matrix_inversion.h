// VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA ROTINAS PARA O CÁLCULO DE MATRIZES INVERSAS

/*
OBS: USAREMOS UM ALGORITMO QUE UTILIZA COFATORES DA MATRIZ ORIGINAL PARA  CALCULAR
MATRIZES INVERSAS E DETERMINANTES DE MATRIZES. NÃO É O ALGORITMO MAIS EFICIENTE,
PORÉM É RELATIVAMENTE SIMPLES DE SE IMPLEMENTAR. POSSUI GRANDE INTERESSE TEÓRICO
NO QUE CONCERNE A ÁLGEBRA DE MATRIZES.

*/

//*******************************************************************************************************************************************************
// CABEÇALHO
#ifndef MATRIX_INVERSION_H
#define MATRIX_INVERSION_H
#include "determinant_gauss_barreis.h"  //Dependências necessárias estão inclusas aqui.

//*******************************************************************************************************************************************************
// DECLARAÇÃO DE FUNÇÕES
template <typename T>
Matrix<T> invert_matrix(Matrix<T>&);

//*******************************************************************************************************************************************************
// FUNÇÕES
// Função que calcula a inversa de uma matriz quadrada
template <typename T>
Matrix<T> invert_matrix(Matrix<T>& m1) {
 
  // Restrições
  assert(m1.rows == m1.columns && m1.rows > 1);
  T matrix_determinant = determinant_gauss_barreis(m1); //Variável local
  assert(matrix_determinant!= 0);

  // Variáveis locais
  Matrix<T> inverse_matrix;
  int64_t i, j;
  T matrix_element;


  // Procedimentos
  // Ajustando o tamanho da matriz inversa
  inverse_matrix.reshape(m1.rows, m1.columns);

  // Calculando as entradas da matriz inversa
  for (i = 0; i < m1.rows; i++) {
    for (j = 0; j < m1.rows; j++) {
      Matrix<T> cofactor_matrix = m1.comatrix(i, j);

      if (((i + j) % 2) == 0)
        inverse_matrix.matrix[i][j] =
            determinant_gauss_barreis(cofactor_matrix) / matrix_determinant;
      if (((i + j) % 2) == 1)
        inverse_matrix.matrix[i][j] =
            ((-1) * determinant_gauss_barreis(cofactor_matrix)) / matrix_determinant;
    };
  };

  // Resultado
  return inverse_matrix.transpose();
};

//*******************************************************************************************************************************************************
// FIM DO HEADER
#endif
