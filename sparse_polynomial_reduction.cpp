//VAMOS CRIAR UM ARQUIVO PARA TESTAR  AS ROTINAS DESENVOLVIDAS NO ARQUIVO sparse_polynomial_reduction.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o sparse_polynomial_reduction sparse_polynomial_reduction.cpp -O2


//Cabeçalho
#include"sparse_polynomial_reduction.h"
using namespace std;


//Função principal
int main(){

  //Instanciando um objeto da classe
  polynomial<int64_t> p1, p2, p3, mod_poly, mod_poly2;
  univariate_monomial<int64_t> poly_term;
  int64_t a;


  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Inteiro] a (a<3): ";
    cin>>a;

    //Instanciando elementos da classe
    poly_term.coefficient=1; poly_term.power=1;
    p1.monomials.insert({poly_term.power, poly_term});//Use p(x)=x+a
    poly_term.coefficient=a; poly_term.power=0;
    p1.monomials.insert({poly_term.power, poly_term});

    poly_term.coefficient=1; poly_term.power=3;
    mod_poly.monomials.insert({poly_term.power, poly_term});//Use p(x)=x³-1
    poly_term.coefficient=(-1); poly_term.power=0;
    mod_poly.monomials.insert({poly_term.power, poly_term});

    poly_term.coefficient=1; poly_term.power=2;
    mod_poly2.monomials.insert({poly_term.power, poly_term});//Use p(x)=x²-1
    poly_term.coefficient=(-1); poly_term.power=0;
    mod_poly2.monomials.insert({poly_term.power, poly_term});

    p2=p1;
    p3=p1;

    cout<<"p2(x)= "<<p2.algebraic()<<'\n';
    cout<<"p3(x)= "<<mod_poly.algebraic()<<'\n';
    cout<<"p4(x)= "<<mod_poly2.algebraic()<<'\n';

    //Teste1: AKS testes com p=7 e r=3
    for(int i=1; i<7; ++i){
      p2=p2*p1;
      if(p2.degree()>mod_poly.degree())
        p2=polynomial_mod<int64_t>(p2, mod_poly);
    }

    p2=polynomial_mod<int64_t>(p2, mod_poly);
    p2=polynomial_mod<int64_t, int64_t>(p2, 7);
    cout<<"p2(x)^7 (mod p3(x), 7): "<<p2.algebraic()<<'\n';
  
    //Teste2: AKS testes com p=11 e r=2
    for(int i=1; i<11; ++i){
      p3=p3*p1;
      if(p3.degree()>mod_poly2.degree())
        p3=polynomial_mod<int64_t>(p3, mod_poly2);
    }

    p3=polynomial_mod<int64_t>(p3, mod_poly2);
    p3=polynomial_mod<int64_t, int64_t>(p3, 11);
    cout<<"p2(x)^11 (mod p4(x), 11): "<<p3.algebraic()<<'\n';


  //Finalizando a aplicação
  return 0;

}
