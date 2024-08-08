//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO DE STURM

/*
PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Sturm%27s_theorem#The_theorem

*/ 

//*******************************************************************************************************
//CABEÇALHO
#ifndef STURM_POLYNOMIAL_ALGORITHM_H
#define STURM_POLYNOMIAL_ALGORITHM_H
#include"polynomial_root.h"
#include<cassert>

//*******************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T, typename U>
int64_t real_root_counting(polynomial<T>, T, T);


//*******************************************************************************************************
//FUNÇÕES
//Função que implementa o algoritmo de Sturm para computar o número de raízes reais de um polinômio em 
//um intervalo [a, b] da reta real (polinômio não deve ter fatores primos repetidos)
template<typename T, typename U>
int64_t real_root_counting(polynomial<T> poly1, T a, T b){

  //Restrição
  assert(b>a && poly1.degree>2);

  //Variáveis locais
  polynomial<T> der_poly1=polynomial_derivative<T>(poly1);
  std::vector<polynomial<T>> polynomial_chain;
  std::vector<U> a_results;
  std::vector<U> b_results;
  int64_t a_sign_changes=0, b_sign_changes=0;

  //Procedimentos

    //Computando a cadeia de polinômios usadas no algoritmo
    polynomial_chain.push_back(poly1);
    polynomial_chain.push_back(der_poly1);

    //Loop principal: computando sucessivas derivadas do polinômio f²(x),..., f^n(x)=c 
    while(1){
      polynomial<T> temp=remainder(polynomial_chain[polynomial_chain.size()-2], polynomial_chain[polynomial_chain.size()-1]);
      for(auto& c:temp.polynomial_coefficients) c*=(-1);
      polynomial_chain.push_back(temp);
      if(temp.degree==0) break;

    }

    //Compultando o valor da cadeia de polinômios comnputadas nos extremos do intervalo
    for(int64_t i=0; i<polynomial_chain.size(); ++i){
      
      a_results.push_back(polynomial_chain[i].evaluate_polynomial(a));
      b_results.push_back(polynomial_chain[i].evaluate_polynomial(b));

    }


    //Computando a mudança de sinais nos valores da cadeia do polinômios nos extremos do intervalo
    for(int64_t j=0; j<polynomial_chain.size()-1; ++j){
      if((a_results[j]>=0 && a_results[j+1]<0) || (a_results[j]<0 && a_results[j+1]>=0))
        a_sign_changes++;
      if((b_results[j]>=0 && b_results[j+1]<0) || (b_results[j]<0 && b_results[j+1]>=0))
        b_sign_changes++;
    }

  //Resultado
  return (a_sign_changes-b_sign_changes);

};



//*******************************************************************************************************
//FIM DO HEADER
#endif
