#ifndef HANDLE_CMD_H
#define HANDLE_CMD_H

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cassert>

#include "../utils/DataGenerator.cpp"
#include "../src/sort_headers.h"

#define ERROR -1

#define RANDOM_DATA 0
#define SORTED_DATA 2
#define REVERSED_DATA 3
#define NEARLY_SORTED_DATA 1

//#define TESTING

typedef void (*sort_ptr)(int[], int);
sort_ptr sortRuntime[] = {
    runtime::BubbleSortOptimize1, runtime::BubbleSort,
    runtime::CountingSort, runtime::MergeSort,
    runtime::RandomizedQuickSort, runtime::MedianQuickSort, 
    runtime::RadixSort, 
    runtime::SelectionSort, runtime::SelectionSortOptimize1, 
    runtime::ShakerSort, runtime::ShellSort, runtime::FlashSort, 
    runtime::HeapSort, 
    runtime::InsertionSort, runtime::BinaryInsertionSort
};

typedef void (*sort_cpr)(int[], int, long long&);
sort_cpr sortCpr[] = {
    runcpr::BubbleSortOptimize1, runcpr::BubbleSort,
    runcpr::CountingSort, runcpr::MergeSort,
    runcpr::RandomizedQuickSort, runcpr::MedianQuickSort, 
    runcpr::RadixSort, 
    runcpr::SelectionSort, runcpr::SelectionSortOptimize1,
    runcpr::ShakerSort, runcpr::ShellSort, runcpr::FlashSort, 
    runcpr::HeapSort, 
    runcpr::InsertionSort, runcpr::BinaryInsertionSort
};

const std::string sortName[] = {
    "Bubble Sort", "Bubble Sort (Optimize 1)", 
    "Counting Sort", "Merge Sort",
    "Quick Sort (Random Pivot)", "Quick Sort (Median of Three Pivot)", "Radix Sort", 
    "Selection Sort", "Selection Sort (Optimize 1)", 
    "Shaker Sort", "Shell Sort", "Flash Sort", 
    "Heap Sort", 
    "Insertion Sort", "Binary Insertion Sort"
};

const std::string typeName[] = {
    "Randomize", "Sorted", "Nearly Sorted", "Reversed"
};

const int sortNum = sizeof(sortRuntime) / sizeof(sortRuntime[0]);
const int maxN = 1E6;
int a[maxN];
int data[maxN];

#ifdef TESTING
int b[maxN];
#endif //TESTING

std::string GetDataName(int dataType);
int GetSortName(const std::string &sortName);
int GetDataOrder(const std::string &dataOrder);
void PrintRuntime(int a[], int inputSize, sort_ptr sortFunction, int isComparison);
void PrintComparisons(int a[], int inputSize, sort_cpr sortFunction, int isComparison);
void PrintArray(int a[], int inputSize, const std::string &filename);
void CopyArray(int a[], int data[], int inputSize);
void AlgorithmMode(int argc, char** argv);
void ComparisonMode(int argc, char** argv);

#endif //HANDLE_CMD_H