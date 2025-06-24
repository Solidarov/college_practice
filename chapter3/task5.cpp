#include <iostream>

#include "sort_lib.hpp"
using namespace std;

int main(){
    const int size = 6, m = 6, n = 6, d = 2; 
    int arr[size] = {};
    int mtx[45][45] = {};
    int tnsr[2][3][2] = {};
    int reverse;

    cout << "Reverse sorting?" << endl;
    getUserChoice(reverse, {{0, "No"}, {1, "Yes"}});

    genAutoArray(arr, size);
    printOutArray(arr, size);

    genAutoMatrix(mtx, m, n);
    printOutMatrix(mtx, m, n);

    genAutoTensor(tnsr, d, m, n);
    printOutTensor(tnsr, d, m, n);

    sortArrayAdv(arr, size, reverse);
    sortMatrixAdv(mtx, m, n, reverse);
    sortTensorAdv(tnsr, d, m, n, reverse);

    cout << "\n\nArray, Matrix and Tensor after sorting" << endl;
    printOutArray(arr, size);
    printOutMatrix(mtx, m, n);
    printOutTensor(tnsr, d, m, n);

    return 0;
}