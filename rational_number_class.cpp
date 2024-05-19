//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO rational_number_class.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o rational_number_class rational_number_class.cpp


//Cabeçalho
#include"rational_number_class.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  rational_number<signed int> r1(2,3), r2, r3, r4, r5, r6, r7(144,480), r8(5,8), r9(12,5);
  rational_number<int> r10, r11;

  float ratio;
  int quotient;
  int i=15;
  float f=0.66565;

  //Procedimentos
    //Recebendo input do usuário
    r2.set();
    
    cout<<"r1: "<<r1.algebraic()<<'\n';
    cout<<"r2: "<<r2.algebraic()<<'\n';


    //Racionalização de frações
    cout<<"Forma reduzida de 144/480: "<<r7.rationalize().algebraic()<<'\n';

    //Operações aritméticas
    r3=r1+r2; r4=r1-r2; r5=r1*r2;r6=r1/r2;
    cout<<"r3=r1+r2: "<<r3.algebraic()<<'\n';
    cout<<"r4=r1-r2: "<<r4.algebraic()<<'\n';
    cout<<"r5=r1*r2: "<<r5.algebraic()<<'\n';
    cout<<"r6=r1/r2: "<<r6.algebraic()<<'\n';


    //Conversão para números
    cout<<"r8: "<<r8.algebraic()<<'\n';
    cout<<"r9: "<<r9.algebraic()<<'\n';

    ratio=to_number<signed int, float>(r8);
    quotient=to_number<signed int,int>(r9);

    cout<<"[float] r8: "<<ratio<<'\n';
    cout<<"[int] r9: "<<quotient<<'\n';

    //Conversão de números em frações
    cout<<"[float] f: "<<f<<'\n';
    cout<<"[int] f: "<<i<<'\n';

    r10=to_rational<int,int>(i);
    r11=to_rational<float,int>(f);

    cout<<"r10: "<<r10.algebraic()<<'\n';
    cout<<"r11: "<<r11.algebraic()<<'\n';


  //Finalizando a aplicação
  return 0;
    
          }
