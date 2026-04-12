// resubmitting for github - pure recurssion solution
class Solution {
public:
    void solve(vector<int> num, vector<int> op, vector<vector<int>> &ans) {
        if(num.size() == 0) {
            ans.push_back(op);
            return;
        }

        vector<int> op1 = op; 
        vector<int> op2 = op; 

        
        op2.push_back(num[0]);

        
        num.erase(num.begin());

        solve(num, op1, ans);
        solve(num, op2, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(nums, op, ans);
        return ans;
    }
};
