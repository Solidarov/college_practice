#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <map>

#include "struct_lib.hpp"
using namespace std;

vector <struct Student> students;

void Shapka() {
    cout << 
    "-------------------------------------------------------------------------------------\n";
    cout << 
    "\\ № \\   Прізвище   \\ Іноземна \\   Вища     \\ Фізика \\ Програмування \\ Найкраща   \\\n";
    cout << 
    "\\   \\              \\    мова  \\ математика \\        \\               \\ дисципліна \\\n";
    cout <<
    "-------------------------------------------------------------------------------------\n";
}

void OutTable() {
    Shapka();
    int i = 0;
    for (Student student : students) {
        i++;
        cout << "\\ " << setw(2) << i << " \\  "
             << setw(14) << left << student.name << " \\ "
             << setw(6) << student.fLang << " \\  "
             << setw(7) << student.advMath << "   \\    "
             << setw(2) << student.physics << "   \\    "
             << setw(7) << student.programming << "   \\    ";
        cout << setw(7) << student.maxMark << "  \\\n";
    }
    cout << "-------------------------------------------------------------------------------------\n";
}


void NewStudent() {
    if (students.size() >= 100) {
        cout << "Максимальна кількість студентів досягнута!\n";
        return;
    }

    string name;
    int fLang, advMath, physics, programming;

    cout << "Прізвище: "; cin >> name;
    cout << "Бал з іноземної мови: "; cin >> fLang;
    cout << "Бал з вищої математики: "; cin >> advMath;
    cout << "Бал з фізики: "; cin >> physics;
    cout << "Бал з програмування: "; cin >> programming;

    Student s(name, fLang, advMath, physics, programming);
    students.push_back(s);
    
}

void DelRow(int n) {
    if (n < 0 || n >= students.size()) {
        cout << "Некоректний номер запису для видалення!\n";
        return;
    }
    students.erase(students.begin() + n);
    cout << "\n\tЗапис видалено!" << endl;
}


void menu() {
    int choice;
    do {
        cout << "\n1. Шапка таблиці"
             << "\n2. Додати студента"
             << "\n3. Вивід таблиці"
             << "\n4. Видалити запис"
             << "\n0. Вихід\n";
        cout << "Ваш вибір: "; cin >> choice;

        switch (choice) {
            case 1: Shapka(); break;
            case 2: NewStudent(); break;
            case 3: OutTable(); break;
            case 4: {
                int del_num;
                cout << "Введіть номер рядка для видалення: ";
                cin >> del_num;
                DelRow(del_num - 1);
                break;
            }
            case 0: cout << "Вихід...\n"; break;
            default: cout << "Невірний вибір, спробуйте ще раз.\n"; break;
        }
    } while (choice != 0);
}