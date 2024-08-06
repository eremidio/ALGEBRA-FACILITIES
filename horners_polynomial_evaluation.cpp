//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO horners_polynomial_evaluation.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o horners_polynomial_evaluation horners_polynomial_evaluation.cpp

//Cabeçalho
#include"horners_polynomial_evaluation.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<int32_t> poly;
  int32_t arg, mod;

  //Procedimentos
    //Recebendo input do usuário
    cout<<"Argumento: "; cin>>arg;
    cout<<"Módulo: "; cin>>mod;

    poly.set();

    //Calculando o valor do polinômio
    cout<<"p(x): "<<poly.algebraic()<<'\n';
    cout<<"p("<<arg<<") = "<<horners_polynomial_evaluation<int32_t, int64_t>(poly, arg)<<'\n';
    cout<<"p("<<arg<<") mod "<< mod<<" = "<<horners_polynomial_evaluation<int32_t, int64_t>(poly, arg, mod)<<'\n';

    
  //Finalizando a applicação
  return 0;

}
