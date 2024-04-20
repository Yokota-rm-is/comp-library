---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.cpp
    title: base.cpp
  - icon: ':heavy_check_mark:'
    path: structure/lazysegmenttree.cpp
    title: structure/lazysegmenttree.cpp
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
  bundledCode: "#line 1 \"test/structure/lazysegmenttree/aoj-dsl-2-d.test.cpp\"\n\
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
    \ name\n#define DUMP1(a) if (DEBUG) {cerr << #a << \": \"; dump(a); cerr << endl;};\n\
    #define DUMP2(a, b) if (DEBUG) {DUMP1(a); DUMP1(b)};\n#define DUMP3(a, b, c) if\
    \ (DEBUG) {DUMP1(a); DUMP2(b, c)};\n#define DUMP4(a, b, c, d) if (DEBUG) {DUMP1(a);\
    \ DUMP3(b, c, d)};\n#define DUMP5(a, b, c, d, e) if (DEBUG) {DUMP1(a); DUMP4(b,\
    \ c, d, e)};\n#define debug(...) OVERLOAD_DEBUG(__VA_ARGS__, DUMP5, DUMP4, DUMP3,\
    \ DUMP2, DUMP1)(__VA_ARGS__)\n\n// \u7701\u7565\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing vll = vector<ll>;\nusing setll = set<ll>;\n\
    using mapll = map<ll, ll>;\nusing pll = pair<ll, ll>;\ntemplate<typename T> using\
    \ vec = vector<T>;\ntemplate<typename T> using vv = vector<vector<T>>;\nusing\
    \ vvll = vector<vector<long long>>;\ntemplate<typename T> using vvv = vector<vector<vector<T>>>;\n\
    using str = string;\nusing vstr = vector<str>;\nusing sstr = set<str>;\nusing\
    \ vchar = vector<char>;\nusing schar = set<char>;\nusing vd = vector<double>;\n\
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
    \       } \n        else ret /= i;\n    }\n    return ret;\n}\n// \u6700\u5927\
    \u516C\u7D04\u6570\u3092\u6C42\u3081\u308B\nlong long gcd(long long a, long long\
    \ b) { \n    if (b > a) swap(a, b);\n    return ((b == 0) ? a : gcd(b, a % b));\n\
    }\n// \u6700\u5C0F\u516C\u500D\u6570\u3092\u6C42\u3081\u308B\nlong long lcm(long\
    \ long a, long long b) { return a / gcd(a, b) * b;}\n// \u62E1\u5F35\u30E6\u30FC\
    \u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\nlong long extGCD(long long a,\
    \ long long b, long long &x, long long &y) {\n    if (b == 0) {x = 1; y = 0;return\
    \ a;}\n    long long d = extGCD(b, a%b, y, x);\n    y -= a/b * x;\n    return\
    \ d;\n}\n\n// string\u95A2\u4FC2\ninline string lltos(long long x) { return to_string(x);}\n\
    inline int ctoi(char x) { return int(x - '0');}\ninline char itoc(int x) { return\
    \ (char)(x + '0');}\n#if __has_include(<boost/algorithm/string.hpp>)\ninline string\
    \ to_upper(string& S) { return boost::to_upper_copy(S);}\ninline string to_lower(string&\
    \ S) { return boost::to_lower_copy(S);}\n#endif\ninline bool is_lower(char c)\
    \ { return (c >= 'a') and (c <= 'z');}\ninline bool is_upper(char c) { return\
    \ (c >= 'A') and (c <= 'Z');}\ninline string zero_padding(string N, long long\
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
    \ A[j + 1]);\n        ++ret;\n    } \n    return ret;\n}\n\n// bit\u95A2\u4FC2\
    \nbool bit_test(long long x, long long pos) { return (x >> pos) & 1ll; }\nlong\
    \ long bit_set(long long x, long long pos, bool flg) { return flg ? (x | (1ll\
    \ << pos)) : (x & ~(1ll << pos)); }\nlong long bit_flip(long long x, long long\
    \ pos) { return x ^ (1ll << pos); }\n#if __cplusplus > 201703L\nlong long bit_count(long\
    \ long x) { return popcount((ull)x); }\n#else \nlong long bit_count(long long\
    \ x) { return __builtin_popcountll(x); }\n#endif\n#line 3 \"structure/lazysegmenttree.cpp\"\
    \n\ntemplate<typename T>\nstruct Node {\n    T value;\n    long long index;\n\
    \    long long size;\n    long long coeff;\n\n    Node(T v, long long i = -1,\
    \ long long s = 0, long long c = 1) : value(v), index(i), size(s), coeff(c) {};\n\
    \n    bool operator< (const Node &other) const {\n        return value < other.value;\n\
    \    }\n\n    bool operator== (const T other) const {\n        return value ==\
    \ other;\n    }\n\n    bool operator!= (const T other) const {\n        return\
    \ value != other;\n    }\n\n    operator T() const {\n        return value;\n\
    \    }\n\n    friend ostream& operator << (ostream &os, const Node<T>& node) {\n\
    \        return os << node.value;\n    }\n};\n\ntemplate<typename T>\nstruct Operation\
    \ {\n    using S = Node<T>;\n\n    Operation() {};\n\n    virtual T e() = 0;\n\
    \n    virtual S operator() (const S& x, const S& y) = 0;\n};\n\ntemplate<typename\
    \ T = long long>\nstruct NoOperation : Operation<T> {\n    using S = Node<T>;\n\
    \n    NoOperation(): _e(T()) {};\n\n    T e() override {\n        return _e;\n\
    \    }\n\n    S operator() (const S& x, const S& y) override {\n        if (x\
    \ == e()) return y;\n        else if (y == e()) return x;\n\n        T value =\
    \ x.value;\n        long long index = -1;\n        long long size = x.size + y.size;\n\
    \        long long coeff = 1;\n\n        S ret(value, index, size, coeff);\n\n\
    \        return ret;\n    }\n\nprivate:\n    T _e;\n};\n\ntemplate<typename T>\n\
    struct Max : Operation<T> {\n    using S = Node<T>;\n\n    Max(): _e(numeric_limits<T>::min())\
    \ {};\n\n    T e() override {\n        return _e;\n    }\n\n    S operator() (const\
    \ S& x, const S& y) override {\n        T value = max(x.value, y.value);\n   \
    \     long long index = (y.value > x.value ? y.index : x.index);\n        long\
    \ long size = x.size + y.size;\n        long long coeff = 1;\n\n        S ret(value,\
    \ index, size, coeff);\n\n        return ret;\n    }\n\nprivate:\n    T _e;\n\
    };\n\ntemplate<typename T>\nstruct Min: Operation<T> {\n    using S = Node<T>;\n\
    \n    Min(): _e(numeric_limits<T>::max()) {};\n\n    T e() override {\n      \
    \  return _e;\n    }\n\n    S operator() (const S& x, const S& y) override {\n\
    \        T value = min(x.value, y.value);\n        long long index = (y.value\
    \ < x.value ? y.index : x.index);\n        long long size = x.size + y.size;\n\
    \        long long coeff = 1;\n\n        S ret(value, index, size, coeff);\n\n\
    \        return ret;\n    }\n\nprivate:\n    T _e;\n};\n\ntemplate<typename T>\n\
    struct Sum: Operation<T> {\n    using S = Node<T>;\n\n    Sum(): _e(T()) {};\n\
    \n    T e() override {\n        return _e;\n    }\n\n    S operator() (const S&\
    \ x, const S& y) override {\n        T value = x.value + y.value;\n        long\
    \ long index = -1;\n        long long size = x.size + y.size;\n        long long\
    \ coeff = size;\n\n        S ret(value, index, size, coeff);\n\n        return\
    \ ret;\n    }\n\nprivate:\n    T _e;\n};\n\ntemplate<typename T>\nstruct Mul:\
    \ Operation<T> {\n    using S = Node<T>;\n\n    Mul(): _e(T(1)) {};\n\n    T e()\
    \ override {\n        return _e;\n    }\n\n    S operator() (const S& x, const\
    \ S& y) override {\n        T value = x.value * y.value;\n        long long index\
    \ = -1;\n        long long size = x.size + y.size;\n        long long coeff =\
    \ 1;\n\n        S ret(value, index, size, coeff);\n\n        return ret;\n   \
    \ }\n\nprivate:\n    T _e;\n};\n\ntemplate<typename T = long long>\nstruct GCD\
    \ : Operation<T> {\n    using S = Node<T>;\n\n    GCD(): _e(T(0)) {};\n\n    T\
    \ e() override {\n        return _e;\n    }\n\n    S operator() (const S& x, const\
    \ S& y) override {\n        T value = gcd(x.value, y.value);\n        long long\
    \ index = -1;\n        long long size = x.size + y.size;\n        long long coeff\
    \ = 1;\n\n        S ret(value, index, size, coeff);\n\n        return ret;\n \
    \   }\n\nprivate:\n    T _e;\n};\n\ntemplate<typename T = long long>\nstruct LCM\
    \ : Operation<T> {\n    using S = Node<T>;\n\n    LCM(): _e(T(1)) {};\n\n    T\
    \ e() override {\n        return _e;\n    }\n\n    S operator() (const S& x, const\
    \ S& y) override {\n        T value = lcm(x.value, y.value);\n        long long\
    \ index = -1;\n        long long size = x.size + y.size;\n        long long coeff\
    \ = 1;\n\n        S ret(value, index, size, coeff);\n\n        return ret;\n \
    \   }\n\nprivate:\n    T _e;\n};\n\ntemplate<typename T, typename F>\nstruct Mapping\
    \ {\n    using S = Node<T>;\n\n    Mapping() {};\n\n    virtual F id() = 0;\n\n\
    \    void operator() (S &x, const F f) {\n        if (f == id()) return;\n\n \
    \       map(x, f);\n    }\n\n    void composition(F &f, const F s) {\n       \
    \ if (f == id()) {\n            f = s;\n            return;\n        };\n    \
    \    if (s == id()) return;\n\n        com(f, s);\n    }\n\n    virtual void map(S\
    \ &x, const F f) = 0;\n    virtual void com(F &f, const F s) = 0;\n};\n\ntemplate<typename\
    \ T, typename F>\nstruct Add: Mapping<T, F> {\n    using S = Node<T>;\n\n    Add():\
    \ _id(F(0)) {};\n\n    F id() override {\n        return _id;\n    }\n\n    void\
    \ map(S &x, const F f) override {\n        x.value += f * x.coeff;\n    }\n\n\
    \    void com(F &f, const F s) override {\n        f += s;\n    }\n\nprivate:\n\
    \    F _id;\n};\n\ntemplate<typename T, typename F>\nstruct Multiply: Mapping<T,\
    \ F> {\n    using S = Node<T>;\n\n    Multiply(): _id(F(1)) {};\n\n    F id()\
    \ override {\n        return _id;\n    }\n\n    void map(S &x, const F f) override\
    \ {\n        x.value *= f;\n    }\n\n    void com(F &f, const F s) override {\n\
    \        f *= s;\n    }\n\nprivate:\n    F _id;\n};\n\ntemplate<typename T, typename\
    \ G>\nstruct Affine: Mapping<T, pair<G, G>> {\n    using S = Node<T>;\n    using\
    \ F = pair<G, G>;\n\n    Affine(): _id(F(1, 0)) {};\n\n    F id() override {\n\
    \        return _id;\n    }\n\n    void map(S &x, const F f) override {\n    \
    \    x.value = f.first * x.value + f.second * x.coeff;\n    }\n\n    void com(F\
    \ &f, const F s) override {\n        f.first *= s.first;\n        f.second *=\
    \ s.first;\n        f.second += s.second;\n    }\n\nprivate:\n    F _id;\n};\n\
    \ntemplate<typename T, typename F>\nstruct Set: Mapping<T, F> {\n    using S =\
    \ Node<T>;\n\n    Set(): _id(numeric_limits<F>::min()) {};\n\n    F id() override\
    \ {\n        return _id;\n    }\n\n    void map(S &x, const F f) override {\n\
    \        x.value = T(f) * x.coeff;\n    }\n\n    void com(F &f, const F s) override\
    \ {\n        f = s;\n    }\n\nprivate:\n    F _id;\n};\n\ntemplate<typename T>\n\
    struct Set<T, string>: Mapping<T, string> {\n    using S = Node<T>;\n    using\
    \ F = string;\n\n    Set(): _id(F()) {};\n\n    F id() override {\n        return\
    \ _id;\n    }\n\n    void map(S &x, const F f) override {\n        x.value = T(f);\n\
    \    }\n\n    void com(F &f, const F s) override {\n        f = s;\n    }\n\n\
    private:\n    F _id;\n};\n\ntemplate<typename T, typename F>\nstruct Flip: Mapping<T,\
    \ F> {\n    using S = Node<T>;\n\n    Flip(): _id(F()) {};\n\n    F id() override\
    \ {\n        return _id;\n    }\n\n    void map(S &x, const F f) override {\n\
    \        if (f) {\n            x.value ^= 1;\n        }\n    }\n\n    void com(F\
    \ &f, const F s) override {\n        f ^= s;\n    }\n\nprivate:\n    F _id;\n\
    };\n\ntemplate<typename T, \n    typename F,\n    template<class, class> class\
    \ _mapping, \n    template<class> class _op>\nstruct LazySegmentTree {\n    using\
    \ S = Node<T>;\n\n    long long N, _N, height;\n\n    vector<S> node;\n    vector<F>\
    \ lazy;\n    _op<T> op;\n    _mapping<T, F> mapping;\n\n    LazySegmentTree(long\
    \ long n) : _N(n), op(), mapping() {\n        vector<T> v(n, op.e());\n      \
    \  init(v);\n    }\n\n    LazySegmentTree(long long n, T a) : _N(n), op(), mapping()\
    \ {\n        vector<T> v(n, a);\n        init(v);\n    }\n\n    LazySegmentTree(vector<T>\
    \ &v) : _N(v.size()), op(), mapping() {\n        init(v);\n    }\n\n    void init(vector<T>\
    \ &v) {\n        _N = v.size();\n        height = 1;\n        N = 1;\n\n     \
    \   while (N < _N) {\n            N *= 2;\n            height++;\n        }\n\
    \        \n        node.resize(2 * N, S(op.e()));\n        lazy.resize(N, mapping.id());\n\
    \n        rep(i, N) {\n            if (i < _N) node[i + N] = S(v[i], i, 1, 1);\n\
    \            else node[i + N] = S(op.e());\n        }\n        repd(i, 1, N) update(i);\n\
    \    }\n\n    // p\u756A\u76EE\u306E\u914D\u5217\u306E\u5024\u306B\u5BFE\u3057\
    \u3066\uFF0Cf\u3067mapping\n    // p\u306F0-indexed\n    void apply(long long\
    \ p, F f) {\n        assert(0 <= p and p < _N);\n\n        long long k = p + N;\n\
    \        repd(i, 1, height) push(k >> i);\n        mapping(node[k], f);\n    \
    \    rep(i, 1, height) update(k >> i);\n    }\n\n    // \u534A\u958B\u533A\u9593\
    [l, r)\u306E\u914D\u5217\u306E\u5024\u306B\u5BFE\u3057\u3066\uFF0Cf\u3067mapping\n\
    \    // l, r\u3068\u3082\u306B0-indexed\n    void apply(long long l, long long\
    \ r, F f) {\n        assert(0 <= l && l <= r && r <= _N);\n\n        l += N;\n\
    \        r += N;\n\n        repd(i, 1, height) {\n            if (((l >> i) <<\
    \ i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >>\
    \ i);\n        }\n\n        long long l2 = l, r2 = r;\n        while (l2 < r2)\
    \ {\n            if (l2 & 1) all_apply(l2++, f);\n            if (r2 & 1) all_apply(--r2,\
    \ f);\n            l2 >>= 1;\n            r2 >>= 1;\n        }\n\n        rep(i,\
    \ 1, height) {\n            if (((l >> i) << i) != l) update(l >> i);\n      \
    \      if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n \
    \   S get(long long p) {\n        assert(0 <= p and p < _N);\n\n        long long\
    \ k = p + N;\n        repd(i, 1, height) push(k >> i);\n        return node[k];\n\
    \    }\n\n    // \u534A\u958B\u533A\u9593[l, r)\u306E\u914D\u5217\u306E\u5024\u3092\
    \u8FD4\u3059\n    // l, r\u3068\u3082\u306B0-indexed\n    S prod(long long l,\
    \ long long r) {\n        assert(0 <= l && l <= r && r <= _N);\n\n        l +=\
    \ N;\n        r += N;\n\n        repd(i, 1, height) {\n            if (((l >>\
    \ i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        }\n\n        S sml(op.e()), smr(op.e());\n        while\
    \ (l < r) {\n            if (l & 1) sml = op(sml, node[l++]);\n            if\
    \ (r & 1) smr = op(node[--r], smr);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n\n        return op(sml, smr);\n    }\n\n    S prod_all() {\n    \
    \    return node[1];\n    }\n\n    // \u5DE6\u7AEF\u3092l\u306B\u56FA\u5B9A\u3057\
    \u305F\u5834\u5408\u306E\uFF0Cg(prod(op(node[l], node[l + 1], ..., node[r - 1])))\
    \ = true\u3068\u306A\u308B\u6700\u5927\u306Er\u3092\u8FD4\u3059\n    // g(node[l])\
    \ = false\u306E\u5834\u5408\uFF0Cl\u3092\u8FD4\u3059 (\u534A\u958B\u533A\u9593\
    [l, l)\u3068\u306A\u308A\uFF0C\u89E3\u306F\u306A\u3044)\n    // l = N\u306E\u5834\
    \u5408\uFF0CN\u3092\u8FD4\u3059\n    template <class G>\n    long long max_right(long\
    \ long l, G g) {\n        assert(0 <= l && l <= _N);\n        assert(g(S(op.e())));\n\
    \n        if (l == _N) return _N;\n        l += N;\n        repd(i, 1, height)\
    \ push(l >> i);\n        \n        S sm(op.e());\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n\n            if (!g(op(sm, node[l]))) {\n          \
    \      while (l < N) {\n                    push(l);\n\n                    l\
    \ *= 2;\n                    if (g(op(sm, node[l]))) {\n                     \
    \   sm = op(sm, node[l]);\n                        l++;\n                    }\n\
    \                }\n                return l - N;\n            }\n\n         \
    \   sm = op(sm, node[l]);\n            l++;\n\n        } while ((l & -l) != l);\n\
    \n        return _N;\n    }\n\n    // \u53F3\u7AEF\u3092r - 1\u306B\u56FA\u5B9A\
    \u3057\u305F\u5834\u5408\u306E\uFF0Cg(prod(op(node[l], node[l + 1], ..., node[r\
    \ - 1]))) = true\u3068\u306A\u308B\u6700\u5C0F\u306El\u3092\u8FD4\u3059\n    //\
    \ g(node[r - 1]) = false\u306E\u5834\u5408\uFF0Cr\u3092\u8FD4\u3059 (\u534A\u958B\
    \u533A\u9593[r, r)\u3068\u306A\u308A\uFF0C\u89E3\u306F\u306A\u3044)\n    // r\
    \ = 0\u306E\u5834\u5408\uFF0C0\u3092\u8FD4\u3059\n    template <class G>\n   \
    \ long long min_left(long long r, G g) {\n        assert(0 <= r && r <= _N);\n\
    \        assert(g(S(op.e())));\n\n        if (r == 0) return 0;\n\n        r +=\
    \ N;\n        \n        repd(i, 1, height) push((r - 1) >> i);\n\n        S sm(op.e());\n\
    \n        do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
    \            \n            if (!g(op(node[r], sm))) {\n                while (r\
    \ < N) {\n                    push(r);\n                    r = (2 * r + 1);\n\
    \n                    if (g(op(node[r], sm))) {\n                        sm =\
    \ op(node[r], sm);\n                        r--;\n                    }\n    \
    \            }\n                return r + 1 - N;\n            }\n\n         \
    \   sm = op(node[r], sm);\n\n        } while ((r & -r) != r);\n\n        return\
    \ 0;\n    }\n\n    friend ostream& operator << (ostream& os, LazySegmentTree&\
    \ seg) {\n        os << \"node\" << endl;\n        long long h = 1;\n        rep(i,\
    \ 1, seg.node.size()) {\n            if (seg.node[i].value == seg.op.e()) os <<\
    \ \"e \";\n            else os << seg.node[i] << \" \";\n\n            if (i ==\
    \ (1 << h) - 1) {\n                os << endl;\n                h++;\n       \
    \     }\n        }\n        os << endl;\n\n        os << \"lazy\" << endl;\n \
    \       h = 1;\n        rep(i, 1, seg.N) {\n            if (seg.lazy[i] == seg.mapping.id())\
    \ os << \"id \";\n            else os << seg.lazy[i] << \" \";\n            if\
    \ (i == (1 << h) - 1) {\n                os << endl;\n                h++;\n \
    \           }\n        }\n\n        os << \"value\" << endl;\n        rep(i, seg._N)\
    \ {\n            os << seg.get(i) << \" \";\n        }\n        os << endl;\n\n\
    \        return os;\n    }\n\nprivate:\n    // k\u756A\u76EE\u306E\u30CE\u30FC\
    \u30C9\u306E\u5024\u3092\u5B50\u306E\u5024\u3067\u66F4\u65B0\n    void update(long\
    \ long k) {\n        assert(1 <= k and k <= N - 1);\n\n        node[k] = op(node[k\
    \ * 2], node[k * 2 + 1]);\n    }\n\n    void all_apply(long long k, F f) {\n \
    \       mapping(node[k], f);\n        if (k < N) mapping.composition(lazy[k],\
    \ f);\n    }\n\n    // k\u756A\u76EE\u306E\u30CE\u30FC\u30C9\u3092\u5B50\u306B\
    \u4F1D\u642C\n    void push(long long k) {\n        assert(1 <= k and k <= N *\
    \ 2 - 1);\n\n        all_apply(2 * k, lazy[k]);\n        all_apply(2 * k + 1,\
    \ lazy[k]);\n\n        lazy[k] = mapping.id();\n    }\n};\n\ntemplate<typename\
    \ T = long long, typename F = long long> using RangeAddRangeSum = LazySegmentTree<T,\
    \ F, Add, Sum>;\ntemplate<typename T = long long, typename F = long long> using\
    \ RangeAddRangeMin = LazySegmentTree<T, F, Add, Min>;\ntemplate<typename T = long\
    \ long, typename F = long long> using RangeAddRangeMax = LazySegmentTree<T, F,\
    \ Add, Max>;\n\ntemplate<typename T = long long, typename F = long long> using\
    \ RangeSetRangeSum = LazySegmentTree<T, F, Set, Sum>;\ntemplate<typename T = long\
    \ long, typename F = long long> using RangeSetRangeMin = LazySegmentTree<T, F,\
    \ Set, Min>;\ntemplate<typename T = long long, typename F = long long> using RangeSetRangeMax\
    \ = LazySegmentTree<T, F, Set, Max>;\n#line 4 \"test/structure/lazysegmenttree/aoj-dsl-2-d.test.cpp\"\
    \n\nint main() {\n    ll n, q;\n    cin >> n >> q;\n\n    RangeSetRangeSum<ll,\
    \ ll> tree(n, (1ll << 31) - 1);\n    while (q--) {\n        ll t;\n        cin\
    \ >> t;\n\n        if (t == 0) {\n            ll s, t, x;\n            cin >>\
    \ s >> t >> x;\n            tree.apply(s, t + 1, x);\n        }\n        else\
    \ {\n            ll i;\n            cin >> i;\n            cout << tree.get(i)\
    \ << endl;\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D&\"\
    \n\n#include \"../../../structure/lazysegmenttree.cpp\"\n\nint main() {\n    ll\
    \ n, q;\n    cin >> n >> q;\n\n    RangeSetRangeSum<ll, ll> tree(n, (1ll << 31)\
    \ - 1);\n    while (q--) {\n        ll t;\n        cin >> t;\n\n        if (t\
    \ == 0) {\n            ll s, t, x;\n            cin >> s >> t >> x;\n        \
    \    tree.apply(s, t + 1, x);\n        }\n        else {\n            ll i;\n\
    \            cin >> i;\n            cout << tree.get(i) << endl;\n        }\n\
    \    }\n\n    return 0;\n}"
  dependsOn:
  - structure/lazysegmenttree.cpp
  - base.cpp
  isVerificationFile: true
  path: test/structure/lazysegmenttree/aoj-dsl-2-d.test.cpp
  requiredBy: []
  timestamp: '2024-04-20 11:19:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/lazysegmenttree/aoj-dsl-2-d.test.cpp
layout: document
redirect_from:
- /verify/test/structure/lazysegmenttree/aoj-dsl-2-d.test.cpp
- /verify/test/structure/lazysegmenttree/aoj-dsl-2-d.test.cpp.html
title: test/structure/lazysegmenttree/aoj-dsl-2-d.test.cpp
---
