//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA UMA CLASSE DE POLINÔMIOS DE DUAS VARIÁVEIS

/*
POLINÔMIOS DEFINIDOS EM DUAS VARIÁVEIS K[x, y] SOBRE UM CORPO NÚMERICO K SÃO
IMPORTANTES FERRAMENTAS EM ALGORITMOS EM TEORIA DE NÚMEROS E ÁLGEBRA.
A PRESENTE CLASSE IMPLEMENTA OPERAÇÕES BÁSICAS ENVOLVENDO ARITMÉTICA POLINOMIAL
E PODERÁ SER USADA PARA IMPLEMENTAR ALGORITMOS MAIS SOFISTICADOS.

*/


//**********************************************************************************************
//CABEÇALHO
#ifndef BIVARIATE_POLYNOMIALS_H
#define BIVARIATE_POLYNOMIALS_H
#include"bivariate_monomial_class.h"
#include<map>
#include<functional>


//**********************************************************************************************
//CLASSE DE POLINÔMIOS EM DUAS VARIÁVEIS
template<typename T>
class bivariate_polynomial{
    public:

  //Membros
  std::map<int64_t, bivariate_monomial<T>, std::greater<int64_t>> monomials;

  //Construtores e destruídores
  bivariate_polynomial(){ };
  virtual ~bivariate_polynomial(){ };  

  //Métodos da classe
    //Funções básicas de input e output
    void set();
    void add_monomial(T, int64_t, int64_t);
    int64_t degree();
    void remove_null_terms();
    std::string algebraic();

    //Operações aritméticas
    bivariate_polynomial<T> operator=(const bivariate_polynomial<T>&);
    bivariate_polynomial<T> operator+(bivariate_polynomial<T>&);
    bivariate_polynomial<T> operator-(bivariate_polynomial<T>&);
    bivariate_polynomial<T> operator*(bivariate_polynomial<T>&);
    bivariate_polynomial<T> operator/(bivariate_polynomial<T>&);
  

};


//**********************************************************************************************
//MÉTODOS DA CLASSE
//Função que define manualmenteos monômios deum polinômio em duas variáveis
template<typename T>
void bivariate_polynomial<T>::set(){

  //Variáveis locais
  bivariate_monomial<T> element;
  int64_t monomial_number;

  //Procedimento
    //Recebendo input do usuário
    std::cout<<"Número de termos do polinômio: ";
    std::cin>>monomial_number;


    //Ajustando os monômios do polinômio em questão
    while(monomial_number>0){
      element.set();
      monomials.insert({element.valuation, element});
      monomial_number--;
    };


};


//Função que insere um monômio no polinômio
template<typename T>
void bivariate_polynomial<T>::add_monomial(T coeff, int64_t x_power, int64_t y_power){

  //Variáveis locais
  bivariate_monomial<T> element(coeff, x_power, y_power);

  //Procedimento
    //Inserindo um termo no polinômio
    monomials.insert({element.valuation, element});
    
};


//Função que retorna o grau de um polinômio
template<typename T>
int64_t bivariate_polynomial<T>::degree(){

  //Caso base 
  if(monomials.size()==0) return 0;

  //Variáveis locais
  auto it=monomials.begin();

  //Resultado
  return (it->second.x_valuation+it->second.y_valuation);

};


//Função que remove termos com coeficientes nulos
template<typename T>
void bivariate_polynomial<T>::remove_null_terms(){

  //Procedimentos: loop sobre os termos
  for(auto it=monomials.begin(); it!=monomials.end();){
    if(it->second.coefficient == 0)
      it = monomials.erase(it);
    else  ++it;
  }

};


//Função que escreve um polinômio como uma string 
template<typename T>
std::string bivariate_polynomial<T>::algebraic(){

  //Variáveis locais
  std::string polynomial_string="";
  auto it=monomials.begin();

  //Procedimentos
    //Caso base:
    if(monomials.size()==0){
      polynomial_string=" ";
      return polynomial_string;
    }

    //1º elemento
    polynomial_string+=it->second.algebraic();
    ++it;

    //Demais elementos
    for(; it!=monomials.end(); ++it){
      if(it->second.coefficient==0) continue;
      if(it->second.coefficient>0) polynomial_string+="+";
      polynomial_string+=it->second.algebraic();
    }

  //Resultado
  return polynomial_string;

};


  //Funções que implementam aritmética de polinômios em duas variáveis

//Cópia (copy constructor)
template <typename T>
bivariate_polynomial<T> bivariate_polynomial<T>::operator=(const bivariate_polynomial<T>& p2) {

  // Condição que checa a não igualdade dos polinômios
  if (this != &p2) {

    // Ajuste do array de monômios
    this->monomials = p2.monomials;

  };

  // Resultado
  return *this;
};

