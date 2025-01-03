//VAMOS CRIAR UM PROGRAMA QUE COMPUTA DE FORMA EXATA  O MDC DE POLINÔMIOS COM ENTRADAS INTEIRAS

/*
ESTA É UMA SUBROTINA ÚTIL EM OUTROS ALGORITMOS MAIS SOFISTICADOS COMO NOS ALGORITMOS DE
FATORAÇÃO DE POLINÔMIOS COM COEFICIENTES INTEIROS.

*/


//*********************************************************************************************************
//CABEÇALHO
#ifndef POLYNOMIAL_RATIONAL_GCD_H
#define POLYNOMIAL_RATIONAL_GCD_H
#include"polynomial_rational_arithmetic.h"


//*********************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<rational_number<T>> polynomial_rational_gcd(polynomial<rational_number<T>>&, polynomial<rational_number<T>>&);


//*********************************************************************************************************
//FUNÇÕES
template<typename T>
polynomial<rational_number<T>> polynomial_rational_gcd(polynomial<rational_number<T>>& p1, polynomial<rational_number<T>>& p2){

  //Restrição
  if(p1.degree<p2.degree) return  polynomial_rational_gcd(p2, p1);

  //Variáveis
  polynomial<rational_number<T>> u=p1, v=p2, t;
  polynomial<rational_number<T>> quotient, remainder;


  //Procedimentos
    //Loop  euclidiano
    while(1){
      
      //Calculando o quociente e o resto dos polinômios
      quotient=rational_polynomial_div<T>(u, v);    
      t=rational_polynomial_mul<T>(quotient, v);
      remainder=rational_polynomial_sub<T>(u, t);
      adjust_degree_rational_polynomial(remainder); 

      //Condição que determina o fim do loop
      if((remainder.polynomial_coefficients[0]).numerator==0) break;
      else{
        u=v;
        v=remainder;
      };

    }
  

  //Resultado
  return v;

};


//*********************************************************************************************************
//FIM DO HEADER
#endif
