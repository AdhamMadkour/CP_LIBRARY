/*
*  Author:
*          ╭━━━┳━━╮╭━━━┳━━━┳━━╮╭╮
*          ┃╭━╮┃╭╮┃┃╭━╮┃╭━╮┃╭╮┃┃┃
*          ┃┃╱┃┃╰╯╰┫┃╱┃┃┃╱╰┫╰╯╰┫┃
*          ┃╰━╯┃╭━╮┃┃╱┃┃┃╭━┫╭━╮┃┃╱╭╮
*          ┃╭━╮┃╰━╯┃╰━╯┃╰┻━┃╰━╯┃╰━╯┃
*          ╰╯╱╰┻━━━┻━━━┻━━━┻━━━┻━━━╯
*/
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
const int mod = 1000000007;
const double pi = acos(-1);
const int N = 1e4 + 5, M = 1e4 + 5;
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

/*___________________________________________________________________________*/
struct node {
    node *nxt[26];
    bool is_end;

    node() {
        for (int i = 0; i < 26; ++i) nxt[i] = nullptr;
        is_end = false;
    }
};

node *root = new node();

void insertTrie(string s) {
    node *cur = root;
    for (auto x: s) {
        int idx = x - 'a';
        if (cur->nxt[idx] == nullptr) {
            cur->nxt[idx] = new node();
        }
        cur = cur->nxt[idx];
    }
    cur->is_end = true;
}

bool searchTrie(string s) {
    node *cur = root;
    for (auto x: s) {
        int idx = x - 'a';
        if (cur->nxt[idx] == nullptr)return false;
        cur = cur->nxt[idx];
    }
    return true;
}

void blow_it() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        insertTrie(name);
    }
    if (searchTrie("ay")) {
        cout << "Found" << endl;
    } else cout << "Not Found" << endl;
}

void preprocess() {

}

int main() {
    //Fast_IO;
    /*freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    cout << fixed << setprecision(12);
    int t = 1, cases = 1;
    //cin >> t;
    preprocess();
    while (t--) {
        //cout << "Scenario #" << cases++ << ':' << endl;
        blow_it();
    }
    return (0 ^ _ ^ 0);
}