//VAMOS CRIAR UM PROGRAMA QUE TEST AS ROTINAS CRIADAS NO ARQUIVO q_number.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o q_number q_number.cpp



//Cabeçalho
#include"q_number.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<int64_t> q_n;
  int64_t n;


  //Procedimentos 
    //Recebendo input do usuário
    cout<<"[Inteiro] n: "; cin>>n;

    //Calculando [n]
    q_n=compute_q_number<int64_t>(n);
    cout<<"\n["<<n<<"] : ";

    for(auto it=q_n.monomials.begin(); it!=q_n.monomials.end(); ++it){
      cout<<"("<<it->second.coefficient<<")q^";
      cout<<it->second.power;
      if(it->second.power>0) cout<<"+";
    }
    cout<<'\n';

   //Checando a equivalência [n]=n no limite q->1
   int64_t qn1=polynomial_evaluation<int64_t, int64_t>(q_n, 1);
   cout<<"[Limite q->1] [n](q->1)="<<qn1<<'\n';
    

  //Finalizando a aplicação
  return 0;  

} 

