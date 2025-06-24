#include <iostream>

#include "sort_lib.hpp"
using namespace std;

int main(){
    const int m = 4, n = 3;
    int mtx[45][45] = {};
    genAutoMatrix(mtx, m, n);
    printOutMatrix(mtx, m, n);

    sortCols(mtx, m, n);

    printOutMatrix(mtx, m, n);
    return 0;
}