//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO polynomial_exponentiation_finite_field.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o polynomial_exponentiation_finite_field polynomial_exponentiation_finite_field.cpp -O2


//Cabeçalho
#include"polynomial_exponentiation_finite_field.h"
using namespace std;


//Função principal
int main(){

  // Variáveis locais
  polynomial<int> p1, p2, pow_poly_gf, powmod_poly_gf;
  int e, p;

  // Procedimentos recebendo input do usuário
  cout << "Expoente: ";
  cin >> e;
  cout << "GF(p)-> p: ";
  cin >> p;

  p1.set();
  p2.set();

  cout << "p1(x): " << p1.algebraic() << '\n';
  cout << "p2(x): " << p2.algebraic() << '\n';
  cout << "e: " << e << '\n';

  // Testando as rotinas de expoenenciação e exponenciação modular
 // pow_poly_gf = polynomial_bin_pow_finite_field<int, int>(p1, e, p);
  powmod_poly_gf = polynomial_powmod_finite_field<int, int>(p1, p2, e, p);

  //cout << "p1(x)^e mod"<<p<< ": " << pow_poly_gf.algebraic() << '\n';
  cout << "p1(x)^e mod(p2(x),"<<p<<"): " << powmod_poly_gf.algebraic() << '\n';

  // Finalizando a aplicação
  return 0;


}

