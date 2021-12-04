class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        int sum = 0;
        vector<int> ret(2);
        while (start<end) {
            sum = nums[start] + nums[end];
            if (sum < target)
                ++start;
            else if (sum > target)
                --end;
            else {
                ret[0] = start, ret[1] = end;
                break;
            }
        }
                return ret;
    }
};