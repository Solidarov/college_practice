// Нестерук Павло ІПЗ-21
// Номер в списку 14. Варіант 7

#include "chapter_one.hpp"
using namespace std;


int main(){
    checkVariant(14, 21, 8);

    double x, y, a, b;

    getUntilNum(&x, "Enter value x: ");

    getUntilNum(&a, "Enter value a: ");
    
    getUntilNum(&b, "Enter value b: ");


    calcAdvConditionalExpr(&y, x, a, b);

    printOutResults({{"x", x}, {"y", y}, {"a", a}, {"b", b}});
    return 0;
}