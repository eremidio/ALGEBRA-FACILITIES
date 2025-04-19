//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA UMA CLASSE DE MONÔMIOS EM DUAS VARIÁVEIS x,y


/*
ESTA CLASSE DE MONÔMIOS EM DUAS VARIÁVEIS SERÁ USADO PARA IMPLEMENTAR
UMA CLASSE DE POLINÔMIOS EM DUAS VARIÁVEIS, QUE PODERÁ SER USADA COMO
SUBROTINAS EM ALGORITMOS MAIS SOFISTICADOS.

*/ 


//************************************************************************************************************************
//CABEÇALHO
#ifndef BIVARIATE_MONOMIAL_CLASS_H
#define BIVARIATE_MONOMIAL_CLASS_H
#include<stdint.h>
#include<inttypes.h>
#include<assert.h>
#include<string>
#include<iostream>
#include<type_traits>



//************************************************************************************************************************
//FUNÇÃO AUXILIAR
//Função para atribuir um peso (chave) aos monômios de duas variáveis
int64_t cantor_pairing_function(int64_t a, int64_t b){

  //Variáveis locais
  int64_t sum = a + b;
  
  //Resultado
  return (((sum * (sum + 1)) / 2) + b);

};

//************************************************************************************************************************
//CLASSE DE MONÔMIOS
template<typename T>
class bivariate_monomial{
    public:
  
  //Membros da classe
  T coefficient;
  int64_t x_valuation;
  int64_t y_valuation;
  int64_t valuation;

  //Construtores e destruidores
  bivariate_monomial(){ };
  bivariate_monomial(T a, int64_t b, int64_t c){
    coefficient=a;
    x_valuation=b;
    y_valuation=c;
    valuation=cantor_pairing_function(x_valuation, y_valuation);
  };

  virtual ~bivariate_monomial(){ };

  //Métodos da classe
    //Funções básicas: input e output
    void set_degrees(int64_t, int64_t);
    void set_coefficient(T);
    void set();
    std::string algebraic();

    //Operações aritméticas
    bivariate_monomial<T> operator+(bivariate_monomial<T>&);
    bivariate_monomial<T> operator-(bivariate_monomial<T>&);
    bivariate_monomial<T> operator*(bivariate_monomial<T>&);
    bivariate_monomial<T> operator/(bivariate_monomial<T>&);
    bivariate_monomial<T> operator=(const bivariate_monomial<T>&);

    //Operadores de comparação: útil em operações com polinômios
    bool operator==(bivariate_monomial<T>&);
    bool operator<(bivariate_monomial<T>&);

};

//************************************************************************************************************************
//MÉTODOS DA CLASSE
//Função que ajusta o grau de um monômio
template<typename T>
void bivariate_monomial<T>::set_degrees(int64_t a, int64_t b){
 
  x_valuation=a;
  y_valuation=b;
  valuation=cantor_pairing_function(x_valuation, y_valuation);

};


//Função que define o coeficiente de um monômio
template<typename T>
void bivariate_monomial<T>::set_coefficient(T n){
  coefficient=n;
};


//Função que define manualmente um monômio
template<typename T>
void bivariate_monomial<T>::set(){

  //Variáveis locais
  T c;
  int64_t x_power, y_power;

  //Procedimentos
    //Recebendo input do usuário
    std::cout<<"Coeficiente do monômio: ";
    std::cin>> c;
    std::cout<<"Potência da variável x monômio: ";
    std::cin>> x_power;
    std::cout<<"Potência da variável y monômio: ";
    std::cin>> y_power;

    //Definindo os parâmetros do monômio
    coefficient=c;
    x_valuation=x_power;
    y_valuation=y_power;
    valuation=cantor_pairing_function(x_valuation, y_valuation);

};

//Função que escreve um monômio como uma string
template<typename T>
std::string bivariate_monomial<T>::algebraic(){

  //Variáveis locais
  std::string monomial_string="";

  //Procedimentos 
    //Caso base: a(n)=0
    if(coefficient==0){
      monomial_string=" ";
      return monomial_string;
    }

    //Caso geral
    monomial_string+=std::to_string(coefficient);
    monomial_string+="x^";
    monomial_string+=std::to_string(x_valuation);
    monomial_string+="y^";
    monomial_string+=std::to_string(y_valuation);


  //Resultado
  return monomial_string;

}

    /*Operações aritméticas*/

