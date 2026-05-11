class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(deadends.begin(), deadends.end());

        // If starting point itself is blocked
        if(dead.count("0000")) return -1;

        queue<string> q;
        unordered_set<string> visited;

        q.push("0000");
        visited.insert("0000");

        int moves = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                string curr = q.front();
                q.pop();

                // Target found
                if(curr == target)
                    return moves;

                // Generate neighbors
                for(int i = 0; i < 4; i++) {

                    char ch = curr[i];

                    // Turn wheel up
                    curr[i] = ((ch - '0' + 1) % 10) + '0';

                    if(!dead.count(curr) && !visited.count(curr)) {
                        q.push(curr);
                        visited.insert(curr);
                    }

                    // Turn wheel down
                    curr[i] = ((ch - '0' + 9) % 10) + '0';

                    if(!dead.count(curr) && !visited.count(curr)) {
                        q.push(curr);
                        visited.insert(curr);
                    }

                    // Restore original digit
                    curr[i] = ch;
                }
            }

            moves++;
        }

        return -1;
    }
};