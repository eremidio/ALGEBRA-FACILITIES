//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA ROTINAS PARA CALCULAR O GCD DE POLINÔMIOS EM DOMÍNIOS DE FATORAÇÃO ÚNICA


//********************************************************************************************************     
//CABEÇALHO
#ifndef POLYNOMIAL_GCD_UNIQUE_FACTORIZATION_DOMAIN_H
#define POLYNOMIAL_GCD_UNIQUE_FACTORIZATION_DOMAIN_H
#include<type_traits>
#include"polynomial_pseudo_division.h"


//********************************************************************************************************     
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
T ufd_gcd(T, T);
template<typename T>
T ufd_gcd_vector(std::vector<T>&);

template<typename T>
polynomial<T> generate_primitive_part_polynomial(polynomial<T>&);


template<typename T>
polynomial<T> generate_primitive_part_polynomial(polynomial<T>&);

template<typename T>
polynomial<T> polynomial_gcd_ufd(polynomial<T>&, polynomial<T>&);

//********************************************************************************************************     
//FUNÇÕES
//Função que calcula o gcd de elementos em um vetor
template<typename T>
T ufd_gcd(T a, T b){
  if(b==0 || b==a) return a;
  else return ufd_gcd(b, (a%b));
};
 
template<typename T>
T ufd_gcd_vector(std::vector<T>& int_vector){
  static_assert(std::is_integral<T>::value, "Float point exception");

  //Variáveis locais
  size_t vec_length=int_vector.size();
  T result;


  //Procedimentos
    //Casos bases:
    if(vec_length==0) return 0;
    if(vec_length==1) return int_vector[0];
    if(vec_length==2) return ufd_gcd(int_vector[0], int_vector[1]);
    if(int_vector[1]==1 || int_vector[0]==1) return 1;

    //Caso geral
    result=ufd_gcd(int_vector[0], int_vector[1]);
    for(size_t i=2; i<vec_length; ++i){
      if(int_vector[i]==1) return 1;

      T temp =ufd_gcd(result, int_vector[i]);
      if(temp==1) return 1;
      else result=temp;

    }  
  
  
  //Resultado
  return result;

};


//Função que calcula a parte primitiva de um polinômio
template<typename T>
polynomial<T> generate_primitive_part_polynomial(polynomial<T>& poly){

  //Variáveis locais
  T polynomial_content=ufd_gcd_vector<T>(poly.polynomial_coefficients);
  polynomial<T> result=poly;
  
  //Procedimento
    //Caso base: o polinômio já é primitivo
    if(polynomial_content==1) return result;
    //Caso geral: redução dos coeficientes
    else{
      for(auto& c:result.polynomial_coefficients)
        c/=polynomial_content;
    }
  

  //Resultado 
  return result;


};


//Função que calcula o mmc de dois polinômios definidos sobre um domínio de fatoração única
template<typename T>
polynomial<T> polynomial_gcd_ufd(polynomial<T>& A, polynomial<T>& B){

  //Caso base: B(x)=0
  if(B.polynomial_coefficients.size()==0 || (B.degree==0 && B.polynomial_coefficients[0]==0)){
    polynomial<T> result=A;
    return A;
  }

   //Restrição
   if(B.degree>A.degree) return polynomial_gcd_ufd(B, A);
  
  //Variáveis locais
  polynomial<T> result, Q, R;
  T a, b, d;


  //Procedimentos
    //Ajuste de coeficientes e cálculo das partes primitivas dos polinômios
    a=ufd_gcd_vector<T>(A.polynomial_coefficients);
    b=ufd_gcd_vector<T>(B.polynomial_coefficients);
    d=ufd_gcd<T>(a, b);

    if(a>1){
      for(auto& ca:A.polynomial_coefficients) ca/=a;
    }
    if(b>1){
      for(auto& cb:B.polynomial_coefficients) cb/=b;
    }
  

    //Loop principal: cadeia euclidiana
    while(1){

      //Cálculo do pseudoquociente e pseudoresto dos polinômios A e B
      polynomial_pseudodivision(A, B, Q, R);
      
      //Condição que determina o fim do loop principal
      if(R.polynomial_coefficients.size()<1 || R.polynomial_coefficients[0]==0)
        break;
      if(R.degree<1){
          B.degree=0;
          B.polynomial_coefficients.resize(0); B.polynomial_coefficients.push_back(1);
          B.polynomial_powers.resize(0); B.polynomial_powers.push_back(0);
          break;  //B(x)=1
        }


      //Atualizando variáveis para a próxima iteração
      A=B;
      B=generate_primitive_part_polynomial<T>(R);
      if(B.polynomial_coefficients[0]<0){
        d*=(-1);
        for(auto& cb:B.polynomial_coefficients) cb*=(-1);
      }
  
    }//Fim do loop principal

    //Ajuste do resultado
    yield_result:
    result=B;
    for(auto& cr:result.polynomial_coefficients) cr*=d;


  //Resultado 
  return result;


};




//********************************************************************************************************     
//FIM DO HEADER
#endif
