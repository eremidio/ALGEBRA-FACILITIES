//VAMOS CRIAR UM PROGRAMA QUE CALCULA O POLINÔMIO CARACTERÍSTICO ASSOCIADO A UMA MATRIZ USANDO O ALGORITMO DE FADDEEV-LEVERRIER


/*
O ALGORITMO DE FADDEEV-LEVERRIER É UM ALGORITMO USADO PARA COMPUTAR O POLINÔMIOCARACTERÍSTICO
ASSOCIADO A UMA MATRIZ. O ALGORITMO NÃO É O MAIS VANTAJOSO DO PONTO DE VISTA DE EFICIÊNCIA,
PORÉM POSSUI A VANTAGEM DE OPERAR DIRETAMENTE COM OS COEFICIENTES DE UMA MATRIZ E PERMITIR
COMPUTAR AS MATRIZES ADJUGATAS DE UMA DADA MATRIZ, ALÉM DA FÁCIL IMPLEMENTAÇÃO PROVIDO DE UMA
ROTINA EFICIENTE PARA MULTIPLICAÇÃO DE MATRIZES.


PARA MAIORES REFERÊNCIAS: https://en.wikipedia.org/wiki/Faddeev–LeVerrier_algorithm#:~:text=In%20mathematics%20(linear%20algebra)%2C%20the,−%20A)%20%7B%5Cdisplaystyle%20p_%7BA%7D(%5Clambda)%3D%5Cdet(%5Clambda%20I_%7Bn%7D-A)%7D
                          https://math.stackexchange.com/questions/405822/what-is-the-fastest-way-to-find-the-characteristic-polynomial-of-a-matrix
                          https://en.wikipedia.org/wiki/Cayley–Hamilton_theorem

*/


//*******************************************************************************************
//CABEÇALHO
#ifndef MATRIX_CHARACTERISTIC_POLYNOMIAL_H
#define MATRIX_CHARACTERISTIC_POLYNOMIAL_H
#include"polynomials.h"
#include"matrix.h"


//*******************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
T matrix_trace(Matrix<T>&);


template<typename T>
polynomial<T> faddeev_leverrier_algorithm(Matrix<T>&);


//*******************************************************************************************
//FUNÇÕES
//Função que calcula o traço de uma matriz
template<typename T>
T matrix_trace(Matrix<T>& m1){
  
  //Restrição
  assert(m1.rows==m1.columns);

  //Variaveis locais
  T trace=0;

  //Procedimentos
    //Loop sobre elementos diagonais
    for(int64_t i=0; i<m1.rows; ++i) trace=(trace+m1.matrix[i][i]);

  //Resultado
  return trace;

};


//Função que calcula o polinômio característico associado a uma matriz usando o algoritmo de Faddeev-LeVerrier
template<typename T>
polynomial<T> faddeev_leverrier_algorithm(Matrix<T>& m1){

  //Restrição
  assert(m1.rows==m1.columns);

  //Variáveis locais
  polynomial<T> characteristic_polynomial;
  Matrix<T> I(m1.rows, Identity), Ic, Mk(m1.rows, Zero), M;
  T c=1;
  
  //Procedimentos
    //Ajuste do grau e do array de coeficientes do polinômio característico
    characteristic_polynomial.degree=m1.rows;
    for(int64_t k=characteristic_polynomial.degree; k>=0; --k)
      characteristic_polynomial.polynomial_powers.push_back(k);

    characteristic_polynomial.polynomial_coefficients.push_back(c);//Coeficiente do termo de maior grau


  //Loop principal: Cálculo recursivo dos coeficientes do polinômio característico
  for(int64_t k=1; k<=m1.rows; k++){

    //Cálculdo da Matriz adjugada
    Matrix<T> temp1=Mk*m1;
    Ic=I.scalar_multiplication(c);
    Mk= temp1+Ic;

    //Cálculo do coeficiente do polinômio característico
    M=Mk*m1;
    c=((-1)*matrix_trace<T>(M))/static_cast<T>(k); 
    characteristic_polynomial.polynomial_coefficients.push_back(c);
  }

  //Resultado
  return characteristic_polynomial;
  

};




//*******************************************************************************************
//FIM DO HEADER
#endif
