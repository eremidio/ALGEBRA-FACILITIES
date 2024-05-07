//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO polynomial_modulus_reduction.h 
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_modulus_reduction polynomial_modulus_reduction.cpp

//Cabeçalho
#include"polynomial_modulus_reduction.h"
using namespace std;


//Função principal
int main(){

 //Variáveis locais
 polynomial<int64_t> poly, reduced_poly;
 int32_t modulus;


 //Procedimentos
  //Recebdendo input do usuário
  cout<<"Coeficiente de redução(m): ";
  cin>>modulus;

  poly.set();
  cout<<"\np(x): "<<poly.algebraic()<<'\n';

  //Reduzindo os coeficientes de um polinômios a menos de uma relação de congruência
  reduced_poly=polynomial_modulus_reduction<int64_t, int32_t>(poly, modulus);
  cout<<"p(x) (mod m): "<< reduced_poly.algebraic() <<'\n';


 //Finalizando a aplicação
 return 0;

          } 
