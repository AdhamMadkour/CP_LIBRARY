#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx4[] = {-1, 0, 0, 1};
int dy4[] = {0, -1, 1, 0};
#define _ 0
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(X) (X).begin(),(X).end()
#define allr(X) (X).rbegin(),(X).rend()
#define Take(X) for (auto &it:(X)) cin >> it;
#define Out(X) for (auto &it:(X))cout << it << " ";
#define TAKE(X, S) for (auto &it:(X)) cin >> it, (S) += it;
#define Fast_IO ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
const int mod = 1e9 + 7;
const int N = 1e7 + 5;
const double pi = acos(-1);
const ll oo = LLONG_MAX;
const int OO = 0x7f7f7f7f;

ll Lcm(ll a, ll b) { return a * (b / __gcd(a, b)); }

int mult(int a, int b) { return (1LL * a * b) % mod; }

int mult(int a, int b, int mm) { return (1LL * a * b) % mm; }

int modSum(ll a, ll b) {
    a = (a % mod + mod) % mod, b = (b % mod + mod) % mod;
    return (a + b) % mod;
}

int modSub(ll a, ll b) { return modSum(a, -b); }

template<class T>
void debug(std::vector<T> &vect) {
    cerr << endl;
    for (auto x: vect)cerr << "'" << x << "' ";
    cerr << endl;
}

template<class T>
void debug(T argumentAmount, ...) {
    va_list arguments;
    va_start(arguments, argumentAmount);
    T parameter;
    for (int i = 0; i < argumentAmount; ++i) {
        parameter = va_arg(arguments, T);
        cerr << "'" << parameter << "' ";
    }
    cerr << endl;
    va_end(arguments);
    return;
}

/*___________________________________________________________________________*/

// problem link :https://www.spoj.com/problems/LCASQ/
/*
You are given a rooted tree and an ordered list of queries.
Each query is specified by two nodes u and v and the answer to a query is the lowest common ancestor of u and v.

Recall that the Lowest Common Ancestor of two nodes is the node that is furthest from the root and also an ancestor of the two nodes.
 In this problem we use the convention that a node is in fact an ancestor of itself.

Input
The first line contains an integer N, the number of nodes in the tree (N <= 10000). 
Each of the next N lines will start with a number M the number of child nodes of the Nth node,
 (0 <= M <= 999) followed by M numbers the child nodes of the Nth node.
Nodes will be labeled from 0 to N-1. Following will be a number Q, the number of queries that will be asked (Q <= 10000).
Each of the next Q lines will have two numbers u and v (0 <= u, v < N) which specify the parameters of that specific query.

The root of the tree will always be node 0.
*/

#define int ll
vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> depth;

void dfs(int node) {
    // Ancestor and depth for every node
    for (auto child: adj[node]) {
        depth[child] = depth[node] + 1;
        up[child][0] = node;

        for (int i = 1; i < 20; ++i) {
            // my power of two parent is the parent of
            // the previous parent

            up[child][i] = up[up[child][i - 1]][i - 1];
        }
        // take care that the dfs must be done after finishing
        // the binary lifting for the current node
        // otherwise it will cause wrong answer

        dfs(child);
    }

}

int getLCA(int u, int v) {
    // we first need to make both node a and b
    // at the same depth, so we will check the depth
    // for both of them to make them equal

    if (depth[u] < depth[v])
        swap(u, v);

    // getting the difference of depth for both of them
    // to lift the deepest one to close one to make them in
    // equal depth
    int k = abs(depth[u] - depth[v]);

    // getting the Kth ancestor of the deepest one
    // to make there depth first
    for (int i = 0; i < 20; ++i) {
        if ((k >> i) & 1) {
            u = up[u][i];
        }
    }

    // checking if both of them are at the same node
    // if so that means that we have the LCA
    if (u == v)
        return u;

    // binary lifting them to get closer to the LCA
    // while both aren't equal
    for (int i = 19; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    // if both nodes are settled down at a point
    // that means we reached our destiny
    // just returning the parent of the current settled node
    // this is the LCA
    return up[u][0];
}

void blow_it() {
    int n;
    cin >> n;
    adj = vector<vector<int>>(n);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        adj[i] = vector<int>(x);
        Take(adj[i]);
    }
    depth = vector<int>(n);
    up = vector<vector<int>>(n, vector<int>(20));
    dfs(0);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << getLCA(u, v) << endl;
    }
}

void preprocess() {

}

int32_t main() {
    Fast_IO;
    /*freopen("input.in", "r", stdin);*/
    //freopen("output.txt", "w", stdout);
    //cout << fixed << setprecision(15);
    int t = 1, cases = 1;
    //cin >> t;
    //std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    preprocess();
    while (t--) {
        //cout << "Case #" << cases++ << ": ";
        //blow_it(n);
        blow_it();
    }
    //std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    //cerr << "Time : " << (end - start).count() / (1000000.0l) << " ms \n";
    return (0 ^ _ ^ 0);
}