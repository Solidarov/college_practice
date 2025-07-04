#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <type_traits>
#include <map>
#include <random>
#include <cmath>

#include "array_lib.hpp"
using namespace std;


void minElement(int arr[], int size){
    int minValue, minSerNum;
    if (size <= 0){
        minValue = 0;
        minSerNum = -1;
        cout << "No minimum value. Array is empty" << endl;
        return;
    }
    minValue = arr[0];
    minSerNum = 1;

    for (int i = 0; i < size; i++){
        if (arr[i] < minValue){
            minValue = arr[i];
            minSerNum = i + 1;
        }
    }

    cout << "Minimum value is (" << minValue << ") at serial number (" << minSerNum << ")"<< endl;
}

void avgNegArithm(double mtx[4][3], int m, int n){
    double avg = 0, count = 0;
    for (int i = 0; i < 4 && i < m; i++){
        for (int j = 0; j < 3 && j < n; j++){
            if (mtx[i][j] < 0){
                avg += mtx[i][j];
                count++;
            }
        }
    }
    if (!(avg == 0 && count == 0)){
        avg = round((avg / count) * 100) / 100;
    }
    cout << "\nArithmetic Average of Negative number is: " << avg << endl;

}

void sumOddElements(int mtx[4][3], int m, int n){
    int oddSum = 0;
    vector<pair<int, int>> idxPairs;

    for (int i = 0; i < 4 && i < m; i++){
        for (int j = 0; j < 3 && j < n; j++){
            if (mtx[i][j] % 2 == 0){
                idxPairs.push_back({i, j});

            }else if (mtx[i][j] > 0){
                oddSum += mtx[i][j];
            }
        }
    }

    for (auto pair: idxPairs){
        mtx[pair.first][pair.second] = oddSum;
    }

    cout << "\nMatrix after operation: " << endl;
    printOutMatrix(mtx, m, n);
}

void sumEvenElements(int tnsr[2][3][2], int d, int m, int n){
    int sum = 0;
    for (int i = 0; i < 2 && i < d; i++){
        for (int j = 0; j < 3 && j < m; j++){
            for (int k = 0; k < 2 && k < n; k++){
                if (tnsr[i][j][k] % 2 == 0){
                    sum += tnsr[i][j][k];
                }
            }
        }
    }
    cout << "Sum of even elements is: " << sum << endl;
}

void minElementBlock(){
    int size, choice;
    
    getUntilNum(size, "Enter the size of array: ");
    size = abs(size);

    int arr[size];

    cout << "Generate array" << endl;
    getUserChoice(choice, {{0, "manually"}, {1, "automatic"}});

    switch (choice)
    {
    case 0:
        genManArray(arr, size);
        break;
    
    case 1:
        genAutoArray(arr, size);
        break;

    default:
        cout << "Unknown error. Please try again" << endl;
        return;
    }

    printOutArray(arr, size);
    minElement(arr, size);
}

void avgNegArithmBlock(){
    const int m = 4, n = 3;
    int choice;
    double mtx[m][n];

    cout << "Generate matrix: " << endl;
    getUserChoice(choice, {{0, "automatic"},{1, "manually"}});

    switch (choice)
    {
    case 0:
        genAutoMatrix(mtx, m, n);
        break;
    
    case 1:
        genManMatrix(mtx, m, n);
        break;
    
    default:
        cout << "Unknown error. Please try again" << endl;
        return;
    }
    
    avgNegArithm(mtx, m, n);
    printOutMatrix(mtx, m, n);
}

void sumOddElementsBlock(){
    const int m = 4, n = 3;
    int mtx[m][n];
    int choice;

    cout << "Generate matrix: " << endl;
    getUserChoice(choice, {{0, "automatic"},{1, "manually"}});

    switch (choice)
    {
    case 0:
        genAutoMatrix(mtx, m, n);
        break;
    
    case 1:
        genManMatrix(mtx, m, n);
        break;
    
    default:
        cout << "Unknown error. Please try again" << endl;
        return;
    }
    
    printOutMatrix(mtx, m, n);
    sumOddElements(mtx, m, n);
}

void sumEvenElementsBlock(){
    const int d = 2, m = 3, n = 2;
    int choice;
    int tnsr[2][3][2]= {
        {
            {1,2}, 
            {3,4}, 
            {5,6}
        },
        {
            {7,8}, 
            {9,10}, 
            {11,12}}
        };

    cout << "Generate matrix: " << endl;

    getUserChoice(choice, {{0, "automatic"},{1, "manually"}, {2, "default"}});

    switch (choice)
    {
    case 0:
        genAutoTensor(tnsr, d, m, n);
        break;
    
    case 1:
        genManTensor(tnsr, d, m, n);
        break;
    
    case 2:
        break;

    default:
        cout << "Unknown error. Please try again" << endl;
        return;
    }
    
    printOutTensor(tnsr, 2, 3, 2);
    sumEvenElements(tnsr, d, m, n);
}

