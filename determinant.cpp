//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS DEFINIDAS NO HEADER determinant.h 
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o determinant determinant.cpp

//Cabeçalho
#include"matrix.h"
#include"determinant.h"
#include<iostream>
using namespace std;

//Função principal
int main(){
//Matrizes
Matrix<int64_t> a(2), b(3), c(1), d(4, Identity);
Matrix<double> e(2);

//Procedimentos
//Definindo as entradas da matriz
cout<<"Matriz a:\n";
a.manual_setup();
cout<<"Matriz b:\n";
b.manual_setup();
cout<<"Matriz c:\n";
c.manual_setup();
cout<<"Matriz e:\n";
e.manual_setup();

//Printando as matrizes
cout<<"Matriz a:\n";
a.print_matrix();
cout<<"Matriz b:\n";
b.print_matrix();
cout<<"Matriz c:\n";
c.print_matrix();
cout<<"Matriz d:\n";
d.print_matrix();
cout<<"Matriz e:\n";
e.print_matrix();

//Calculando o  determinante das matrizes
cout<<"Determinante da matriz a: "<<determinant(a)<<"\n";
cout<<"Determinante da matriz b: "<<determinant(b)<<"\n";
cout<<"Determinante da matriz c: "<<determinant(c)<<"\n";
cout<<"Determinante da matriz d: "<<determinant(d)<<"\n";
cout<<"Determinante da matriz e: "<<determinant(e)<<"\n";

//Finalizando a aplicação
return 0;
          };
