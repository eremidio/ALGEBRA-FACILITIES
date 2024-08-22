//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADASNO ARQUIVO sparse_polynomials.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o sparse_polynomials sparse_polynomials.cpp


//Cabeçalho
#include"sparse_polynomials.h"
using namespace std;


//Função principal
int main(){

  //Instanciando um objeto da classe
  polynomial<int64_t> p1, p2, p3, p4, p5, p6, p7, p8, p9;
  int64_t arg, mod, val1, val2;

  //Procedimentos
    //Instanciando elementos da classe
    p1.setup();
    p2.setup();

    cout<<"deg(p1(x)) = "<<p1.degree()<<'\n';
    cout<< "p1(x): "<<p1.algebraic()<<'\n';

    cout<<"deg(p2(x)) = "<<p2.degree()<<'\n';
    cout<< "p2(x): "<<p2.algebraic()<<'\n';


    //Operadores arimtéticos
    p3=p1;
    p4=p1+p2;
    p5=p1-p2;
    p6=p1*p2;
    p7=p1/p2;

    cout<<"deg(p3(x)) = "<<p3.degree()<<'\n';
    cout<< "p3(x)=p1(x): "<<p3.algebraic()<<'\n';

    cout<<"deg(p4(x)) = "<<p4.degree()<<'\n';
    cout<< "p4(x)=p1(x)+p2(x): "<<p4.algebraic()<<'\n';

    cout<<"deg(p5(x)) = "<<p5.degree()<<'\n';
    cout<< "p5(x)=p1(x)-p2(x): "<<p5.algebraic()<<'\n';

    cout<<"deg(p6(x)) = "<<p6.degree()<<'\n';
    cout<< "p6(x)=p1(x)*p2(x): "<<p6.algebraic()<<'\n';

    cout<<"deg(p7(x)) = "<<p7.degree()<<'\n';
    cout<< "p7(x)=p1(x)/p2(x): "<<p7.algebraic()<<'\n';

    //Redução modular e resto de divisão
    cout<<"Congruente: ";
    cin>>mod;

    p8=remainder<int64_t>(p6, p5);
    p9=polynomial_mod<int64_t, int64_t>(p6, mod);

    cout<<"deg(p8(x)) = "<<p8.degree()<<'\n';
    cout<< "p8(x)=Resto(p6(x), p5(x)): "<<p8.algebraic()<<'\n';

    cout<<"deg(p9(x)) = "<<p9.degree()<<'\n';
    cout<< "p9(x)=p6(x) mod "<<mod<<": "<<p9.algebraic()<<'\n';

    //Cálculo do valor de um polinômio
    cout<<"Argumento: ";
    cin>>arg;

    val1=polynomial_evaluation<int64_t, int64_t>(p1, arg);
    val2=modular_polynomial_evaluation<int64_t, int64_t>(p1, arg, mod);

    cout<<"p1("<<arg<<") = "<<val1<<'\n';
    cout<<"p1("<<arg<<") mod "<<mod <<" = "<<val2<<'\n';


  


  //Finalizando a aplicação
  return 0;

}
