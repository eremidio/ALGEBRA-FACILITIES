//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO polynomial_gcd_finite_field.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_gcd_finite_field polynomial_gcd_finite_field.cpp


//Cabeçalho
#include"polynomial_gcd_finite_field.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<int64_t> p1, p2, poly_gcd;
  int64_t prime;

  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Característica do corpo finito] Primo: ";
    cin>>prime;

    p1.set();
    p2.set();
    p1 = polynomial_modulus_reduction<int64_t, int64_t>(p1, prime);
    p2 = polynomial_modulus_reduction<int64_t, int64_t>(p2, prime);
  
    cout << "p1(x): " << p1.algebraic() << '\n';
    cout << "p2(x): " << p2.algebraic() << '\n';


    //Calculando o gcd de polinômios
    poly_gcd=polynomial_gcd_finite_field<int64_t>(p1, p2, prime);
    cout << "[Em F("<<prime<<")] mdc(p1(x), p2(x)) : " << poly_gcd.algebraic() << '\n';


  //Finalizando a aplicação
  return 0;
}
