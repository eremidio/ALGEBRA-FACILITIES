//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO determinant_gauss_barreis.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o determinant_gauss_barreis determinant_gauss_barreis.cpp


//Cabeçalho
#include"determinant_gauss_barreis.h"
using namespace std;


// Função principal
int main() {

  // Matrizes
  Matrix<int64_t> m;
  int64_t matrix_size, matrix_entry;

  // Procedimentos
    // Definindo as entradas da matriz
    cout << "Ordem da matriz quadrada\n";
    cin>> matrix_size;
    m.reshape(matrix_size, matrix_size);
   

    //Definindo as entradas matrizes com um gerador de números aleatórios
    srand(time(NULL));
    
    for(int64_t i=0;  i<matrix_size; ++i){
      for(int64_t j=0;  j<matrix_size; ++j){
        matrix_entry=(-1)+rand()%3;
        m.matrix[i][j]=matrix_entry;
      }
    }

    cout << "Matriz m:\n";
    m.print_matrix();

  // Calculando o  determinante das matrizes
  cout << "Determinante da matriz m: " << determinant_gauss_barreis(m) << "\n";

  // Finalizando a aplicação
  return 0;

}
