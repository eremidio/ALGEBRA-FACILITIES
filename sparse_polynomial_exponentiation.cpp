//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO sparse_polynomial_exponentiation.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o sparse_polynomial_exponentiation sparse_polynomial_exponentiation.cpp


//Cabeçalho
#include"sparse_polynomial_exponentiation.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<int64_t> p1, p2;
  polynomial<int64_t> pow_poly, powmod_poly, pow_poly_finite, powmod_poly_finite;
  int64_t exponent, modulus;


  //Procedimentos
    //Recebendo input do usuário
    p1.setup(); cout<<'\n';
    cout<< "p1(x): "<<p1.algebraic()<<'\n';

    p2.setup(); cout<<'\n';
    cout<< "p2(x): "<<p2.algebraic()<<"\n\n";

    
    cout<<"[Inteiro] expoente: "; cin>>exponent;
    cout<<"[Inteiro] congruente: "; cin>>modulus;

    //Exponenciação
    cout<<'\n';
    pow_poly = sparse_polynomial_pow<int64_t, int64_t>(p1, exponent);
    cout<< "p1(x)^"<<exponent<<": "<<pow_poly.algebraic()<<'\n';


    //Exponenciação modular
    cout<<'\n';
    powmod_poly = sparse_polynomial_powmod<int64_t,int64_t>(p1, exponent, modulus);
    cout<< "p1(x)^"<<exponent<<" mod("<<modulus<<"): "<<powmod_poly.algebraic()<<'\n';


    //Exponenciação a menos de uma congruência polinomial
    cout<<'\n';
    pow_poly_finite = sparse_polynomial_pow_finite_field<int64_t,int64_t>(p1, p2, exponent);
    cout<< "p1(x)^"<<exponent<<" mod(p2(x)): "<<pow_poly_finite.algebraic()<<'\n';



    //Exponenciação modular a menos de uma congruência polinomial
    cout<<'\n';
    powmod_poly_finite = sparse_polynomial_powmod_finite_field<int64_t,int64_t>(p1, p2, exponent, modulus);
    cout<< "p1(x)^"<<exponent<<" mod(p2(x), "<<modulus<<"): "<<powmod_poly_finite.algebraic()<<'\n';
    cout<<'\n';


  //Finalizando a aplicação
  return 0;

}
