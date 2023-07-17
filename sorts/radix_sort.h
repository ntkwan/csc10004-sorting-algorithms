#ifndef RADIX_SORT_H_INCLUDED
#define RADIX_SORT_H_INCLUDED
int findMax(int a[], int n)
{
	int m = -2e9;
	for (int i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];
	return m;
}

int findMin(int a[], int n)
{
	int m = 2e9;
	for (int i = 0; i < n; i++)
		if (a[i] < m)
			m = a[i];
	return m;
}

void CountingSort(int a[], int n, int exp)
{
	int* f = new int[10];
	int* b = new int[n];

	for (int i = 0; i < 10; i++)
		f[i] = 0;

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

    int min = findMin(a, n);
    if (min < 0)
        for (int i = 0; i < n; i++)
            a[i] -= min;

    int max = findMax(a, n);
	for (int exp = 1; max / exp > 0; exp *= 10)
		CountingSort(a, n, exp);

    if (min < 0)
        for (int i = 0; i < n; i++)
            a[i] += min;
}
#endif // RADIX_SORT_H_INCLUDED
