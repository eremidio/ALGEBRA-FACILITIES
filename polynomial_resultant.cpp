//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO NO ARQUIVO polynomial_resultant.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_resultant polynomial_resultant.cpp


//Cabeçalho
#include"polynomial_resultant.h"
using namespace std;


//Função principal
int main(){


  //Variáveis locais
  polynomial<int64_t> p1, p2;
  int64_t resultant, discriminant1, discriminant2;


  //Procedimentos
    //Recebendo input do usuário
    p1.set();
    p2.set();
    cout<<"p1(x): "<<p1.algebraic()<<'\n';
    cout<<"p2(x): "<<p2.algebraic()<<'\n';


    //Calculando o resultante e o discriminante de polinômios
    resultant=polynomial_resultant<int64_t>(p1, p2);
    cout<<"[Resultante] R(p1(x), p2(x)): "<<resultant<<'\n';

  //Finalizando a aplicação
  return 0;

}
