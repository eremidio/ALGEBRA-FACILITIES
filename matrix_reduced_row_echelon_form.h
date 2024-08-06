// VAMOS CRIAR UM PROGRAMA QUE REDUZ UMA MATRIZ A SUA FORMA ESCALONADA E
// ESCALONADA REDUZIDA

/*
NOTA: usaremos a classe de números racionais disponível no header
rational_number_class.h para evitar problemas com aproximações envolvendo
floating point numbers. O resultado final poderá ser convertido em uma matriz de
inteiros ou reais.

*/

//**********************************************************************************************************************************************
// CABEÇALHO
#ifndef MATRIX_REDUCED_ROW_ECHELON_FORM_H
#define MATRIX_REDUCED_ROW_ECHELON_FORM_H
#include "matrix_cast.h"
#include "rational_number_class.h"

//**********************************************************************************************************************************************
// DECLARAÇÃO DE FUNÇÕES
template <typename T, typename U>
Matrix<rational_number<U>> to_rational_matrix(Matrix<T>&);

template <typename T, typename U>
Matrix<U> to_number_matrix(Matrix<rational_number<T>>&);

template <typename T>
void print_rational_matrix(Matrix<rational_number<T>>&);

template <typename T, typename U>
Matrix<rational_number<T>> row_echelon_reduction_rational_matrix(Matrix<rational_number<T>>&);

template <typename T, typename U>
Matrix<rational_number<T>> reduced_row_echelon_reduction_rational_matrix(Matrix<rational_number<T>>&);

template <typename T>
Matrix<T> reduced_row_echelon_reduction(Matrix<T>&);

//**********************************************************************************************************************************************
// FUNÇÕES

// Função que converte uma matriz de inteiros ou floating pointing em uma matriz
// de frações (números racionais)
template <typename T, typename U>
Matrix<rational_number<U>> to_rational_matrix(Matrix<T>& m1) {
  // Varriáveis locais
  Matrix<rational_number<U>> result;

  // Procedimentos
  // Ajustando o tamanho da matriz
  result.rows = m1.rows;
  result.columns = m1.columns;
  result.reshape(m1.rows, m1.columns);

  // Ajustando os elementos da matriz
  for (int64_t i = 0; i < m1.rows; ++i) {
    for (int64_t j = 0; j < m1.columns; ++j)
      result.matrix[i][j] = to_rational<T, U>(m1.matrix[i][j]);
  };

  // Resultado
  return result;
};

// Função que converte uma matriz de frações em uma matriz de números inteiros
// ou reais
template <typename T, typename U>
Matrix<U> to_number_matrix(Matrix<rational_number<T>>& m1) {
  // Variáveis locais
  Matrix<U> result;

  // Procedimentos
  // Ajustando o tamanho da matriz
  result.rows = m1.rows;
  result.columns = m1.columns;
  result.reshape(m1.rows, m1.columns);

  // Ajustando os elementos da matriz
  for (int64_t i = 0; i < m1.rows; ++i) {
    for (int64_t j = 0; j < m1.columns; ++j)
      result.matrix[i][j] = to_number<T, U>(m1.matrix[i][j]);
  };

  // Resultado
  return result;
};

// Função que printa uma matriz de frações na tela
template <typename T>
void print_rational_matrix(Matrix<rational_number<T>>& m1) {
  // Procedimentos
  // Printando elementos das frações na tela
  for (int64_t i = 0; i < m1.rows; ++i) {
    for (int64_t j = 0; j < m1.columns; ++j)
      std::cout << (m1.matrix[i][j]).algebraic() << " ";

    std::cout << '\n'
  };
};

