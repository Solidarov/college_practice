// Нестерук Павло ІПЗ-21
// Номер в списку 14

#include "chapter_one.hpp"
using namespace std;


int main(){
    double x, y, a;
    int choice;
    string msg;

    getUserChoice(&choice, {{0, "linear function"}, 
                            {1, "function with conditions"}});

    switch (choice){
        case 0:
            msg = "\n\nLinear Function";
            
            getUntilDouble(&x, "Enter x value: ");
            getUntilDouble(&a, "Enter a value: ");
            y = calcLinearExpr(x, y);
            break;
        
        case 1:
            msg = "\n\nFunction With Conditions";

            getUntilDouble(&x, "Enter x value: ");
            getUntilDouble(&a, "Enter a value: ");
            calcConditionalExpr(&y, x, a);
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            return 0;
    }

    cout << msg;
    printOutResults({{"x", x}, {"y", y}, {"a", a}});
    
    return 0;
}