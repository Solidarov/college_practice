// Нестерук Павло ІПЗ-21
// Номер в списку 14

#include "chapter_one.hpp"
using namespace std;

int main(){
    double x, y, a;
    string msg;
    int choice, times, i = 0;
    getUserChoice(&choice, {{0, "linear function"},
                            {1, "conditional function"},
                            {2, "advanced conditional function"}});

    
    getUntilNum(&times, "Times to repeat function: ");
    times = abs(times);

    switch (choice)
    {
    case 0:
    
    for (i = 0; i < times; i++){
            cout << "\nLinear Function " << i + 1 << endl;

            getUntilNum(&x, "Enter x value: ");
            getUntilNum(&a, "Enter a value: ");
            y = calcLinearExpr(x, y);
            
            printOutResults({{"x", x}, {"y", y}, {"a", a}});
        }
        break;
    
    case 1:
        while (times > 0){
            cout << "\nConditional Function " << i + 1 << endl;

            getUntilNum(&x, "Enter x value: ");
            getUntilNum(&a, "Enter a value: ");
            calcConditionalExpr(&y, x, a);

            printOutResults({{"x", x}, {"y", y}, {"a", a}});
            times--;
        }
        break;
    
    case 2:
        double b;
        do{
            cout << "\nAdvanced Conditional Function " << i + 1 << endl;
            
            getUntilNum(&x, "Enter value x: ");
            getUntilNum(&a, "Enter value a: ");
            getUntilNum(&b, "Enter value b: ");
            calcAdvConditionalExpr(&y, x, a, b);
            
            printOutResults({{"x", x}, {"y", y}, {"a", a}, {"b", b}});
            
            times--;
        }while(times > 0);
        break;

    default:
        cout << "Error occur. Please, try again" << endl;
        break;
    }
    return 0;   
}