//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS RORINAS CRIADAS NO ARQUIVO matrix_inversion.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o matrix_inversion matrix_inversion.cpp


//Cabeçalho
#include"matrix_inversion.h"
using namespace std;


//Função principal
int main(){
//Criando objetos da classe de matrizes
Matrix<double> m1, inverse_m1;

//Procedimentos
//Ajustando a matriz
m1.set_size();
m1.manual_setup();

cout<<"Matriz:\n";
m1.print_matrix();

//Calculando a matriz inversa
inverse_m1=invert_matrix(m1);
cout<<"Matriz inversa:\n";
inverse_m1.print_matrix();

//Finalizando a aplicação
return 0;

          }
