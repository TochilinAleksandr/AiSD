// lr1_aisd.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<locale.h>
#include "list.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    List list = List();
    list.push_back(5);
    list.push_back(4);
    list.push_front(3);
    list.push_front(2);
    list.push_back(1);
    list.print_to_console();

    list.insert(222, 3);
    list.print_to_console();

    list.remove(3);
    list.print_to_console();

    list.pop_back();
    list.print_to_console();


    List list2;
    list2.push_front(10);
    list2.push_back(20);
    list2.print_to_console();
    list.push_front(list2);
    list.print_to_console();

    cout << "Размер списка: " 
        << list.get_size() << endl;

    list.clear();
    list.print_to_console();
}