//Adição
template <typename T>
bivariate_polynomial<T> bivariate_polynomial<T>::operator+(bivariate_polynomial<T>& p1){

  //Caso base
  if(p1.monomials.size()==0){
    bivariate_polynomial<T> result=*this;
    return result;
  }

  if(this->monomials.size()==0){
    bivariate_polynomial<T> result=p1;
    return result;
  }

  //Variáveis locais
  bivariate_polynomial<T> result=p1;


  //Procedimentos
    //Iterando sobre os monômios do primeiro termo
    for(auto it=monomials.begin(); it!=monomials.end(); ++it){

      //Definindo um termo
      bivariate_monomial<T> element=it->second;
      int64_t key=element.valuation;

      //Busca por monômios com o mesmo grau
      auto found=result.monomials.find(key);

      //Caso haja um termo com o mesmo grau os coeficientes são adicionados
      if(found != result.monomials.end() && found->second.x_valuation==it->second.x_valuation)
        found->second.coefficient=found->second.coefficient+element.coefficient;
      else result.monomials.insert({key, element});
 
    }

    //Ajuste do resultado final
    result.remove_null_terms();

  //Resultados
  return result;

};


//Subtração
template<typename T>
bivariate_polynomial<T> bivariate_polynomial<T>::operator-(bivariate_polynomial<T>& p1){


  //Caso base
  if(p1.monomials.size()==0){
    bivariate_polynomial<T> result=*this;
    return result;
  }

  //Variáveis locais
  bivariate_polynomial<T> result=*this;


  //Procedimentos
    //Iterando sobre os monômios do segundo termo
    for(auto it=p1.monomials.begin(); it!=p1.monomials.end(); ++it){

      //Definindo um termo
      bivariate_monomial<T> element=it->second;
      int64_t key=element.valuation;

      //Busca por monômios com o mesmo grau
      auto found=result.monomials.find(key);

      //Caso haja um termo com o mesmo grau os coeficientes são adicionados
      if(found != result.monomials.end() && found->second.x_valuation==it->second.x_valuation)
        found->second.coefficient=found->second.coefficient-element.coefficient;
      else{
        element.coefficient=element.coefficient*(-1);//Invertendo o sinal do coefficiente
        result.monomials.insert({key, element});
          }
 
    }

    //Ajuste do resultado final
    result.remove_null_terms();

  //Resultados
  return result;


};



//Multiplicação
template<typename T>
bivariate_polynomial<T> bivariate_polynomial<T>::operator*(bivariate_polynomial<T>& p1){

  //Caso base
  if(this->monomials.size()==0 || p1.monomials.size()==0){
    bivariate_polynomial<T> result;
    return result;
  }

  //Variáveis locais
  bivariate_polynomial<T> result;
  T new_coefficient;
  int64_t new_x_val, new_y_val, val;
  

  //Procedimentos
    //Iterando sobre todos os produtos possíveis de monômios de ambos dos polinômios
    for(auto it1=this->monomials.begin(); it1!=this->monomials.end(); ++it1){
      for(auto it2=p1.monomials.begin(); it2!=p1.monomials.end(); ++it2){

        //Calculando os coeficientes e potências dos novos termos
        new_coefficient=it1->second.coefficient*it2->second.coefficient;
        new_x_val=it1->second.x_valuation+it2->second.x_valuation;
        new_y_val=it1->second.y_valuation+it2->second.y_valuation;
        val=(3*new_x_val)+(2*new_y_val);

        //Checando se há algum termo no produto com o mesmo expoente
        auto found=result.monomials.find(val);

        if(found != result.monomials.end())
          found->second.coefficient+=new_coefficient;
        else{
          bivariate_monomial<T> product_monomial(new_coefficient, new_x_val, new_y_val);
          result.monomials.insert({val, product_monomial});
        }        
     


      }

    }

    //Ajuste do resultado final
    result.remove_null_terms();

  //Resultados
  return result;

};


