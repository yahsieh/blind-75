class Solution {
   public:
    int bsearch(vector<int>& nums, int l, int r, int target) {
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > target)
                r = m;
            else if (nums[m] < target)
                l = m + 1;
            else
                return m;
        }
        if (nums[l] == target)
            return l;
        else if (nums[r] == target)
            return r;
        return -1;
    }
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
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        if (sz == 1) return target == nums[0] ? 0 : -1;
        int l = 0, r = sz - 1;
        int m = l + (r - l) / 2;
        int pivot = findPivot(nums, 0, sz - 1);
        int ans;
        if (pivot != 0) {
            ans = bsearch(nums, 0, pivot - 1, target);
            if (ans == -1) ans = bsearch(nums, pivot, sz - 1, target);
        } else {
            ans = bsearch(nums, 0, sz - 1, target);
        }
        return ans;
    }
};