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
    struct Date {
        int day, month, year;
        Date() {}
    };
	struct Flight {
        string flight_id;
        Date date;
        string time_take_off;
        string arrival;
        string departure;
        Flight() {}
    };
    int n;
    vector<Flight> flights;
   
    void input() { // input
        cin >> n; string tmp; getline(cin, tmp);
        REP(i, n) {
            flights.push_back(Flight());
            getline(cin, flights[i].flight_id);
            while (true) {
                bool ok = true;
                for (auto x : flights[i].flight_id) 
                    if (x == ' ') ok = false;
                    else {
                        if (x < '0' || x > '9') 
                        if (x < 'a' || x > 'z') 
                        if (x < 'A' && x > 'Z') ok= false;
                    }
                if (ok == true) break;
                cout << "Nhap lai ma so chuyen bay: ";
                getline(cin, flights[i].flight_id);
            }

            cin >> flights[i].date.day >> flights[i].date.month >> flights[i].date.year; getline(cin, tmp);
            getline(cin, flights[i].time_take_off);
            getline(cin, flights[i].departure);
            getline(cin, flights[i].arrival);
        }

        // REP(i, n) {
        //     cout << flights[i].flight_id << "\n";
        //     cout << flights[i].date.day << "/" << flights[i].date.month << "/" << flights[i].date.year << "\n";
        //     cout << flights[i].time_take_off << "\n";
        //     cout << flights[i].departure << "\n";
        //     cout << flights[i].arrival << "\n";
        // }
    }
    bool is_lower_date(Date& A, Date& B) { // compare to date whether date A stands before or after date B 
        if (A.year < B.year) return true;
        if (A.year > B.year) return false;
        if (A.month < B.month) return true;
        if (A.month > B.month) return false;
        if (A.day <= B.day) return true;
        return false;
    }
    bool is_lower_time(string s1, string s2) { // compare two time whether time s1 stands before or after time s2
        int x = (s1[0] - '0')*10 + (s1[1] - '0');
        int y = (s1[3] - '0')*10 + (s1[4] - '0');
        int a = (s2[0] - '0')*10 + (s2[1] - '0');
        int b = (s2[3] - '0')*10 + (s2[4] - '0');
        if (x < a) return true;
        if (x > a) return false;
        if (y <= b) return true;
        return false;
    }
    void solve() {
        // sort
        sort(ALL(flights), [&](Flight& A, Flight& B){
            if (is_lower_date(A.date, B.date)) return true;
            if (is_lower_time(A.time_take_off, B.time_take_off)) return true;
            return false;
        });

        // print arranged flight
        cout << "Danh sach chuyen bay duoc sap xep la:\n";
        REP(i, n) {
            cout << flights[i].flight_id << "\n";
        }
        // find function
        cout << "Nhap ma chuyen bay, noi di va noi den can tim:";
        string st; getline(cin, st);
        REP(i, n) if (flights[i].flight_id == st) {
            cout << "Da tim thay\n";
            cout << flights[i].flight_id << "\n";
            cout << flights[i].date.day << "/" << flights[i].date.month << "/" << flights[i].date.year << "\n";
            cout << flights[i].time_take_off << "\n";
            cout << flights[i].departure << "\n";
            cout << flights[i].arrival << "\n";
            return;
        }
        cout << "Khong tim thay chuyen bay";
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
        freopen("bai8.inp", "r", stdin);
        freopen("bai8.out", "w", stdout);
        #else
        //
        #endif // ONLINE_JUDGE*/
        int t = 1; //cin >> t;
        while (t--) solve();
    return 0;
}
