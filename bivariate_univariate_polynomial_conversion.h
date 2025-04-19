//VAMOS CRIAR UM PROGRAMA QUE EXTRAI POLINÔMIOS EM UMA VARIÁVEL A PARTIR DE POLINÔMIOS DE DUAS VARIÁVEIS

/*

O PRESENTE ALGORITMO É UMA SUBROTINA ÚTIL PARA COMPUTAR UMA SEQUÊNCIAS POLINOMIAIS A PARTIR DE UMA FUNÇÃO
GERADORA, QUE EM GERAL, É UMA SÉRIE FORMAL EM DUAS VARIÁVEIS DO TIPO F(x, y)= Σp(n, x){y^n}.


*/


//***********************************************************************************************
//CABEÇALHO
#ifndef BIVARIATE_UNIVARIATE_POLYNOMIAL_CONVERSION_H
#define BIVARIATE_UNIVARIATE_POLYNOMIAL_CONVERSION_H
#include"sparse_polynomials.h"
#include"bivariate_polynomials.h"


//***********************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> bivariate_univariate_polynomial_conversion(bivariate_polynomial<T>&, int64_t);


//***********************************************************************************************
//FUNÇÕES
//Função que extrai um termo fixo da série formal F(x, y)= ΣP(n, x){y^n} para um valor fixo de n 
template<typename T>
polynomial<T> bivariate_univariate_polynomial_conversion(bivariate_polynomial<T>& p1, int64_t y_index){

  //Variáveis locais
  polynomial<T> result;
  univariate_monomial<T> poly_term;


  //Procedimentos 
    //Loop principal: iterando sobre os coeficientes do polinômio de duas variáveis
    for(auto it=p1.monomials.begin(); it!=p1.monomials.end(); ++it){
      if(it->second.y_valuation==y_index){
         poly_term.power=it->second.x_valuation;
         poly_term.coefficient=it->second.coefficient;
         result.monomials.insert({poly_term.power, poly_term});
      }
      else continue;

    };

    //Caso base 
    if(result.monomials.empty()){
      poly_term.power=0;
      poly_term.coefficient=0;
      result.monomials.insert({poly_term.power, poly_term});
    }
  

  //Resultado
  return result;


};


//***********************************************************************************************
//FIM DO HEADER
#endif
