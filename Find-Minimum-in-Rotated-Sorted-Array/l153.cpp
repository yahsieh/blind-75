class Solution {
   public:
    int findPivot(vector<int>& nums, int l, int r) {
        while (l < r) {
            if (r - l == 1) return nums[l] < nums[r] ? l : r;
            if (nums[l] > nums[r]) {
                int m = l + (r - l) / 2;
                if (nums[m] < nums[l])
                    r = m;
                else
                    l = m + 1;
            } else {
                return l;
            }
        }
        return l;
    }
    int findMin(vector<int>& nums) {
        return nums[findPivot(nums, 0, nums.size() - 1)];
    }
};