//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO polynomial_gcd_extended.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_gcd_extended polynomial_gcd_extended.cpp


//Cabeçalho
#include"polynomial_gcd_extended.h"
using namespace std;


//Função principal 
int main(){

  //Variáveis locais
  polynomial<int> f, g, A, B, gcd_poly;

  //Procedimentos
    //Recebendo input do usuário
    f.set();
    g.set();
    cout<<"f(x)="<<f.algebraic()<<'\n';
    cout<<"g(x)="<<g.algebraic()<<'\n';  
    
    //Aplicando o algoritmo de Euclides extendido para polinômios
    polynomial_extended_euclidean_algorithm<int>(f, g, A, B, gcd_poly);
    cout<<"Identidade de Bézout: A(x)p1(x)+B(x)p2(x)=mdc(p1(x), p2(x)).\n";
    cout<<"A(x)="<<A.algebraic()<<'\n';
    cout<<"B(x)="<<B.algebraic()<<'\n';
    cout<<"mdc(f(x), g(x))="<<gcd_poly.algebraic()<<'\n';

  //Finalizando a aplicação
  return 0;
}
