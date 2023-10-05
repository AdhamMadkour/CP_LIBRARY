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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
#define _ 0
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(X) (X).begin(),(X).end()
#define allr(X) (X).rbegin(),(X).rend()
#define popcnt(X) __builtin_popcount(X)
#define mem(X, Y) memset(X,Y,sizeof(X))
#define Take(X) for (auto &it:(X)) cin >> it;
#define Out(X) for (auto &it:(X))cout << it << " ";
#define TAKE(X, S) for (auto &it:(X)) cin >> it, (S) += it;
#define Fast_IO ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
ll mod = 1e9 + 7;
const double pi = acos(-1);
const int N = 2e5 + 5;
const ll oo = LLONG_MAX;
const int OO = 0x7f7f7f7f;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx4[] = {-1, 0, 0, 1};
int dy4[] = {0, -1, 1, 0};

/*___________________________________________________________________________*/
ll merge(vector<int> &a, int l, int r) {
    int i = l;
    int m = (r + l) / 2;
    int j = m + 1;
    vector<int> temp;
    ll cnt = 0;
    while (i <= m && j <= r) {
        if (a[i] < a[j]) {
            temp.push_back(a[i++]);
        } else {
            // if a[i] >= a[j] cnt equal the remain of sorted segment
            cnt += (m - i + 1);
            temp.push_back(a[j++]);
        }
    }
    while (i <= m) {
        temp.push_back(a[i++]);
    }
    while (j <= r) {
        temp.push_back(a[j++]);
    }
    int k = 0;
    for (int idx = l; idx <= r; idx++) {
        a[idx] = temp[k++];
    }
    return cnt;
}

ll divide(vector<int> &a, int l, int r) {
    if (l >= r)return 0;
    int mid = (r + l) / 2;
    // number of inversion on left side 
    ll c1 = divide(a, l, mid);
    // number of inversion on right side 
    ll c2 = divide(a, mid + 1, r);
    // number of inversion on intersection side 
    ll c3 = merge(a, l, r);
    return c1 + c2 + c3;
}

void blow_it() {
    int n;
    cin >> n;
    vector<int> a(n);
    Take(a);
    cout << divide(a, 0, n - 1) << endl;
}

void preprocess() {

}

int main() {
    Fast_IO;
    /*freopen("Case_100.in", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    //cout << fixed << setprecision(12);
    int t = 1, cases = 1;
    cin >> t;
    preprocess();
    while (t--) {
        //cout << "Case #" << cases++ << ':' << endl;
        blow_it();
    }
    return (0 ^ _ ^ 0);
}