// Нестерук Павло ІПЗ-21
// Номер в списку 14. Варіант 15


#include "chapter_one.hpp"
using namespace std;


int main(){

    double x, a, y;

    getUntilNum(&x, "Enter value x: ");
    getUntilNum(&a, "Enter value a: ");

    calcConditionalExpr(&y, x, a);

    printOutResults({{"x", x}, {"y", y}, {"a", a}});

    return 0;
}