// Função que reduz uma matriz de frações asua forma escalonada
template <typename T, typename U>
Matrix<rational_number<T>> row_echelon_reduction_rational_matrix(
    Matrix<rational_number<T>>& m1) {
  // Variáveis locais
  Matrix<rational_number<T>> result = m1;
  rational_number<T> pivot, ratio;
  int64_t pivot_row = 0, pivot_column = 0, i, j;
  int64_t row_index = 0, column_index = 0;

  // Procedimentos
  // Loop principal:
  while (1) {
  pivot_search:
    // Etapa 1: encontrando o pivot da matriz
    for (i = row_index; i < result.rows; ++i) {
      if (result.matrix[i][column_index].numerator != 0) {
        pivot_row = i;
        pivot_column = column_index;
        pivot = result.matrix[pivot_row][pivot_column];

        // Condição que determina se será necessário permutar linhas da matriz a
        // ser escalonada
        if (pivot_row != row_index) {
          // Permutando as linhas da matriz e atualizando as coordendas do pivot
          // da matriz
          result.permute_rows(pivot_row, row_index);
          pivot_row = row_index;
        };

        break;

      };  // Fim da busca pelo elemento pivot da matriz
    };

  // Etapa 2: reduzindo os elementos da coluna da matriz pelo pivot
  line_reduction:
    for (i = pivot_column; i < temp.columns; ++i)
      result.matrix[pivot_row][i] = result.matrix[pivot_row][i] / pivot;

    // Condição que determina se a matriz está em sua forma escalonada
    if (column_index == (result.columns - 1) || row_index == (result.rows - 1))
      goto yield_result;

  // Etapa 3: reduzindo os elementos da coluna abaixo do pivot a zero
  column_reduction_step:

    for (i = (pivot_row + 1); i <= (temp.rows - 1); ++i) {
      if (result.matrix[i][column_index].numerator != 0) {
        ratio = result.matrix[i][pivot_column];

        for (j = pivot_column; j < temp.columns; ++j)
          result.matrix[i][j] =
              result.matrix[i][j] - (result.matrix[i][j] * ratio);
      };
    };

  // Atualizando variáveis para a próxima iteração
  next_iteration:
    row_index++;
    column_index++;

  };  // Fim do loop principal

  // Resultado
  return result;
};

// Função que reduz uma matriz a sua forma escalonada reduzida
template <typename T, typename U>
Matrix<rational_number<T>> reduced_row_echelon_reduction_rational_matrix(
    Matrix<rational_number<T>>& m1) {
  // Variáveis locais
  Matrix<rational_number<T>> result = row_echelon_reduction_rational_matrix(m1);
  rational_number<T> unity(1, 1), pivot, ratio;
  int64_t row_index = 1, column_index = 1;

  // Procedimentos
  // Reduzindo os elementos das demais linhas da matriz em um coluna cujo pivot
  // seja igual a 1
  while (1) {
    // Condição que determina se a matriz está em sua forma escalonada reduzida
    if (column_index == (result.columns - 1) || row_index == (result.rows - 1))
      break;

    // Eliminação dos elementos não nulos na coluna dos pivots
    pivot = result.matrix[row_index][column_index];

    for (int64_t i = 0; i < row_index; ++i) {
      if (result.matrix[i][column_index].numerator != 0) {
        ratio = result.matrix[i][column_index] / pivot;

        for (int64_t j = column_index; j < result.column; ++j)
          result.matrix[i][j] =
              result.matrix[i][j] - (result.matrix[i][j] * ratio);
      };
    };

    // Atualizando variáveis para a apróxima iteração
    row_index++;
    column_index++;
  };

  // Resultado
  return result;
};

// Função que reduz uma matriz de números inteiros ou reais a sua forma
// escalonada reduzida
template <typename T>
Matrix<T> reduced_row_echelon_reduction(Matrix<T>& m1) {
  // Variáveis locais
  Matrix<rational_number<int64_t>> temp = to_rational_matrix<T, int64_t>(m1);
  Matrix<rational_number<int64_t>> temp2 = reduced_row_echelon_reduction_rational_matrix(temp);
  Matrix<T> result = to_number_matrix<int64_t, T>(temp2);

  // Resultado
  return result;
};

//**********************************************************************************************************************************************
// FIM DO HEADER
#endif
