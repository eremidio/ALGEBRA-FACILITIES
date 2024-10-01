//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO polynomial_root_finite_field.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_root_finite_field polynomial_root_finite_field.cpp


//Cabeçalho
#include"polynomial_root_finite_field.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<int64_t> p1;
  int64_t prime;
  int64_t root;


  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Característica do corpo finito] Primo: ";
    cin>>prime;
 
    p1.set();
    cout<<"p(x): "<<p1.algebraic()<<'\n';

    //Cálculo da raíz do polinômio
    root=polynomial_root_finite_field(p1, prime);

    if(root!=0)
      cout<<"Solução de p(x)=0 em F("<<prime<<"): "<<root<<'\n';
    else
      cout<<"Não foi encontrada solução de p(x)=0 em F("<<prime<<")\n";

    
  //Finalizando a aplicação
  return 0;

}
