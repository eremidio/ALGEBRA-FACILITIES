//VAMOS CRIAR UM PROGRAMA QUE TESTAAS ROTINAS CRIADAS NO ARQUIVO matrix_rational.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o matrix_rational matrix_rational.cpp


//Cabeçalho
#include"matrix_rational.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  Matrix<int64_t> number_matrix;
  Matrix<rational_number<int64_t>>rational_matrix1, rational_matrix2, rational_matrix3;
  rational_number<int64_t> ratio(2,7);
  int64_t matrix_size;

  //Procedimentos
    //Definindo as entradas da matriz númerica
    cout << "Ordem da matriz quadrada\n";
    cin>> matrix_size;
    number_matrix.reshape(matrix_size, matrix_size);
    number_matrix.manual_setup();

    cout << "Matriz m:\n";
    number_matrix.print_matrix();


    //Convertendo a matriz em questão em uma matriz de frações
    rational_matrix1=generate_rational_matrix<int64_t>(number_matrix);
    rational_matrix2=rational_matrix1+rational_matrix1;
    rational_matrix3=rational_matrix2;
    //Definindo as entradas da matriz
    for(int64_t i=0; i<rational_matrix3.rows; ++i){
      for(int64_t j=0; j<rational_matrix3.columns; ++j){
        rational_matrix3.matrix[i][j]=rational_matrix3.matrix[i][j]*ratio;
      }
    }

    cout << "[Matriz de frações]  m:\n";
    print_rational_matrix<int64_t>(rational_matrix1);

    cout << "[Matriz de frações]  2m=m+m:\n";
    print_rational_matrix<int64_t>(rational_matrix2);

    cout << "[Matriz de frações]  (2/7)m:\n";
    print_rational_matrix<int64_t>(rational_matrix3);



  //Finalizando a aplicação
  return 0;  
}

