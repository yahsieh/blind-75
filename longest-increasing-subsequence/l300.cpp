class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        // X[k] = stores the smallest element that LIS length = k
        int X[sz+1];
        int L = 0;
        for (int i=1;i<=sz;i++) {
            // do binary search from X[1] to X[L], where L is current max LIS
            int l = 1, r = L;
            while (l<r) {
                int m = l+(r-l)/2;
                if (X[m]>=nums[i-1])
                    r = m;
                else
                    l = m+1;
            }
            // we are finding l such that X[l] < currentElement
            // X[l] need to be strictly lesser than currentElement
            if (X[l]>=nums[i-1])
                --l;
            // initial condition where L == 0
            if (L == 0)
                l = 0;
            // we can append currentElement to current LIS
            // append it and increment L
            if (l == L)
                ++L;
            X[l+1] = nums[i-1];
        }
        return L;
    }
};