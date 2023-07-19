#ifndef QUICK_SORT_HEADER
#define QUICK_SORT_HEADER

namespace runtime {
    int Partition(int a[], int l, int r) {
        int p = a[l];
        int i = l;
        int j = r + 1;
        do {
            do i++; while (a[i] < p && i < r);
            do j--; while (a[j] > p && j > l);
            std::swap(a[i], a[j]);
        } while (i < j);

        std::swap(a[i], a[j]);
        std::swap(a[l], a[j]);
    return j;
    }

    int GetRandomPivot(int a[], int l, int r) {
        srand(time(NULL));
        int random = (1ll * rand() * rand()) % (r - l + 1) + l;

        std::swap(a[random], a[l]);

        return Partition(a, l, r);
    }

    void RandomizedQuickSort(int a[], int l, int r) {
        if (l >= r) return;

        int s = GetRandomPivot(a, l, r);
        RandomizedQuickSort(a, l, s - 1);
        RandomizedQuickSort(a, s + 1, r);
    }

    void RandomizedQuickSort(int a[], int n) {
        RandomizedQuickSort(a, 0, n - 1);
    }

    int GetMedianPivot(int a[], int l, int r) {
        int mid = (l + r) / 2;

        if (a[l] > a[mid])
            std::swap(a[l], a[mid]);

        if (a[l] > a[r])
            std::swap(a[l], a[r]);

        if (a[mid] > a[r])
            std::swap(a[mid], a[r]);

        std::swap(a[mid], a[l]);

        return Partition(a, l, r);
    }

    void MedianQuickSort(int a[], int l, int r) {
        if (l >= r) return;

        int s = GetMedianPivot(a, l, r);
        MedianQuickSort(a, l, s - 1);
        MedianQuickSort(a, s + 1, r);
    }

    void MedianQuickSort(int a[], int n) {
        MedianQuickSort(a, 0, n - 1);
    }
}

namespace runcpr {
    int Partition(int a[], int l, int r, long long& comparison) {
        int p = a[l];
        int i = l;
        int j = r + 1;
        do {
            do i++; while (++comparison && a[i] < p && ++comparison && i < r);
            do j--; while (++comparison && a[j] > p && ++comparison && j > l);
            std::swap(a[i], a[j]);
        } while (++comparison && i < j);

        std::swap(a[i], a[j]);
        std::swap(a[l], a[j]);
    return j;
    }

    int GetRandomPivot(int a[], int l, int r, long long& comparison) {
        srand(time(NULL));
        int random = (1ll * rand() * rand()) % (r - l + 1) + l;

        std::swap(a[random], a[l]);

        return Partition(a, l, r, comparison);
    }

    void RandomizedQuickSort(int a[], int l, int r, long long& comparison) {
        if (++comparison && l >= r) return;

        int s = GetRandomPivot(a, l, r, comparison);
        RandomizedQuickSort(a, l, s - 1, comparison);
        RandomizedQuickSort(a, s + 1, r, comparison);
    }

    void RandomizedQuickSort(int a[], int n, long long& comparison) {
        RandomizedQuickSort(a, 0, n - 1, comparison);
    }

    int GetMedianPivot(int a[], int l, int r, long long& comparison) {
        int mid = (l + r) / 2;

        if (++comparison && a[l] > a[mid])
            std::swap(a[l], a[mid]);

        if (++comparison && a[l] > a[r])
            std::swap(a[l], a[r]);

        if (++comparison && a[mid] > a[r])
            std::swap(a[mid], a[r]);

        std::swap(a[mid], a[l]);

        return Partition(a, l, r, comparison);
    }

    void MedianQuickSort(int a[], int l, int r, long long& comparison) {
        if (++comparison && l >= r) return;

        int s = GetMedianPivot(a, l, r, comparison);
        MedianQuickSort(a, l, s - 1, comparison);
        MedianQuickSort(a, s + 1, r, comparison);
    }

    void MedianQuickSort(int a[], int n, long long& comparison) {
        MedianQuickSort(a, 0, n - 1, comparison);
    }
}

#endif // QUICK_SORT_HEADER
