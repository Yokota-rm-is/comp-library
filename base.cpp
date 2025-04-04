#pragma once

#include <bits/stdc++.h>
// #include <atcoder/all>
#if __has_include(<boost/algorithm/string.hpp>)
#include <boost/algorithm/string.hpp>
#endif
#if __has_include(<boost/algorithm/cxx11/all_of.hpp>)
#include <boost/algorithm/cxx11/all_of.hpp>
#include <boost/algorithm/cxx11/any_of.hpp>
#include <boost/algorithm/cxx11/none_of.hpp>
#include <boost/algorithm/cxx11/one_of.hpp>
#endif
#if __has_include(<boost/lambda/lambda.hpp>)
#include <boost/lambda/lambda.hpp>
#endif
#if __has_include(<boost/range/irange.hpp>)
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>
#endif
#if __has_include(<boost/multiprecision/cpp_int.hpp>)
#include <boost/multiprecision/cpp_int.hpp>
#endif
#if __has_include(<gmpxx.h>)
#include <gmpxx.h>
#endif

using namespace std;

// constant values
const int INF32 = numeric_limits<int>::max(); //2.147483647×10^{9}:32bit整数のinf
const int inf32 = INF32 / 2;
const long long INF64 = numeric_limits<long long>::max(); //9.223372036854775807×10^{18}:64bit整数のinf
const long long inf64 = INF64 / 4;
const double EPS = numeric_limits<double>::epsilon(); //問題による
// const int MOD = 998244353; //問題による

#ifdef LOCAL
bool DEBUG = true;
#else
bool DEBUG = false;
#endif

// REP macro
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) REP2(i, 0, n)
#define REP2(i, l, r) for (long long i = (l); (i) < (long long)(r); ++(i))
#define REP3(i, l, r, s) for (long long i = (l); (i) < (long long)(r); (i) += (s))
#define rep(i, ...) OVERLOAD_REP(__VA_ARGS__, REP3, REP2, REP1)(i, __VA_ARGS__)

#define REPD1(i, n) REPD2(i, 0, n)
#define REPD2(i, l, r) for (long long i = (long long)(r) - 1; (i) >= (long long)(l); --(i))
#define REPD3(i, l, r, s) for (long long i = (long long)(r) - 1; (i) >= (long long)(l); (i) -= (s))
#define repd(i, ...) OVERLOAD_REP(__VA_ARGS__, REPD3, REPD2, REPD1)(i, __VA_ARGS__)

#define fore(i, I) for (auto& i: (I))
#define fored(i, I) for (auto& i: (I) | views::reverse)
#define ALL(A) A.begin(), A.end()

// for debug
#define OVERLOAD_DEBUG(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, name, ...) name
#define DUMP1(a) if (DEBUG) {cerr << "line: " << __LINE__ << ", " << #a << ": "; dump(a); cerr << endl;};
#define DUMP2(a, ...) if (DEBUG) {DUMP1(a); DUMP1(__VA_ARGS__);};
#define DUMP3(a, ...) if (DEBUG) {DUMP1(a); DUMP2(__VA_ARGS__);};
#define DUMP4(a, ...) if (DEBUG) {DUMP1(a); DUMP3(__VA_ARGS__);};
#define DUMP5(a, ...) if (DEBUG) {DUMP1(a); DUMP4(__VA_ARGS__);};
#define DUMP6(a, ...) if (DEBUG) {DUMP1(a); DUMP5(__VA_ARGS__);};
#define DUMP7(a, ...) if (DEBUG) {DUMP1(a); DUMP6(__VA_ARGS__);};
#define DUMP8(a, ...) if (DEBUG) {DUMP1(a); DUMP7(__VA_ARGS__);};
#define DUMP9(a, ...) if (DEBUG) {DUMP1(a); DUMP8(__VA_ARGS__);};
#define DUMP10(a, ...) if (DEBUG) {DUMP1(a); DUMP9(__VA_ARGS__);};
#define debug(...) OVERLOAD_DEBUG(__VA_ARGS__, DUMP10, DUMP9, DUMP8, DUMP7, DUMP6, DUMP5, DUMP4, DUMP3, DUMP2, DUMP1)(__VA_ARGS__)

