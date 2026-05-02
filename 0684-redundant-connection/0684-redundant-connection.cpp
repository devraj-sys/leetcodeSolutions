class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unionSet(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return false; // cycle

        parent[pa] = pb;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &e : edges) {
            if (!unionSet(e[0], e[1]))
                return e;
        }

        return {};
    }
};