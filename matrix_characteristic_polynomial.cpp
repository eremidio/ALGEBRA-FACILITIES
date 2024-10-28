//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS NO ARQUIVO matrix_characteristic_polynomial.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o matrix_characteristic_polynomial matrix_characteristic_polynomial.cpp


//Cabeçalho
#include"matrix_characteristic_polynomial.h"
using namespace std;

//Função principal
int main(){

  //Variáveis locais
  Matrix<int64_t> number_matrix;
  polynomial<int64_t> char_poly;
  int64_t matrix_size;

  //Procedimentos
    //Definindo as entradas da matriz númerica
    cout << "Ordem da matriz quadrada\n";
    cin>> matrix_size;
    number_matrix.reshape(matrix_size, matrix_size);
    number_matrix.manual_setup();

    cout << "Matriz m:\n";
    number_matrix.print_matrix();


    //Calculando o polinômio caracteristico associado a matriz
    char_poly=faddeev_leverrier_algorithm<int64_t>(number_matrix);
    cout<<"[Polinômio característico associado a matriz] p(x): "<<char_poly.algebraic()<<'\n';


  //Finalizando a aplicação
  return 0;

} 