// 省略
using ushort = unsigned short;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using lll = __int128_t;
using ulll = __uint128_t;
using vll = vector<ll>;
using setll = set<ll>;
using mapll = map<ll, ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
template<typename T> using vec = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vvll = vector<vector<long long>>;
template<typename T> using vvv = vector<vector<vector<T>>>;
using str = string;
using vstr = vector<str>;
using sstr = set<str>;
using vchar = vector<char>;
using schar = set<char>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
template<typename T> using priority_queue_greater = priority_queue<T, vector<T>, greater<T>>;

// boost関連
#if __has_include(<boost/algorithm/cxx11/all_of.hpp>)
using boost::algorithm::all_of_equal;
using boost::algorithm::any_of_equal;
using boost::algorithm::none_of_equal;
using boost::algorithm::one_of_equal;
#endif
#if __has_include(<boost/lambda/lambda.hpp>)
using boost::lambda::_1;
using boost::lambda::_2;
using boost::lambda::_3;
#endif
#if __has_include(<boost/multiprecision/cpp_int.hpp>)
using namespace boost::multiprecision;
#endif
#if __has_include(<gmpxx.h>)
#include <gmpxx.h>
using mpz = mpz_class;
#endif

// 出力ストリーム演算子
template<typename T, typename U> ostream& operator<< (ostream& os, pair<T, U>& p);
template<typename T, typename U> ostream& operator<< (ostream& os, const pair<T, U>& p);
template<typename T> ostream& operator<< (ostream& os, vector<T>& v);
template<typename T> ostream& operator<< (ostream& os, const vector<T>& v);
ostream& operator << (ostream& os, vector<string>& v);
ostream& operator << (ostream& os, const vector<string>& v);
template<typename T> ostream& operator<< (ostream& os, vector<vector<T>>& v);
template<typename T> ostream& operator<< (ostream& os, const vector<vector<T>>& v);
template<typename T> ostream& operator<< (ostream& os, vector<stack<T>>& v);
template<typename T> ostream& operator<< (ostream& os, const vector<stack<T>>& v);
template<typename T> ostream& operator<< (ostream& os, vector<queue<T>>& v);
template<typename T> ostream& operator<< (ostream& os, const vector<queue<T>>& v);
template<typename T> ostream& operator<< (ostream& os, vector<deque<T>>& v);
template<typename T> ostream& operator<< (ostream& os, const vector<deque<T>>& v);
template<typename T> ostream& operator<< (ostream& os, vector<vector<vector<T>>>& v);
template<typename T> ostream& operator<< (ostream& os, const vector<vector<vector<T>>>& v);
template<typename T> ostream& operator<< (ostream& os, set<T>& s);
template<typename T> ostream& operator<< (ostream& os, const set<T>& s);
template<typename T, typename U> ostream& operator<< (ostream& os, map<T, U>& m);
template<typename T, typename U> ostream& operator<< (ostream& os, const map<T, U>& m);
template<typename T> ostream& operator<< (ostream& os, queue<T>& que);
template<typename T> ostream& operator<< (ostream& os, const queue<T>& que);
template<typename T> ostream& operator<< (ostream& os, stack<T>& st);
template<typename T> ostream& operator<< (ostream& os, const stack<T>& st);

