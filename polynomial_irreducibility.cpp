//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO polynomial_irreducibility.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_irreducibility polynomial_irreducibility.cpp -O2


//Cabeçalho
#include"polynomial_irreducibility.h"
using namespace std;

//Função  principal
int main(){

  //Variáveis locais
  polynomial<int64_t> f_poly;
  int64_t field_characteristic;

  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Característica-primo base de GF(p)] p: ";
    cin>> field_characteristic;

    f_poly.set();
    cout<<"f(x): "<<f_poly.algebraic()<<'\n';
    
    //Redução dos coeficientes do polinômio
    for (auto& c:f_poly.polynomial_coefficients) c%=field_characteristic;
    cout<<"f(x) mod "<<field_characteristic<<": "<<f_poly.algebraic()<<'\n';

    //Teste de irredutibilidade 
    if(irredutibility_criterion(f_poly, field_characteristic)==true)
      cout<<"f(x) é irredutível em GF("<<field_characteristic<<")\n";
    else cout<<"f(x) não é irredutível em GF("<<field_characteristic<<")\n";


  //Finalizando a aplicação
  return 0;

}
