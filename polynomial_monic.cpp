//VAMOS CRIAR UMA FUNÇÃO QUE TESTA AS ROTINAS DO ARQUIVO polynomial_monic.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_monic polynomial_monic.cpp


//Cabçalho
#include"polynomial_monic.h"
using namespace std;

//Função principal
int main(){

 //Variáveis locais
 polynomial<int> p1, monic_poly1;
 polynomial<float> p2, monic_poly2;


 //Procedimentos
  //Definindo os polinômios
  p1.set();
  p2.set();

  cout<<"p1(x): "<<p1.algebraic()<<'\n';
  cout<<"p2(x): "<<p2.algebraic()<<'\n';

  //Calculando os respectivos polinômios associados
  monic_poly1=make_monic_polynomial<int>(p1);
  monic_poly2=make_monic_polynomial<float>(p2);

  cout<<"[Mônico] p1(x): "<<monic_poly1.algebraic()<<'\n';
  cout<<"[Mônico] p2(x): "<<monic_poly2.algebraic()<<'\n';

 

 //Finalizando a aplicação
 return 0;

          }