template<typename T, typename U> ostream& operator << (ostream& os, pair<T, U>& p) { return os << "(" << p.first << ", " << p.second << ")";}
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) { return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream& os, vector<T>& v) { rep(i, v.size()) os << v[i] << ((i + 1 < (long long)v.size()) ? " " : ""); return os;}
template<typename T> ostream& operator << (ostream& os, const vector<T>& v) { rep(i, v.size()) os << v[i] << ((i + 1 < (long long)v.size()) ? " " : ""); return os;}
ostream& operator << (ostream& os, vector<string>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1) ? "\n" : ""); return os;}
ostream& operator << (ostream& os, const vector<string>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1) ? "\n" : ""); return os;}
template<typename T> ostream& operator << (ostream& os, vector<vector<T>>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1 )? "\n" : ""); return os;}
template<typename T> ostream& operator << (ostream& os, const vector<vector<T>>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1 )? "\n" : ""); return os;}
template<typename T> ostream& operator << (ostream& os, vector<stack<T>>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1 )? "\n" : ""); return os;}
template<typename T> ostream& operator << (ostream& os, const vector<stack<T>>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1 )? "\n" : ""); return os;}
template<typename T> ostream& operator << (ostream& os, vector<queue<T>>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1 )? "\n" : ""); return os;}
template<typename T> ostream& operator << (ostream& os, const vector<queue<T>>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1 )? "\n" : ""); return os;}
template<typename T> ostream& operator << (ostream& os, vector<deque<T>>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1 )? "\n" : ""); return os;}
template<typename T> ostream& operator << (ostream& os, const vector<deque<T>>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1 )? "\n" : ""); return os;}
template<typename T> ostream& operator << (ostream& os, vector<vector<vector<T>>>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1) ? "\n\n": ""); return os;}
template<typename T> ostream& operator << (ostream& os, const vector<vector<vector<T>>>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1) ? "\n\n": ""); return os;}
template<typename T> ostream& operator << (ostream& os, set<T>& s) { for (auto it = s.begin(); it != s.end(); ++it) os << *it << ((it != --s.end()) ? " " : ""); return os;}
template<typename T> ostream& operator << (ostream& os, const set<T>& s) { for (auto it = s.begin(); it != s.end(); ++it) os << *it << ((it != --s.end()) ? " " : ""); return os;}
template<typename T, typename U> ostream& operator << (ostream& os, map<T, U>& m) { for (auto it = m.begin(); it != m.end(); ++it) os << it->first << ": " << it->second << (it != --m.end() ? "\n" : ""); return os;}
template<typename T, typename U> ostream& operator << (ostream& os, const map<T, U>& m) { for (auto it = m.begin(); it != m.end(); ++it) os << it->first << ": " << it->second << (it != --m.end() ? "\n" : ""); return os;}
template<typename T> ostream& operator << (ostream& os, queue<T>& que) { queue<T> tmp(que); while(!tmp.empty()) {os << tmp.front() << ((tmp.size() > 0)? " " : "\n"); tmp.pop();}; return os;}
template<typename T> ostream& operator << (ostream& os, const queue<T>& que) { queue<T> tmp(que); while(!tmp.empty()) {os << tmp.front() << ((tmp.size() > 0)? " " : "\n"); tmp.pop();}; return os;}
template<typename T> ostream& operator << (ostream& os, stack<T>& st) { stack<T> tmp(st); while(!tmp.empty()) {os << tmp.top() << ((tmp.size() > 0)? " " : "\n"); tmp.pop();}; return os;}
template<typename T> ostream& operator << (ostream& os, const stack<T>& st) { stack<T> tmp(st); while(!tmp.empty()) {os << tmp.top() << ((tmp.size() > 0)? " " : "\n"); tmp.pop();}; return os;}
ostream& operator<< (ostream& os, __int128_t x) { 
    if (x == 0) return os << '0';
    if (x < 0) {os << '-'; x = -x;}

    string s; 
    for (__int128_t y = x; y > 0; y /= 10) s += (char)('0' + y % 10); 
    reverse(s.begin(), s.end()); 
    return os << s;
}

// デバッグ用
template<typename T> void dump(T a) { cerr << a;}
void dump(vector<string>& a) { cerr << '\n' << a;}
template<typename T> void dump(vector<vector<T>>& a) { cerr << '\n' << a;}
template<typename T> void dump(vector<stack<T>>& a) { cerr << '\n' << a;}
template<typename T> void dump(vector<queue<T>>& a) { cerr << '\n' << a;}
template<typename T> void dump(vector<deque<T>>& a) { cerr << '\n' << a;}

