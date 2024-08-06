// VAMOS IMPLEMENTAR UM PROGRAMA COM FUNÇÕES PARA O CÁLCULO DE DETERMINANTES DE
// MATRIZES

/*
OBS.: NO CÁLCULO DO DETERMINANTES DE MATRIZES USAR AS OPERAÇÕES DE TRANSPOSIÇÃO
DE LINHAS E COLUNAS PARA COLOCAR O ELEMENTO COM MAIOR NÚMEROS DE ZEROS NA
PRIMEIRA LINHA PARA FACILITAR OS CÁLCULOS.

*/

//******************************************************************************************************************************************************************
// CABEÇALHO
#ifndef DETERMINANT_H
#define DETERMINANT_H
#include "matrix.h"  //Header incluindo as depedências necessárias

//******************************************************************************************************************************************************************
// FUNÇÕES
// Função que calcula o determinante para matrizede entradas inteiras
template <typename T>
T determinant(Matrix<T>& m1) {
  // Restrição
  assert(m1.rows == m1.columns && m1.rows >= 1);

  // Casos bases
  // Dimensão 1
  if (m1.rows == 1) return m1.matrix[0][0];

  // Dimensão 2
  if (m1.rows == 2)
    return ((m1.matrix[0][0] * m1.matrix[1][1]) -
            (m1.matrix[1][0] * m1.matrix[0][1]));

  // Dimensão 3
  if (m1.rows == 3)
    return ((m1.matrix[0][0] * m1.matrix[1][1] * m1.matrix[2][2]) +
            (m1.matrix[0][1] * m1.matrix[1][2] * m1.matrix[2][0]) +
            (m1.matrix[0][2] * m1.matrix[1][0] * m1.matrix[2][1]) -
            (m1.matrix[0][2] * m1.matrix[1][1] * m1.matrix[2][0]) -
            (m1.matrix[0][0] * m1.matrix[1][2] * m1.matrix[2][1]) -
            (m1.matrix[0][1] * m1.matrix[1][0] * m1.matrix[2][2]));

  // Caso geral o determinante de uma matriz quadrada de ordem n superior a 3 é
  // dada pelo produto de elementos de uma linha ou coluna pelos respectivos
  // cofatores
  if (m1.rows > 3) {
    // Variáveis locais
    int64_t i;
    T result = 0;
    // Procedimentos
    // Loop principal: produtos dos elementos da primeira linha pelos
    // respectivos cofatores
    for (i = 0; i < m1.rows; ++i) {
      Matrix<T> cofactor_matrix = m1.comatrix(0, i);
      if (i % 2 == 0)
        result += determinant(cofactor_matrix);
      else
        result -= determinant(cofactor_matrix);
    };
    return result;
  };

  // Caso de erro
  return (-1);
};

//******************************************************************************************************************************************************************
// FIM DO HEADER
#endif
