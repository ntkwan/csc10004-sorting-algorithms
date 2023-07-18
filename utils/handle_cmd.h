#ifndef HANDLE_CMD_H
#define HANDLE_CMD_H

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <vector>

#include "../utils/DataGenerator.cpp"
#include "../src/sort_headers.h"

#define ERROR -1
#define SUCCESS -2

#define RANDOM_DATA 0
#define SORTED_DATA 2
#define REVERSED_DATA 3
#define NEARLY_SORTED_DATA 1

typedef void (*sort_ptr)(int[], int);
sort_ptr sortRuntime[] = {
    runtime::BubbleSort, runtime::CountingSort, runtime::MergeSort,
    runtime::QuickSort, runtime::RadixSort, runtime::SelectionSort, 
    runtime::ShakerSort, runtime::ShellSort};
    //, runtime::FlashSort, runtime::HeapSort, runtime::InsertionSort, runtimeBinaryInsertionSort};

const int sortNum = sizeof(sortRuntime) / sizeof(sortRuntime[0]);
const int maxN = 5E5;
int a[maxN];

std::string GetDataName(int dataType);
int GetSortName(const std::string &sortName);
int GetDataOrder(const std::string &dataOrder);
void PrintRuntime(int a[], int inputSize, sort_ptr sortFunction);
void PrintArray(int a[], int inputSize, const std::string &filename);
void AlgorithmMode(int argc, char** argv);
void ComparisonMode(int argc, char** argv);

#endif //HANDLE_CMD_H