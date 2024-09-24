//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADASNO ARQUIVO bivariate_polynomials.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o bivariate_polynomials bivariate_polynomials.cpp -lm -O2


//Cabeçalho
#include"bivariate_polynomials.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  bivariate_polynomial<int> p1, p2, p3, p4, p5, p6, p7, p8, p9;
  int arg1, arg2, mod, val, mod_val;

  //Procedimentos
    //Recebendo input do usuário
    p1.set();
    p2.set();

    cout<<"p1(x, y): "<<p1.algebraic()<<'\n';
    cout<<"deg(p1(x, y)): "<<p1.degree()<<'\n';
    cout<<"p2(x, y): "<<p2.algebraic()<<'\n';
    cout<<"deg(p2(x, y)): "<<p2.degree()<<'\n';

  
    //Operações aritméticas
    p3=p1;
    p4=p1+p2;
    p5=p1-p2;
    p6=p1*p2;
    p7=p1/p2;

    cout<<"p3(x, y)=p1(x, y): "<<p3.algebraic()<<'\n';
    cout<<"p1(x, y)+p2(x, y): "<<p4.algebraic()<<'\n';
    cout<<"p1(x, y)-p2(x, y): "<<p5.algebraic()<<'\n';
    cout<<"p1(x, y)*p2(x, y): "<<p6.algebraic()<<'\n';
    cout<<"p1(x, y)/p2(x, y): "<<p7.algebraic()<<'\n';

    //Cálculo de resto e redução modular dos coefficientes
    p8=remainder<int>(p1, p2);
    p9=polynomial_mod<int, int>(p6, 7);

    cout<<"[Resto da divisão]Re(p1(x, y); p2(x, y)): "<<p8.algebraic()<<'\n';
    cout<<"p6(x, y) mod 7: "<<p9.algebraic()<<'\n';

    //Funções que calculam um valor de um polinômio em duas variáveis
    cout<<"Valor x : "; 
    cin>> arg1;
    cout<<"Valor y : "; 
    cin>> arg2;
    cout<<"Inteiro congruente: ";
    cin>>mod;

    val=polynomial_evaluation<int, int>(p1, arg1, arg2);
    mod_val=modular_polynomial_evaluation<int, int>(p1, arg1, arg2, mod);

    cout<<"p1("<<arg1<<", "<<arg2<<") = "<<val<<'\n';
    cout<<"p1("<<arg1<<", "<<arg2<<") mod "<<mod<<" = "<<mod_val<<'\n';


  //Finalizando a aplicação
  return 0;

}
