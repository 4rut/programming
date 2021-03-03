#include <iostream>

#include "IntArray.h"

int main()
{
    int size = 30;
    IntArray arr;

    arr.create(arr, size);
    for (int i = 0; i < size; ++i)
        arr.set(arr, i, i + 1);
    arr.print(arr);

    arr.resize(arr, 50);
    arr.print(arr);

    arr.resize(arr, 10);
    arr.print(arr);

    arr.destroy(arr);
}
