/* 
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include "pre_config.h"
// #include "../../../pre_config/pre_config.h"

static const char *TAG = "towSum";

// hl_result_e twoSum(int nums[], size_t numsSize, int target, int returnSize[2])
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
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
    int nums[] = {3,3};
    int target = 6;
    int returnSize[2] = {};

    twoSum(nums, sizeof(nums), target, returnSize);

    printf("result[%d, %d]\n", returnSize[0], returnSize[1]);
    return 0;
}