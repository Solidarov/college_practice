#include <iostream>

#include "array_lib.hpp"
using namespace std;


int main(){
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
        return 1;
    }
    
    printOutTensor(tnsr, 2, 3, 2);
    sumEvenElements(tnsr, d, m, n);
    return 0;
}