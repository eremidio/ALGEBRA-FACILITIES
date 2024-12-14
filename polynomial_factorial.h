//VAMOS CRIAR UM PROGRAMA QUE ESTENDE A NOÇÃO DE FATORIAL PARA POLINÔMIOS

/*

O FATORIAL ASCENDENTE  É DEFINIDO COMO f(+, x, n)=x(x+1)(x+2)...(x+n-1).
O FATORIAL DESCENDENTE  É DEFINIDO COMO f(-, x, n)=x(x-1)(x-2)...(x-n+1).

TAIS POLINÔMIOS SÃO ÚTEIS EM CÁLCULOS ENVOLVENDO CERTOS TIPOS DE POLINÔMIOS COMO OS POLINÔMIOS DE BERNOULLI

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Falling_and_rising_factorials

*/


//**************************************************************************************************************************
//CABEÇALHO
#ifndef POLYNOMIAL_FACTORIAL_H
#define POLYNOMIAL_FACTORIAL_H
#include"polynomial_exponentiation.h"
#include<type_traits>

//**************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> generate_linear_signed_polynomial_factor(T, signed);

template<typename T>
polynomial<T> polynomial_falling_factorial(T);

template<typename T>
polynomial<T> polynomial_rising_factorial(T);


//**************************************************************************************************************************
//FUNÇÕES
//Função que gera um polinômio linear do tipo f(x)=x+a, com a≳0 ou a<0
template<typename T>
polynomial<T> generate_linear_signed_polynomial_factor(T a, signed flag/*(-1) ou 1*/){

  //Variáveis
  polynomial<T> linear_poly;
  

  //Procedimento
    //Ajuste do fator linear usado para se computar o fatorial
    linear_poly.degree=1;

    linear_poly.polynomial_coefficients.push_back(1);
    if(flag>0)  linear_poly.polynomial_coefficients.push_back(a);
    else linear_poly.polynomial_coefficients.push_back((-1)*a);

    linear_poly.polynomial_powers.push_back(1); linear_poly.polynomial_powers.push_back(0);


  //Resultado
  return linear_poly;
  
};


//Função que calcula o polinômio fatorial descendente
template<typename T>
polynomial<T> polynomial_falling_factorial(T index){

  //Restrição a coeficientes inteiros
  static_assert(std::is_integral<T>::value, "Coeficientes devem ser inteiros");
  
  //Variáveis locais
  polynomial<T> falling_factorial_poly=generate_unity_polynomial<T>();
  

  //Procedimentos
    //Loop principal
    for(auto i = 0;  i<index; ++i){

      polynomial<T> linear_poly=generate_linear_signed_polynomial_factor<T>(i, (-1));
      falling_factorial_poly=falling_factorial_poly*linear_poly;

    }


  //Resultado
  return falling_factorial_poly;
 
};


//Função que calcula o polinômio fatorial ascendente
template<typename T>
polynomial<T> polynomial_rising_factorial(T index){

  //Restrição a coeficientes inteiros
  static_assert(std::is_integral<T>::value, "Coeficientes devem ser inteiros");
  
  //Variáveis locais
  polynomial<T> rising_factorial_poly=generate_unity_polynomial<T>();
  

  //Procedimentos
    //Loop principal
    for(auto i = 0;  i<index; ++i){

      polynomial<T> linear_poly=generate_linear_signed_polynomial_factor<T>(i, 1);
      rising_factorial_poly=rising_factorial_poly*linear_poly;

    }


  //Resultado
  return rising_factorial_poly;
 
};



//**************************************************************************************************************************
//FIM DO HEADER
#endif
