#ifndef BUBBLE_SORT_H_INCLUDED
#define BUBBLE_SORT_H_INCLUDED
void BubbleSort(int a[], int n)
{
    int lstExchange = n - 2;
    for (int i = 0; i < n; i++)
    {
        int pos = -1;
        for (int j = 0; j <= lstExchange; j++)
        {
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                pos = j;
            }
        }
        if (pos == -1)
            break;
        else
            lstExchange = pos;
    }
}

#endif // BUBBLE_SORT_H_INCLUDED
