#include <iostream>

#include "sort_lib.hpp"

using namespace std;


int main(){
    const int size = 10;
    int arr[size];
    int reverse, choice;
    
    cout << "How to generate array?" << endl;
    getUserChoice(choice, {
        {0, "automatically"}, 
        {1, "manually"}});

    switch(choice){
        case 0:
            genAutoArray(arr, size);
            break;
        case 1:
            genManArray(arr, size);
            break;

        default:
            cout << "Unknown error. Please, try again" << endl;
            return -1;
    }
    cout << "\nGenerated array: " << endl;
    printOutArray(arr, size);

    cout << "\nChoose the sorting method" << endl;
    getUserChoice(choice, {
        {0, "bubble sort"}, 
        {1, "selection sort"}, 
        {2, "insertion sort"}});

    cout << "\nReverse sorting?" << endl;
    getUserChoice(reverse, {{0, "No"}, {1, "Yes"}});

    switch (choice)
    {
    case 0:
        bubbleSort(arr, size, reverse);
        break;
    
    case 1:
        selectionSort(arr, size, reverse);
        break;
    
    case 2:
        insertionSort(arr, size, reverse);
        break;

    default:
        cout << "Unknown error. Please, try again" << endl;
        return -1;
    }

    cout << "\nSorted array: " << endl;
    printOutArray(arr, size);

    int minIdx = reverse ? size - 1 : 0;

    cout << "Smallest elements is " << arr[minIdx] << endl;
    return 0;
}