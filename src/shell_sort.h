#ifndef SHELL_SORT_HEADER
#define SHELL_SORT_HEADER

namespace runtime {
    void ShellSort(int a[], int n) {
        const int gaps[] = {65921, 16577, 4193, 1073, 281, 77, 23, 8, 1};

        for (int gap : gaps) {
            for (int i = gap; i < n; ++i) {
                int v = a[i];
                int j = i;
                while (j >= gap && a[j - gap] > v) {
                    a[j] = a[j - gap];
                    j -= gap;
                }

                a[j] = v;
            }
        }
    }
}

namespace runcpr {
    void ShellSort(int a[], int n, int &comparison) {
    const int gaps[] = {65921, 16577, 4193, 1073, 281, 77, 23, 8, 1};

    for (int idx = 0; ++comparison && idx < 9; ++idx) {
        int gap = gaps[idx];
        for (int i = gap; ++comparison && i < n; ++i) {
            int v = a[i];
            int j = i;
            while (++comparison && j >= gap && ++comparison && a[j - gap] > v) {
                a[j] = a[j - gap];
                j -= gap;
            }

            a[j] = v;
        }
    }
    }
}

#endif // SHELL_SORT_HEADER
