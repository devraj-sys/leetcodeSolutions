class Solution {
public:

    unordered_map<string, string> parent;

    string find(string x) {

        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }

        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void unite(string x, string y) {

        string px = find(x);
        string py = find(y);

        if (px != py) {
            parent[py] = px;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, string> emailToName;

        // Union emails in same account
        for (auto &account : accounts) {

            string name = account[0];
            string firstEmail = account[1];

            for (int i = 1; i < account.size(); i++) {

                string email = account[i];

                emailToName[email] = name;

                unite(firstEmail, email);
            }
        }

        // Group emails by parent
        unordered_map<string, vector<string>> groups;

        for (auto &it : emailToName) {

            string email = it.first;

            string root = find(email);

            groups[root].push_back(email);
        }

        // Build final answer
        vector<vector<string>> result;

        for (auto &it : groups) {

            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> temp;

            temp.push_back(emailToName[it.first]);

            for (auto &email : emails) {
                temp.push_back(email);
            }

            result.push_back(temp);
        }

        return result;
    }
};