#include "utils/DataGenerator.cpp"
#include "sorts/sort_headers.h"

using namespace std;

const int N = 10;
int a[N];

int main()
{
    GenerateRandomData(a, N);
    selectionSort(a, N);
}
