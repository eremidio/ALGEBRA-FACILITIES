//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO DE PSEUDODIVISÃO DE POLINÔMIOS

/*
PARA MAIORES REFERÊNCIAS: The Art Of Computer Programming Volume 2, by D. E. Knuth

*/ 

//************************************************************************************************
//CABEÇALHO
#ifndef POLYNOMIAL_PSEUDODIVISION_H
#define POLYNOMIAL_PSEUDODIVISION_H
#include<type_traits>
#include"polynomials.h"


//************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
T pseudodivision_bin_pow(T, int64_t);

template<typename T>
void polynomial_pseudodivision(polynomial<T>&, polynomial<T>&, polynomial<T>&, polynomial<T>&);

//************************************************************************************************
//FUNÇÕES 
//Função que implementa a exponenciação binária módular
template<typename T>
T pseudodivision_bin_pow(T a, int64_t b){

  // Variáveis locais
  T result = 1;

  //Procedimentos
    //Loop principal
    while (b > 0) {
      
      if (b & 1) result *= a;
      a = a * a;
      b >>= 1;
    };

  // Resultado
  return result;

};


//Função que implementa o algoritmo de pseudo-divisão de polinômios
template<typename T>
void polynomial_pseudodivision(polynomial<T>& A, polynomial<T>& B, polynomial<T>& quotient, polynomial<T>& remainder){

  //Restrição
  assert(A.degree>=B.degree);

  //Variáveis locais
  polynomial<T> Q;
  int64_t m=A.degree, n=B.degree;
  int64_t e=m-n+1;
  T d= B.polynomial_coefficients[0]; //Coeficiente do monômio de maior potência
  T q;

  //Procedimentos
    //Ajuste inicial de variáveis
    Q.degree=0; Q.polynomial_powers.push_back(0); Q.polynomial_coefficients.push_back(0);
    remainder=A;

    //Loop principal
    while(remainder.degree>=B.degree){
      //Definindo um polinômio auxiliar S
      polynomial<T> S;
      S.degree=(remainder.degree-B.degree);
      for(int64_t i=S.degree; i>=0;--i){

        S.polynomial_powers.push_back(i);

        if(i==S.degree) S.polynomial_coefficients.push_back(1);
        else S.polynomial_coefficients.push_back(0);

      }

      //Ajuste dos coeficientes dos polinômios R e Q
      for(auto& c1:Q.polynomial_coefficients) c1*=d;
      for(auto& c2:remainder.polynomial_coefficients) c2*=d;

      //Redução de Euclides
      polynomial<T> diff_poly=S*B;
      polynomial<T>temp= Q+S;
      polynomial<T>temp2= remainder-diff_poly;
      Q=temp;
      remainder=temp2;
      e--;

    }
    

    //Ajuste final do resultado
    q=pseudodivision_bin_pow(d, e);
    for(auto& c1:Q.polynomial_coefficients) c1*=q;
    for(auto& c2:remainder.polynomial_coefficients) c2*=q;
    quotient=Q;



};



//************************************************************************************************
//FIM DO HEADER
#endif
