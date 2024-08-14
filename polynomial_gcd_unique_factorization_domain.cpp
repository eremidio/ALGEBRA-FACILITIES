//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO polynomial_gcd_unique_factorization_domain.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_gcd_unique_factorization_domain polynomial_gcd_unique_factorization_domain.cpp -O2


//Cabeçalho
#include"polynomial_gcd_unique_factorization_domain.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<int> p1, p2, poly_gcd;


  //Procedimentos
    //Recebendo input do usuário
    p1.set();
    p2.set();
    cout<<"p1(x): "<<p1.algebraic()<<'\n';
    cout<<"p2(x): "<<p2.algebraic()<<'\n';

    //Calculando o mmc de dois polinômios em domínio de fatoração única
    poly_gcd=  polynomial_gcd_ufd<int>(p1, p2);
    cout<<"[DFU mdc] gcd(x): "<<poly_gcd.algebraic()<<'\n';


  //Finalizando a aplicação
  return 0;

}
