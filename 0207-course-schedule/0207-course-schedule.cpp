class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        if (state[node] == 1) return true;   // cycle
        if (state[node] == 2) return false;  // already safe

        state[node] = 1; // mark visiting

        for (auto neighbor : adj[node]) {
            if (dfs(neighbor, adj, state))
                return true;
        }

        state[node] = 2; // mark safe
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // build graph
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, adj, state))
                return false;
        }

        return true;
    }
};