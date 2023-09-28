#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <random>
#include <algorithm>

class array {
private:
    int size;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    std::vector<int> nums;
    void swap(int *a, int *b);
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    int sleeptime;

public:
    array(int s);
    void sort();
    void setxy(int x, int y);
    void print();

};

#endif
