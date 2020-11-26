#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include <ctime>
#include "sortings.h"

//return index of value in sorted array
int BinarySearch(int* array, size_t size, int value) {
    if (size == 0) {
        std::cout << "Array length = 0" << std::endl;
        return -1;
    }

    int first = 0, last = size, middle = 0;
    while (first <= last) {
        middle = (first + last) / 2;
        if (value == array[middle]) {
            return middle;
        }
        else if (value > array[middle]) {
            first = middle + 1;
        }
        else {
            last = middle - 1;
        }
    }
    return -1;
}

void QuickSort(int* array, int left, int right) {
    int leftNumber = left, rightNumber = right;             // right and left border of array
    int pivot = array[(leftNumber + rightNumber) / 2];      // base element
    int temp = 0;
    while (leftNumber <= rightNumber) {                     // while borders not equal
        while (array[leftNumber] < pivot)
            leftNumber++;                                   // change the left border while left border
        while (array[rightNumber] > pivot)                  // is less then pivot
            rightNumber--;                                  // change the right border while right border 
        if (leftNumber <= rightNumber) {                    // is bigger then pivot
            temp = array[leftNumber];
            array[leftNumber] = array[rightNumber];         // change the left and the right element
            array[rightNumber] = temp;
            leftNumber++;
            rightNumber--;
        }
    }
    if (left < rightNumber) {
        QuickSort(array, left, rightNumber);
    }
    if (leftNumber < right) {
        QuickSort(array, leftNumber, right);
    }
}

void measureQuickSort() {
    std::cout << "Quick sort testing" << std::endl;
    int array_10[10], array_100[100], array_1000[1000], array_10000[10000], array_100000[100000];
    double array_10_time[10], array_100_time[10], array_1000_time[10], array_10000_time[10], array_100000_time[10];
    clock_t start;
    clock_t end;

    srand(time(0));
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 10; j++) {
            array_10[j] = rand() % 2000 - 1000;
        }
        start = clock();
        QuickSort(array_10, 0, 10 - 1);
        end = clock();
        array_10_time[i] = (double)(end - start) / CLOCKS_PER_SEC;
    }
    std::cout << "Array length: 10 | " << "Mean time: " << meanArray(array_10_time, 10) << " | ";
    for (size_t i = 0; i < 10; i++) {
        std::cout << array_10_time[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 100; j++) {
            array_100[j] = rand() % 2000 - 1000;
        }
        start = clock();
        QuickSort(array_100, 0, 100 - 1);
        end = clock();
        array_100_time[i] = (double)(end - start) / CLOCKS_PER_SEC;
    }
    std::cout << "Array length: 100 | " <<  "Mean time: " << meanArray(array_100_time, 10) << " | ";
    for (size_t i = 0; i < 10; i++) {
        std::cout << array_100_time[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 1000; j++) {
            array_1000[j] = rand() % 2000 - 1000;
        }
        start = clock();
        QuickSort(array_1000, 0, 1000 - 1);
        end = clock();
        array_1000_time[i] = (double)(end - start) / CLOCKS_PER_SEC;
    }
    std::cout << "Array length: 1000 | " << "Mean time: " << meanArray(array_1000_time, 10) << " | ";
    for (size_t i = 0; i < 10; i++) {
        std::cout << array_1000_time[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 10000; j++) {
            array_10000[j] = rand() % 2000 - 1000;
        }
        start = clock();
        QuickSort(array_10000, 0, 10000 - 1);
        end = clock();
        array_10000_time[i] = (double)(end - start) / CLOCKS_PER_SEC;
    }
    std::cout << "Array length: 10000 | " <<  "Mean time: " << meanArray(array_10000_time, 10) << " | ";
    for (size_t i = 0; i < 10; i++) {
        std::cout << array_10000_time[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 100000; j++) {
            array_100000[j] = rand() % 2000 - 1000;
        }
        start = clock();
        QuickSort(array_100000, 0, 100000 - 1);
        end = clock();
        array_100000_time[i] = (double)(end - start) / CLOCKS_PER_SEC;
    }
    std::cout << "Array length: 100000 | " <<  "Mean time: " << meanArray(array_100000_time, 10) << " | ";
    for (size_t i = 0; i < 10; i++) {
        std::cout << array_100000_time[i] << " ";
    }
    std::cout << std::endl;
}

