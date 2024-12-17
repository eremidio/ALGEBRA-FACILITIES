//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO DE EUCLIDES EXTENDIDO PARA POLINÔMIOS COM COEFICIENTES REAIS

/*
PARA MAIORES INFORMAÇÕES: Prime Numbers A computational Perspective, by Richard Crandall and Carl Pomerance

*/


//*************************************************************************************************************
//CABEÇALHO
#ifndef POLYNOMIAL_EXTENDED_GCD_H
#define POLYNOMIAL_EXTENDED_GCD_H
#include"polynomial_cast.h"
#include"polynomial_exponentiation.h"
#include"polynomial_monic.h"
#include"polynomial_gcd.h"


//*************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
void polynomial_extended_euclidean_algorithm(polynomial<T>&, polynomial<T>&, polynomial<T>&, polynomial<T>&, polynomial<T>&);


//*************************************************************************************************************
//FUNÇÕES
//Função que implementa o algoritmo extendido de Euclides para inteiros com coeficientes reais
/*
NOTA: Erros de truncamento ocorrem devido a representações aproximadas de números reais.
      Em caso de coeficientes inteiros o uso de uma classe de frações fornece resultado
      preciso.
*/

template<typename T> /* Identidade de Bézout: A(x)p1(x)+B(x)p2(x)=mdc(p1(x), p2(x))*/
void polynomial_extended_euclidean_algorithm(polynomial<T>&  p1, polynomial<T>& p2, polynomial<T>& A, polynomial<T>& B, polynomial<T>& gcd_poly){

  //Restrição
  assert(p1.degree>=p2.degree);

  //Variáveis locais
  polynomial<double> r0=polynomial_cast<T, double>(p1);
  polynomial<double> r1=polynomial_cast<T, double>(p2);
  polynomial<double> s0=generate_unity_polynomial<double>();
  polynomial<double> s1=generate_zero_polynomial<double>();
  polynomial<double> t0=generate_zero_polynomial<double>();
  polynomial<double> t1=generate_unity_polynomial<double>();
  polynomial<double> s2, t2;


  //Procedimento
    //Loop principal
    while(1){

      //Calculando o quociente e o resto da divisão
      polynomial<double> quotient=r0/r1, temp, remainder;
      temp=r1*quotient; remainder=r0-temp;


      //Atualizando variáveis para a próxima iteração
      r0=r1;
      r1=remainder;
      r1 = make_monic_polynomial<double>(r1);


      polynomial<double> temp1=quotient*s1;
      polynomial<double> temp2=quotient*t1;

      s2=s0-temp1;      
      t2=t0-temp2;

      s0=s1;
      s1=s2;
      t0=t1;
      t1=t2; 


      //Fim do loop 
      if(is_zero_polynomial<double>(r1)  || r1.polynomial_coefficients.size()==0 || (r1.polynomial_coefficients[0]==0 && r1.degree==0))
        break;     


    };


  //Resultado da execusção do algoritmo
  gcd_poly=polynomial_cast<double, T>(r0);
  A = polynomial_cast<double, T>(s0); B=polynomial_cast<double, T>(t0); 
  

};

//*************************************************************************************************************
//FIM DO HEADER
#endif
