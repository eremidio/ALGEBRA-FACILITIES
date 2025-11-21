//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA ROTINAS PARA EXPONENCIAÇÃO DE POLINÔMIOS ESPARSOS

/*

PARA MAIORES INFORMAÇÕES: https://github.com/eremidio/ALGEBRA-FACILITIES/blob/main/sparse_polynomials.h

*/ 


//************************************************************************************************
//CABEÇALHO
#ifndef SPARSE_POLYNOMIAL_EXPONENTIATION_H
#define SPARSE_POLYNOMIAL_EXPONENTIATION_H
#include"sparse_polynomial_reduction.h"


//************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> generate_unity_polynomial();

template<typename T>
polynomial<T> generate_zero_polynomial();

template<typename T>
polynomial<T> generate_identity_polynomial();


template<typename T, typename U>  //Parâmetro template U devem ser inteiro
polynomial<T> sparse_polynomial_pow(polynomial<T>&, U);


template<typename T, typename U>  //Parâmetros template T e U devem ser inteiros
polynomial<T> sparse_polynomial_powmod(polynomial<T>&, U, U);

template<typename T, typename U>  //Parâmetros template T e U devem ser inteiros
polynomial<T> sparse_polynomial_pow_finite_field(polynomial<T>&, polynomial<T>&, U);


template<typename T, typename U> //Parâmetros template T e U devem ser inteiros
polynomial<T> sparse_polynomial_powmod_finite_field(polynomial<T>&, polynomial<T>&, U, U);


//************************************************************************************************
//FUNÇÕES
//Função que gera o polinômio f(x)=1
template<typename T>
polynomial<T> generate_unity_polynomial(){

  //Variáveis locais
  polynomial<T> unity;
  univariate_monomial<T> one(1,0);


  //Procedimentos: ajuste do resultaso
  unity.monomials.insert({one.power, one});

  //Resultado
  return unity;

};


//Função que gera o polinômio f(x)=0
template<typename T>
polynomial<T> generate_zero_polynomial(){

  //Variáveis locais
  polynomial<T> zero_poly;
  univariate_monomial<T> zero(0,0);


  //Procedimentos: ajuste do resultaso
  zero_poly.monomials.insert({zero.power, zero});

  //Resultado
  return zero_poly;

};


//Função que gera o polinômio f(x)=x
template<typename T>
polynomial<T> generate_identity_polynomial(){

  //Variáveis locais
  polynomial<T> identity;
  univariate_monomial<T> x(1,1);


  //Procedimentos: ajuste do resultaso
  identity.monomials.insert({x.power, x});

  //Resultado
  return identity;

};


//Função que calcula uma exponencial de polinômios
template<typename T, typename U> 
polynomial<T> sparse_polynomial_pow(polynomial<T>& p1,  U exponent){
  
  //Variáveis locais
  polynomial<T> result=generate_unity_polynomial<T>();
  polynomial<T> q=p1;

  //Procedimentos
    //Loop sobre os bits do expoente
    while(exponent>0){

      //Checando a paridade do bit do expoente
      if(exponent&1) result=result*q;

      //Atualizando variáveis para a próxima iteração
      q=q*q;
      exponent>>=1;  

    }


  //Resultado
  return result;

};


//Função que calcula uma exponencial de polinômios a menos de uma relação de congruência
template<typename T, typename U> 
polynomial<T> sparse_polynomial_powmod(polynomial<T>& p1, U exponent, U modulus){
  
  //Variáveis locais
  polynomial<T> result=generate_unity_polynomial<T>();
  polynomial<T> q=p1;

  //Procedimentos
    //Loop sobre os bits do expoente
    while(exponent>0){

      //Checando a paridade do bit do expoente
      if(exponent&1){
        result=result*q;

        //Reduzindo os coeficientes e eliminando termos nulos
        result=polynomial_mod<T, U>(result, modulus);
        result.remove_null_terms();

      }


      //Atualizando variáveis para a próxima iteração
      q=q*q;
      q=polynomial_mod<T, U>(q, modulus);
      exponent>>=1;  

    }

    //Ajuste fino do resultado
    result=polynomial_mod<T, U>(result, modulus);

  //Resultado
  return result;
};


//Função que calcula uma exponencial de polinômios a menos de uma relação de congruência polinomial
template<typename T, typename U>  //Parâmetros template T e U devem ser inteiros
polynomial<T> sparse_polynomial_pow_finite_field(polynomial<T>& p1, polynomial<T>& p2, U exponent){

  //Variáveis locais
  polynomial<T> result=generate_unity_polynomial<T>();
  polynomial<T> q=p1;

  //Procedimentos
    //Loop sobre os bits do expoente
    while(exponent>0){

      //Checando a paridade do bit do expoente
      if(exponent&1){
        result=result*q;
        if(result.degree()>=p2.degree()) result=polynomial_mod<T>(result, p2);
      }

      //Atualizando variáveis para a próxima iteração
      q=q*q;
      q=polynomial_mod<T>(q, p2);
      exponent>>=1;  

    }

    result=polynomial_mod<T>(result, p2);

  //Resultado
  return result;

};

//Função que calcula uma exponencial modular de polinômios a menos de uma congruência polinomial
template<typename T, typename U> //Parâmetros template T e U devem ser inteiros
polynomial<T> sparse_polynomial_powmod_finite_field(polynomial<T>& p1, polynomial<T>& p2, U exponent, U modulus){

  //Variáveis locais
  polynomial<T> result=generate_unity_polynomial<T>();
  polynomial<T> q=p1;

  //Procedimentos
    //Loop sobre os bits do expoente
    while(exponent>0){

      //Checando a paridade do bit do expoente
      if(exponent&1){
        result=result*q;
        if(result.degree()>=p2.degree()) result=polynomial_mod<T>(result, p2);
      }
    

      //Atualizando variáveis para a próxima iteração
      result=polynomial_mod<T, U>(result, modulus);
      q=q*q;
      q=polynomial_mod<T>(q, p2);
      q=polynomial_mod<T, U>(q, modulus);
      exponent>>=1;  

    }

    result=polynomial_mod<T>(result, p2);
    result=polynomial_mod<T, U>(result, modulus);

  //Resultado
  return result;

};

//************************************************************************************************
//FIM DO HEADER
#endif
