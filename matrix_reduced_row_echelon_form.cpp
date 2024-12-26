//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO matrix_reduced_row_echelon_form.h
//COMPILAR ESTE PROGRAMA COM COMANDO: g++ -o matrix_reduced_row_echelon_form matrix_reduced_row_echelon_form.cpp

// Cabeçalho
#include "matrix_reduced_row_echelon_form.h"
using namespace std;

// Função principal
int main(){

  //Variáveis locais
  Matrix<int32_t> m1, reduced_matrix1;
  Matrix<double> m2, reduced_matrix2;
  int64_t row_changes;


  //Procedimentos
    //Recebendo input do usuário
    m1.set_size();
    m1.manual_setup();
    cout<<"[Matriz] m:\n";
    m1.print_matrix();

    m2.set_size();
    m2.manual_setup();
    cout<<"[Matriz] m2:\n";
    m2.print_matrix();


    //Transformando a matriz em sua forma escalonada reduzida
    reduced_matrix1=reduced_echelon_form<int32_t>(m1, row_changes);
    cout<<"[Matriz escalonada reduzida] m1:\n";
    reduced_matrix1.print_matrix();

    reduced_matrix2=reduced_echelon_form<double>(m2, row_changes);
    cout<<"[Matriz escalonada reduzida] m2:\n";
    reduced_matrix2.print_matrix();



  //Finalizando a aplicação
  return 0;

}
