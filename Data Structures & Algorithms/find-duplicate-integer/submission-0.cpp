class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int pointTo = abs(nums[i]);
            if (nums[pointTo] < 0) return abs(nums[i]);
            nums[pointTo] *= -1;
        }
        return 0;
    }
};
