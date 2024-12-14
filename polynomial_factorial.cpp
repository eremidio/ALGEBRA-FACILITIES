//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO polynomial_factorial.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_factorial polynomial_factorial.cpp



//Cabeçalho
#include"polynomial_factorial.h"
using namespace std;


//Função  principal
int main(){

  //Variáveis locais
  polynomial<int64_t> rising_factorial, falling_factorial;
  int64_t index;


  //Procedimentos
    //Recebendo input do usuário
    cout<<"Índice do polinômio: ";
    cin>>index;

    //Calculando os polinômios fatoriais
    falling_factorial=polynomial_falling_factorial<int64_t>(index);
    rising_factorial=polynomial_rising_factorial<int64_t>(index);

    cout<<"[Fatorial descedente] f(-, x,"<< index<<"): "<<falling_factorial.algebraic()<<'\n';
    cout<<"[Fatorial ascedente] f(+, x,"<< index<<"): "<<rising_factorial.algebraic()<<'\n';

  //Finalizando a aplicação
  return 0;

}