//Cópia (copy constructor)
template<typename T>
bivariate_monomial<T> bivariate_monomial<T>::operator=(const bivariate_monomial<T>& m1){

  //Condição que implica a não igualdade de monômios
  if(this!= &m1){
    this->coefficient=m1.coefficient;
    this->x_valuation=m1.x_valuation;
    this->y_valuation=m1.y_valuation;
    this->valuation=m1.valuation;
  }


  //Resultado
  return *this;

};


//Adição
template<typename T>
bivariate_monomial<T> bivariate_monomial<T>::operator+(bivariate_monomial<T>& m1){

  //Restrição: grau dos monômios nas duas variáveis devem ser iguais
  assert(valuation==m1.valuation && x_valuation==m1.x_valuation);

  //Variáveis locais
  bivariate_monomial<T> result;

  //Procedimentos
    //Ajuste do resultado
    result.valuation=valuation;    
    result.x_valuation=x_valuation;
    result.y_valuation=y_valuation;
    result.coefficient=coefficient+m1.coefficient;


  //Resultado
  return result;
};


//Subtração
template<typename T>
bivariate_monomial<T> bivariate_monomial<T>::operator-(bivariate_monomial<T>& m1){

  //Restrição: grau dos monômios nas duas variáveis devem ser iguais
  assert(valuation==m1.valuation && x_valuation==m1.x_valuation);

  //Variáveis locais
  bivariate_monomial<T> result;

  //Procedimentos
    //Ajuste do resultado
    result.valuation=valuation;    
    result.x_valuation=x_valuation;
    result.y_valuation=y_valuation;
    result.coefficient=coefficient-m1.coefficient;


  //Resultado
  return result;
};


//Multiplicação
template<typename T>
bivariate_monomial<T> bivariate_monomial<T>::operator*(bivariate_monomial<T>& m1){

  //Variáveis locais
  bivariate_monomial<T> result;

  //Procedimentos
    //Ajuste do resultado
    result.x_valuation=x_valuation+m1.x_valuation;
    result.y_valuation=y_valuation+m1.y_valuation;
    result.valuation=cantor_pairing_function(result.x_valuation, result.y_valuation);
    result.coefficient=coefficient*m1.coefficient;
    

  //Resultado
  return result;
};


//Divisão
template<typename T>
bivariate_monomial<T> bivariate_monomial<T>::operator/(bivariate_monomial<T>& m1){


  //Variáveis locais
  bivariate_monomial<T> result;

  //Procedimentos
    //Ajuste do resultado
    result.x_valuation=x_valuation-m1.x_valuation;
    result.y_valuation=y_valuation-m1.y_valuation;
    result.valuation=cantor_pairing_function(result.x_valuation, result.y_valuation);
    result.coefficient=coefficient/m1.coefficient;
    

  //Resultado
  return result;
};


  /*Operadores relacionais*/

//Comparação
template<typename T>
bool bivariate_monomial<T>::operator==(bivariate_monomial<T>& m1){

  //Resultado
  return (coefficient==m1.coefficient && valuation==m1.valuation && x_valuation==m1.x_valuation);

};


//Menor que <  
template<typename T>
bool bivariate_monomial<T>::operator<(bivariate_monomial<T>& m1){

  //Resultado
  if (valuation != m1.valuation) return valuation < m1.valuation;
  else if (x_valuation != m1.x_valuation) return x_valuation < m1.x_valuation;
  else return y_valuation < m1.y_valuation;

};

//************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES AUXILIARES

template<typename T, typename U>
bivariate_monomial<T> bivariate_monomial_bin_pow(bivariate_monomial<T>&, U);

template<typename T, typename U>
bivariate_monomial<T> bivariate_monomial_mod_bin_pow(bivariate_monomial<T>&, U, U);

template<typename T, typename U>
bivariate_monomial<T> bivariate_monomial_mod(bivariate_monomial<T>&, U);

template<typename T, typename U>
U bivariate_monomial_valuation(bivariate_monomial<T>&, U, U);

template<typename T, typename U>
U modular_bivariate_monomial_valuation(bivariate_monomial<T>&, U, U, U); 


//************************************************************************************************************************
//FUNÇÕES AUXILIARES
//Função que calcula a exponencial de um monômio
template<typename T, typename U>
bivariate_monomial<T> bivariate_monomial_bin_pow(bivariate_monomial<T>& m1, U exponent){

  //Restrição
  static_assert(std::is_integral<U>::value, "Expoentes devem ser inteiros");

  //Variáveis locais
  bivariate_monomial<T> result(1,0,0); //Identidadena classe de monômios em duas variáveis
  bivariate_monomial<T> multiplier=m1;

  //Procedimentos
    //Loop principal sobre os bits do expoentes
    while(exponent>0){
      
      //Checando a paridade do bit menos significativo
      if(exponent&1){
        bivariate_monomial<T> temp=result*multiplier;
        result=temp;
      }

      //Atualizando variáveis para a próxima iteração
      bivariate_monomial<T> temp2=multiplier*multiplier;
      multiplier=temp2;
      exponent>>=1;

    }


  //Resultado
  return result;

};


