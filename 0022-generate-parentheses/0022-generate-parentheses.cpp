class Solution {
public:
    void solve(int open, int close, int n, string curr, vector<string>& res) {
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }

        // Add '('
        if (open < n) {
            solve(open + 1, close, n, curr + "(", res);
        }

        // Add ')'
        if (close < open) {
            solve(open, close + 1, n, curr + ")", res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(0, 0, n, "", res);
        return res;
    }
};