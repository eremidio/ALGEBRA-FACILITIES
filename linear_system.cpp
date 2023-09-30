//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO linear_system.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o linear_system linear_system.cpp


//Cabeçalho
#include"linear_system.h"
#include<iostream>
using namespace std;


//Função principal
int main(){
//Instanciando um objeto da classe
cramer_linear_system_solver<double> system1;

//Testes
//Inicializando o sistema linear de equações
system1.setup();
//Verificando se o sistema de equações tem solução ou não
system1.set_status();
//Exibindo o sistema linear de equações
system1.print_linear_system();

//Resolvendo o sistema linear
system1.solve();

//Printando a solução na tela
std::cout<<"\nEis a solução do sistema linear:\n";
system1.print_solution();
//Finalizando a aplicação
return 0;
          }

