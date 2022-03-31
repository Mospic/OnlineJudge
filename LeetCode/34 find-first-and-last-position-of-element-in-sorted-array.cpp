class Solution {
private:
    vector<int> search(vector<int>& nums, int target, int low, int high)
    {
        if(low == high && nums[low] == target)
        {
            vector<int> vec = {low, high};
            return vec;
        }
        else if(low == high && nums[low] != target)
        {
            vector<int> vec = {-1, -1};
            return vec;
        }
        int mid = (low + high)/2;
        vector<int> vec1 = search(nums, target, low, mid);
        vector<int> vec2 = search(nums, target, mid + 1, high);
        if(vec1[0] != -1 && vec2[0] != -1)
        {
            vec1[1] = vec2[1];
            return vec1;
        }
        else if(vec1[1] == -1 && vec2[1] != -1)
        {
            return vec2;
        }
        else if(vec1[0] != -1 && vec2[1] == -1)
        {
            return vec1;
        }
        return vec1;
    }


public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int length = nums.size();
        if(nums.size() == 0)
        {
            vector<int> vec = {-1, -1};
            return vec;
        }
        return search(nums, target, 0, length - 1);

    }
};