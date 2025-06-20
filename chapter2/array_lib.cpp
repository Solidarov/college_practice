#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <type_traits>
#include <map>

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

int getUntilNum(string msg){
    int dInput;
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

    return dInput;
}

void printOutArray(int arr[], int size){
    cout << "Content of the array: [ ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}