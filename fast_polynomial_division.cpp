//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO fast_polynomial_division.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o fast_polynomial_division fast_polynomial_division.cpp -lm -O2


//Cabeçalho
#include"fast_polynomial_division.h"
using namespace std;

//Função principal
int main(){

  //Variáveis locais
  polynomial<int64_t> p1, p2, quotient, remainder;

  //Procedimentos
    //Recebendo input do usuário
    p1.set();
    p2.set();
    cout << "p1(x): " << p1.algebraic() << '\n';
    cout << "p2(x): " << p2.algebraic() << '\n';


    //Calculando o resto e a divisão de polinômios
    fast_polynomial_division<int64_t>(p1, p2, quotient, remainder);
    cout << "[Quociente] q(x)=p1(x)/p2(x): " << quotient.algebraic() << '\n';
    if(is_zero_polynomial<int64_t>(remainder))
      cout << "[Resto] r(x)=p1(x) mod p2(x): \n";
    else
      cout << "[Resto] r(x)=p1(x) mod p2(x): " << remainder.algebraic() << '\n';


  //Finalizando a aplicação
  return 0;

}
