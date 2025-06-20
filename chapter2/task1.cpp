#include <iostream>
#include <cmath>

#include "array_lib.hpp"
using namespace std;


int main(){
    int size, choice;
    
    size = getUntilNum("Enter the size of array: ");
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
        cout << "Invalid input. Please, try again." << endl;
        return 1;
    }

    printOutArray(arr, size);
    
    minElement(arr, size);

    return 0;
}