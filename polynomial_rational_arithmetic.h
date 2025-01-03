//VAMOS CRIAR UM PROGRAMA PARA IMPLEMENTAR ARITMÉTICA COM POLINÔMIOS CUJOS COEFICIENTES SEJAM FRAÇÕES (RACIONAIS)

/*
ROTINA ÚTIL COMO SUBROTINAS PARA ALGORITMOS MAIS SOFISTICADOS COM
POLINÔMIOS CUJOS COEFICIENTES SEJAM INTEIROS.

*/


//**********************************************************************************************
//CABEÇALHO
#ifndef POLYNOMIAL_RATIONAL_ARITHMETIC_H
#define POLYNOMIAL_RATIONAL_ARITHMETIC_H
#include"polynomials.h"
#include"rational_number_class.h"

//**********************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<rational_number<T>> generate_rational_polynomial(polynomial<T>&);

template<typename T>
polynomial<T> generate_number_polynomial(polynomial<rational_number<T>>&);

template<typename T>
void print_rational_polynomial(polynomial<rational_number<T>>&, bool);

template<typename T>
void adjust_degree_rational_polynomial(polynomial<rational_number<T>>&);

template<typename T>
polynomial<rational_number<T>> rational_polynomial_add(polynomial<rational_number<T>>&, polynomial<rational_number<T>>&);

template<typename T>
polynomial<rational_number<T>> rational_polynomial_sub(polynomial<rational_number<T>>&, polynomial<rational_number<T>>&);

template<typename T>
polynomial<rational_number<T>> rational_polynomial_mul(polynomial<rational_number<T>>&, polynomial<rational_number<T>>&);

template<typename T>
polynomial<rational_number<T>> rational_polynomial_div(polynomial<rational_number<T>>&, polynomial<rational_number<T>>&);



//**********************************************************************************************
//FUNÇÕES
//Função que converte um polinômio com entradas númericas em um polinômio de coeficientes racionais
template<typename T>
polynomial<rational_number<T>> generate_rational_polynomial(polynomial<T>& p1){

  //Variáveis locais
  polynomial<rational_number<T>> result;


  //Procedimentos
    //Ajuste do grau e do array de coeficientes do polinômios
    result.degree=p1.degree;
    result.polynomial_powers=p1.polynomial_powers;

    //Ajuste dos coeficientes dos polinômios
    for(auto c:p1.polynomial_coefficients){
      rational_number<T> c1=to_rational<T, T>(c);
      result.polynomial_coefficients.push_back(c1);

    }

  //Resultado
  return result;

};


//Função que converte um polinômio cujos coeficientes são frações em polinômios cujos coeficientes são números
template<typename T>
polynomial<T> generate_number_polynomial(polynomial<rational_number<T>>& p1){

  //Variáveis locais
  polynomial<T> result;


  //Procedimentos
    //Ajuste do grau e do array de coeficientes do polinômios
    result.degree=p1.degree;
    result.polynomial_powers=p1.polynomial_powers;

    //Ajuste dos coeficientes dos polinômios
    for(auto c:p1.polynomial_coefficients){
      rational_number<T> c1=to_number<T, T>(c);
      result.polynomial_coefficients.push_back(c1);

    }

  //Resultado
  return result;

};


//Função que printa um polynômio com coeficierntes racionais (frações)
template<typename T>
void print_rational_polynomial(polynomial<rational_number<T>>& p1, bool new_line){

  // Variáveis locais
  std::string polynomial_string = "";
  int64_t i;

  // Procedimentos
   //Caso base: zero
   if((p1.polynomial_coefficients[0].numerator==0 && p1.degree==0) || p1.polynomial_coefficients.size()==0){
     polynomial_string = " ";
     goto printing;    
   }
    
    
  // 1º coeficiente
  if ((p1.polynomial_coefficients[0]).numerator != 0) {
    polynomial_string += (p1.polynomial_coefficients[0]).algebraic();
    polynomial_string += "x^";
    polynomial_string += std::to_string(p1.polynomial_powers[0]);
  };

  // Demais coeficientes
  if (p1.degree >= 0) {
    for (i = 1; i <= p1.degree; ++i) {
      if ((p1.polynomial_coefficients[i]).numerator == 0) continue;
      polynomial_string += "+(";
      polynomial_string += (p1.polynomial_coefficients[i]).algebraic();
      polynomial_string += ")";

      if (p1.polynomial_powers[i] > 0) {
        polynomial_string += "x^";
        polynomial_string += std::to_string(p1.polynomial_powers[i]);
      } else
        continue;
    };
  };

  // Resultado
  printing:
  std::cout<<polynomial_string;
  if(new_line) std::cout<<'\n';

};


