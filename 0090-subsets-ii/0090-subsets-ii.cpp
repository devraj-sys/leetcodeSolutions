class Solution {
public:

    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int i) {

        if (i >= nums.size()) {
            ans.push_back(curr);
            return;
        }

        // 1. TAKE current
        curr.push_back(nums[i]);
        solve(nums, ans, curr, i + 1);
        curr.pop_back();

        // 2. SKIP all duplicates
        int next = i + 1;
        while (next < nums.size() && nums[next] == nums[i]) {
            next++;
        }

        solve(nums, ans, curr, next);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(nums, ans, curr, 0);
        return ans;
    }
};