inline string YESNO(bool flag) { return flag ? "YES" : "NO";}
inline string yesno(bool flag) { return flag ? "yes" : "no";}
inline string YesNo(bool flag) { return flag ? "Yes" : "No";}
inline string POSSIBLE(bool flag) { return flag ? "POSSIBLE" : "IMPOSSIBLE";}
inline string Possible(bool flag) { return flag ? "Possible" : "Impossible";}
inline string TakahashiAoki(bool flag) { return flag ? "Takahashi" : "Aoki";}

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template<typename T> inline bool chmin(T &a, const T &b) { return ((a > b) ? (a = b, true) : false);}
template<typename T> inline bool chmax(T &a, const T &b) { return ((a < b) ? (a = b, true) : false);}

#if __cplusplus > 201703L
using ranges::random_access_range;
using ranges::bidirectional_range;
using ranges::forward_range;
using ranges::input_range;
using ranges::range_value_t;
using ranges::iterator_t;
using ranges::borrowed_iterator_t;
using ranges::range_difference_t;

template <input_range R, class Proj = identity, indirect_unary_predicate<projected<iterator_t<R>, Proj>> Pred> constexpr bool all_of(R&& r, Pred pred, Proj proj = {}) { return ranges::all_of(r, pred, proj);};
template <input_range R, class Proj = identity, indirect_unary_predicate<projected<iterator_t<R>, Proj>> Pred> constexpr bool any_of(R&& r, Pred pred, Proj proj = {}) { return ranges::any_of(r, pred, proj);}; 
template <input_range R, class Proj = identity, indirect_unary_predicate<projected<iterator_t<R>, Proj>> Pred> constexpr bool none_of(R&& r, Pred pred, Proj proj = {}) { return ranges::none_of(r, pred, proj);};
template <forward_range R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>, Proj>> Comp = ranges::less> constexpr bool is_sorted(R&& r, Comp comp = {}, Proj proj = {}) { return ranges::is_sorted(r, comp, proj);};
template <forward_range R1, forward_range R2, class Proj1 = identity, class Proj2 = identity, indirect_equivalence_relation<projected<iterator_t<R1>, Proj1>, projected<iterator_t<R2>, Proj2>> Pred = ranges::equal_to> constexpr bool is_permutation(R1&& r1, R2&& r2, Pred pred = {}, Proj1 proj1 = {}, Proj2 proj2 = {}) { return is_permutation(r1, r2, pred, proj1, proj2);}; 
template <forward_range R, class T, class Proj = identity, indirect_strict_weak_order<const T*, projected<iterator_t<R>, Proj>> Comp = ranges::less> constexpr borrowed_iterator_t<R> lower_bound(R&& r, const T& value, Comp comp = {}, Proj proj = {}) { return ranges::lower_bound(r, value, comp, proj);}; 
template <forward_range R, class T, class Proj = identity, indirect_strict_weak_order<const T*, projected<iterator_t<R>, Proj>> Comp = ranges::less> constexpr borrowed_iterator_t<R> upper_bound(R&& r, const T& value, Comp comp = {}, Proj proj = {}) { return ranges::upper_bound(r, value, comp, proj);};
template <input_range R, weakly_incrementable O, class Gen> O sample(R&& r, O out, range_difference_t<R> n, Gen&& g) {return ranges::sample(r, out, n, g);};
template <input_range R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>, Proj>> Comp = ranges::less> constexpr range_value_t<R> max(R&& r, Comp comp = {}, Proj proj = {}) { return ranges::max(r, comp, proj);};
template <input_range R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>, Proj>> Comp = ranges::less> constexpr range_value_t<R> min(R&& r, Comp comp = {}, Proj proj = {}) { return ranges::min(r, comp, proj);};
template <input_range R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>, Proj>> Comp = ranges::less> constexpr ranges::minmax_result<range_value_t<R>> minmax(R&& r, Comp comp = {}, Proj proj = {}) { return ranges::minmax(r, comp, proj);};
template <forward_range R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>, Proj>> Comp = ranges::less> constexpr borrowed_iterator_t<R> max_element(R&& r, Comp comp = {}, Proj proj = {}) { return ranges::max_element(r, comp, proj);};
template <forward_range R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>, Proj>> Comp = ranges::less> constexpr borrowed_iterator_t<R> min_element(R&& r, Comp comp = {}, Proj proj = {}) { return ranges::min_element(r, comp, proj);};
template <forward_range R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>, Proj>> Comp = ranges::less> constexpr ranges::minmax_element_result<borrowed_iterator_t<R>> minmax_element(R&& r, Comp comp = {}, Proj proj = {}) { return ranges::minmax_element(r, comp, proj);};
template <bidirectional_range R, class Comp = ranges::less, class Proj = identity> constexpr ranges::next_permutation_result<borrowed_iterator_t<R>> next_permutation(R&& r, Comp comp = {}, Proj proj = {}) {return ranges::next_permutation(r, comp, proj);}; 
template <bidirectional_range R, class Comp = ranges::less, class Proj = identity> constexpr ranges::prev_permutation_result<borrowed_iterator_t<R>> prev_permutation(R&& r, Comp comp = {}, Proj proj = {}) {return ranges::prev_permutation(r, comp, proj);}; 
template <random_access_range R, class Comp = ranges::less, class Proj = identity> constexpr borrowed_iterator_t<R> sort(R&& r, Comp comp = {}, Proj proj = {}) { return ranges::sort(r, comp, proj);};
template <random_access_range R, class Comp = ranges::less, class Proj = identity> constexpr borrowed_iterator_t<R> stable_sort(R&& r, Comp comp = {}, Proj proj = {}) { return ranges::stable_sort(r, comp, proj);};
template <bidirectional_range R> constexpr borrowed_iterator_t<R> reverse(R&& r) { return ranges::reverse(r);};

