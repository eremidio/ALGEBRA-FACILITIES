//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO polynomial_gcd_extended.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_gcd_extended polynomial_gcd_extended.cpp


//Cabeçalho
#include"polynomial_gcd_extended.h"

//Função principal
int main(){

 //Variáveis locais
 polynomial<int> p1, p2;


 //Procedimentos
  //Recebendo input do usuário
  p1.set();
  p2.set();


  //Executando o algoritmo de Euclides
  polynomial_gcd_extended(p1,p2);


 //Resultado
 return 0;

          }
