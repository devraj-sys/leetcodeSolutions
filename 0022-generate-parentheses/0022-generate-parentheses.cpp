class Solution {
public:
    void solve(int open, int close, int n, string& curr, vector<string>& res) {
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');        // DO
            solve(open + 1, close, n, curr, res);
            curr.pop_back();            // UNDO
        }

        if (close < open) {
            curr.push_back(')');        // DO
            solve(open, close + 1, n, curr, res);
            curr.pop_back();            // UNDO
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        solve(0, 0, n, curr, res);
        return res;
    }
};