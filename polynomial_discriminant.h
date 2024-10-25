//VAMOS CRIAR UM PROGRAMA QUE CALCULA O DISCRIMINANTE DE UM POLINÔMIO

/*
PARA MAIORES INFORMAÇÕES: A Course In Computational Algebraic Number Theory by Henri Cohen

*/


//******************************************************************************************************
//CABEÇALHO
#ifndef POLYNOMIAL_DISCRIMINANT_H
#define POLYNOMIAL_DISCRIMINANT_H
#include"polynomial_resultant.h"


//******************************************************************************************************
//DECLRAÇÃO DE FUNÇÕES
template<typename T>
T polynomial_discriminant(polynomial<T>&);

//******************************************************************************************************
//FUNÇÕES
//Função que calcula o discriminante de um polinômio f'(x)
template<typename T>
T polynomial_discriminant(polynomial<T>& p1){

  //Casos bases
  if(p1.degree==0) return 0;
  if(p1.degree==1) return 1;


  //Variáveis locais
  polynomial<T> poly_der=polynomial_derivative<T>(p1);
  T resultant;
  T lead_coefficient=p1.polynomial_coefficients[0];
  int64_t t;


  //Procedimentos
    //Calculando o resultante de f(x) e f'(x)
    poly_der.polynomial_coefficients.pop_back();
    resultant=polynomial_resultant<T>(p1, poly_der);

    //Calculando a paridade do discriminante
    t=(p1.degree-1)*p1.degree;
    t>>=1;

  //Resultado
  if(t&1) return (((-1)*resultant)/lead_coefficient);
  else return (resultant/lead_coefficient);


};



//******************************************************************************************************
//FIM DO HEADER
#endif
