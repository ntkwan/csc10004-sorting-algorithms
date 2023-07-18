#ifndef RADIX_SORT_H_INCLUDED
#define RADIX_SORT_H_INCLUDED

namespace runtime {
	int FindMax(int a[], int n) {
		int m = -2e9;
		for (int i = 0; i < n; i++)
			if (a[i] > m)
				m = a[i];

	return m;
	}

	int FindMin(int a[], int n) {
		int m = 2e9;
		for (int i = 0; i < n; i++)
			if (a[i] < m)
				m = a[i];

	return m;
	}

	void CountingSort(int a[], int n, int shift) {
		int* f = new int[16] {0};
		int* b = new int[n];

		for (int i = 0; i < n; i++)
			f[a[i] >> shift & 15]++;

		for (int i = 1; i < 16; i++)
			f[i] += f[i - 1];

		for (int i = n - 1; i >= 0; i--)
		{
			b[f[a[i] >> shift & 15] - 1] = a[i];
			f[a[i] >> shift & 15]--;
		}

		for (int i = 0; i < n; i++)
			a[i] = b[i];
	}

	void RadixSort(int a[], int n) {
		int minVal = FindMin(a, n);

		if (minVal < 0)
			for (int i = 0; i < n; i++)
				a[i] -= minVal;

		int maxVal = FindMax(a, n);
		for (int shift = 0; (maxVal >> shift) > 0; shift += 4)
			CountingSort(a, n, shift);

		if (minVal < 0)
			for (int i = 0; i < n; i++)
				a[i] += minVal;
	}
}

namespace runcpr {
    int FindMax(int a[], int n, int &comparison)
    {
        int m = -2e9;
        for (int i = 0; ++comparison && i < n; i++)
            if (a[i] > m)
                m = a[i];

        return m;
    }

    int FindMin(int a[], int n, int &comparison)
    {
        int m = 2e9;
        for (int i = 0; ++comparison && i < n; i++)
            if (a[i] < m)
                m = a[i];

        return m;
    }

    void CountingSort(int a[], int n, int shift, int &comparison)
    {
        int* f = new int[16] {0};
        int* b = new int[n];

        for (int i = 0; ++comparison && i < n; i++)
            f[a[i] >> shift & 15]++;

        for (int i = 1; ++comparison && i < 16; i++)
            f[i] += f[i - 1];

        for (int i = n - 1; ++comparison && i >= 0; i--)
        {
            b[f[a[i] >> shift & 15] - 1] = a[i];
            f[a[i] >> shift & 15]--;
        }

        for (int i = 0; ++comparison && i < n; i++)
            a[i] = b[i];
    }

    void RadixSort(int a[], int n, int &comparison)
    {
        int minVal = FindMin(a, n, comparison);

        if (++comparison && minVal < 0)
            for (int i = 0; ++comparison && i < n; i++)
                a[i] -= minVal;

        int maxVal = FindMax(a, n, comparison);
        for (int shift = 0; ++comparison && (maxVal >> shift) > 0; shift += 4)
            CountingSort(a, n, shift);

        if (++comparison && minVal < 0)
            for (int i = 0; ++comparison && i < n; i++)
                a[i] += minVal;
    }
}

#endif // RADIX_SORT_H_INCLUDED
