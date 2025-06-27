#include <ctime>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <random>
#include <algorithm>
#include <utility>

#include "sort_lib.hpp"

using namespace std;


void bubbleSort(int arr[], int size, bool reverse){
    int temp;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j+1] && !reverse){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }else if (arr[j] < arr[j+1] && reverse){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size, bool reverse){
    int mIdx, temp;
    for (int i = 0; i < size; i++){
        mIdx = i;
        for (int j = i; j < size; j++){
            if (arr[mIdx] > arr[j] && !reverse){
                mIdx = j;
            }else if (arr[mIdx] < arr[j] && reverse){
                mIdx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[mIdx];
        arr[mIdx] = temp;
    }
}

void insertionSort(int arr[], int size, bool reverse){
    int temp;
    for (int i = 1; i < size; i++){
        for (int j = 0; j < i + 1; j++){
            if (arr[j] >= arr[i] && !reverse){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }else if (arr[j] <= arr[i] && reverse){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void insertionSort(double arr[], int size, bool reverse){
    double temp;
    for (int i = 1; i < size; i++){
        for (int j = 0; j < i + 1; j++){
            if (arr[j] >= arr[i] && !reverse){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }else if (arr[j] <= arr[i] && reverse){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void mergeSort(int arr[], int size, bool reverse){
    int* temp = new int[size];

    for (int width = 1; width < size; width = 2 * width){
        for (int i = 0; i < size; i = i + 2 * width){

            int left = i;
            int mid = min(i + width, size);
            int right = min(i+2*width, size);
            int i1 = left;
            int i2 = mid;
            int j = left;

            while (i1 < mid && i2 < right){
                if ((!reverse && arr[i1] <= arr[i2]) || 
                (reverse && arr[i1] >= arr[i2])){
                    temp[j++] = arr[i1++];
                } else {
                    temp[j++] = arr[i2++];
                }
            }

            while (i1 < mid){
                temp[j++] = arr[i1++];
            }
            while (i2 < right){
                temp[j++] = arr[i2++];
            }
        }

        for (int i = 0; i < size; i++){
            arr[i] = temp[i];
        }
    }

    delete[] temp;
}

void bogoSort(int arr[], int size, bool reverse) {
    // Helper function to check if array is sorted
    auto isSorted = [reverse](int arr[], int size) -> bool {
        for (int i = 0; i < size - 1; i++) {
            if ((!reverse && arr[i] > arr[i+1]) || 
                (reverse && arr[i] < arr[i+1])) {
                return false;
            }
        }
        return true;
    };
    
    // Keep shuffling until the array is sorted
    while (!isSorted(arr, size)) {
        // Fisher-Yates shuffle
        for (int i = size - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }
    }
}

void quickSort(int arr[], int low, int high, bool reverse){
    if (low < high){
        int pivotIndex = partition(arr, low, high, reverse);
        quickSort(arr, low, pivotIndex - 1, reverse);
        quickSort(arr, pivotIndex + 1, high, reverse);
    }
}

    int partition(int arr[], int low, int high, bool reverse){
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++){
            if ((arr[j] <= pivot && !reverse) ||
            (arr[j] >= pivot && reverse)){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

void cocktailSort(int arr[], int size, bool reverse){
    bool swapped;
    do {
        swapped = false;
        
        for (int i = 0; i < size - 1; i++) {
            if ((!reverse && arr[i] > arr[i + 1]) || 
                (reverse && arr[i] < arr[i + 1])) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        
        if (!swapped) 
            break; 

        swapped = false;
        
        for (int i = size - 2; i >= 0; i--) {
            if ((!reverse && arr[i] > arr[i + 1]) || 
                (reverse && arr[i] < arr[i + 1])) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void partialSort(int arr[], int size, int k, bool reverse) {
    if (k <= 0 || k > size) {
        return; 
    }
    
    for (int i = 0; i < k; i++) {
        int extremeIndex = i;
        
        for (int j = i + 1; j < size; j++) {
            if ((!reverse && arr[j] < arr[extremeIndex]) ||
                (reverse && arr[j] > arr[extremeIndex])) {
                extremeIndex = j;
            }
        }
        
        if (extremeIndex != i) {
            swap(arr[i], arr[extremeIndex]);
        }
    }
}

void sortMatrix(int mtx[45][45], int m, int n){
    int choice;
    auto sorter = bubbleSort;
    cout << "\nWhat method use for sorting?" << endl;
    getUserChoice(choice, {{
        {0, "bubble sort"}, 
        {1, "selection sort"}, 
        {2, "insertion sort"}}});

    switch (choice)
    {
    case 0:
        sorter = bubbleSort;
        break;
    case 1:
        sorter = selectionSort;
        break;
    case 2:
        sorter = insertionSort;
        break;
    
    default:
        cout << "Unknown problem" << endl;
        return;
    }

    int size;
    for (int i = 0; i < m && i < 45; i++){
        size = moveEvenToFront(mtx[i], n);
        sorter(mtx[i], size, true);
    }
}

int moveEvenToFront(int arr[], int size){
    int* temp = new int[size];
    int index = 0, count = 0;

    for (int i = 0; i < size; i++){
        if (arr[i] % 2 == 0){
            temp[index++] = arr[i];
            count++;
        }
    }

    for (int i = 0; i < size; i++){
        if (arr[i] % 2 != 0){
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < size; i++){
        arr[i] = temp[i];
    }
    delete[] temp;

    return count;
} 

double findMin(double row[], int size) {
    double minVal = row[0];
    for (int i = 1; i < size && i < 45; ++i) {
        if (row[i] < minVal)
            minVal = row[i];
    }
    return minVal;
}

bool helpSortByCols(pair<long long, int> &a, pair<long long, int> &b){
    return a.first < b.first;
}

void sortColumnsByProduct(int mtx[45][45], int m, int n) {
    
    // Масив пар {добуток, індекс стовпця}
    pair <long long, int> prodIdxCols[45];
    
    for (int j = 0; j < n; j++) {
        prodIdxCols[j].first = 1;
        prodIdxCols[j].second = j;
        
        for (int i = 0; i < m; i++) {
            prodIdxCols[j].first *= mtx[i][j];
        }
    }

    sort(&prodIdxCols[0], &prodIdxCols[n], helpSortByCols);
    
    int temp[45][45];
    
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            temp[i][j] = mtx[i][prodIdxCols[j].second];
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mtx[i][j] = temp[i][j];
        }
    }
}


void findMinInRows(int mtx[45][45], int m, int n) {
    cout << "Minimum elements in each row:" << endl;
    
    for (int i = 0; i < m; i++) {
        int minVal = mtx[i][0];
        
        for (int j = 1; j < n; j++) {
            if (mtx[i][j] < minVal) {
                minVal = mtx[i][j];
            }
        }
        
        cout << "Row " << (i + 1) << ": " << minVal << endl;
    }
}

void processMatrix(int mtx[45][45], int m, int n) {

    sortColumnsByProduct(mtx, m, n);
    cout << "Matrix with columns sorted by product:" << endl;
    printOutMatrix(mtx, m, n);

    findMinInRows(mtx, m, n);
}

void sortCols(int mtx[45][45], int m, int n) {
    int* tempCol = new int[m];
    
    for (int j = 0; j < n; j++) {

        for (int i = 0; i < m; i++) {
            tempCol[i] = mtx[i][j];
        }
        
        insertionSort(tempCol, m, true);
        
        for (int i = 0; i < m; i++) {
            mtx[i][j] = tempCol[i];
        }
    }
    delete[] tempCol;
}

void sortCols(double mtx[45][45], int m, int n) {
    double* tempCol = new double[m];
    
    for (int j = 0; j < n; j++) {

        for (int i = 0; i < m; i++) {
            tempCol[i] = mtx[i][j];
        }
        
        insertionSort(tempCol, m, true);
        
        for (int i = 0; i < m; i++) {
            mtx[i][j] = tempCol[i];
        }
    }
    delete[] tempCol;
}

void sortArrayAdv(int arr[], int size, bool reverse){
    int choice, k;

    cout << "\n\nChoose algorithm for sort array" << endl;
    getUserChoice(choice, {
        {0, "merge sort"},
        {1, "bogo sort"},
        {2, "quick sort"},
        {3, "cocktail sort"},
        {4, "partial sort"}, });

    switch (choice)
    {
    case 0:
        mergeSort(arr, size, reverse);
        break;
    case 1:
        bogoSort(arr, size, reverse);
        break;
    
    case 2:
        quickSort(arr, 0, size-1, reverse);
        break;

    case 3:
        cocktailSort(arr, size, reverse);
        break;
    case 4:
        getUntilNum(k, "How many nums sort: ");
        partialSort(arr, size, k, reverse);
        break;
    
    default:
        cout << "Unknown error. Try again" << endl;
        return;
    }
}

void sortMatrixAdv(int mtx[45][45], int m, int n, bool reverse){
    int choice, k;

    cout << "\n\nChoose algorithm for sort matrix" << endl;
    getUserChoice(choice, {
        {0, "merge sort"},
        {1, "bogo sort"},
        {2, "quick sort"},
        {3, "cocktail sort"},
        {4, "partial sort"}, });

    switch (choice)
    {
    case 0:
        for (int i = 0; i < m && i < 45; i++){
            mergeSort(mtx[i], n, reverse);
        }
        break;

    case 1:
        for (int i = 0; i < m && i < 45; i++){
            bogoSort(mtx[i], n, reverse);
        }
        break;
    
    case 2:
        for (int i = 0; i < m && i < 45; i++){
            quickSort(mtx[i], 0, n-1, reverse);
        }
        break;

    case 3:
        for (int i = 0; i < m && i < 45; i++){
            cocktailSort(mtx[i], n, reverse);
        }
        break;

    case 4:
        getUntilNum(k, "How many nums sort: ");

        for (int i = 0; i < m && i < 45; i++){
            partialSort(mtx[i], n, k, reverse);
        }
        break;
    
    default:
        cout << "Unknown error. Try again" << endl;
        return;
    }
}

void sortTensorAdv(int tnsr[2][3][2], int d, int m, int n, bool reverse){
    int choice, k;

    cout << "\n\nChoose algorithm for sort tensor" << endl;
    getUserChoice(choice, {
        {0, "merge sort"},
        {1, "bogo sort"},
        {2, "quick sort"},
        {3, "cocktail sort"},
        {4, "partial sort"}, });

    switch (choice)
    {
    case 0:
        for (int j = 0; j < d && j < 2; j++){
            for (int i = 0; i < m && i < 3; i++){
                mergeSort(tnsr[j][i], n, reverse);
            }
        }
        
        break;

    case 1:
        for (int j = 0; j < d && j < 2; j++){
            for (int i = 0; i < m && i < 3; i++){
                bogoSort(tnsr[j][i], n, reverse);
            }
        }
        break;
    
    case 2:
        for (int j = 0; j < d && j < 2; j++){
            for (int i = 0; i < m && i < 45; i++){
                quickSort(tnsr[j][i], 0, n - 1, reverse);
            }
        }
        break;

    case 3:
        for (int j = 0; j < d && j < 2; j++){
            for (int i = 0; i < m && i < 45; i++){
                cocktailSort(tnsr[j][i], n, reverse);
            }
        }
        break;

    case 4:
        getUntilNum(k, "How many nums sort: ");

        for (int j = 0; j < d && j < 2; j++){
            for (int i = 0; i < m && i < 45; i++){
                partialSort(tnsr[j][i], n, k, reverse);
            }
        }
        break;
    
    default:
        cout << "Unknown error. Try again" << endl;
        return;
    }
}

void genAutoArray(int arr[], int size){
    srand(time(0));

    for (int i = 0; i < size; i++){
        arr[i] = (rand() % 201) - 100;
    }
}

void genManArray(int arr[], int size){
    int number, i = 0;
    while (size != 0){

        getUntilNum(number, "Enter the value: ");
        arr[i] = number;

        i++;
        size--;
    }
}

void genAutoMatrix(int mtx[45][45], int m, int n){
    srand(time(0));

    for (int i = 0; i < m && i < 45; i++){
        for (int j = 0; j < n && j < 45; j++){
            mtx[i][j] = (rand() % 201) - 100;
        }
    }
}

void genAutoMatrix(double mtx[45][45], int m, int n){
    double number;
    uniform_real_distribution<double> unif(-100, 100);
    default_random_engine re(time(0));

    for (int i = 0; i < m && i < 45; i++){
        for (int j = 0; j < n && j < 45; j++){
            number = round(unif(re) * 100) / 100;
            mtx[i][j] = number;
        }
    }
}

void genManMatrix(int mtx[45][45], int m, int n){
    int number; 
    for (int i = 0; i < m && i < 45; i++){
        cout << i + 1 << " row: ";
        for (int j = 0; j < n && j < 45; j++){
            getUntilNum(number, "Enter value: ");
            mtx[i][j] = number;
        }
        cout << "\n";
    }
}

void genManMatrix(double mtx[45][45], int m, int n){
    double number; 
    for (int i = 0; i < m && i < 45; i++){
        cout << i + 1 << " row: ";
        for (int j = 0; j < n && j < 45; j++){
            getUntilNum(number, "Enter value: ");
            mtx[i][j] = round(number * 100) / 100;
        }
        cout << "\n";
    }
}

void genAutoTensor(int tnsr[2][3][2], int d, int m, int n){
    srand(time(0));
    for (int i = 0; i < 2 && i < d; i++){
        for (int j = 0; j < 3 && j < m; j++){
            for (int k = 0; k < 2 && k < n; k++){
                tnsr[i][j][k] = (rand() % 201) - 100;
            }
        }
    }
}

void genManTensor(int tnsr[2][3][2], int d, int m, int n){
    int number;
    for (int i = 0; i < 2 && i < d; i++){
        cout << "\t" << i + 1 << " depth:" << endl;
        for (int j = 0; j < 3 && j < m; j++){
            cout << "\t" << j + 1 << " row:";
            for (int k = 0; k < 2 && k < n; k++){
                getUntilNum(number, "Enter the value: ");
                tnsr[i][j][k] = number;
            }
            cout << endl;
        }
        cout << endl;
    }
}

void getUserChoice(int& choice, map<int, string> av_options){
    cout << "Available options:" << endl;
    for (auto pair: av_options){
        cout << "\t" << pair.first << " - " << pair.second << endl;
    }

    while (true){

        getUntilNum(choice, "Enter your choice: ");
        
        if (av_options.find(choice) == av_options.end()){
            cout << "No available option for your choice" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        break;
    }
}

void getUntilNum(int& iInput, string msg){
    cout << "\n" << msg;
    cin >> iInput;

    while (!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. \n" << msg;
        cin >> iInput;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void getUntilNum(double& dInput, string msg){
    cout << "\n" << msg;
    cin >> dInput;

    while (!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. \n" << msg;
        cin >> dInput;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void printOutArray(int arr[], int size){
    cout << "Content of the array: [ ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

void printOutMatrix(int mtx[45][45], int m, int n){
    cout << "Content of the matrix:" << endl;
    for (int i = 0; i < m && i < 45; i++){
        cout << "\t";
        for (int j = 0; j < n && j < 45; j++){
            cout << mtx[i][j] << "\t\t";
        }
        cout << endl;
    } 
}

void printOutMatrix(double mtx[45][45], int m, int n){
    cout << "Content of the matrix:" << endl;
    for (int i = 0; i < m && i < 45; i++){
        cout << "\t";
        for (int j = 0; j < n && j < 45; j++){
            cout << mtx[i][j] << "\t\t";
        }
        cout << endl;
    } 
}

void printOutTensor(int tnsr[2][3][2], int d, int m, int n){
    cout << "Content of the tensor: \n" << endl;
    for (int i = 0; i < 2 && i < d; i++){
        for (int j = 0; j < 3 && j < m; j++){
            for (int k = 0; k < 2 && k < n; k++){
                cout << "\t" << tnsr[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
}
