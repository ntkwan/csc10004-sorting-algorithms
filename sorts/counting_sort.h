#ifndef COUNTING_SORT_HEADER
#define COUNTING_SORT_HEADER

void CountingSort(int a[], int n) {
    int mx = -2E9;
    for (int i = 0; i < n; ++i)
        if (mx < a[i]) mx = a[i];

    int mn = 2E9;
    for (int i = 0; i < n; ++i)
        if (mn > a[i]) mn = a[i];

    for (int i = 0; i < n; ++i) a[i] = a[i] - mn;

    int *f = new int[mx - mn + 1];
    for (int i = 0; i <= mx - mn; ++i) f[i] = 0;

    for (int i = 0; i < n; ++i) f[a[i]]++;

    for (int u = 1; u <= mx - mn; ++u)
        f[u] = f[u - 1] + f[u];

    int *b = new int[n];
    for (int i = n - 1; i >= 0; --i) {
        b[f[a[i]] - 1] = a[i];
        --f[a[i]];
    }

    for (int i = 0; i < n; ++i) a[i] = b[i] + mn;
}

#endif // COUNTING_SORT_HEADER
