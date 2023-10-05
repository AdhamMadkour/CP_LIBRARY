// problem link : https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

class TreeAncestor {
public:
    vector<vector<int>> up;

    TreeAncestor(int n, vector<int> &parent) {
        up = vector<vector<int>>(n + 1, vector<int>(21, -1));
        for (int i = 0; i < n; ++i)
            up[i][0] = parent[i];

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < 20; ++j) {
                if (up[i][j - 1] == -1)
                    continue;
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; ++i) {
            if ((k >> i) & 1) {
                node = up[node][i];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
};
