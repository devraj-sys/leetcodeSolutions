class Solution {
public:
    void solve(vector<int>& c, int target, vector<vector<int>>& ans, vector<int>& curr, int i) {

        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        if(i == c.size() || target < 0) return;

        curr.push_back(c[i]);
        
        solve(c, target - c[i] , ans, curr, i);
        curr.pop_back();

        solve(c, target, ans, curr, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(candidates, target, ans, curr, 0);
        return ans;
    }
};