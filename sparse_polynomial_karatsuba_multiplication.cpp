//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO sparse_polynomial_karatsuba_multiplication.h
//COMPILAR ESTE PROGRAMA COMO COMANDO: g++ -o sparse_polynomial_karatsuba_multiplication sparse_polynomial_karatsuba_multiplication.cpp -O2


//Cabeçalho
#include"sparse_polynomial_karatsuba_multiplication.h"
using namespace std;


//Função principal
int main(){

  //Variṕaveis
  polynomial<int64_t> p1, p2, p3;
  int64_t arg, mod, val1, val2;

  //Procedimentos
    //Instanciando elementos da classe
    p1.setup();
    p2.setup();

    cout<<"deg(p1(x)) = "<<p1.degree()<<'\n';
    cout<< "p1(x): "<<p1.algebraic()<<'\n';

    cout<<"deg(p2(x)) = "<<p2.degree()<<'\n';
    cout<< "p2(x): "<<p2.algebraic()<<'\n'<<'\n';


    //Testando o algoritmo de karatsuba para multiplicação de polinômios
    p3=karatsuba_sparse_polynomial_multiplication<int64_t>(p1, p2, 5);
    cout<<"deg(p3(x)) = "<<p3.degree()<<'\n';
    cout<< "p3(x): "<<p3.algebraic()<<'\n';


  //Finalizando a aplicação
  return 0;

}
