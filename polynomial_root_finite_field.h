//VAMOS CRIARUM PROGRAMA  QUE IMPLEMENTA ROTINAS PARA CALCULAR RAÍZES DE POLINÔMIOS EM CORPOS FINITOS DO PRIMEIRO TIPO
//USANDO O ALGORITMO DE BERKELAMP-RABIN

/*

PARA MAIORES INFORMAÇÕES: https://github.com/eremidio/NUMBER-THEORY-ALGORITHMS/blob/main/berkelamp_rabin_modular_square_root.h

*/

//*******************************************************************************************************************
//CABEÇALHO
#ifndef POLYNOMIAL_ROOT_FINITE_FIELD_H
#define POLYNOMIAL_ROOT_FINITE_FIELD_H
#include"polynomial_gcd_finite_field.h"
#include"polynomial_exponentiation_finite_field.h"
#include"fast_polynomial_division_finite_field.h"
#include<random>

//*******************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> generate_split_polynomial(T);

template<typename T>
T generate_random_number(T);

template<typename T>
polynomial<T> generate_random_split_polynomial(T);

template<typename T>
T polynomial_root_finite_field(polynomial<T>&, T);

//*******************************************************************************************************************
//FUNÇÕES
//Função que gera um polinômio p(x)=x^p-x
template<typename T>
polynomial<T> generate_split_polynomial(T prime){

  //Variáveis locais
  polynomial<T> monomial;
  polynomial<T> split_poly;


  //Procedimento
    //Ajuste do monômio m(x)=x
    monomial.degree=1;
    monomial.polynomial_coefficients.push_back(1); monomial.polynomial_coefficients.push_back(0);
    monomial.polynomial_powers.push_back(1); monomial.polynomial_powers.push_back(0);

    //Ajuste do resultado: s(x)=m(x)^p-m(x)
    split_poly= polynomial_bin_pow<T, T>(monomial, prime);
    split_poly =  split_poly-monomial;

  //Resultado
  return split_poly;

};


//Função que gera um número aleatório em F(p)
template<typename T>
T generate_random_number(T prime){

  //Variáveis locais
  T min=2;
  T max=prime;
  T result;

  //Procedimentos
    //Ajuste da distribuição de números aleatórios
    std::random_device generator_x;
    std::mt19937 gen(generator_x());
    std::uniform_int_distribution<T> elliptic_distribution(min, max);

  //Resultado
  result=elliptic_distribution(generator_x);
  return result;

};

//Função que gera um polinômio mônico h(x)=(x+δ)^s-1, onde s=(p-1)/2 e δ é umelemento de F(p)
template<typename T>
polynomial<T> generate_random_split_polynomial(T prime){

  //Variáveis locais
  polynomial<T> random_split_poly;
  polynomial<T> monomial;
  polynomial<T> unity=generate_unity_polynomial<T>();
  T s = ((prime-1)>>1);
  T rand_int = generate_random_number<T>(prime);
  
  //Procedimentos
    //Ajuste do monômio m(x)=x+δ
    monomial.degree=1;
    monomial.polynomial_coefficients.push_back(1); monomial.polynomial_coefficients.push_back(rand_int);
    monomial.polynomial_powers.push_back(1); monomial.polynomial_powers.push_back(0);

    //Ajuste do resultado: s(x)=m(x)^p-1
    random_split_poly= polynomial_bin_pow_finite_field<T, T>(monomial, s, prime);
    random_split_poly = random_split_poly-unity;

  //Resultado
  return random_split_poly;

};


//Função que calcula raízes de um polinômio f(x) em um corpo finito do primeiro tipo F(p)
/*
NOTA: f(x) deve ser mônico (coeficiente do termo de maior grau deve ser 1) 
      para que o algoritmo funcione corretamente.
*/
template<typename T>
T polynomial_root_finite_field(polynomial<T>& p1, T prime){

  //Caso base: checando se f(0)=0,isto é, f(x) não possui monômios de grau 0 com coeficientes nulos
  if(horners_polynomial_evaluation<T, T>(p1, 0)==0) return 0; //Raíz trivial


  //Variáveis locais
  polynomial<T> split_polynomial=generate_split_polynomial<T>(prime);
  polynomial<T> random_split_polynomial;
  polynomial<T> g, h, Q, R;

  //Procedimentos
    //Testando se g(x)=x^p-x possuí algum fator comum com o polinômio f(x)
    g=polynomial_gcd_finite_field<T>(p1, split_polynomial, prime);
    if(g.degree<1){
      std::cout<<"Não há raízes de f(x) em F("<<prime<<")\n";
      return 0;
    };

  

    //Testando se polinômios h(x)=(x+δ)^s-1 tem fatores lineares com f(x)
    while(true){

      random_split_polynomial=generate_random_split_polynomial<T>(prime);
      h=polynomial_gcd_finite_field<T>(g, random_split_polynomial, prime);
      
      if(h.degree==1){
        g=h;
        break;
      }

      if(h.degree>0 && h.degree<g.degree)
        fast_polynomial_division_finite_field<T>(g, h, Q, R, prime);

      //Atualizando variáveis para a próxima iteração
      if(h.degree>R.degree) g=R;
      else  g=h;
        
    }


  //Resultado
  return  ((-1)*g.polynomial_coefficients[1]);

};


//*******************************************************************************************************************
//FIM DO HEADER
#endif
