#include <stdio.h>

int secLargest(int x[], int n, int *result)
{
    if (n < 2)
    {
        return 0;
    }
    int largest = x[0];
    int secondLargest;
    int foundSecond = 0;

    for (int i = 1; i < n; i++)
    {
        if (x[i] > largest)
        {
            secondLargest = largest;
            largest = x[i];
            foundSecond = 1;
        }
        else if (!foundSecond && x[i] != largest)
        {
            secondLargest = x[i];
            foundSecond = 1;
        }
        else if (foundSecond == 1 && x[i] < largest && x[i] > secondLargest)
        {
            secondLargest = x[i];
        }
    }

    if (foundSecond == 0)
    {
        return 0; // failure: no second largest
    }

    *result = secondLargest; // store the value for the caller
    return 1;                // success
}


int main(void)
{
    int test1[] = {5, 5, 5};
    int test2[] = {4, 9, 2, 7, 9, 5};
    int test3[] = {-10, -3, -7, -1};
    int test4[] = {8, 8, 8, 3, 3};
    int test5[] = {5, 0, -3};
    int test6[] = {42};

    int *tests[] = {test1, test2, test3, test4, test5, test6};
    int sizes[] = {3, 6, 4, 5, 3, 1};

    for (int i = 0; i < 6; i++)
    {
        int result;
        int success = secLargest(tests[i], sizes[i], &result);

        printf("Test %d: ", i + 1);

        if (success == 1)
        {
            printf("Second largest: %d\n", result);
        }
        else
        {
            printf("No second-largest number exists.\n");
        }
    }

    return 0;
}
