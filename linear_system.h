//VAMOS CRIAR UM PROGRAMA QUE IMPLMENTA A CLASSE DE SOLUCIONADORES DE SISTEMAS LINEARES 

/*

VAMOS IMPLMENTAR O ALGORITMO DE CRAMER PARA RESOLVER SISTEMAS DE EQUAÇÕES LINEARES USANDO DETERMINANTES
PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Cramer%27s_rule

*/


//*********************************************************************************************************************************************************************
//CABEÇALHO
#ifndef CRAMER_LINEAR_SYSTEM_SOLVER_H
#define CRAMER_LINEAR_SYSTEM_SOLVER_H
#include"determinant.h"                 //Todas as dependência necessárias estão inclusas aqui
#include<iostream>

//*********************************************************************************************************************************************************************
//CLASSE
template<typename T>
class cramer_linear_system_solver{
public:
//Membros da classe
const char symbols[27]={'a', 'b', 'c', 'd' ,'e', 'f', 'g', 'h', 'i' ,'j', 'k', 'l', 'm', 'n' ,'o', 'p', 'q', 'r', 's' ,'t', 'u', 'v', 'w', 'x' ,'y', 'z'};
Matrix<T> left_coefficients_matrix;//Matriz de coeficientes das equações lineares
Matrix<T> right_coefficients_matrix;//Matriz de valores das equações
Matrix<T> solution_matrix;//Matriz de soluções
int64_t dimension; //Número de equações e variáveis independentes
T main_determinant;//Variável que determina se um sistema é resolúvel por meio do algoritmo de Cramer

//Construtor e destruidores
cramer_linear_system_solver(){ };
virtual ~cramer_linear_system_solver(){ };

//Métodos da classe
void setup();//Função que recebe input do usuário e ajusta as matrizes usadas no cálculo
void set_status();//Função que determina se um sistema é resolúvel ou não
void print_linear_system();//Função printa o sistema de equações lineares na tela
void step_solution(int64_t);//Função que calcula o valor de uma váriavel
void solve();//Função que resolve o sistema de equações lineares
void print_solution();//Função printa a solução do sistema de equações lineares na tela
                                 };

//*********************************************************************************************************************************************************************
//MÉTODOS DA CLASSE

//Função que recebe input do usuário e ajusta as matrizes usadas no cálculo
template<typename T>
void cramer_linear_system_solver<T>::setup(){
//Recebendo input do usuário
std::cout<<"Usuário digite quantas equações e variáveis desconhecidas há no seu sistema linear: ";
std::cin>>dimension;

//Redimensionando as matrizes
left_coefficients_matrix.reshape(dimension, dimension);
right_coefficients_matrix.reshape(dimension, 1);
solution_matrix.reshape(dimension, 1);

//Definindo entradas da matriz
std::cout<<"\nCoeficientes das equações lineares:\n";
left_coefficients_matrix.manual_setup();
std::cout<<"\nValores númericos equações lineares:\n";
right_coefficients_matrix.manual_setup();
                                            };

//Função que determina se um sistema é resolúvel ou não por meio do algoritmo de Cramer
template<typename T>
void cramer_linear_system_solver<T>::set_status(){
//Calculando o determinante das matrizes de coeficiente das equações lineares
main_determinant=determinant(left_coefficients_matrix);

//Restrição
if(main_determinant==0)
std::cout<<"O sistema de equações não admite soluções ou possui infinitas soluções!\n";
                                                 };

//Função printa o sistema de equações lineares na tela
template<typename T>
void cramer_linear_system_solver<T>::print_linear_system(){
//Variáveis locais 
int64_t i, j;

//Printando o sistema de equações lineares na tela
std::cout<<"\nSistemas de equações a ser resolvido:\n";
for(i=0; i<dimension; ++i){
for(j=0; j<dimension; ++j){
if(j==0)
std::cout<<left_coefficients_matrix.matrix[i][0]<<symbols[0];
else{
if(left_coefficients_matrix.matrix[i][j]>=0)
std::cout<<"+"<<left_coefficients_matrix.matrix[i][j]<<symbols[j];
else
std::cout<<left_coefficients_matrix.matrix[i][j]<<symbols[j];
    };
                          };
std::cout<<"="<<right_coefficients_matrix.matrix[i][0]<<'\n';
                          };
                                                          };

//Função que calcula o valor de uma váriavel
template<typename T>
void cramer_linear_system_solver<T>::step_solution(int64_t k){
//Variáveis locais 
Matrix<T> variable_matrix;
T variable_determinant;
int64_t  i, j;

//Procedimentos 
//Ajuste da matriz auxiliar usada no cálculo de função de uma variável
variable_matrix.reshape(dimension, dimension);
for(i=0; i<dimension; ++i){
for(j=0; j<dimension; ++j){
if(j==k)
variable_matrix.matrix[i][j]=right_coefficients_matrix.matrix[i][0];
else
variable_matrix.matrix[i][j]=left_coefficients_matrix.matrix[i][j];
                          };
                          };

//Calculando uma solução da equação em questão
variable_determinant=determinant(variable_matrix);
solution_matrix.matrix[k][0]=variable_determinant/main_determinant;
                                                             };

//Função que resolve o sistema de equações lineares
template<typename T>
void cramer_linear_system_solver<T>::solve(){
//Variáveis locais
int64_t i;

//Procedimento
for(i=0; i<dimension; ++i)
step_solution(i);
                                            };

//Função printa a solução do sistema de equações lineares na tela
template<typename T>
void cramer_linear_system_solver<T>::print_solution(){
//Variáveis locais
int64_t i;

//Procedimentos
//Printando a solução do sistema linear na tela
for(i=0; i<dimension; ++i)
std::cout<<symbols[i]<<" = "<<solution_matrix.matrix[i][0]<<'\n';
                                                     };

//*********************************************************************************************************************************************************************
//FIM DO HEADER
#endif
