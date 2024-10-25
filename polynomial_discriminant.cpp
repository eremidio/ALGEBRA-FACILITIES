//VAMOS CRIAR PARA TESTAR AS RPOTINAS CRIADAS NO ARQUIVO polynomial_discriminant.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_discriminant polynomial_discriminant.cpp


//Cabeçalho
#include"polynomial_discriminant.h"
using namespace std;


//Função principal
int main(){


  //Variáveis locais
  polynomial<int64_t> p1;
  int64_t discriminant;


  //Procedimentos
    //Recebendo input do usuário
    p1.set();
    cout<<"p1(x): "<<p1.algebraic()<<'\n';


    //Calculando o discriminante do polinômio
    discriminant=polynomial_discriminant<int64_t>(p1);
    cout<<"[Discriminante] Δ(p1(x)): "<<discriminant<<'\n';

  //Finalizando a aplicação
  return 0;

}