//Função que ajusta o grau de um polinômio
template<typename T>
void adjust_degree_rational_polynomial(polynomial<rational_number<T>>& p1){

  //Variáveis locais
  std::vector<rational_number<T>> new_coefficients;
  rational_number<T> zero(0,1);

  //Procedimentos
    //Loop principal: eleminando os termos 0 dos monômios de maior potência
    new_coefficients.resize(0);
    for(auto c:p1.polynomial_coefficients){
      if(c.numerator==0 && new_coefficients.size()==0) continue;
      else new_coefficients.push_back(c);

    }

    //Ajuste do grau do polinômio

    if(p1.polynomial_coefficients.size()==0){
      p1.degree=0;
      p1.polynomial_coefficients.push_back(zero);
      p1.polynomial_powers.push_back(0);
    }

    p1.polynomial_coefficients=new_coefficients;
    p1.degree = p1.polynomial_coefficients.size()-1;
    p1.polynomial_powers.resize(0);
    for (int64_t i = p1.degree; i >= 0; --i) p1.polynomial_powers.push_back(i);



};


      /////Operações aritméticas

//Adição
template<typename T>
polynomial<rational_number<T>> rational_polynomial_add(polynomial<rational_number<T>>& p1, polynomial<rational_number<T>>& p2){

  // Variáveis locais
  polynomial<rational_number<T>> result;
  int64_t difference, temp, i = 0;

  // Procedimento
  // Definindo o grau do polinômio a ser obtido como resultado
  if (p1.degree > p2.degree) {
    result.degree = p1.degree;
    difference = p1.degree - p2.degree;
  } else {
    result.degree = p2.degree;
    difference = p2.degree - p1.degree;
  };

  // Definindo os coeficientes do polinômio resultante
  result.polynomial_coefficients.resize(0);  // Ajuste de variáveis
  temp = difference;                         // Ajuste de variáveis

  if (result.degree == p1.degree) {
    while (result.polynomial_coefficients.size() < (result.degree + 1)) {
      if (difference > 0) {
        difference--;
        result.polynomial_coefficients.push_back(p1.polynomial_coefficients[i]);
        ++i;
      };

      if (difference <= 0) {
        rational_number<T> t1=p1.polynomial_coefficients[i] + p2.polynomial_coefficients[i - temp];
        result.polynomial_coefficients.push_back(t1);
        ++i;
      };
    };
  };

  if (result.degree == p2.degree) {
    while (result.polynomial_coefficients.size() < (result.degree + 1)) {
      if (difference > 0) {
        difference--;
        result.polynomial_coefficients.push_back(p2.polynomial_coefficients[i]);
        ++i;
      };

      if (difference <= 0) {
        rational_number<T> t2=p2.polynomial_coefficients[i] + p1.polynomial_coefficients[i - temp];
        result.polynomial_coefficients.push_back(t2);
        ++i;
      };
    };
  };

  // Ajustando o array de potências do polinômio resultado
  result.polynomial_powers.resize(0);
  if (result.degree == p1.degree) {
    for (auto x : p1.polynomial_powers) result.polynomial_powers.push_back(x);
  };
  if (result.degree == p2.degree) {
    for (auto y : p2.polynomial_powers) result.polynomial_powers.push_back(y);
  };

  //Ajuste final
  if((result.polynomial_coefficients[0]).numerator==0 && result.degree>0)
    adjust_degree_rational_polynomial(result);

  // Resultado
  return result;

};


//Subtração
template<typename T>
polynomial<rational_number<T>> rational_polynomial_sub(polynomial<rational_number<T>>& p1, polynomial<rational_number<T>>& p2){

  // Variáveis locais
  polynomial<rational_number<T>> result;
  int64_t difference, temp, i = 0;

  // Procedimento
  // Definindo o grau do polinômio a ser obtido como resultado
  if (p1.degree > p2.degree) {
    result.degree = p1.degree;
    difference = p1.degree - p2.degree;
  } else {
    result.degree = p2.degree;
    difference = p2.degree - p1.degree;
  };

  // Definindo os coeficientes do polinômio resultante
  result.polynomial_coefficients.resize(0);  // Ajuste de variáveis
  temp = difference;                         // Ajuste de variáveis

  if (result.degree == p1.degree) {
    while (result.polynomial_coefficients.size() < (result.degree + 1)) {
      if (difference > 0) {
        difference--;
        result.polynomial_coefficients.push_back(p1.polynomial_coefficients[i]);
        ++i;
      };

      if (difference <= 0) {
        rational_number<T> t1=p1.polynomial_coefficients[i] - p2.polynomial_coefficients[i - temp];
        result.polynomial_coefficients.push_back(t1);
        ++i;
      };
    };
  };

  if (result.degree == p2.degree) {
    while (result.polynomial_coefficients.size() < (result.degree + 1)) {
      if (difference > 0) {
        difference--;
        rational_number<T> t2=p2.polynomial_coefficients[i]; t2.numerator*=(-1);
        result.polynomial_coefficients.push_back(t2);
        ++i;
      };

      if (difference <= 0) {
        rational_number<T> t3=p1.polynomial_coefficients[i - temp]-p2.polynomial_coefficients[i];
        result.polynomial_coefficients.push_back(t3) ;
        ++i;
      };
    };
  };

  // Ajustando o array de potências do polinômio resultado
  result.polynomial_powers.resize(0);
  if (result.degree == p1.degree) {
    for (auto x : p1.polynomial_powers) result.polynomial_powers.push_back(x);
  };
  if (result.degree == p2.degree) {
    for (auto y : p2.polynomial_powers) result.polynomial_powers.push_back(y);
  };

  //Ajuste final
  if((result.polynomial_coefficients[0]).numerator==0 && result.degree>0)
    adjust_degree_rational_polynomial(result);

  // Resultado
  return result;

};