//Divisão
template<typename T>
bivariate_polynomial<T> bivariate_polynomial<T>::operator/(bivariate_polynomial<T>& p1){

  //Restrição
  assert(this->degree() >= p1.degree() && p1.monomials.size() > 0);

  // Caso base: o dividendo é um polinômio nulo
  if (this->monomials.size() == 0) {
    bivariate_polynomial<T> result;
    return result;
  }

  //Variáveis locais
  bivariate_polynomial<T> dividend_polynomial = *this;
  bivariate_polynomial<T> result;


  //Procedimentos
    // Loop sobre os monômios do dividendo
    while (dividend_polynomial.degree() >= p1.degree()) {

        //Cálculos dos termos de maior coefficientes
        auto lead_term_dividend = dividend_polynomial.monomials.begin();
        auto lead_term_divisor = p1.monomials.begin();

        //Condição que determina o fim do loop: divisibilidade dos termos de maior ordem no divisor e dividendo
        if(lead_term_dividend->second.x_valuation<lead_term_divisor->second.x_valuation ||
          lead_term_dividend->second.y_valuation<lead_term_divisor->second.y_valuation) break;

        //Cálculo do termo (monômio do quociente)
        T coeff_ratio = lead_term_dividend->second.coefficient / lead_term_divisor->second.coefficient;
        if(coeff_ratio==0){
          std::cout<<"Erro na divisão polinomial.\n";
          break;
        }
        int64_t x_power=lead_term_dividend->second.x_valuation - lead_term_divisor->second.x_valuation;
        int64_t y_power=lead_term_dividend->second.y_valuation - lead_term_divisor->second.y_valuation;
        int64_t val=(3*x_power)+(2*y_power);
        bivariate_monomial<T> quotient_monomial(coeff_ratio, x_power, y_power);
        result.monomials.insert({val, quotient_monomial});

        //Atualizando o dividendo
        bivariate_polynomial<T> multiplier;
        multiplier.monomials[val] = quotient_monomial;
        bivariate_polynomial<T> reducer = multiplier * p1;
        dividend_polynomial = dividend_polynomial - reducer;

        // Remove termos com coeficientes nulos
        dividend_polynomial.remove_null_terms();
    }

    // Ajuste do resultado final
    result.remove_null_terms();

  //Resultado
  return result;

};

//**********************************************************************************************
//DECLARAÇÃO DE FUNÇÕES AUXILIARES
template<typename T>
bivariate_polynomial<T> remainder(bivariate_polynomial<T>&, bivariate_polynomial<T>&);

template<typename T, typename U>
bivariate_polynomial<T> polynomial_mod(bivariate_polynomial<T>&, U);

template<typename T, typename U>
U polynomial_evaluation(bivariate_polynomial<T>&, U, U);

template<typename T, typename U>
U modular_polynomial_evaluation(bivariate_polynomial<T>&, U, U, U);


//**********************************************************************************************
//FUNÇÕES AUXILIARES
//Função que calcula o resto da divisão de dois polinômios
template<typename T>
bivariate_polynomial<T> remainder(bivariate_polynomial<T>& p1, bivariate_polynomial<T>& p2){

  //Variáveis locais
  bivariate_polynomial<T> quotient=p1/p2;
  bivariate_polynomial<T> reducer =quotient*p2;
  bivariate_polynomial<T> result=p1-reducer;

  //Resultado
  return result;

};


//Função que reduzos coefficientes de um inteiro a menos de uma relação de congruência
template<typename T, typename U>
bivariate_polynomial<T> polynomial_mod(bivariate_polynomial<T>& p1, U modulus){

  //Restrição
  static_assert(std::is_integral<T>::value, "Expoentes devem ser inteiros");
  static_assert(std::is_integral<U>::value, "Coeficientes devem ser inteiros");

  //Variáveis locais
  bivariate_polynomial<T> result;


  //Procedimentos
    //Loop sobre os monômios do polinômio
    for(auto it=p1.monomials.begin(); it!=p1.monomials.end(); ++it){
  
      int64_t key=it->first;
      bivariate_monomial<T> new_monomial=it->second;

      new_monomial.coefficient%=modulus;
      result.monomials[key]=new_monomial;
      
    }
   

    //Ajuste do resultado final
    result.remove_null_terms();

  //Resultado
  return result;
  
};

//Função que calcula o valor de um polinômio
template<typename T, typename U>
U polynomial_evaluation(bivariate_polynomial<T>& p1, U arg1, U arg2){

  //Variáveis locais
  U result=0;

  //Procedimentos
    //Loop sobre os monômios do polinômio
    for(auto it=p1.monomials.begin(); it!=p1.monomials.end(); ++it)
      result=result+bivariate_monomial_valuation<T,U>(it->second, arg1, arg2);


  //Resultado
  return result;
  
};

//Função que calcula o valor de um polinômio a menos de uma relação de congruência
template<typename T, typename U>
U modular_polynomial_evaluation(bivariate_polynomial<T>& p1, U arg1, U arg2, U modulus){

  //Restrição
  static_assert(std::is_integral<T>::value, "Expoentes devem ser inteiros");
  static_assert(std::is_integral<U>::value, "Coeficientes devem ser inteiros");

  //Variáveis locais
  U result=0;

  //Procedimentos
    //Loop sobre os monômios do polinômio
    for(auto it=p1.monomials.begin(); it!=p1.monomials.end(); ++it){
      result=result+modular_bivariate_monomial_valuation<T,U>(it->second, arg1, arg2, modulus);
      result%=modulus;
    }

  //Resultado
  return (result%modulus);
  
};
 


//**********************************************************************************************
//FIM DO HEADER
#endif
