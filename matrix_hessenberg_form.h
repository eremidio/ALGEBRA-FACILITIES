//VAMOS CRIAR UM PROGRAMA QUER CONVERTE UMA MATRIZ A SUA FORMA DE HESSENBERG

/*
UMA MATRIZ É DITA ESTAR NA SUA FORMA DE HESSENBERG SE OS ELEMENTOS ABAIXO OU ACIMA DA
SUBDIAGONAL PRINCIPAL. MUITOS ALGORITMOS EM ÁLGEBRA LINEAR SÃO MAIS EFICIENTES QUANDO
UMA MATRIZ ESTÁ REDUZIDA A SUA FORMA TRIANGULAR, QUANDO A DETERMINAÇÃO DA FORMA 
TRIANGULAR DE UMA MATRIZ NÃO FOR POSSÍVEL, EM GERAL REDUZIR UMA MATRIZ A SUA FORMA DE
HESSENBERG É A SEGUNDA MELHOR OPÇÃO.

PARA MAIORES INFORMAÇÕES: A Course In Computational Algebraic Number Theory by Henri Cohen
                          https://en.wikipedia.org/wiki/Hessenberg_matrix
                          https://www.cecm.sfu.ca/CAG/theses/marshall.pdf

*/ 


//********************************************************************************************
//CABEÇALHO
#ifndef MATRIX_HESSENBERG_ALGORITHM_H
#define MATRIX_HESSENBERG_ALGORITHM_H
#include"polynomial_rational_arithmetic.h"
#include"matrix_rational.h"
#include"polynomial_exponentiation.h"

//********************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
Matrix<rational_number<T>> hessenberg_reduction(Matrix<T>&);

template<typename T>
polynomial<rational_number<T>> hessenberg_characterisc_polynomial(Matrix<T>&);


//********************************************************************************************
//FUNÇÕES
//Função que converte uma matriz a forma de Hessenberg
/*
  NOTA: Usaremos a classe de Frações disponível no header "rational_number_class.h"
        para evitar imprecisões e erros de truncamento durante o cálculo.
        Casting pode ser usado para obter a matriz em uma representação aproximada.

*/
template<typename T>
Matrix<rational_number<T>> hessenberg_reduction(Matrix<T>& m1){

  //Restrição
  assert(m1.rows>=3);

  //Variáveis locais
  Matrix<rational_number<T>> H=generate_rational_matrix<T>(m1);
  rational_number<T> temp, t, u;
  int64_t m=1, i, j, k;


  //Procedimentos
    //Loop principal
    while(m<=(m1.rows-1)){

      //Busca por elementos não nulos da matriz
      for(i=(m+1); i<m1.rows; ++i){

        //Checando se os elementos são nulos (numerador igual a 0)
        if((H.matrix[i][m-1]).numerator==0) continue;
        else{ /* Permutação de Elementos e colunas na matriz*/
          t=H.matrix[i][m-1];

          //Permutando elementos da linha da matriz
          if(i>m){
            for(j=(m-1); j<m1.rows; ++j){
              temp=H.matrix[i][j];
              H.matrix[i][j]=H.matrix[m][j];
              H.matrix[m][j]=temp;
            }

            //Permutando as colunas da matriz          
            H.permute_columns(m, i);

          };

        }


      };

      //Redução dos elementos da matriz
      for(i=(m+1); i<m1.rows; ++i){
        
        //Checando se os elementos da matriz são nulos
        if((H.matrix[i][m-1]).numerator!=0){
  
          //Reduzindo os elementos da columa
          u=H.matrix[i][m-1]/t;
          for(j=m; j<m1.rows; ++j){
            temp=u*H.matrix[m][j];
            H.matrix[i][j]=H.matrix[i][j]-temp;
          }

          //Ajustando o elemento da matrix em 0
          (H.matrix[i][m-1]).numerator=0;(H.matrix[i][m-1]).denominator=1;

          //Combinando linearmente os elementos das m-ésimas e i-ésimas colunas
          for(k=0; k<m1.rows; ++k){
            temp=H.matrix[k][i]*u;
            H.matrix[k][m]=H.matrix[k][m]+temp;
          }


        }


      };

      //Atualizando variáveis para a próxima iteração 
      ++m;



    };//Fim do loop principal


  //Resultado
  return H;


};



//Função que computa o polinômio caracteristico de uma matriz usando sua forma reduzida de Hessenberg
template<typename T>
polynomial<rational_number<T>> hessenberg_characterisc_polynomial(Matrix<T>& m1){

  //Variáveis locais
  Matrix<rational_number<T>> H=hessenberg_reduction<T>(m1);
  std::vector<polynomial<rational_number<T>>> poly_vector;
  polynomial<rational_number<T>> p0, pm, pm1, pmi, linear_poly;
  rational_number<T> one(1,1), minus_one((-1), 1), t, h, u;
  int64_t m=1, i;

  //Procedimentos
    //Gerando o primeiro elemento do vetor de polinômios
    poly_vector.resize(0);
    p0.degree=0; p0.polynomial_powers={0}; p0.polynomial_coefficients={one};
    poly_vector.push_back(p0);

    //Ajuste do fator linear
    linear_poly.degree=1; linear_poly.polynomial_powers={1, 0}; linear_poly.polynomial_coefficients={one, one};

    //Loop principal
    while(m<=m1.rows){
    
      //Ajuste de variáveis 
      t=one;
      pm1=poly_vector[m-1]; //p(m-1, x) 
      linear_poly.polynomial_coefficients[1]=H.matrix[m-1][m-1];//m está indexando os elementos da matriz F(m1.rows-1, m1.rows-1) aqui
      linear_poly.polynomial_coefficients[1].numerator =linear_poly.polynomial_coefficients[1].numerator*(-1);

      //Calculando o polinômio
      pm=rational_polynomial_mul(pm1, linear_poly);

      //Ajuste dos coeficientes do polinômio
      for(i=1; i<m; ++i){
        if(m==1) break;
        pmi=poly_vector[m-i-1];
        t=t*H.matrix[m-i][m-i-1]; 
        u=t*H.matrix[m-i-1][m-1];
  
        for(auto& c:pmi.polynomial_coefficients) c=c*u;
        pm=rational_polynomial_sub(pm, pmi);

      }

      //Adicionando o polinômio a lista
      poly_vector.push_back(pm);


     //Atualizando variáveis para a próxima iteração
     m++;
    
    }; //Fim do loop principal

  //Resultado final
  return poly_vector[poly_vector.size()-1];

};



//********************************************************************************************
//FIM DO HEADER
#endif
