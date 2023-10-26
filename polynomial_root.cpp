//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO polynomial_root.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_root polynomial_root.cpp

//Cabeçalho
#include"polynomial_root.h"
#include"polynomials.h"
#include<iostream>
using namespace std;

//Função principal 
int main(){
//Variáveis locais
polynomial<double> p1, p2;
double root;

//Procedimentos
//Definindo polinômios
p1.set();
cout<<"p1(x): "<<p1.algebraic()<<'\n';

//Cálculo  da derivada de polinômios
p2=polynomial_derivative(p1);
cout<<"p2=p1'(x): "<<p2.algebraic()<<'\n';

//Cálculo de raízes
root=find_root(p1);
cout<<"Raíz de p1: "<<root<<'\n';

//Finalizando a aplicação
return 0;
          }
