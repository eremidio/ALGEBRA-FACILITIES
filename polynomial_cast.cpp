//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO HEADER polynomial_cast.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_cast polynomial_cast.cpp


//Cabeçalho
#include"polynomial_cast.h"
using namespace std;

//Função principal
int main(){

 //Variáveis locais
 polynomial<int> p1;
 polynomial<float> p2;


 //Procedimentos
  //Definindo os polinômios
  p1.set();
  cout<<"[int] p1(x): "<<p1.algebraic()<<'\n';
 
  //Conversão de argumentos templates de um objeto da classe
  p2=polynomial_cast<int, float>(p1);

  cout<<"[float] p2(x): "<<p2.algebraic()<<'\n';

 //Finalizando a aplicação
 return 0;

          }