void BubbleSort(int* array, size_t size) {
    if (size == 0) {
        std::cout << "Array length = 0" << std::endl;
        return;
    }
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {                  //swap elements
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

void measureBubbleSort() {
    std::cout << "Bubble sort testing" << std::endl;
    int array_10[10], array_100[100], array_1000[1000], array_10000[10000], array_100000[100000];
    double array_10_time[10], array_100_time[10], array_1000_time[10], array_10000_time[10], array_100000_time[10];
    clock_t start;
    clock_t end;

    srand(time(0));
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 10; j++) {
            array_10[j] = rand() % 2000 - 1000;
        }
        start = clock();
        BubbleSort(array_10, 10);
        end = clock();
        array_10_time[i] = (double)(end - start) / CLOCKS_PER_SEC;
    }
    std::cout << "Array length: 10 | " << "Mean time: " << meanArray(array_10_time, 10) << " | ";
    for (size_t i = 0; i < 10; i++) {
        std::cout << array_10_time[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 100; j++) {
            array_100[j] = rand() % 2000 - 1000;
        }
        start = clock();
        BubbleSort(array_100, 100);
        end = clock();
        array_100_time[i] = (double)(end - start) / CLOCKS_PER_SEC;
    }
    std::cout << "Array length: 100 | " << "Mean time: " << meanArray(array_100_time, 10) << " | ";
    for (size_t i = 0; i < 10; i++) {
        std::cout << array_100_time[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 1000; j++) {
            array_1000[j] = rand() % 2000 - 1000;
        }
        start = clock();
        BubbleSort(array_1000, 1000);
        end = clock();
        array_1000_time[i] = (double)(end - start) / CLOCKS_PER_SEC;
    }
    std::cout << "Array length: 1000 | " << "Mean time: " << meanArray(array_1000_time, 10) << " | ";
    for (size_t i = 0; i < 10; i++) {
        std::cout << array_1000_time[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 10000; j++) {
            array_10000[j] = rand() % 2000 - 1000;
        }
        start = clock();
        BubbleSort(array_10000, 10000);
        end = clock();
        array_10000_time[i] = (double)(end - start) / CLOCKS_PER_SEC;
    }
    std::cout << "Array length: 10000 | " << "Mean time: " << meanArray(array_10000_time, 10) << " | ";
    for (size_t i = 0; i < 10; i++) {
        std::cout << array_10000_time[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 100000; j++) {
            array_100000[j] = rand() % 2000 - 1000;
        }
        start = clock();
        BubbleSort(array_100000, 100000);
        end = clock();
        array_100000_time[i] = (double)(end - start) / CLOCKS_PER_SEC;
    }
    std::cout << "Array length: 100000 | " << "Mean time: " << meanArray(array_100000_time, 10) << " | ";
    for (size_t i = 0; i < 10; i++) {
        std::cout << array_100000_time[i] << " ";
    }
    std::cout << std::endl;
}

void BogoSort(int* array, size_t size) {
    if (size == 0) {
        std::cout << "Array length = 0" << std::endl;
        return;
    }

    while (!isSorted(array, size)) {
        shakeArray(array, size);
    }
}

void CountingSort(char* array, size_t size) {
    if (size == 0) {
        std::cout << "Array length = 0" << std::endl;
        return;
    }
    size_t frequency[256]{ 0 };
    for (size_t i = 0; i < size; i++) {
        frequency[array[i]]++;
    }
    size_t position = 0;
    for (size_t number = 0; number <= 255; number++) {
        for (size_t i = 0; i < frequency[number]; i++) {
            array[position] = number;
            position++;
        }
    }
}

bool isSorted(int* array, size_t size) {
    while (size-- > 0) {
        if (array[size - 1] > array[size]) {
            return false;
        }
    }
    return true;
}

void shakeArray(int* array, size_t size) {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    for (size_t i = 0; i < size; i++) {
        std::swap(array[i], array[mersenne() % size]);
    }
}

double meanArray(double* array, size_t size)
{
    double summ = 0;
    for (size_t i = 0; i < size; i++)
    {
        summ += array[i];
    }
    return summ / size;
}
