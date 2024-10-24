//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO determinant_gauss_barreis.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o determinant_gauss_barreis determinant_gauss_barreis.cpp


//Cabeçalho
#include"determinant_gauss_barreis.h"
using namespace std;



//Função principal
int main(){

  //Variáveis locais
  Matrix<int64_t> m;
  int64_t det;

  //Procedimentos 
    //Recebendo input do usuário
    m.set_size();
    m.manual_setup();

    cout<<"Matriz m: \n";
    m.print_matrix();

    //Calculando o determinante da matriz usandooalgoritmo de Gauss-Barreis
    det=determinant_gauss_barreis<int64_t>(m);
    cout<<"det(m) = "<<det<<'\n';


  //Finalizando a aplicação
  return 0;

}
