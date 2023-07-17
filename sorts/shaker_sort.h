#ifndef SHAKER_SORT_H_INCLUDED
#define SHAKER_SORT_H_INCLUDED
void ShakerSort (int a[], int n)
{
    int left = 0;
	int right = n - 1;
	int k = 0;

	while (left < right) {
        bool isSwapped = false;
		for (int i = left; i < right; i++) {
			if (a[i] > a[i + 1]) {
				std::swap(a[i], a[i + 1]);
				k = i;
				isSwapped = true;
			}
		}

        if (isSwapped == false) break;
		right = k;

        isSwapped = false;
		for (int i = right; i > left; i--) {
			if (a[i] < a[i - 1]) {
				std::swap(a[i], a[i - 1]);
				k = i;
                isSwapped = true;
			}
		}

		if (isSwapped == false) break;
		left = k;
	}
}

#endif // SHAKER_SORT_H_INCLUDED
