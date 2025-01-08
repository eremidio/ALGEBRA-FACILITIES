//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ALGORITMO matrix_hessenberg_form.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o matrix_hessenberg_form matrix_hessenberg_form.cpp


//Cabeçalho
#include"matrix_hessenberg_form.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  Matrix<int64_t> number_matrix;
  Matrix<rational_number<int64_t>> hessenberg_matrix;
  polynomial<rational_number<int64_t>> rational_characteristic_polynomial;
  polynomial<int64_t> characteristic_polynomial;
  int64_t matrix_size;

  //Procedimentos
    //Definindo as entradas da matriz númerica
    cout << "Ordem da matriz quadrada\n";
    cin>> matrix_size;
    number_matrix.reshape(matrix_size, matrix_size);
    number_matrix.manual_setup();

    cout << "Matriz m:\n";
    number_matrix.print_matrix();

    //Calculando a forma de Hessenberg da matriz em questão
    hessenberg_matrix=hessenberg_reduction<int64_t>(number_matrix);

    cout << "[Matriz na forma reduzida de Hessenberg]  Hm:\n";
    print_rational_matrix<int64_t>(hessenberg_matrix);


    //Computando o polinômio característico da matriz
    rational_characteristic_polynomial=hessenberg_characterisc_polynomial<int64_t>(number_matrix);
    characteristic_polynomial=generate_number_polynomial<int64_t>(rational_characteristic_polynomial);
    cout<<"[Polinômio característico associado a matriz] p(x): "<<characteristic_polynomial.algebraic()<<'\n';

  //Finalizando a aplicação
  return 0;


}
