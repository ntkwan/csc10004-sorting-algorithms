#ifndef RADIX_SORT_H_INCLUDED
#define RADIX_SORT_H_INCLUDED
int FindMax(int a[], int n)
{
	int m = -2e9;
	for (int i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];

return m;
}

int FindMin(int a[], int n)
{
	int m = 2e9;
	for (int i = 0; i < n; i++)
		if (a[i] < m)
			m = a[i];

return m;
}

void CountingSort(int a[], int n, int exp)
{
	int* f = new int[10] {0};
	int* b = new int[n] {0};

	for (int i = 0; i < n; i++)
		f[(a[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		f[i] += f[i - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		b[f[(a[i] / exp) % 10] - 1] = a[i];
		f[(a[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
		a[i] = b[i];
}

void RadixSort(int a[], int n)
{
    int minVal = FindMin(a, n);
    if (minVal < 0)

    for (int i = 0; i < n; i++)
        a[i] -= minVal;

    int maxVal = FindMax(a, n);
	for (int exp = 1; maxVal / exp > 0; exp *= 10)
		CountingSort(a, n, exp);

    if (minVal < 0)
        for (int i = 0; i < n; i++)
            a[i] += minVal;
}
#endif // RADIX_SORT_H_INCLUDED
