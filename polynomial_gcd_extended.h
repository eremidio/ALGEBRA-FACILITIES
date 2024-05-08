//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA ROTINAS PARA O ALGORITMO DE EUCLIDES EXTENDIDO E PARA O CÁLCULO DE INVERSOS MODULARES PARA POLINÔMIOS


//************************************************************************************************************************************************
//CABEÇALHO
#ifndef POLYNOMIAL_GCD_EXTENDED_H
#define POLYNOMIAL_GCD_EXTENDED_H
#include"polynomial_gcd.h"
#include"polynomial_exponentiation.h"
#include"polynomial_cast.h"


//************************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
void polynomial_gcd_extended(polynomial<T>&, polynomial<T>&);

template<typename T>
polynomial<T> modular_inverse(polynomial<T>&, polynomial<T>&);

//************************************************************************************************************************************************
//FUNÇÕES
//Função que implementa o algoritmo de Euclides extendido para dois polinômios f(x) e g(x) sobre um corpo númerico com deg(f)>deg(g)
template<typename T>
void polynomial_gcd_extended(polynomial<T>& f, polynomial<T>& g){

 //Restrição: deg(f)>deg(g)
 if(f.degree<g.degree){
  polynomial_gcd_extended(g, f);
  return;
                      };
 //Variáveis locais
 polynomial<double> s=generate_unity_polynomial<double>();
 polynomial<double> t=generate_zero_polynomial<double>();
 polynomial<double> d=polynomial_cast<T, double>(f);
 polynomial<double> u=generate_zero_polynomial<double>();
 polynomial<double> v=generate_unity_polynomial<double>();
 polynomial<double> w=polynomial_cast<T, double>(g);


 //Procedimento
  // loop euclidiano
  while(is_zero_polynomial<double>(w)==false){
  
   //Cálculo do quociente intermediário
   polynomial<double> quotient=d/w;

   //Atualizando asvariáveis para a próxima iteração
   s=u;
   t=v;
   d=w;

   polynomial<double>u1=quotient*u;
   u=s-u1;
   polynomial<double>v1=quotient*v;
   v=t-v1;
   polynomial<double>w1=quotient*w;
   w=d-w1;       


                                             };


    //Ajustando os coeficientes do polinômios
     //Variáveis locais
     double leading_coefficient=1.0;

    //Determinandoo maior coeficiente de d(x)
    for(auto c:d.polynomial_coefficients){
     if(c!=0){
      leading_coefficient=c;
      break;
             }
                                         };


    //Ajustando os coeficientes dos polynômios
    for(auto& c1:d.polynomial_coefficients)
     c1=c1/leading_coefficient;
    for(auto& c2:s.polynomial_coefficients)
     c2=c2/leading_coefficient;
    for(auto& c3:t.polynomial_coefficients)
     c3=c3/leading_coefficient;


   //Convertendo polinômios para o argumento template original
   polynomial<T> dT=polynomial_cast<double, T>(d);
   polynomial<T> sT=polynomial_cast<double, T>(s);
   polynomial<T> tT=polynomial_cast<double, T>(t);


   //Resultado da execução do algoritmo
   std::cout<<"\nf(x): "<<f.algebraic()<<'\n';
   std::cout<<"g(x): "<<g.algebraic()<<'\n';
   std::cout<<"f(x)s(x)+g(x)t(x)=d(x)\nCoeficiente da identidade de Bézout:\n";
   std::cout<<"d(x): "<<dT.algebraic()<<'\n';
   std::cout<<"s(x): "<<sT.algebraic()<<'\n';
   std::cout<<"t(x): "<<tT.algebraic()<<'\n';


                                                                };



//Função que calcula o inverso modular de um polinômio
template<typename T>
polynomial<T> modular_inverse(polynomial<T>& f, polynomial<T>& g){


 //Variáveis locais
 polynomial<double> s=generate_unity_polynomial<double>();
 polynomial<double> t=generate_zero_polynomial<double>();
 polynomial<double> d=polynomial_cast<T, double>(f);
 polynomial<double> u=generate_zero_polynomial<double>();
 polynomial<double> v=generate_unity_polynomial<double>();
 polynomial<double> w=polynomial_cast<T, double>(g);


 //Procedimento
  // loop euclidiano
  while(is_zero_polynomial<double>(w)==false){
  
   //Cálculo do quociente intermediário
   polynomial<double> quotient=d/w;

   //Atualizando asvariáveis para a próxima iteração
   s=u;
   t=v;
   d=w;

   polynomial<double>u1=quotient*u;
   u=s-u1;
   polynomial<double>v1=quotient*v;
   v=t-v1;
   polynomial<double>w1=quotient*w;
   w=d-w1;       


                                             };


    //Ajustando os coeficientes do polinômios
     //Variáveis locais
     double leading_coefficient=1.0;

    //Determinandoo maior coeficiente de d(x)
    for(auto c:d.polynomial_coefficients){
     if(c!=0){
      leading_coefficient=c;
      break;
             }
                                         };


    //Ajustando os coeficientes dos polynômios
    for(auto& c1:d.polynomial_coefficients)
     c1=c1/leading_coefficient;
    for(auto& c2:s.polynomial_coefficients)
     c2=c2/leading_coefficient;
    for(auto& c3:t.polynomial_coefficients)
     c3=c3/leading_coefficient;


   //Convertendo polinômios para o argumento template original
   polynomial<T> dT=polynomial_cast<double, T>(d);
   polynomial<T> sT=polynomial_cast<double, T>(s);
   polynomial<T> tT=polynomial_cast<double, T>(t);


 //Resultado
 if(dT.degree==0)
  return sT;
 else{
  polynomial<T> zero_polynomial=generate_zero_polynomial<double>();
  return zero_polynomial;//Caso não exista o inverso modular
     } 
                                                                 };



//************************************************************************************************************************************************
//FIM DO HEADER
#endif
