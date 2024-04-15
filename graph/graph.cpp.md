---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.cpp
    title: base.cpp
  - icon: ':warning:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':warning:'
    path: graph/stamp.cpp
    title: graph/stamp.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"base.cpp\"\n\n#include <bits/stdc++.h>\n// #include <atcoder/all>\n\
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
    \ x) { return __builtin_popcountll(x); }\n#endif\n#line 3 \"graph/edge.cpp\"\n\
    \ntemplate<class Weight = long long, class Cap = long long>\nstruct Edge {\n \
    \   long long from;\n    long long to;\n    Weight weight;\n    Cap cap;\n   \
    \ long long id;\n    long long rev;\n    Cap flow;\n    \n    explicit Edge(long\
    \ long u = -1, long long v = -1, Weight w = 1, long long i = -1, Cap c = 0, long\
    \ long r = -1) : from(u), to(v), weight(w), cap(c), id(i), rev(r), flow(0) {};\n\
    \n    bool operator < (const Edge& other) const {\n        if (from == other.from)\
    \ {\n            if (to == other.to) return weight < other.weight;\n         \
    \   else return to < other.to;\n        }\n        else return from < other.from;\n\
    \    }\n\n    friend ostream& operator << (ostream& os, const Edge& edge) {\n\
    \        return os << edge.to;\n    }\n};\n#line 3 \"graph/stamp.cpp\"\n\nstruct\
    \ Stamp {\n    long long index;\n    long long time;\n    explicit Stamp(long\
    \ long i = 0, long long t = -1) : index(i), time(t) {};\n\n    bool operator<(const\
    \ Stamp& right) const {\n        return time < right.time;\n    }\n\n    friend\
    \ ostream& operator << (ostream& os, const Stamp& stamp) {\n        return os\
    \ << \"(\" << stamp.time << \", \" << stamp.index << \")\";\n    }\n};\n#line\
    \ 5 \"graph/graph.cpp\"\n\ntemplate<class Weight = long long, class Cap = long\
    \ long, class DP = long long>\nstruct Graph {\n    // DFS, BFS\u5171\u901A\n \
    \   long long V;\n    bool directed_;\n    vector<vector<Edge<Weight, Cap>>> G;\n\
    \    vector<bool> seen, done;\n    vector<Edge<Weight, Cap>> prev;\n    long long\
    \ edge_index = 0;\n    vector<Edge<Weight, Cap>> edges;\n    vector<long long>\
    \ merged;\n\n    // DFS\u7528\n    vector<Stamp> pre_order, post_order;\n    long\
    \ long first, last;\n    bool has_cycle;\n    vector<long long> descendants;\n\
    \    long long inf = inf64;\n\n    // BFS\u7528\n    vector<long long> depth;\n\
    \n    // \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u7528\n    vector<Weight> cost;\n\
    \n    // LCA\u7528\n    vector<vector<long long>> doubling;\n    long long log;\n\
    \    bool _lca_init_done;\n\n    // \u4E8C\u90E8\u30B0\u30E9\u30D5\u7528\n   \
    \ bool _is_bipartite = true;\n    vector<long long> colors;\n\n    // CC\u7528\
    \n    vector<long long> groups;\n    vector<set<long long>> cc; \n    vector<set<long\
    \ long>> cc_edge;\n\n    // SCC\u7528\n    vector<vector<Edge<Weight, Cap>>> rG;\n\
    \    vector<long long> roots;\n    vector<set<long long>> scc;\n\n    // \u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u7528\n    vector<long long>\
    \ topo_dp;\n\n    // \u5168\u65B9\u4F4D\u6728dp\u7528\n    vector<vector<DP>>\
    \ tree_dp;\n    vector<DP> prod_all;\n    long long root_;\n\n    // maxflow\u7528\
    \n    vector<long long> level;\n    vector<long long> iter;\n\n    // mincostflow\u7528\
    \n    vector<Weight> dual, dist;\n    vector<long long> prevv, preve;\n    Cap\
    \ cur_flow;\n    Cap cur_cost, pre_cost;\n    vector<pair<Cap, Weight>> min_cost_slope;\n\
    \n    explicit Graph(long long N, bool directed) : V(N), directed_(directed),\
    \ G(V), rG(V) {\n        init();\n    };\n    \n    void init() {\n        first\
    \ = 0;\n        last = 0;\n        has_cycle = false;\n        _lca_init_done\
    \ = false;\n        cur_flow = 0;\n        cur_cost = 0;\n        pre_cost = -1;\n\
    \n        log = 1;\n        while ((1ll << log) <= V) ++log;\n\n        seen.assign(V,\
    \ false);\n        done.assign(V, false);\n        prev.assign(V, Edge<Weight,\
    \ Cap>());\n        colors.assign(V, -1);\n        descendants.assign(V, 0);\n\
    \        roots.assign(V, -1);\n        groups.assign(V, -1);\n        depth.assign(V,\
    \ inf);\n        cost.assign(V, inf);\n        doubling.assign(log, vector<long\
    \ long>(V, -1));\n        level.assign(V, -1);\n        iter.assign(V, 0);\n \
    \       dual.assign(V, 0);\n        dist.assign(V, 0);\n        prevv.assign(V,\
    \ -1);\n        preve.assign(V, -1);\n        topo_dp.assign(V, -1);\n       \
    \ tree_dp.resize(V);\n        prod_all.assign(V, id());\n        merged.assign(V,\
    \ -1);\n    }\n    \n    void connect(long long from, long long to, Weight weight\
    \ = 1) {\n        assert(0 <= from and from < V);\n        assert(0 <= to and\
    \ to < V);\n\n        from = find(from);\n        to = find(to);\n\n        //\
    \ assert(from != to);\n\n        if (directed_) {\n            long long from_id\
    \ = G[from].size();\n            long long to_id = rG[to].size();\n\n        \
    \    edges.emplace_back(from, to, weight, edge_index);\n\n            G[from].emplace_back(from,\
    \ to, weight, edge_index, weight, to_id);\n            rG[to].emplace_back(to,\
    \ from, weight, edge_index, weight, from_id);\n        }\n        else {\n   \
    \         long long from_id = G[from].size();\n            long long to_id = G[to].size();\n\
    \n            edges.emplace_back(from, to, weight, edge_index, weight, from_id);\n\
    \n            G[from].emplace_back(from, to, weight, edge_index, weight, to_id);\n\
    \            G[to].emplace_back(to, from, weight, edge_index, 0, from_id);\n\n\
    \            tree_dp[from].push_back(id());\n            tree_dp[to].push_back(id());\n\
    \        }\n\n        ++edge_index;\n    }\n\n    void connect(long long from,\
    \ long long to, Cap cap, Weight weight) {\n        assert(0 <= from and from <\
    \ V);\n        assert(0 <= to and to < V);\n\n        from = find(from);\n   \
    \     to = find(to);\n\n        // assert(from != to);\n\n        if (!directed_)\
    \ {\n            long long from_id = G[from].size();\n            long long to_id\
    \ = G[to].size();\n\n            edges.emplace_back(from, to, weight, edge_index,\
    \ cap, from_id);\n\n            G[from].emplace_back(from, to, weight, edge_index,\
    \ cap, to_id);\n            G[to].emplace_back(to, from, -weight, edge_index,\
    \ 0, from_id);\n        }\n\n        ++edge_index;\n    }\n\n    long long find(long\
    \ long x) { // \u30C7\u30FC\u30BFx\u304C\u5C5E\u3059\u308B\u6728\u306E\u6839\u3092\
    \u518D\u5E30\u3067\u5F97\u308B\uFF1Aroot(x) = {x\u306E\u6728\u306E\u6839}\n  \
    \      if (merged[x] < 0) return x;\n\n        long long rx = find(merged[x]);\n\
    \        return merged[x] = rx;\n    }\n\n    void unite(long long x, long long\
    \ y) {\n        long long rx = find(x); //x\u306E\u6839\u3092rx\n        long\
    \ long ry = find(y); //y\u306E\u6839\u3092ry\n        if (rx == ry) return; //x\u3068\
    y\u306E\u6839\u304C\u540C\u3058(=\u540C\u3058\u6728\u306B\u3042\u308B)\u6642\u306F\
    \u305D\u306E\u307E\u307E\n\n        // -par\u306F\u30B5\u30A4\u30BA\u3092\u8FD4\
    \u3059\n        // ry\u306E\u65B9\u304C\u30B5\u30A4\u30BA\u304C\u5927\u304D\u3051\
    \u308C\u3070rx\u3068rx\u3092\u5165\u308C\u66FF\u3048\u308B\n        if (-merged[rx]\
    \ < -merged[ry]) {\n            swap(rx, ry);\n        }\n\n        merged[rx]\
    \ += merged[ry]; // rx\u306E\u30B5\u30A4\u30BA\u3092\u5909\u66F4\n        merged[ry]\
    \ = rx; //x\u3068y\u306E\u6839\u304C\u540C\u3058\u3067\u306A\u3044(=\u540C\u3058\
    \u6728\u306B\u306A\u3044)\u6642\uFF1Ay\u306E\u6839ry\u3092x\u306E\u6839rx\u306B\
    \u3064\u3051\u308B\n\n        if (directed_) {\n            fore(edge, G[ry])\
    \ {\n                long long from_id = G[rx].size();\n\n                G[rx].emplace_back(rx,\
    \ edge.to, edge.weight, edge.id, edge.cap, edge.rev);\n                rG[edge.to][edge.rev].to\
    \ = rx;\n                rG[edge.to][edge.rev].rev = from_id;\n            }\n\
    \n            G[ry].clear();\n\n            fore(edge, rG[ry]) {\n           \
    \     long long to_id = rG[rx].size();\n\n                rG[rx].emplace_back(rx,\
    \ edge.to, edge.weight, edge.id, edge.cap, edge.rev);\n                G[edge.to][edge.rev].to\
    \ = rx;\n                G[edge.to][edge.rev].rev = to_id;\n            }\n\n\
    \            rG[ry].clear();\n        }\n        else {\n            fore(edge,\
    \ G[ry]) {\n                long long from_id = G[rx].size();\n\n            \
    \    G[rx].emplace_back(rx, edge.to, edge.weight, edge.id, edge.cap, edge.rev);\n\
    \                G[edge.to][edge.rev].to = rx;\n                G[edge.to][edge.rev].rev\
    \ = from_id;\n            }\n\n            G[ry].clear();\n        }\n    }\n\n\
    \    DP id() {\n        return 0;\n    }\n\n    DP merge(DP x, DP y) {\n     \
    \   return max(x, y);\n    }\n\n    DP put_edge(DP x, Edge<Weight, Cap>& edge)\
    \ {\n        return x + (DP)edge.weight;\n    }\n\n    DP put_vertex(DP x, long\
    \ long v) {\n        return x;\n    }\n\n    DP build(long long root) {\n    \
    \    root_ = root;\n        dfs(root_);\n    }\n\n    vector<DP> reroot() {\n\
    \        dfs_dp(root_, id());\n\n        return prod_all;\n    }\n\n    void dfs_all()\
    \ {\n        long long group = 0;\n\n        rep(i, V) {\n            if (seen[i])\
    \ continue;\n            dfs(i, group);\n            ++group;\n        }\n   \
    \ }\n\n    DP dfs(long long now, long long group = 0, Edge<Weight, Cap> e = Edge<Weight,\
    \ Cap>()) {\n        assert(0 <= now and now < V);\n\n        now = find(now);\n\
    \n        DP ret = id();\n\n        seen[now] = true;\n        pre_order.emplace_back(now,\
    \ first);\n        ++first;\n\n        groups[now] = group;\n        while ((long\
    \ long)cc.size() <= group) cc.push_back(set<long long>());\n        cc[group].insert(now);\n\
    \        while ((long long)cc_edge.size() <= group) cc_edge.push_back(set<long\
    \ long>());\n\n        if (colors[now] == -1) colors[now] = 0;\n        long long\
    \ next_color = !colors[now];\n\n        rep(i, G[now].size()) {\n            Edge<Weight,\
    \ Cap> edge = G[now][i];\n            long long next = edge.to;\n\n          \
    \  if (edge.id == e.id) continue;\n\n            cc_edge[group].insert(edge.id);\n\
    \n            if (colors[next] == -1) colors[next] = next_color;\n           \
    \ else if (colors[next] != next_color) _is_bipartite = false;\n\n            if\
    \ (seen[next]) {\n                if (!done[next]) has_cycle = true;\n       \
    \         continue;\n            }\n\n            prev[next] = edge;\n\n     \
    \       if (!directed_) {\n                tree_dp[now][i] = dfs(next, group,\
    \ edge);\n                ret = merge(ret, put_edge(tree_dp[now][i], edge));\n\
    \            }\n            else {\n                dfs(next, group, edge);\n\
    \            }\n\n            descendants[now] += descendants[next] + 1;\n   \
    \     }\n\n        done[now] = true;\n        post_order.emplace_back(now, last);\n\
    \        ++last;\n\n        return put_vertex(ret, now);\n    }\n\n    void dfs_dp(long\
    \ long now, const DP& dp_p, Edge<Weight, Cap> e = Edge<Weight, Cap>()) {\n   \
    \     now = find(now);\n        long long deg = G[now].size();\n\n        if (e.rev\
    \ != -1) tree_dp[now][e.rev] = dp_p;\n\n        vector<DP> prod_l(deg + 1, id()),\
    \ prod_r(deg + 1, id());\n\n        rep(i, deg) {\n            Edge<Weight, Cap>\
    \ edge = G[now][i];\n            prod_l[i + 1] = merge(prod_l[i], put_edge(tree_dp[now][i],\
    \ edge));\n        }\n\n        repd(i, deg) {\n            Edge<Weight, Cap>\
    \ edge = G[now][i];\n            prod_r[i] = merge(prod_r[i + 1], put_edge(tree_dp[now][i],\
    \ edge));\n        }\n\n        prod_all[now] = put_vertex(prod_l.back(), now);\n\
    \n        rep(i, deg) {\n            if (i == e.rev) continue;\n\n           \
    \ Edge<Weight, Cap> edge = G[now][i];\n            long long child = edge.to;\n\
    \            dfs_dp(child, put_vertex(merge(prod_l[i], prod_r[i + 1]), now), edge);\n\
    \        }\n    }\n\n    void dfs_scc(long long now, long long group) {  // SCC\u7528\
    \n        now = find(now);\n        roots[now] = group;\n        fore(edge, rG[now])\
    \ {\n            long long next = edge.to;\n            if (roots[next] != -1)\
    \ continue;\n            dfs_scc(next, group);\n        }\n    }\n\n    Cap dfs_flow(long\
    \ long v, long long s, long long t, Cap flow) { // maxflow\u7528\n        if (v\
    \ == s) return flow;\n\n        Cap res = 0;\n        long long level_v = level[v];\n\
    \n        for (long long& i = iter[v]; i < (long long)(G[v].size()); ++i) {\n\
    \            Edge<Weight, Cap>& e = G[v][i];\n            long long next = e.to;\n\
    \n            if (level_v <= level[next] || G[next][e.rev].cap == 0) continue;\n\
    \n            Cap d = dfs_flow(next, s, t, min(flow - res, G[next][e.rev].cap));\n\
    \n            if (d <= 0) continue;\n\n            G[v][i].cap += d;\n       \
    \     G[next][e.rev].cap -= d;\n            res += d;\n\n            if (res ==\
    \ flow) return res;\n        }\n\n        level[v] = V;\n        return res;\n\
    \    }\n\n    void bfs_all() {\n        long long group = 0;\n\n        rep(i,\
    \ V) {\n            if (seen[i]) continue;\n            bfs(i, group);\n     \
    \       ++group;\n        }\n    }\n\n    void bfs(long long start, long long\
    \ group = -1) {\n        assert(0 <= start and start < V);\n        start = find(start);\n\
    \n        queue<long long> que;\n\n        // \u521D\u671F\u6761\u4EF6 (\u9802\
    \u70B9 start \u3092\u521D\u671F\u30CE\u30FC\u30C9\u3068\u3059\u308B)\n       \
    \ seen[start] = true;\n        depth[start] = 0;\n        groups[start] = group;\n\
    \        que.push(start); // noq \u3092\u6A59\u8272\u9802\u70B9\u306B\u3059\u308B\
    \n\n        // BFS \u958B\u59CB (\u30AD\u30E5\u30FC\u304C\u7A7A\u306B\u306A\u308B\
    \u307E\u3067\u63A2\u7D22\u3092\u884C\u3046)\n        while (!que.empty()) {\n\
    \            long long now = que.front(); // \u30AD\u30E5\u30FC\u304B\u3089\u5148\
    \u982D\u9802\u70B9\u3092\u53D6\u308A\u51FA\u3059\n            que.pop();\n\n \
    \           // v \u304B\u3089\u8FBF\u308C\u308B\u9802\u70B9\u3092\u3059\u3079\u3066\
    \u8ABF\u3079\u308B\n            fore(edge, G[now]) {\n                long long\
    \ next = edge.to;\n                if (seen[next]) continue; // \u3059\u3067\u306B\
    \u767A\u898B\u6E08\u307F\u306E\u9802\u70B9\u306F\u63A2\u7D22\u3057\u306A\u3044\
    \n                seen[next] = true;\n\n                // \u65B0\u305F\u306A\u767D\
    \u8272\u9802\u70B9 nv \u306B\u3064\u3044\u3066\u8DDD\u96E2\u60C5\u5831\u3092\u66F4\
    \u65B0\u3057\u3066\u30AD\u30E5\u30FC\u306B\u8FFD\u52A0\u3059\u308B\n         \
    \       depth[next] = depth[now] + 1;\n                prev[next] = edge;\n  \
    \              groups[next] = group;\n                que.push(next);\n      \
    \          doubling.front()[next] = now;\n            }\n        }\n    }\n\n\
    \    void bfs_flow(long long s, long long t) {\n        assert(0 <= s and s <\
    \ V);\n        assert(0 <= t and t < V);\n\n        fill(level.begin(), level.end(),\
    \ -1);\n        queue<long long> que;\n\n        // \u521D\u671F\u6761\u4EF6 (\u9802\
    \u70B9 start \u3092\u521D\u671F\u30CE\u30FC\u30C9\u3068\u3059\u308B)\n       \
    \ level[s] = 0;\n        que.push(s); // noq \u3092\u6A59\u8272\u9802\u70B9\u306B\
    \u3059\u308B\n\n        // BFS \u958B\u59CB (\u30AD\u30E5\u30FC\u304C\u7A7A\u306B\
    \u306A\u308B\u307E\u3067\u63A2\u7D22\u3092\u884C\u3046)\n        while (!que.empty())\
    \ {\n            long long now = que.front(); // \u30AD\u30E5\u30FC\u304B\u3089\
    \u5148\u982D\u9802\u70B9\u3092\u53D6\u308A\u51FA\u3059\n            que.pop();\n\
    \n            // v \u304B\u3089\u8FBF\u308C\u308B\u9802\u70B9\u3092\u3059\u3079\
    \u3066\u8ABF\u3079\u308B\n            fore(edge, G[now]) {\n                long\
    \ long next = edge.to;\n                if (edge.cap == 0 or level[next] >= 0)\
    \ continue; // \u3059\u3067\u306B\u767A\u898B\u6E08\u307F\u306E\u9802\u70B9\u306F\
    \u63A2\u7D22\u3057\u306A\u3044\n\n                // \u65B0\u305F\u306A\u767D\u8272\
    \u9802\u70B9 nv \u306B\u3064\u3044\u3066\u8DDD\u96E2\u60C5\u5831\u3092\u66F4\u65B0\
    \u3057\u3066\u30AD\u30E5\u30FC\u306B\u8FFD\u52A0\u3059\u308B\n               \
    \ level[next] = level[now] + 1;\n                \n                if (next ==\
    \ t) return;\n                que.push(next);\n            }\n        }\n    }\n\
    \n    void lca_init(long long root) {\n        assert(0 <= root and root < V);\n\
    \        root = find(root);\n\n        bfs(root);\n\n        rep(k, log - 1) {\n\
    \            rep(v, V) {\n                if (doubling[k][v] >= 0) {\n       \
    \             doubling[k + 1][v] = doubling[k][doubling[k][v]];\n            \
    \    }\n            }\n        }\n\n        _lca_init_done = true;\n    }\n\n\
    \    // lca_init\u5F8C\u306Bu\u3068v\u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\
    \u3092\u8FD4\u3059\n    long long lca(long long u, long long v) {\n        assert(_lca_init_done);\n\
    \        assert(0 <= u and u < V);\n        assert(0 <= v and v < V);\n      \
    \  \n        u = find(u);\n        v = find(v);\n\n        if (depth[u] < depth[v])\
    \ swap(u, v);\n\n        rep(k, log) {\n            if ((depth[u] - depth[v])\
    \ >> k & 1) {\n                u = doubling[k][u];\n            }\n        }\n\
    \n        if (u == v) return u;\n        \n        repd(k, log - 1) {\n      \
    \      if (doubling[k][u] != doubling[k][v]) {\n                u = doubling[k][u];\n\
    \                v = doubling[k][v];\n            }\n        }\n\n        return\
    \ doubling.front()[u];\n    }\n\n    // lca_init\u5F8C\u306Bu\u3068v\u306E\u8DDD\
    \u96E2\u3092\u8FD4\u3059\n    long long get_dist(long long u, long long v) {\n\
    \        assert(_lca_init_done);\n        assert(0 <= u and u < V);\n        assert(0\
    \ <= v and v < V);\n\n        u = find(u);\n        v = find(v);\n\n        return\
    \ depth[u] + depth[v] - 2 * depth[lca(u, v)];\n    }\n\n    // lca_init\u5F8C\u306B\
    u\u3068v\u3092\u7D50\u3076\u30D1\u30B9\u4E0A\u306Ba\u304C\u3042\u308B\u304B\u8FD4\
    \u3059\n    bool is_on_path(long long u, long long v, long long a) {\n       \
    \ assert(0 <= u and u < V);\n        assert(0 <= v and v < V);\n        assert(0\
    \ <= a and a < V);\n        assert(_lca_init_done);\n\n        u = find(u);\n\
    \        v = find(v);\n\n        return get_dist(u, a) + get_dist(a, v) == get_dist(u,\
    \ v);\n    }\n\n    void dijkstra_all() {\n        long long group = 0;\n\n  \
    \      rep(i, V) {\n            if (done[i]) continue;\n            dijkstra(i,\
    \ group);\n            ++group;\n        }\n    }\n\n    void dijkstra(long long\
    \ start, long long group = -1) {\n        assert(0 <= start and start < V);\n\n\
    \        start = find(start);\n\n        priority_queue<pair<long long, long long>,\
    \ vector<pair<long long, long long>>, greater<>> que;\n\n        cost[start] =\
    \ 0;\n        \n        que.emplace(cost[start], start);\n        while (!que.empty())\
    \ {\n            long long now = que.top().second;\n            que.pop();\n\n\
    \            if (done[now]) continue;  // now\u304C\u78BA\u5B9A\u6E08\u3060\u3063\
    \u305F\u3089\u98DB\u3070\u3059\n            done[now] = true;   // now\u3092\u521D\
    \u3081\u3066\u30AD\u30E5\u30FC\u304B\u3089\u53D6\u308A\u51FA\u3057\u305F\u3089\
    \u6700\u5C0F\u3068\u3057\u3066\u78BA\u5B9A\n\n            fore(edge, G[now]) {\n\
    \                long long next = edge.to;\n                if (chmin(cost[next],\
    \ cost[now] + edge.weight)) {\n                    prev[next] = edge;\n      \
    \              que.emplace(cost[next], next);\n                }\n           \
    \ }\n        }\n    }\n\n    long long find_diameter() {\n        long long ret\
    \ = 0;\n\n        rep(i, V) {\n            if (seen[i]) continue;\n          \
    \  bfs(i);\n            long long u = distance(depth.begin(), max_element(depth.begin(),\
    \ depth.end()));\n\n            init();\n            bfs(u);\n            long\
    \ long v = distance(depth.begin(), max_element(depth.begin(), depth.end()));\n\
    \            \n            chmax(ret, depth[v]);\n            init();\n      \
    \  }\n\n        return ret;\n    }\n\n    bool reach_at(long long to) {\n    \
    \    assert(0 <= to and to < V);\n        to = find(to);\n\n        return seen[to]\
    \ or done[to];\n    }\n\n    bool is_connected() {\n        bool ret = true;\n\
    \        rep(i, V) {\n            if (seen[i] or done[i]) continue;\n        \
    \    ret = false;\n            break;\n        }\n\n        return ret;\n    }\n\
    \n    vector<long long> path_to(long long to) {\n        assert(0 <= to and to\
    \ < V);\n\n        to = find(to);\n\n        vector<long long> p;\n        p.push_back(to);\n\
    \n        while (prev[p.back()].from != -1) {\n            p.push_back(prev[p.back()].from);\n\
    \        }\n\n        reverse(p.begin(), p.end());\n\n        return p;\n    }\n\
    \n    long long find_scc() {    // \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
    , \u6709\u52B9\u30B0\u30E9\u30D5\u3067\u4E92\u3044\u306B\u884C\u304D\u6765\u53EF\
    \u80FD\u306A\u9802\u70B9\u540C\u58EB\u3092\u8ABF\u3079\u308B\n        dfs_all();\n\
    \        vector<long long> v(V);\n        rep(i, V) {\n            v[post_order[i].time]\
    \ = post_order[i].index;\n        }\n        reverse(v);\n        \n        fore(index,\
    \ v) {\n            if (roots[index] != -1) continue;\n            dfs_scc(index,\
    \ index);\n        }\n\n        map<long long, set<long long>> m;\n\n        rep(i,\
    \ roots.size()) {\n            m[roots[i]].insert(i);\n        }\n\n        fore(p,\
    \ m) {\n            set<long long> s_i = p.second;\n            scc.push_back(s_i);\n\
    \        }\n\n        return (long long)scc.size();\n    }\n\n    vector<long\
    \ long> topological_sort() {\n        cost.assign(V, -1);\n        \n        std::vector<long\
    \ long> indegrees(V);\n\n        rep(i, V) {\n            indegrees[i] = rG[i].size();\n\
    \        }\n\n        queue<long long> que;\n\n        rep(i, V) {\n         \
    \   if (indegrees[i] == 0) {\n                que.push(i);\n                cost[i]\
    \ = 0;\n            }\n        }\n\n        vector<long long> ret;\n\n       \
    \ while (!que.empty()) {\n            long long now = que.front(); \n        \
    \    que.pop();\n\n            ret.push_back(now);\n\n            fore(edge, G[now])\
    \ {\n                long long next = edge.to;\n\n                if (--indegrees[next]\
    \ == 0) {\n                    que.push(next);\n                }\n\n        \
    \        if (chmax(cost[next], cost[now] + edge.weight)) {\n                 \
    \   prev[next] = edge;\n                }\n            }\n        }\n\n      \
    \  if ((long long)ret.size() != V) return {};\n\n        return ret;\n    }\n\n\
    \    bool is_same(long long u, long long v) {    // SCC\u7528, \u540C\u3058\u5F37\
    \u9023\u7D50\u6210\u5206\u306E\u30B0\u30EB\u30FC\u30D7\u304B\u3069\u3046\u304B\
    \u8FD4\u3059\n        assert(0 <= u and u < V);\n        assert(0 <= v and v <\
    \ V);\n        \n        return roots[u] == roots[v];\n    }\n\n    vector<long\
    \ long> get_longest_path() {\n        vector<long long> ret;\n\n        ll goal\
    \ = distance(cost.begin(), max_element(cost.begin(), cost.end()));\n\n       \
    \ return path_to(goal);\n    }\n\n    Cap max_flow(long long s, long long t) {\n\
    \        return max_flow(s, t, numeric_limits<Cap>::max());\n    }\n\n    Cap\
    \ max_flow(long long s, long long t, Cap flow_limit) {\n        assert(0 <= s\
    \ && s < V);\n        assert(0 <= t && t < V);\n        assert(s != t);\n\n  \
    \      Cap flow = 0;\n        while (flow < flow_limit) {\n            bfs_flow(s,\
    \ t);\n\n            if (level[s] == -1) break;\n\n            fill(iter.begin(),\
    \ iter.end(), 0);\n\n            Cap f = dfs_flow(t, s, t, flow_limit - flow);\n\
    \n            if (!f) break;\n            flow += f;\n        }\n        return\
    \ flow;\n    }\n\n    void change_edge(long long i, Cap new_cap, Cap new_flow)\
    \ {\n        long long m = edges.size();\n\n        assert(0 <= i && i < m);\n\
    \        assert(0 <= new_flow && new_flow <= new_cap);\n\n        Edge<Weight,\
    \ Cap> edge = edges[i];\n\n        auto& _e = G[edge.from][edge.rev];\n      \
    \  auto& _re = G[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n     \
    \   _re.cap = new_flow;\n    }\n\n    // max_flow(s, t)\u5F8C\u306B\u4F7F\u7528\
    \u3059\u308B\u3053\u3068\u3067s,t\u9593\u306E\u6700\u5C0F\u30AB\u30C3\u30C8\u3092\
    \u8FD4\u3059\n    vector<bool> min_cut(long long s) {\n        vector<bool> visited(V);\n\
    \n        queue<long long> que;\n        que.push(s);\n        \n        while\
    \ (!que.empty()) {\n            long long p = que.front();\n            que.pop();\n\
    \            visited[p] = true;\n\n            fore(e, G[p]) {\n             \
    \   if (e.cap && !visited[e.to]) {\n                    visited[e.to] = true;\n\
    \                    que.push(e.to);\n                }\n            }\n     \
    \   }\n        return visited;\n    }\n\n    pair<Cap, Weight> min_cost_flow(long\
    \ long s, long long t) {\n        return min_cost_flow(s, t, numeric_limits<Cap>::max());\n\
    \    }\n    \n    pair<Cap, Weight> min_cost_flow(long long s, long long t, Cap\
    \ flow_limit) {\n        return slope(s, t, flow_limit).back();\n    }\n\n   \
    \ vector<pair<Cap, Weight>> slope(long long s, long long t) {\n        return\
    \ slope(s, t, numeric_limits<Cap>::max());\n    }\n\n    vector<pair<Cap, Weight>>\
    \ slope(long long s, long long t, Cap flow_limit) {\n        assert(0 <= s &&\
    \ s < V);\n        assert(0 <= t && t < V);\n        assert(s != t);\n\n     \
    \   min_cost_slope.emplace_back(cur_flow, cur_cost);\n        \n        // primal-dual\n\
    \        while (cur_flow < flow_limit) {\n            if (!dual_step(s, t)) break;\n\
    \            primal_step(s, t, flow_limit);\n        }\n        return min_cost_slope;\n\
    \    }\n\n    bool dual_step(long long s, long long t) {\n        priority_queue<pair<Weight,\
    \ long long>, vector<pair<Weight, long long>>, greater<pair<Weight, long long>>>\
    \ que;\n        que.emplace(0, s);\n\n        dist.assign(G.size(), numeric_limits<Weight>::max());\n\
    \        dist[s] = 0;\n\n        while (!que.empty()) {\n            auto p =\
    \ que.top();\n            auto _cur_cost = p.first;\n            auto v = p.second;\n\
    \            que.pop();\n\n            if (dist[v] < _cur_cost) continue;\n  \
    \          rep(i, G[v].size()) {\n                const auto &e = G[v][i];\n \
    \               Weight new_cost = e.weight + dual[v] - dual[e.to];\n\n       \
    \         if (e.cap > 0 && dist[e.to] > dist[v] + new_cost) {\n              \
    \      dist[e.to] = dist[v] + new_cost;\n                    prevv[e.to] = v;\n\
    \                    preve[e.to] = i;\n                    que.emplace(dist[e.to],\
    \ e.to);\n                }\n            }\n        }\n        \n        if (dist[t]\
    \ == numeric_limits<Weight>::max()) return false;\n        \n        rep(v, G.size())\
    \ {\n            if (dist[t] == numeric_limits<Weight>::max()) continue;\n   \
    \         dual[v] -= dist[t] - dist[v];\n        }\n        return true;\n   \
    \ }\n\n    void primal_step(long long s, long long t, Cap flow_limit) {\n    \
    \    Cap flow = flow_limit - cur_flow;\n        Weight weight = -dual[s];\n  \
    \      for (long long v = t; v != s; v = prevv[v]) {\n            flow = min(flow,\
    \ G[prevv[v]][preve[v]].cap);\n        }\n\n        for (long long v = t; v !=\
    \ s; v = prevv[v]) {\n            auto &e = G[prevv[v]][preve[v]];\n         \
    \   auto &re = G[e.to][e.rev];\n            e.cap -= flow, e.flow += flow;\n \
    \           re.cap += flow, re.flow -= flow;\n        }\n\n        cur_flow +=\
    \ flow;\n        cur_cost += flow * weight;\n\n        if (pre_cost == weight)\
    \ min_cost_slope.pop_back();\n        min_cost_slope.emplace_back(cur_flow, cur_cost);\n\
    \        pre_cost = cur_cost;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.cpp\"\n#include \"edge.cpp\"\n#include \"\
    stamp.cpp\"\n\ntemplate<class Weight = long long, class Cap = long long, class\
    \ DP = long long>\nstruct Graph {\n    // DFS, BFS\u5171\u901A\n    long long\
    \ V;\n    bool directed_;\n    vector<vector<Edge<Weight, Cap>>> G;\n    vector<bool>\
    \ seen, done;\n    vector<Edge<Weight, Cap>> prev;\n    long long edge_index =\
    \ 0;\n    vector<Edge<Weight, Cap>> edges;\n    vector<long long> merged;\n\n\
    \    // DFS\u7528\n    vector<Stamp> pre_order, post_order;\n    long long first,\
    \ last;\n    bool has_cycle;\n    vector<long long> descendants;\n    long long\
    \ inf = inf64;\n\n    // BFS\u7528\n    vector<long long> depth;\n\n    // \u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u7528\n    vector<Weight> cost;\n\n    // LCA\u7528\
    \n    vector<vector<long long>> doubling;\n    long long log;\n    bool _lca_init_done;\n\
    \n    // \u4E8C\u90E8\u30B0\u30E9\u30D5\u7528\n    bool _is_bipartite = true;\n\
    \    vector<long long> colors;\n\n    // CC\u7528\n    vector<long long> groups;\n\
    \    vector<set<long long>> cc; \n    vector<set<long long>> cc_edge;\n\n    //\
    \ SCC\u7528\n    vector<vector<Edge<Weight, Cap>>> rG;\n    vector<long long>\
    \ roots;\n    vector<set<long long>> scc;\n\n    // \u30C8\u30DD\u30ED\u30B8\u30AB\
    \u30EB\u30BD\u30FC\u30C8\u7528\n    vector<long long> topo_dp;\n\n    // \u5168\
    \u65B9\u4F4D\u6728dp\u7528\n    vector<vector<DP>> tree_dp;\n    vector<DP> prod_all;\n\
    \    long long root_;\n\n    // maxflow\u7528\n    vector<long long> level;\n\
    \    vector<long long> iter;\n\n    // mincostflow\u7528\n    vector<Weight> dual,\
    \ dist;\n    vector<long long> prevv, preve;\n    Cap cur_flow;\n    Cap cur_cost,\
    \ pre_cost;\n    vector<pair<Cap, Weight>> min_cost_slope;\n\n    explicit Graph(long\
    \ long N, bool directed) : V(N), directed_(directed), G(V), rG(V) {\n        init();\n\
    \    };\n    \n    void init() {\n        first = 0;\n        last = 0;\n    \
    \    has_cycle = false;\n        _lca_init_done = false;\n        cur_flow = 0;\n\
    \        cur_cost = 0;\n        pre_cost = -1;\n\n        log = 1;\n        while\
    \ ((1ll << log) <= V) ++log;\n\n        seen.assign(V, false);\n        done.assign(V,\
    \ false);\n        prev.assign(V, Edge<Weight, Cap>());\n        colors.assign(V,\
    \ -1);\n        descendants.assign(V, 0);\n        roots.assign(V, -1);\n    \
    \    groups.assign(V, -1);\n        depth.assign(V, inf);\n        cost.assign(V,\
    \ inf);\n        doubling.assign(log, vector<long long>(V, -1));\n        level.assign(V,\
    \ -1);\n        iter.assign(V, 0);\n        dual.assign(V, 0);\n        dist.assign(V,\
    \ 0);\n        prevv.assign(V, -1);\n        preve.assign(V, -1);\n        topo_dp.assign(V,\
    \ -1);\n        tree_dp.resize(V);\n        prod_all.assign(V, id());\n      \
    \  merged.assign(V, -1);\n    }\n    \n    void connect(long long from, long long\
    \ to, Weight weight = 1) {\n        assert(0 <= from and from < V);\n        assert(0\
    \ <= to and to < V);\n\n        from = find(from);\n        to = find(to);\n\n\
    \        // assert(from != to);\n\n        if (directed_) {\n            long\
    \ long from_id = G[from].size();\n            long long to_id = rG[to].size();\n\
    \n            edges.emplace_back(from, to, weight, edge_index);\n\n          \
    \  G[from].emplace_back(from, to, weight, edge_index, weight, to_id);\n      \
    \      rG[to].emplace_back(to, from, weight, edge_index, weight, from_id);\n \
    \       }\n        else {\n            long long from_id = G[from].size();\n \
    \           long long to_id = G[to].size();\n\n            edges.emplace_back(from,\
    \ to, weight, edge_index, weight, from_id);\n\n            G[from].emplace_back(from,\
    \ to, weight, edge_index, weight, to_id);\n            G[to].emplace_back(to,\
    \ from, weight, edge_index, 0, from_id);\n\n            tree_dp[from].push_back(id());\n\
    \            tree_dp[to].push_back(id());\n        }\n\n        ++edge_index;\n\
    \    }\n\n    void connect(long long from, long long to, Cap cap, Weight weight)\
    \ {\n        assert(0 <= from and from < V);\n        assert(0 <= to and to <\
    \ V);\n\n        from = find(from);\n        to = find(to);\n\n        // assert(from\
    \ != to);\n\n        if (!directed_) {\n            long long from_id = G[from].size();\n\
    \            long long to_id = G[to].size();\n\n            edges.emplace_back(from,\
    \ to, weight, edge_index, cap, from_id);\n\n            G[from].emplace_back(from,\
    \ to, weight, edge_index, cap, to_id);\n            G[to].emplace_back(to, from,\
    \ -weight, edge_index, 0, from_id);\n        }\n\n        ++edge_index;\n    }\n\
    \n    long long find(long long x) { // \u30C7\u30FC\u30BFx\u304C\u5C5E\u3059\u308B\
    \u6728\u306E\u6839\u3092\u518D\u5E30\u3067\u5F97\u308B\uFF1Aroot(x) = {x\u306E\
    \u6728\u306E\u6839}\n        if (merged[x] < 0) return x;\n\n        long long\
    \ rx = find(merged[x]);\n        return merged[x] = rx;\n    }\n\n    void unite(long\
    \ long x, long long y) {\n        long long rx = find(x); //x\u306E\u6839\u3092\
    rx\n        long long ry = find(y); //y\u306E\u6839\u3092ry\n        if (rx ==\
    \ ry) return; //x\u3068y\u306E\u6839\u304C\u540C\u3058(=\u540C\u3058\u6728\u306B\
    \u3042\u308B)\u6642\u306F\u305D\u306E\u307E\u307E\n\n        // -par\u306F\u30B5\
    \u30A4\u30BA\u3092\u8FD4\u3059\n        // ry\u306E\u65B9\u304C\u30B5\u30A4\u30BA\
    \u304C\u5927\u304D\u3051\u308C\u3070rx\u3068rx\u3092\u5165\u308C\u66FF\u3048\u308B\
    \n        if (-merged[rx] < -merged[ry]) {\n            swap(rx, ry);\n      \
    \  }\n\n        merged[rx] += merged[ry]; // rx\u306E\u30B5\u30A4\u30BA\u3092\u5909\
    \u66F4\n        merged[ry] = rx; //x\u3068y\u306E\u6839\u304C\u540C\u3058\u3067\
    \u306A\u3044(=\u540C\u3058\u6728\u306B\u306A\u3044)\u6642\uFF1Ay\u306E\u6839ry\u3092\
    x\u306E\u6839rx\u306B\u3064\u3051\u308B\n\n        if (directed_) {\n        \
    \    fore(edge, G[ry]) {\n                long long from_id = G[rx].size();\n\n\
    \                G[rx].emplace_back(rx, edge.to, edge.weight, edge.id, edge.cap,\
    \ edge.rev);\n                rG[edge.to][edge.rev].to = rx;\n               \
    \ rG[edge.to][edge.rev].rev = from_id;\n            }\n\n            G[ry].clear();\n\
    \n            fore(edge, rG[ry]) {\n                long long to_id = rG[rx].size();\n\
    \n                rG[rx].emplace_back(rx, edge.to, edge.weight, edge.id, edge.cap,\
    \ edge.rev);\n                G[edge.to][edge.rev].to = rx;\n                G[edge.to][edge.rev].rev\
    \ = to_id;\n            }\n\n            rG[ry].clear();\n        }\n        else\
    \ {\n            fore(edge, G[ry]) {\n                long long from_id = G[rx].size();\n\
    \n                G[rx].emplace_back(rx, edge.to, edge.weight, edge.id, edge.cap,\
    \ edge.rev);\n                G[edge.to][edge.rev].to = rx;\n                G[edge.to][edge.rev].rev\
    \ = from_id;\n            }\n\n            G[ry].clear();\n        }\n    }\n\n\
    \    DP id() {\n        return 0;\n    }\n\n    DP merge(DP x, DP y) {\n     \
    \   return max(x, y);\n    }\n\n    DP put_edge(DP x, Edge<Weight, Cap>& edge)\
    \ {\n        return x + (DP)edge.weight;\n    }\n\n    DP put_vertex(DP x, long\
    \ long v) {\n        return x;\n    }\n\n    DP build(long long root) {\n    \
    \    root_ = root;\n        dfs(root_);\n    }\n\n    vector<DP> reroot() {\n\
    \        dfs_dp(root_, id());\n\n        return prod_all;\n    }\n\n    void dfs_all()\
    \ {\n        long long group = 0;\n\n        rep(i, V) {\n            if (seen[i])\
    \ continue;\n            dfs(i, group);\n            ++group;\n        }\n   \
    \ }\n\n    DP dfs(long long now, long long group = 0, Edge<Weight, Cap> e = Edge<Weight,\
    \ Cap>()) {\n        assert(0 <= now and now < V);\n\n        now = find(now);\n\
    \n        DP ret = id();\n\n        seen[now] = true;\n        pre_order.emplace_back(now,\
    \ first);\n        ++first;\n\n        groups[now] = group;\n        while ((long\
    \ long)cc.size() <= group) cc.push_back(set<long long>());\n        cc[group].insert(now);\n\
    \        while ((long long)cc_edge.size() <= group) cc_edge.push_back(set<long\
    \ long>());\n\n        if (colors[now] == -1) colors[now] = 0;\n        long long\
    \ next_color = !colors[now];\n\n        rep(i, G[now].size()) {\n            Edge<Weight,\
    \ Cap> edge = G[now][i];\n            long long next = edge.to;\n\n          \
    \  if (edge.id == e.id) continue;\n\n            cc_edge[group].insert(edge.id);\n\
    \n            if (colors[next] == -1) colors[next] = next_color;\n           \
    \ else if (colors[next] != next_color) _is_bipartite = false;\n\n            if\
    \ (seen[next]) {\n                if (!done[next]) has_cycle = true;\n       \
    \         continue;\n            }\n\n            prev[next] = edge;\n\n     \
    \       if (!directed_) {\n                tree_dp[now][i] = dfs(next, group,\
    \ edge);\n                ret = merge(ret, put_edge(tree_dp[now][i], edge));\n\
    \            }\n            else {\n                dfs(next, group, edge);\n\
    \            }\n\n            descendants[now] += descendants[next] + 1;\n   \
    \     }\n\n        done[now] = true;\n        post_order.emplace_back(now, last);\n\
    \        ++last;\n\n        return put_vertex(ret, now);\n    }\n\n    void dfs_dp(long\
    \ long now, const DP& dp_p, Edge<Weight, Cap> e = Edge<Weight, Cap>()) {\n   \
    \     now = find(now);\n        long long deg = G[now].size();\n\n        if (e.rev\
    \ != -1) tree_dp[now][e.rev] = dp_p;\n\n        vector<DP> prod_l(deg + 1, id()),\
    \ prod_r(deg + 1, id());\n\n        rep(i, deg) {\n            Edge<Weight, Cap>\
    \ edge = G[now][i];\n            prod_l[i + 1] = merge(prod_l[i], put_edge(tree_dp[now][i],\
    \ edge));\n        }\n\n        repd(i, deg) {\n            Edge<Weight, Cap>\
    \ edge = G[now][i];\n            prod_r[i] = merge(prod_r[i + 1], put_edge(tree_dp[now][i],\
    \ edge));\n        }\n\n        prod_all[now] = put_vertex(prod_l.back(), now);\n\
    \n        rep(i, deg) {\n            if (i == e.rev) continue;\n\n           \
    \ Edge<Weight, Cap> edge = G[now][i];\n            long long child = edge.to;\n\
    \            dfs_dp(child, put_vertex(merge(prod_l[i], prod_r[i + 1]), now), edge);\n\
    \        }\n    }\n\n    void dfs_scc(long long now, long long group) {  // SCC\u7528\
    \n        now = find(now);\n        roots[now] = group;\n        fore(edge, rG[now])\
    \ {\n            long long next = edge.to;\n            if (roots[next] != -1)\
    \ continue;\n            dfs_scc(next, group);\n        }\n    }\n\n    Cap dfs_flow(long\
    \ long v, long long s, long long t, Cap flow) { // maxflow\u7528\n        if (v\
    \ == s) return flow;\n\n        Cap res = 0;\n        long long level_v = level[v];\n\
    \n        for (long long& i = iter[v]; i < (long long)(G[v].size()); ++i) {\n\
    \            Edge<Weight, Cap>& e = G[v][i];\n            long long next = e.to;\n\
    \n            if (level_v <= level[next] || G[next][e.rev].cap == 0) continue;\n\
    \n            Cap d = dfs_flow(next, s, t, min(flow - res, G[next][e.rev].cap));\n\
    \n            if (d <= 0) continue;\n\n            G[v][i].cap += d;\n       \
    \     G[next][e.rev].cap -= d;\n            res += d;\n\n            if (res ==\
    \ flow) return res;\n        }\n\n        level[v] = V;\n        return res;\n\
    \    }\n\n    void bfs_all() {\n        long long group = 0;\n\n        rep(i,\
    \ V) {\n            if (seen[i]) continue;\n            bfs(i, group);\n     \
    \       ++group;\n        }\n    }\n\n    void bfs(long long start, long long\
    \ group = -1) {\n        assert(0 <= start and start < V);\n        start = find(start);\n\
    \n        queue<long long> que;\n\n        // \u521D\u671F\u6761\u4EF6 (\u9802\
    \u70B9 start \u3092\u521D\u671F\u30CE\u30FC\u30C9\u3068\u3059\u308B)\n       \
    \ seen[start] = true;\n        depth[start] = 0;\n        groups[start] = group;\n\
    \        que.push(start); // noq \u3092\u6A59\u8272\u9802\u70B9\u306B\u3059\u308B\
    \n\n        // BFS \u958B\u59CB (\u30AD\u30E5\u30FC\u304C\u7A7A\u306B\u306A\u308B\
    \u307E\u3067\u63A2\u7D22\u3092\u884C\u3046)\n        while (!que.empty()) {\n\
    \            long long now = que.front(); // \u30AD\u30E5\u30FC\u304B\u3089\u5148\
    \u982D\u9802\u70B9\u3092\u53D6\u308A\u51FA\u3059\n            que.pop();\n\n \
    \           // v \u304B\u3089\u8FBF\u308C\u308B\u9802\u70B9\u3092\u3059\u3079\u3066\
    \u8ABF\u3079\u308B\n            fore(edge, G[now]) {\n                long long\
    \ next = edge.to;\n                if (seen[next]) continue; // \u3059\u3067\u306B\
    \u767A\u898B\u6E08\u307F\u306E\u9802\u70B9\u306F\u63A2\u7D22\u3057\u306A\u3044\
    \n                seen[next] = true;\n\n                // \u65B0\u305F\u306A\u767D\
    \u8272\u9802\u70B9 nv \u306B\u3064\u3044\u3066\u8DDD\u96E2\u60C5\u5831\u3092\u66F4\
    \u65B0\u3057\u3066\u30AD\u30E5\u30FC\u306B\u8FFD\u52A0\u3059\u308B\n         \
    \       depth[next] = depth[now] + 1;\n                prev[next] = edge;\n  \
    \              groups[next] = group;\n                que.push(next);\n      \
    \          doubling.front()[next] = now;\n            }\n        }\n    }\n\n\
    \    void bfs_flow(long long s, long long t) {\n        assert(0 <= s and s <\
    \ V);\n        assert(0 <= t and t < V);\n\n        fill(level.begin(), level.end(),\
    \ -1);\n        queue<long long> que;\n\n        // \u521D\u671F\u6761\u4EF6 (\u9802\
    \u70B9 start \u3092\u521D\u671F\u30CE\u30FC\u30C9\u3068\u3059\u308B)\n       \
    \ level[s] = 0;\n        que.push(s); // noq \u3092\u6A59\u8272\u9802\u70B9\u306B\
    \u3059\u308B\n\n        // BFS \u958B\u59CB (\u30AD\u30E5\u30FC\u304C\u7A7A\u306B\
    \u306A\u308B\u307E\u3067\u63A2\u7D22\u3092\u884C\u3046)\n        while (!que.empty())\
    \ {\n            long long now = que.front(); // \u30AD\u30E5\u30FC\u304B\u3089\
    \u5148\u982D\u9802\u70B9\u3092\u53D6\u308A\u51FA\u3059\n            que.pop();\n\
    \n            // v \u304B\u3089\u8FBF\u308C\u308B\u9802\u70B9\u3092\u3059\u3079\
    \u3066\u8ABF\u3079\u308B\n            fore(edge, G[now]) {\n                long\
    \ long next = edge.to;\n                if (edge.cap == 0 or level[next] >= 0)\
    \ continue; // \u3059\u3067\u306B\u767A\u898B\u6E08\u307F\u306E\u9802\u70B9\u306F\
    \u63A2\u7D22\u3057\u306A\u3044\n\n                // \u65B0\u305F\u306A\u767D\u8272\
    \u9802\u70B9 nv \u306B\u3064\u3044\u3066\u8DDD\u96E2\u60C5\u5831\u3092\u66F4\u65B0\
    \u3057\u3066\u30AD\u30E5\u30FC\u306B\u8FFD\u52A0\u3059\u308B\n               \
    \ level[next] = level[now] + 1;\n                \n                if (next ==\
    \ t) return;\n                que.push(next);\n            }\n        }\n    }\n\
    \n    void lca_init(long long root) {\n        assert(0 <= root and root < V);\n\
    \        root = find(root);\n\n        bfs(root);\n\n        rep(k, log - 1) {\n\
    \            rep(v, V) {\n                if (doubling[k][v] >= 0) {\n       \
    \             doubling[k + 1][v] = doubling[k][doubling[k][v]];\n            \
    \    }\n            }\n        }\n\n        _lca_init_done = true;\n    }\n\n\
    \    // lca_init\u5F8C\u306Bu\u3068v\u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\
    \u3092\u8FD4\u3059\n    long long lca(long long u, long long v) {\n        assert(_lca_init_done);\n\
    \        assert(0 <= u and u < V);\n        assert(0 <= v and v < V);\n      \
    \  \n        u = find(u);\n        v = find(v);\n\n        if (depth[u] < depth[v])\
    \ swap(u, v);\n\n        rep(k, log) {\n            if ((depth[u] - depth[v])\
    \ >> k & 1) {\n                u = doubling[k][u];\n            }\n        }\n\
    \n        if (u == v) return u;\n        \n        repd(k, log - 1) {\n      \
    \      if (doubling[k][u] != doubling[k][v]) {\n                u = doubling[k][u];\n\
    \                v = doubling[k][v];\n            }\n        }\n\n        return\
    \ doubling.front()[u];\n    }\n\n    // lca_init\u5F8C\u306Bu\u3068v\u306E\u8DDD\
    \u96E2\u3092\u8FD4\u3059\n    long long get_dist(long long u, long long v) {\n\
    \        assert(_lca_init_done);\n        assert(0 <= u and u < V);\n        assert(0\
    \ <= v and v < V);\n\n        u = find(u);\n        v = find(v);\n\n        return\
    \ depth[u] + depth[v] - 2 * depth[lca(u, v)];\n    }\n\n    // lca_init\u5F8C\u306B\
    u\u3068v\u3092\u7D50\u3076\u30D1\u30B9\u4E0A\u306Ba\u304C\u3042\u308B\u304B\u8FD4\
    \u3059\n    bool is_on_path(long long u, long long v, long long a) {\n       \
    \ assert(0 <= u and u < V);\n        assert(0 <= v and v < V);\n        assert(0\
    \ <= a and a < V);\n        assert(_lca_init_done);\n\n        u = find(u);\n\
    \        v = find(v);\n\n        return get_dist(u, a) + get_dist(a, v) == get_dist(u,\
    \ v);\n    }\n\n    void dijkstra_all() {\n        long long group = 0;\n\n  \
    \      rep(i, V) {\n            if (done[i]) continue;\n            dijkstra(i,\
    \ group);\n            ++group;\n        }\n    }\n\n    void dijkstra(long long\
    \ start, long long group = -1) {\n        assert(0 <= start and start < V);\n\n\
    \        start = find(start);\n\n        priority_queue<pair<long long, long long>,\
    \ vector<pair<long long, long long>>, greater<>> que;\n\n        cost[start] =\
    \ 0;\n        \n        que.emplace(cost[start], start);\n        while (!que.empty())\
    \ {\n            long long now = que.top().second;\n            que.pop();\n\n\
    \            if (done[now]) continue;  // now\u304C\u78BA\u5B9A\u6E08\u3060\u3063\
    \u305F\u3089\u98DB\u3070\u3059\n            done[now] = true;   // now\u3092\u521D\
    \u3081\u3066\u30AD\u30E5\u30FC\u304B\u3089\u53D6\u308A\u51FA\u3057\u305F\u3089\
    \u6700\u5C0F\u3068\u3057\u3066\u78BA\u5B9A\n\n            fore(edge, G[now]) {\n\
    \                long long next = edge.to;\n                if (chmin(cost[next],\
    \ cost[now] + edge.weight)) {\n                    prev[next] = edge;\n      \
    \              que.emplace(cost[next], next);\n                }\n           \
    \ }\n        }\n    }\n\n    long long find_diameter() {\n        long long ret\
    \ = 0;\n\n        rep(i, V) {\n            if (seen[i]) continue;\n          \
    \  bfs(i);\n            long long u = distance(depth.begin(), max_element(depth.begin(),\
    \ depth.end()));\n\n            init();\n            bfs(u);\n            long\
    \ long v = distance(depth.begin(), max_element(depth.begin(), depth.end()));\n\
    \            \n            chmax(ret, depth[v]);\n            init();\n      \
    \  }\n\n        return ret;\n    }\n\n    bool reach_at(long long to) {\n    \
    \    assert(0 <= to and to < V);\n        to = find(to);\n\n        return seen[to]\
    \ or done[to];\n    }\n\n    bool is_connected() {\n        bool ret = true;\n\
    \        rep(i, V) {\n            if (seen[i] or done[i]) continue;\n        \
    \    ret = false;\n            break;\n        }\n\n        return ret;\n    }\n\
    \n    vector<long long> path_to(long long to) {\n        assert(0 <= to and to\
    \ < V);\n\n        to = find(to);\n\n        vector<long long> p;\n        p.push_back(to);\n\
    \n        while (prev[p.back()].from != -1) {\n            p.push_back(prev[p.back()].from);\n\
    \        }\n\n        reverse(p.begin(), p.end());\n\n        return p;\n    }\n\
    \n    long long find_scc() {    // \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
    , \u6709\u52B9\u30B0\u30E9\u30D5\u3067\u4E92\u3044\u306B\u884C\u304D\u6765\u53EF\
    \u80FD\u306A\u9802\u70B9\u540C\u58EB\u3092\u8ABF\u3079\u308B\n        dfs_all();\n\
    \        vector<long long> v(V);\n        rep(i, V) {\n            v[post_order[i].time]\
    \ = post_order[i].index;\n        }\n        reverse(v);\n        \n        fore(index,\
    \ v) {\n            if (roots[index] != -1) continue;\n            dfs_scc(index,\
    \ index);\n        }\n\n        map<long long, set<long long>> m;\n\n        rep(i,\
    \ roots.size()) {\n            m[roots[i]].insert(i);\n        }\n\n        fore(p,\
    \ m) {\n            set<long long> s_i = p.second;\n            scc.push_back(s_i);\n\
    \        }\n\n        return (long long)scc.size();\n    }\n\n    vector<long\
    \ long> topological_sort() {\n        cost.assign(V, -1);\n        \n        std::vector<long\
    \ long> indegrees(V);\n\n        rep(i, V) {\n            indegrees[i] = rG[i].size();\n\
    \        }\n\n        queue<long long> que;\n\n        rep(i, V) {\n         \
    \   if (indegrees[i] == 0) {\n                que.push(i);\n                cost[i]\
    \ = 0;\n            }\n        }\n\n        vector<long long> ret;\n\n       \
    \ while (!que.empty()) {\n            long long now = que.front(); \n        \
    \    que.pop();\n\n            ret.push_back(now);\n\n            fore(edge, G[now])\
    \ {\n                long long next = edge.to;\n\n                if (--indegrees[next]\
    \ == 0) {\n                    que.push(next);\n                }\n\n        \
    \        if (chmax(cost[next], cost[now] + edge.weight)) {\n                 \
    \   prev[next] = edge;\n                }\n            }\n        }\n\n      \
    \  if ((long long)ret.size() != V) return {};\n\n        return ret;\n    }\n\n\
    \    bool is_same(long long u, long long v) {    // SCC\u7528, \u540C\u3058\u5F37\
    \u9023\u7D50\u6210\u5206\u306E\u30B0\u30EB\u30FC\u30D7\u304B\u3069\u3046\u304B\
    \u8FD4\u3059\n        assert(0 <= u and u < V);\n        assert(0 <= v and v <\
    \ V);\n        \n        return roots[u] == roots[v];\n    }\n\n    vector<long\
    \ long> get_longest_path() {\n        vector<long long> ret;\n\n        ll goal\
    \ = distance(cost.begin(), max_element(cost.begin(), cost.end()));\n\n       \
    \ return path_to(goal);\n    }\n\n    Cap max_flow(long long s, long long t) {\n\
    \        return max_flow(s, t, numeric_limits<Cap>::max());\n    }\n\n    Cap\
    \ max_flow(long long s, long long t, Cap flow_limit) {\n        assert(0 <= s\
    \ && s < V);\n        assert(0 <= t && t < V);\n        assert(s != t);\n\n  \
    \      Cap flow = 0;\n        while (flow < flow_limit) {\n            bfs_flow(s,\
    \ t);\n\n            if (level[s] == -1) break;\n\n            fill(iter.begin(),\
    \ iter.end(), 0);\n\n            Cap f = dfs_flow(t, s, t, flow_limit - flow);\n\
    \n            if (!f) break;\n            flow += f;\n        }\n        return\
    \ flow;\n    }\n\n    void change_edge(long long i, Cap new_cap, Cap new_flow)\
    \ {\n        long long m = edges.size();\n\n        assert(0 <= i && i < m);\n\
    \        assert(0 <= new_flow && new_flow <= new_cap);\n\n        Edge<Weight,\
    \ Cap> edge = edges[i];\n\n        auto& _e = G[edge.from][edge.rev];\n      \
    \  auto& _re = G[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n     \
    \   _re.cap = new_flow;\n    }\n\n    // max_flow(s, t)\u5F8C\u306B\u4F7F\u7528\
    \u3059\u308B\u3053\u3068\u3067s,t\u9593\u306E\u6700\u5C0F\u30AB\u30C3\u30C8\u3092\
    \u8FD4\u3059\n    vector<bool> min_cut(long long s) {\n        vector<bool> visited(V);\n\
    \n        queue<long long> que;\n        que.push(s);\n        \n        while\
    \ (!que.empty()) {\n            long long p = que.front();\n            que.pop();\n\
    \            visited[p] = true;\n\n            fore(e, G[p]) {\n             \
    \   if (e.cap && !visited[e.to]) {\n                    visited[e.to] = true;\n\
    \                    que.push(e.to);\n                }\n            }\n     \
    \   }\n        return visited;\n    }\n\n    pair<Cap, Weight> min_cost_flow(long\
    \ long s, long long t) {\n        return min_cost_flow(s, t, numeric_limits<Cap>::max());\n\
    \    }\n    \n    pair<Cap, Weight> min_cost_flow(long long s, long long t, Cap\
    \ flow_limit) {\n        return slope(s, t, flow_limit).back();\n    }\n\n   \
    \ vector<pair<Cap, Weight>> slope(long long s, long long t) {\n        return\
    \ slope(s, t, numeric_limits<Cap>::max());\n    }\n\n    vector<pair<Cap, Weight>>\
    \ slope(long long s, long long t, Cap flow_limit) {\n        assert(0 <= s &&\
    \ s < V);\n        assert(0 <= t && t < V);\n        assert(s != t);\n\n     \
    \   min_cost_slope.emplace_back(cur_flow, cur_cost);\n        \n        // primal-dual\n\
    \        while (cur_flow < flow_limit) {\n            if (!dual_step(s, t)) break;\n\
    \            primal_step(s, t, flow_limit);\n        }\n        return min_cost_slope;\n\
    \    }\n\n    bool dual_step(long long s, long long t) {\n        priority_queue<pair<Weight,\
    \ long long>, vector<pair<Weight, long long>>, greater<pair<Weight, long long>>>\
    \ que;\n        que.emplace(0, s);\n\n        dist.assign(G.size(), numeric_limits<Weight>::max());\n\
    \        dist[s] = 0;\n\n        while (!que.empty()) {\n            auto p =\
    \ que.top();\n            auto _cur_cost = p.first;\n            auto v = p.second;\n\
    \            que.pop();\n\n            if (dist[v] < _cur_cost) continue;\n  \
    \          rep(i, G[v].size()) {\n                const auto &e = G[v][i];\n \
    \               Weight new_cost = e.weight + dual[v] - dual[e.to];\n\n       \
    \         if (e.cap > 0 && dist[e.to] > dist[v] + new_cost) {\n              \
    \      dist[e.to] = dist[v] + new_cost;\n                    prevv[e.to] = v;\n\
    \                    preve[e.to] = i;\n                    que.emplace(dist[e.to],\
    \ e.to);\n                }\n            }\n        }\n        \n        if (dist[t]\
    \ == numeric_limits<Weight>::max()) return false;\n        \n        rep(v, G.size())\
    \ {\n            if (dist[t] == numeric_limits<Weight>::max()) continue;\n   \
    \         dual[v] -= dist[t] - dist[v];\n        }\n        return true;\n   \
    \ }\n\n    void primal_step(long long s, long long t, Cap flow_limit) {\n    \
    \    Cap flow = flow_limit - cur_flow;\n        Weight weight = -dual[s];\n  \
    \      for (long long v = t; v != s; v = prevv[v]) {\n            flow = min(flow,\
    \ G[prevv[v]][preve[v]].cap);\n        }\n\n        for (long long v = t; v !=\
    \ s; v = prevv[v]) {\n            auto &e = G[prevv[v]][preve[v]];\n         \
    \   auto &re = G[e.to][e.rev];\n            e.cap -= flow, e.flow += flow;\n \
    \           re.cap += flow, re.flow -= flow;\n        }\n\n        cur_flow +=\
    \ flow;\n        cur_cost += flow * weight;\n\n        if (pre_cost == weight)\
    \ min_cost_slope.pop_back();\n        min_cost_slope.emplace_back(cur_flow, cur_cost);\n\
    \        pre_cost = cur_cost;\n    }\n};"
  dependsOn:
  - base.cpp
  - graph/edge.cpp
  - graph/stamp.cpp
  isVerificationFile: false
  path: graph/graph.cpp
  requiredBy: []
  timestamp: '2024-04-16 00:15:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph.cpp
layout: document
redirect_from:
- /library/graph/graph.cpp
- /library/graph/graph.cpp.html
title: graph/graph.cpp
---
