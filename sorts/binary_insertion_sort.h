#ifndef BINARY_INSERTION_SORT_HEADER
#define BINARY_INSERTION_SORT_HEADER
namespace runtime
{
    void BinaryInsertionsortSort(int a[], int n)
    {
        for (int i = 1; i < n; i++){
            int pivot = a[i];
            int s = std::upper_bound(a, a + i, a[i]) - a;
            for (int j = i - 1; j >= s; j--)
			a[j + 1] = a[j];
            a[s] = pivot;
        }
    }
}
namespace runcpr
{
    void BinaryInsertionsortSort(int a[], int n, int& comparison)
    {
        for (int i = 1; ++comparison && i < n; i++)
        {
            int pivot = a[i];
            int left = 0;
            int right = i - 1;
            while (++comparison && left <= right)
            {
                int mid = (right + left) / 2;
                if (++comparison && a[mid] < pivot)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            for (int j = i - 1; ++comparison && j >= left; j--)
                a[j + 1] = a[j];
            a[left] = pivot;
        }
    }
}
#endif // BINARY_INSERTION_SORT_HEADER
