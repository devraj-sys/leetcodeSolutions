class Solution {
public:

    void solve(vector<int>& c, int target, vector<vector<int>> &ans, vector<int> &curr, int i ){

        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(i  >= c.size() || c[i] > target) return;
        curr.push_back(c[i]);
        solve(c,target-c[i],ans,curr,i+1);
        curr.pop_back();
        int next = i+1;
        while(next < c.size() && c[next] == c[i] ){
            next++;
        }
        solve(c,target,ans,curr,next);
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        int i = 0;
        solve(candidates,target,ans,curr,i);
        return ans;
    }
};