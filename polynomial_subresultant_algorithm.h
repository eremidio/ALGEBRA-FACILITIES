//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA ROTINAS PARA CALCULAR O RESULTANTE, O DISCRIMINANTE E O MDC DE DOIS POLINÔMIOS 

/*
PARA MAIORES INFORMAÇÕES: The Art Of Computer Programming Volume 2, by D. E. Knuth
                          A Course In Computational Algebraic Number Theory by Henri Cohen
*/


//**************************************************************************************
//CABEÇALHO
#ifndef POLYNOMIAL_SUBRESULTANT_ALGORITHM_H
#define POLYNOMIAL_SUBRESULTANT_ALGORITHM_H
#include"polynomial_pseudo_division.h"
#include"polynomial_gcd_unique_factorization_domain.h"
#include"polynomial_root.h"


//**************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> polynomial_subresultant_gcd(polynomial<T>&, polynomial<T>&);

template<typename T>
T polynomial_resultant(polynomial<T>&, polynomial<T>&);

template<typename T>
T polynomial_discriminant(polynomial<T>&);


//**************************************************************************************
//FUNÇÕES
//Função que calcula o gcd de dois polinômios
template<typename T>
polynomial<T> polynomial_subresultant_gcd(polynomial<T>& A, polynomial<T>& B){

  //Caso base: B(x)=0
  if(B.polynomial_coefficients.size()==0 || (B.degree==0 && B.polynomial_coefficients[0]==0)){
    polynomial<T> result=A;
    return A;
  }

  //Caso base: deg(B)>deg(A)
  if(B.degree>A.degree) return polynomial_subresultant_gcd(B, A);


  //Variáveis locais
  T a, b, d, g=1, h=1;
  polynomial<T> Q, R, result;
  int64_t delta;


  //Procedimentos
    //Inicializando variáveis
    a=ufd_gcd_vector<T>(A.polynomial_coefficients);
    b=ufd_gcd_vector<T>(B.polynomial_coefficients);
    d=ufd_gcd<T>(a, b);

    if(a>1){
      for(auto& ca:A.polynomial_coefficients) ca/=a;
    }
    if(b>1){
      for(auto& cb:B.polynomial_coefficients) cb/=b;
    }
  


    //Loop principal
    while(1){

      //Cálculo do pseudoquociente e pseudoresto dos polinômios A e B
      polynomial_pseudodivision(A, B, Q, R);
      delta=(A.degree-B.degree);

      //Condição que determina o fim do loop principal
      if(R.polynomial_coefficients.size()<1 || R.polynomial_coefficients[0]==0)
        break;
      if(R.degree<1){
          B.degree=0;
          B.polynomial_coefficients.resize(0); B.polynomial_coefficients.push_back(1);
          B.polynomial_powers.resize(0); B.polynomial_powers.push_back(0);
          break;  //B(x)=1
        }

      //Atualizando variáveis para a próxima iteração
      A=B;
      B=R;
      for(auto& cb:B.polynomial_coefficients) cb/=(g*pseudodivision_bin_pow(h, delta));
      g=A.polynomial_coefficients[0];
      h=h*pseudodivision_bin_pow((g/h), delta);

    }

    //Ajuste do resultado 
    result=B;
      for(auto& cb:B.polynomial_coefficients){
        cb*=d;
        cb/=b;
      }


  //Resultado
  return  result;

};


//Função que calcula o resultante de dois polinômios
template<typename T>
T polynomial_resultant(polynomial<T>& A, polynomial<T>& B){

  //Casos bases: um dos polinômios tem grau 0
  if(A.degree==0 || B.degree==0) return 0;
  if(A.polynomial_coefficients.size()<1 || A.polynomial_coefficients[0]==0) return 0;
  if(B.polynomial_coefficients.size()<1 || B.polynomial_coefficients[0]==0) return 0;


  //Variáveis locais
  T a, b, g, h, s, t;
  int64_t delta;
  polynomial<T> Q, R;


  //Procedimentos
    //Ajuste de variáveis
    a=ufd_gcd_vector<T>(A.polynomial_coefficients);
    b=ufd_gcd_vector<T>(B.polynomial_coefficients);
    g=1; h=1; s=1;
    t=pseudodivision_bin_pow(a, B.degree)*pseudodivision_bin_pow(b, A.degree);

    if(A.degree<B.degree){
      s=(-1);
       polynomial<T>  temp=A;
       A=B;
       B=temp;
    }



    //Loop principal
    while(1){

      //Cálculo do pseudoquociente e pseudoresto dos polinômios A e B
      delta=(A.degree-B.degree);
      if((A.degree&1) && (B.degree&1)) s*=(-1); //Ajuste da paridade do resultado
      polynomial_pseudodivision(A, B, Q, R);

      
      //Ajuste de variáveis para a próxima iteração
      A=B;
      B=R;
      for(auto& cb:B.polynomial_coefficients) cb/=(g*pseudodivision_bin_pow(h, delta));

      g=A.polynomial_coefficients[0];
      h=h*pseudodivision_bin_pow((g/h), delta);
      if(B.degree<1 || B.polynomial_coefficients.size()<1 || B.polynomial_coefficients[0]==0) break;

    }

    //Ajuste final do parâmetro h
    h=h*pseudodivision_bin_pow((B.polynomial_coefficients[0]/h), A.degree);


  //Resultado
  return (s*t*h);


};


//Função que calcula o valor do discriminante de um polinômio
template<typename T>
T polynomial_discriminant(polynomial<T>& A){

  //Caso bases:
  if(A.degree==0) return 0;
  if(A.degree==1) return 1;


  //Variáveis locais
  polynomial<T> A_prime=polynomial_derivative<T>(A);
  int64_t sign;
  T resultant=polynomial_resultant<T>(A, A_prime);


  //Procedimentos
    //Checando a paridade do resultado
    int64_t m=(A.degree*(A.degree-1))/2;
    if(m&1) sign=(-1);
    else sign=1;


  //Resultado
  return (sign*resultant)/A.polynomial_coefficients[0];


};


//**************************************************************************************
//FIM DO HEADER
#endif
