---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.cpp
    title: base.cpp
  - icon: ':heavy_check_mark:'
    path: structure/dualsegmenttree.cpp
    title: structure/dualsegmenttree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D&
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D&
  bundledCode: "#line 1 \"test/structure/dualsegmenttree/aoj-dsl-2-d.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D&\"\
    \n\n#line 2 \"base.cpp\"\n\n#include <bits/stdc++.h>\n// #include <atcoder/all>\n\
    #if __has_include(<boost/algorithm/string.hpp>)\n#include <boost/algorithm/string.hpp>\n\
    #endif\n#if __has_include(<boost/algorithm/cxx11/all_of.hpp>)\n#include <boost/algorithm/cxx11/all_of.hpp>\n\
    #include <boost/algorithm/cxx11/any_of.hpp>\n#include <boost/algorithm/cxx11/none_of.hpp>\n\
    #include <boost/algorithm/cxx11/one_of.hpp>\n#endif\n#if __has_include(<boost/lambda/lambda.hpp>)\n\
    #include <boost/lambda/lambda.hpp>\n#endif\n#if __has_include(<boost/range/irange.hpp>)\n\
    #include <boost/range/irange.hpp>\n#include <boost/range/adaptors.hpp>\n#endif\n\
    #if __has_include(<boost/multiprecision/cpp_int.hpp>)\n#include <boost/multiprecision/cpp_int.hpp>\n\
    #endif\n#if __has_include(<gmpxx.h>)\n#include <gmpxx.h>\n#endif\n\nusing namespace\
    \ std;\n\n// constant values\nconst int INF32 = numeric_limits<int>::max(); //2.147483647\xD7\
    10^{9}:32bit\u6574\u6570\u306Einf\nconst int inf32 = INF32 / 2;\nconst long long\
    \ INF64 = numeric_limits<long long>::max(); //9.223372036854775807\xD710^{18}:64bit\u6574\
    \u6570\u306Einf\nconst long long inf64 = INF64 / 2;\nconst double EPS = numeric_limits<double>::epsilon();\
    \ //\u554F\u984C\u306B\u3088\u308B\n// const int MOD = 998244353; //\u554F\u984C\
    \u306B\u3088\u308B\n\n#ifdef LOCAL\nbool DEBUG = true;\n#else\nbool DEBUG = false;\n\
    #endif\n\n// REP macro\n#define OVERLOAD_REP(_1, _2, _3, name, ...) name\n#define\
    \ REP1(i, n) REP2(i, 0, n)\n#define REP2(i, l, r) for (long long i = (l); (i)\
    \ < (long long)(r); ++(i))\n#define REP3(i, l, r, s) for (long long i = (l); (i)\
    \ < (long long)(r); (i) += (s))\n#define rep(i, ...) OVERLOAD_REP(__VA_ARGS__,\
    \ REP3, REP2, REP1)(i, __VA_ARGS__)\n\n#define REPD1(i, n) REPD2(i, 0, n)\n#define\
    \ REPD2(i, l, r) for (long long i = (long long)(r) - 1; (i) >= (long long)(l);\
    \ --(i))\n#define REPD3(i, l, r, s) for (long long i = (long long)(r) - 1; (i)\
    \ >= (long long)(l); (i) -= (s))\n#define repd(i, ...) OVERLOAD_REP(__VA_ARGS__,\
    \ REPD3, REPD2, REPD1)(i, __VA_ARGS__)\n\n#define fore(i, I) for (auto& i: (I))\n\
    #define fored(i, I) for (auto& i: (I) | views::reverse)\n#define all(A) A.begin(),\
    \ A.end()\n\n// for debug\n#define OVERLOAD_DEBUG(_1, _2, _3, _4, _5, name, ...)\
    \ name\n#define DUMP1(a) if (DEBUG) {cerr << \"line: \" << __LINE__ << \", \"\
    \ << #a << \": \"; dump(a); cerr << endl;};\n#define DUMP2(a, b) if (DEBUG) {DUMP1(a);\
    \ DUMP1(b)};\n#define DUMP3(a, b, c) if (DEBUG) {DUMP1(a); DUMP2(b, c)};\n#define\
    \ DUMP4(a, b, c, d) if (DEBUG) {DUMP1(a); DUMP3(b, c, d)};\n#define DUMP5(a, b,\
    \ c, d, e) if (DEBUG) {DUMP1(a); DUMP4(b, c, d, e)};\n#define debug(...) OVERLOAD_DEBUG(__VA_ARGS__,\
    \ DUMP5, DUMP4, DUMP3, DUMP2, DUMP1)(__VA_ARGS__)\n\n// \u7701\u7565\nusing ll\
    \ = long long;\nusing ull = unsigned long long;\nusing vll = vector<ll>;\nusing\
    \ setll = set<ll>;\nusing mapll = map<ll, ll>;\nusing pll = pair<ll, ll>;\ntemplate<typename\
    \ T> using vec = vector<T>;\ntemplate<typename T> using vv = vector<vector<T>>;\n\
    using vvll = vector<vector<long long>>;\ntemplate<typename T> using vvv = vector<vector<vector<T>>>;\n\
    using str = string;\nusing vstr = vector<str>;\nusing sstr = set<str>;\nusing\
    \ vchar = vector<char>;\nusing schar = set<char>;\nusing vd = vector<double>;\n\
    using vvd = vector<vector<double>>;\nusing vb = vector<bool>;\nusing vvb = vector<vector<bool>>;\n\
    \n// boost\u95A2\u9023\n#if __has_include(<boost/algorithm/cxx11/all_of.hpp>)\n\
    using boost::algorithm::all_of_equal;\nusing boost::algorithm::any_of_equal;\n\
    using boost::algorithm::none_of_equal;\nusing boost::algorithm::one_of_equal;\n\
    #endif\n#if __has_include(<boost/lambda/lambda.hpp>)\nusing boost::lambda::_1;\n\
    using boost::lambda::_2;\nusing boost::lambda::_3;\n#endif\n#if __has_include(<boost/multiprecision/cpp_int.hpp>)\n\
    using namespace boost::multiprecision;\nusing lll = int128_t;\n#endif\n#if __has_include(<gmpxx.h>)\n\
    #include <gmpxx.h>\nusing mpz = mpz_class;\n#endif\n\n// \u51FA\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\u6F14\u7B97\u5B50\ntemplate<typename T, typename U> ostream&\
    \ operator<< (ostream& os, pair<T, U>& p);\ntemplate<typename T, typename U> ostream&\
    \ operator<< (ostream& os, const pair<T, U>& p);\ntemplate<typename T> ostream&\
    \ operator<< (ostream& os, vector<T>& v);\ntemplate<typename T> ostream& operator<<\
    \ (ostream& os, const vector<T>& v);\nostream& operator << (ostream& os, vector<string>&\
    \ v);\nostream& operator << (ostream& os, const vector<string>& v);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, vector<vector<T>>& v);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, const vector<vector<T>>& v);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, vector<vector<vector<T>>>& v);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, const vector<vector<vector<T>>>& v);\n\
    template<typename T> ostream& operator<< (ostream& os, set<T>& s);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, const set<T>& s);\ntemplate<typename T,\
    \ typename U> ostream& operator<< (ostream& os, map<T, U>& m);\ntemplate<typename\
    \ T, typename U> ostream& operator<< (ostream& os, const map<T, U>& m);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, queue<T>& que);\ntemplate<typename T> ostream&\
    \ operator<< (ostream& os, const queue<T>& que);\ntemplate<typename T> ostream&\
    \ operator<< (ostream& os, stack<T>& st);\ntemplate<typename T> ostream& operator<<\
    \ (ostream& os, const stack<T>& st);\n\ntemplate<typename T, typename U> ostream&\
    \ operator << (ostream& os, pair<T, U>& p) { return os << \"(\" << p.first <<\
    \ \", \" << p.second << \")\";}\ntemplate<typename T, typename U> ostream& operator\
    \ << (ostream& os, const pair<T, U>& p) { return os << \"(\" << p.first << \"\
    , \" << p.second << \")\";}\ntemplate<typename T> ostream& operator << (ostream&\
    \ os, vector<T>& v) { rep(i, v.size()) os << v[i] << ((i + 1 < (long long)v.size())\
    \ ? \" \" : \"\"); return os;}\ntemplate<typename T> ostream& operator << (ostream&\
    \ os, const vector<T>& v) { rep(i, v.size()) os << v[i] << ((i + 1 < (long long)v.size())\
    \ ? \" \" : \"\"); return os;}\nostream& operator << (ostream& os, vector<string>&\
    \ v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1) ? \"\\n\"\
    \ : \"\"); return os;}\nostream& operator << (ostream& os, const vector<string>&\
    \ v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1) ? \"\\n\"\
    \ : \"\"); return os;}\ntemplate<typename T> ostream& operator << (ostream& os,\
    \ vector<vector<T>>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size()\
    \ - 1 )? \"\\n\" : \"\"); return os;}\ntemplate<typename T> ostream& operator\
    \ << (ostream& os, const vector<vector<T>>& v) { rep(i, v.size()) os << v[i] <<\
    \ ((i < (long long)v.size() - 1 )? \"\\n\" : \"\"); return os;}\ntemplate<typename\
    \ T> ostream& operator << (ostream& os, vector<vector<vector<T>>>& v) { rep(i,\
    \ v.size()) os << v[i] << ((i < (long long)v.size() - 1) ? \"\\n\\n\": \"\");\
    \ return os;}\ntemplate<typename T> ostream& operator << (ostream& os, const vector<vector<vector<T>>>&\
    \ v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1) ? \"\\n\\\
    n\": \"\"); return os;}\ntemplate<typename T> ostream& operator << (ostream& os,\
    \ set<T>& s) { for (auto it = s.begin(); it != s.end(); ++it) os << *it << ((it\
    \ != --s.end()) ? \" \" : \"\"); return os;}\ntemplate<typename T> ostream& operator\
    \ << (ostream& os, const set<T>& s) { for (auto it = s.begin(); it != s.end();\
    \ ++it) os << *it << ((it != --s.end()) ? \" \" : \"\"); return os;}\ntemplate<typename\
    \ T, typename U> ostream& operator << (ostream& os, map<T, U>& m) { for (auto\
    \ it = m.begin(); it != m.end(); ++it) os << it->first << \": \" << it->second\
    \ << (it != --m.end() ? \"\\n\" : \"\"); return os;}\ntemplate<typename T, typename\
    \ U> ostream& operator << (ostream& os, const map<T, U>& m) { for (auto it = m.begin();\
    \ it != m.end(); ++it) os << it->first << \": \" << it->second << (it != --m.end()\
    \ ? \"\\n\" : \"\"); return os;}\ntemplate<typename T> ostream& operator << (ostream&\
    \ os, queue<T>& que) { queue<T> tmp(que); while(!tmp.empty()) {os << tmp.front()\
    \ << ((tmp.size() > 1)? \"\\n\" : \"\"); tmp.pop();}; return os;}\ntemplate<typename\
    \ T> ostream& operator << (ostream& os, const queue<T>& que) { queue<T> tmp(que);\
    \ while(!tmp.empty()) {os << tmp.front() << ((tmp.size() > 1)? \"\\n\" : \"\"\
    ); tmp.pop();}; return os;}\ntemplate<typename T> ostream& operator << (ostream&\
    \ os, stack<T>& st) { stack<T> tmp(st); while(!tmp.empty()) {os << tmp.top() <<\
    \ ((tmp.size() > 1)? \"\\n\" : \"\"); tmp.pop();}; return os;}\ntemplate<typename\
    \ T> ostream& operator << (ostream& os, const stack<T>& st) { stack<T> tmp(st);\
    \ while(!tmp.empty()) {os << tmp.top() << ((tmp.size() > 1)? \"\\n\" : \"\");\
    \ tmp.pop();}; return os;}\n\n// \u30C7\u30D0\u30C3\u30B0\u7528\ntemplate<typename\
    \ T> void dump(T a) { cerr << a;}\nvoid dump(vector<string>& a) { cerr << '\\\
    n' << a;}\ntemplate<typename T> void dump(vector<vector<T>>& a) { cerr << '\\\
    n' << a;}\n\n// input\ntemplate<typename T> inline void input(T& a) {cin >> a;}\n\
    template<typename T, typename... Args> inline void input(T& a, Args&&... args)\
    \ { cin >> a; input(args...);}\ntemplate<typename T> inline void input(vector<T>&\
    \ A) { rep(i, A.size()) cin >> A[i];}\ntemplate<typename T> inline void input(vector<T>&\
    \ A, vector<T>& B) { assert(A.size() == B.size());rep(i, A.size()) cin >> A[i]\
    \ >> B[i];}\ntemplate<typename T> inline void input(vector<T>& A, vector<T>& B,\
    \ vector<T>& C) { assert(A.size() == B.size() and A.size() == C.size()); rep(i,\
    \ A.size()) cin >> A[i] >> B[i] >> C[i];}\ntemplate<typename T> inline void input(const\
    \ long long N, vector<T>& A) { A.resize(N); rep(i, N) cin >> A[i];}\ntemplate<typename\
    \ T> inline void input(const long long N, vector<T>& A, vector<T>& B) { A.resize(N);\
    \ B.resize(N); rep(i, N) cin >> A[i] >> B[i];}\ntemplate<typename T> inline void\
    \ input(const long long N, vector<T>& A, vector<T>& B, vector<T>& C) { A.resize(N);\
    \ B.resize(N); C.resize(N); rep(i, A.size()) cin >> A[i] >> B[i] >> C[i];}\ntemplate<typename\
    \ T> inline void input(const long long N, set<T>& A) {rep(i, N) { T a; cin >>\
    \ a; A.insert(a);}}\ntemplate<typename T> inline void input(const long long N,\
    \ set<T>& A, set<T>& B) { rep(i, N) {T a, b; cin >> a >> b; A.insert(a); B.insert(b);}}\n\
    template<typename T> inline void input(const long long N, set<T>& A, set<T>& B,\
    \ set<T>& C) { rep(i, N) {T a, b, c; cin >> a >> b >> c; A.insert(a); B.insert(b);\
    \ C.insert(c);}}\ntemplate<typename T> inline void input(vector<vector<T>>& A)\
    \ { rep(i, A.size()) input(A[i]);}\n\ninline string YESNO(bool flag) { return\
    \ flag ? \"YES\" : \"NO\";}\ninline string yesno(bool flag) { return flag ? \"\
    yes\" : \"no\";}\ninline string YesNo(bool flag) { return flag ? \"Yes\" : \"\
    No\";}\ninline string POSSIBLE(bool flag) { return flag ? \"POSSIBLE\" : \"IMPOSSIBLE\"\
    ;}\ninline string Possible(bool flag) { return flag ? \"Possible\" : \"Impossible\"\
    ;}\ninline string TakahashiAoki(bool flag) { return flag ? \"Takahashi\" : \"\
    Aoki\";}\n\n// \u7B2C\u4E00\u5F15\u6570\u3068\u7B2C\u4E8C\u5F15\u6570\u3092\u6BD4\
    \u8F03\u3057\u3001\u7B2C\u4E00\u5F15\u6570(a)\u3092\u3088\u308A\u5927\u304D\u3044\
    /\u5C0F\u3055\u3044\u5024\u306B\u4E0A\u66F8\u304D\ntemplate<typename T> inline\
    \ bool chmin(T &a, const T &b) { return ((a > b) ? (a = b, true) : false);}\n\
    template<typename T> inline bool chmax(T &a, const T &b) { return ((a < b) ? (a\
    \ = b, true) : false);}\n\n#if __cplusplus > 201703L\nusing ranges::random_access_range;\n\
    using ranges::bidirectional_range;\nusing ranges::forward_range;\nusing ranges::input_range;\n\
    using ranges::range_value_t;\nusing ranges::iterator_t;\nusing ranges::borrowed_iterator_t;\n\
    using ranges::range_difference_t;\n\ntemplate <input_range R, class Proj = identity,\
    \ indirect_unary_predicate<projected<iterator_t<R>, Proj>> Pred> constexpr bool\
    \ all_of(R&& r, Pred pred, Proj proj = {}) { return ranges::all_of(r, pred, proj);};\n\
    template <input_range R, class Proj = identity, indirect_unary_predicate<projected<iterator_t<R>,\
    \ Proj>> Pred> constexpr bool any_of(R&& r, Pred pred, Proj proj = {}) { return\
    \ ranges::any_of(r, pred, proj);}; \ntemplate <input_range R, class Proj = identity,\
    \ indirect_unary_predicate<projected<iterator_t<R>, Proj>> Pred> constexpr bool\
    \ none_of(R&& r, Pred pred, Proj proj = {}) { return ranges::none_of(r, pred,\
    \ proj);};\ntemplate <forward_range R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>,\
    \ Proj>> Comp = ranges::less> constexpr bool is_sorted(R&& r, Comp comp = {},\
    \ Proj proj = {}) { return ranges::is_sorted(r, comp, proj);};\ntemplate <forward_range\
    \ R1, forward_range R2, class Proj1 = identity, class Proj2 = identity, indirect_equivalence_relation<projected<iterator_t<R1>,\
    \ Proj1>, projected<iterator_t<R2>, Proj2>> Pred = ranges::equal_to> constexpr\
    \ bool is_permutation(R1&& r1, R2&& r2, Pred pred = {}, Proj1 proj1 = {}, Proj2\
    \ proj2 = {}) { return is_permutation(r1, r2, pred, proj1, proj2);}; \ntemplate\
    \ <forward_range R, class T, class Proj = identity, indirect_strict_weak_order<const\
    \ T*, projected<iterator_t<R>, Proj>> Comp = ranges::less> constexpr borrowed_iterator_t<R>\
    \ lower_bound(R&& r, const T& value, Comp comp = {}, Proj proj = {}) { return\
    \ ranges::lower_bound(r, value, comp, proj);}; \ntemplate <forward_range R, class\
    \ T, class Proj = identity, indirect_strict_weak_order<const T*, projected<iterator_t<R>,\
    \ Proj>> Comp = ranges::less> constexpr borrowed_iterator_t<R> upper_bound(R&&\
    \ r, const T& value, Comp comp = {}, Proj proj = {}) { return ranges::upper_bound(r,\
    \ value, comp, proj);};\ntemplate <input_range R, weakly_incrementable O, class\
    \ Gen> O sample(R&& r, O out, range_difference_t<R> n, Gen&& g) {return ranges::sample(r,\
    \ out, n, g);};\ntemplate <input_range R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>,\
    \ Proj>> Comp = ranges::less> constexpr range_value_t<R> max(R&& r, Comp comp\
    \ = {}, Proj proj = {}) { return ranges::max(r, comp, proj);};\ntemplate <input_range\
    \ R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>,\
    \ Proj>> Comp = ranges::less> constexpr range_value_t<R> min(R&& r, Comp comp\
    \ = {}, Proj proj = {}) { return ranges::min(r, comp, proj);};\ntemplate <input_range\
    \ R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>,\
    \ Proj>> Comp = ranges::less> constexpr ranges::minmax_result<range_value_t<R>>\
    \ minmax(R&& r, Comp comp = {}, Proj proj = {}) { return ranges::minmax(r, comp,\
    \ proj);};\ntemplate <forward_range R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>,\
    \ Proj>> Comp = ranges::less> constexpr borrowed_iterator_t<R> max_element(R&&\
    \ r, Comp comp = {}, Proj proj = {}) { return ranges::max_element(r, comp, proj);};\n\
    template <forward_range R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>,\
    \ Proj>> Comp = ranges::less> constexpr borrowed_iterator_t<R> min_element(R&&\
    \ r, Comp comp = {}, Proj proj = {}) { return ranges::min_element(r, comp, proj);};\n\
    template <forward_range R, class Proj = identity, indirect_strict_weak_order<projected<iterator_t<R>,\
    \ Proj>> Comp = ranges::less> constexpr ranges::minmax_element_result<borrowed_iterator_t<R>>\
    \ minmax_element(R&& r, Comp comp = {}, Proj proj = {}) { return ranges::minmax_element(r,\
    \ comp, proj);};\ntemplate <bidirectional_range R, class Comp = ranges::less,\
    \ class Proj = identity> constexpr ranges::next_permutation_result<borrowed_iterator_t<R>>\
    \ next_permutation(R&& r, Comp comp = {}, Proj proj = {}) {return ranges::next_permutation(r,\
    \ comp, proj);}; \ntemplate <bidirectional_range R, class Comp = ranges::less,\
    \ class Proj = identity> constexpr ranges::prev_permutation_result<borrowed_iterator_t<R>>\
    \ prev_permutation(R&& r, Comp comp = {}, Proj proj = {}) {return ranges::prev_permutation(r,\
    \ comp, proj);}; \ntemplate <random_access_range R, class Comp = ranges::less,\
    \ class Proj = identity> constexpr borrowed_iterator_t<R> sort(R&& r, Comp comp\
    \ = {}, Proj proj = {}) { return ranges::sort(r, comp, proj);};\ntemplate <random_access_range\
    \ R, class Comp = ranges::less, class Proj = identity> constexpr borrowed_iterator_t<R>\
    \ stable_sort(R&& r, Comp comp = {}, Proj proj = {}) { return ranges::stable_sort(r,\
    \ comp, proj);};\ntemplate <bidirectional_range R> constexpr borrowed_iterator_t<R>\
    \ reverse(R&& r) { return ranges::reverse(r);};\n\n#else\ntemplate<typename T>\
    \ inline void sort(vector<T>& A) { sort(A.begin(), A.end());}\ntemplate<typename\
    \ T> inline void reverse(vector<T>& A) { reverse(A.begin(), A.end());}\ninline\
    \ void reverse(string &s) { reverse(s.begin(), s.end());}\ntemplate<typename T>\
    \ inline T min(const vector<T>& A) { return *min_element(A.begin(), A.end());}\n\
    template<typename T> inline T max(const vector<T>& A) { return *max_element(A.begin(),\
    \ A.end());}\n\n#endif\n\ntemplate<typename T> T accumulate(vector<T> A) { return\
    \ accumulate(A.begin(), A.end(), T(0));}\ntemplate<typename T> inline size_t min_index(const\
    \ vector<T>& A) { return distance(A.begin(), min_element(A.begin(), A.end()));}\n\
    template<typename T> inline size_t max_index(const vector<T>& A) { return distance(A.begin(),\
    \ max_element(A.begin(), A.end()));}\n\n// math\u95A2\u4FC2\ninline long long\
    \ min(long long x, int y) {return min(x, (long long)y);}\ninline long long min(int\
    \ x, long long y) {return min((long long)x, y);}\ninline long long max(long long\
    \ x, int y) {return max(x, (long long)y);}\ninline long long max(int x, long long\
    \ y) {return max((long long)x, y);}\ninline long long ceil(long long x, long long\
    \ y) { return x / y + (x % y > 0);}\ninline long long floor(long long x, long\
    \ long y) { return x / y - (x % y < 0);}\npair<long long, long long> divmod(long\
    \ long x, long long y) {return ((x >= 0) ? pll(x / y, x % y) : pll((x - y + 1)\
    \ / y, (x % y + y) % y));}\ntemplate<typename T> inline T binpow(T x, T n, T m\
    \ = 0) {\n    T ret = 1;\n    while (n > 0) {\n        if (n & 1) ret *= x;  //\
    \ n \u306E\u6700\u4E0B\u4F4Dbit\u304C 1 \u306A\u3089\u3070 x^(2^i) \u3092\u304B\
    \u3051\u308B\n        x *= x;\n        if (m > 0) {ret %= m; x %= m;};\n     \
    \   n >>= 1;  // n \u30921bit \u5DE6\u306B\u305A\u3089\u3059\n    }\n    return\
    \ ret;\n}\n// mod. m \u3067\u306E a \u306E\u9006\u5143 a^{-1} \u3092\u8A08\u7B97\
    \u3059\u308B\ntemplate<typename T> T modinv(T a, T m) {\n    T b = m, u = 1, v\
    \ = 0;\n    while (b) {\n        T t = a / b;\n        a -= t * b; swap(a, b);\n\
    \        u -= t * v; swap(u, v);\n    }\n    u %= m;\n    if (u < 0) u += m;\n\
    \    return u;\n}\n// combination\u3092\u6C42\u3081\u308B\nlong long nCr(long\
    \ long n, long long k, long long m = 0) {\n    if (n < k) return 0;\n    if (n\
    \ - k < k) k = n - k;\n    long long ret = 1;\n    rep(i, k) {\n        ret *=\
    \ (n - i);\n        if (m > 0) ret %= m;\n    }\n    rep(i, 1, k + 1) {\n    \
    \    if (m > 0) {\n            ret *= modinv(i, m);\n            ret %= m;\n \
    \       } \n        else ret /= i;\n    }\n    return ret;\n}\n\n// \u6700\u5927\
    \u516C\u7D04\u6570\u3092\u6C42\u3081\u308B\nlong long gcd(const vector<long long>\
    \ &A) {\n    long long ret = 0;\n    rep(i, A.size()) ret = gcd(ret, A[i]);\n\
    \    return ret;\n}\n// \u6700\u5C0F\u516C\u500D\u6570\u3092\u6C42\u3081\u308B\
    \nlong long lcm(const vector<long long> &A, const long long m = 0) { \n    long\
    \ long ret = 1;\n    rep(i, A.size()) { ret = lcm(ret, A[i]); if (m > 0) ret %=\
    \ m;}\n    return ret;\n}\n// \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\
    \u306E\u4E92\u9664\u6CD5\ntuple<long long, long long, long long> extGCD(long long\
    \ a, long long b) {\n    if (b == 0) return {a, 1, 0};\n    auto [g, x, y] = extGCD(b,\
    \ a % b);\n    return {g, y, x - (a / b) * y};\n}\n\n// string\u95A2\u4FC2\ninline\
    \ string lltos(long long x) { return to_string(x);}\ninline int ctoi(char x) {\
    \ return int(x - '0');}\ninline char itoc(int x) { return (char)(x + '0');}\n\
    #if __has_include(<boost/algorithm/string.hpp>)\ninline string to_upper(string&\
    \ S) { return boost::to_upper_copy(S);}\ninline string to_lower(string& S) { return\
    \ boost::to_lower_copy(S);}\n#endif\ninline bool is_lower(char c) { return (c\
    \ >= 'a') and (c <= 'z');}\ninline bool is_upper(char c) { return (c >= 'A') and\
    \ (c <= 'Z');}\ninline char to_upper(char c) { if (is_upper(c)) return c; else\
    \ return c + 'A' - 'a';}\ninline char to_lower(char c) { if (is_lower(c)) return\
    \ c; else return c + 'a' - 'A';}\ninline string zero_padding(string N, long long\
    \ width) {\n    stringstream ss;\n    ss << setw(width) << setfill('0') << N;\n\
    \    return ss.str();\n}\ninline string zero_padding(long long N, long long width)\
    \ { return zero_padding(lltos(N), width);}\ninline string to_n_base(long long\
    \ x, long long base) {\n    assert(2 <= base and base <= 36);\n    if (x == 0)\
    \ return \"0\";\n    string ret;\n    for (; x > 0; x /= base) ret += (((x % base)\
    \ < 10) ? '0' + (x % base) : 'a' + (x % base) - 10);\n    reverse(ret);\n    return\
    \ ret;\n}\ninline long long to_decimal(string S, long long base) {\n    assert(2\
    \ <= base and base <= 36);\n    long long ret = 0, x = 1;\n    repd(i, S.size())\
    \ {\n        ret += (long long)(('0' <= S[i] and S[i] <= '9') ? S[i] - '0' : (('a'\
    \ <= S[i] and S[i] <= 'z') ? S[i] = 'a' + 10 : S[i] - 'A' + 10)) * x;\n      \
    \  x *= base;\n    }\n    return ret;\n}\n\ntemplate<class T = long long> inline\
    \ pair<T, T> RULD(T x, T y, char c) { return {((c == 'R') ? x + 1 : ((c == 'L')\
    \ ? x - 1 : x)), ((c == 'U') ? y + 1 : ((c == 'D') ? y - 1 : y))};}\ntemplate\
    \ <typename T> long long bubble_sort(vector<T> &A) {\n    ll ret = 0;\n    rep(i,\
    \ A.size() - 1) rep(j, A.size() - 1) if (A[j] > A[j + 1]) {\n        swap(A[j],\
    \ A[j + 1]);\n        ++ret;\n    } \n    return ret;\n}\ntemplate<typename T>\
    \ vector<T> compress(const vector<T> &A) {\n    long long N = A.size();\n    vector<pair<T,\
    \ long long>> B;\n    rep(i, N) B.emplace_back(A[i], i);\n    sort(B.begin(),\
    \ B.end());\n    vector<T> C(N);\n    ll count = 0;\n    rep(i, N) {\n       \
    \ C[B[i].second] = count;\n        if (i < N - 1 and B[i].first != B[i + 1].first)\
    \ ++count;\n    } \n    return C;\n}\n\n// bit\u95A2\u4FC2\nbool bit_test(long\
    \ long x, long long pos) { return (x >> pos) & 1ll; }\nlong long bit_set(long\
    \ long x, long long pos, bool flg) { return flg ? (x | (1ll << pos)) : (x & ~(1ll\
    \ << pos)); }\nlong long bit_flip(long long x, long long pos) { return x ^ (1ll\
    \ << pos); }\n#if __cplusplus > 201703L\nlong long bit_count(long long x) { return\
    \ popcount((ull)x); }\n#else \nlong long bit_count(long long x) { return __builtin_popcountll(x);\
    \ }\n#endif\n#line 3 \"structure/dualsegmenttree.cpp\"\n\ntemplate<typename T>\n\
    struct Node {\n    T value;\n    long long time;\n\n    Node(T v, long long t\
    \ = -1) : value(v), time(t) {};\n\n    bool operator< (const Node &other) const\
    \ {\n        return value < other.value;\n    }\n\n    operator T() const {\n\
    \        return value;\n    }\n    \n    friend ostream& operator << (ostream\
    \ &os, const Node<T> &node) {\n        return os << node.value;\n    }\n};\n\n\
    template<typename S, typename T>\nstruct Mapping {\n    using F = Node<T>;\n\n\
    \    Mapping() {};\n\n    virtual T id() = 0;\n\n    void operator() (S &x, const\
    \ F &f) {\n        if (f == id()) return;\n\n        map(x, f);\n    }\n\n   \
    \ void composition(F &f, const F &s) {\n        if (f == id()) {\n           \
    \ f = s;\n            return;\n        };\n        if (s == id()) return;\n\n\
    \        com(f, s);\n    }\n\n    virtual void map(S &x, const F &f) = 0;\n  \
    \  virtual void com(F &f, const F &s) = 0;\n};\n\ntemplate<typename S, typename\
    \ T>\nstruct Add: Mapping<S, T> {\n    using F = Node<T>;\n\n    Add(): _id(T(0))\
    \ {};\n\n    T id() override {\n        return _id;\n    }\n\n    void map(S &x,\
    \ const F &f) override {\n        x += f.value;\n    }\n\n    void com(F &f, const\
    \ F &s) override {\n        f.value += s.value;\n    }\n\nprivate:\n    T _id;\n\
    };\n\ntemplate<typename S, typename T>\nstruct Multiply: Mapping<S, T> {\n   \
    \ using F = Node<T>;\n\n    Multiply(): _id(T(1)) {};\n\n    T id() override {\n\
    \        return _id;\n    }\n\n    void map(S &x, const F &f) override {\n   \
    \     x *= f.value;\n    }\n\n    void com(F &f, const F &s) override {\n    \
    \    f.value *= s.value;\n    }\n\nprivate:\n    T _id;\n};\n\ntemplate<typename\
    \ S, typename T>\nstruct Set: Mapping<S, T> {\n    using F = Node<T>;\n\n    Set():\
    \ _id(numeric_limits<T>::min()) {};\n\n    T id() override {\n        return _id;\n\
    \    }\n\n    void map(S &x, const F &f) override {\n        x = S(f.value);\n\
    \    }\n\n    void com(F &f, const F &s) override {\n        if (f.time < s.time)\
    \ f = s;\n    }\n\nprivate:\n    T _id;\n};\n\ntemplate<typename S>\nstruct Set<S,\
    \ string>: Mapping<S, string> {\n    using T = string;\n    using F = Node<T>;\n\
    \n    Set(): _id(T()) {};\n\n    T id() override {\n        return _id;\n    }\n\
    \n    void map(S &x, const F &f) override {\n        x = T(f.value);\n    }\n\n\
    \    void com(F &f, const F &s) override {\n        if (f.time < s.time) f = s;\n\
    \    }\n\nprivate:\n    T _id;\n};\n\ntemplate<typename S, typename T>\nstruct\
    \ Chmin: Mapping<S, T> {\n    using F = Node<T>;\n\n    Chmin(): _id(numeric_limits<T>::max())\
    \ {};\n\n    T id() override {\n        return _id;\n    }\n\n    void map(S &x,\
    \ const F &f) override {\n        if (x > T(f.value)) x = T(f.value);\n    }\n\
    \n    void com(F &f, const F &s) override {\n        if (f.value > s.value) f\
    \ = s;\n    }\n\nprivate:\n    T _id;\n};\n\ntemplate<typename S, typename T>\n\
    struct Chmax: Mapping<S, T> {\n    using F = Node<T>;\n\n    Chmax(): _id(numeric_limits<T>::min())\
    \ {};\n\n    T id() override {\n        return _id;\n    }\n\n    void map(S &x,\
    \ const F &f) override {\n        if (x < T(f.value)) x = T(f.value);\n    }\n\
    \n    void com(F &f, const F &s) override {\n        if (f.value < s.value) f\
    \ = s;\n    }\n\nprivate:\n    T _id;\n};\n\ntemplate<typename S, typename T>\n\
    struct Flip: Mapping<S, T> {\n    using F = Node<T>;\n\n    Flip(): _id(T()) {};\n\
    \n    T id() override {\n        return _id;\n    }\n\n    void map(S &x, const\
    \ F &f) override {\n        if (f.value) x = ~x;\n    }\n\n    void com(F &f,\
    \ const F &s) override {\n        f = s;\n    }\n\nprivate:\n    T _id;\n};\n\n\
    template<typename S, \n    typename T,\n    template<class, class> class _mapping>\n\
    struct DualSegmentTree {\n    using F = Node<T>;\n\n    long long N, _N, height;\n\
    \n    vector<S> v;\n    vector<F> node;\n    _mapping<S, T> mapping;\n\n    long\
    \ long time;\n\n    DualSegmentTree(ll n) : _N(n), mapping(), time(0) {\n    \
    \    v(n, mapping.id());\n        init();\n    }\n\n    DualSegmentTree(ll n,\
    \ S a) : _N(n), v(n, a), mapping(), time(0) {\n        init();\n    }\n\n    DualSegmentTree(vector<S>\
    \ &A) : _N(v.size()), v(A), mapping(), time(0) {\n        init();\n    }\n\n \
    \   void init() {\n        _N = v.size();\n        height = 1;\n        N = 1;\n\
    \n        while (N < _N) {\n            N *= 2;\n            height++;\n     \
    \   }\n        \n        node.resize(N * 2, F(mapping.id()));\n    }\n\n    //\
    \ p\u756A\u76EE\u306E\u914D\u5217\u306E\u5024\u306B\u5BFE\u3057\u3066\uFF0Cf\u3067\
    mapping\n    // p\u306F0-indexed\n    void apply(long long p, T f) {\n       \
    \ apply_with_time(p, f, time++);\n    }\n\n    // p\u756A\u76EE\u306E\u914D\u5217\
    \u306E\u5024\u306B\u5BFE\u3057\u3066\uFF0Cf\u3067mapping\n    // p\u306F0-indexed\n\
    \    void apply_with_time(long long p, T f, long long t) {\n        assert(0 <=\
    \ p and p < _N);\n\n        long long k = p + N;\n        mapping.composition(node[k],\
    \ F(f, t));\n    }\n\n    // \u534A\u958B\u533A\u9593[l, r)\u306E\u914D\u5217\u306E\
    \u5024\u306B\u5BFE\u3057\u3066\uFF0Cf\u3067mapping\n    // l, r\u3068\u3082\u306B\
    0-indexed\n    void apply(long long l, long long r, T f) {\n        apply_with_time(l,\
    \ r, f, time++);\n    }\n\n    void apply_with_time(long long l, long long r,\
    \ T f, long long t) {\n        assert(0 <= l && l <= r && r <= _N);\n\n      \
    \  l += N;\n        r += N;\n\n        while (l < r) {\n            if (l & 1)\
    \ mapping.composition(node[l++], F(f, t));\n            if (r & 1) mapping.composition(node[--r],\
    \ F(f, t));\n            l >>= 1;\n            r >>= 1;\n        }\n    }\n\n\
    \    S get(long long p) {\n        assert(0 <= p and p < _N);\n\n        long\
    \ long k = p + N;\n        F f(mapping.id());\n\n        repd(i, height) mapping.composition(f,\
    \ node[k >> i]);\n\n        S ret = v[p];\n        mapping(ret, f);\n        return\
    \ ret;\n    }\n\n    friend ostream& operator << (ostream& os, DualSegmentTree&\
    \ seg) {\n        os << \"v\" << endl;\n        rep(i, seg._N) {\n           \
    \ os << seg.v[i] << \" \";\n        }\n        os << endl;\n\n        os << \"\
    node\" << endl;\n        ll h = 1;\n        rep(i, 1, seg.node.size()) {\n   \
    \         if (seg.node[i].value == seg.mapping.id()) os << \"id \";\n        \
    \    else os << seg.node[i] << \" \";\n\n            if (i == (1 << h) - 1) {\n\
    \                os << endl;\n                h++;\n            }\n        }\n\
    \        os << endl;\n\n        os << \"value\" << endl;\n        rep(i, seg._N)\
    \ {\n            os << seg.get(i) << \" \";\n        }\n        os << endl;\n\n\
    \        return os;\n    }\n};\n\ntemplate<typename S = long long, typename T\
    \ = long long> using RangeAddPointGet = DualSegmentTree<S, T, Add>;\ntemplate<typename\
    \ S = long long, typename T = long long> using RangeSetPointGet = DualSegmentTree<S,\
    \ T, Set>;\ntemplate<typename S = long long, typename T = long long> using RangeChminPointGet\
    \ = DualSegmentTree<S, T, Chmin>;\ntemplate<typename S = long long, typename T\
    \ = long long> using RangeChmaxPointGet = DualSegmentTree<S, T, Chmax>;\n#line\
    \ 4 \"test/structure/dualsegmenttree/aoj-dsl-2-d.test.cpp\"\n\nint main() {\n\
    \    ll n, q;\n    cin >> n >> q;\n\n    RangeSetPointGet<ll, ll> tree(n, (1ll\
    \ << 31) - 1);\n    while (q--) {\n        ll t;\n        cin >> t;\n\n      \
    \  if (t == 0) {\n            ll s, t, x;\n            cin >> s >> t >> x;\n \
    \           tree.apply(s, t + 1, x);\n        }\n        else {\n            ll\
    \ i;\n            cin >> i;\n            cout << tree.get(i) << endl;\n      \
    \  }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D&\"\
    \n\n#include \"../../../structure/dualsegmenttree.cpp\"\n\nint main() {\n    ll\
    \ n, q;\n    cin >> n >> q;\n\n    RangeSetPointGet<ll, ll> tree(n, (1ll << 31)\
    \ - 1);\n    while (q--) {\n        ll t;\n        cin >> t;\n\n        if (t\
    \ == 0) {\n            ll s, t, x;\n            cin >> s >> t >> x;\n        \
    \    tree.apply(s, t + 1, x);\n        }\n        else {\n            ll i;\n\
    \            cin >> i;\n            cout << tree.get(i) << endl;\n        }\n\
    \    }\n\n    return 0;\n}"
  dependsOn:
  - structure/dualsegmenttree.cpp
  - base.cpp
  isVerificationFile: true
  path: test/structure/dualsegmenttree/aoj-dsl-2-d.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 16:55:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/dualsegmenttree/aoj-dsl-2-d.test.cpp
layout: document
redirect_from:
- /verify/test/structure/dualsegmenttree/aoj-dsl-2-d.test.cpp
- /verify/test/structure/dualsegmenttree/aoj-dsl-2-d.test.cpp.html
title: test/structure/dualsegmenttree/aoj-dsl-2-d.test.cpp
---
