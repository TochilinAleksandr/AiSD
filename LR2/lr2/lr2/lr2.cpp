#include <iostream>
#include "sortings.h"

int main()
{
    setlocale(LC_ALL, "rus");
    int numbers[10]{ 15, 43, 21, 77, 64, 55, 33, -100, -121, 555 };
    QuickSort(numbers, 0, 9);
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    std::cout << BinarySearch(numbers, 10, 33) << std::endl;
    std::cout << BinarySearch(numbers, 10, -33) << std::endl;
    char chars[7]{ 'f', 'a', 'q', 't', 'f', 'l', 'n' };
    CountingSort(chars, 7);
    for (size_t i = 0; i < 7; i++)
    {
        std::cout << chars[i] << " ";
    }
    std::cout << std::endl;
    measureQuickSort();
    measureBubbleSort();
}
