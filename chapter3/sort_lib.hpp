#ifndef SORT_LIB
#define SORT_LIB

#include <string>
#include <map>

/*
    Сортування масива методом вставки
*/
void bubbleSort(int arr[], int size, bool reverse);

/*
    Сортування масиву методом вибору
*/
void selectionSort(int arr[], int size, bool reverse);

/*
    Сортування масиву методом вставки
*/
void insertionSort(int arr[], int size, bool reverse);

/*
    Автоматична генерація масиву в діапазоні від -100 до 100
*/
void genAutoArray(int arr[], int size);

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
void getUntilNum(int& iInput, std::string msg);

/*
    Виводить вміст масиву на екран
*/
void printOutArray(int arr[], int size);

#endif