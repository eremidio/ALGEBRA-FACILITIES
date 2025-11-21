//VAMOS CRIAR UM PROGRAMA QUE COMPUTA A OPERAÇÃO DE REDUÇÃO MODULAR COM POLINÔMIOS ESPARSOS MÔNICOS

/*

SUBROTINA ÚTIL PARA OUTROS ALGORITMOS EM ESPECIAL PARA SE FAZER ARITMÉTICA EM CORPOS FINITOS DO SEGUNDO
POLINÔMIOS COM COEFICIENTES RESTRITOS A GF(p) (INTEIROS A MENOS DE UMA CONGRUÊNCIA MÓDULO p).

*/ 

//********************************************************************************************************
//CABEÇALHO
#ifndef SPARSE_POLYNOMIAL_REDUCTION_H
#define SPARSE_POLYNOMIAL_REDUCTION_H
#include"sparse_polynomials.h"


//********************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> generate_polynomial_reducer(polynomial<T>&, int64_t&);

template<typename T>
polynomial<T> generate_polynomial_reduced_piece(polynomial<T>&, univariate_monomial<T>&);

template<typename T>
polynomial<T> polynomial_mod(polynomial<T>&, polynomial<T>&);


//********************************************************************************************************
//FUNÇÕES
//Função que computa um polinômio base usado na operação de redução modular
template<typename T>
polynomial<T> generate_polynomial_reducer(polynomial<T>& p1, int64_t& cut_degree){

  //Variáveis locais
  polynomial<T> result=p1;

  
  //Procedimentos
    //Ajuste de variáveis 
    auto it =result.monomials.begin();
    cut_degree=it->second.power;
    it = result.monomials.erase(it);

    for(auto it=result.monomials.begin(); it!=result.monomials.end(); ++it)
      it->second.coefficient=it->second.coefficient*(-1);


  //Resultado
  return result;

};


//Função que computa um polinômio intermediário na operação de redução modular
template<typename T>
polynomial<T> generate_polynomial_reduced_piece(polynomial<T>& reducer, univariate_monomial<T>& m1){

  //Variáveis locais
  polynomial<T> partial;
  
  
  //Procedimento
    //Definindo um polinômio intermediário nos cálculos
    partial.monomials.insert({m1.power, m1});


  //Resultado
  polynomial<T> result=partial*reducer;
  return result;

};


//Função que computa a redução modular de dois polinômios
/*
  NOTA: A classe de polinômios esparsos possui um método polynomial_mod<T, U>() que reduz os
        os coeficientes de um polinômio por um inteiro. Estas duas funções podem ser combina-
        das em algoritmos que trabalhem com corpos finitos do segundo tipo.

*/
template<typename T>
polynomial<T> polynomial_mod(polynomial<T>& p1, polynomial<T>& p2){

  //Caso base:
  if(p1.degree()<p2.degree()) return p1;

  //Variáveis locais
  polynomial<T> reducer, result;
  univariate_monomial<T> zero_monomial(0,0);
  int64_t cut_degree;


  //Procedimento
    //Inicializando variáveis
    result.monomials.insert({zero_monomial.power, zero_monomial});
    reducer=generate_polynomial_reducer<T>(p2, cut_degree);

    //Loop principal: iterando sobre os monômios do polinômio a ser reduzido
    for(auto it=p1.monomials.begin(); it!=p1.monomials.end(); ++it){

      if((it->second.power)>=cut_degree){
        univariate_monomial<T> m1=it->second;
        m1.power=m1.power-cut_degree;
        polynomial<T> partial=generate_polynomial_reduced_piece<T>(reducer, m1);
        result=result+partial;
      }
      else{
        univariate_monomial<T> m1=it->second;
        polynomial<T> partial;
        partial.monomials.insert({m1.power, m1});
        result=result+partial;
      }

    };


  //Resultado
  if(result.degree()>=p2.degree()) return result=polynomial_mod(result, p2);
  else return result;

};


//********************************************************************************************************
//FIM DO HEADER
#endif
