#ifndef MERGE_SORT_HEADER
#define MERGE_SORT_HEADER

namespace runtime {
    void MergeSort(int a[], int l, int r) {
        if (l >= r) return;

        int mid = (l + r) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, r);
        std::inplace_merge(a + l, a + mid + 1, a + r + 1);
    }

    void MergeSort(int a[], int n) {
        MergeSort(a, 0, n - 1);
    }
}

#endif // MERGE_SORT_HEADER
