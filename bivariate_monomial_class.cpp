//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO bivariate_monomial_class.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o bivariate_monomial_class bivariate_monomial_class.cpp


//Cabeçalho
#include"bivariate_monomial_class.h"
using namespace std;

//Função principal
int main(){

  //Variáveis locais
  bivariate_monomial<int> m1(15,3,4), m2, m3, m4, m5, m6, m7, m8, m9, m10;
  int val, mod_val;
  int arg1, arg2, mod;


  //Procedimentos
    //Testando funções que definem um monômio e os escrevem como uma string
    m2.set();
    
    cout<<"m1(x, y): "<<m1.algebraic()<<'\n';
    cout<<"[Index] m1: "<<m1.valuation<<'\n';
    cout<<"m2(x, y): "<<m2.algebraic()<<'\n';
    cout<<"[Index] m2: "<<m2.valuation<<'\n';
  
    

    //Operações aritméticas
    m3=m1;
    m4=m1+m2;
    m5=m1-m2;
    m6=m1*m2;
    m7=m1/m2;

    cout<<"m3(x, y)=m1(x, y) : "<<m3.algebraic()<<'\n';
    cout<<"m4(x, y)=m1(x, y)+m2(x,y) : "<<m4.algebraic()<<'\n';
    cout<<"m5(x, y)=m1(x, y)-m2(x,y) : "<<m5.algebraic()<<'\n';
    cout<<"m6(x, y)=m1(x, y)*m2(x,y) : "<<m6.algebraic()<<'\n';
    cout<<"m7(x, y)=m1(x, y)/m2(x,y) : "<<m7.algebraic()<<'\n';

    //Operadores de comparação
    cout<<"m1(x,y)==m3(x,y): "<<(m1==m3)<<'\n';
    cout<<"m1(x,y)<m6(x,y): "<<(m1<m6)<<'\n';
    cout<<"m6(x,y)<m3(x,y): "<<(m6<m3)<<'\n';


    //Funções que reduzem os coeficientes de um monômio e de exponenciação
    m8=bivariate_monomial_mod<int, int>(m1, 13);
    m9=bivariate_monomial_bin_pow<int,int>(m1, 2);
    m10=bivariate_monomial_mod_bin_pow<int,int>(m1, 100, 11);


    cout<<"m8(x, y)= m1(x, y) mod 13: "<<m8.algebraic()<<'\n';
    cout<<"m9(x, y)= m1(x, y)^2 : "<<m9.algebraic()<<'\n';
    cout<<"m10(x, y)= m1(x, y)^100 mod 13: "<<m10.algebraic()<<'\n';


    //Funções que calculam um valor de um monômio em duas variáveis
    cout<<"Valor x : "; 
    cin>> arg1;
    cout<<"Valor y : "; 
    cin>> arg2;
    cout<<"Inteiro congruente: ";
    cin>>mod;

    val = bivariate_monomial_valuation<int, int>(m1, arg1, arg2);
    mod_val =modular_bivariate_monomial_valuation<int, int>(m1, arg1, arg2, mod);
   
    cout<<"m1("<<arg1<<","<<arg2<<") ="<<val<<'\n';
    cout<<"m1("<<arg1<<","<<arg2<<") mod "<<mod<<" ="<<mod_val<<'\n';
  

  //Finalizando a aplicação
  return 0;

}
