#ifndef MERGE_SORT_HEADER
#define MERGE_SORT_HEADER

namespace runtime {
    void Merge(int a[], int l, int mid, int r) {
        int i = l, j = mid + 1;
        std::vector<int> sortedArray;
        while (i <= mid && j <= r) {
            if (a[i] < a[j]) {
                sortedArray.push_back(a[i]);
                i++;
            } else {
                sortedArray.push_back(a[j]);
                j++;
            }
        }

        while (i <= mid) {
            sortedArray.push_back(a[i]);
            i++;
        }

        while (j <= r) {
            sortedArray.push_back(a[j]);
            j++;
        }

        for (int i = l; i <= r; i++) {
            a[i] = sortedArray[i - l];
        }
    }

    void MergeSort(int a[], int l, int r) {
        if (l >= r) return;

        int mid = (l + r) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, r);
        Merge(a, l, mid, r);
    }

    void MergeSort(int a[], int n) {
        MergeSort(a, 0, n - 1);
    }
}

namespace runcpr {
    void Merge(int a[], int l, int mid, int r, long long &comparison) {
        int i = l, j = mid + 1;
        std::vector<int> sortedArray;
        while (++comparison && i <= mid && ++comparison && j <= r) {
            if (++comparison && a[i] < a[j]) {
                sortedArray.push_back(a[i]);
                i++;
            } else {
                sortedArray.push_back(a[j]);
                j++;
            }
        }

        while (++comparison && i <= mid) {
            sortedArray.push_back(a[i]);
            i++;
        }

        while (++comparison && j <= r) {
            sortedArray.push_back(a[j]);
            j++;
        }

        for (int i = l; ++comparison && i <= r; i++) {
            a[i] = sortedArray[i - l];
        }
    }

    void MergeSort(int a[], int l, int r, long long& comparison) {
        if (l >= r) return;

        int mid = (l + r) / 2;
        MergeSort(a, l, mid, comparison);
        MergeSort(a, mid + 1, r, comparison);
        Merge(a, l, mid, r, comparison);
    }

    void MergeSort(int a[], int n, long long& comparison) {
        MergeSort(a, 0, n - 1, comparison);
    }
}

#endif // MERGE_SORT_HEADER
