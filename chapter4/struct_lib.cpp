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

void OutRow(Student& student, int n){
    Shapka();
    cout << "\\ " << setw(2) << n + 1 << " \\  "
             << setw(14) << left << student.name << " \\ "
             << setw(6) << student.fLang << " \\  "
             << setw(7) << student.advMath << "   \\    "
             << setw(2) << student.physics << "   \\    "
             << setw(7) << student.programming << "   \\    ";
        cout << setw(7) << student.maxMark << "  \\\n";
    cout << "-------------------------------------------------------------------------------------\n";
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

    cout << "\nСтудента успішно додано\n" << endl;
    
}

void DelRow(int n) {
    if (n < 0 || n >= students.size()) {
        cout << "Некоректний номер запису для видалення!\n";
        return;
    }
    students.erase(students.begin() + n);
    cout << "\n\tЗапис видалено!" << endl;
}

string GetName(){
    string name;

    cout << "Введіть прізвище студента: ";
    cin >> name;
    
    return name;
}

void SearchStudent(string name){
    int foundIndex = -1;
    for (int i = 0; i < students.size(); i++){
        if (students[i].name == name){
            foundIndex = i;
            break;
        }
    }
    if (foundIndex == -1){
        cout << "Студента з іменем " << name << " не знайдено." << endl;
        return;
    }
    OutRow(students[foundIndex], foundIndex);
}

void menu() {
    int choice;
    do {
        cout << "\n1. Шапка таблиці"
             << "\n2. Додати студента"
             << "\n3. Шукати студента"
             << "\n4. Вивід таблиці"
             << "\n5. Видалити запис"
             << "\n0. Вихід\n";
        cout << "Ваш вибір: "; cin >> choice;

        switch (choice) {
            case 1: Shapka(); break;
            case 2: NewStudent(); break;
            case 3: {
                string studName;
                studName = GetName();
                SearchStudent(studName);
                break;
            }
            case 4: OutTable(); break;
            case 5: {
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