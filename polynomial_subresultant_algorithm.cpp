//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO polynomial_subresultant_algorithm.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_subresultant_algorithm polynomial_subresultant_algorithm.cpp


//Cabeçalho
#include"polynomial_subresultant_algorithm.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<int> p1, p2, poly_gcd;
  int resultant, discriminant;


  //Procedimentos
    //Recebendo input do usuário
    p1.set();
    p2.set();
    cout<<"p1(x): "<<p1.algebraic()<<'\n';
    cout<<"p2(x): "<<p2.algebraic()<<'\n';

    //Calculando o mmc de dois polinômios em domínio de fatoração única
    poly_gcd= polynomial_subresultant_gcd<int>(p1, p2);
    cout<<"[Subresultante mdc] gcd(x): "<<poly_gcd.algebraic()<<'\n';


    //Calculando o resultante e o discriminante de polinômios
    resultant=polynomial_resultant<int>(p1, p2);
    discriminant=polynomial_discriminant<int>(p1);

    cout<<"[Resultante] R(p1(x), p2(x)): "<<resultant<<'\n';
    cout<<"[Discriminante]  Δ(p1(x)): "<<discriminant<<'\n';

  //Finalizando a aplicação
  return 0;

}
