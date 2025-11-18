---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: base.cpp
    title: base.cpp
  - icon: ':x:'
    path: mystd/myset.cpp
    title: mystd/myset.cpp
  - icon: ':x:'
    path: structure/implicit-treap.cpp
    title: structure/implicit-treap.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    links:
    - https://atcoder.jp/contests/abc403/tasks/abc403_g
  bundledCode: "#line 1 \"test/structure/implicit-treap/atcoder-abc403-g.test.cpp\"\
    \n#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/abc403/tasks/abc403_g\"\
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
    \u6570\u306Einf\nconst long long inf64 = INF64 / 4;\nconst double EPS = numeric_limits<double>::epsilon();\
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
    \    return result;\n}\n#line 3 \"structure/implicit-treap.cpp\"\n\nstruct xorshift\
    \ {\n    unsigned long long x;\n\n    xorshift() {\n        mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        x = rnd();\n        rep(i, 100) random();\n    }\n    unsigned long long\
    \ random() {\n        x = x ^ (x << 7);\n        return x = x ^ (x >> 9);\n  \
    \  }\n};\n\n#if __cplusplus >= 201703L\ntemplate<typename S, \n    typename F,\n\
    \    auto op,\n    auto e,\n    auto mapping,\n    auto composition,\n    auto\
    \ id>\n#else\ntemplate<typename S, \n    typename F,\n    S (*op)(S, S),\n   \
    \ S (*e)(),\n    S (*mapping)(S, F),\n    void (*composition)(F&, F),\n    F (*id)()>\n\
    #endif\nstruct ImplicitTreap {\n#if __cplusplus >= 201703L\n    static_assert(is_convertible_v<decltype(op),\
    \ function<S(S, S)>>, \"op must be function<S(S, S)>\");\n    static_assert(is_convertible_v<decltype(e),\
    \ function<S()>>, \"e must be function<S()>\");\n    static_assert(is_convertible_v<decltype(mapping),\
    \ function<S(S, F)>>, \"mapping must be function<S(S, F)>\");\n    static_assert(is_convertible_v<decltype(composition),\
    \ function<void(F&, F)>>, \"composition must be function<F(F, F)>\");\n    static_assert(is_convertible_v<decltype(id),\
    \ function<F()>>, \"id must be function<F()>\");\n\n    static_assert(op(S(),\
    \ e()) == S(), \"op(S(), e()) must be S()\");\n    static_assert(mapping(S(),\
    \ id()) == S(), \"mapping(S(), id()) must be S()\");\n#endif\n    \n    xorshift\
    \ rnd;\n\n    struct Node {\n        S value = e(), prod = e(), rprod = e();\n\
    \        F lazy = id();\n        unsigned long long priority = numeric_limits<unsigned\
    \ long long>::max();\n        long long cnt = 0;\n        bool rev = false;\n\
    \        Node *l = nullptr, *r = nullptr;\n\n        bool operator< (const Node\
    \ &other) const {\n            return value < other.value;\n        }\n\n    \
    \    bool operator== (const S other) const {\n            return value == other;\n\
    \        }\n\n        bool operator!= (const S other) const {\n            return\
    \ value != other;\n        }\n\n        operator S() const {\n            return\
    \ value;\n        }\n    };\n\n    xorshift rng;\n\n    using pNode = unique_ptr<Node>;\n\
    \n    pNode pNIL;\n    Node *NIL = nullptr;\n\n    vector<pNode> pool;\n    Node*\
    \ root = nullptr;\n\n    ImplicitTreap() {\n        init();\n    }\n\n    ImplicitTreap(long\
    \ long n, S a) {\n        init();\n        rep(i, n) insert(i, a);\n    }\n\n\
    \    ImplicitTreap(const vector<S>& v) {\n        init();\n        rep(i, v.size())\
    \ insert(i, v[i]);\n    }\n\n    void init() {\n        pNIL = make_unique<Node>();\n\
    \        NIL = pNIL.get();\n        NIL->l = NIL->r = NIL;\n        NIL->value\
    \ = NIL->prod = NIL->rprod = e();\n        NIL->lazy = id();\n        NIL->cnt\
    \ = 0;\n        NIL->priority = numeric_limits<unsigned long long>::max();\n \
    \       NIL->rev = false;\n\n        root = NIL;\n    }\n\n    long long size()\
    \ { \n        return root->cnt; \n    }\n\n    // pos\u306E\u524D\u306B\u633F\u5165\
    \n    void insert(long long pos, S val) {\n        assert(0 <= pos && pos <= size());\n\
    \n        pNode pnx = make_unique<Node>();\n        Node* nx = pnx.get();\n  \
    \      nx->value = nx->prod = nx->rprod = val;\n        nx->lazy = id();\n   \
    \     nx->priority = rnd.random();\n        nx->cnt = 1;\n        nx->l = nx->r\
    \ = NIL;\n        nx->rev = false;\n        pool.emplace_back(move(pnx));\n\n\
    \        insert(root, pos, nx);\n    }\n\n    void erase(long long pos) {\n  \
    \      assert(0 <= pos && pos < size());\n        erase(root, pos);\n    }\n\n\
    \    void apply(long long pos, F val) {\n        assert(0 <= pos && pos < size());\n\
    \        apply(pos, pos + 1, val);\n    }\n\n    void apply(long long l, long\
    \ long r, F val) {\n        assert(0 <= l && l <= r && r <= size());\n       \
    \ apply(root, l, r, val);\n    }\n\n    S prod(long long l, long long r) {\n \
    \       return prod(root, l, r);\n    }\n\n    S get(long long pos) {\n      \
    \  return prod(root, pos, pos + 1);\n    }\n\n    void push_back(S val) {\n  \
    \      insert(size(), val);\n    }\n\n    void pop_back() {\n        if (size()\
    \ == 0) return;\n        erase(size() - 1);\n    }\n\n    void push_front(S val)\
    \ {\n        insert(0, val);\n    }\n\n    void pop_front() {\n        if (size()\
    \ == 0) return;\n        erase(0);\n    }\n\n    // int find_first(int l, int\
    \ r, S x) {\n    //     Node *left, *mid, *right;\n    //     split(root, l, left,\
    \ mid);\n    //     split(mid, r - l, mid, right);\n    //     int res = find(mid,\
    \ x, l, true);\n    //     merge(mid, mid, right);\n    //     merge(root, left,\
    \ mid);\n    //     return res;\n    // }\n\n    void reverse(long long l, long\
    \ long r) {\n        reverse(root, l, r);\n    }\n\n    void rotate(long long\
    \ l, long long m, long long r) {\n        rotate(root, l, m, r);\n    }\n\n  \
    \  void dump() {\n        rep(i, size()) cerr << (*this).get(i) << \" \";\n  \
    \      cerr << endl;\n    }\n\nprivate:\n    void update(Node* node) {\n     \
    \   if (node == NIL) return;\n        node->cnt = 1 + node->l->cnt + node->r->cnt;\n\
    \        node->prod = op(node->l->prod, op(node->value, node->r->prod));\n   \
    \     node->rprod = op(node->r->rprod, op(node->value, node->l->rprod));\n   \
    \ }\n\n    void push(Node* node) {\n        if (node == NIL) return;\n       \
    \ if (node->rev) {\n            swap(node->l, node->r);\n            swap(node->prod,\
    \ node->rprod);\n            if (node->l) node->l->rev ^= 1;\n            if (node->r)\
    \ node->r->rev ^= 1;\n            node->rev = false;\n        }\n\n        if\
    \ (node->lazy != id()) {\n            if (node->l != NIL) {\n                composition(node->l->lazy,\
    \ node->lazy);\n                node->l->prod = mapping(node->l->prod, node->lazy);\n\
    \                node->l->rprod = mapping(node->l->rprod, node->lazy);\n     \
    \       }\n            if (node->r != NIL) {\n                composition(node->r->lazy,\
    \ node->lazy);\n                node->r->prod = mapping(node->r->prod, node->lazy);\n\
    \                node->r->rprod = mapping(node->r->rprod, node->lazy);\n     \
    \       }\n            node->value = mapping(node->value, node->lazy);\n     \
    \       node->lazy = id();\n        }\n\n        update(node);\n    }\n\n    void\
    \ split(Node* node, long long key, Node*& left, Node*& right) {\n        if (node\
    \ == NIL) { \n            left = right = NIL; \n            return; \n       \
    \ }\n        \n        push(node);\n        long long pos = node->l->cnt;\n  \
    \      if (key <= pos) {\n            split(node->l, key, left, node->l);\n  \
    \          right = node;\n        }\n        else {\n            split(node->r,\
    \ key - pos - 1, node->r, right);\n            left = node;\n        }\n     \
    \   update(node);\n    }\n\n    void merge(Node*& node, Node* left, Node* right)\
    \ {\n        push(left);\n        push(right);\n        if (left == NIL || right\
    \ == NIL) {\n            node = (left != NIL) ? left : right;\n        } \n  \
    \      else if (left->priority > right->priority) {\n            merge(left->r,\
    \ left->r, right);\n            node = left;\n        } \n        else {\n   \
    \         merge(right->l, left, right->l);\n            node = right;\n      \
    \  }\n        update(node);\n    }\n\n    void insert(Node*& node, long long pos,\
    \ Node* item) {\n        Node *left, *right;\n        split(node, pos, left, right);\n\
    \        merge(left, left, item);\n        merge(node, left, right);\n    }\n\n\
    \    void erase(Node*& node, long long pos) {\n        Node *left, *mid, *right;\n\
    \        split(node, pos + 1, mid, right);\n        split(mid, pos, left, mid);\n\
    \        merge(node, left, right);\n    }\n\n    void apply(Node*& node, long\
    \ long l, long long r, F x) {\n        Node *left, *mid, *right;\n        split(node,\
    \ l, left, mid);\n        split(mid, r - l, mid, right);\n        if (mid != NIL)\
    \ {\n            composition(mid->lazy, x);\n            mid->prod = mapping(mid->prod,\
    \ x);\n            mid->rprod = mapping(mid->rprod, x);\n        }\n        merge(mid,\
    \ mid, right);\n        merge(node, left, mid);\n    }\n\n    S prod(Node*& node,\
    \ long long l, long long r) {\n        Node *left, *mid, *right;\n        split(node,\
    \ l, left, mid);\n        split(mid, r - l, mid, right);\n        S res = mid->prod;\n\
    \        merge(mid, mid, right);\n        merge(node, left, mid);\n        return\
    \ res;\n    }\n\n    void reverse(Node*& node, long long l, long long r) {\n \
    \       if (l >= r) return;\n        Node *left, *mid, *right;\n        split(node,\
    \ l, left, mid);\n        split(mid, r - l, mid, right);\n        if (mid != NIL)\
    \ mid->rev ^= 1;\n        merge(mid, mid, right);\n        merge(node, left, mid);\n\
    \    }\n\n    void rotate(Node*& node, long long l, long long m, long long r)\
    \ {\n        reverse(node, l, r);\n        reverse(node, l, l + r - m);\n    \
    \    reverse(node, l + r - m, r);\n    }\n\n    // int find(Node* node, S x, int\
    \ offset, bool left_search) {\n    //     if (!node || Monoid::op(node->aggregate,\
    \ x) == x) return -1;\n    //     push(node);\n    //     if (left_search) {\n\
    \    //         if (node->left && Monoid::op(node->left->aggregate, x) != x)\n\
    \    //             return find(node->left, x, offset, true);\n    //        \
    \ if (Monoid::op(node->value, x) != x)\n    //             return offset + get_count(node->left);\n\
    \    //         return find(node->right, x, offset + get_count(node->left) + 1,\
    \ true);\n    //     } else {\n    //         if (node->right && Monoid::op(node->right->aggregate,\
    \ x) != x)\n    //             return find(node->right, x, offset + get_count(node->left)\
    \ + 1, false);\n    //         if (Monoid::op(node->value, x) != x)\n    //  \
    \           return offset + get_count(node->left);\n    //         return find(node->left,\
    \ x, offset, false);\n    //     }\n    // }\n};\n#line 3 \"mystd/myset.cpp\"\n\
    \n// \u53C2\u8003:https://github.com/kazuma8128/procon-lib/blob/master/Structure/binary_search_tree/red_black_tree/normal/set.cpp\n\
    template <typename T, bool multi = false>\nstruct RedBlackTree {\n    using Color\
    \ = bool;\n    static const Color RED = false, BLACK = true;\n\n    struct Node\
    \ {\n        Color color = BLACK;\n        long long size = 0;\n        long long\
    \ unique_size = 0;\n        long long count = 0;\n        T val = T(), sum = T();\n\
    \        Node *p = 0, *ch[2] = {0, 0};\n\n        operator T() const {\n     \
    \       return val;\n        }\n    };\n\n    struct iterator {\n        Node\
    \ *node;\n        RedBlackTree *rbt;\n\n        iterator(Node *n, RedBlackTree\
    \ *tree) : node(n), rbt(tree) {}\n\n        iterator& operator++() {\n       \
    \     node = rbt->next(node);\n            return *this;\n        }\n\n      \
    \  iterator& operator--() {\n            node = rbt->prev(node);\n           \
    \ return *this;\n        }\n\n        T operator*() const {\n            return\
    \ node->val;\n        }\n\n        bool operator==(const iterator &it) const {\n\
    \            return node == it.node;\n        }\n\n        bool operator!=(const\
    \ iterator &it) const {\n            return node != it.node;\n        }\n\n  \
    \      long long operator-(const iterator &it) const {\n            return rbt->rank(*this)\
    \ - rbt->rank(it);\n        }\n    };\n\n    struct reverse_iterator {\n     \
    \   Node *node;\n        RedBlackTree *rbt;\n\n        reverse_iterator(Node *n,\
    \ RedBlackTree *tree) : node(n), rbt(tree) {}\n\n        reverse_iterator& operator++()\
    \ {\n            node = rbt->prev(node);\n            return *this;\n        }\n\
    \n        reverse_iterator& operator--() {\n            node = rbt->next(node);\n\
    \            return *this;\n        }\n\n        T operator*() const {\n     \
    \       return node->val;\n        }\n\n        bool operator==(const reverse_iterator\
    \ &it) const {\n            return node == it.node;\n        }\n\n        bool\
    \ operator!=(const reverse_iterator &it) const {\n            return node != it.node;\n\
    \        }\n    };\n\n    RedBlackTree() {\n        pNIL = make_unique<Node>();\n\
    \        NIL = pNIL.get();\n        NIL->p = NIL->ch[0] = NIL->ch[1] = NIL;\n\
    \        NIL->size = 0;\n        NIL->unique_size = 0;\n        NIL->count = 0;\n\
    \        NIL->color = BLACK;\n        NIL->val = T();\n        NIL->sum = T();\n\
    \        root = NIL;\n\n        front_node = back_node = NIL;\n    }\n\n    long\
    \ long size() const {\n        return root->size;\n    }\n\n    long long unique_size()\
    \ const {\n        return root->unique_size;\n    }\n\n    T front() const {\n\
    \        return front_node->val;\n    }\n\n    T back() const {\n        return\
    \ back_node->val;\n    }\n\n    long long count(T val) const {\n        return\
    \ find(root, val)->count;\n    }\n\n    long long count(T l, T r) const {\n  \
    \      return count_less_than(r) - count_less_than(l);\n    }\n\n    bool contains(T\
    \ val) const {\n        return find(root, val) != NIL;\n    }\n\n    long long\
    \ count_less_than(T val, bool unique = false) const {\n        Node *x = lower_bound(root,\
    \ val);\n        if (!unique) return rank(x);\n        else return unique_rank(x);\n\
    \    }\n\n    long long count_less_than_or_equal(T val, bool unique = false) const\
    \ {\n        Node *x = upper_bound(root, val);\n        if (!unique) return rank(x);\n\
    \        else return unique_rank(x);\n    }\n\n    long long count_greater_than(T\
    \ val, bool unique = false) const {\n        if (!unique) return size() - count_less_than_or_equal(val,\
    \ false);\n        else return unique_size() - count_less_than_or_equal(val, true);\n\
    \    }\n\n    long long count_greater_than_or_equal(T val, bool unique = false)\
    \ const {\n        if (!unique) return size() - count_less_than(val, false);\n\
    \        else return unique_size() - count_less_than(val, true);\n    }\n\n  \
    \  iterator find_greater_than(T val) {\n        return upper_bound(val);\n   \
    \ }\n\n    iterator find_greater_than_or_equal(T val) {\n        return lower_bound(val);\n\
    \    }\n\n    iterator find_less_than(T val) {\n        Node *x = lower_bound(root,\
    \ val);\n        if (x == front_node) return end();\n        return iterator(prev(x),\
    \ this);\n    }\n\n    iterator find_less_than_or_equal(T val) {\n        Node\
    \ *x = upper_bound(root, val);\n        if (x == front_node) return end();\n \
    \       return iterator(prev(x), this);\n    }\n\n    T at(long long k) const\
    \ {\n        assert(0 <= k && k < size());\n\n        Node *x = root;\n      \
    \  while (x != NIL) {\n            if (k < x->ch[0]->size) {\n               \
    \ x = x->ch[0];\n            }\n            else if (k < x->ch[0]->size + x->count)\
    \ {\n                return x->val;\n            }\n            else {\n     \
    \           k -= x->ch[0]->size + x->count;\n                x = x->ch[1];\n \
    \           }\n        }\n        return x->val;\n    }\n\n    pair<iterator,\
    \ bool> insert(T val, long long num = 1) {\n        Node *x = root, *y = NIL;\n\
    \        while (x != NIL) {\n            if (val == x->val) {\n              \
    \  if (!multi) return {iterator(x, this), false};\n\n                x->count\
    \ += num;\n                while (x != NIL) update(x), x = x->p;\n           \
    \     return {iterator(x, this), false};\n            }\n            y = x;\n\
    \            x = x->ch[val > x->val];\n        }\n        Node *v = new_node(val,\
    \ num);\n        v->p = y;\n        if (y == NIL) {\n            root = v;\n \
    \       }\n        else {\n            y->ch[val > y->val] = v;\n        }\n \
    \       while (y != NIL) update(y), y = y->p;\n        insert_fix(v);\n\n    \
    \    if (front_node == NIL || val < front_node->val) front_node = v;\n       \
    \ if (back_node == NIL || back_node->val < val) back_node = v;\n\n        return\
    \ {iterator(v, this), true};\n    }\n\n    long long erase_all(T val) {\n    \
    \    return erase(val, size());\n    }\n\n    long long erase(T val, long long\
    \ num = 1) {\n        Node *x = find(root, val);\n        if (x == NIL) return\
    \ 0;\n\n        num = min(num, x->count);\n        x->count -= num;\n        if\
    \ (x->count > 0) {\n            while (x != NIL) update(x), x = x->p;\n      \
    \      return num;\n        }\n\n        Node *y = x, *z;\n        Color c = y->color;\n\
    \        if (x->ch[0] == NIL) {\n            z = x->ch[1];\n            transplant(x,\
    \ x->ch[1]);\n        }\n        else if (x->ch[1] == NIL) {\n            z =\
    \ x->ch[0];\n            transplant(x, x->ch[0]);\n        }\n        else {\n\
    \            y = minimum(x->ch[1]);\n            c = y->color;\n            z\
    \ = y->ch[1];\n            if (y->p == x) {\n                z->p = y;\n     \
    \       }\n            else {\n                transplant(y, y->ch[1]);\n    \
    \            y->ch[1] = x->ch[1];\n                y->ch[1]->p = y;\n        \
    \    }\n            transplant(x, y);\n            y->ch[0] = x->ch[0];\n    \
    \        y->ch[0]->p = y;\n            y->color = x->color;\n            update(y);\n\
    \        }\n        Node *t = z->p;\n        while (t != NIL) update(t), t = t->p;\n\
    \        if (c == BLACK) {\n            erase_fix(z);\n        }\n\n        if\
    \ (front_node == x) front_node = next(x);\n        if (back_node == x) back_node\
    \ = prev(x);\n\n        return num;\n    }\n\n    void erase(iterator first, iterator\
    \ last) {\n        while (first != last) {\n            first = erase(first);\n\
    \        }\n    }\n\n    iterator erase(iterator pos) {\n        if (pos.node\
    \ == NIL) return end();\n\n        T val = *pos;\n        iterator next_it = pos;\n\
    \        ++next_it;\n        erase(val);\n        return next_it;\n    }\n\n \
    \   T sum() const {\n        return root->sum;\n    }\n\n    T sum(T l, T r) const\
    \ {\n        return sum_less_than(r) - sum_less_than(l);\n    }\n\n    T sum_less_than(T\
    \ x) const {\n        T ret = T();\n\n        Node *v = root;\n        while (v\
    \ != NIL) {\n            if (x <= v->val) {\n                v = v->ch[0];\n \
    \           }\n            else {\n                ret += v->val * v->count;\n\
    \                ret += v->ch[0]->sum;\n                v = v->ch[1];\n      \
    \      }\n        }\n\n        return ret;\n    }\n\n    T sum_less_than_or_equal(T\
    \ x) const {\n        return sum_less_than(x) + x * count(x);\n    }\n\n    T\
    \ sum_greater_than(T x) const {\n        T ret = T();\n\n        Node *v = root;\n\
    \        while (v != NIL) {\n            if (x < v->val) {\n                ret\
    \ += v->val * v->count;\n                ret += v->ch[1]->sum;\n             \
    \   v = v->ch[0];\n            }\n            else {\n                v = v->ch[1];\n\
    \            }\n        }\n\n        return ret;\n    }\n\n    T sum_greater_than_or_equal(T\
    \ x) const {\n        return sum_greater_than(x) + x * count(x);\n    }\n\n  \
    \  // 1-indexed\n    T kth_min(long long k) const {\n        assert(1 <= k &&\
    \ k <= size());\n\n        return at(k - 1);\n    }\n\n    // 1-indexed\n    T\
    \ kth_max(long long k) const {\n        assert(1 <= k && k <= size());\n\n   \
    \     return at(size() - k);\n    }\n\n    // 1-indexed \n    T sum_min_k(long\
    \ long k) const {\n        assert(0 <= k);\n        if (k == 0) return 0;\n  \
    \      k = min(k, size());\n\n        T kth_val = kth_min(k);\n        long long\
    \ kth_val_count = k - count_less_than(kth_val);\n        return sum_less_than(kth_val)\
    \ + kth_val * kth_val_count;\n    }\n\n    // 1-indexed\n    T sum_max_k(long\
    \ long k) const {\n        assert(0 <= k);\n        if (k == 0) return 0;\n  \
    \      k = min(k, size());\n\n        T kth_val = kth_max(k);\n        long long\
    \ kth_val_count = k - count_greater_than(kth_val);\n        return sum_greater_than(kth_val)\
    \ + kth_val * kth_val_count;\n    }\n\n    Node* next(Node *x) const {\n     \
    \   assert(x != NIL);\n        if (x == back_node) return NIL;\n\n        if (x->ch[1]\
    \ != NIL) {\n            return minimum(x->ch[1]);\n        }\n        while (x->p\
    \ != NIL && x == x->p->ch[1]) {\n            x = x->p;\n        }\n        return\
    \ x->p;\n    }\n\n    Node* prev(Node *x) const {\n        assert(x != front_node);\n\
    \        if (x == NIL) return back_node;\n\n        if (x->ch[0] != NIL) {\n \
    \           return maximum(x->ch[0]);\n        }\n        while (x->p != NIL &&\
    \ x == x->p->ch[0]) {\n            x = x->p;\n        }\n        return x->p;\n\
    \    }\n\n    iterator begin() {\n        return iterator(front_node, this);\n\
    \    }\n\n    iterator end() {\n        return iterator(NIL, this);\n    }\n\n\
    \    reverse_iterator rbegin() {\n        return reverse_iterator(back_node, this);\n\
    \    }\n\n    reverse_iterator rend() {\n        return reverse_iterator(NIL,\
    \ this);\n    }\n\n    iterator find(T val) {\n        return iterator(find(root,\
    \ val), this);\n    }\n\n    iterator lower_bound(T val) {\n        return iterator(lower_bound(root,\
    \ val), this);\n    }\n\n    iterator upper_bound(T val) {\n        return iterator(upper_bound(root,\
    \ val), this);\n    }\n\n    long long rank(iterator it) {\n        return rank(it.node);\n\
    \    }\n\n    void dump() const {\n        rep(i, size()) {\n            cerr\
    \ << at(i) << \" \\n\"[i == size() - 1];\n        }\n    }\n\nprivate:\n    using\
    \ pN = unique_ptr<Node>;\n\n    pN pNIL;\n    Node *NIL = nullptr;\n    vector<pN>\
    \ A;\n    Node *root;\n    Node *front_node, *back_node;\n\n    Node* new_node(T\
    \ val, long long num = 1) {\n        pN pnx = make_unique<Node>();\n        Node\
    \ *nx = pnx.get();\n        nx->color = RED;\n        nx->val = val;\n       \
    \ nx->sum = val * num;\n        nx->size = nx->count = num;\n        nx->unique_size\
    \ = 1;\n        nx->p = nx->ch[0] = nx->ch[1] = NIL;\n\n        A.emplace_back(move(pnx));\n\
    \        return nx;\n    }\n\n    void update(Node *x) {\n        x->size = x->ch[0]->size\
    \ + x->ch[1]->size + x->count;\n        x->unique_size = x->ch[0]->unique_size\
    \ + x->ch[1]->unique_size + 1;\n        x->sum = x->ch[0]->sum + x->ch[1]->sum\
    \ + x->val * x->count;\n    }\n\n    void rotate(Node *x, int b) {\n        Node\
    \ *y = x->ch[1 - b];\n        x->ch[1 - b] = y->ch[b];\n        if (y->ch[b] !=\
    \ NIL) {\n            y->ch[b]->p = x;\n        }\n        y->p = x->p;\n    \
    \    if (x->p == NIL) {\n            root = y;\n        }\n        else {\n  \
    \          x->p->ch[x != x->p->ch[0]] = y;\n        }\n        y->ch[b] = x;\n\
    \        x->p = y;\n        update(x);\n        update(y);\n    }\n\n    void\
    \ insert_fix(Node *x) {\n        while (x->p->color == RED) {\n            int\
    \ b = (x->p != x->p->p->ch[0]);\n            Node *y = x->p->p->ch[1 - b];\n \
    \           if (y->color == RED) {\n                x->p->color = BLACK;\n   \
    \             y->color = BLACK;\n                x->p->p->color = RED;\n     \
    \           x = x->p->p;\n                continue;\n            }\n         \
    \   if (x == x->p->ch[1 - b]) {\n                x = x->p;\n                rotate(x,\
    \ b);\n            }\n            x->p->color = BLACK;\n            x->p->p->color\
    \ = RED;\n            rotate(x->p->p, 1 - b);\n        }\n        root->color\
    \ = BLACK;\n    }\n\n    void transplant(Node *u, Node *v) {\n        if (u->p\
    \ == NIL) {\n            root = v;\n        }\n        else {\n            u->p->ch[u\
    \ != u->p->ch[0]] = v;\n        }\n        v->p = u->p;\n    }\n\n    void erase_fix(Node\
    \ *x) {\n        while (x != root && x->color == BLACK) {\n            int b =\
    \ (x != x->p->ch[0]);\n            Node *w = x->p->ch[1 - b];\n            if\
    \ (w->color == RED) {\n                w->color = BLACK;\n                x->p->color\
    \ = RED;\n                rotate(x->p, b);\n                w = x->p->ch[1 - b];\n\
    \            }\n            if (w->ch[b]->color == BLACK && w->ch[1 - b]->color\
    \ == BLACK) {\n                w->color = RED;\n                x = x->p;\n  \
    \              continue;\n            }\n            if (w->ch[1 - b]->color ==\
    \ BLACK) {\n                w->ch[b]->color = BLACK;\n                w->color\
    \ = RED;\n                rotate(w, 1 - b);\n                w = x->p->ch[1 -\
    \ b];\n            }\n            w->color = x->p->color;\n            x->p->color\
    \ = BLACK;\n            w->ch[1 - b]->color = BLACK;\n            rotate(x->p,\
    \ b);\n            x = root;\n        }\n        x->color = BLACK;\n    }\n\n\
    \    Node* find(Node *x, T val) const {\n        while (x != NIL) {\n        \
    \    if (val == x->val) return x;\n            x = x->ch[val > x->val];\n    \
    \    }\n        return NIL;\n    }\n\n    Node* lower_bound(Node *x, T val) const\
    \ {\n        Node *ret = NIL;\n        while (x != NIL) {\n            if (val\
    \ <= x->val) {\n                ret = x;\n                x = x->ch[0];\n    \
    \        } \n            else {\n                x = x->ch[1];\n            }\n\
    \        }\n        return ret;\n    }\n\n    Node* upper_bound(Node *x, T val)\
    \ const {\n        Node *ret = NIL;\n        while (x != NIL) {\n            if\
    \ (val < x->val) {\n                ret = x;\n                x = x->ch[0];\n\
    \            } \n            else {\n                x = x->ch[1];\n         \
    \   }\n        }\n        return ret;\n    }\n\n    // [l, r)\u306E\u8981\u7D20\
    \u6570 (\u91CD\u8907\u3092\u542B\u3080)\n    long long rank(Node* l, Node* r)\
    \ const {\n        return rank(r) - rank(l);\n    }\n\n    // [0, pos)\u306E\u8981\
    \u7D20\u6570 (\u91CD\u8907\u3092\u542B\u3080)\n    long long rank(Node* p) const\
    \ {\n        if (p == NIL) return size();\n\n        long long ret = 0;\n    \
    \    T val = p->val;\n        Node *x = root;\n\n        while (x != NIL) {\n\
    \            if (val <= x->val) {\n                x = x->ch[0];\n           \
    \ } \n            else {\n                ret += x->ch[0]->size + x->count;\n\
    \                x = x->ch[1];\n            }\n        }\n        return ret;\n\
    \    }\n\n    // [l, r)\u306E\u8981\u7D20\u6570 (\u91CD\u8907\u3092\u542B\u307E\
    \u306A\u3044)\n    long long unique_rank(Node* l, Node* r) const {\n        return\
    \ unique_rank(r) - unique_rank(l);\n    }\n\n    // [0, pos)\u306E\u8981\u7D20\
    \u6570 (\u91CD\u8907\u3092\u542B\u307E\u306A\u3044)\n    long long unique_rank(Node*\
    \ p) const {\n        if (p == NIL) return unique_size();\n\n        long long\
    \ ret = 0;\n        T val = p->val;\n        Node *x = root;\n\n        while\
    \ (x != NIL) {\n            if (val <= x->val) {\n                x = x->ch[0];\n\
    \            } \n            else {\n                ret += x->ch[0]->unique_size\
    \ + 1;\n                x = x->ch[1];\n            }\n        }\n        return\
    \ ret;\n    }\n\n    Node* minimum(Node *x) const {\n        if (x == NIL) return\
    \ NIL;\n        while (x->ch[0] != NIL) {\n            x = x->ch[0];\n       \
    \ }\n        return x;\n    }\n\n    Node* maximum(Node *x) const {\n        if\
    \ (x == NIL) return NIL;\n        while (x->ch[1] != NIL) {\n            x = x->ch[1];\n\
    \        }\n        return x;\n    }\n};\n\ntemplate<typename T> using Set = RedBlackTree<T,\
    \ false>;\ntemplate<typename T> using MultiSet = RedBlackTree<T, true>;\n#line\
    \ 6 \"test/structure/implicit-treap/atcoder-abc403-g.test.cpp\"\n\nint main()\
    \ {\n    ll Q;\n    cin >> Q;\n\n    MultiSet<ll> ms;\n    using S = pll;\n  \
    \  auto op = [](S a, S b) { return S(a.first + b.first, a.second + b.second);\
    \ };\n    auto e = []() { return S(0, 0); };\n    using F = bool;\n    auto mapping\
    \ = [](S a, F b) { return b ? S(a.second, a.first) : a; };\n    auto composition\
    \ = [](F& a, F b) { a ^= b; };\n    auto id = []() { return false; };\n    ImplicitTreap<S,\
    \ F, op, e, mapping, composition, id> treap;\n\n    ll z = 0;\n    ll M = 1e9;\n\
    \n    while (Q--) {\n        ll y;\n        cin >> y;\n\n        ll x = ((y +\
    \ z) % M) + 1;\n        auto it = ms.upper_bound(x);\n        ll rank = ms.rank(it);\n\
    \n        treap.apply(rank, treap.size(), true);\n        S s = (rank % 2 == 0)\
    \ ? S(x, 0) : S(0, x);\n        treap.insert(rank, s);\n        ms.insert(x);\n\
    \n        ll ans = treap.prod(0, treap.size()).first;\n        cout << ans <<\
    \ endl;\n        z = ans;\n    }\n\n    return 0;\n} \n"
  code: "#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/abc403/tasks/abc403_g\"\
    \n\n#include \"../../../structure/implicit-treap.cpp\"\n#include \"../../../mystd/myset.cpp\"\
    \n\nint main() {\n    ll Q;\n    cin >> Q;\n\n    MultiSet<ll> ms;\n    using\
    \ S = pll;\n    auto op = [](S a, S b) { return S(a.first + b.first, a.second\
    \ + b.second); };\n    auto e = []() { return S(0, 0); };\n    using F = bool;\n\
    \    auto mapping = [](S a, F b) { return b ? S(a.second, a.first) : a; };\n \
    \   auto composition = [](F& a, F b) { a ^= b; };\n    auto id = []() { return\
    \ false; };\n    ImplicitTreap<S, F, op, e, mapping, composition, id> treap;\n\
    \n    ll z = 0;\n    ll M = 1e9;\n\n    while (Q--) {\n        ll y;\n       \
    \ cin >> y;\n\n        ll x = ((y + z) % M) + 1;\n        auto it = ms.upper_bound(x);\n\
    \        ll rank = ms.rank(it);\n\n        treap.apply(rank, treap.size(), true);\n\
    \        S s = (rank % 2 == 0) ? S(x, 0) : S(0, x);\n        treap.insert(rank,\
    \ s);\n        ms.insert(x);\n\n        ll ans = treap.prod(0, treap.size()).first;\n\
    \        cout << ans << endl;\n        z = ans;\n    }\n\n    return 0;\n} \n"
  dependsOn:
  - structure/implicit-treap.cpp
  - base.cpp
  - mystd/myset.cpp
  isVerificationFile: true
  path: test/structure/implicit-treap/atcoder-abc403-g.test.cpp
  requiredBy: []
  timestamp: '2025-11-16 22:01:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/structure/implicit-treap/atcoder-abc403-g.test.cpp
layout: document
redirect_from:
- /verify/test/structure/implicit-treap/atcoder-abc403-g.test.cpp
- /verify/test/structure/implicit-treap/atcoder-abc403-g.test.cpp.html
title: test/structure/implicit-treap/atcoder-abc403-g.test.cpp
---
