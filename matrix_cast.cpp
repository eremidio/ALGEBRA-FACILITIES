//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO matrix_cast.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o matrix_cast matrix_cast.cpp


//Cabeçalho
#include"matrix_cast.h"
using namespace std;


//Função principal
int main(){

 //Variáveis locais
 Matrix<int> int_m;
 Matrix<double> double_m;

 //Procedimentos
  //Recebendo input do usuário
  double_m.set_size();
  double_m.manual_setup();
    
  //Conversão de matrizes
  int_m=matrix_cast<double, int>(double_m);

  cout<<"[Matriz de inteiros] m:\n";
  int_m.print_matrix();
  cout<<"[Matriz de reais] m:\n";
  double_m.print_matrix();


 //Finalizando a aplicação
 return 0;

          }



