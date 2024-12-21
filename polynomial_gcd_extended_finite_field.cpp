//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO polynomial_gcd_extended_finite_field.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_gcd_extended_finite_field polynomial_gcd_extended_finite_field.cpp


//Cabeçalho
#include"polynomial_gcd_extended_finite_field.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<int> f, g, A, B, gcd_poly;
  int prime;


  //Procedimentos
    //Recebendo input do usuário
    f.set();
    g.set();
    cout<<"f(x)="<<f.algebraic()<<'\n';
    cout<<"g(x)="<<g.algebraic()<<'\n';  

    cout<<"[Característica do corpo finito] Primo: ";
    cin>>prime;

    
    //Aplicando o algoritmo de Euclides extendido para polinômios
    polynomial_finite_field_extended_euclidean_algorithm<int>(f, g, A, B, gcd_poly, prime);
    cout<<"Identidade de Bézout: A(x)p1(x)+B(x)p2(x)=mdc(p1(x), p2(x)) (mod "<<prime<<").\n";
    cout<<"A(x)="<<A.algebraic()<<'\n';
    cout<<"B(x)="<<B.algebraic()<<'\n';
    cout<<"mdc(f(x), g(x))="<<gcd_poly.algebraic()<<'\n';

  //Finalizando a aplicação
  return 0;

}
