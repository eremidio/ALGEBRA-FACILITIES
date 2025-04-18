//VAMOS CRIAR UM PROGRAMA QUE UTILIZA O ALGORITMO DE KARATSUBA PARA MULTIPLICAÇÃO DE POLINÔMIOS ESPARSOS

/*

O ALGORITMO DE KARATSUBA PARA MULTIPLICAÇÃO POLINOMIAL É UM EFICIENTE ALGORITMO PARA MULTIPLICAÇÃO DE 
POLINÔMIOS EM UMA VARIÁVEL ANÁLOGO AO ALGORITMO DE MESMO NOME PARA MULTIPLICAÇÃO DE INTEIROS. A IDEIA
DO ALGORITMO É TRABALHAR COM POLINÔMIOS COM UM MENOR NÚMERO DE TERMOS AO CUSTO DE ALGUMAS OPERAÇÕES
DE ADIÇÃO E SUBTRAÇÃO  EXTRAS.

SEJAM A(x) E B(x) DOIS POLINÔMIOS DE GRAU SUPERIOR A n (COM n INTEIRO), PODEMOS ESCREVER ESTES
POLINÔMIOS COMO: A(x)=A0(x)+A1(x)(x^n) E B(x)=B0(x)+B1(x)(x^n). DEFINIMOS OS SEGUINTES POLINÔMIOS
ADICIONAIS P1(x)=A0(x)B0(x), P2(x)=A1(x)B1(x) E P3(x)=[A0(x)+A1(x)][B0(x)+B1(x)]. USANDO ESTE TERMOS
INTERMEDIÁRIOS PODEMOS CHECAR A IDENTIDADE: A(x)B(x)=P1(x)+[P3(x)-P1(x)-P2(x)]x^n+[P2(x)]x^(2n).
MULTIPLICAÇÃO POR x^(2n) E (x^n) É EQUIVALENTE A AUMENTAR OS EXPOENTES DOS RESPECTIVOS TERMOS POR
2n E n RESPECTIVAMENTE. PARA A DECOMPOSIÇÃO DE A(x) E B(x) NENHUMA OPERAÇÃO É NECESSÁRIA.

O ALGORITMO DE KARATSUBA TEM COMPLEXIDADE O(n^α), ONDE α=log2(3) SENDO MAIS EFICIENTE QUE O ALGORITMO
USUAL DE COMPLEXIDADE O(n^2).


PARA MAIORES INFORMAÇÕES: https://maths-people.anu.edu.au/~brent/pd/number_theoretic_algs.pdf


*/


//*********************************************************************************************************
//CABEÇALHO
#ifndef SPARSE_POLYNOMIAL_KARATSUBA_MULTIPLICATION_H
#define SPARSE_POLYNOMIAL_KARATSUBA_MULTIPLICATION_H
#include"sparse_polynomials.h"


//*********************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
void karatsuba_decomposition(polynomial<T>&, polynomial<T>&, polynomial<T>&, int64_t);

template<typename T>
polynomial<T> karatsuba_sparse_polynomial_multiplication(polynomial<T>&, polynomial<T>&, int64_t);

//*********************************************************************************************************
//FUNÇÃO
//Função que decompõe um polinômio de grau >n em dois polinômios com um número menor de termos
template<typename T>
void karatsuba_decomposition(polynomial<T>& A, polynomial<T>& A0, polynomial<T>& A1, int64_t n){


  //Variáveis locais 
  univariate_monomial<T> poly_term;
  int64_t poly_term_index;


  //Procedimentos
    //Loop principal: iterando sobre os monômios do polinômio a ser decomposto
    for(auto it=A.monomials.begin(); it!=A.monomials.end(); ++it){
      poly_term_index=it->second.power;

      if(poly_term_index>n){
        poly_term.coefficient=(it->second.coefficient);
        poly_term.power=(poly_term_index-n);
        A1.monomials.insert({poly_term.power, poly_term});
        continue;
      }
      else{
        poly_term.coefficient=(it->second.coefficient);
        poly_term.power=(poly_term_index);
        A0.monomials.insert({poly_term.power, poly_term});
      };

    
    };

    //Ajuste fino do resultado
    poly_term.coefficient=0;
    poly_term.power=0;
    if (A0.monomials.empty()) A0.monomials.insert({poly_term.power, poly_term});
    if (A1.monomials.empty()) A1.monomials.insert({poly_term.power, poly_term});

};


//Função que executa o algoritmo de Karatsuba para multiplicar dois polinômios
template<typename T>
polynomial<T> karatsuba_sparse_polynomial_multiplication(polynomial<T>& A, polynomial<T>& B, int64_t threshold){


  //Váriáveis locais
  polynomial<T> result, P, P1, P2, P3; 
  polynomial<T>  A0, A1, B0, B1, multiplier;
  univariate_monomial<T> poly_term;  
  int64_t split_index=A.degree();


  //Procedimentos
    //Ajuste de variáveis      
    if(split_index>B.degree()) split_index=B.degree();
    split_index>>=1;
    

    //Decompondo os coeficientes dos polinômios a serem multiplicados
    karatsuba_decomposition(A, A0, A1, split_index);
    karatsuba_decomposition(B, B0, B1, split_index);

  
    //Calculando os polinômios intermediários usados no cálculo
    if(A0.degree()<threshold || B0.degree()<threshold) P1=A0*B0;
    else P1=karatsuba_sparse_polynomial_multiplication(A0, B0, threshold);
    if(A1.degree()<threshold || B1.degree()<threshold) P2=A1*B1;
    else P2=karatsuba_sparse_polynomial_multiplication(A1, B1, threshold);

    P=A0+A1; P3=P;
    P=B0+B1; P3=P3*P;
    P3=P3-P1; P3=P3-P2;
  
    poly_term.coefficient=1; poly_term.power=split_index;
    multiplier.monomials.insert({poly_term.power, poly_term}); 

    P3=P3*multiplier;
    P2=P2*multiplier;
    P2=P2*multiplier;

    //Calculando o resultado final
    result=P1; result=result+P3;  result=result+P2;


  //Resultado
  return result;

};

//*********************************************************************************************************
//FIM DO HEADER
#endif
