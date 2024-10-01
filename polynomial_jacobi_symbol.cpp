//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO polynomial_jacobi_symbol.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_jacobi_symbol polynomial_jacobi_symbol.cpp


//Cabeçalho
#include"polynomial_jacobi_symbol.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<int64_t> f, g;
  int64_t prime;
  int j_symbol;


  //Procedimento
    //Recebendo input do usuário
    cout<<"[Primo - característica de corpo finito] p: ";
    cin>> prime;

    f.set();
    g.set();
    cout<<"f(x): "<<f.algebraic()<<'\n';
    cout<<"g(x): "<<g.algebraic()<<'\n';

    //Checando se g(x) é irredutível em F(p)
    if(irredutibility_criterion<int64_t>(g, prime)==false){
      cout<<"g(x) não é irredutivél em F("<<prime<<")\n";
      return 0;
    }
  
    //Calculando o sṕimbolo de Jacobi
    j_symbol=polynomial_jacobi_symbol(f, g, prime);
    cout<<"(f(x)|g(x)) = "<<j_symbol<<'\n';


  //Finalizando a aplicação
  return 0;

}
