class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26);

        // Step 1: store rank of each character
        for (int i = 0; i < order.size(); i++) {
            rank[order[i] - 'a'] = i;
        }

        // Step 2: compare adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int j = 0;
            bool foundDiff = false;

            while (j < w1.size() && j < w2.size()) {
                if (w1[j] != w2[j]) {
                    if (rank[w1[j] - 'a'] > rank[w2[j] - 'a'])
                        return false;
                    foundDiff = true;
                    break;
                }
                j++;
            }

            // Edge case: prefix issue
            if (!foundDiff && w1.size() > w2.size())
                return false;
        }

        return true;
    }
};