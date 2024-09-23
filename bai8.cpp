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
bool date_31[13]; 
            
struct Solve {
    struct Date {
        int day, month, year;
        Date() {}
        bool is_leap(int year) {
            if (year % 100) return year % 400 == 0;
            return year % 4 == 0;
        }
        bool check_valid() {
            if (month < 1 || month > 12) return false;
            if (day < 1 || day > 31) return false;
            if (month == 2) {
                if (is_leap(year)) {
                    if (day > 28) return false;
                } else if (day > 29) return false;
            }
            if (date_31[month] == false && day == 31) return false;
            if (year < 0) return false;
            return true;
        }
    };
	struct Flight {
        string flight_id;
        Date date;
        string date_string;
        string time_take_off;
        string arrival;
        string departure;
        Flight() {}
        void output() {
            cout << "Ma so chuyen bay: ";
            cout << flight_id << "\n";
            cout << "Ngay bay:";
            cout << date.day << "/" << date.month << "/" << date.year << "\n";
            cout << "Thoi gian cat canh:";
            cout << time_take_off << "\n";
            cout << "Dia diem khoi hanh: ";
            cout << departure << "\n";
            cout << "Diem den: ";
            cout << arrival << "\n";
            cout << "\n";
        }
    };
    int n;
    vector<Flight> flights;
   
    void input() { // input
        cin >> n; string tmp; getline(cin, tmp);
        REP(i, n) {
            //cout << i << "\n";
            flights.push_back(Flight());
            cout << "Nhap ma so chuyen bay: ";
            getline(cin, flights[i].flight_id);
            
            while (true) {
                bool ok = true;
                if (sz(flights[i].flight_id) > 5) ok = false;
                for (auto x : flights[i].flight_id) 
                    if (x == ' ') ok = false;
                    else {
                        if (x < '0' || x > '9') 
                        if (x < 'a' || x > 'z') 
                        if (x < 'A' || x > 'Z') ok= false;
                    }
                if (ok == true) break;
                cout << "Ma so loi, Nhap lai ma so chuyen bay: ";
                getline(cin, flights[i].flight_id);
            }
            //
            cout << "Nhap ngay bay:";
            getline(cin, flights[i].date_string);
            
            while (true) {
                bool ok = true;
                int x = 0, cnt = 0;
                for (auto c : flights[i].date_string) {
                    if (c == '-') {
                        ok = false;
                        break;
                    }
                    else 
                    if (c == ' ') {
                        cnt++;
                        if (cnt == 1) flights[i].date.day = x;
                        if (cnt == 2) flights[i].date.month = x;
                        x = 0;
                    } 
                    else if (x == 0 && c == '0') {
                        ok = false;
                        break;
                    } else x = x * 10 + (c - '0');
                }
                flights[i].date.year = x;
                if (flights[i].date.check_valid() == false) ok = false;
                if (ok == true) break;
                cout << "Ngay bay loi, Nhap lai ngay bay: ";
                getline(cin, flights[i].date_string);
            }

            cout << "Nhap thoi gian cat canh:";
            getline(cin, flights[i].time_take_off);
            while (true) {
                bool ok = true;
                int x = 0, cnt = 0, hour = -1, minute = -1;
                for (auto c : flights[i].time_take_off) {
                    if (c == '-') {
                        ok = false;
                        break;
                    }
                    else 
                    if (c == ':') {
                        hour = x;
                        x = 0;
                    } 
                    else if (x == 0 && c == '0') {
                        ok = false;
                        break;
                    } else x = x * 10 + (c - '0');
                }
                minute = x;
                if (minute < 0 || minute > 59) ok = false;
                if (hour < 0 || hour > 59) ok = false;
                if (ok == true) break;
                cout << "Thoi gian cat canh loi, Nhap lai thoi gian cat canh: ";
                getline(cin, flights[i].time_take_off);
            }

            cout << "Nhap dia diem khoi hanh: ";
            getline(cin, flights[i].departure);
             while (true) {
                bool ok = true;
                if (sz(flights[i].departure) > 20) ok = false;
                for (auto c : flights[i].departure) {
                    if ('0' <= c && c <= '9') ok = false;
                    if (c < 'a' || c > 'z')
                    if (c < 'A' || c > 'Z') ok = false;
                }
                if (ok == true) break;
                cout << "Dia diem sai quy chuan, nhap lai dia diem khoi hanh: ";
                getline(cin, flights[i].departure);
            }


            cout << "Nhap diem den: ";
            getline(cin, flights[i].arrival);
             while (true) {
                bool ok = true;
                if (sz(flights[i].arrival) > 20) ok = false;
                for (auto c : flights[i].arrival) {
                    if (c >= '0' && c <= '9') ok = false;
                    if (c < 'a' || c > 'z')
                    if (c < 'A' || c > 'Z') ok = false;
                }
                if (ok == true) break;
                cout << "Diem den sai quy chuan, nhap lai diem den: ";
                getline(cin, flights[i].arrival);
            }

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
        // find functi on
        cout << "Nhap ma chuyen bay, noi di va noi den can tim:";
        string st; getline(cin, st);
        bool found = false;
        REP(i, n) if (flights[i].flight_id == st) {
            cout << "Da tim thay\n";
            flights[i].output();
            found = true;
        }
        if (found == false) cout << "Khong tim thay chuyen bay\n";
        cout << "Nhap dia diem khoi hanh de tim tat ca chuyen bay:";
        string departure; getline(cin, departure);
        REP(i, n) if (departure == flights[i].departure) flights[i].output();
        cout << "Nhap diem den de tim tat ca chuyen bay:";
        string arrival; getline(cin, arrival);
        REP(i, n) if (arrival == flights[i].arrival) flights[i].output();
    }
} minhntq;

void solve() {
    memset(date_31, false, sizeof date_31);
    date_31[1] = date_31[3] = date_31[5] = date_31[7] = date_31[8] = true;
    date_31[10] = date_31[12] = true;
	minhntq.input();
	minhntq.solve();
}
 
int main() {
        ios_base::sync_with_stdio(false);
        #ifndef ONLINE_JUDGE
        //freopen("bai8.inp", "r", stdin);
        //freopen("bai8.out", "w", stdout);
        #else
        //
        #endif // ONLINE_JUDGE*/
        int t = 1; //cin >> t;
        while (t--) solve();
    return 0;
}

