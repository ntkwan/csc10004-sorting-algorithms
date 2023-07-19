#ifndef HEAP_SORT_HEADER
#define HEAP_SORT_HEADER
namespace runtime
{
    void Sift(int a[], int left, int right) // right = n - 1
    {
        int i = left;
        int j = left * 2 + 1;
        int x = a[i];
        while (j <= right){
            if (j < right)
                if (a[j] < a[j + 1])
                    j++;
            if (x >= a[j])
                break;
            a[i] = a[j];
            i = j;
            j = 2 * i + 1;
        }
        a[i] = x;
    }
    void HeapSort(int a[], int n)
    {
        for (int i = n / 2; i >= 0; i--)
            Sift(a, i, n - 1);
        for (int i = n - 1; i > 0; i--){
            std::swap(a[0], a[i]);
            Sift(a, 0, i - 1);
        }
    }
}

namespace runcpr
{
    void Sift(int a[], int left, int right, long long& comparison)
    {
        int i = left;
        int j = left * 2 + 1;
        int x = a[i];
        while (++comparison && j <= right){
            if (++comparison && j < right)
                if (++comparison && a[j] < a[j + 1])
                    j++;
            if (++comparison && x >= a[j])
                break;
            a[i] = a[j];
            i = j;
            j = 2 * i + 1;
        }
        a[i] = x;
    }
    void HeapSort(int a[], int n, long long& comparison)
    {
        for (int i = n / 2; ++comparison && i >= 0; i--)
            Sift(a, i, n - 1, comparison);
        for (int i = n - 1; ++comparison && i > 0; i--){
            std::swap(a[0], a[i]);
            Sift(a, 0, i - 1, comparison);
        }
    }
}

#endif // HEAP_SORT_HEADER
