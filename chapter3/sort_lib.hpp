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
    Сортування масиву методом вставки (цілі числа)
*/
void insertionSort(int arr[], int size, bool reverse);

/*
    Сортування масиву методом вставки (дійсні числа)
*/
void insertionSort(double arr[], int size, bool reverse);

/*
    Сортування масиву методом злиття
*/
void mergeSort(int arr[], int size, bool reverse = false);

/*
    Сортування масиву методом випадкового сортування
*/
void bogoSort(int arr[], int size, bool reverse = false);

/*
    Сортування масиву методом швидкого сортування
*/
void quickSort(int arr[], int low, int high, bool reverse = false);
    /*
        Допоміжна функція до quickSort, що виконує розділення масиву 
        для алгоритму швидкого сортування 
    */
    int partition(int arr[], int low, int high, bool reverse);
/*
    Сортування масиву методом шейкерного сортування
*/
void cocktailSort(int arr[], int size, bool reverse = false);

/*
    Сортування масиву методом сортування частинами
*/
void partialSort(int arr[], int size, int k, bool reverse = false);

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
    Шукає найменший елемент в рядку матриці, тобто в масиві
*/
double findMin(double row[], int size);

/*
    Змінює рядки матриці місцями
*/
void swapRows(double a[], double b[], int size);

/*
    Сортує рядки матриці за спаданням мінімальних елементів
*/
void sortRows(double mtx[45][45], int m, int n);

/*
    Знаходить кількість від'ємних елементів у матриці
*/
void countNegNums(double mtx[45][45], int m, int n);

/*
    Сортує стовпці матриці (цілі числа)
*/
void sortCols(int mtx[45][45], int m, int n);

/*
    Сортує стовпці матриці (дійсні числа)
*/
void sortCols(double mtx[45][45], int m, int n);

/*
    Сортує масив швидкими методами сортування (цілі числа)
*/
void sortArrayAdv(int arr[], int size, bool reverse = false);

/*
    Сортує матрицю швидкими методами сортування (цілі числа)
*/
void sortMatrixAdv(int mtx[45][45], int m, int n, bool reverse = false);

/*
    Сортує тенсор швидкими методами сортування (цілі числа)
*/
void sortTensorAdv(int tnsr[2][3][2], int d, int m, int n, bool reverse = false);
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
    Автоматично генерує матрицю (дійсні числа) 45*45 в діапазоні [-100; 100] 
*/
void genAutoMatrix(double mtx[45][45], int m, int n);

/*
    Користувач вручну генерує матрицю 45*45 (цілі числа)
*/
void genManMatrix(int mtx[45][45], int m, int n);

/*
    Користувач вручну генерує матрицю 45*45 (дійсні числа)
*/
void genManMatrix(double mtx[45][45], int m, int n);

/*
    Автоматично генерує тензор (цілі числа) T(3*2*2) в діапазоні [-100; 100]
*/
void genAutoTensor(int tnsr[2][3][2], int d, int m, int n);

/*
    Користувач вручну генерує тензор T(3*2*2) (цілі числа)
*/
void genManTensor(int tnsr[2][3][2], int d, int m, int n);

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
    Виводить вміст матриці на екран (цілі числа)
*/
void printOutMatrix(int mtx[45][45], int m, int n);

/*
    Виводить вміст матриці на екран (дійсні числа)
*/
void printOutMatrix(double mtx[45][45], int m, int n);

/*
    Виводить вміст тензору на екран (цілі числа)
*/
void printOutTensor(int tnsr[2][3][2], int d, int m, int n);

#endif