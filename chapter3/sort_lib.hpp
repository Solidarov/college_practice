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
    Сортує матрицю за спаданням
*/
void sortMatrix(int mtx[45][45], int m, int n);

/*
    Переміщає всі парні елементи на початок масиву 
    та повертає значення їхньої кількості
*/
int moveEvenToFront(int arr[], int size);

/*
    Автоматична генерація масиву в діапазоні від -100 до 100
*/
void genAutoArray(int arr[], int size);

/*
    Ручна генерація масиву
*/
void genManArray(int arr[], int size);

/*
   Автоматично генерує матрицю (цілі числа) 45*45 в діапазоні [-100; 100] 
*/
void genAutoMatrix(int mtx[45][45], int m, int n);

/*
    Користувач вручну генерує матрицю 45*45 (цілі числа)
*/
void genManMatrix(int mtx[45][45], int m, int n);


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

/*
    Виводить вміст матриці на екран (цілі числа)
*/
void printOutMatrix(int mtx[45][45], int m, int n);


#endif