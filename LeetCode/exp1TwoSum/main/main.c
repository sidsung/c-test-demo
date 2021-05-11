#include "pre_config.h"

static const char *TAG = "towSum";

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j = 0;
    for (i = 0; i < numsSize - i; i++)
    {
        for (j = i + 1; j < numsSize - j; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                returnSize[0] = i;
                returnSize[1] = j;
                break;
            }
        }
    }

    return returnSize;
}

int main()
{
    int nums[] = {3, 3};
    int target = 6;
    int returnSize[2] = {};

    twoSum(nums, sizeof(nums), target, returnSize);

    printf("result[%d, %d]\n", returnSize[0], returnSize[1]);
    return 0;
}