//Função que imeplementa a exponenciação modular a menos de uma relação de congruência para um monômio
template<typename T, typename U>
bivariate_monomial<T> bivariate_monomial_mod_bin_pow(bivariate_monomial<T>& m1, U exponent, U mod){

  //Restrição
  static_assert(std::is_integral<U>::value, "Expoentes devem ser inteiros");
  static_assert(std::is_integral<T>::value, "Coeficientes devem ser inteiros");

  //Variáveis locais
  bivariate_monomial<T> result(1,0,0); //Identidade na classe de monômios em duas variáveis
  bivariate_monomial<T> multiplier=m1;

  //Procedimentos
    //Loop principal sobre os bits do expoentes
    while(exponent>0){
      
      //Checando a paridade do bit menos significativo
      if(exponent&1){
        bivariate_monomial<T> temp=result*multiplier;
        result=temp;
        result.coefficient=(result.coefficient%mod);
      }

      //Atualizando variáveis para a próxima iteração
      bivariate_monomial<T> temp2=multiplier*multiplier;
      multiplier=temp2;
      multiplier.coefficient=(multiplier.coefficient%mod);
      exponent>>=1;

    }

    //Ajuste final do resultado
    result.coefficient=(result.coefficient%mod);

  //Resultado
  return result;

};


//Função que reduz os coefficientes de um monômio a menos de uma relação de congruência
template<typename T, typename U>
bivariate_monomial<T> bivariate_monomial_mod(bivariate_monomial<T>& m1, U mod){

  //Restrição
  static_assert(std::is_integral<U>::value, "Expoentes devem ser inteiros");
  static_assert(std::is_integral<T>::value, "Coeficientes devem ser inteiros");

  //Variáveis locais
  bivariate_monomial<T> result=m1;
  
  //Procedimentos
    //Ajuste do resultado
    result.coefficient=(result.coefficient%mod);

  //Resultado
  return result;

};


//Função que calcula o valor de um monômio para um par de argumentos
template<typename T, typename U>
U bivariate_monomial_valuation(bivariate_monomial<T>& m1, U x_value, U y_value){

  //Variáveis locais
  U result=1;
  U temp1=x_value, temp2=y_value;
  int64_t x_power=m1.x_valuation, y_power=m1.y_valuation;


  //Procedimentos
    //Iterando sobre os bits do expoente de x
    while(x_power>0){

      //Checando a paridade do bit do expoente em x
      if(x_power&1) result=result*temp1;

      //Atualizando variáveis para a próxima iteração
      temp1=temp1*temp1;
      x_power>>=1;
    
    }

    //Iterando sobre os bits do expoente de y
    while(y_power>0){

      //Checando a paridade do bit do expoente em x
      if(y_power&1) result=result*temp2;

      //Atualizando variáveis para a próxima iteração
      temp2=temp2*temp2;
      y_power>>=1;
    
    }

    //Cálculo do resultado final
    result=static_cast<U>(m1.coefficient)*result;


  //Resultado
  return result;

};



//Função que calcula o valor de um monômio para um par de argumentosa menos de uma relação de contruência
template<typename T, typename U>
U modular_bivariate_monomial_valuation(bivariate_monomial<T>& m1, U x_value, U y_value, U mod){

  //Variáveis locais
  U result=1;
  U temp1=x_value, temp2=y_value;
  int64_t x_power=m1.x_valuation, y_power=m1.y_valuation;


  //Procedimentos
    //Iterando sobre os bits do expoente de x
    while(x_power>0){

      //Checando a paridade do bit do expoente em x
      if(x_power&1) result=(result*temp1)%mod;

      //Atualizando variáveis para a próxima iteração
      temp1=(temp1*temp1)%mod;
      x_power>>=1;
    
    }

    //Iterando sobre os bits do expoente de y
    while(y_power>0){

      //Checando a paridade do bit do expoente em x
      if(y_power&1) result=(result*temp2)%mod;

      //Atualizando variáveis para a próxima iteração
      temp2=(temp2*temp2)%mod;
      y_power>>=1;
    
    }

    //Cálculo do resultado final
    result=(static_cast<U>(m1.coefficient)*result)%mod;


  //Resultado
  return result;

};


//************************************************************************************************************************
//FIM DO HEADER
#endif
