#include <ctime>
#include <cstdlib>
#include <iostream>
#include <limits>

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

void printOutArray(int arr[], int size){
    cout << "Content of the array: [ ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}