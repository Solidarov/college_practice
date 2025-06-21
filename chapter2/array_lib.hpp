#ifndef ARRAY_LIB
#define ARRAY_LIB
#include <map>
#include <string>

/*
    Визначає мінімальний елемент масиву та його порядковий номер
*/
void minElement(int arr[], int size);

/*
    Обчислює середнє арифметичне значення від'ємних елементів
*/
void avgNegArithm(double mtx[4][3], int m, int n);

/*
    Автоматична генерація масиву в діапазоні від 0 до 100
*/
void genAutoArray(int arr[], int& size);

/*
    Ручна генерація масиву
*/
void genManArray(int arr[], int size);

/*
    Автоматично генерує матрицю 4*3 в діапазоні [-100; 100] 
*/
void genAutoMatrix(double mtx[4][3], int m, int n);

/*
    Користувач вручну генерує матрицю 4*3
*/
void genManMatrix(double mtx[4][3], int m, int n);

/*
    Перевіряє правильність вибору користувача із запропонованих варіантів
*/
void getUserChoice(int& choice, std::map<int, std::string> av_options);

/*
    Перевіряє правильний користувацький ввід для типу int
*/
void getUntilNum(int& iInput, std::string msg);

/*
    Перевіряє правильний користувацький ввід для типу double  
*/
void getUntilNum(double& dInput, std::string msg);

/*
    Виводить вміст масиву на екран
*/
void printOutArray(int arr[], int size);

/*
    Виводить вміст матриці на екран
*/
void printOutMatrix(double mtx[4][3], int m, int n);

#endif