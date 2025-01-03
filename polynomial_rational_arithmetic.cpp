//VAMOS CRIARUM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO polynomial_rational_arithmetic.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_rational_arithmetic polynomial_rational_arithmetic.cpp



//Cabeçalho
#include"polynomial_rational_arithmetic.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<rational_number<int64_t>> pr1, pr2, pr3, pr4, pr5, pr6;
  polynomial<int64_t> p1, p2;
  rational_number<int64_t> r1(2,7), r2(3,11);


  //Procedimento
    //Recebendo input do usuario
    p1.set();
    p2.set();
    cout<<"p1(x)  = "<<p1.algebraic()<<'\n';
    cout<<"p2(x)  = "<<p2.algebraic()<<'\n';
    cout<<'\n';

    //Convertendo os polinômios em polinômios de frações
    pr1=generate_rational_polynomial<int64_t>(p1);
    pr2=generate_rational_polynomial<int64_t>(p2);
    for(auto& c1:pr1.polynomial_coefficients) c1=c1*r1;
    for(auto& c2:pr2.polynomial_coefficients) c2=c2*r2;

    cout<<"[(2/7)p1(x)]   pr1(x) = ";
    print_rational_polynomial<int64_t>(pr1, true);
    cout<<"[(3/11)p2(x)]  pr2(x)  = ";
    print_rational_polynomial<int64_t>(pr2, true);
    cout<<'\n';

    //Operações aritméticas
    pr3=rational_polynomial_add<int64_t>(pr1, pr2);
    pr4=rational_polynomial_sub<int64_t>(pr1, pr2);
    pr5=rational_polynomial_mul<int64_t>(pr1, pr2);
    pr6=rational_polynomial_div<int64_t>(pr1, pr2);


    cout<<" pr1(x) + pr2(x) = ";
    print_rational_polynomial<int64_t>(pr3, true);
    cout<<" pr1(x) - pr2(x) = ";
    print_rational_polynomial<int64_t>(pr4, true);
    cout<<" pr1(x) * pr2(x) = ";
    print_rational_polynomial<int64_t>(pr5, true);
    cout<<" pr1(x) / pr2(x) = ";
    print_rational_polynomial<int64_t>(pr6, true);


  //Finalizando a aplicação
  return 0;

}
