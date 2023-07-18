#ifndef FLASH_SORT_H_INCLUDED
#define FLASH_SORT_H_INCLUDED

int bucket[300000];
namespace runtime
{
    void FlashSort(int a[], int n)
    {
        if (n <= 1)
            return;
        // step 1
        int m = n * 0.45;
        if (m <= 2)
            m = 2;

        for (int i = 0; i < m; ++i)
            bucket[i] = 0;
        int max = a[0], min = a[0];
        for (int i = 1; i < n; ++i){
            if (max < a[i]) max = a[i];
            if (min > a[i]) min = a[i];
        }
        if (max == min)
            return;

    #define getK(x) 1ll * (m - 1) * (x - min) / (max - min)
        for (int i = 0; i < n; ++i)
            ++bucket[getK(a[i])];
        for (int i = 1; i < m; ++i)
            bucket[i] += bucket[i - 1];

        //step 2
        int count = 0;
        int i = 0;
        while (count < n){
            int k = getK(a[i]);
            while (i >= bucket[k])
                k = getK(a[++i]);
            int z = a[i];
            while (i != bucket[k]){
                k = getK(z);
                int y = a[bucket[k] - 1];
                a[--bucket[k]] = z;
                z = y;
                ++count;
            }
        }
        //step 3
        for (int k = 1; k < m; ++k){
            for (int i = bucket[k] - 2; i >= bucket[k - 1]; --i)
                if (a[i] > a[i + 1]){
                    int t = a[i], j = i;
                    while (t > a[j + 1]){
                        a[j] = a[j + 1];
                        ++j;
                    }
                    a[j] = t;
                }
        }
    }
}
namespace runcpr
{
    void FlashSort(int a[], int n, long long& comparison)
    {
        if (++comparison && n <= 1)
            return;
        // step 1
        int m = n * 0.45;
        if (++comparison && m <= 2)
            m = 2;

        for (int i = 0; ++comparison && i < m; ++i)
            bucket[i] = 0;
        int max = a[0], min = a[0];
        for (int i = 1; ++comparison && i < n; ++i){
            if (++comparison && max < a[i]) max = a[i];
            else if (++comparison && min > a[i]) min = a[i];
        }
        if (++comparison && max == min)
            return;

        #define getK(x) 1ll * (m - 1) * (x - min) / (max - min)
        for (int i = 0; ++comparison && i < n; ++i)
            ++bucket[getK(a[i])];
        for (int i = 1; ++comparison && i < m; ++i)
            bucket[i] += bucket[i - 1];
        //step 2
        int count = 0;
        int i = 0;
        while (++comparison && count < n){
            int k = getK(a[i]);
            while (++comparison && i >= bucket[k])
                k = getK(a[++i]);
            int z = a[i];
            while (++comparison && i != bucket[k]){
                k = getK(z);
                int y = a[bucket[k] - 1];
                a[--bucket[k]] = z;
                z = y;
                ++count;
            }
        }
        //step 3
        for (int k = 1; ++comparison && k < m; ++k){
            for (int i = bucket[k] - 2; ++comparison && i >= bucket[k - 1]; --i)
                if (++comparison && a[i] > a[i + 1]){
                    int t = a[i], j = i;
                    while (++comparison && t > a[j + 1]){
                        a[j] = a[j + 1];
                        ++j;
                    }
                    a[j] = t;
                }
        }
    }
}
#endif // FLASH_SORT_H_INCLUDED
