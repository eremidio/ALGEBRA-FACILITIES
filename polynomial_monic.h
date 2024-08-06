// VAMOS CRIAR UM PROGRAMA QUE CONVERTE UM POLINÔMIO EM UM POLINÔMIO MÔNICO

//**********************************************************************************************************************************
// CABEÇALHO
#ifndef POLYNOMIAL_MONIC_H
#define POLYNOMIAL_MONIC_H
#include "polynomials.h"

//**********************************************************************************************************************************
// DECLARAÇÃO DE FUNÇÕES
template <typename T>
polynomial<T> make_monic_polynomial(polynomial<T>&);

//**********************************************************************************************************************************
// FUNÇÕES
// Função que transforma um polinômio em um polinômio
template <typename T>
polynomial<T> make_monic_polynomial(polynomial<T>& p1) {
  // Variáveis locais
  polynomial<T> monic_polynomial = p1;
  T leading_coefficient = 1;

  // Procedimento
  // Calculando o coeficiente do termo de maior expoente
  for (auto x : p1.polynomial_coefficients) {
    if (x != 0) {
      leading_coefficient = x;
      break;
    };
  };

  // TESTE USE UM /**/ APÓS O MESMO
  /*std::cout<<"Lead coefficient: "<<leading_coefficient<<'\n';*/

  // Redefinindo os coeficientes do polinômio
  for (auto& y : monic_polynomial.polynomial_coefficients)
    y = y / leading_coefficient;

  // Resultado
  return monic_polynomial;
};

//**********************************************************************************************************************************
// FIM DO HEADER
#endif
