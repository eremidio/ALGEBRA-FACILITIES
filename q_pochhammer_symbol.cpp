//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO q_pochhammer_symbol.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o q_pochhammer_symbol q_pochhammer_symbol.cpp -O3


//Cabeçalho
#include"q_pochhammer_symbol.h"
using namespace std;

//Função principal
int main(){

  //Variáveis locais
  polynomial<int64_t> q_symbol1, q_symbol2;
  int64_t a, n;


  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Inteiro] n: ";
    cin>>n;
    cout<<"[Inteiro] a: ";
    cin>>a;

    //Computandos os símbolos de q-Pochhammer
    q_symbol1=compute_q_pochhammer_symbol<int64_t>(n);
    cout<<"[Parcial do símbolo de q-Pochhammer] (q; q)(∞): ... "<<q_symbol1.algebraic()<<"\n\n";

    q_symbol2=compute_q_pochhammer_symbol<int64_t>(a, n);
    cout<<"[Símbolo de q-Pochhammer] ("<<a<<"; q)("<<n<<"): "<<q_symbol2.algebraic()<<"\n";

  //Finalizando a aplicação
  return 0;

}

