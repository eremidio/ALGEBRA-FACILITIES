//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO DE GAUSS PARA CÁLCULO DO VETOR MAIS CURTO EM UMA TRELIÇA


/*

O ALGORITMO DE GAUSS É UMA VARIAÇÃO DO ALGORITMO DE EUCLIDES APLICADO AO PROBLEMA DE COMPUTAR O VETOR MAIS 
CURTO EM UMA TRELIÇA. DADO DOIS VETORES u E v LINEARMENTE INDEPEDENTE O ALGORITMO PERMITE DETERMINAR UMA
COMBINAÇÃO LINEAR DESTES VETORES QUE POSSUI MENOR NORMA EUCLIDIANA.

O ALGORITMO EM QUESTÃO É UMA VARIAÇÃO DO ALGORITMO DE EUCLIDES PARA COMPUTAR O MDC DE DOIS INTEIROS, QUANDO 
SE TEM UM CONJUNTO FORMADO POR MAIS DE DOIS VETORES LINEARMENTE INDEPENDENTE O ALGORITMO MAIS SOFISTICADO DE
LENSTRA-LENSTRA-LOVÁSZ DEVE SER EMPREGADO.

PARA MAIORES INFORMAÇÕES: A Course In Computational Algebraic Number Theory by Henri Cohen

*/ 



//******************************************************************************************************************
//CABEÇALHO
#ifndef GAUSS_SHORTEST_VECTOR_ALGORITHM_H
#define GAUSS_SHORTEST_VECTOR_ALGORITHM_H
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<math.h>

//CONSTANTE GLOBAL
#define GAUSS_VECTOR_MAX 100

//******************************************************************************************************************
//ESTRTURAS USADAS NO NO ALGORITMO

//Estrtura representando um vetor
struct gauss_vector{

    int64_t x;
    int64_t y;
};

//Função que inicializa um vetor
struct gauss_vector gauss_vector_init(void){

  //Variáveis locais  
  struct gauss_vector v;



  //Procedimentos
    //Definindo as coordenadas do vetor
    printf("2D vector\n");
    printf("Coordenada x: "); scanf("%li", &v.x);
    printf("Coordenada y: "); scanf("%li", &v.y);

  //Resultado
  return v;

};


//Função que calcula o produto escalar de dois vetores
int64_t gauss_dot_product(struct gauss_vector v1, struct gauss_vector v2){
  
  //Resultado
  return (v1.x*v2.x)+(v1.y*v2.y);

};


//Função que combina linearmente dois vetores v1, v2 de acordo com a regra: u=v1-(r.v2), com r escalar
struct gauss_vector gauss_linear_combination(struct gauss_vector v1, struct gauss_vector v2, int64_t r){

  //Variáveis locais  
  struct gauss_vector v;

  //Procedimentos
    //Definindo as coordenadas do vetor
     v.x=(v1.x)-(v2.x*r);
     v.x=(v1.y)-(v2.y*r);


  //Resultado
  return v;

};


//Função que exibe as coordenadas de um vetor
void show_gauss_vector(struct gauss_vector v){

  //Procedimentos:
  printf("(%li, %li)\n", v.x, v.y);


};

//******************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
struct gauss_vector gauss_shortest_vector_algorithm(struct gauss_vector, struct gauss_vector);


//******************************************************************************************************************
//FUNÇÕES
//Função que imeplementa o algoritmo de Gauss
struct gauss_vector gauss_shortest_vector_algorithm(struct gauss_vector a, struct gauss_vector b){

  //Variáveis locais
  struct gauss_vector t;
  int64_t A=gauss_dot_product(a, a);
  int64_t B=gauss_dot_product(b, b);
  int64_t T, r, n;


  //Procedimentos
    //Checando a normas dos vetores
    if(A<B){
      t=a; a=b; b=t;
      T=A; A=B; B=T;
    };

     T=0;//Ajuste de parâmetro

    //Loop euclidiano
    while(1){

      //Checando as normas do vetores
      n=gauss_dot_product(a, b);
      r=round(n/B);
      T = A - (2*n*r)+(r*r*B);

      if(T>=B) break;

      //Atuallizando variáveis para a próxima iteração
      t=gauss_linear_combination(a, b, r);
      a=b; b=t; 
      A=B; B=T;

    }
    
  //Resultado
  return b;

}


//******************************************************************************************************************
//FIM DO HEADER
#endif
