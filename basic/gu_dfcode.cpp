#include <bits/stdc++.h>
// #pragma GCC optimize(1,2,3,"Ofast","inline")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define int i64
#define FF first
#define SS second
#define SZ(x) ((i32)(x).size())
#define PB push_back
#define EB emplace_back
#define all(x) (x).begin(), (x).end()
using i128 = __int128_t;
using ui64 = uint64_t;
using i64 = int64_t;
using ui32 = uint32_t;
using i32 = int32_t;
using ld = long double;
using P32 = pair<i32, i32>;
using P64 = pair<i64, i64>;
const i64 INF = 1e18;
const ld eps = 1e-8L;

// mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
// i64 randint(i64 l, i64 r) { uniform_int_distribution<> dis(l, r); return dis(mt); }
// double randld(i64 l, i64 r) { uniform_real_distribution<> dis(l, r); return dis(mt); }
bool chmin(auto &a, auto b) { return (b < a) and (a = b, true); }
bool chmax(auto &a, auto b) { return (a < b) and (a = b, true); }

void debug() {}
template<class T> void debug(T var) { cerr << var; }
template<class T, class ...P> void debug(T var, P ...t) { cerr << var << ", "; debug(t...); }
template<class T> void org(T l, T r) { while(l != r) cerr << *l++ << ' '; }
#define de(...) { cerr << "[Line: " << __LINE__ << "][" << #__VA_ARGS__ << "] -> [", debug(__VA_ARGS__), cerr << "]\n"; }
#define orange(...) { cerr << "[Line: " << __LINE__ << "][" << #__VA_ARGS__ << "] -> [", org(__VA_ARGS__), cerr << "]\n"; }

const i32 msize = 200000;
char buf[msize], *p1 = buf, *p2 = buf;
char obuf[msize], *p3 = obuf;
#define getc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, msize, stdin), p1 == p2) ? EOF : *p1++)
#define putac(x) (p3 - obuf < msize) ? (*p3 ++ = x) :(fwrite(obuf, p3 - obuf, 1, stdout), p3 = obuf, *p3 ++ = x)
template<class T> inline void read(T &x) {
    x = 0;
    i32 f = 1;
    char ch = getc();
    for (; ch < 48 || ch > 57; ch = getc()) if (ch == '-') f = -1;
    for (; ch >= 48 && ch <= 57; ch = getc()) x = (x << 3) + (x << 1) + (ch ^ 0x30);
    x = x * f;
}
template<class T> void write(const T &x) {
    static i32 c[40];
    if (!x) { putac('0'); return; }
    i32 len = 0;
    T k1 = x;
    if (k1 < 0) k1 = -k1, putac('-');
    while (k1) c[len++] = k1 % 10 ^ 48, k1 /= 10;
    while (len--) putac(c[len]);
}
void write(const char *str) { while (*str) putac(*str++); }
void write(const string &str) { for (char c : str) putac(c); }
void write(const char &c) { putac(c); }
template<typename T, typename... Args>
inline void read(T &x, Args&... args) {
    read(x);  // 讀取第一個變數
    (read(args), ...); // 展開剩餘變數的讀取
}
template<typename T, typename... Args>
inline void write(const T &x, const Args&... args) {
    write(x);
    write(args...);
}
// 喵
//           ／＞　フ
// 　　　　  |   _　 _l
// 　 　　　／` ミ＿Xノ
// 　　 　 /　　　 　|
// 　　　 /　 ヽ　　 ﾉ
// 　 　 │　　|　|　|
// 　／￣|　　 |　|　|
// 　| (￣ヽ＿_ヽ_)__)
// 　＼二つ
// 喵
void OUO();
i32 main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    i32 t = 1;
    for (i32 tt = 0; tt < t; tt++){
        OUO();
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
}

void OUO() {
    
}
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠟⠛⠛⠛⠛⠛⠛⠛⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿ 
// ⣿⣿⣿⣿⣿⠿⠛⢉⣠⣴⣶⣾⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⣌⣉⠙⠻⠿⢿⣿⣿ 
// ⣿⣿⡿⠛⣁⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣀⠈⣻ 
// ⣿⡟⢁⣾⣿⣿⠿⠛⠻⢿⣭⣿⣿⣿⣿⣿⣿⣟⣥⠟⠛⠛⠻⢿⣿⣿⡟⣿⣧⢸ 
// ⡟⢀⣾⣿⣿⡏⠀⠤⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⠃⠠⠶⠄⠀⠀⣽⣿⣿⣦⡉⢸ 
// ⢁⣾⣿⣿⣿⣷⣦⣀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣦⣄⡀⣀⣀⣴⣿⣿⣿⣿⣇⠹ 
// ⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠉⠀⠀⠉⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤ 
// ⣿⣟⡻⠿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢛⣿ 
// ⣿⣟⣻⣷⣾⣿⣿⣿⣿⣿⣿⣿⡿⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣵⣿⣟⣻ 
// ⣿⡿⣿⣿⣿⣿⠿⣿⣿⣿⠟⢋⣠⣤⣤⣀⡙⠛⠻⠿⣿⠿⠿⣩⣿⣿⣿⣟⣻⣿ 
// ⣿⣿⣿⣿⣿⣿⣦⣤⣉⣠⣶⣿⣿⣿⣿⣿⣿⣷⣦⣄⡀⠀⠀⣨⣿⣿⣿⣿⣿⣿ 
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⡿⣿⣿⣿⠿⠿⣭⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇ 
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣤⣤⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