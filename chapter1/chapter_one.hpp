#include <iostream>
#include <cmath>
#include <map>
using namespace std;

// Перевіряє правильний користувацький ввід для типу double
void getUntilNum(double* dInput, string msg){
    cout << "\n" << msg;
    cin >> *dInput;
    while (!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. \n" << msg;
        cin >> *dInput;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Перевіряє правильний користувацький ввід для типу double
void getUntilNum(int* iInput, string msg){
    cout << "\n" << msg;
    cin >> *iInput;
    while (!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. \n" << msg;
        cin >> *iInput;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Виводить результат поданих змінних
void printOutResults(map<string, double> vars){
    cout << "\nResults:" << endl;
    for (auto pair: vars){
        cout << pair.first << " = " << pair.second << endl;
    }
}

// Перевіряє правильність вибору користувача із запропонованих варіантів
void getUserChoice(int* choice, map<int, string> av_options){
    cout << "Available options:" << endl;
    for (auto pair: av_options){
        cout << "\t" << pair.first << " - " << pair.second << endl;
    }

    while (true){
        
        cout << "\nEnter your choice: ";
        cin >> *choice;
        
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please, provide only numbers" << endl;
            continue;
        }
        
        if (av_options.find(*choice) == av_options.end()){
            cout << "No available option for your choice" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }


}

// Розраховує варіант студента за формулою:
// номер варіанту = (номер_групи * номер_в_списку_групи) % (кількість _варіантів +1) + 1
void checkVariant(int studentNum, int groupNum, int varQuant){
    int result = (groupNum * studentNum) % (varQuant + 1) + 1;
    cout << "Your variant is -> " << result << endl;
}

// Обчислює лінійний вираз із 1 завдання для 20 варіанту
double calcLinearExpr(double x, double a){

    double nominator = 4 * x - a;
    double denominator = (x - 2 == 0) ? 1 : x - 2;
    double logAbs = log(abs(x + 2));
    return sqrt(nominator / denominator) - logAbs;

}

// Обчислює розгалужений вираз із 2 завдання для 15 варіанту
void calcConditionalExpr(double* y, double x, double a){
    if (x > 9){
        *y = cos(x);
    }else{
        *y = 3 * exp(a*x) + 1;
    }
}

// Обчислює розширений розгалужений вираз із 3 завдання для 15 варіанту
void calcAdvConditionalExpr(double *y, double x, double a, double b){
    if ((x >= 0) && (x < 9)){
        *y = tan(x);

    }else if (x == 9){
        *y = 3 * exp(a * x) + 1;

    }else if ((x > 9) && (x < 11)){
        *y = x*x*x - b * x + 3;

    }else{
        *y = 0;
        cout << "\nx value doesn`t complete any of the available conditions" << endl;
    }
}

// Обчислює суму сплаченого податку із 4 завдання для 15 варіанту
void taxCalc(double* salary){

    cout.precision(2);
    if (*salary > 10'000){
        *salary = *salary * 0.22;
    
    }else if (*salary > 5'000){
        *salary = *salary * 0.21;
    }

    cout << fixed;
    cout << "The tax worker need to pay: " << *salary << endl;

}