//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO sturm_polynomial_algorithm.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o  sturm_polynomial_algorithm sturm_polynomial_algorithm.cpp


//Cabeçalho
#include"sturm_polynomial_algorithm.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  double min, max;
  polynomial<double> poly;
  int64_t root_counter;

  //Procedimentos
    //Recebendo input do usuário
    cout<<"Extremo inferior do intervalo: ";
    cin>>min;
    cout<<"Extremo superior do intervalo: ";
    cin>>max;

    poly.set();


    //Computando o número de reaízes reais de um polinômio num dado intervalo
    cout<<"p(x): "<<poly.algebraic()<<'\n';
    root_counter=real_root_counting<double, double>(poly, min, max);
    cout<<"Número de raízes de p(x) nointervalo ["<<min<<", "<<max<<"]: "<<root_counter<<'\n';


  //Finalizando a aplicação
  return 0;

}
