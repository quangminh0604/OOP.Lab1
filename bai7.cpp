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
 
#define MAX 

struct Solve {
	struct Student {
		string full_name;
		double math, literature, foreign_language;
		double avr;
		string type;
		void input() {
			getline(cin, full_name);
			cin >> math >> literature >> foreign_language;
			string tmp; getline(cin, tmp);
		}
		Student() {
		}
	};
	const int n = 3;
	Student std[4];
    void input() {
        FOR(i, 1, n) std[i].input();  
    }
    void solve() {
		//FOR(i, 1, n) cout << std[i].full_name << " " << std[i].math << " " << std[i].literature << " " << std[i].foreign_language << "\n";
		int highest = 1, math_lowest = 1;
		FOR(i, 1, n) {
			std[i].avr = (double)(2*std[i].math + std[i].literature + std[i].foreign_language) / 4;
			
			if (std[i].avr >= 9) std[i].type = "Xuat sac";
			else 
			if (std[i].avr >= 8) std[i].type = "Gioi";
			else 
			if (std[i].avr >= 6.5) std[i].type = "Kha";
			else 
			if (std[i].avr >= 5) std[i].type = "Trung Binh";
			else std[i].type = "Yeu";

			if (std[i].avr > std[highest].avr) highest = i;
			if (std[i].math < std[math_lowest].math) math_lowest = i;
		}

		FOR(i, 1, n) {
			cout << std[i].avr << " " << std[i].type << "\n";
		}
		cout << "Hoc sinh co diem trung binh cao nhat la:\n" << std[highest].full_name << "\n";
		cout << "Danh sach hoc sinh co diem toan thap nhat la:\n";
		FOR(i, 1, n) if (std[math_lowest].math == std[i].math)	cout << std[i].full_name << "\n";
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
