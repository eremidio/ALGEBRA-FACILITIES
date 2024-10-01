//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO fast_polynomial_division_finite_field.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o fast_polynomial_division_finite_field fast_polynomial_division_finite_field.cpp -lm -O2


//Cabeçalho
#include"fast_polynomial_division_finite_field.h"
using namespace std;

//Função principal
int main(){

  //Variáveis locais
  polynomial<int64_t> p1, p2, quotient, remainder;
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


    //Calculando o resto e a divisão de polinômios
    fast_polynomial_division_finite_field<int64_t>(p1, p2, quotient, remainder, prime);
    cout << "[Em F("<<prime<<")] q(x)=p1(x)/p2(x): " << quotient.algebraic() << '\n';
    cout << "[Em F("<<prime<<")] r(x)=p1(x) mod p2(x): " << remainder.algebraic() << '\n';


  //Finalizando a aplicação
  return 0;

}
