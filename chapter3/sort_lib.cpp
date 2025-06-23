#include <ctime>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <random>

#include "sort_lib.hpp"

using namespace std;


void bubbleSort(int arr[], int size, bool reverse){
    int temp;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j+1] && !reverse){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }else if (arr[j] < arr[j+1] && reverse){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size, bool reverse){
    int mIdx, temp;
    for (int i = 0; i < size; i++){
        mIdx = i;
        for (int j = i; j < size; j++){
            if (arr[mIdx] > arr[j] && !reverse){
                mIdx = j;
            }else if (arr[mIdx] < arr[j] && reverse){
                mIdx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[mIdx];
        arr[mIdx] = temp;
    }
}

void insertionSort(int arr[], int size, bool reverse){
    int temp;
    for (int i = 1; i < size; i++){
        for (int j = 0; j < i + 1; j++){
            if (arr[j] >= arr[i] && !reverse){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }else if (arr[j] <= arr[i] && reverse){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void sortMatrix(int mtx[45][45], int m, int n){
    int choice;
    auto sorter = bubbleSort;
    cout << "\nWhat method use for sorting?" << endl;
    getUserChoice(choice, {{
        {0, "bubble sort"}, 
        {1, "selection sort"}, 
        {2, "insertion sort"}}});

    switch (choice)
    {
    case 0:
        sorter = bubbleSort;
        break;
    case 1:
        sorter = selectionSort;
        break;
    case 2:
        sorter = insertionSort;
        break;
    
    default:
        cout << "Unknown problem" << endl;
        return;
    }

    int size;
    for (int i = 0; i < m && i < 45; i++){
        size = moveEvenToFront(mtx[i], n);
        sorter(mtx[i], size, true);
    }
}

int moveEvenToFront(int arr[], int size){
    int* temp = new int[size];
    int index = 0, count = 0;

    for (int i = 0; i < size; i++){
        if (arr[i] % 2 == 0){
            temp[index++] = arr[i];
            count++;
        }
    }

    for (int i = 0; i < size; i++){
        if (arr[i] % 2 != 0){
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < size; i++){
        arr[i] = temp[i];
    }
    delete[] temp;

    return count;
} 

double findMin(double row[], int size) {
    double minVal = row[0];
    for (int i = 1; i < size && i < 45; ++i) {
        if (row[i] < minVal)
            minVal = row[i];
    }
    return minVal;
}

void swapRows(double a[], double b[], int size) {
    for (int i = 0; i < size && size < 45; ++i) {
        swap(a[i], b[i]);
    }
}

void sortRows(double mtx[45][45], int m, int n){
    for (int i = 0; i < m - 1 && i < 45; ++i) {
        for (int j = i + 1; j < n && j < 45; ++j) {
            if (findMin(mtx[i], n) < findMin(mtx[j], n)) {
                swapRows(mtx[i], mtx[j], n);
            }
        }
    }
}

void countNegNums(double mtx[45][45], int m, int n){
    int count = 0, rowCount[m] = {};
    for (int i = 0; i < m && i < 45; i++){
        for (int j = 0; j < n && j < 45; j++){
            if (mtx[i][j] < 0){
                count++;
            }
        }
        rowCount[i] = count;
        count = 0;
    }

    cout << "Count of negative numbers by the rows: " << endl;
    for (int i = 0; i < m && i < 45; i++){
        cout << i+1 << " row -> " << rowCount[i] << " negative numbers;" << endl;
    }
}

void genAutoArray(int arr[], int size){
    srand(time(0));

    for (int i = 0; i < size; i++){
        arr[i] = (rand() % 201) - 100;
    }
}

void genManArray(int arr[], int size){
    int number, i = 0;
    while (size != 0){

        getUntilNum(number, "Enter the value: ");
        arr[i] = number;

        i++;
        size--;
    }
}

void genAutoMatrix(int mtx[45][45], int m, int n){
    srand(time(0));

    for (int i = 0; i < m && i < 45; i++){
        for (int j = 0; j < n && j < 45; j++){
            mtx[i][j] = (rand() % 201) - 100;
        }
    }
}

void genAutoMatrix(double mtx[45][45], int m, int n){
    double number;
    uniform_real_distribution<double> unif(-100, 100);
    default_random_engine re(time(0));

    for (int i = 0; i < m && i < 45; i++){
        for (int j = 0; j < n && j < 45; j++){
            number = round(unif(re) * 100) / 100;
            mtx[i][j] = number;
        }
    }
}

void genManMatrix(int mtx[45][45], int m, int n){
    int number; 
    for (int i = 0; i < m && i < 45; i++){
        cout << i + 1 << " row: ";
        for (int j = 0; j < n && j < 45; j++){
            getUntilNum(number, "Enter value: ");
            mtx[i][j] = number;
        }
        cout << "\n";
    }
}

void genManMatrix(double mtx[45][45], int m, int n){
    double number; 
    for (int i = 0; i < m && i < 45; i++){
        cout << i + 1 << " row: ";
        for (int j = 0; j < n && j < 45; j++){
            getUntilNum(number, "Enter value: ");
            mtx[i][j] = round(number * 100) / 100;
        }
        cout << "\n";
    }
}

void getUserChoice(int& choice, map<int, string> av_options){
    cout << "Available options:" << endl;
    for (auto pair: av_options){
        cout << "\t" << pair.first << " - " << pair.second << endl;
    }

    while (true){

        getUntilNum(choice, "Enter your choice: ");
        
        if (av_options.find(choice) == av_options.end()){
            cout << "No available option for your choice" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        break;
    }
}

void getUntilNum(int& iInput, string msg){
    cout << "\n" << msg;
    cin >> iInput;

    while (!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. \n" << msg;
        cin >> iInput;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void getUntilNum(double& dInput, string msg){
    cout << "\n" << msg;
    cin >> dInput;

    while (!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. \n" << msg;
        cin >> dInput;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void printOutArray(int arr[], int size){
    cout << "Content of the array: [ ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

void printOutMatrix(int mtx[45][45], int m, int n){
    cout << "Content of the matrix:" << endl;
    for (int i = 0; i < m && i < 45; i++){
        cout << "\t";
        for (int j = 0; j < n && j < 45; j++){
            cout << mtx[i][j] << "\t\t";
        }
        cout << endl;
    } 
}

void printOutMatrix(double mtx[45][45], int m, int n){
    cout << "Content of the matrix:" << endl;
    for (int i = 0; i < m && i < 45; i++){
        cout << "\t";
        for (int j = 0; j < n && j < 45; j++){
            cout << mtx[i][j] << "\t\t";
        }
        cout << endl;
    } 
}