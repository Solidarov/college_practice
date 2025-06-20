#ifndef ARRAY_LIB
#define ARRAY_LIB
#include <map>
#include <string>

/*
    Визначає мінімальний елемент масиву та його порядковий номер
*/
void minElement(int arr[], int size);

/*
    Автоматична генерація масиву в діапазоні від 0 до 100
*/
void genAutoArray(int arr[], int& size);

/*
    Ручна генерація масиву
*/
void genManArray(int arr[], int size);

/*
    Перевіряє правильність вибору користувача із запропонованих варіантів
*/
void getUserChoice(int& choice, std::map<int, std::string> av_options);

/*
    Перевіряє правильний користувацький ввід для типу int
*/
int getUntilNum(std::string msg);

/*
    Виводить вміст масиву на екран
*/
void printOutArray(int arr[], int size);

#endif