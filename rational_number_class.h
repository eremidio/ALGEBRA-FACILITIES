// VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA UMA CLASSE DE FRAÇÕES (NÚMEROS
// RACIONAIS) PARA SE TRABALHAR COM FLOATING POINT NUMBERS USANDO APENAS
// INTEIROS

//********************************************************************************************************************************************************
// CABEÇALHO
#ifndef RATIONAL_NUMBER_CLASS_H
#define RATIONAL_NUMBER_CLASS_H
#include <inttypes.h>
#include <stdint.h>

#include <cmath>
#include <iostream>
#include <string>
#include <type_traits>

//********************************************************************************************************************************************************
// FUNÇÕES AUXILIARES
template <typename T>
T rational_gcd(T a, T b) {
  // Restrição a tipos inteiros
  static_assert(std::is_integral<T>::value,
                "Parcelas devem ser números inteiros.\n");

  // Resultado
  if (b == 0)
    return a;
  else
    return rational_gcd(b, (a % b));
};

template <typename T>
T rational_lcm(T a, T b) {
  // Restrição a tipos inteiros
  static_assert(std::is_integral<T>::value,
                "Parcelas devem ser números inteiros.\n");

  // Resultado
  return (a * b) / rational_gcd(a, b);
};

//********************************************************************************************************************************************************
// CLASSE DE NÚMEROS RACIONAIS
template <typename T>
class rational_number {
 public:
  // Membros
  T numerator;
  T denominator;

  // Construtores da classe
  rational_number();
  rational_number(T, T);
  ~rational_number(){};

  // Métodos da classe
  // Operações aritméticas básicas
  rational_number<T> operator+(rational_number<T>);
  rational_number<T> operator-(rational_number<T>);
  rational_number<T> operator*(rational_number<T>);
  rational_number<T> operator/(rational_number<T>);
  rational_number<T> operator=(const rational_number<T>&);
  rational_number<T> rationalize();

  // Input/output e acesso a elementos
  void set();
  T get_denominator();
  T get_numerator();
  std::string algebraic();
};

//********************************************************************************************************************************************************
// CONSTRUTORES DA CLASSE DE NÚMEROS RACIONAIS
template <typename T>
rational_number<T>::rational_number() {
  // Restrição a tipos inteiros
  static_assert(std::is_integral<T>::value,
                "Numerador e denominador devem ser inteiros.\n");
};

template <typename T>
rational_number<T>::rational_number(T a, T b) {
  // Restrição a tipos inteiros
  static_assert(std::is_integral<T>::value,
                "Numerador e denominador devem ser inteiros.\n");

  //--------------
  numerator = a;
  denominator = b;
};

//********************************************************************************************************************************************************
// MÉTODOS DA CLASSE DE NÚMEROS RACIONAIS

// Operações aritméticas básicas
// Racionaização de frações
template <typename T>
rational_number<T> rational_number<T>::rationalize() {
  // Variáveis locais
  rational_number<T> result;
  T reducer = rational_gcd<T>(numerator, denominator);

  // Procedimentos
  // Ajuste do resultado
  result.numerator = numerator / reducer;
  result.denominator = denominator / reducer;

  // Resultado
  return result;
};

// Adição
template <typename T>
rational_number<T> rational_number<T>::operator+(rational_number<T> r1) {
  // Variáveis locais
  rational_number<T> result;

  // Procedimentos
  // Calculando o denominador
  result.denominator = rational_lcm<T>(denominator, r1.denominator);

  // Calculando o numerador
  result.numerator = ((result.denominator / denominator) * numerator) +
                     ((result.denominator / r1.denominator) * r1.numerator);

  // Resultado
  return result.rationalize();
};

// Subtração
template <typename T>
rational_number<T> rational_number<T>::operator-(rational_number<T> r1) {
  // Variáveis locais
  rational_number<T> result;

  // Procedimentos
  // Calculando o denominador
  result.denominator = rational_lcm<T>(denominator, r1.denominator);

  // Calculando o numerador
  result.numerator = ((result.denominator / denominator) * numerator) -
                     ((result.denominator / r1.denominator) * r1.numerator);

  // Resultado
  return result.rationalize();
};

// Multiplicação
template <typename T>
rational_number<T> rational_number<T>::operator*(rational_number<T> r1) {
  // Variáveis locais
  rational_number<T> result;

  // Procedimentos
  // Ajuste do resultado final
  result.numerator = (numerator * r1.numerator);
  result.denominator = (denominator * r1.denominator);

  // Resultado
  return result.rationalize();
};

