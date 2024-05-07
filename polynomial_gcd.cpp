//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO polynomial_gcd.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_gcd polynomial_gcd.cpp


//Cabeçalho
#include"polynomial_gcd.h"
using namespace std;

//Função principal
int main(){

 //Variáveis locais
 polynomial<int> p1, p2, gcd_poly;

 //Procedimentos
  //Inicializandos os polinômios
  p1.set();
  p2.set();

  //Calculando o mdc de dois polinômios
  gcd_poly=polynomial_gcd<int>(p1, p2);
  
  //Exebindo o resultado da execução do algoritmo
  cout<<"p1(x)="<<p1.algebraic()<<'\n';
  cout<<"p2(x)="<<p2.algebraic()<<'\n';
  cout<<"mdc(p1(x), p2(x))="<<gcd_poly.algebraic()<<'\n';


 //Finalizando a aplicação
 return 0;
          }