#else
template<typename T> inline void sort(vector<T>& A) { sort(A.begin(), A.end());}
template<typename T> inline void reverse(vector<T>& A) { reverse(A.begin(), A.end());}
inline void reverse(string &s) { reverse(s.begin(), s.end());}
template<typename T> inline T min(const vector<T>& A) { return *min_element(A.begin(), A.end());}
template<typename T> inline T max(const vector<T>& A) { return *max_element(A.begin(), A.end());}

#endif

template<typename T> T accumulate(vector<T> A) { return accumulate(A.begin(), A.end(), T(0));}
template<typename T> inline size_t min_index(const vector<T>& A) { return distance(A.begin(), min_element(A.begin(), A.end()));}
template<typename T> inline size_t max_index(const vector<T>& A) { return distance(A.begin(), max_element(A.begin(), A.end()));}

// math関係
inline long long min(long long x, int y) {return min(x, (long long)y);}
inline long long min(int x, long long y) {return min((long long)x, y);}
inline long long max(long long x, int y) {return max(x, (long long)y);}
inline long long max(int x, long long y) {return max((long long)x, y);}
inline long long ceil(long long x, long long y) { return x / y + (x % y > 0);}
inline long long floor(long long x, long long y) { return x / y - (x % y < 0);}
pair<long long, long long> divmod(long long x, long long y) {return ((x >= 0) ? pll(x / y, x % y) : pll((x - y + 1) / y, (x % y + y) % y));}
template <typename T = unsigned long long> inline T binpow(T x, T n) { T ret = 1; while (n) {if (n & 1) ret *= x; x *= x; n >>= 1;} return ret; }
template <typename T = unsigned long long> inline T binpow(T x, T n, T m) { T ret = 1; while (n) {if (n & 1) ret = (ret * x) % m; x = (x * x) % m; n >>= 1;} return ret; }
// mod. m での a の逆元 a^{-1} を計算する
template<typename T> T modinv(T a, T m) {
    T b = m, u = 1, v = 0;
    while (b) { T t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
    u %= m;
    if (u < 0) u += m;
    return u;
}
// combinationを求める
long long nCr(long long n, long long k, long long m = 0) {
    if (n < k) return 0;
    if (n - k < k) k = n - k;
    long long ret = 1;
    rep(i, k) {
        ret *= (n - i);
        if (m > 0) ret %= m;
    }
    rep(i, 1, k + 1) {
        if (m > 0) {
            ret *= modinv(i, m);
            ret %= m;
        } 
        else ret /= i;
    }
    return ret;
}

// 最大公約数を求める
long long gcd(const vector<long long> &A) {
    long long ret = 0;
    rep(i, A.size()) ret = gcd(ret, A[i]);
    return ret;
}
// 最小公倍数を求める
long long lcm(const vector<long long> &A, const long long m = 0) { 
    long long ret = 1;
    rep(i, A.size()) { ret = lcm(ret, A[i]); if (m > 0) ret %= m;}
    return ret;
}
// 拡張ユークリッドの互除法
tuple<long long, long long, long long> extGCD(long long a, long long b) {
    if (b == 0) return {a, 1, 0};
    auto [g, x, y] = extGCD(b, a % b);
    return {g, y, x - (a / b) * y};
}

// 分数比較
inline bool is_greater(long long p, long long q, long long r, long long s) { return __int128_t(p) * s > __int128_t(q) * r;}
inline bool is_greater_or_equal(long long p, long long q, long long r, long long s) { return __int128_t(p) * s >= __int128_t(q) * r;}
inline bool is_less(long long p, long long q, long long r, long long s) { return __int128_t(p) * s < __int128_t(q) * r;}
inline bool is_less_or_equal(long long p, long long q, long long r, long long s) { return __int128_t(p) * s <= __int128_t(q) * r;}
#if __has_include(<boost/multiprecision/cpp_int.hpp>)
inline bool is_greater(__int128_t p, __int128_t q, __int128_t r, __int128_t s) { return int256_t(p) * s > int256_t(q) * r;}
inline bool is_greater_or_equal(__int128_t p, __int128_t q, __int128_t r, __int128_t s) { return int256_t(p) * s >= int256_t(q) * r;}
inline bool is_less(__int128_t p, __int128_t q, __int128_t r, __int128_t s) { return int256_t(p) * s < int256_t(q) * r;}
inline bool is_less_or_equal(__int128_t p, __int128_t q, __int128_t r, __int128_t s) { return int256_t(p) * s <= int256_t(q) * r;}
#endif

// string関係
inline string lltos(long long x) { return to_string(x);}
inline int ctoi(char x) { return int(x - '0');}
inline char itoc(int x) { return (char)(x + '0');}
#if __has_include(<boost/algorithm/string.hpp>)
inline string to_upper(string& S) { return boost::to_upper_copy(S);}
inline string to_lower(string& S) { return boost::to_lower_copy(S);}
#endif
inline bool is_lower(char c) { return (c >= 'a') and (c <= 'z');}
inline bool is_upper(char c) { return (c >= 'A') and (c <= 'Z');}
inline char to_upper(char c) { if (is_upper(c)) return c; else return c + 'A' - 'a';}
inline char to_lower(char c) { if (is_lower(c)) return c; else return c + 'a' - 'A';}
inline string zero_padding(string N, long long width) {
    stringstream ss;
    ss << setw(width) << setfill('0') << N;
    return ss.str();
}
inline string zero_padding(long long N, long long width) { return zero_padding(lltos(N), width);}
inline string to_n_base(long long x, long long base) {
    assert(2 <= base and base <= 36);
    if (x == 0) return "0";
    string ret;
    for (; x > 0; x /= base) ret += (((x % base) < 10) ? '0' + (x % base) : 'a' + (x % base) - 10);
    reverse(ret);
    return ret;
}
inline long long to_decimal(string S, long long base) {
    assert(2 <= base and base <= 36);
    long long ret = 0, x = 1;
    repd(i, S.size()) {
        ret += (long long)(('0' <= S[i] and S[i] <= '9') ? S[i] - '0' : (('a' <= S[i] and S[i] <= 'z') ? S[i] = 'a' + 10 : S[i] - 'A' + 10)) * x;
        x *= base;
    }
    return ret;
}
bool is_palindrome(const string& S) {
    rep(i, S.size() / 2) if (S[i] != S[S.size() - i - 1]) return false;
    return true;
}

template<class T = long long> inline pair<T, T> DRUL(T y, T x, char c) { return {((c == 'D') ? y + 1 : ((c == 'U') ? y - 1 : y)), ((c == 'R') ? x + 1 : ((c == 'L') ? x - 1 : x))};}
template <typename T> long long bubble_sort(vector<T> &A) {
    ll ret = 0;
    rep(i, A.size() - 1) rep(j, A.size() - 1) if (A[j] > A[j + 1]) {
        swap(A[j], A[j + 1]);
        ++ret;
    } 
    return ret;
}

template<typename T> vector<T> compress(const vector<T> &A, bool unique_id = false) {
    long long N = A.size();
    vector<pair<T, long long>> B;
    rep(i, N) B.emplace_back(A[i], i);
    sort(B.begin(), B.end());
    vector<T> C(N);
    ll count = 0;
    rep(i, N) {
        C[B[i].second] = count;
        if (unique_id)++count;
        else if (i < N - 1 and B[i].first != B[i + 1].first) ++count;
    } 
    return C;
}

// bit関係
bool bit_test(long long x, long long pos) { return (x >> pos) & 1ll; }
long long bit_set(long long x, long long pos, bool flg) { return flg ? (x | (1ll << pos)) : (x & ~(1ll << pos)); }
long long bit_flip(long long x, long long pos) { return x ^ (1ll << pos); }
#if __cplusplus > 201703L
long long bit_count(long long x) { return popcount((ull)x); }
#else 
long long bit_count(long long x) { return __builtin_popcountll(x); }
#endif

// 配列関係
// キー以上の最小の要素を見つけるイテレータを返す関数
template <typename T> inline typename vector<T>::iterator find_greater_than_or_equal(vector<T>& v, T key) { return lower_bound(v.begin(), v.end(), key); }
template <typename T> inline typename vector<T>::iterator find_greater_than_or_equal(typename vector<T>::iterator begin, typename vector<T>::iterator end, T key) { return lower_bound(begin, end, key); }
template <typename T> inline typename set<T>::iterator find_greater_than_or_equal(set<T>& st, T key) { return st.lower_bound(key); }
// キーを超える最小の要素を見つけるイテレータを返す関数
template <typename T> inline typename vector<T>::iterator find_greater_than(vector<T>& v, T key) { return upper_bound(v.begin(), v.end(), key); }
template <typename T> inline typename vector<T>::iterator find_greater_than(typename vector<T>::iterator begin, typename vector<T>::iterator end, T key) { return upper_bound(begin, end, key); }
template <typename T> inline typename set<T>::iterator find_greater_than(set<T>& st, T key) { return st.upper_bound(key); }
// キー以下の最大の要素を見つけるイテレータを返す関数, ない場合はendを返す
template <typename T> inline typename vector<T>::iterator find_less_than_or_equal(vector<T>& v, T key) { auto it = upper_bound(v.begin(), v.end(), key); return it == v.begin() ? v.end() : --it;}
template <typename T> inline typename vector<T>::iterator find_less_than_or_equal(typename vector<T>::iterator begin, typename vector<T>::iterator end, T key) { auto it = upper_bound(begin, end, key); return it == begin ? end : --it;}
template <typename T> inline typename set<T>::iterator find_less_than_or_equal(set<T>& st, T key) { auto it = st.upper_bound(key); return it == st.begin() ? st.end() : --it;}
// キー未満の最大の要素を見つけるイテレータを返す関数, ない場合はendを返す
template <typename T> inline typename vector<T>::iterator find_less_than(vector<T>& v, T key) { auto it = lower_bound(v.begin(), v.end(), key); return it == v.begin() ? v.end() : --it; }
template <typename T> inline typename vector<T>::iterator find_less_than(typename vector<T>::iterator begin, typename vector<T>::iterator end, T key) { auto it = lower_bound(begin, end, key); return it == begin ? end : --it; }
template <typename T> inline typename set<T>::iterator find_less_than(set<T>& st, T key) { auto it = st.lower_bound(key); return it == st.begin() ? st.end() : --it;}

template <typename T> auto operator+(const vector<T>& A, const T x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i] = A[i] + x; return ret; }
template <typename T> auto operator-(const vector<T>& A, const T x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i] = A[i] - x; return ret; }
template <typename T> auto operator*(const vector<T>& A, const T x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i] = A[i] * x; return ret; }
template <typename T> auto operator/(const vector<T>& A, const T x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i] = A[i] / x; return ret; }
template <typename T> auto operator%(const vector<T>& A, const T x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i] = A[i] % x; return ret; }
template <typename T> auto binpow(const vector<T>& A, const T x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i] = binpow(A[i], x); return ret; }

