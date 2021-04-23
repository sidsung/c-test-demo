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

// #include "preConfig.h"
// #include "../../pre_config/pre_config.h"
#include "D:\1A.My Program Files\vscode workspace\c-test-demo\pre_config\pre_config.h"

static const char *TAG = "towSum";

hl_result_e towSum(int nums[], size_t numSize, int target, int out[2])
{
    if ((NULL == nums) || (NULL == out) || (numSize != sizeof(&nums)))
    {
        hlLogError("params error");
        return HL_FAIL;
    }

    int outOne, outTwo = 0;

    int i, j = 0;
    for (i = 0; i < numSize - i; i++)
    {
        for (j = i + 1; j < numSize - j; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                out[0] = i;
                out[1] = j;
                return HL_OK;
            }
        }
    }
    hlLogError("no factors sum to be target");

    return HL_FAIL;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int out[2] = {};

    HL_CHECK_ERROR(towSum(nums, sizeof(nums), target, out));

    hlLogInfo("result[%d, %d]", out[0], out[1]);
    return 0;
}