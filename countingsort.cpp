
#include <iostream>
#include <cstring>

int main()
{

    long long int N, number, max = -10000000, min = 10000000;
    std::cin >> N;
    long long int *arr = new long long int[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> number;
        arr[i] = number;
        if (number > max)
            max = number;

        if (min > number)
            min = number;
    }
    if (N == 1)
    {
        std::cout << arr[0];
        return 0;
    }

    if (min < 0)
    {
        long long int total = max - min, count[total + 1];
        for (int i = 0; i <= total; i++)
        {
            count[i] = 0;
        }
        int k = 0;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] < 0)
            {
                count[min - arr[i]]++;
            }
            else
            {
                count[abs(min) + arr[i]]++;
            }
        }

        for (long long int i = 0, b = 0; i <= total; i++)
        {
            for (long long int j = 0; j < count[i]; j++)
            {
                std::cout << min + i << " ";
            }
        }
    }
    else
    {
        long long int count[max + 1];
        for (int i = 0; i <= max; i++)
        {
            count[i] = 0;
        }

        for (int i = 0; i < N; i++)
        {
            count[arr[i]]++;
        }

        for (long long int i = 0; i <= max; i++)
        {
            for (long long int j = 0; j < count[i]; j++)
            {
                std::cout << i << " ";
            }
        }
    }
    return 0;
}