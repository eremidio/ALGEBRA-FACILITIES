//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO matrix_modular_reduction.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o matrix_modular_reduction matrix_modular_reduction.cpp


//Cabeçalho
#include"matrix_modular_reduction.h"
using namespace std;


//Função principal
int main(){

 //Variáveis locais
 Matrix<int> m, reduced_m;
 int modulus;

 //Procedimentos
  //Recebendo input do usuário
  m.set_size();
  m.manual_setup();

  cout<<"Inteiro congruente (n): ";
  cin>>modulus;

  //Reduzindo os coeficientes da matriz
  reduced_m=matrix_mod<int,int>(m, modulus);

  cout<<"[Matriz] m:\n";
  m.print_matrix();
  cout<<"[Matriz reduzida] m (mod n):\n";
  reduced_m.print_matrix();

 //Finalizando a aplicação
 return 0;


          }
