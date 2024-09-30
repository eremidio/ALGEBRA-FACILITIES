//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO polynomial_monic_finite_field.h
//COMPILAR ESTE PROGRAMA COMO COMANDO: g++ -o polynomial_monic_finite_field polynomial_monic_finite_field.cpp


//Cabeçalho
#include"polynomial_monic_finite_field.h"
#include"polynomial_modulus_reduction.h"
using namespace std;


//Função principal
int main(){

  // Variáveis locais
  polynomial<int64_t> p1, monic_poly1;
  int64_t prime;

  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Característica do corpo finito] Primo: ";
    cin>>prime;

    p1.set();
    p1 = polynomial_modulus_reduction<int64_t, int64_t>(p1, prime);
    cout << "p1(x): " << p1.algebraic() << '\n';

    //Reduzindo os coeficientes do polinômio
    monic_poly1=make_monic_polynomial_finite_field<int64_t>(p1, prime);
    cout << "[Mônico em F("<<prime<<")] p1(x): " << monic_poly1.algebraic() << '\n';

  //Finalizando a aplicação
  return 0;
} 
