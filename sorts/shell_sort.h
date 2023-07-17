#ifndef SHELL_SORT_HEADER
#define SHELL_SORT_HEADER

const int gaps[] = {65921, 16577, 4193, 1073, 281, 77, 23, 8, 1};

void ShellSort(int a[], int n) {
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

#endif // SHELL_SORT_HEADER
