//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO polynomial_rational_irreducibility.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_rational_irreducibility polynomial_rational_irreducibility.cpp -O2



//Cabeçalho
#include"polynomial_rational_irreducibility.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<int64_t> poly, shifted_poly, poly_reverse;
  int64_t shifting;
  bool cohn_test, eisenstein_test, perron_test;

  //Procedimentos
    //Recebendo input do usuário
    poly.set();
    cout<<"p1(x): "<<poly.algebraic()<<'\n';

    cout<<"[Translado da origem: x->(x-a)] a: ";
    cin>>shifting;


    //Invertendo os coeficientes de um polinômio
    poly_reverse=polynomial_reversal<int64_t>(poly);
    cout<<"[Invertendo os coeficientes] p1(x): "<<poly_reverse.algebraic()<<'\n';

    //Aplicando uma tranaformaçãolinear ao polinômio
    shifted_poly=polynomial_lifting<int64_t>(poly, shifting);
    cout<<"[Transformação linear: x->(x-a)] p1(x): "<<shifted_poly.algebraic()<<'\n';


    //Testes de irredutibilidade de polinômios definidos sobre os reais/racionais
    cohn_test=cohn_irreducibility_criterion<int64_t>(poly, 1000);
    eisenstein_test=eisenstein_irreducibility_criterion<int64_t>(poly);
    perron_test=perron_irreducibility_criterion<int64_t>(poly);

    cout<<"Teste de irredutibilidade de Perron: "<< perron_test<<'\n';
    cout<<"Teste de irredutibilidade de Cohn: "<< cohn_test<<'\n';
    cout<<"Teste de irredutibilidade de Eisenstein: "<< eisenstein_test<<'\n';


  //Finalizando a aplicação
  return 0;

}
