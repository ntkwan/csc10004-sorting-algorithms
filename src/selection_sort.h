#ifndef SELECTION_SORT_HEADER
#define SELECTION_SORT_HEADER

namespace runtime {
    void SelectionSort(int a[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] < a[minIdx])
                    minIdx = j;
            }

            if (minIdx != i) std::swap(a[minIdx], a[i]);
        }
    }
}

namespace runcpr {
    void SelectionSort(int a[], int n, long long &comparison) {
        for (int i = 0; ++comparison && i < n - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; ++comparison && j < n; ++j) {
                if (++comparison && a[j] < a[minIdx])
                    minIdx = j;
            }

            if (++comparison && minIdx != i) std::swap(a[minIdx], a[i]);
        }
    }
}

#endif // SELECTION_SORT_HEADER