//Multiplicação
template<typename T>
polynomial<rational_number<T>> rational_polynomial_mul(polynomial<rational_number<T>>& p1, polynomial<rational_number<T>>& p2){

  // Variáveis locais
  polynomial<rational_number<T>> result;
  rational_number<T> zero(0,1);
  rational_number<T> calculated_coefficient;
  int64_t i, j, k;

  // Procedimentos
  // Ajuste do grau do polinômio resultante
  result.degree = p1.degree + p2.degree;

  // Ajuste do array de potências
  result.polynomial_powers.resize(0);
  for (i = result.degree; i >= 0; --i) result.polynomial_powers.push_back(i);

  // Ajuste do array de coeficientes
  result.polynomial_coefficients.resize(0);

  // Adicionando o primeiro coeficiente
  rational_number<T> t0=p1.polynomial_coefficients[0] *p2.polynomial_coefficients[0];
  result.polynomial_coefficients.push_back(t0);
  k = 1;  // Ajuste de variáveis

  // Ajustando os demais coeficientes
  while (k < result.degree) {
    calculated_coefficient = zero;
    for (i = 0; i < p1.polynomial_coefficients.size(); ++i) {
      for (j = 0; j < p2.polynomial_coefficients.size(); ++j) {
        if ((i + j) == k){
          rational_number<T> t1 = (p1.polynomial_coefficients[i] * p2.polynomial_coefficients[j]);
          calculated_coefficient = calculated_coefficient + t1;
              
        }
      };
    };

    result.polynomial_coefficients.push_back(calculated_coefficient);
    k++;
  };

  // Adicionando o último coeficiente
  rational_number<T> t2=p1.polynomial_coefficients[(p1.polynomial_coefficients.size() - 1)]*p2.polynomial_coefficients[(p2.polynomial_coefficients.size() - 1)];
  result.polynomial_coefficients.push_back(t2);

  // Resultado
  return result;

};


//Divisão
template<typename T>
polynomial<rational_number<T>> rational_polynomial_div(polynomial<rational_number<T>>& p1, polynomial<rational_number<T>>& p2){

  // Restrição
  assert(p1.degree >= p2.degree);

  // Variáveis locais
  std::vector<rational_number<T>> operand_vector = p1.polynomial_coefficients;
  rational_number<T> ratio;
  rational_number<T> zero(0,1);
  polynomial<rational_number<T>> result;
  int64_t i, k = 0;

  // Procedimentos
  // Caso base: polinômios de mesmo grau
  if (p1.degree == p2.degree) {
    result.degree = 0;
    result.polynomial_powers = {0};
    ratio=p1.polynomial_coefficients[0]/p2.polynomial_coefficients[0];
    result.polynomial_coefficients.push_back(ratio);
    return result;
  };

  // Ajuste do grau do polinômio resultante
  result.degree = p1.degree - p2.degree;

  // Ajuste do array de potências
  result.polynomial_powers.resize(0);
  for (i = result.degree; i >= 0; --i) result.polynomial_powers.push_back(i);

  // Ajuste do array de coeficientes
  result.polynomial_coefficients.resize(0);

  while (result.polynomial_coefficients.size() < (result.degree + 1)) {
    ratio = operand_vector[k] / p2.polynomial_coefficients[0];
    result.polynomial_coefficients.push_back(ratio);

    for (i = k; i < (k + p2.polynomial_coefficients.size()); ++i){
      rational_number<T> t=(ratio * p2.polynomial_coefficients[i - k]);
      operand_vector[i] = operand_vector[i] - t;
      if(i==k) operand_vector[i]=zero;
    }

    // Atualizando variável para a próxima iteração
    ++k;
  };

  // Resultado
  return result;
};


//**********************************************************************************************
//FIM DO HEADER 
#endif
