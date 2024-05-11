//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO matrix_exponentiation.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o matrix_exponentiation matrix_exponentiation.cpp


//Cabeçalho
#include"matrix_exponentiation.h"
using namespace std;

//Função principal
int main(){

 //Variáveis locais
 Matrix<int64_t> m, pow_m, powmod_m;
 int64_t e, modulus;


 //Procedimentos
   //Recebendo input do usuário
     //Inteiros
     cout<<"Expoente: ";
     cin>> e;
     cout<<"Inteiro congruente: ";
     cin>> modulus;

     //Matrizes
     m.set_size();
     m.manual_setup();
     cout<<"[Matriz] m:\n ";
     m.print_matrix();

  
   //Testando as rotinas de exponenciação e exponenciação modular
   pow_m=matrix_pow(m, e);
   powmod_m=matrix_powmod(m, e, modulus);

   cout<<"[Matriz] m^"<<e<<":\n";
   pow_m.print_matrix();   
   cout<<"[Matriz] m^"<<e<<" (mod "<<modulus<<"):\n";
   powmod_m.print_matrix();      


 //Finalizando a aplicação
 return 0;

          }
