//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO matrix_inversion2.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o matrix_inversion2 matrix_inversion2.cpp


//Cabeçalho
#include"matrix_inversion2.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  Matrix<double> m1, inverse_m1;

  // Procedimentos
    // Ajustando a matriz
    m1.set_size();
    m1.manual_setup();

    cout << "[Matriz] m:\n";
    m1.print_matrix();

    // Calculando a matriz inversa
    inverse_m1 = matrix_adjugate_inversion_algorithm<double>(m1);
    cout << "[Matriz inversa] m⁻¹:\n";
    inverse_m1.print_matrix();

  // Finalizando a aplicação
  return 0;

}
