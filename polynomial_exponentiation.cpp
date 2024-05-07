//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO polynomial_exponentiation.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_exponentiation polynomial_exponentiation.cpp


//Cabeçalho
#include"polynomial_exponentiation.h"
using namespace std;

//Função principal
int main(){

 //Variáveis locais
 polynomial<int> p1, p2, pow_poly, powmod_poly;
 int e;


 //Procedimentos recebendo input do usuário
 cout<<"Expoente: ";
 cin>>e;

 p1.set();
 p2.set();

 cout<<"p1(x): "<<p1.algebraic()<<'\n';
 cout<<"p2(x): "<<p2.algebraic()<<'\n';
 cout<<"e: "<<e<<'\n';

 //Testando as rotinas de expoenenciação e exponenciação modular
 pow_poly=polynomial_bin_pow<int, int>(p1, e);
 powmod_poly=polynomial_powmod<int,int>(p1, p2, e);
 
 cout<<"p1(x)^e: "<<pow_poly.algebraic()<<'\n';
 cout<<"p2(x)^e mod(p2(x)): "<<powmod_poly.algebraic()<<'\n';


 //Finalizando a aplicação
 return 0;

          }
