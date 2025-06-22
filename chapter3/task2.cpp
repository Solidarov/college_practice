#include <iostream>

#include "sort_lib.hpp"
using namespace std;

int main(){
    const int m = 10, n = 5;
    int mtx[45][45] = {};
    genAutoMatrix(mtx, m, n);
    printOutMatrix(mtx, m, n);
    sortMatrix(mtx, m, n);
    printOutMatrix(mtx, m, n);
    
    return 0;
}