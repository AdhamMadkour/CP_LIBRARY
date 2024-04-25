class SparseTable {
public:
    vector<vector<int>> table;
    vector<int> log;
    int n, m;
    function<int(int, int)> f;

    SparseTable() {
    }

    //                          the function to be used in comparison
    void init(vector<int> &arr, function<int(int, int)> _f) {
      n = arr.size();
      m = log2(n) + 1;
      table.resize(n, vector<int>(m));
      log.resize(n + 1);
      log[1] = 0;
      for (int i = 2; i <= n; i++) {
        log[i] = log[i / 2] + 1;
      }
      f = _f;
      build(arr);
    }

    void build(vector<int> &arr) {
      for (int i = 0; i < n; i++) {
        table[i][0] = arr[i];
      }
      for (int j = 1; j < m; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
          table[i][j] = f(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
      }
    }

    int query(int l, int r) {
      int j = log[r - l + 1];
      return f(table[l][j], table[r - (1 << j) + 1][j]);
    }
};