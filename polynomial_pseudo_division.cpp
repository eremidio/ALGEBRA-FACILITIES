//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO polynomial_pseudo_division.h
//COMPILAR ESTE PROGRAMA COMO COMANDO: g++ -o polynomial_pseudo_division polynomial_pseudo_division.cpp


//Cabeçalho
#include"polynomial_pseudo_division.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<double> p1, p2, quotient, remainder;


  //Procedimentos
    //Recebendo input do usuário
    p1.set();
    p2.set();

    //Calculando o quociente e o resto usandoo algoritmo de pseudodivisão de polinômios
    polynomial_pseudodivision(p1, p2, quotient, remainder);
    
    cout<<"p1(x): "<<p1.algebraic()<<'\n';
    cout<<"p2(x): "<<p2.algebraic()<<'\n';
    cout<<"[Pseudo quociente] q(x): "<<quotient.algebraic()<<'\n';
    cout<<"[Pseudo resto] r(x): "<<remainder.algebraic()<<'\n';

  //Finalizando a aplicação
  return 0;

}
