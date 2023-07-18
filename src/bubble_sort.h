#ifndef BUBBLE_SORT_H_INCLUDED
#define BUBBLE_SORT_H_INCLUDED

namespace runtime {
    void BubbleSort(int a[], int n) {
        int lstExchange = n - 2;
        for (int i = 0; i < n; i++) {
            int curExchange = -1;
            for (int j = 0; j <= lstExchange; j++) {
                if (a[j] > a[j + 1]) {
                    std::swap(a[j], a[j + 1]);
                    curExchange = j;
                }
            }
            if (curExchange == -1) break;
            else lstExchange = curExchange;
        }
    }
}

namespace runcpr
{
    void BubbleSort(int a[], int n, long long& comparison)
    {
        int lstExchange = n - 2;
        for (int i = 0; ++comparison && i < n; i++)
        {
            int curExchange = -1;
            for (int j = 0; ++comparison && j <= lstExchange; j++)
            {
                if (++comparison && a[j] > a[j + 1])
                {
                    std::swap(a[j], a[j + 1]);
                    curExchange = j;
                }
            }

            if (++comparison && curExchange == -1) break;
            else lstExchange = curExchange;
        }
    }
}

#endif // BUBBLE_SORT_H_INCLUDED
