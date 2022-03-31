class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return ;
        int index = nums.size() - 1;
        while(index > 0 && nums[index - 1] >= nums[index])
        {
            index--;
        }
        if(index != 0)
        {
            int k = nums.size() - 1;
            int min = INT_MAX;
            for(auto i = nums.size() - 1; i >= index; i--)
            {
                if(nums[i] > nums[index - 1] && nums[i] < min)
                {
                    min = nums[i];
                    k = i;
                }
            }
            int temp = nums[k];
            nums[k] = nums[index - 1];
            nums[index - 1] = temp;
            for(auto i = 0; i < (nums.size() - index)/2; i++)
            {
                temp = nums[i + index];
                nums[i + index] = nums[nums.size() - 1 - i];
                nums[nums.size() - 1 - i] = temp;
            }            
        }
        else
        {
            for(auto i = 0; i < nums.size()/2; i++)
            {
                int temp = nums[i];
                nums[i] = nums[nums.size() - 1 - i];
                nums[nums.size() - 1 - i] = temp;
            }
        }
        return ;
    }
};