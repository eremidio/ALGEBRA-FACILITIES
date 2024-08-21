//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO univariate_monomial_class.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o univariate_monomial_class univariate_monomial_class.cpp


//Cabeçalho
#include"univariate_monomial_class.h"
using namespace std;


//Função principal
int main(){

  //Instanciando objetos da classe
  univariate_monomial<int> m1(12,4), m2(12,4), m3((-5),4), m4, m5, m6, m7, m8, m9, m10, m11;
  int64_t val1, val2;


  //Procedimentos
    //Input e output
    m4.set();
    cout<<"m1(x): "<<m1.algebraic()<<'\n';
    cout<<"m2(x): "<<m2.algebraic()<<'\n';
    cout<<"m3(x): "<<m3.algebraic()<<'\n';
    cout<<"m4(x): "<<m4.algebraic()<<'\n';

    //Operadores aritméticos
    m5=m1+m3;
    m6=m1-m3;
    m7=m1*m4;
    m8=m1/m4;
    cout<<"m5(x)=m1(x)+m3(x): "<<m5.algebraic()<<'\n';
    cout<<"m6(x)=m1(x)-m3(x): "<<m6.algebraic()<<'\n';
    cout<<"m7(x)=m1(x)*m4(x): "<<m7.algebraic()<<'\n';
    cout<<"m8(x)=m1(x)/m4(x): "<<m8.algebraic()<<'\n';


    //Operadores relacionais
    cout<<"m1(x)<m7(x): "<<(m1<m7)<<'\n';
    cout<<"m7(x)<m1(x): "<<(m7<m1)<<'\n';
    cout<<"m1(x)==m2(x): "<<(m1==m2)<<'\n';
    cout<<"m1(x)==m7(x): "<<(m1==m7)<<'\n';

    //Funções auxiliares: exponenciação, redução e valuação
    m9=univariate_monomial_bin_pow<int, int>(m1, 2);
    m10=univariate_monomial_mod_bin_pow<int, int>(m1, 2, 11);
    m11=univariate_monomial_mod<int, int>(m7,11);
    val1=univariate_monomial_valuation<int, int64_t>(m2, 3);
    val2=modular_univariate_monomial_valuation<int, int64_t>(m2, 3, 7);

    cout<<"m9(x)=m1(x)²: "<<m9.algebraic()<<'\n';
    cout<<"m10(x)=m1(x)² mod 11: "<<m10.algebraic()<<'\n';
    cout<<"m11(x)=m7(x) mod 11: "<<m11.algebraic()<<'\n';
    cout<<"va11=m2(3): "<<val1<<'\n';
    cout<<"va12=m2(3) mod 7: "<<val2<<'\n';


  //Finalizando a aplicação
  return 0;

}
