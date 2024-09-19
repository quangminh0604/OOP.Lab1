#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, b) for (int i = 0, _b = (b); i < _b; i++)
#define ii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define ll long long
#define ld long double
#define sz(x) ((int)(x).size())
#define next ____next
#define prev ____prev
#define left ____left
#define right ___right
#define lcm ___lcm
#define index ____index
using namespace std;
 
template<class M> M myabs(M x) {
        return x < 0 ? -x : x;
}
template<class M1, class M2> bool minimize(M1 &x, const M2 &y) {
        if (x > y) {x = y; return true;} return false;
}
template<class M1, class M2> bool maximize(M1 &x, const M2 &y) {
        if (x < y) {x = y; return true;} return false;
}
 
const int INF = (int)1e9 + 7;
const ll INFLL = (ll)1e18 + 7LL;
 
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
 
mt19937 rd(time(0));
 
#define MAX 100100

struct Solve {
    int n, m;
    int a[MAX], b[MAX];
    const int P1 = (int)1e9 + 7;
    const int P2 = (int)1e9 + 1011;
    const int BASE = (int)1e9;
    ii hashID;
    ii hash[MAX], pw[MAX];
    void input() {
        cin >> n; cin >> m;
        FOR(i, 1, n) cin >> a[i];
        
        FOR(i, 1, m) cin >> b[i];
    }
    ii getHash(int l, int r) {
        ii res;
        res.fi = (hash[r].fi - 1LL * hash[l - 1].fi * pw[r - l + 1].fi % P1 + P1) % P1;
        res.se = (hash[r].se - 1LL * hash[l - 1].se * pw[r - l + 1].se % P2 + P2) % P2;
        return res;
    }
    void solve() {
        pw[0].fi = pw[0].se = 1;
        FOR(i, 1, MAX - 1) {
            pw[i].fi = 1LL * pw[i - 1].fi * BASE % P1;
            pw[i].se = 1LL * pw[i - 1].se * BASE % P2;
        }
        FOR(i, 1, n) {
            hashID.fi = (1LL * hashID.fi * BASE % P1 + a[i]) % P1;
            hashID.se = (1LL * hashID.se * BASE % P2 + a[i]) % P2;
        }
        FOR(i, 1, m) {
            hash[i].fi = (1LL * hash[i - 1].fi * BASE % P1 + b[i]) % P1;
            hash[i].se = (1LL * hash[i - 1].se * BASE % P2 + b[i]) % P2;
        }
        //cout << hashValue.fi << " " << hashValue.se << "\n";
        vector<int> res;
        FOR(i, 1, m - n + 1) {
            if (getHash(i, i + n - 1) == hashID) res.push_back(i);
        }
        cout << sz(res) << "\n";
        for (auto x : res) cout << x << " "; 
    }
} minhntq;

void solve() {
    minhntq.input();
    minhntq.solve();
}
 
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
        #else
        //
        #endif // ONLINE_JUDGE*/
        int t = 1; //cin >> t;
        while (t--) solve();
    return 0;
}
