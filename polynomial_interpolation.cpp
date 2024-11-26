//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO polynomial_interpolation.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_interpolation polynomial_interpolation.cpp -O2


//Cabeçalho
#include"polynomial_interpolation.h"
using namespace std;

//Função principal
int main(){

  //Variáveis locais
  polynomial<double> interpolation_polynomial;
  vector<double>  x_vector, y_vector;
  double x, y;
  int64_t point_number;

  //Procedimentos
    //Recebendo input do usuário
    cout<<"Número de pontos usados na interpolação: ";
    cin>> point_number;

    for(int64_t i=0; i<point_number;  ++i){
      cout<<"[Ponto para interpolação] x("<<i<<"): "; cin>>x;
      x_vector.push_back(x);
      cout<<"[Ponto para interpolação] y("<<i<<"): "; cin>>y;
      y_vector.push_back(y);
    }

    //Calculando o polinômio resultante da interpolação
    interpolation_polynomial=langrange_interpolation_formula<double>(x_vector, y_vector);
    cout<<"[Polinômio interpolado] p(x) = "<<interpolation_polynomial.algebraic()<<'\n';


  //Finalizando a aplicação
  return 0;

}
