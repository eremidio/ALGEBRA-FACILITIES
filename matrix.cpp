//VAMOS CRIAR UM PROGRAMAPARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO matrix.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o matrix matrix.cpp

//Cabeçalho
#include"matrix.h"
#include<iostream>
using namespace std;

//Função principal
int main(){
//Variáveis locais
Matrix<int> a(2), b(2,2), c, d, e, f, g, h, j, i(2, Identity), z(2, Zero); 

//Testes
//Matriz identidade e matriz nula
cout<<"Matriz identidade:\n";
i.print_matrix();
cout<<"Matriz nula:\n";
z.print_matrix();

//Operações de entradas e saída de dados envolvendo matrizes
cout<<"Entrada e saída de dados:\n";
cout<<"Matriz a:\n";
a.manual_setup();
a.print_matrix();
cout<<"Matriz b:\n";
b.manual_setup();
b.print_matrix();

//Redimensionando matrizes
cout<<"Redimensionando matrizes:\n";
cout<<"Matriz c:\n";
c.set_size();
c.reshape(3,3);
c.add_row();
c.add_column();

c.manual_setup();
c.print_matrix();
cout<<"Matriz a:\n";
a.remove_row();
a.remove_column();
a.print_matrix();

//Operações de acesso aos elementos da matriz
cout<<"Extraindo linhas e coluna da matriz C:\n";
c.get_row(2).print_matrix();
c.get_column(2).print_matrix();
c.slice(2,3,2,3).print_matrix();
c.comatrix(2,3).print_matrix();

//Operações básicas
cout<<"Operações básicas em matrizes:\n";
cout<<"Soma:\n";
d=b+i;
d.print_matrix();
cout<<"Subtração:\n";
e=b-i;
e.print_matrix();
cout<<"Multiplicação:\n";
f=b*e;
f.print_matrix();
cout<<"Multiplicação por escalar:\n";
h=b.scalar_multiplication(35);
h.print_matrix();
cout<<"Tranposição:\n";
j=b.transpose();
j.print_matrix();
cout<<"Permutação de linhas e colunas:\n";
j.permute_rows(0,1);
j.print_matrix();
j.permute_columns(0,1);
j.print_matrix();


//Finalizando a aplicação
return 0;
          }

