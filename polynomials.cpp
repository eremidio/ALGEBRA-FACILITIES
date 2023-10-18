//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO polynomials.h 
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomials polynomials.cpp


//Cabeçalho
#include"polynomials.h"
#include<iostream>
#include<vector>
using namespace std;

//Função principal
int main(){
//Declarando polinômios
polynomial<int> p1, p2, p3, p4, p5, p6, p7;

//Ajustando os polinômios
p1.set();
p2.set();

//Printando os polinômios na tela
cout<<"p1: "<<p1.algebraic()<<'\n';
cout<<"p2: "<<p2.algebraic()<<'\n';


//Calculando os valores de um polinômio
cout<<"p2(100)= "<<p2.evaluate_polynomial(100)<<'\n';

//Operações aritméticas básicas
//Adição e subtração
p3=p1+p2;
p4=p1-p2;
cout<<"p3: "<<p3.algebraic()<<'\n';
cout<<"p4: "<<p4.algebraic()<<'\n';

//Multiplicação e divisão
p5=p1*p2;
p6=p1/p2;
p7=remainder(p1, p2);
cout<<"p5: "<<p5.algebraic()<<'\n';
cout<<"p6: "<<p6.algebraic()<<'\n';
cout<<"p7: "<<p7.algebraic()<<'\n';

//Finalizando a aplicação
return 0;
          }