void genAutoArray(int arr[], int& size){
    srand(time(0));
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 101;
    }
}

void genManArray(int arr[], int size){
    int number, i = 0;
    while (size != 0){
        cout << "\nEnter the "<< i + 1 <<"th value: ";
        cin >> number;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again" << endl;
            continue;
        }
        arr[i] = number;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        i++;
        size--;
    }
}

void genAutoMatrix(double mtx[4][3], int m, int n){
    double number;
    uniform_real_distribution<double> unif(-100, 100);
    default_random_engine re(time(0));

    for (int i = 0; i < m && i < 4; i++){
        for (int j = 0; j < n && j < 3; j++){
            number = round(unif(re) * 100) / 100;
            mtx[i][j] = number;
        }
    }
}

void genAutoMatrix(int mtx[4][3], int m, int n){
    int number;
    uniform_int_distribution<int> dist(-100, 100);
    default_random_engine re(time(0));

    for (int i = 0; i < m && i < 4; i++){
        for (int j = 0; j < n && j < 3; j++){
            number = round(dist(re) * 100) / 100;
            mtx[i][j] = number;
        }
    }
}

void genManMatrix(double mtx[4][3], int m, int n){
    double number; 
    for (int i = 0; i < m && i < 4; i++){
        cout << i + 1 << " row: ";
        for (int j = 0; j < n && j < 3; j++){
            getUntilNum(number, "Enter value: ");
            mtx[i][j] = round(number * 100) / 100;
        }
        cout << "\n";
    }
}

void genManMatrix(int mtx[4][3], int m, int n){
    int number; 
    for (int i = 0; i < m && i < 4; i++){
        cout << i + 1 << " row: ";
        for (int j = 0; j < n && j < 3; j++){
            getUntilNum(number, "Enter value: ");
            mtx[i][j] = round(number * 100) / 100;
        }
        cout << "\n";
    }
}

void genAutoTensor(int tnsr[2][3][2], int d, int m, int n){
    srand(time(0));
    for (int i = 0; i < 2 && i < d; i++){
        for (int j = 0; j < 3 && j < m; j++){
            for (int k = 0; k < 2 && k < n; k++){
                tnsr[i][j][k] = (rand() % 201) - 100;
            }
        }
    }
}

void genManTensor(int tnsr[2][3][2], int d, int m, int n){
    int number;
    for (int i = 0; i < 2 && i < d; i++){
        cout << "\t" << i + 1 << " depth:" << endl;
        for (int j = 0; j < 3 && j < m; j++){
            cout << "\t" << j + 1 << " row:";
            for (int k = 0; k < 2 && k < n; k++){
                getUntilNum(number, "Enter the value: ");
                tnsr[i][j][k] = number;
            }
            cout << endl;
        }
        cout << endl;
    }
}

void getUserChoice(int& choice, map<int, string> av_options){
    cout << "Available options:" << endl;
    for (auto pair: av_options){
        cout << "\t" << pair.first << " - " << pair.second << endl;
    }

    while (true){
        
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please, provide only numbers" << endl;
            continue;
        }
        
        if (av_options.find(choice) == av_options.end()){
            cout << "No available option for your choice" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

void printOutMatrix(double mtx[4][3], int m, int n){
    cout << "Content of the matrix:" << endl;
    for (int i = 0; i < m && i < 4; i++){
        cout << "\t";
        for (int j = 0; j < n && j < 3; j++){
            cout << mtx[i][j] << "\t\t";
        }
        cout << endl;
    } 
}

void printOutMatrix(int mtx[4][3], int m, int n){
    cout << "Content of the matrix:" << endl;
    for (int i = 0; i < m && i < 4; i++){
        cout << "\t";
        for (int j = 0; j < n && j < 3; j++){
            cout << mtx[i][j] << "\t\t";
        }
        cout << endl;
    } 
}

void printOutTensor(int tnsr[2][3][2], int d, int m, int n){
    cout << "Content of the tensor: \n" << endl;
    for (int i = 0; i < 2 && i < d; i++){
        for (int j = 0; j < 3 && j < m; j++){
            for (int k = 0; k < 2 && k < n; k++){
                cout << "\t" << tnsr[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
}