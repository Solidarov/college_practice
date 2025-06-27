#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <cstring>
#include <algorithm>

using namespace std;

struct CUPURA
{
    string Name;
    int Nominal;
    string Year;
    float Kurs;
};

const int maxCupuraCount = 100;
CUPURA BANK[maxCupuraCount];
int cupuraCount = 0;

/*
    Друкує шапку для таблиці
*/
void Shapka() {
    cout << 
    "\n---------------------------------------------------------\n";
    cout << 
    "\\ № \\   Назва   \\ Номінал \\    Рік    \\  Курс до  \\\n";
    cout << 
    "\\   \\  валюти   \\         \\  випуску  \\   гривні  \\\n";
    cout <<
    "---------------------------------------------------------\n";
}

/*
    Виводить рядок таблиці
*/
void OutRow(CUPURA& cupura, int n){
    cout << "\\ " << setw(2) << n + 1 << " \\  "
             << setw(10) << left << cupura.Name << " \\ "
             << setw(6) << cupura.Nominal << " \\  "
             << setw(7) << cupura.Year << "   \\    ";
        cout << setw(7) << cupura.Kurs << "  \\\n";
    cout << "---------------------------------------------------------\n";
}

/*
    Виводить таблицю з масиву BANK
*/
void PrintTable(){
    Shapka();
    for (int i = 0; i < cupuraCount; i++){
        OutRow(BANK[i], i);
    }
}

/*
    Отримує інформацію про купюру від користувача
*/
void GetCupuraFrUser(CUPURA& cup){
    cout << "\nВведіть наступні дані" << endl;
    cout << "Назва валюти: "; cin >> cup.Name;
    cout << "Номінал: "; cin >> cup.Nominal;
    cout << "Рік: "; cin >> cup.Year;
    cout << "Курс: "; cin >> cup.Kurs;

}

/*
    Додає купюру до BANK
*/
void AddCupura(){
    if (cupuraCount >= maxCupuraCount){
        cout << "Немає місця. Не можна додати нову купюру" << endl;
        return;
    }

    CUPURA c;
    GetCupuraFrUser(c);
    
    BANK[cupuraCount] = c;
    
    cupuraCount++;

    cout << "\nЗапис успішно додано\n" << endl;
}

/*
    Видаляє купюру з масиву BANK
*/
void DeleteCupura(int n){
    n--;
    if (n < 0 || n >= maxCupuraCount || n >= cupuraCount){
        cout << "\nНекоректний номер для видалення. Рядка з таким номером не існує\n" << endl;
        return;
    }

    cupuraCount--;

    for (int i = n; i < cupuraCount; i++){
        BANK[i] = BANK[i + 1];
    }

    cout << "\nЗапис успішно видалено\n" << endl;

}

/*
    Допоміжна функція для сортування за іменем
    в порядку зростання
*/
bool sortByName(CUPURA& a, CUPURA& b){
    return a.Name < b.Name;
}

/*
    Сортує масив BANK за іменем
*/
void SortCupByName(){
    sort(&BANK[0], &BANK[cupuraCount], sortByName);

    cout << "\nТаблицю успішно відсортовано\n" << endl;
}

/*
    Виводить купюри за певним роком
*/
void GetCupuraByYear(string year){
    Shapka();

    for (int i = 0; i < cupuraCount; i++){
        if (BANK[i].Year == year){
            OutRow(BANK[i], i);
        }
    }

}

void menu() {
    int choice;
    do {
        cout << "\n1. Шапка таблиці"
            << "\n2. Додати купюру"
            << "\n3. Вивід таблиці"
            << "\n4. Видалити купюру"
            << "\n5. Сортувати за зростанням назви купюри"
            << "\n6. Вивести номінали певного року"
            << "\n0. Вихід\n";
        cout << "Ваш вибір: "; cin >> choice;

        switch (choice) {
            case 1: Shapka(); break;
            case 2: AddCupura(); break;
            case 3: PrintTable(); break;
            case 4: {
                int n;
                cout << "Введіть номер рядка: "; cin >> n;
                DeleteCupura(n);
                break;
            }
            case 5: {
                SortCupByName();
                PrintTable();
                break;
            }
            case 6: {
                string year;
                cout << "Введіть рік: "; cin >> year;
                GetCupuraByYear(year);
                break;
            }
            case 0: cout << "Вихід...\n"; break;
            default: cout << "Невірний вибір, спробуйте ще раз.\n"; break;
        }
    } while (choice != 0);
}

int main(){
    menu();
    return 0;
}