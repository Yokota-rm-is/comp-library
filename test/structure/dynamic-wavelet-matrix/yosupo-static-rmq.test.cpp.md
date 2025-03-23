---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: base.cpp
    title: base.cpp
  - icon: ':x:'
    path: other/compressor.cpp
    title: other/compressor.cpp
  - icon: ':x:'
    path: structure/dynamic-wavelet-matrix.cpp
    title: structure/dynamic-wavelet-matrix.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/structure/dynamic-wavelet-matrix/yosupo-static-rmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 2 \"\
    base.cpp\"\n\n#include <bits/stdc++.h>\n// #include <atcoder/all>\n#if __has_include(<boost/algorithm/string.hpp>)\n\
    #include <boost/algorithm/string.hpp>\n#endif\n#if __has_include(<boost/algorithm/cxx11/all_of.hpp>)\n\
    #include <boost/algorithm/cxx11/all_of.hpp>\n#include <boost/algorithm/cxx11/any_of.hpp>\n\
    #include <boost/algorithm/cxx11/none_of.hpp>\n#include <boost/algorithm/cxx11/one_of.hpp>\n\
    #endif\n#if __has_include(<boost/lambda/lambda.hpp>)\n#include <boost/lambda/lambda.hpp>\n\
    #endif\n#if __has_include(<boost/range/irange.hpp>)\n#include <boost/range/irange.hpp>\n\
    #include <boost/range/adaptors.hpp>\n#endif\n#if __has_include(<boost/multiprecision/cpp_int.hpp>)\n\
    #include <boost/multiprecision/cpp_int.hpp>\n#endif\n#if __has_include(<gmpxx.h>)\n\
    #include <gmpxx.h>\n#endif\n\nusing namespace std;\n\n// constant values\nconst\
    \ int INF32 = numeric_limits<int>::max(); //2.147483647\xD710^{9}:32bit\u6574\u6570\
    \u306Einf\nconst int inf32 = INF32 / 2;\nconst long long INF64 = numeric_limits<long\
    \ long>::max(); //9.223372036854775807\xD710^{18}:64bit\u6574\u6570\u306Einf\n\
    const long long inf64 = INF64 / 4;\nconst double EPS = numeric_limits<double>::epsilon();\
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
    #define fored(i, I) for (auto& i: (I) | views::reverse)\n#define ALL(A) A.begin(),\
    \ A.end()\n\n// for debug\n#define OVERLOAD_DEBUG(_1, _2, _3, _4, _5, _6, _7,\
    \ _8, _9, _10, name, ...) name\n#define DUMP1(a) if (DEBUG) {cerr << \"line: \"\
    \ << __LINE__ << \", \" << #a << \": \"; dump(a); cerr << endl;};\n#define DUMP2(a,\
    \ ...) if (DEBUG) {DUMP1(a); DUMP1(__VA_ARGS__);};\n#define DUMP3(a, ...) if (DEBUG)\
    \ {DUMP1(a); DUMP2(__VA_ARGS__);};\n#define DUMP4(a, ...) if (DEBUG) {DUMP1(a);\
    \ DUMP3(__VA_ARGS__);};\n#define DUMP5(a, ...) if (DEBUG) {DUMP1(a); DUMP4(__VA_ARGS__);};\n\
    #define DUMP6(a, ...) if (DEBUG) {DUMP1(a); DUMP5(__VA_ARGS__);};\n#define DUMP7(a,\
    \ ...) if (DEBUG) {DUMP1(a); DUMP6(__VA_ARGS__);};\n#define DUMP8(a, ...) if (DEBUG)\
    \ {DUMP1(a); DUMP7(__VA_ARGS__);};\n#define DUMP9(a, ...) if (DEBUG) {DUMP1(a);\
    \ DUMP8(__VA_ARGS__);};\n#define DUMP10(a, ...) if (DEBUG) {DUMP1(a); DUMP9(__VA_ARGS__);};\n\
    #define debug(...) OVERLOAD_DEBUG(__VA_ARGS__, DUMP10, DUMP9, DUMP8, DUMP7, DUMP6,\
    \ DUMP5, DUMP4, DUMP3, DUMP2, DUMP1)(__VA_ARGS__)\n\n// \u7701\u7565\nusing ushort\
    \ = unsigned short;\nusing uint = unsigned int;\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing lll = __int128_t;\nusing ulll = __uint128_t;\n\
    using vll = vector<ll>;\nusing setll = set<ll>;\nusing mapll = map<ll, ll>;\n\
    using pll = pair<ll, ll>;\nusing vpll = vector<pll>;\ntemplate<typename T> using\
    \ vec = vector<T>;\ntemplate<typename T> using vv = vector<vector<T>>;\nusing\
    \ vvll = vector<vector<long long>>;\ntemplate<typename T> using vvv = vector<vector<vector<T>>>;\n\
    using str = string;\nusing vstr = vector<str>;\nusing sstr = set<str>;\nusing\
    \ vchar = vector<char>;\nusing schar = set<char>;\nusing vd = vector<double>;\n\
    using vvd = vector<vector<double>>;\nusing vb = vector<bool>;\nusing vvb = vector<vector<bool>>;\n\
    template<typename T> using priority_queue_greater = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n// boost\u95A2\u9023\n#if __has_include(<boost/algorithm/cxx11/all_of.hpp>)\n\
    using boost::algorithm::all_of_equal;\nusing boost::algorithm::any_of_equal;\n\
    using boost::algorithm::none_of_equal;\nusing boost::algorithm::one_of_equal;\n\
    #endif\n#if __has_include(<boost/lambda/lambda.hpp>)\nusing boost::lambda::_1;\n\
    using boost::lambda::_2;\nusing boost::lambda::_3;\n#endif\n#if __has_include(<boost/multiprecision/cpp_int.hpp>)\n\
    using namespace boost::multiprecision;\n#endif\n#if __has_include(<gmpxx.h>)\n\
    #include <gmpxx.h>\nusing mpz = mpz_class;\n#endif\n\n// \u51FA\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\u6F14\u7B97\u5B50\ntemplate<typename T, typename U> ostream&\
    \ operator<< (ostream& os, pair<T, U>& p);\ntemplate<typename T, typename U> ostream&\
    \ operator<< (ostream& os, const pair<T, U>& p);\ntemplate<typename T> ostream&\
    \ operator<< (ostream& os, vector<T>& v);\ntemplate<typename T> ostream& operator<<\
    \ (ostream& os, const vector<T>& v);\nostream& operator << (ostream& os, vector<string>&\
    \ v);\nostream& operator << (ostream& os, const vector<string>& v);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, vector<vector<T>>& v);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, const vector<vector<T>>& v);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, vector<stack<T>>& v);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, const vector<stack<T>>& v);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, vector<queue<T>>& v);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, const vector<queue<T>>& v);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, vector<deque<T>>& v);\ntemplate<typename\
    \ T> ostream& operator<< (ostream& os, const vector<deque<T>>& v);\ntemplate<typename\
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
    \ T> ostream& operator << (ostream& os, vector<stack<T>>& v) { rep(i, v.size())\
    \ os << v[i] << ((i < (long long)v.size() - 1 )? \"\\n\" : \"\"); return os;}\n\
    template<typename T> ostream& operator << (ostream& os, const vector<stack<T>>&\
    \ v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1 )? \"\\n\"\
    \ : \"\"); return os;}\ntemplate<typename T> ostream& operator << (ostream& os,\
    \ vector<queue<T>>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size()\
    \ - 1 )? \"\\n\" : \"\"); return os;}\ntemplate<typename T> ostream& operator\
    \ << (ostream& os, const vector<queue<T>>& v) { rep(i, v.size()) os << v[i] <<\
    \ ((i < (long long)v.size() - 1 )? \"\\n\" : \"\"); return os;}\ntemplate<typename\
    \ T> ostream& operator << (ostream& os, vector<deque<T>>& v) { rep(i, v.size())\
    \ os << v[i] << ((i < (long long)v.size() - 1 )? \"\\n\" : \"\"); return os;}\n\
    template<typename T> ostream& operator << (ostream& os, const vector<deque<T>>&\
    \ v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size() - 1 )? \"\\n\"\
    \ : \"\"); return os;}\ntemplate<typename T> ostream& operator << (ostream& os,\
    \ vector<vector<vector<T>>>& v) { rep(i, v.size()) os << v[i] << ((i < (long long)v.size()\
    \ - 1) ? \"\\n\\n\": \"\"); return os;}\ntemplate<typename T> ostream& operator\
    \ << (ostream& os, const vector<vector<vector<T>>>& v) { rep(i, v.size()) os <<\
    \ v[i] << ((i < (long long)v.size() - 1) ? \"\\n\\n\": \"\"); return os;}\ntemplate<typename\
    \ T> ostream& operator << (ostream& os, set<T>& s) { for (auto it = s.begin();\
    \ it != s.end(); ++it) os << *it << ((it != --s.end()) ? \" \" : \"\"); return\
    \ os;}\ntemplate<typename T> ostream& operator << (ostream& os, const set<T>&\
    \ s) { for (auto it = s.begin(); it != s.end(); ++it) os << *it << ((it != --s.end())\
    \ ? \" \" : \"\"); return os;}\ntemplate<typename T, typename U> ostream& operator\
    \ << (ostream& os, map<T, U>& m) { for (auto it = m.begin(); it != m.end(); ++it)\
    \ os << it->first << \": \" << it->second << (it != --m.end() ? \"\\n\" : \"\"\
    ); return os;}\ntemplate<typename T, typename U> ostream& operator << (ostream&\
    \ os, const map<T, U>& m) { for (auto it = m.begin(); it != m.end(); ++it) os\
    \ << it->first << \": \" << it->second << (it != --m.end() ? \"\\n\" : \"\");\
    \ return os;}\ntemplate<typename T> ostream& operator << (ostream& os, queue<T>&\
    \ que) { queue<T> tmp(que); while(!tmp.empty()) {os << tmp.front() << ((tmp.size()\
    \ > 0)? \" \" : \"\\n\"); tmp.pop();}; return os;}\ntemplate<typename T> ostream&\
    \ operator << (ostream& os, const queue<T>& que) { queue<T> tmp(que); while(!tmp.empty())\
    \ {os << tmp.front() << ((tmp.size() > 0)? \" \" : \"\\n\"); tmp.pop();}; return\
    \ os;}\ntemplate<typename T> ostream& operator << (ostream& os, stack<T>& st)\
    \ { stack<T> tmp(st); while(!tmp.empty()) {os << tmp.top() << ((tmp.size() > 0)?\
    \ \" \" : \"\\n\"); tmp.pop();}; return os;}\ntemplate<typename T> ostream& operator\
    \ << (ostream& os, const stack<T>& st) { stack<T> tmp(st); while(!tmp.empty())\
    \ {os << tmp.top() << ((tmp.size() > 0)? \" \" : \"\\n\"); tmp.pop();}; return\
    \ os;}\nostream& operator<< (ostream& os, __int128_t x) { \n    if (x == 0) return\
    \ os << '0';\n    if (x < 0) {os << '-'; x = -x;}\n\n    string s; \n    for (__int128_t\
    \ y = x; y > 0; y /= 10) s += (char)('0' + y % 10); \n    reverse(s.begin(), s.end());\
    \ \n    return os << s;\n}\n\n// \u30C7\u30D0\u30C3\u30B0\u7528\ntemplate<typename\
    \ T> void dump(T a) { cerr << a;}\nvoid dump(vector<string>& a) { cerr << '\\\
    n' << a;}\ntemplate<typename T> void dump(vector<vector<T>>& a) { cerr << '\\\
    n' << a;}\ntemplate<typename T> void dump(vector<stack<T>>& a) { cerr << '\\n'\
    \ << a;}\ntemplate<typename T> void dump(vector<queue<T>>& a) { cerr << '\\n'\
    \ << a;}\ntemplate<typename T> void dump(vector<deque<T>>& a) { cerr << '\\n'\
    \ << a;}\n\ninline string YESNO(bool flag) { return flag ? \"YES\" : \"NO\";}\n\
    inline string yesno(bool flag) { return flag ? \"yes\" : \"no\";}\ninline string\
    \ YesNo(bool flag) { return flag ? \"Yes\" : \"No\";}\ninline string POSSIBLE(bool\
    \ flag) { return flag ? \"POSSIBLE\" : \"IMPOSSIBLE\";}\ninline string Possible(bool\
    \ flag) { return flag ? \"Possible\" : \"Impossible\";}\ninline string TakahashiAoki(bool\
    \ flag) { return flag ? \"Takahashi\" : \"Aoki\";}\n\n// \u7B2C\u4E00\u5F15\u6570\
    \u3068\u7B2C\u4E8C\u5F15\u6570\u3092\u6BD4\u8F03\u3057\u3001\u7B2C\u4E00\u5F15\
    \u6570(a)\u3092\u3088\u308A\u5927\u304D\u3044/\u5C0F\u3055\u3044\u5024\u306B\u4E0A\
    \u66F8\u304D\ntemplate<typename T> inline bool chmin(T &a, const T &b) { return\
    \ ((a > b) ? (a = b, true) : false);}\ntemplate<typename T> inline bool chmax(T\
    \ &a, const T &b) { return ((a < b) ? (a = b, true) : false);}\n\n#if __cplusplus\
    \ > 201703L\nusing ranges::random_access_range;\nusing ranges::bidirectional_range;\n\
    using ranges::forward_range;\nusing ranges::input_range;\nusing ranges::range_value_t;\n\
    using ranges::iterator_t;\nusing ranges::borrowed_iterator_t;\nusing ranges::range_difference_t;\n\
    \ntemplate <input_range R, class Proj = identity, indirect_unary_predicate<projected<iterator_t<R>,\
    \ Proj>> Pred> constexpr bool all_of(R&& r, Pred pred, Proj proj = {}) { return\
    \ ranges::all_of(r, pred, proj);};\ntemplate <input_range R, class Proj = identity,\
    \ indirect_unary_predicate<projected<iterator_t<R>, Proj>> Pred> constexpr bool\
    \ any_of(R&& r, Pred pred, Proj proj = {}) { return ranges::any_of(r, pred, proj);};\
    \ \ntemplate <input_range R, class Proj = identity, indirect_unary_predicate<projected<iterator_t<R>,\
    \ Proj>> Pred> constexpr bool none_of(R&& r, Pred pred, Proj proj = {}) { return\
    \ ranges::none_of(r, pred, proj);};\ntemplate <forward_range R, class Proj = identity,\
    \ indirect_strict_weak_order<projected<iterator_t<R>, Proj>> Comp = ranges::less>\
    \ constexpr bool is_sorted(R&& r, Comp comp = {}, Proj proj = {}) { return ranges::is_sorted(r,\
    \ comp, proj);};\ntemplate <forward_range R1, forward_range R2, class Proj1 =\
    \ identity, class Proj2 = identity, indirect_equivalence_relation<projected<iterator_t<R1>,\
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
    \ / y, (x % y + y) % y));}\ntemplate <typename T = unsigned long long> inline\
    \ T binpow(T x, T n) { T ret = 1; while (n) {if (n & 1) ret *= x; x *= x; n >>=\
    \ 1;} return ret; }\ntemplate <typename T = unsigned long long> inline T binpow(T\
    \ x, T n, T m) { T ret = 1; while (n) {if (n & 1) ret = (ret * x) % m; x = (x\
    \ * x) % m; n >>= 1;} return ret; }\n// mod. m \u3067\u306E a \u306E\u9006\u5143\
    \ a^{-1} \u3092\u8A08\u7B97\u3059\u308B\ntemplate<typename T> T modinv(T a, T\
    \ m) {\n    T b = m, u = 1, v = 0;\n    while (b) { T t = a / b; a -= t * b; swap(a,\
    \ b); u -= t * v; swap(u, v); }\n    u %= m;\n    if (u < 0) u += m;\n    return\
    \ u;\n}\n// combination\u3092\u6C42\u3081\u308B\nlong long nCr(long long n, long\
    \ long k, long long m = 0) {\n    if (n < k) return 0;\n    if (n - k < k) k =\
    \ n - k;\n    long long ret = 1;\n    rep(i, k) {\n        ret *= (n - i);\n \
    \       if (m > 0) ret %= m;\n    }\n    rep(i, 1, k + 1) {\n        if (m > 0)\
    \ {\n            ret *= modinv(i, m);\n            ret %= m;\n        } \n   \
    \     else ret /= i;\n    }\n    return ret;\n}\n\n// \u6700\u5927\u516C\u7D04\
    \u6570\u3092\u6C42\u3081\u308B\nlong long gcd(const vector<long long> &A) {\n\
    \    long long ret = 0;\n    rep(i, A.size()) ret = gcd(ret, A[i]);\n    return\
    \ ret;\n}\n// \u6700\u5C0F\u516C\u500D\u6570\u3092\u6C42\u3081\u308B\nlong long\
    \ lcm(const vector<long long> &A, const long long m = 0) { \n    long long ret\
    \ = 1;\n    rep(i, A.size()) { ret = lcm(ret, A[i]); if (m > 0) ret %= m;}\n \
    \   return ret;\n}\n// \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
    \u9664\u6CD5\ntuple<long long, long long, long long> extGCD(long long a, long\
    \ long b) {\n    if (b == 0) return {a, 1, 0};\n    auto [g, x, y] = extGCD(b,\
    \ a % b);\n    return {g, y, x - (a / b) * y};\n}\n\n// \u5206\u6570\u6BD4\u8F03\
    \ninline bool is_greater(long long p, long long q, long long r, long long s) {\
    \ return __int128_t(p) * s > __int128_t(q) * r;}\ninline bool is_greater_or_equal(long\
    \ long p, long long q, long long r, long long s) { return __int128_t(p) * s >=\
    \ __int128_t(q) * r;}\ninline bool is_less(long long p, long long q, long long\
    \ r, long long s) { return __int128_t(p) * s < __int128_t(q) * r;}\ninline bool\
    \ is_less_or_equal(long long p, long long q, long long r, long long s) { return\
    \ __int128_t(p) * s <= __int128_t(q) * r;}\n#if __has_include(<boost/multiprecision/cpp_int.hpp>)\n\
    inline bool is_greater(__int128_t p, __int128_t q, __int128_t r, __int128_t s)\
    \ { return int256_t(p) * s > int256_t(q) * r;}\ninline bool is_greater_or_equal(__int128_t\
    \ p, __int128_t q, __int128_t r, __int128_t s) { return int256_t(p) * s >= int256_t(q)\
    \ * r;}\ninline bool is_less(__int128_t p, __int128_t q, __int128_t r, __int128_t\
    \ s) { return int256_t(p) * s < int256_t(q) * r;}\ninline bool is_less_or_equal(__int128_t\
    \ p, __int128_t q, __int128_t r, __int128_t s) { return int256_t(p) * s <= int256_t(q)\
    \ * r;}\n#endif\n\n// string\u95A2\u4FC2\ninline string lltos(long long x) { return\
    \ to_string(x);}\ninline int ctoi(char x) { return int(x - '0');}\ninline char\
    \ itoc(int x) { return (char)(x + '0');}\n#if __has_include(<boost/algorithm/string.hpp>)\n\
    inline string to_upper(string& S) { return boost::to_upper_copy(S);}\ninline string\
    \ to_lower(string& S) { return boost::to_lower_copy(S);}\n#endif\ninline bool\
    \ is_lower(char c) { return (c >= 'a') and (c <= 'z');}\ninline bool is_upper(char\
    \ c) { return (c >= 'A') and (c <= 'Z');}\ninline char to_upper(char c) { if (is_upper(c))\
    \ return c; else return c + 'A' - 'a';}\ninline char to_lower(char c) { if (is_lower(c))\
    \ return c; else return c + 'a' - 'A';}\ninline string zero_padding(string N,\
    \ long long width) {\n    stringstream ss;\n    ss << setw(width) << setfill('0')\
    \ << N;\n    return ss.str();\n}\ninline string zero_padding(long long N, long\
    \ long width) { return zero_padding(lltos(N), width);}\ninline string to_n_base(long\
    \ long x, long long base) {\n    assert(2 <= base and base <= 36);\n    if (x\
    \ == 0) return \"0\";\n    string ret;\n    for (; x > 0; x /= base) ret += (((x\
    \ % base) < 10) ? '0' + (x % base) : 'a' + (x % base) - 10);\n    reverse(ret);\n\
    \    return ret;\n}\ninline long long to_decimal(string S, long long base) {\n\
    \    assert(2 <= base and base <= 36);\n    long long ret = 0, x = 1;\n    repd(i,\
    \ S.size()) {\n        ret += (long long)(('0' <= S[i] and S[i] <= '9') ? S[i]\
    \ - '0' : (('a' <= S[i] and S[i] <= 'z') ? S[i] = 'a' + 10 : S[i] - 'A' + 10))\
    \ * x;\n        x *= base;\n    }\n    return ret;\n}\nbool is_palindrome(const\
    \ string& S) {\n    rep(i, S.size() / 2) if (S[i] != S[S.size() - i - 1]) return\
    \ false;\n    return true;\n}\n\ntemplate<class T = long long> inline pair<T,\
    \ T> DRUL(T y, T x, char c) { return {((c == 'D') ? y + 1 : ((c == 'U') ? y -\
    \ 1 : y)), ((c == 'R') ? x + 1 : ((c == 'L') ? x - 1 : x))};}\ntemplate <typename\
    \ T> long long bubble_sort(vector<T> &A) {\n    ll ret = 0;\n    rep(i, A.size()\
    \ - 1) rep(j, A.size() - 1) if (A[j] > A[j + 1]) {\n        swap(A[j], A[j + 1]);\n\
    \        ++ret;\n    } \n    return ret;\n}\n\ntemplate<typename T> vector<T>\
    \ compress(const vector<T> &A, bool unique_id = false) {\n    long long N = A.size();\n\
    \    vector<pair<T, long long>> B;\n    rep(i, N) B.emplace_back(A[i], i);\n \
    \   sort(B.begin(), B.end());\n    vector<T> C(N);\n    ll count = 0;\n    rep(i,\
    \ N) {\n        C[B[i].second] = count;\n        if (unique_id)++count;\n    \
    \    else if (i < N - 1 and B[i].first != B[i + 1].first) ++count;\n    } \n \
    \   return C;\n}\n\n// bit\u95A2\u4FC2\nbool bit_test(long long x, long long pos)\
    \ { return (x >> pos) & 1ll; }\nlong long bit_set(long long x, long long pos,\
    \ bool flg) { return flg ? (x | (1ll << pos)) : (x & ~(1ll << pos)); }\nlong long\
    \ bit_flip(long long x, long long pos) { return x ^ (1ll << pos); }\n#if __cplusplus\
    \ > 201703L\nlong long bit_count(long long x) { return popcount((ull)x); }\n#else\
    \ \nlong long bit_count(long long x) { return __builtin_popcountll(x); }\n#endif\n\
    \n// \u914D\u5217\u95A2\u4FC2\n// \u30AD\u30FC\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\
    \u8981\u7D20\u3092\u898B\u3064\u3051\u308B\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\
    \u8FD4\u3059\u95A2\u6570\ntemplate <typename T> inline typename vector<T>::iterator\
    \ find_greater_than_or_equal(vector<T>& v, T key) { return lower_bound(v.begin(),\
    \ v.end(), key); }\ntemplate <typename T> inline typename vector<T>::iterator\
    \ find_greater_than_or_equal(typename vector<T>::iterator begin, typename vector<T>::iterator\
    \ end, T key) { return lower_bound(begin, end, key); }\ntemplate <typename T>\
    \ inline typename set<T>::iterator find_greater_than_or_equal(set<T>& st, T key)\
    \ { return st.lower_bound(key); }\n// \u30AD\u30FC\u3092\u8D85\u3048\u308B\u6700\
    \u5C0F\u306E\u8981\u7D20\u3092\u898B\u3064\u3051\u308B\u30A4\u30C6\u30EC\u30FC\
    \u30BF\u3092\u8FD4\u3059\u95A2\u6570\ntemplate <typename T> inline typename vector<T>::iterator\
    \ find_greater_than(vector<T>& v, T key) { return upper_bound(v.begin(), v.end(),\
    \ key); }\ntemplate <typename T> inline typename vector<T>::iterator find_greater_than(typename\
    \ vector<T>::iterator begin, typename vector<T>::iterator end, T key) { return\
    \ upper_bound(begin, end, key); }\ntemplate <typename T> inline typename set<T>::iterator\
    \ find_greater_than(set<T>& st, T key) { return st.upper_bound(key); }\n// \u30AD\
    \u30FC\u4EE5\u4E0B\u306E\u6700\u5927\u306E\u8981\u7D20\u3092\u898B\u3064\u3051\
    \u308B\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u8FD4\u3059\u95A2\u6570, \u306A\u3044\
    \u5834\u5408\u306Fend\u3092\u8FD4\u3059\ntemplate <typename T> inline typename\
    \ vector<T>::iterator find_less_than_or_equal(vector<T>& v, T key) { auto it =\
    \ upper_bound(v.begin(), v.end(), key); return it == v.begin() ? v.end() : --it;}\n\
    template <typename T> inline typename vector<T>::iterator find_less_than_or_equal(typename\
    \ vector<T>::iterator begin, typename vector<T>::iterator end, T key) { auto it\
    \ = upper_bound(begin, end, key); return it == begin ? end : --it;}\ntemplate\
    \ <typename T> inline typename set<T>::iterator find_less_than_or_equal(set<T>&\
    \ st, T key) { auto it = st.upper_bound(key); return it == st.begin() ? st.end()\
    \ : --it;}\n// \u30AD\u30FC\u672A\u6E80\u306E\u6700\u5927\u306E\u8981\u7D20\u3092\
    \u898B\u3064\u3051\u308B\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u8FD4\u3059\u95A2\
    \u6570, \u306A\u3044\u5834\u5408\u306Fend\u3092\u8FD4\u3059\ntemplate <typename\
    \ T> inline typename vector<T>::iterator find_less_than(vector<T>& v, T key) {\
    \ auto it = lower_bound(v.begin(), v.end(), key); return it == v.begin() ? v.end()\
    \ : --it; }\ntemplate <typename T> inline typename vector<T>::iterator find_less_than(typename\
    \ vector<T>::iterator begin, typename vector<T>::iterator end, T key) { auto it\
    \ = lower_bound(begin, end, key); return it == begin ? end : --it; }\ntemplate\
    \ <typename T> inline typename set<T>::iterator find_less_than(set<T>& st, T key)\
    \ { auto it = st.lower_bound(key); return it == st.begin() ? st.end() : --it;}\n\
    \ntemplate <typename T> auto operator+(const vector<T>& A, const T x) { vector<T>\
    \ ret(A.size()); rep(i, A.size()) ret[i] = A[i] + x; return ret; }\ntemplate <typename\
    \ T> auto operator-(const vector<T>& A, const T x) { vector<T> ret(A.size());\
    \ rep(i, A.size()) ret[i] = A[i] - x; return ret; }\ntemplate <typename T> auto\
    \ operator*(const vector<T>& A, const T x) { vector<T> ret(A.size()); rep(i, A.size())\
    \ ret[i] = A[i] * x; return ret; }\ntemplate <typename T> auto operator/(const\
    \ vector<T>& A, const T x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i]\
    \ = A[i] / x; return ret; }\ntemplate <typename T> auto operator%(const vector<T>&\
    \ A, const T x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i] = A[i] % x;\
    \ return ret; }\ntemplate <typename T> auto binpow(const vector<T>& A, const T\
    \ x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i] = binpow(A[i], x); return\
    \ ret; }\n\ntemplate <typename R> auto& operator++(R& a) { for (auto& x : a) ++x;\
    \ return a; }\ntemplate <typename R> auto operator++(R& a, int) { auto temp =\
    \ a; for (auto& x : a) x++; return temp; }\ntemplate <typename R> auto& operator--(R&\
    \ a) { for (auto& x : a) --x; return a; }\ntemplate <typename R> auto operator--(R&\
    \ a, int) { auto temp = a; for (auto& x : a) x--; return temp; }\n\ntemplate <typename\
    \ T, typename U> auto operator+(const pair<T, U>& p, const T x) { return pair<T,\
    \ U>(p.first + x, p.second + x); }\ntemplate <typename T, typename U> auto operator-(const\
    \ pair<T, U>& p, const T x) { return pair<T, U>(p.first - x, p.second - x); }\n\
    template <typename T, typename U> auto operator*(const pair<T, U>& p, const T\
    \ x) { return pair<T, U>(p.first * x, p.second * x); }\ntemplate <typename T,\
    \ typename U> auto operator/(const pair<T, U>& p, const T x) { return pair<T,\
    \ U>(p.first / x, p.second / x); }\ntemplate <typename T, typename U> auto operator%(const\
    \ pair<T, U>& p, const T x) { return pair<T, U>(p.first % x, p.second % x); }\n\
    template <typename T, typename U> auto binpow(const pair<T, U>& p, const T x)\
    \ { return pair<T, U>(binpow(p.first, x), binpow(p.second, x)); }\n\ntemplate\
    \ <typename T, typename U> auto operator+(const pair<T, U>& p, const pair<T, U>&\
    \ q) { return pair<T, U>(p.first + q.first, p.second + q.second); }\ntemplate\
    \ <typename T, typename U> auto operator-(const pair<T, U>& p, const pair<T, U>&\
    \ q) { return pair<T, U>(p.first - q.first, p.second - q.second); }\ntemplate\
    \ <typename T, typename U> auto operator*(const pair<T, U>& p, const pair<T, U>&\
    \ q) { return pair<T, U>(p.first * q.first, p.second * q.second); }\ntemplate\
    \ <typename T, typename U> auto operator/(const pair<T, U>& p, const pair<T, U>&\
    \ q) { return pair<T, U>(p.first / q.first, p.second / q.second); }\ntemplate\
    \ <typename T, typename U> auto operator%(const pair<T, U>& p, const pair<T, U>&\
    \ q) { return pair<T, U>(p.first % q.first, p.second % q.second); }\n\ntemplate\
    \ <typename T, typename U> auto& operator++(pair<T, U>& p) { ++p.first; ++p.second;\
    \ return p; }\ntemplate <typename T, typename U> auto operator++(pair<T, U>& p,\
    \ int) { auto temp = p; ++p.first; ++p.second; return temp; }\ntemplate <typename\
    \ T, typename U> auto& operator--(pair<T, U>& p) { --p.first; --p.second; return\
    \ p; }\ntemplate <typename T, typename U> auto operator--(pair<T, U>& p, int)\
    \ { auto temp = p; --p.first; --p.second; return temp; }\n\ntemplate<typename\
    \ T, typename U> vector<pair<T, U>> to_pair(const vector<T>& vec1, const vector<U>&\
    \ vec2) {\n    size_t n = min(vec1.size(), vec2.size());\n    vector<pair<T, U>>\
    \ result(n);\n    for(size_t i = 0; i < n; ++i) result.emplace_back(vec1[i], vec2[i]);\n\
    \    return result;\n}\n#line 3 \"structure/dynamic-wavelet-matrix.cpp\"\n\nenum\
    \ {\n    NOTFOUND = 0xFFFFFFFFFFFFFFFFLLU\n};\n\nstruct DynamicBitVector {\n \
    \   using ull = unsigned long long;\n    using ll = long long;\n\n    struct Node\
    \ {\n        // internal node\u306E\u3068\u304D\u306B\u4F7F\u7528\n        ull\
    \ size_l;       // \u5DE6\u306E\u5B50\u306E\u90E8\u5206\u6728\u306E\u3082\u3064\
    bit\u306E\u6570\n        ull ones_l;      // \u5DE6\u306E\u5B50\u306E\u90E8\u5206\
    \u6728\u306E\u3082\u30641\u306E\u6570\n        Node *left = 0, *right = 0;\n \
    \       ll balance;    // \u53F3\u306E\u5B50\u306E\u9AD8\u3055 - \u5DE6\u306E\u5B50\
    \u306E\u9AD8\u3055\uFF0E+\u306A\u3089\u53F3\u306E\u5B50\u306E\u65B9\u304C\u9AD8\
    \u3044\uFF0C-\u306A\u3089\u5DE6\u306E\u5B50\u306E\u65B9\u304C\u9AD8\u3044\n\n\
    \        // leaf\u306E\u3068\u304D\u306B\u4F7F\u7528\n        ull bits;      \
    \ // bit\n        ull bits_size;  // bit\u306E\u30B5\u30A4\u30BA(debug\u7528)\n\
    \n        bool is_leaf;\n\n        Node(ull bits, ull bits_size, bool is_leaf)\
    \ : size_l(0), ones_l(0), bits(bits), bits_size(bits_size), is_leaf(is_leaf),\
    \ left(nullptr), right(nullptr), balance(0) {}\n    };\n\n    using S = Node;\n\
    \    using pS = unique_ptr<S>;\n\n    pS pNIL;\n    S *NIL = nullptr;\n    vector<pS>\
    \ A;\n\n    Node *root;\n    ull N;  // \u5168\u4F53\u306Ebit\u306E\u6570\n  \
    \  ull zeros, ones;    // \u5168\u4F53\u306E0\u306E\u6570\uFF0C1\u306E\u6570\n\
    \    const ull bits_size_limit = 32;   // \u5404\u30CE\u30FC\u30C9\u304C\u7BA1\
    \u7406\u3059\u308Bbit\u306E\u9577\u3055\u5236\u9650\uFF0E2 * bits_size_limit\u4EE5\
    \u4E0A\u306B\u306A\u3063\u305F\u3089\u30CE\u30FC\u30C9\u3092\u5206\u5272\u3057\
    \uFF0C 1/2*bits_size_limit\u4EE5\u4E0B\u306B\u306A\u3063\u305F\u3089\u30CE\u30FC\
    \u30C9\u3092\u7D50\u5408\u3059\u308B\n\n    DynamicBitVector() {\n        init();\n\
    \    }\n    \n    DynamicBitVector(ull n) {\n        init();\n        rep(i, n)\
    \ push_back(0);\n    }\n\n    void init() {\n        N = 0;\n        ones = 0;\n\
    \        zeros = 0;\n\n        pNIL = make_unique<S>(0, 0, true);\n        NIL\
    \ = pNIL.get();\n        NIL->left = NIL->right = NIL;\n        root = NIL;\n\
    \    }\n\n    // B[pos]\n    ull access(ull pos) {\n        assert(pos < N);\n\
    \n        return access(root, pos);\n    }\n\n    // B[0, pos)\u306B\u3042\u308B\
    \u6307\u5B9A\u3055\u308C\u305Fbit\u306E\u6570\n    ull rank(ull bit, ull pos)\
    \ {\n        assert(bit == 0 or bit == 1);\n        assert(pos <= N);\n\n    \
    \    if (bit == 1) return rank1(root, pos, 0);\n        else return pos - rank1(root,\
    \ pos, 0);\n    }\n\n    // k\u756A\u76EE(1-indexed)\u306E\u6307\u5B9A\u3055\u308C\
    \u305Fbit\u306E\u4F4D\u7F6E(0-indexed)\n    ull select(ull bit, ull k) {\n   \
    \     assert(bit == 0 or bit == 1);\n        assert(k > 0);\n\n        if (bit\
    \ == 0 and k > zeros) return NOTFOUND;\n        if (bit == 1 and k > ones) return\
    \ NOTFOUND;\n\n        if (bit == 1) return select1(root, 0, k);\n        else\
    \ return select0(root, 0, k);\n    }\n\n    // pos(0-indexed)\u306Bbit\u3092\u633F\
    \u5165\u3059\u308B\n    void insert(ull pos, ull bit) {\n        assert(bit ==\
    \ 0 or bit == 1);\n        assert(pos <= N);  // \u73FE\u5728\u3082\u3063\u3066\
    \u308Bbits\u306E\u672B\u5C3E\u306B\u306F\u633F\u5165\u3067\u304D\u308B\n\n   \
    \     if (N == 0) {\n            pS pnx = make_unique<S>(*NIL);\n            S*\
    \ nx = pnx.get();\n            nx->bits = bit;\n            nx->bits_size = 1;\n\
    \            nx->is_leaf = true;\n            A.emplace_back(move(pnx));\n\n \
    \           root = nx;\n        } \n        else insert(root, nullptr, bit, pos,\
    \ N);\n        \n        N++;\n        ones += (bit == 1);\n        zeros += (bit\
    \ == 0);\n    }\n\n    // \u672B\u5C3E\u306Bbit\u3092\u8FFD\u52A0\u3059\u308B\n\
    \    void push_back(ull bit) {\n        assert(bit == 0 or bit == 1);\n\n    \
    \    insert(N, bit);\n    }\n\n    // pos(0-indexed)\u3092\u524A\u9664\u3059\u308B\
    \n    void erase(ull pos) {\n        assert(pos < N);\n\n        ull bit = remove(root,\
    \ nullptr, pos, N, 0, true).first;\n        N--;\n        ones -= (bit == 1);\n\
    \        zeros -= (bit == 0);\n    }\n\n    // pos(0-indexed)\u306Bbit\u3092\u30BB\
    \u30C3\u30C8\u3059\u308B\n    void update(ull pos, ull bit) {\n        assert(bit\
    \ == 0 or bit == 1);\n        assert(pos < N);\n\n        if (bit == 1) bitset(pos);\n\
    \        else bitclear(pos);\n    }\n\n    // pos(0-indexed)\u306Ebit\u30921\u306B\
    \u3059\u308B\n    void bitset(ull pos) {\n        assert(pos < N);\n\n       \
    \ bool flip = bitset(root, pos);\n        ones += flip;\n        zeros -= flip;\n\
    \    }\n\n    // pos(0-indexed)\u306Ebit\u30920\u306B\u3059\u308B\n    void bitclear(ull\
    \ pos) {\n        assert(pos < N);\n\n        bool flip = bitclear(root, pos);\n\
    \        ones -= flip;\n        zeros += flip;\n    }\n\nprivate:\n    ull access(const\
    \ Node *node, ull pos) {\n        if (node->is_leaf) {\n            assert(pos\
    \ <= 2 * bits_size_limit);\n            return (node->bits >> pos) & (ull)1;\n\
    \        }\n\n        if (pos < node->size_l) return access(node->left, pos);\n\
    \        else return access(node->right, pos - node->size_l);\n    }\n\n    ull\
    \ rank1(const Node *node, ull pos, ull num_ones) {\n        if (node->is_leaf)\
    \ {\n            assert(node->bits_size >= pos);\n            const ull mask =\
    \ ((ull)1 << pos) - 1;\n            return num_ones + bit_count(node->bits & mask);\n\
    \        }\n\n        if (pos < node->size_l) return rank1(node->left, pos, num_ones);\n\
    \        else return rank1(node->right, pos - node->size_l, num_ones + node->ones_l);\n\
    \    }\n\n    ull select1(const Node *node, ull pos, ull k) {\n        if (node->is_leaf)\
    \ {\n            return pos + select_in_block(node->bits, k);\n        }\n\n \
    \       if (k <= node->ones_l) return select1(node->left, pos, k);\n        else\
    \ return select1(node->right, pos + node->size_l, k - node->ones_l);\n    }\n\n\
    \    ull select0(const Node *node, ull pos, ull k) {\n        if (node->is_leaf)\
    \ {\n            return pos + select_in_block(~node->bits, k);\n        }\n\n\
    \        if (k <= (node->size_l - node->ones_l)) return select0(node->left, pos,\
    \ k);\n        else return select0(node->right, pos + node->size_l, k - (node->size_l\
    \ - node->ones_l));\n    }\n\n    // bits(64bit)\u306Erank\u756A\u76EE(0-indexed)\u306E\
    1\u306E\u6570\n    ull select_in_block(ull bits, ull rank) {\n        const ull\
    \ x1 = bits - ((bits & 0xAAAAAAAAAAAAAAAALLU) >> (ull)1);\n        const ull x2\
    \ = (x1 & 0x3333333333333333LLU) + ((x1 >> (ull)2) & 0x3333333333333333LLU);\n\
    \        const ull x3 = (x2 + (x2 >> (ull)4)) & 0x0F0F0F0F0F0F0F0FLLU;\n\n   \
    \     ull pos = 0;\n        for (;; pos += 8) {\n            const ull rank_next\
    \ = (x3 >> pos) & 0xFFLLU;\n            if (rank <= rank_next) break;\n      \
    \      rank -= rank_next;\n        }\n\n        const ull v2 = (x2 >> pos) & 0xFLLU;\n\
    \        if (rank > v2) {\n            rank -= v2;\n            pos += 4;\n  \
    \      }\n\n        const ull v1 = (x1 >> pos) & 0x3LLU;\n        if (rank > v1)\
    \ {\n            rank -= v1;\n            pos += 2;\n        }\n\n        const\
    \ ull v0  = (bits >> pos) & 0x1LLU;\n        if (v0 < rank) pos += 1;\n\n    \
    \    return pos;\n    }\n\n    // node\u304B\u3089\u8FBF\u308C\u308B\u8449\u306E\
    pos\u756A\u76EE\u306Bbit\u3092\u3044\u308C\u308B(\u8449\u306Ebit\u306E\u9577\u3055\
    \u306Flen)\n    // \u9AD8\u3055\u306E\u5909\u5316\u3092\u8FD4\u3059\n    ll insert(Node\
    \ *node, Node *parent, ull bit, ull pos, ull len) {\n        assert(bit == 0 or\
    \ bit == 1);\n        if (node->is_leaf) {\n            assert(pos <= 2 * bits_size_limit);\n\
    \n            // pos\u3088\u308A\u5DE6\u3092\u3068\u308A\u3060\u3059\n       \
    \     const ull up_mask = (((ull)1 << (len - pos)) - 1) << pos;\n            const\
    \ ull up = (node->bits & up_mask);\n\n            // pos\u3088\u308A\u53F3\u3092\
    \u3068\u308A\u3060\u3059\n            const ull down_mask = ((ull)1 << pos) -\
    \ 1;\n            const ull down = node->bits & down_mask;\n\n            node->bits\
    \ = (up << (ull)1) | (bit << pos) | down;\n            node->bits_size++;\n  \
    \          assert(node->bits_size == len + 1);\n\n            // bits\u306E\u30B5\
    \u30A4\u30BA\u304C\u5927\u304D\u304F\u306A\u3063\u305F\u306E\u3067\u5206\u5272\
    \u3059\u308B\n            if (len + 1 >= 2 * bits_size_limit) {\n            \
    \    split_node(node, len + 1); // \u5F15\u6570\u306Elen\u306Finsert\u5F8C\u306E\
    \u9577\u3055\u306A\u306E\u3067+1\u3059\u308B\n                return 1;\n    \
    \        }\n\n            return 0;\n        }\n\n        if (pos < node->size_l)\
    \ {\n            const ll diff = insert(node->left, node, bit, pos, node->size_l);\n\
    \            node->size_l += 1;\n            node->ones_l += (bit == 1);\n   \
    \         return achieve_balance(parent, node, diff, 0);\n        } else {\n \
    \           const ll diff = insert(node->right, node, bit, pos - node->size_l,\
    \ len - node->size_l);\n            return achieve_balance(parent, node, 0, diff);\n\
    \        }\n    }\n\n    // node\u306Epos\u756A\u76EE\u306Ebit\u3092\u524A\u9664\
    \u3059\u308B\n    // \u6D88\u3057\u305Fbit\u3068\u9AD8\u3055\u306E\u5909\u5316\
    \u306Epair\u3092\u8FD4\u3059\n    pair<ull, ll> remove(Node *node, Node *parent,\
    \ ull pos, ull len, ull num_ones, bool allow_under_flow) {\n        if (node->is_leaf)\
    \ {\n            // \u6D88\u3059\u3068under flow\u306B\u306A\u308B\u306E\u3067\
    \u6D88\u3055\u306A\u3044\n            if (node != root and len <= bits_size_limit\
    \ / 2 and not allow_under_flow) {\n                return make_pair(NOTFOUND,\
    \ 0);\n            }\n\n            assert(pos <= 2 * bits_size_limit);\n    \
    \        assert(pos < len);\n            const ull bit = (node->bits >> pos) &\
    \ (ull)1;\n\n            // pos\u3088\u308A\u5DE6\u3092\u3068\u308A\u3060\u3059\
    (pos\u3092\u542B\u307E\u306A\u3044\u3088\u3046\u306B\u3059\u308B)\n          \
    \  const ull up_mask = (((ull)1 << (len - pos - 1)) - 1) << (pos + 1);\n     \
    \       const ull up = (node->bits & up_mask);\n\n            // pos\u3088\u308A\
    \u53F3\u3092\u3068\u308A\u3060\u3059\n            const ull down_mask = ((ull)1\
    \ << pos) - 1;\n            const ull down = node->bits & down_mask;\n\n     \
    \       node->bits = (up >> (ull)1) | down;\n            node->bits_size--;\n\
    \            assert(node->bits_size == len - 1);\n\n            return make_pair(bit,\
    \ 0);\n        }\n\n        if (pos < node->size_l) {\n            const auto\
    \ bit_diff = remove(node->left, node, pos, node->size_l, node->ones_l, allow_under_flow);\n\
    \            if (bit_diff.first == NOTFOUND) {\n                return bit_diff;\n\
    \            }\n\n            node->ones_l -= (bit_diff.first == 1);\n       \
    \     // \u5DE6\u306E\u5B50\u306E\u8449\u306Ebit\u30921\u3064\u6D88\u3057\u305F\
    \u306E\u3067under flow\u304C\u767A\u751F\u3057\u3066\u3044\u308B\n           \
    \ if (node->size_l == bits_size_limit / 2) {\n                const auto b_d =\
    \ remove(node->right, node, 0, len - bits_size_limit / 2, 0, false);  // \u53F3\
    \u306E\u8449\u306E\u5148\u982Dbit\u3092\u524A\u308B\n\n                // \u53F3\
    \u306E\u8449\u3082under flow\u306B\u306A\u3063\u3066\u6D88\u305B\u306A\u3044\u5834\
    \u5408\u306F2\u3064\u306E\u8449\u3092\u7D71\u5408\u3059\u308B\n              \
    \  if (b_d.first == NOTFOUND) {\n                    assert(node->left->is_leaf);\n\
    \                    assert(node->left->bits_size == bits_size_limit / 2 - 1);\n\
    \                    // \u53F3\u306E\u5B50\u304B\u3089\u8FBF\u308C\u308B\u4E00\
    \u756A\u5DE6\u306E\u8449\u306E\u5148\u982D\u306Bleft\u306Ebits\u3092\u8FFD\u52A0\
    \u3059\u308B\n                    merge_nodes(node->right, 0, len - bits_size_limit\
    \ / 2, node->left->bits, bits_size_limit / 2 - 1, node->ones_l, true);\n     \
    \               replace(parent, node, node->right);    // parent\u306E\u5B50\u306E\
    node\u3092node->right\u306B\u7F6E\u304D\u63DB\u3048\u308B\n                  \
    \  return make_pair(bit_diff.first, -1);\n                }\n\n              \
    \  // \u53F3\u306E\u8449\u304B\u3089\u3068\u3063\u305F\u5148\u982Dbit\u3092\u5DE6\
    \u306E\u8449\u306E\u672B\u5C3E\u306B\u3044\u308C\u308B\n                assert(node->left->bits_size\
    \ == bits_size_limit / 2 - 1);\n                insert(node->left, node, b_d.first,\
    \ bits_size_limit / 2 - 1, bits_size_limit / 2 - 1);\n                node->ones_l\
    \ += (b_d.first == 1);\n            }\n            else {\n                node->size_l\
    \ -= 1;\n            }\n\n            const ll diff = achieve_balance(parent,\
    \ node, bit_diff.second, 0);\n            return make_pair(bit_diff.first, diff);\n\
    \n        } \n        else {\n            const auto bit_diff = remove(node->right,\
    \ node, pos - node->size_l, len - node->size_l, num_ones - node->ones_l, allow_under_flow);\n\
    \            if (bit_diff.first == NOTFOUND) {\n                return bit_diff;\n\
    \            }\n\n            num_ones -= (bit_diff.first == 1);\n           \
    \ // \u53F3\u306E\u5B50\u306E\u8449\u306Ebit\u30921\u3064\u6D88\u3057\u305F\u306E\
    \u3067under flow\u304C\u767A\u751F\u3059\u308B\n            if ((len - node->size_l)\
    \ == bits_size_limit / 2) {\n                const auto b_d = remove(node->left,\
    \ node, node->size_l - 1, node->size_l, 0, false);    // \u5DE6\u306E\u8449\u306E\
    \u672B\u5C3E\u3092bit\u3092\u524A\u308B\n\n                // \u5DE6\u306E\u8449\
    \u3082under flow\u306B\u306A\u3063\u3066\u6D88\u305B\u306A\u3044\u5834\u5408\u306F\
    2\u3064\u306E\u8449\u3092\u7D71\u5408\u3059\u308B\n                if (b_d.first\
    \ == NOTFOUND) {\n                    assert(node->right->is_leaf);\n        \
    \            assert(node->right->bits_size == bits_size_limit / 2 - 1);\n    \
    \                // \u5DE6\u306E\u5B50\u304B\u3089\u8FBF\u308C\u308B\u4E00\u756A\
    \u53F3\u306E\u8449\u306E\u672B\u5C3E\u306Bleft\u306Ebits\u3092\u8FFD\u52A0\u3059\
    \u308B\n                    merge_nodes(node->left, node->size_l, node->size_l,\
    \ node->right->bits, bits_size_limit / 2 - 1, num_ones - node->ones_l, false);\n\
    \                    replace(parent, node, node->left);    // parent\u306E\u5B50\
    \u306Enode\u3092node->left\u306B\u7F6E\u304D\u63DB\u3048\u308B\n             \
    \       return make_pair(bit_diff.first, -1);\n                }\n\n         \
    \       // \u5DE6\u306E\u8449\u304B\u3089\u3068\u3063\u305F\u6700\u5F8C\u5C3E\
    bit\u3092\u53F3\u306E\u8449\u306E\u5148\u982D\u306B\u3044\u308C\u308B\n      \
    \          insert(node->right, node, b_d.first, 0, bits_size_limit / 2 - 1);\n\
    \                node->size_l -= 1;\n                node->ones_l -= (b_d.first\
    \ == 1);\n            }\n\n            const ll diff = achieve_balance(parent,\
    \ node, 0, bit_diff.second);\n            return make_pair(bit_diff.first, diff);\n\
    \        }\n    }\n\n    // pos\u756A\u76EE\u306Ebit\u30921\u306B\u3059\u308B\uFF0E\
    0\u304B\u30891\u3078\u306E\u53CD\u8EE2\u304C\u8D77\u304D\u305F\u3089true\u3092\
    \u8FD4\u3059\n    bool bitset(Node *node, ull pos) {\n        if (node->is_leaf)\
    \ {\n            assert(pos <= 2 * bits_size_limit);\n            const ull bit\
    \ = (node->bits >> pos) & 1;\n            if (bit == 1) {\n                return\
    \ false;\n            }\n\n            node->bits |= ((ull)1 << pos);\n      \
    \      return true;\n        }\n\n        if (pos < node->size_l) {\n        \
    \    bool flip = bitset(node->left, pos);\n            node->ones_l += flip;\n\
    \            return flip;\n        } \n        else {\n            return bitset(node->right,\
    \ pos - node->size_l);\n        }\n    }\n\n    // pos\u756A\u76EE\u306Ebit\u3092\
    0\u306B\u3059\u308B\uFF0E1\u304B\u30890\u3078\u306E\u53CD\u8EE2\u304C\u8D77\u304D\
    \u305F\u3089true\u3092\u8FD4\u3059\n    bool bitclear(Node *node, ull pos) {\n\
    \        if (node->is_leaf) {\n            assert(pos <= 2 * bits_size_limit);\n\
    \n            const ull bit = (node->bits >> pos) & 1;\n            if (bit ==\
    \ 0) {\n                return false;\n            }\n            node->bits &=\
    \ ~((ull)1 << pos);\n            return true;\n        }\n\n        if (pos <\
    \ node->size_l) {\n            const bool flip = bitclear(node->left, pos);\n\
    \            node->ones_l -= flip;\n            return flip;\n        } \n   \
    \     else {\n            return bitclear(node->right, pos - node->size_l);\n\
    \        }\n    }\n\n    // node\u30922\u3064\u306E\u8449\u306B\u5206\u5272\u3059\
    \u308B\n    void split_node(Node *node, ull len) {\n        assert(node->is_leaf);\n\
    \        assert(node->bits_size == len);\n\n        // \u5DE6\u306E\u8449\n  \
    \      const ull left_size = len / 2;\n        const ull left_bits = node->bits\
    \ & (((ull)1 << left_size) - 1);\n        {\n            pS pnx = make_unique<S>(*NIL);\n\
    \            S* nx = pnx.get();\n            nx->bits = left_bits;\n         \
    \   nx->bits_size = left_size;\n            nx->is_leaf = true;\n            A.emplace_back(move(pnx));\n\
    \            node->left = nx;\n        }\n\n        // \u53F3\u306E\u8449\n  \
    \      const ull right_size = len - left_size;\n        const ull right_bits =\
    \ node->bits >> left_size;\n        {\n            pS pnx = make_unique<S>(*NIL);\n\
    \            S* nx = pnx.get();\n            nx->bits = right_bits;\n        \
    \    nx->bits_size = right_size;\n            nx->is_leaf = true;\n          \
    \  A.emplace_back(move(pnx));\n            node->right = nx;\n        }\n\n  \
    \      // node\u3092\u5185\u90E8\u30CE\u30FC\u30C9\u306B\u3059\u308B\n       \
    \ node->is_leaf = false;\n        node->size_l = left_size;\n        node->ones_l\
    \ = bit_count(left_bits);\n        node->bits = 0;\n        node->bits_size =\
    \ 0;\n    }\n\n    // node\u304B\u3089\u8FBF\u308C\u308B\u8449\u306Epos\u756A\u76EE\
    \u306Bbits\u3092\u683C\u7D0D\u3059\u308B\n    void merge_nodes(Node *node, ull\
    \ pos, ull len, ull bits, ull s, ull num_ones, bool left) {\n        if (node->is_leaf)\
    \ {\n            if (left) {\n                node->bits = (node->bits << s) |\
    \ bits;\n            }\n            else {\n                assert(len == node->bits_size);\n\
    \                node->bits = node->bits | (bits << len);\n            }\n   \
    \         node->bits_size += s;\n            return;\n        }\n\n        if\
    \ (pos < node->size_l) {\n            node->size_l += s;\n            node->ones_l\
    \ += num_ones;\n            merge_nodes(node->left, pos, node->size_l, bits, s,\
    \ num_ones, left);\n        }\n        else {\n            merge_nodes(node->right,\
    \ pos, len - node->size_l, bits, s, num_ones, left);\n        }\n    }\n\n   \
    \ // node\u306E\u5DE6\u306E\u9AD8\u3055\u304CleftHeightDiff\u3060\u3051\u5909\u308F\
    \u308A\uFF0C\u53F3\u306E\u9AD8\u3055\u304CrightHeightDiff\u3060\u3051\u5909\u308F\
    \u3063\u305F\u3068\u304D\u306Bnode\u3092\u4E2D\u5FC3\u306B\u56DE\u8EE2\u3055\u305B\
    \u308B\n    // \u9AD8\u3055\u306E\u5909\u5316\u3092\u8FD4\u3059\n    ll achieve_balance(Node\
    \ *parent, Node *node, ll leftHeightDiff, ll rightHeightDiff) {\n        assert(-1\
    \ <= node->balance and node->balance <= 1);\n        assert(-1 <= leftHeightDiff\
    \ and leftHeightDiff <= 1);\n        assert(-1 <= rightHeightDiff and rightHeightDiff\
    \ <= 1);\n\n        if (leftHeightDiff == 0 and rightHeightDiff == 0) {\n    \
    \        return 0;\n        }\n\n        ll heightDiff = 0;\n        // \u5DE6\
    \u304C\u9AD8\u3044\u3068\u304D\u306B\uFF0C\u5DE6\u304C\u9AD8\u304F\u306A\u308B\
    \ or \u53F3\u304C\u9AD8\u3044\u3068\u304D\u306B\u53F3\u304C\u9AD8\u304F\u306A\u308B\
    \n        if ((node->balance <= 0 and leftHeightDiff > 0) or (node->balance >=\
    \ 0 and rightHeightDiff > 0)) {\n            ++heightDiff;\n        }\n      \
    \  // \u5DE6\u304C\u9AD8\u3044\u3068\u304D\u306B\u5DE6\u304C\u4F4E\u304F\u306A\
    \u308B or \u53F3\u304C\u9AD8\u3044\u3068\u304D\u306B\u53F3\u304C\u4F4E\u304F\u306A\
    \u308B\n        if ((node->balance < 0 and leftHeightDiff < 0) or (node->balance\
    \ > 0 and rightHeightDiff < 0)) {\n            --heightDiff;\n        }\n\n  \
    \      node->balance += -leftHeightDiff + rightHeightDiff;\n        assert(-2\
    \ <= node->balance and node->balance <= 2);\n\n        // \u5DE6\u304C2\u9AD8\u3044\
    \n        if (node->balance == -2) {\n            assert(-1 <= node->left->balance\
    \ and node->left->balance <= 1);\n            if (node->left->balance != 0) {\n\
    \                heightDiff--;\n            }\n\n            if (node->left->balance\
    \ == 1) {\n                replace(node, node->left, rotate_left(node->left));\n\
    \            }\n            replace(parent, node, rotate_right(node));\n     \
    \   }\n            // \u53F3\u304C2\u9AD8\u3044\n        else if (node->balance\
    \ == 2) {\n            assert(-1 <= node->right->balance and node->right->balance\
    \ <= 1);\n            if (node->right->balance != 0) {\n                heightDiff--;\n\
    \            }\n\n            if (node->right->balance == -1) {\n            \
    \    replace(node, node->right, rotate_right(node->right));\n            }\n \
    \           replace(parent, node, rotate_left(node));\n        }\n\n        return\
    \ heightDiff;\n    }\n\n    // node B\u3092\u4E2D\u5FC3\u306B\u5DE6\u56DE\u8EE2\
    \u3059\u308B\uFF0E\u65B0\u3057\u3044\u89AA\u3092\u8FD4\u3059\n    Node *rotate_left(Node\
    \ *B) {\n        Node *D = B->right;\n\n        const ll heightC = 0;\n      \
    \  const ll heightE = heightC + D->balance;\n        const ll heightA = max(heightC,\
    \ heightE) + 1 - B->balance;\n\n        B->right = D->left;\n        D->left =\
    \ B;\n\n        B->balance = heightC - heightA;\n        D->size_l += B->size_l;\n\
    \        D->ones_l += B->ones_l;\n        D->balance = heightE - (max(heightA,\
    \ heightC) + 1);\n\n        assert(-2 <= B->balance and B->balance <= 2);\n  \
    \      assert(-2 <= D->balance and D->balance <= 2);\n\n        return D;\n  \
    \  }\n\n    // node D\u3092\u4E2D\u5FC3\u306B\u53F3\u56DE\u8EE2\u3059\u308B\uFF0E\
    \u65B0\u3057\u3044\u89AA\u3092\u8FD4\u3059\n    Node *rotate_right(Node *D) {\n\
    \        Node *B = D->left;\n\n        const ll heightC = 0;\n        const ll\
    \ heightA = heightC - B->balance;\n        const ll heightE = max(heightA, heightC)\
    \ + 1 + D->balance;\n\n        D->left = B->right;\n        B->right = D;\n\n\
    \        D->size_l -= B->size_l;\n        D->ones_l -= B->ones_l;\n        D->balance\
    \ = heightE - heightC;\n        B->balance = max(heightC, heightE) + 1 - heightA;\n\
    \n\n        assert(-2 <= B->balance and B->balance <= 2);\n        assert(-2 <=\
    \ D->balance and D->balance <= 2);\n\n        return B;\n    }\n\n    // parent\u306E\
    \u5B50\u306EoldNode\u3092newNode\u306B\u7F6E\u304D\u63DB\u3048\u308B\n    void\
    \ replace(Node *parent, Node *oldNode, Node *newNode) {\n        if (parent ==\
    \ nullptr) {\n            root = newNode;\n            return;\n        }\n\n\
    \        if (parent->left == oldNode) {\n            parent->left = newNode;\n\
    \        }\n        else if (parent->right == oldNode) {\n            parent->right\
    \ = newNode;\n        }\n        else {\n            throw \"old node is not child\"\
    ;\n        }\n    }\n};\n\ntemplate <typename T>\nstruct DynamicWaveletMatrix\
    \ {\n    using ull = unsigned long long;\n\n    vector<DynamicBitVector> bit_vectors;\n\
    \    map<T, ull> values;\n    T max_val;\n\n    ull N;  // \u4E0E\u3048\u3089\u308C\
    \u305F\u914D\u5217\u306E\u30B5\u30A4\u30BA\n    ull bit_size;   // \u6587\u5B57\
    \u3092\u8868\u3059\u306E\u306B\u5FC5\u8981\u306Abit\u6570\n\n    T NOTFOUND =\
    \ numeric_limits<T>::max() / 2;\n\n    DynamicWaveletMatrix (const T max_v) {\n\
    \        init(max_v);\n    }\n\n    DynamicWaveletMatrix (const T max_v, const\
    \ vector<T> &A) {\n        init(max_v);\n        rep(i, A.size()) push_back(A[i]);\n\
    \    }\n\n    DynamicWaveletMatrix (const T max_v, ull n, T a) {\n        init(max_v);\n\
    \        rep(i, n) push_back(a);\n    }\n\n    void init(T max_v) {\n        N\
    \ = 0;\n        bit_size = 0;\n        max_val = max_v;\n\n        while (T(1ull\
    \ << bit_size) <= max_val + 1) ++bit_size;\n\n        bit_vectors.resize(bit_size);\n\
    \    }\n\n    // v[pos]\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    T access(ull\
    \ pos) {\n        assert(pos < N);\n\n        T val = 0;\n        repd(h, bit_size)\
    \ {\n            ull bit = bit_vectors[h].access(pos);   // \u3082\u3068\u306E\
    \u6570\u5024\u306Ei\u756A\u76EE\u306Ebit\n            if (bit == 1) {\n      \
    \          val |= (1ull << h);\n                pos = bit_vectors[h].rank(1, pos)\
    \ + bit_vectors[h].zeros;\n            }\n            else {\n               \
    \ pos = bit_vectors[h].rank(0, pos);\n            }\n        }\n        return\
    \ val;\n    }\n\n    // pos\u306Bc\u3092\u633F\u5165\u3059\u308B\n    void insert(ull\
    \ pos, T val) {\n        assert(pos <= N);\n        ++N;\n        values[val]\
    \ += 1;\n\n        repd(h, bit_size) {\n            const ull bit = (val >> h)\
    \ & 1;  //\u3000\u4E0A\u304B\u3089i\u756A\u76EE\u306Ebit\n            bit_vectors[h].insert(pos,\
    \ bit);\n            pos = bit_vectors[h].rank(bit, pos);\n            if (bit\
    \ == 1) pos += bit_vectors[h].zeros;\n        }\n    }\n\n    // pos\u3092\u524A\
    \u9664\u3059\u308B\n    void erase(ull pos) {\n        assert(pos < N);\n\n  \
    \      T val = access(pos);\n        values[val] -= 1;\n        --N;\n\n     \
    \   repd(h, bit_size) {\n            ull bit = bit_vectors[h].access(pos);   //\
    \ \u3082\u3068\u306E\u6570\u5024\u306Ei\u756A\u76EE\u306Ebit\n\n            auto\
    \ next_pos = bit_vectors[h].rank(bit, pos);\n            bit_vectors[h].erase(pos);\n\
    \n            if (bit == 1) next_pos += bit_vectors[h].zeros;\n\n            pos\
    \ = next_pos;\n        }\n    }\n\n    void set(ull pos, T val) {\n        assert(pos\
    \ < N);\n\n        T old_val = access(pos);\n        if (old_val == val) return;\n\
    \n        erase(pos);\n        insert(pos, val);\n    }\n\n    void add(ull pos,\
    \ T val) {\n        assert(pos < N);\n\n        T old_val = access(pos);\n   \
    \     set(pos, old_val + val);\n    }\n\n    void push_back(T val) {\n       \
    \ insert(N, val);\n    }\n\n    void pop_back() {\n        erase(N - 1);\n   \
    \ }\n\n    void push_front(T val) {\n        insert(0, val);\n    }\n\n    void\
    \ pop_front() {\n        erase(0);\n    }\n\n    // k\u756A\u76EE(1-indexed)\u306E\
    val\u306E\u4F4D\u7F6E(0-indexed)\u3092\u8FD4\u3059\n    // \u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u306FN\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n\
    \    ull select(T val, ull k) {\n        assert(k > 0);\n        if (!values.contains(val))\
    \ return N;\n\n        ull left = 0;\n        repd(h, bit_size) {\n          \
    \  const ull bit = (val >> h) & 1;  // \u4E0A\u304B\u3089i\u756A\u76EE\u306Ebit\n\
    \            left = bit_vectors[h].rank(bit, left);               // c\u306Ei\u756A\
    \u76EE\u306Ebit\u3068\u540C\u3058\u6570\u5024\u306E\u6570\n            if (bit)\
    \ left += bit_vectors[h].zeros;\n        }\n\n        ull index = left + k;\n\
    \        rep(h, bit_size){\n            ull bit = ((val >> h) & 1); // \u4E0B\u304B\
    \u3089i\u756A\u76EE\u306Ebit\n            if (bit == 1) {\n                index\
    \ -= bit_vectors[h].zeros;\n            }\n\n            index = bit_vectors[h].select(bit,\
    \ index) + 1;\n        }\n        return index;\n    }\n\n    // v[l, r)\u3067\
    k\u756A\u76EE\u306B\u5927\u304D\u3044\u6570\u5024\u3068index\u3092\u8FD4\u3059\
    (k\u306F1-indexed)\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    T kth_max(ull\
    \ l, ull r, ull k) {\n        assert(l < r and r <= N and 0 < k and k <= r - l);\n\
    \        return quantile(l, r, r - l - k);\n    }\n\n    // v[l, r)\u3067k\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u6570\u5024\u3068index\u3092\u8FD4\u3059(k\u306F\
    1-indexed)\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    T kth_min(ull l,\
    \ ull r, ull k) {\n        assert(l < r and r <= N and 0 < k and k <= r - l);\n\
    \        return quantile(l, r, k - 1);\n    }\n\n    // v[l, r)\u306E\u4E2D\u592E\
    \u5024(\u5207\u308A\u6368\u3066)\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF\
    : O(log(bit_size))\n    T median(ull l, ull r) {\n        assert(l < r and r <=\
    \ N);\n        return (quantile(l, r, floor(r - l + 1, 2) - 1) + quantile(l, r,\
    \ ceil(r - l + 1, 2) - 1)) / 2;\n    }\n\n    // v[l, r)\u3067k\u756A\u76EE(0-indexed)\u306B\
    \u5C0F\u3055\u3044\u6570\u5024\u3068index(0-indexed)\u3092\u8FD4\u3059\n    //\
    \ \u5C0F\u3055\u3044\u9806\u306B\u4E26\u3079\u3066k\u756A\u76EE\u306E\u5024\n\
    \    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    T quantile(ull l, ull r, ull\
    \ k) {\n        assert(l < r and r <= N and k < r - l);\n\n        ull val = 0;\n\
    \        repd(h, bit_size) {\n            const ull num_zero_l = bit_vectors[h].rank(0,\
    \ l);\n            const ull num_zero_r = bit_vectors[h].rank(0, r);\n       \
    \     const ull zeros = num_zero_r - num_zero_l;    // l\u304B\u3089end\u307E\u3067\
    \u306B\u3042\u308B0\u306E\u6570\n            const ull bit = (k >= zeros);   //\
    \ k\u756A\u76EE\u306E\u5024\u306E\u4E0A\u304B\u3089i\u756A\u76EE\u306Ebit\u304C\
    0\u304B1\u304B\n\n            if (bit == 1) {\n                k -= zeros;\n \
    \               l = bit_vectors[h].zeros + l - num_zero_l;\n                r\
    \ = bit_vectors[h].zeros + r - num_zero_r;\n            }\n            else {\n\
    \                l = num_zero_l;\n                r = num_zero_l + zeros;\n  \
    \          }\n\n            val = (val << 1) | bit;\n        }\n\n        return\
    \ val;\n    }\n\n    // v[0, pos)\u306Eval\u306E\u6570\n    // \u8A08\u7B97\u91CF\
    : O(log(bit_size))\n    ull rank(T val, ull pos) {\n        assert(pos <= N);\n\
    \        if (pos == 0) return 0;\n        if (!values.contains(val)) return 0;\n\
    \n        ull left = 0, right = pos;\n        repd(h, bit_size) {\n          \
    \  ull bit = (val >> h) & 1;  // \u4E0A\u304B\u3089i\u756A\u76EE\u306Ebit\n  \
    \          left = bit_vectors[h].rank(bit, left);             // c\u306Ei\u756A\
    \u76EE\u306Ebit\u3068\u540C\u3058\u6570\u5024\u306E\u6570\n            right =\
    \ bit_vectors[h].rank(bit, right);           // c\u306Ei\u756A\u76EE\u306Ebit\u3068\
    \u540C\u3058\u6570\u5024\u306E\u6570\n            if (bit) {\n               \
    \ left += bit_vectors[h].zeros;\n                right += bit_vectors[h].zeros;\n\
    \            }\n        }\n\n        return right - left;\n    }\n\n    // v[l,\
    \ r)\u306Eval\u306E\u6570\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    ull\
    \ rank(T val, ull l, ull r) {\n        assert(l <= r and r <= N);\n        if\
    \ (l == r) return 0;\n        if (!values.contains(val)) return 0;\n\n       \
    \ return rank(val, r) - rank(val, l);\n    }\n\n    // v[0, pos)\u306Eval\u306E\
    \u6570\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    ull count(ull l, ull\
    \ r, T val) {\n        return rank(val, l, r);\n    }\n\n    // v[0, pos)\u3067\
    val\u3088\u308A\u5C0F\u3055\u3044\u5024\u306E\u6570\u3092\u8FD4\u3059\n    //\
    \ \u8A08\u7B97\u91CF: O(log(bit_size))\n    ull count_less_than(ull pos, T val)\
    \ {\n        assert(pos <= N);\n\n        if (val <= values.begin()->first) return\
    \ 0;\n        if (val > values.rbegin()->first) return pos;\n\n        ull ret\
    \ = 0;\n        ull l = 0, r = pos;\n        repd(h, bit_size) {\n           \
    \ if (l >= r) break;\n            const ull bit = (val >> h) & 1;\n\n        \
    \    const ull rank0_l = bit_vectors[h].rank(0, l);\n            const ull rank0_r\
    \ = bit_vectors[h].rank(0, r);\n            const ull rank1_l = l - rank0_l;\n\
    \            const ull rank1_r = r - rank0_r;\n\n            if (bit == 1) {\n\
    \                ret += (rank0_r - rank0_l);    // i\u756A\u76EE\u306Ebit\u304C\
    0\u306E\u3082\u306E\u306F\u9664\u5916\u3055\u308C\u308B\n                l = bit_vectors[h].zeros\
    \ + rank1_l;\n                r = bit_vectors[h].zeros + rank1_r;\n          \
    \  } \n            else {\n                l = rank0_l;\n                r = rank0_r;\n\
    \            }\n        }\n\n        return ret;\n    }\n\n    // v[l, r)\u3067\
    val\u3088\u308A\u5C0F\u3055\u3044\u5024\u306E\u6570\u3092\u8FD4\u3059\n    //\
    \ \u8A08\u7B97\u91CF: O(log(bit_size))\n    ull count_less_than(ull l, ull r,\
    \ T val) {\n        assert(l <= r and r <= N);\n        if (l == r) return 0;\n\
    \n        return count_less_than(r, val) - count_less_than(l, val);\n    }\n\n\
    \    // v[0, pos)\u3067val\u3088\u308A\u5927\u304D\u3044\u5024\u306E\u6570\u3092\
    \u8FD4\u3059\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    ull count_more_than(ull\
    \ pos, T val) {\n        assert(pos <= N);\n\n        if (val >= values.rbegin()->first)\
    \ return 0;\n        if (val < values.begin()->first) return pos;\n\n        ull\
    \ ret = 0;\n        ull l = 0, r = pos;\n        repd(h, bit_size) {\n       \
    \     const ull bit = (val >> h) & 1;\n\n            const ull rank0_l = bit_vectors[h].rank(0,\
    \ l);\n            const ull rank0_r = bit_vectors[h].rank(0, r);\n          \
    \  const ull rank1_l = l - rank0_l;\n            const ull rank1_r = r - rank0_r;\n\
    \n            if (bit == 1) {\n                l = bit_vectors[h].zeros + rank1_l;\n\
    \                r = bit_vectors[h].zeros + rank1_r;\n            }\n        \
    \    else {\n                ret += (rank1_r - rank1_l);    // i\u756A\u76EE\u306E\
    bit\u304C1\u306E\u3082\u306E\u306F\u9664\u5916\u3055\u308C\u308B\n           \
    \     l = rank0_l;\n                r = rank0_r;\n            } \n        }\n\n\
    \        return ret;\n    }\n\n    // v[l, r)\u3067val\u3088\u308A\u5927\u304D\
    \u3044\u5024\u306E\u6570\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n\
    \    ull count_more_than(ull l, ull r, T val) {\n        assert(l <= r and r <=\
    \ N);\n        if (l == r) return 0;\n        return count_more_than(r, val) -\
    \ count_more_than(l, val);\n    }\n\n    // v[l, r)\u3067[lower, upper)\u306B\u5165\
    \u308B\u5024\u306E\u500B\u6570\u3092\u8FD4\u3059\n    ull count_in_range(ull l,\
    \ ull r, T lower, T upper) {\n        assert(l <= r and r <= N and lower <= upper);\n\
    \        if (l == r) return 0;\n        if (lower == upper) return 0;\n\n    \
    \    return count_less_than(l, r, upper) - count_less_than(l, r, lower);\n   \
    \ }\n\n    // v[l, r)\u3067\u983B\u5EA6\u304C\u9AD8\u3044\u9806\u306Bk\u500B\u306E\
    (\u5024\uFF0C\u983B\u5EA6)\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF: O(min(r\
    \ - l, k)log(bit_size)\n    vector<pair<T, ull>> top_k(ull l, ull r, ull k) {\n\
    \        // (\u983B\u5EA6\uFF0C\u6DF1\u3055\uFF0C\u5024)\u306E\u9806\u3067\u30BD\
    \u30FC\u30C8\n        auto comp = [](const tuple<ull, ull, ull, ull, T> &left,\
    \ const tuple<ull, ull, ull, ull, T> &right) {\n            // width\n       \
    \     if (get<0>(left) != get<0>(right)) {\n                return get<0>(left)\
    \ < get<0>(right);\n            }\n            // height\n            if (get<3>(left)\
    \ != get<3>(right)) {\n                return get<3>(left) > get<3>(right);\n\
    \            }\n            // value\n            if (get<4>(left) != get<4>(right))\
    \ {\n                return get<4>(left) > get<4>(right);\n            }\n   \
    \         return true;\n        };\n\n        return top_k(l, r, k, comp);\n \
    \   }\n\n    // v[l, r)\u3067\u5024\u304C\u5927\u304D\u3044\u9806\u306Bk\u500B\
    \u306E(\u5024\uFF0C\u983B\u5EA6)\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF\
    : O(min(r - l, k)log(bit_size)\n    vector<pair<T, ull>> max_k(ull l, ull r, ull\
    \ k) {\n        // (\u5024\uFF0C\u983B\u5EA6)\u306E\u9806\u3067\u30BD\u30FC\u30C8\
    \n        auto comp = [](const tuple<ull, ull, ull, ull, T> &left, const tuple<ull,\
    \ ull, ull, ull, T> &right) {\n            // value\n            if (get<4>(left)\
    \ != get<4>(right)) {\n                return get<4>(left) > get<4>(right);\n\
    \            }\n            // width\n            if (get<0>(left) != get<0>(right))\
    \ {\n                return get<0>(left) < get<0>(right);\n            }\n   \
    \         // height\n            if (get<3>(left) != get<3>(right)) {\n      \
    \          return get<3>(left) > get<3>(right);\n            }\n            return\
    \ true;\n        };\n\n        return top_k(l, r, k, comp);\n    }\n\n    // v[l,\
    \ r)\u3067\u5024\u304C\u5C0F\u3055\u3044\u9806\u306Bk\u500B\u306E(\u5024\uFF0C\
    \u983B\u5EA6)\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF: O(min(r - l, k)log(bit_size)\n\
    \    vector<pair<T, ull>> min_k(ull l, ull r, ull k) {\n        // (\u5024\uFF0C\
    \u983B\u5EA6)\u306E\u9806\u3067\u30BD\u30FC\u30C8\n        auto comp = [](const\
    \ tuple<ull, ull, ull, ull, T> &left, const tuple<ull, ull, ull, ull, T> &right)\
    \ {\n            // value\n            if (get<4>(left) != get<4>(right)) {\n\
    \                return get<4>(left) < get<4>(right);\n            }\n       \
    \     // width\n            if (get<0>(left) != get<0>(right)) {\n           \
    \     return get<0>(left) < get<0>(right);\n            }\n            // height\n\
    \            if (get<3>(left) != get<3>(right)) {\n                return get<3>(left)\
    \ > get<3>(right);\n            }\n            return true;\n        };\n\n  \
    \      return top_k(l, r, k, comp);\n    }\n\n    // T[l, r)\u3067\u51FA\u73FE\
    \u56DE\u6570\u304C\u591A\u3044\u9806\u306Bk\u500B\u306E(\u5024\uFF0C\u983B\u5EA6\
    )\u3092\u8FD4\u3059\n    // \u983B\u5EA6\u304C\u540C\u3058\u5834\u5408\u306F\u5024\
    \u304C\u5C0F\u3055\u3044\u3082\u306E\u304C\u512A\u5148\u3055\u308C\u308B\n   \
    \ // \u8A08\u7B97\u91CF: O(min(r - l, k)log(bit_size)\n    vector<pair<T, ull>>\
    \ top_k(ull l, ull r, ull k, auto comp) {\n        assert(l <= r and r <= N);\n\
    \        vector<pair<T, ull>> result;\n\n        priority_queue<tuple<ull, ull,\
    \ ull, ull, T>, vector<tuple<ull, ull, ull, ull, T>>, decltype(comp)> que(comp);\
    \  // width, height, value, left, right\n        que.emplace(r - l, l, r, bit_size\
    \ - 1, 0);\n\n        while (!que.empty()) {\n            auto element = que.top();\
    \ que.pop();\n            ull width, left, right, height;\n            T value;\n\
    \            tie(width, left, right, height, value) = element;\n\n           \
    \ if (height == 0) {\n                result.emplace_back(value, right - left);\n\
    \                if (result.size() >= k) break;\n                \n          \
    \      continue;\n            }\n\n            // 0\n            const ull left0\
    \ = bit_vectors[height].rank(0, left);\n            const ull right0 = bit_vectors[height].rank(0,\
    \ right);\n            if (left0 < right0) {\n                que.emplace(right0\
    \ - left0, left0, right0, height - 1, value);\n            }\n\n            //\
    \ 1\n            const ull left1 = bit_vectors[height].zeros + bit_vectors[height].rank(1,\
    \ left);\n            const ull right1 = bit_vectors[height].zeros + bit_vectors[height].rank(1,\
    \ right);\n            if (left1 < right1) {\n                que.emplace(right1\
    \ - left1, left1, right1, height - 1, value | (1ull << height));\n           \
    \ }\n        }\n\n        return result;\n    };\n\n    // T[l, r)\u3067lower\
    \ <= val < upper\u3092\u6E80\u305F\u3059\u6700\u5927\u306Eval\u3092\u8FD4\u3059\
    \n    // \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306FNOTFOUND\u3092\u8FD4\u3059\
    \n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    ull prev_value(ull l, ull r,\
    \ T lower, T upper) {\n        assert(l <= r and r <= N);\n\n        if (l ==\
    \ r) return NOTFOUND;\n        if (lower >= upper) return NOTFOUND;\n        if\
    \ (lower > values.rbegin()->first) return NOTFOUND;\n        if (upper <= values.begin()->first)\
    \ return NOTFOUND;\n\n        --upper; // lower <= val <= upper\u306B\u3059\u308B\
    \n\n        if (upper > max_val) upper = max_val;\n\n        stack<tuple<ull,\
    \ ull, ull, T, bool>> st;   // (l, r, depth, val, tight)\n        st.emplace(l,\
    \ r, 0, 0, true);\n\n        while (!st.empty()) {\n            ull l, r, depth;\n\
    \            T val;\n            bool tight;\n            tie(l, r, depth, val,\
    \ tight) = st.top(); st.pop();\n\n            if (depth == bit_size) {\n     \
    \           if (val >= lower) return val;\n                \n                continue;\n\
    \            }\n\n            ull height = bit_size - depth - 1;\n\n         \
    \   const ull bit = (upper >> height) & 1;\n\n            const ull rank0_l =\
    \ bit_vectors[height].rank(0, l);\n            const ull rank0_r = bit_vectors[height].rank(0,\
    \ r);\n            const ull rank1_l = l - rank0_l;\n            const ull rank1_r\
    \ = r - rank0_r;\n\n            // d\u756A\u76EE\u306Ebit\u304C0\u306E\u3082\u306E\
    \u3092\u4F7F\u3046\n            const ull l0 = rank0_l;\n            const ull\
    \ r0 = rank0_r;\n            if (l0 != r0) { // \u7BC4\u56F2\u304C\u3064\u3076\
    \u308C\u3066\u306A\u3044\n                const ull val0 = val << 1;\n       \
    \         st.emplace(l0, r0, depth + 1, val0, tight and bit == 0);\n         \
    \   }\n\n            // d\u756A\u76EE\u306Ebit\u304C1\u306E\u3082\u306E\u3092\u4F7F\
    \u3046\n            const ull l1 = bit_vectors[height].zeros + rank1_l;\n    \
    \        const ull r1 = bit_vectors[height].zeros + rank1_r;\n            if (l1\
    \ != r1) {\n                if (!tight or bit == 1) {\n                    const\
    \ auto val1 = ((val << 1) | 1);\n                    st.emplace(l1, r1, depth\
    \ + 1, val1, tight);\n                }\n            }\n        }\n\n        return\
    \ NOTFOUND;\n    }\n\n    // T[l, r)\u3067lower <= val < upper\u3092\u6E80\u305F\
    \u3059\u6700\u5C0F\u306Eval\u3092\u8FD4\u3059\n    ull next_value(ull l, ull r,\
    \ ull lower, ull upper) {\n        assert(l <= r and r <= N);\n\n        if (l\
    \ == r) return NOTFOUND;\n        if (lower >= upper) return NOTFOUND;\n     \
    \   if (lower > values.rbegin()->first) return NOTFOUND;\n        if (upper <=\
    \ values.begin()->first) return NOTFOUND;\n\n        stack<tuple<ull, ull, ull,\
    \ T, bool>> st;   // (l, r, depth, val, tight)\n        st.emplace(l, r, 0, 0,\
    \ true);\n\n        while (!st.empty()) {\n            ull l, r, depth;\n    \
    \        T val;\n            bool tight;\n            tie(l, r, depth, val, tight)\
    \ = st.top(); st.pop();\n\n            if (depth == bit_size) {\n            \
    \    if (val < upper) return val;\n\n                continue;\n            }\n\
    \n            ull height = bit_size - depth - 1;\n\n            const ull bit\
    \ = (lower >> height) & 1;\n\n            const ull rank0_l = bit_vectors[height].rank(0,\
    \ l);\n            const ull rank0_r = bit_vectors[height].rank(0, r);\n     \
    \       const ull rank1_l = l - rank0_l;\n            const ull rank1_r = r -\
    \ rank0_r;\n\n            // d\u756A\u76EE\u306Ebit\u304C1\u306E\u3082\u306E\u3092\
    \u4F7F\u3046\n            const ull l1 = bit_vectors[height].zeros + rank1_l;\n\
    \            const ull r1 = bit_vectors[height].zeros + rank1_r;\n           \
    \ if (l1 != r1) {\n                const auto val1 = ((val << 1) | 1);\n     \
    \           st.emplace(l1, r1, depth + 1, val1, tight and bit == 1);\n       \
    \     }\n\n            // d\u756A\u76EE\u306Ebit\u304C0\u306E\u3082\u306E\u3092\
    \u4F7F\u3046\n            const ull l0 = rank0_l;\n            const ull r0 =\
    \ rank0_r;\n            if (l0 != r0) {\n                if (!tight or bit ==\
    \ 0) {\n                    const ull val0 = val << 1;\n                    st.emplace(l0,\
    \ r0, depth + 1, val0, tight);\n                }\n            }\n        }\n\n\
    \        return NOTFOUND;\n    }\n\n    // T[l, r)\u3067val < upper\u3092\u6E80\
    \u305F\u3059\u6700\u5927\u306Eval\u3092\u8FD4\u3059\n    ull prev_value(ull l,\
    \ ull r, T upper) {\n        return prev_value(l, r, values.begin()->first, upper);\n\
    \    }\n\n    // T[l, r)\u3067lower <= val\u3092\u6E80\u305F\u3059\u6700\u5C0F\
    \u306Eval\u3092\u8FD4\u3059\n    ull next_value(ull l, ull r, T lower) {\n   \
    \     return next_value(l, r, lower, max_val + 1);\n    }\n\n    // T[l1, r1)\u3068\
    T[l2, r2)\u306B\u5171\u901A\u3057\u3066\u51FA\u73FE\u3059\u308B\u8981\u7D20\u3092\
    \u6C42\u3081\u308B\n    vector<tuple<ull, ull, ull>> intersect(ull l1, ull r1,\
    \ ull l2, ull r2) {\n        assert(l1 <= r1 and r1 <= N);\n        assert(l2\
    \ <= r2 and r2 <= N);\n\n        vector<tuple<ull, ull, ull>> intersection;\n\n\
    \        queue<tuple<ull, ull, ull, ull, ull, ull>> que; // l1, r1, l2, r2, height,\
    \ value\n        que.emplace(l1, r1, l2, r2, bit_size - 1, 0);\n        while\
    \ (!que.empty()) {\n            auto element = que.front(); que.pop();\n     \
    \       ull l1, r1, l2, r2, height, value;\n            tie(l1, r1, l2, r2, height,\
    \ value) = element;\n\n            if (height == 0) {\n                intersection.emplace_back(value,\
    \ r1 - l1, r2 - l2);\n                continue;\n            }\n\n           \
    \ // 0\n            ull l1_0 = bit_vectors[height].rank(0, l1);\n            ull\
    \ r1_0 = bit_vectors[height].rank(0, r1);\n            ull l2_0 = bit_vectors[height].rank(0,\
    \ l2);\n            ull r2_0 = bit_vectors[height].rank(0, r2);\n\n          \
    \  if (l1_0 != r1_0 and l2_0 != r2_0) {\n                que.emplace(l1_0, r1_0,\
    \ l2_0, r2_0, height - 1, value);\n            }\n\n            // 1\n       \
    \     ull l1_1 = bit_vectors[height].zeros + bit_vectors[height].rank(1, l1);\n\
    \            ull r1_1 = bit_vectors[height].zeros + bit_vectors[height].rank(1,\
    \ r1);\n            ull l2_1 = bit_vectors[height].zeros + bit_vectors[height].rank(1,\
    \ l2);\n            ull r2_1 = bit_vectors[height].zeros + bit_vectors[height].rank(1,\
    \ r2);\n\n            if (l1_1 != r1_1 and l2_1 != r2_1) {\n                que.emplace(l1_1,\
    \ r1_1, l2_1, r2_1, height - 1, value | (1ull << height));\n            }\n  \
    \      }\n\n        return intersection;\n    }\n};\n#line 3 \"other/compressor.cpp\"\
    \n\n// EraseDuplicate: false\u306E\u3068\u304D\uFF0C\u91CD\u8907\u3059\u308B\u8981\
    \u7D20\u3092\u5225\u306E\u8981\u7D20\u3068\u3057\u3066\u6271\u3046\n// Accending:\
    \ \u91CD\u8907\u3059\u308B\u8981\u7D20\u3092\u3069\u3061\u3089\u306E\u65B9\u5411\
    \u306B\u5272\u308A\u5F53\u3066\u308B\u304B\ntemplate <typename T, bool EraseDuplicate\
    \ = true, bool Accending = true>\nstruct Compressor {\n    vector<T> original,\
    \ values;\n    vector<long long> compressed;\n    unordered_map<T, long long>\
    \ remap, count;\n\n    Compressor() {}\n    Compressor(const vector<T>& v) {\n\
    \        init(v);\n    }\n\n    void init(const vector<T>& v) {\n        original\
    \ = v;\n        values = v;\n\n        sort(values.begin(), values.end());\n \
    \       if (EraseDuplicate) {\n            values.erase(unique(values.begin(),\
    \ values.end()), values.end());\n            compressed.resize(original.size());\n\
    \        }\n\n        rep(i, original.size()) {\n            if (EraseDuplicate)\
    \ compressed[i] = std::lower_bound(values.begin(), values.end(), original[i])\
    \ - values.begin();\n            else {\n                if (Accending) compressed[i]\
    \ = std::lower_bound(values.begin(), values.end(), original[i]) - values.begin()\
    \ + count[original[i]];\n                else compressed[i] = std::upper_bound(values.begin(),\
    \ values.end(), original[i]) - values.begin() - count[original[i]] - 1;\n    \
    \        }\n\n            if (!remap.contains(original[i])) remap[original[i]]\
    \ = compressed[i];\n            ++count[original[i]];\n        }\n    }\n\n  \
    \  // x\u3092\u5727\u7E2E\u5F8C\u306E\u5024\u306B\u5909\u63DB\n    long long compress(T\
    \ x) {\n        assert(remap.contains(x));\n        return remap[x];\n    }\n\n\
    \    // x\u3092\u5727\u7E2E\u5F8C\u306E\u5024\u306B\u5909\u63DB\n    long long\
    \ operator()(T x) {\n        return compress(x);\n    }\n\n    // x\u3092\u5727\
    \u7E2E\u5F8C\u306E\u5024\u306B\u5909\u63DB\n    long long find(T x) {\n      \
    \  return compress(x);\n    }\n\n    long long size() {\n        return (long\
    \ long)values.size();\n    }\n\n    long long lower_bound(T x) {\n        return\
    \ std::lower_bound(values.begin(), values.end(), x) - values.begin();\n    }\n\
    \n    long long upper_bound(T x) {\n        return std::upper_bound(values.begin(),\
    \ values.end(), x) - values.begin();\n    }\n\n    bool contains(T x) {\n    \
    \    return remap.contains(x);\n    }\n\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30C8\u6642\u306E\u914D\u5217\u306Epos\u756A\u76EE\u306E\u5024\u3092\u53D6\
    \u5F97\n    T operator[](long long pos) {\n        return compressed[pos];\n \
    \   }\n\n    // comp\u5F8C\u306E\u5024\u304B\u3089\u5143\u306E\u5024\u3092\u53D6\
    \u5F97\n    T retrieve(long long k) {\n        return values[k];\n    }\n};\n\
    #line 5 \"test/structure/dynamic-wavelet-matrix/yosupo-static-rmq.test.cpp\"\n\
    \nint main() {\n    ll N, Q;\n    cin >> N >> Q;\n\n    vll a(N);\n    rep(i,\
    \ N) cin >> a[i];\n\n    Compressor<ll> comp(a);\n    vll b = comp.compressed;\n\
    \n    DynamicWaveletMatrix<ll> wm(max(b), b);\n\n    rep(i, Q) {\n        ll l,\
    \ r;\n        cin >> l >> r;\n\n        ll ans = wm.kth_min(l, r, 1);\n      \
    \  ans = comp.retrieve(ans);\n\n        cout << ans << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../../structure/dynamic-wavelet-matrix.cpp\"\n#include \"../../../other/compressor.cpp\"\
    \n\nint main() {\n    ll N, Q;\n    cin >> N >> Q;\n\n    vll a(N);\n    rep(i,\
    \ N) cin >> a[i];\n\n    Compressor<ll> comp(a);\n    vll b = comp.compressed;\n\
    \n    DynamicWaveletMatrix<ll> wm(max(b), b);\n\n    rep(i, Q) {\n        ll l,\
    \ r;\n        cin >> l >> r;\n\n        ll ans = wm.kth_min(l, r, 1);\n      \
    \  ans = comp.retrieve(ans);\n\n        cout << ans << endl;\n    }\n}"
  dependsOn:
  - structure/dynamic-wavelet-matrix.cpp
  - base.cpp
  - other/compressor.cpp
  isVerificationFile: true
  path: test/structure/dynamic-wavelet-matrix/yosupo-static-rmq.test.cpp
  requiredBy: []
  timestamp: '2025-03-23 18:59:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/structure/dynamic-wavelet-matrix/yosupo-static-rmq.test.cpp
layout: document
redirect_from:
- /verify/test/structure/dynamic-wavelet-matrix/yosupo-static-rmq.test.cpp
- /verify/test/structure/dynamic-wavelet-matrix/yosupo-static-rmq.test.cpp.html
title: test/structure/dynamic-wavelet-matrix/yosupo-static-rmq.test.cpp
---
