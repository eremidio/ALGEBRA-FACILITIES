// VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA ROTINAS PARA CONVERSÃO DOS TIPOS DOS
// ELEMENTOS DE UMA MATRIZ

//******************************************************************************************************************************************************************
// CABEÇALHO
#ifndef MATRIX_CAST_H
#define MATRIX_CAST_H
#include "matrix.h"

//******************************************************************************************************************************************************************
// DECLARAÇÃO DE FUNÇÕES
template <typename T, typename U>
Matrix<U> matrix_cast(Matrix<T>&);

//******************************************************************************************************************************************************************
// FUNÇÕES

// Função que converte o tipo associado elementos de uma matriz
template <typename T, typename U>
Matrix<U> matrix_cast(Matrix<T>& m1) {
  // Variáveis locais
  Matrix<U> result;

  // Procedimentos
  // Ajuste dos tamanho da matriz
  result.rows = m1.rows;
  result.columns = m1.columns;
  result.reshape(m1.rows, m1.columns);

  // Realizando a conversão dos elementos da matriz
  for (int64_t i = 0; i < m1.rows; ++i) {
    for (int64_t j = 0; j < m1.columns; ++j)
      result.matrix[i][j] = static_cast<U>(m1.matrix[i][j]);
  };

  // Resultado
  return result;
};

//******************************************************************************************************************************************************************
// FIM DO HEADER
#endif
