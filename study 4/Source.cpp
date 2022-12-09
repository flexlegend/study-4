#include <iostream>
#include "List.h"
#include "Matrix.h"

int main()
{
    setlocale(LC_ALL, "ru");

    List<int> list;
    list.Add(5);
    list.Add(6);
    list.Add(7);
    return 0;
}