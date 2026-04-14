class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        
        dfs(0, s, part, res);
        return res;
    }

    void dfs(int i, string& s, vector<string>& part, vector<vector<string>>& res) {
        if (i >= s.length()) {
            res.push_back(part);
            return;
        }

        for (int j = i; j < s.length(); j++) {
            if (isPali(s, i, j)) {
                part.push_back(s.substr(i, j - i + 1)); // choose
                dfs(j + 1, s, part, res);               // explore
                part.pop_back();                        // backtrack
            }
        }
    }

    bool isPali(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};