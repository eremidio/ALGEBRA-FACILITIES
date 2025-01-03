//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS RORINAS CRIADAS NO ARQUIVO polynomial_rational_gcd.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_rational_gcd polynomial_rational_gcd.cpp


//Cabeçalho
#include"polynomial_rational_gcd.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<rational_number<int64_t>> pr1, pr2, pr_gcd;
  polynomial<int64_t> p1, p2, poly_gcd;
  rational_number<int64_t> lead_coeff;

  //Procedimento
    //Recebendo input do usuario
    p1.set();
    p2.set();
    cout<<"p1(x)  = "<<p1.algebraic()<<'\n';
    cout<<"p2(x)  = "<<p2.algebraic()<<'\n';
    cout<<'\n';

    //Convertendo os polinômios para frações
    pr1=generate_rational_polynomial<int64_t>(p1);
    pr2=generate_rational_polynomial<int64_t>(p2);


    //Calculando o gcd de polinômios
    pr_gcd= polynomial_rational_gcd<int64_t>(pr1, pr2);
    lead_coeff=pr_gcd.polynomial_coefficients[0];

    cout<<"mdc(p1(x), p2(x)) = ";
    print_rational_polynomial<int64_t>(pr_gcd, true);


    //Resultado aproximado
    for(auto& c:pr_gcd.polynomial_coefficients) c=c/lead_coeff;
    poly_gcd=generate_number_polynomial<int64_t>(pr_gcd);
    cout<<"[Resultado aproximado] mdc(p1(x), p2(x)) = "<<poly_gcd.algebraic()<<'\n';


  //Finalizando a aplicação
  return 0;

}
