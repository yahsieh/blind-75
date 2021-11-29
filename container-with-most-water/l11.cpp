class Solution {
   public:
    int calc(int a, int b, int w) { return min(a, b) * w; }
    int maxArea(vector<int>& height) {
        int ret;
        ret = calc(height.front(), height.back(), height.size() - 1);
        int l = 0, sz = height.size(), r = sz - 1;
        while (l < r) {
            ret = max(ret, calc(height[l], height[r], r - l));
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return ret;
    }
};