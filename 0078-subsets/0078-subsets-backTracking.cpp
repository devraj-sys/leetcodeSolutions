class Solution {
public:

    void solve(vector<int>& nums, vector<vector<int>> &ans, vector<int> curr, int i  ){
        if(i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(nums,ans,curr,i+1);

        curr.pop_back();
        solve(nums,ans,curr,i+1);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int i = 0 ;
        solve(nums,ans,curr,i);
        return ans;
    }
};
