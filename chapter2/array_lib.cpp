#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <type_traits>
#include <map>
#include <random>

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