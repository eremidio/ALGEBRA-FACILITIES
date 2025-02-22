//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA ROTINAS PARA COMPUTAR SÍMBOLOS DE Q-POCHHAMMER  

/*
SÍMBOLOS DE POCHHAMMER SÃO DEFINIDOS PELA RELAÇÃO: x(n)=Γ(x+n)/Γ(n)=x(x+1)...(x+n-1). ELES 
TAMBÉM SÃO DENOMINADOS FATORIAIS ASCENDENTES.

O SÍMBOLOS DE Q-POCHHAMMER SÃO DEFINIDOS PELAS RELAÇÕES:
a(n) = (a; q)(n) = Π{1-a(q^k)} k=0,1,2,..., (n-1) SE n>0
a(0) = (a; q)(0)=1
a(∞) = (a; q)(∞) = Π{1-a(q^k)} k=0,1,2,...
q(∞) = (q; q)(∞) = Π{1-(q^k)} k=1,2,...

EM ALGUNS CONTEXTOS DEFINIÇÕES PARA n<0 SÃO ÚTEIS TAMBÉM.


A SEGUINTE IDENTIDADE QUE É FACILMENTE DEMONSTRÁVEL:
q->1  ----> ((q^a); q)/{(1-q)^n}=a(a+1)...(a+n-1), MOSTRA QUE TAIS SÍMBOLOS SÃO ÚTEIS EM
COMPUTAÇÕES SIMBÓLICAS EM ANÁLISE COMBINATÓRIA.

MUITOS TEOREMAS E FÓRMULAS MATEMÁTICAS SÃO OBTIDOS QUANDO USAMOS TAIS SÍMBOLOS EM
MANIPULAÇÕES SÍMBÓLICAS, ESTES SÃO CHAMADOS DE Q-ANÁLOGOS. EM GERAL COM O LIMITE q->n, COM 
n INTEIRO, PODEMOS OBTER OS MESMOS TEOREMAS E FÓRMULAS NAS VERSÕES ORIGINAIS.

AS CHAMADAS SÉRIES Q SÃO SÉRIES (FREQUENTEMENTE INFINITAS) ENVOLVENDO SÍMBOLOS DE 
Q-POCHHAMMER. ELAS SÃO ÚTEIS EM VÁRIAS ÁREAS DA MATEMÁTICA COMO TEORIA DOS NÚMEROS NA QUAL
ESTÁ DIRETAMENTE ASSOCIADA A TEORIA DE FORMAS MODULARES E A COMPUTAÇÃO DE FUNÇÕES
ARITMÉTICAS E EM FÍSICA, POR EXEMPLO, NA ENUMERAÇÃO DE DIFERENTES ESTADOS QUÂNTICOS EM
REDES CRISTALINAS.

NAS MANIPULAÇÕES SIMBÓLICAS ENVOLVENDO SÍMBOLOS DE Q-POCHHAMMER q É APENAS UM SÍMBOLO
FORMAL. USAREMOS A CLASSE DE POLINÔMIOS ESPARSOS PARA REPRESENTAR TAIS SÍMBOLOS.

PARA MAIORES INFORMAÇÕES: Number Theory in the Spirit of Ramanujan by Bruce C. Berndt
                          https://mathworld.wolfram.com/q-Series.html
                          https://mathworld.wolfram.com/q-PochhammerSymbol.html
                          https://mathworld.wolfram.com/PochhammerSymbol.html


*/



//*************************************************************************************************
//CABEÇALHO
#ifndef Q_POCHHAMMER_SYMBOL_H
#define Q_POCHHAMMER_SYMBOL_H
#include"sparse_polynomials.h"


//*************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES 
template<typename T>
polynomial<T> compute_q_pochhammer_symbol(int64_t);

template<typename T>
polynomial<T> compute_q_pochhammer_symbol(int64_t, int64_t);


//*************************************************************************************************
//FUNÇÕES
//Função que calcula uma parcial do símbolo de q-Pochhammer (q; q)(∞) 
template<typename T>
polynomial<T> compute_q_pochhammer_symbol(int64_t n){

  //Variáveis locais
  polynomial<T> q_symbol;
  univariate_monomial<T> q_term;


  //Procedimentos
    //Caso base 
    if(n==0){
      q_term.coefficient=1;  q_term.power=0;
      q_symbol.monomials.insert({q_term.power, q_term});
      return q_symbol;
    };

    //Caso geral:
      //Adicionando o primeiro termo (1-q)
      q_term.coefficient=1;  q_term.power=0;
      q_symbol.monomials.insert({q_term.power, q_term});
      q_term.coefficient=(-1);  q_term.power=1;
      q_symbol.monomials.insert({q_term.power, q_term});

      //Adicionando os demais termos
      for(int64_t i=2; i<=n; ++i){
    
        polynomial<T> q_partial;
  
        q_term.coefficient=1;  q_term.power=0;
        q_partial.monomials.insert({q_term.power, q_term});
        q_term.coefficient=(-1);  q_term.power=i;
        q_partial.monomials.insert({q_term.power, q_term});

        q_symbol=q_symbol*q_partial;

     };

  //Resultado
  return q_symbol;
    

};



//Função que calcula o símbolo de q-Pochhammer (a; q)(n), uma parcial do símbolo de q-Pochhammer (a; q)(∞) 
template<typename T>
polynomial<T> compute_q_pochhammer_symbol(int64_t a, int64_t n){

  //Variáveis locais
  polynomial<T> q_symbol;
  univariate_monomial<T> q_term;


  //Procedimentos
    //Caso base 
    if(n==0){
      q_term.coefficient=(1-a);  q_term.power=0;
      q_symbol.monomials.insert({q_term.power, q_term});
      return q_symbol;
    };

    //Caso geral:
      //Adicionando o primeiro termo (1-a)
      q_term.coefficient=(1-a);  q_term.power=0;
      q_symbol.monomials.insert({q_term.power, q_term});

      //Adicionando os demais termos
      for(int64_t i=1; i<n; ++i){
    
        polynomial<T> q_partial;
  
        q_term.coefficient=1;  q_term.power=0;
        q_partial.monomials.insert({q_term.power, q_term});
        q_term.coefficient=((-1)*a);  q_term.power=i;
        q_partial.monomials.insert({q_term.power, q_term});

        q_symbol=q_symbol*q_partial;

     };

  //Resultado
  return q_symbol;
    

};


//*************************************************************************************************
//FIM DO HEADER
#endif
