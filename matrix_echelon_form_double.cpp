// VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO matrix_echelon_form_double.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o matrix_echelon_form_double matrix_echelon_form_double.cpp -O2

// Cabeçalho
#include "matrix_echelon_form_double.h"
using namespace std;

// Função principal
int main() {
  // Variáveis locais
  Matrix<float> matrix1, echelon_matrix;
  int64_t row_permutations = 0;

  // Procedimentos
  // Recebendo input do usuário
  matrix1.set_size();
  matrix1.manual_setup();

  // Calculando a matriz na sua forma escalonada
  echelon_matrix = echelon_row_form<float>(matrix1, row_permutations);

  cout << "[Matriz] m:\n";
  matrix1.print_matrix();
  cout << "[Matriz escalonada] m:\n";
  echelon_matrix.print_matrix();

  // Finalizando a aplicação
  return 0;
}
