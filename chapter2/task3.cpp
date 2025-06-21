// Варіант 15
// 4*3 цілий Обчислити суму додатних непарних елементів 
// і замінити парні елементи масиву на цю суму

#include <iostream>

#include "array_lib.hpp"
using namespace std;


int main(){
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
        return 1;
    }
    
    printOutMatrix(mtx, m, n);
    sumOddElements(mtx, m, n);
    return 0;
}