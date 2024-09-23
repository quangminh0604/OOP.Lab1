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
	struct SoTietKiem {
        string ma_so;
        string loai_tiet_kiem;
        string ho_va_ten;
        string cmnd;
        string date_string;
        Date date;
        double so_tien_gui;
        SoTietKiem() {}
        void output() {
            cout << "Ma so: " << ma_so << "\n";
            cout << "Loai tiet kiem: " << loai_tiet_kiem << "\n";
            cout << "Ho ten khach hang: " << ho_va_ten << "\n";
            cout << "Chung minh nhan dan: " << cmnd << "\n";
            cout << "Ngay mo so: " << date_string << "\n";
            cout << "So tien gui: " << so_tien_gui << "\n";
            cout << "\n";
        }
    };
    int n;
    vector<SoTietKiem> so;
   
    void input() { // input
        cin >> n; string tmp; getline(cin, tmp);
        REP(i, n) {
            //cout << i << "\n";
            so.push_back(SoTietKiem());
            cout << "Nhap ma so: ";
            getline(cin, so[i].ma_so);
            
            while (true) {
                bool ok = true;
                if (sz(so[i].ma_so) != 5) ok = false;
                for (auto x : so[i].ma_so) 
                    if (x == ' ') ok = false;
                    else {
                        if (x < '0' || x > '9') 
                        if (x < 'a' || x > 'z') 
                        if (x < 'A' || x > 'Z') ok= false;
                    }
                if (ok == true) break;
                cout << "Ma so loi, Nhap lai ma so: ";
                getline(cin, so[i].ma_so);
            }
            //
            cout << "Nhap loai tiet kiem:";
            getline(cin, so[i].loai_tiet_kiem);
            while (true) {
                bool ok = true;
                if (sz(so[i].loai_tiet_kiem) > 10) ok = false;
                if (ok == true) break;
                cout << "Loai tiet kiem loi, Nhap lai: ";
                getline(cin, so[i].loai_tiet_kiem);
            }

            cout << "Nhap ho ten khach hang:";
            getline(cin, so[i].ho_va_ten);
            while (true) {
                bool ok = true;
                if (sz(so[i].ho_va_ten) > 30) ok = false;
                for (auto c : so[i].ho_va_ten) {
                    if (c >= '0' && c <= '9') ok = false;
                    if (c < 'a' || c > 'z')
                    if (c < 'A' || c > 'Z')
                    if (c != ' ') ok = false;
                }
                if (ok == true) break;
                cout << "Ho va ten loi, nhap lai: ";
                getline(cin, so[i].ho_va_ten);
            }

            cout << "Nhap chung minh nhan dan: ";
            getline(cin, so[i].cmnd);
            while (true) {
                bool ok = true;
                if (sz(so[i].cmnd) != 9 && sz(so[i].cmnd) != 12) ok = false;
                if (ok == true) break;
                cout << "Chung minh nhan dan loi, nhap lai: ";
                getline(cin, so[i].cmnd);
            }

            cout << "Nhap ngay mo so:";
            getline(cin, so[i].date_string);
            
            while (true) {
                bool ok = true;
                int x = 0, cnt = 0;
                for (auto c : so[i].date_string) {
                    if (c == '-') {
                        ok = false;
                        break;
                    }
                    else 
                    if (c == ' ') {
                        cnt++;
                        if (cnt == 1) so[i].date.day = x;
                        if (cnt == 2) so[i].date.month = x;
                        x = 0;
                    } 
                    else if (x == 0 && c == '0') {
                        ok = false;
                        break;
                    } else x = x * 10 + (c - '0');
                }
                so[i].date.year = x;
                if (so[i].date.check_valid() == false) ok = false;
                if (ok == true) break;
                cout << "Ngay mo so loi, Nhap lai: ";
                getline(cin, so[i].date_string);
            }

            cout << "Nhap so tien gui: ";
            cin >> so[i].so_tien_gui;
            while (so[i].so_tien_gui <= 0) {
                cout << "So tien gui loi, Nhap lai: ";
                cin >> so[i].so_tien_gui;
            }
        }

    }
    
    void solve() {
        // sort
        REP(i, n) so[i].output();
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
        //freopen("bai9.inp", "r", stdin);
        //freopen("bai9.out", "w", stdout);
        #else
        //
        #endif // ONLINE_JUDGE*/
        int t = 1; //cin >> t;
        while (t--) solve();
    return 0;
}

