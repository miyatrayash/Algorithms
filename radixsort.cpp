#include <iostream>

long long max(long long *arr, long long n)
{
    long long Max = arr[0];

    for (long long i = 1; i < n; i++)
    {
        if (Max < arr[i])
            Max = arr[i];
    }

    return Max;
}
void countingsort(long long *arr, long long div, long long n)
{
    long long *sorted = new long long[n];
    int count[10] = {0};
    for (long long i = 0; i < n; i++)
    {
        count[(arr[i] / div) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (long long i = n - 1; i >= 0; i--)
    {
        sorted[--count[(arr[i] / div) % 10]] = arr[i];
    }
    for (long long i = 0; i < n; i++)
    {
        arr[i] = sorted[i];
    }
    delete (sorted);
}

void radixsort(long long *arr, long long n)
{
    long long Max = max(arr, n), div = 1;

    for (long long i = 0; Max / div > 0; i++, div = div * 10)
    {
        countingsort(arr, div, n);
    }
}
int main()
{

    long long N, Pindex = 0, Nindex = 0, number;
    std::cin >> N;
    long long *positive = new long long[N], *negative = new long long[N];
    for (long long i = 0; i < N; i++)
    {

        std::cin >> number;
        if (number < 0)
        {
            negative[Nindex] = -number;
            Nindex++;
        }
        else
        {
            positive[Pindex] = number;
            Pindex++;
        }
    }

    radixsort(negative, Nindex);
    radixsort(positive, Pindex);
    for (long long i = Nindex - 1; i >= 0; i--)
    {
        std::cout << -negative[i] << ' ';
    }
    for (long long i = 0; i < Pindex; i++)
    {
        std::cout << positive[i] << ' ';
    }

    return 0;
}