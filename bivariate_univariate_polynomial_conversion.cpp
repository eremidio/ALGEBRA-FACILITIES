//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO bivariate_univariate_polynomial_conversion.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o bivariate_univariate_polynomial_conversion bivariate_univariate_polynomial_conversion.cpp -O2


//Cabeçalho
#include"bivariate_univariate_polynomial_conversion.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  bivariate_polynomial<int64_t> p1, fib_bv_poly, multiplier;
  bivariate_monomial<int64_t> poly_bv_term;
  int n;
  
  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Inteiro] n: ";
    cin>> n;


    /*NOTA: TESTAREMOS ESTAS ROTINAS COMPUTANDO POLINÔMIOS DE FIBONACCI A PARTIR DE SUA FUNÇÃO GERADORA
            ΣF(x){y^n}={y}/{1-xy-y²}.
    */
    //Computando polinômios intermediários usados no cálculo
    poly_bv_term.coefficient=1; poly_bv_term.x_valuation=0; poly_bv_term.y_valuation=1;
    poly_bv_term.valuation=cantor_pairing_function(poly_bv_term.x_valuation, poly_bv_term.y_valuation);
    p1.monomials.insert({poly_bv_term.valuation, poly_bv_term});//p(x, y)=y
    cout<<"g1(x, y)= "<<p1.algebraic()<<'\n';

    poly_bv_term.coefficient=1; poly_bv_term.x_valuation=1; poly_bv_term.y_valuation=1;
    poly_bv_term.valuation=cantor_pairing_function(poly_bv_term.x_valuation, poly_bv_term.y_valuation);
    multiplier.monomials.insert({poly_bv_term.valuation, poly_bv_term});//p(x, t)=xy+y²

    poly_bv_term.coefficient=1; poly_bv_term.x_valuation=0; poly_bv_term.y_valuation=2;
    poly_bv_term.valuation=cantor_pairing_function(poly_bv_term.x_valuation, poly_bv_term.y_valuation);
    multiplier.monomials.insert({poly_bv_term.valuation, poly_bv_term});//p(x, t)=xy+y²
    cout<<"g2(x, y)= "<<multiplier.algebraic()<<'\n';


    //Computando uma parcial da série formal que gera os polinômios de Fibonacci
    fib_bv_poly=p1; 

    for(int i=0; i<n; ++i){
      p1 = p1*multiplier;
      fib_bv_poly = fib_bv_poly+p1;
    }



    cout<<"[Função geradora dos polimios de Fibonacci] F(x, y)= "<<fib_bv_poly.algebraic()<<'\n'<<'\n';

    //Computando os polinômios de Fibonacci
    for(int j=0; j<=n; ++j){
      polynomial<int64_t> fib_poly=bivariate_univariate_polynomial_conversion<int64_t>(fib_bv_poly, j);
      cout<<"n: "<<j<<", F(x) = "<<fib_poly.algebraic()<<'\n';

    }

    
  //Finalizando a aplicação
  return 0;

}

