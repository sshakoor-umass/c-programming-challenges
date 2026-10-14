
#include <stdio.h>

int removeDuplicates(int nums[], int n)
{
    int uniqueCount = 0;

    for (int i = 0; i < n; i++)
    {
        int isDuplicate = 0;

        for (int j = 0; j < uniqueCount; j++)
        {
            if (nums[j] == nums[i])
            {
                isDuplicate = 1;
                break;
            }
        }

        if (isDuplicate == 0)
        {
            nums[uniqueCount] = nums[i];
            uniqueCount++;
        }
    }

    return uniqueCount;
}

int main(void)
{
    int nums[] = {-3, 0, -3, 5, 0, -1, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    int newLength = removeDuplicates(nums, n);

    for (int i = 0; i < newLength; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("\n");

    return 0;
}
