// Нестерук Павло ІПЗ-21
// Номер в списку 14. Варіант 20

#include "chapter_one.hpp"
using namespace std;


int main(){

    checkVariant(14, 21, 24);

    double y, x, a;
    
    getUntilDouble(&x, "Enter x value: ");

    getUntilDouble(&a, "Enter a value: ");

    y = calcLinearExpr(x, y);

    printOutResults({{"x", x}, {"y", y}, {"a", a}});

    return 0;
}