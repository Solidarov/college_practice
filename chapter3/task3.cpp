#include <iostream>

#include "sort_lib.hpp"
using namespace std;


int main(){
    int mtx[45][45] = {};
    const int m = 5, n = 5;

    genAutoMatrix(mtx, m, n);
    printOutMatrix(mtx, m, n);
    
    processMatrix(mtx, m, n);

    return 0;
}