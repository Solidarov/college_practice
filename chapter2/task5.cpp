#include <iostream>

#include "array_lib.hpp"
using namespace std;

int main(){
    int task_choice;
    getUserChoice(task_choice, 
        {{0, "Find minimim element and his serial number at array"}, 
        {1, "Count avg arithmetic of negative elements at matrix"}, 
        {2, "Find sum of odd elements in matrix"},
        {3, "Find sum of even elements of tensor"}});

    switch (task_choice)
    {
    case 0:
        minElementBlock();
        break;
    
    case 1:
        avgNegArithmBlock();
        break;

    case 2:
        sumOddElementsBlock();
        break;

    case 3:
        sumEvenElementsBlock();
        break;

    default:
        cout << "Unknown error. Please try again" << endl;
        return 1;
    }

    return 0;
}