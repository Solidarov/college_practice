#include <iostream>
#include <cmath>

#include "array_lib.hpp"
using namespace std;


int main(){
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
        return 1;
    }
    
    avgNegArithm(mtx, m, n);
    printOutMatrix(mtx, m, n);
    return 0;
}