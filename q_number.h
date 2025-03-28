//VAMOS CRIAR UM PROGRAMA QUE CALCULA NÚMEROS-Q

/*
NÚMEROS-Q SÃO Q-ANÁLOGOS (EXPANSÕES FORMAIS EM UMA VARIÁVEL q) DE NÚMEROS INTEIROS DEFINIDOS PELA
EXPRESSÃO: [n]={1-(q^n)}/{1-q}. NO LIMITE q->1 TÊM-SE QUE [n]=n. TAIS EXPRESSÕES SÃO UTÉS EM 
CERTOS TIPOS DE MANIPULAÇÕES SIMBÓLICAS.

PARA MAIORES INFORMAÇÕES: Number Theory in the Spirit of Ramanujan by Bruce C. Berndt
                          https://mathworld.wolfram.com/q-Analog.html


*/


//************************************************************************************************
//CABEÇALHO
#ifndef Q_NUMBER_H
#define Q_NUMBER_H
#include"sparse_polynomials.h"


//************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> compute_q_number(int64_t);


//************************************************************************************************
//FUNÇÕES
//Função que computa o análogo-q de um número inteiro
template<typename T>
polynomial<T> compute_q_number(int64_t n){

  //Variáveis locais
  polynomial<T> den, num, q_number;
  univariate_monomial<T> q_term;


  //Procedimentos
    //Definindo o numerador e o denominador da expressão formal de [n]
    q_term.coefficient=1;  q_term.power=0;
    den.monomials.insert({q_term.power, q_term});
    num.monomials.insert({q_term.power, q_term});

    q_term.coefficient=(-1);  q_term.power=1;
    den.monomials.insert({q_term.power, q_term});

    q_term.coefficient=(-1);  q_term.power=n;
    num.monomials.insert({q_term.power, q_term});

    //Calculando o valor de [n]
    q_number=num/den;


  //Resultado
  return q_number;

};


//************************************************************************************************
//FIM DO HEADER
#endif
