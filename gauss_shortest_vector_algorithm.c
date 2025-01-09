//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO gauss_shortest_vector_algorithm.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o gauss_shortest_vector_algorithm gauss_shortest_vector_algorithm.c -lm


//Cabeçalho
#include"gauss_shortest_vector_algorithm.h"


//Função principal
int main(){

  //Variáveis locais: inicializando os vetores 
  struct gauss_vector u=gauss_vector_init(), v=gauss_vector_init();


  //Procedimentos
    //Exibindo os vetores
    show_gauss_vector(u);
    show_gauss_vector(v);

    //Calculando o vetor de menor norma
    struct gauss_vector smallest_vector=gauss_shortest_vector_algorithm(u, v);
    printf("Vetor de menor norma (combinação linear): ");
    show_gauss_vector(smallest_vector);

    
  //Finalizando a aplicação
  return 0;

}
