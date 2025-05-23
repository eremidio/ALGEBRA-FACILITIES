//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO generalized_q_pochhammer_symbol.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o generalized_q_pochhammer_symbol generalized_q_pochhammer_symbol.cpp -O2


//Cabeçalho
#include"generalized_q_pochhammer_symbol.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  int64_t a=1;
  int64_t k=0, n=0, m=0;


  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Números de termos na expansão] k: ";
    cin>>k;
    cout<<"[Inteiro- expoente 1] n: ";
    cin>> n;
    cout<<"[Inteiro- expoente 2] m: ";
    cin>> m;  

    //Computando o símbolo de q-Pochhammer
    polynomial<int64_t> q_symbol=compute_q_pochhammer_symbol<int64_t>(n, m, k, a/*1*/, a/*1*/);

    cout<<"[Série parcial] (q^"<<n<<"; q^"<<m<<")(∞)≃";
    for(auto it=q_symbol.monomials.begin(); it!=q_symbol.monomials.end(); ++it){
      cout<<"("<<it->second.coefficient<<")q^";
      cout<<it->second.power;
      if(it->second.power>0) cout<<"+";
    }
    cout<<'\n';


  //Finalizando a aplicação
  return 0;

}