template <typename R> auto& operator++(R& a) { for (auto& x : a) ++x; return a; }
template <typename R> auto operator++(R& a, int) { auto temp = a; for (auto& x : a) x++; return temp; }
template <typename R> auto& operator--(R& a) { for (auto& x : a) --x; return a; }
template <typename R> auto operator--(R& a, int) { auto temp = a; for (auto& x : a) x--; return temp; }

template <typename T, typename U> auto operator+(const pair<T, U>& p, const T x) { return pair<T, U>(p.first + x, p.second + x); }
template <typename T, typename U> auto operator-(const pair<T, U>& p, const T x) { return pair<T, U>(p.first - x, p.second - x); }
template <typename T, typename U> auto operator*(const pair<T, U>& p, const T x) { return pair<T, U>(p.first * x, p.second * x); }
template <typename T, typename U> auto operator/(const pair<T, U>& p, const T x) { return pair<T, U>(p.first / x, p.second / x); }
template <typename T, typename U> auto operator%(const pair<T, U>& p, const T x) { return pair<T, U>(p.first % x, p.second % x); }
template <typename T, typename U> auto binpow(const pair<T, U>& p, const T x) { return pair<T, U>(binpow(p.first, x), binpow(p.second, x)); }

template <typename T, typename U> auto operator+(const pair<T, U>& p, const pair<T, U>& q) { return pair<T, U>(p.first + q.first, p.second + q.second); }
template <typename T, typename U> auto operator-(const pair<T, U>& p, const pair<T, U>& q) { return pair<T, U>(p.first - q.first, p.second - q.second); }
template <typename T, typename U> auto operator*(const pair<T, U>& p, const pair<T, U>& q) { return pair<T, U>(p.first * q.first, p.second * q.second); }
template <typename T, typename U> auto operator/(const pair<T, U>& p, const pair<T, U>& q) { return pair<T, U>(p.first / q.first, p.second / q.second); }
template <typename T, typename U> auto operator%(const pair<T, U>& p, const pair<T, U>& q) { return pair<T, U>(p.first % q.first, p.second % q.second); }

template <typename T, typename U> auto& operator++(pair<T, U>& p) { ++p.first; ++p.second; return p; }
template <typename T, typename U> auto operator++(pair<T, U>& p, int) { auto temp = p; ++p.first; ++p.second; return temp; }
template <typename T, typename U> auto& operator--(pair<T, U>& p) { --p.first; --p.second; return p; }
template <typename T, typename U> auto operator--(pair<T, U>& p, int) { auto temp = p; --p.first; --p.second; return temp; }

template<typename T, typename U> vector<pair<T, U>> to_pair(const vector<T>& vec1, const vector<U>& vec2) {
    size_t n = min(vec1.size(), vec2.size());
    vector<pair<T, U>> result(n);
    for(size_t i = 0; i < n; ++i) result.emplace_back(vec1[i], vec2[i]);
    return result;
}