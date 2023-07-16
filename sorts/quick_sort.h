#ifndef QUICK_SORT_HEADER
#define QUICK_SORT_HEADER

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
    int random = l + rand() % (r - l);

    std::swap(a[random], a[l]);

    return Partition(a, l, r);
}

void QuickSort(int a[], int l, int r) {
    if (l >= r) return;

    int s = Partition(a, l, r);
    QuickSort(a, l, s - 1);
    QuickSort(a, s + 1, r);
}

#endif // QUICK_SORT_HEADER
