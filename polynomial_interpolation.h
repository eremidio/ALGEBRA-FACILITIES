//VAMOS CRIAR UM PROGRAMA QUE CALCULA UMA INTERPOLAÇÃO DE POLINÔMIOS USANDO O ALGORITMO DE LAGRANGE 

/*

AFÓRMULA DE LAGRANGE PERMITE CALCULAR UM POLINÔMIO QUE FORNECE UMA BOA APROXIMAÇÃO PARA UMA
FUNÇÃO QUE TOMA VALORES SÉRIE DE PONTOS DE PONTOS { x(i), y(i)}, i=1,...,n. A FÓRMULA DE
INTERPOLAÇÃO DE LAGRANGE É DADA POR: p(x)=Σ{y(i)Π[x-x(i)]/[x(k)-x(i)]}, COM O PRODUTO
REALIZADO SOBRE VALORES k'S TAIS QUE k=1,..., (i-1), (i+1),...,n.

O MÉTODO DE LAGRANGE SE BASEIA NA EXPANSÃO LINEAR DO POLINÔMIO BUSCADO p(x) EM TERMOS DE
POLINÔMIOS Q(i, x) TAIS QUE: p(x)=Σy(i)Q(i, x) E Q(i, x(j))=δ(i,j), ONDE δ(i,j) É O SÍMBOLO DE
KRONECKER DEFINIDO COMO:
                        δ(i,j)={ 1 SE i=j
                               { 0 SE i≠j

PARA MAIORES INFORMAÇÕES: Mathematics; Its Content, Methods and Meaning by A. D. Aleksandrov, A. N. Kolmogorov, M. A. Lavrent'ev

*/


//*******************************************************************************************************
//CABEÇALHO
#ifndef POLYNOMIAL_INTERPOLATION_H
#define POLYNOMIAL_INTERPOLATION_H
#include"polynomial_exponentiation.h"

//*******************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> find_Q_polynomial(std::vector<T>&, std::vector<T>&, int64_t);

template<typename T>
polynomial<T> langrange_interpolation_formula(std::vector<T>&, std::vector<T>&);



//*******************************************************************************************************
//FUNÇÕES
//Função que calcula um polinômio auxiliar para interpolação de Lagrange

/*
NOTA: Erros de aproximação podem ocorrer ao se computar os polinômios dos coeficientes dos polinômios,
      devido a representações aproximadas de números reais.
*/
template<typename T>
polynomial<T> find_Q_polynomial(std::vector<T>& x_vector, std::vector<T>& y_vector, int64_t skip){

  //Variáveis locais
  polynomial<T> result=generate_unity_polynomial<T>();
  T denominator=1, multiplier;

  //Procedimentos
    //Loop sobre os arrays de pares ordenados
    for(int64_t i=0; i<x_vector.size(); ++i){
    
      //Checando a condição δ(i, skip)=1
      if(i==skip) continue;

      //Calculando os fatores lineares expansão do coeficiente 
      polynomial<T> linear_factor_poly;
      linear_factor_poly.degree=1;
      linear_factor_poly.polynomial_coefficients.push_back(1); linear_factor_poly.polynomial_coefficients.push_back(x_vector[i]*(-1));
      linear_factor_poly.polynomial_powers.push_back(1); linear_factor_poly.polynomial_powers.push_back(0);


      //Cálculo  do resultado parcial
      result=result*linear_factor_poly;
      denominator=denominator*(x_vector[skip]-x_vector[i]);

    }

    //Ajuste final dos coeficientes
    multiplier=y_vector[skip]/denominator;
    for(auto& c:result.polynomial_coefficients) c*=multiplier;


  //Resultado
  return result;

};


//Função que calcula um polinômio usando a técnica de interpolação de Lagrange

/*  
NOTA: Por conta da representação aproximada de números reais os coeficientes obtidos são apenas
      aproximaados. Um  resultado mais preciso é obtido representado s mcoeficientes na forma
      de frações quando se trabalha  com pontos (x,y) com coordenadas inteiras. Para valores
      obtidos de formas aleatórias ou usando-se coordenadas com valores no cojunto dos racionais
      erros de aprtoximação tendem a se acumular eoutras técnicas devem ser empregadas para
      maior precisão nos coeficientes. Usamos um par de std::vector para alocar as respectivas 
      coordenadas.

*/

template<typename T>
polynomial<T> langrange_interpolation_formula(std::vector<T>& x_vector, std::vector<T>& y_vector){



  //Variável locais
  polynomial<T> result=generate_zero_polynomial<T>();
  size_t i, bound=x_vector.size();


  //Procedimentos
    //Restrição
    if(bound!=y_vector.size()) return result; //Erro


    //Loop sobre os vetores que contém as coordenadas
    for(i=0; i<bound; ++i){
      
      polynomial<T> partial_poly=find_Q_polynomial<T>(x_vector, y_vector, i);
      result=result+partial_poly;

    }
  

  //Resultado
  return result;  

};



//*******************************************************************************************************
//FIM DO HEADER
#endif
