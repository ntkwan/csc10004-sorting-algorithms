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

    void SelectionSortOptimize1(int a[], int n) {
        int r = n;
        for (int i = 0; i < r - 1; ++i) {
            int cur_min = i;
            int cur_max = i;
            for (int j = i + 1; j < r; ++j)
                if (a[cur_min] > a[j])
                    cur_min = j;
                else if (a[cur_max] < a[j])
                    cur_max = j;
            
            std::swap(a[cur_min], a[i]);
            if (cur_max == i) cur_max = cur_min;
            --r;
            std::swap(a[cur_max], a[r]);
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

    void SelectionSortOptimize1(int a[], int n, long long& comparison) {
        int r = n;
        for (int i = 0; ++comparison && i < r - 1; ++i) {
            int cur_min = i;
            int cur_max = i;
            for (int j = i + 1; ++comparison && j < r; ++j)
                if (++comparison && a[cur_min] > a[j])
                    cur_min = j;
                else if (++comparison && a[cur_max] < a[j])
                    cur_max = j;
            
            std::swap(a[cur_min], a[i]);
            if (++comparison && cur_max == i) cur_max = cur_min;
            --r;
            std::swap(a[cur_max], a[r]);
        }
    }
}

#endif // SELECTION_SORT_HEADER