// Divisão
template <typename T>
rational_number<T> rational_number<T>::operator/(rational_number<T> r1) {
  // Variáveis locais
  rational_number<T> result;

  // Procedimentos
  // Ajuste do resultado final
  result.numerator = (numerator * r1.denominator);
  result.denominator = (denominator * r1.numerator);

  // Resultado
  return result.rationalize();
};

// Cópia
template <typename T>
rational_number<T> rational_number<T>::operator=(const rational_number<T>& r1) {
  // Variáveis  locais
  rational_number<T> result;

  // Procedimentos
  // Copiando os numerador e denominador
  this->denominator = r1.denominator;
  this->numerator = r1.numerator;

  // Resultado
  return *this;
};

// Funções de entradas e saídas de dados

// Função que define os elementos deuma fração
template <typename T>
void rational_number<T>::set() {
  // Recebendo input do usuário
  std::cout << "Numerador: ";
  std::cin >> numerator;
  std::cout << "Denominador: ";
  std::cin >> denominator;
};

// Funções que retornam o numerador e denominador das frações
template <typename T>
T rational_number<T>::get_numerator() {
  return numerator;
};

template <typename T>
T rational_number<T>::get_denominator() {
  return denominator;
};

// Função que escreve uma fração como uma string
template <typename T>
std::string rational_number<T>::algebraic() {
  // Váriáveis locais
  std::string rational_string = "";

  // Procedimentos
  // Caso 1: denominador divide numerador
  if (numerator % denominator == 0)
    rational_string += std::to_string((numerator / denominator));

  // Caso 2: denominador não divide numerador
  else if (numerator % denominator != 0) {
    rational_string += std::to_string(numerator);
    rational_string += "/";
    rational_string += std::to_string(denominator);
  };

  // Resultado
  return rational_string;
};

//********************************************************************************************************************************************************
// FUNÇÕES DE CONVERSÃO DA CLASSE DE RACIONAIS PARA INTEIROS E FLOATING POINT
// NUMBERS

//--------------------------------------------
// DECLARAÇÕES DE FUNÇÕES
template <typename T, typename U>
U to_int(rational_number<T>);

template <typename T, typename U>
U to_float(rational_number<T>);

template <typename T, typename U>
U to_number(rational_number<T>);

template <typename T, typename U>
rational_number<U> int_to_rational(T);

template <typename T, typename U>
rational_number<U> float_to_rational(T);

template <typename T, typename U>
rational_number<U> to_rational(T);

//--------------------------------------------
// FUNÇÕES
template <typename T, typename U>
U to_int(rational_number<T> r) {
  return static_cast<U>(r.numerator / r.denominator);
};

template <typename T, typename U>
U to_double(rational_number<T> r) {
  return static_cast<U>(r.numerator * 1.0 / r.denominator);
};

template <typename T, typename U>
U to_number(rational_number<T> r) {
  if (std::is_integral<U>::value) return to_int<T, U>(r);
  if (std::is_floating_point<U>::value)
    return to_double<T, U>(r);
  else
    return 0;
};

template <typename T, typename U>
rational_number<U> int_to_rational(T n) {
  // Variáveis locais
  rational_number<U> result;

  // Procedimentos
  // Ajuste do resultado
  result.numerator = static_cast<U>(n);
  result.denominator = static_cast<U>(1);

  // Reseultado
  return result;
};

template <typename T, typename U>
rational_number<U> float_to_rational(T r) {
  // Variáveis locais
  rational_number<U> result;
  __int128_t multiplier = 10;

  // Procedimentos
  // Ajuste de variáveis
  while (std::floor(multiplier * r) != std::ceil(multiplier * r))
    multiplier *= 10;
  result.numerator = static_cast<U>(multiplier * r);
  result.denominator = static_cast<U>(multiplier);

  // Reseultado
  return result.rationalize();
};

template <typename T, typename U>
rational_number<U> to_rational(T q) {
  if (std::is_integral<T>::value) return int_to_rational<T, U>(q);
  if (std::is_floating_point<T>::value)
    return float_to_rational<T, U>(q);
  else {
    rational_number<U> result(0, 0);
    return result;
  };
};

//********************************************************************************************************************************************************
// FIM DO HEADER
#endif
