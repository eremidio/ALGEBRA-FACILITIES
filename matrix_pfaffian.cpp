//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO matrix_pfaffian.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o matrix_pfaffian matrix_pfaffian.cpp


//Cabeçalho
#include"matrix_pfaffian.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  Matrix<int32_t> m1;
  int32_t m1_pfaffian, m1_determinant;

  //Procedimentos
    //Recebendo input do usuário
    m1.set_size();
    m1.manual_setup();

    cout<<"[Matriz] m:\n";
    m1.print_matrix();

    //Checando se a matriz em questão é antissimétrica
    if(is_skew_symetric<int32_t>(m1)==false){
      cout<<"A matriz em questão não é antissimétrica\n";
      return 0;
    }

    //Calculando o Pfaffiano e o determinante da matriz
    m1_pfaffian=matrix_pfaffian<int32_t>(m1);
    m1_determinant=antisymetric_matrix_determinant<int32_t>(m1);
    cout<<"[Pfaffiano] pf(m) = "<<m1_pfaffian<<'\n';    
    cout<<"[Determinante] det(m) = "<<m1_determinant<<'\n';

  //Resultados
  return 0;

}
