class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> res;
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        string curr = "";
        solve(0, digits, mapping, curr, res);
        return res;
    }

    void solve(int index, string& digits, vector<string>& mapping, string& curr, vector<string>& res) {
        if (index == digits.length()) {
            res.push_back(curr);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {
            curr.push_back(ch);            // choose
            solve(index + 1, digits, mapping, curr, res); // explore
            curr.pop_back();               // backtrack
        }
    }
};