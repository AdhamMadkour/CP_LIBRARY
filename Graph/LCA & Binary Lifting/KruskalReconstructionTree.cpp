class KRT {
public:
    int id, timer = 0;
    vector<int> par, cost, depth, in, out, all_values;
    vector<vector<int>> adj, up;
//    SparseTable stin, stout;

    KRT(int n) {
      id = n + 1;
      par.resize(2 * n + 1);
      adj.resize(2 * n + 1);
      cost.resize(2 * n + 1);
      depth.resize(2 * n + 1);
      in = vector<int>(2 * n + 1);
      out = vector<int>(2 * n + 1);
      all_values.resize(4 * n + 1);
      up = vector<vector<int>>(2 * n + 1, vector<int>(20));
      iota(all(par), 0);
    }

    int find(int u) {
      return par[u] == u ? u : par[u] = find(par[u]);
    }

    bool join(int u, int v) {
      u = find(u), v = find(v);
      if (u == v) return false;
      par[u] = par[v] = par[id] = id;
      adj[id].push_back(u);
      adj[id].push_back(v);
      id++;
      return true;
    }

    void add_edge(int u, int v, int c) {
      if (join(u, v)) {
        cost[id - 1] = c;
      }
    }

    void dfs(int node) {
      all_values[timer] = node;
      in[node] = timer++;
      for (auto &child: adj[node]) {
        depth[child] = depth[node] + 1;
        up[child][0] = node;
        for (int i = 1; i < 20; i++) {
          up[child][i] = up[up[child][i - 1]][i - 1];
        }
        dfs(child);
      }
      all_values[timer] = node;
      out[node] = timer++;
    }

    int lca(int u, int v) {
      if (depth[u] < depth[v]) swap(u, v);
      for (int i = 19; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
          u = up[u][i];
        }
      }
      if (u == v) return u;
      for (int i = 19; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
          u = up[u][i];
          v = up[v][i];
        }
      }
      return up[u][0];
    }

    void build() {
      dfs(id - 1);
//      stin.init(in);
//      stout.init(out);
    }

    int query(int u, int v) {
//      int l = stin.query(u, v).first;
//      int r = stout.query(u, v).second;
//      int l_node = all_values[l];
//      int r_node = all_values[r];
//      int lca_node = lca(l_node, r_node);
//      return cost[lca_node];
      return cost[lca(u, v)];
    }
};