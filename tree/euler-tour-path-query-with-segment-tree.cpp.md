---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: base.cpp
    title: base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/euler-tour-path-query-with-segment-tree/atcoder-abc294-g.test.cpp
    title: test/tree/euler-tour-path-query-with-segment-tree/atcoder-abc294-g.test.cpp
  - icon: ':x:'
    path: test/tree/euler-tour-path-query-with-segment-tree/yosupo-lowest-common-ancestor.test.cpp
    title: test/tree/euler-tour-path-query-with-segment-tree/yosupo-lowest-common-ancestor.test.cpp
  - icon: ':x:'
    path: test/tree/euler-tour-path-query-with-segment-tree/yosupo-vertex-add-path-sum.test.cpp
    title: test/tree/euler-tour-path-query-with-segment-tree/yosupo-vertex-add-path-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \    return result;\n}\n#line 3 \"tree/euler-tour-path-query-with-segment-tree.cpp\"\
    \n\n#if __cplusplus >= 201703L\ntemplate<class S, \n        auto op,\n       \
    \ auto e,\n        class F,\n        auto mapping>\n#else\n    template<class\
    \ S,\n        S (*op)(S, S),\n        S (*e)(),\n        class F,\n        S (*mapping)(S,\
    \ F)>\n#endif\nstruct SegmentTree {\n#if __cplusplus >= 201703L\n    static_assert(is_convertible_v<decltype(op),\
    \ function<S(S, S)>>, \"op must be function<S(S, S)>\");\n    static_assert(is_convertible_v<decltype(e),\
    \ function<S()>>, \"e must be function<S()>\");\n    static_assert(is_convertible_v<decltype(mapping),\
    \ function<S(S, F)>>, \"mapping must be function<S(S, F)>\");\n#endif\n    long\
    \ long N, _N, height;\n    vector<S> node;\n\n    SegmentTree(ll _N) : _N(_N)\
    \ {\n        height = 1;\n        N = 1;\n\n        while (N < _N) {\n       \
    \     N *= 2;\n            height++;\n        }\n\n        node.resize(2 * N,\
    \ e());\n        repd(i, 1, N) update(i);\n    }\n\n    void build() {\n     \
    \   repd(i, 1, N) update(i);\n    }\n\n    void apply(long long p, S f, bool no_update=false)\
    \ {\n        assert(0 <= p and p < _N);\n\n        long long k = p + N;\n    \
    \    node[k] = mapping(node[k], f);\n        if (!no_update) rep(i, 1, height)\
    \ update(k >> i);\n    }\n\n    S get(long long p) {\n        assert(0 <= p and\
    \ p < _N);\n\n        long long k = p + N;\n        return node[k];\n    }\n\n\
    \    S prod(long long l, long long r) {\n        assert(0 <= l && l <= r && r\
    \ <= _N);\n\n        l += N;\n        r += N;\n\n        S sml = e(), smr = e();\n\
    \        while (l < r) {\n            if (l & 1) sml = op(sml, node[l++]);\n \
    \           if (r & 1) smr = op(node[--r], smr);\n            l >>= 1;\n     \
    \       r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S prod_all()\
    \ {\n        return node[1];\n    }\n\nprivate:\n    void update(long long k)\
    \ {\n        assert(1 <= k and k <= N - 1);\n\n        node[k] = op(node[k * 2],\
    \ node[k * 2 + 1]);\n    }\n};\n\n// \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\
    \n// 2\u9802\u70B9\u9593\u306E\u30D1\u30B9\u306B\u5BFE\u3057\u3066\uFF0C\u9006\
    \u5143\u3092\u6301\u3064\u6F14\u7B97(sum, xor\u306A\u3069)\u304C\u53EF\u80FD\n\
    #if __cplusplus >= 201703L\ntemplate<class S, \n        auto op,\n        auto\
    \ inv,\n        auto e,\n        class F,\n        auto mapping>\n#else\n    template<class\
    \ S,\n        S (*op)(S, S),\n        S (*inv)(S),\n        S (*e)(),\n      \
    \  class F,\n        S (*mapping)(S, F)>\n#endif\nstruct EulerTourPath {\n#if\
    \ __cplusplus >= 201703L\n    static_assert(is_convertible_v<decltype(op), function<S(S,\
    \ S)>>, \"op must be function<S(S, S)>\");\n    static_assert(is_convertible_v<decltype(inv),\
    \ function<S(S)>>, \"inv must be function<S(S)>\");\n    static_assert(is_convertible_v<decltype(e),\
    \ function<S()>>, \"e must be function<S()>\");\n    static_assert(is_convertible_v<decltype(mapping),\
    \ function<S(S, F)>>, \"mapping must be function<S(S, F)>\");\n#endif\n\n    struct\
    \ Edge {\n        long long from;\n        long long to;\n        long long idx;\n\
    \        \n        explicit Edge(long long u = -1, long long v = -1, long long\
    \ i = -1) : from(u), to(v), idx(i) {};\n\n        bool operator < (const Edge&\
    \ other) const {\n            if (from == other.from) return to < other.to;\n\
    \            else return from < other.from;\n        }\n\n        friend ostream&\
    \ operator << (ostream& os, const Edge& edge) {\n            return os << edge.to;\n\
    \        }\n    };\n\n    using pll = pair<long long, long long>;\n\n    long\
    \ long V;\n    vector<vector<Edge>> G;\n    vector<bool> seen;\n\n    vector<S>\
    \ weights;\n\n    long long time;\n    vector<long long> pre_order, post_order;\n\
    \    vector<long long> visited_order;\n    vector<pll> visited_depth;\n\n    long\
    \ long edge_index;\n    bool built = false;\n\n    SegmentTree<S, op, e, F, mapping>\
    \ seg;\n    SegmentTree<pll, [](pll x, pll y){return (x.first < y.first ? x :\
    \ y);}, [](){return pll(inf64, -1);}, pll, [](pll x, pll f){return f;}> seg_depth;\n\
    \n    EulerTourPath(long long N) : V(N), G(V), seg(4 * N - 2), seg_depth(4 * N\
    \ - 2) {\n        init();\n    };\n\n    void init() {\n        time = 0;\n  \
    \      seen.assign(V, false);\n\n        weights.resize(2 * V - 1, e());\n   \
    \     pre_order.assign(2 * V - 1, -1);\n        post_order.assign(2 * V - 1, -1);\n\
    \n        edge_index = 0;\n    }\n\n    void connect(long long from, long long\
    \ to) {\n        connect(from, to, e());\n    }\n\n    void connect(long long\
    \ from, long long to, S weight) {\n        assert(0 <= from and from < V);\n \
    \       assert(0 <= to and to < V);\n        assert(!built);\n\n        G[from].emplace_back(from,\
    \ to, edge_index);\n        G[to].emplace_back(to, from, edge_index);\n\n    \
    \    weights[V + edge_index] = weight;\n\n        edge_index++;\n    }\n\n   \
    \ void set_vertex_weight(long long v, S w) {\n        assert(0 <= v and v < V);\n\
    \        assert(!built);\n\n        weights[v] = w;\n    }\n\n    void build(long\
    \ long root) {\n        assert(0 <= root and root < V);\n\n        dfs(root, 0);\n\
    \n        rep(i, visited_order.size()) {\n            if (visited_order[i] >=\
    \ 0) {\n                long long v = visited_order[i];\n                seg.node[seg.N\
    \ + i] = weights[v];\n                seg_depth.node[seg_depth.N + i] = visited_depth[i];\n\
    \            }\n            else {\n                long long v = ~visited_order[i];\n\
    \                seg.node[seg.N + i] = inv(weights[v]);\n                seg_depth.node[seg_depth.N\
    \ + i] = visited_depth[i];\n            }\n        }\n\n        seg.build();\n\
    \        seg_depth.build();\n\n        built = true;\n    }\n\n    void apply_vertex(long\
    \ long v, S f) {\n        assert(0 <= v and v < V);\n        assert(built);\n\n\
    \        weights[v] = mapping(weights[v], f);\n\n        long long pre = pre_order[v];\n\
    \        seg.apply(pre, f);\n\n        long long post = post_order[v];\n     \
    \   seg.apply(post, inv(f));\n    }\n\n    void apply_edge(long long i, S f) {\n\
    \        assert(0 <= i and i < edge_index);\n        assert(built);\n\n      \
    \  weights[V + i] = mapping(weights[V + i], f);\n\n        long long pre = pre_order[V\
    \ + i];\n        seg.apply(pre, f);\n\n        long long post = post_order[V +\
    \ i];\n        seg.apply(post, inv(f));\n    }\n\n    long long lca(long long\
    \ u, long long v) {\n        assert(0 <= min(u, v) and max(u, v) < V);\n     \
    \   assert(built);\n\n        long long l = pre_order[u];\n        long long r\
    \ = pre_order[v];\n        if (l > r) swap(l, r);\n        return seg_depth.prod(l,\
    \ r + 1).second;\n    }\n\n    S prod(long long v) {\n        assert(0 <= v and\
    \ v < V);\n        assert(built);\n\n        ll r = post_order[v];\n        return\
    \ seg.prod(0, r);\n    }\n\n    S prod(long long u, long long v) {\n        assert(0\
    \ <= min(u, v) and max(u, v) < V);\n        assert(built);\n\n        ll pu =\
    \ post_order[u];\n        ll pv = post_order[v];\n        ll a = lca(u, v);\n\
    \        ll pa = post_order[a];\n        return seg.prod(0, pu) + seg.prod(0,\
    \ pv) - 2 * seg.prod(0, pa) + seg.get(pre_order[a]);\n    }\n\n    S get_vertex(long\
    \ long v) {\n        assert(0 <= v and v < V);\n        assert(built);\n\n   \
    \     return weights[v];\n    }\n\n    S get_edge(long long i) {\n        assert(0\
    \ <= i and i < edge_index);\n        assert(built);\n\n        return weights[V\
    \ + i];\n    }\n\nprivate:\n    void dfs(long long v, long long d) {\n       \
    \ seen[v] = true;\n\n        visited_order.push_back(v);\n        visited_depth.push_back({d,\
    \ v});\n        pre_order[v] = time++;\n\n        for (auto& edge : G[v]) {\n\
    \            if (seen[edge.to]) continue;\n\n            visited_order.push_back(V\
    \ + edge.idx);\n            visited_depth.push_back({d + 1, edge.to});\n     \
    \       pre_order[V + edge.idx] = time++;\n\n            dfs(edge.to, d + 1);\n\
    \n            visited_order.push_back(~(V + edge.idx));\n            visited_depth.push_back({d,\
    \ v});\n            post_order[V + edge.idx] = time++;\n        }\n\n        visited_order.push_back(~v);\n\
    \        visited_depth.push_back({d, v});\n        post_order[v] = time++;\n \
    \   }\n};\n"
  code: "#pragma once\n#include \"../base.cpp\"\n\n#if __cplusplus >= 201703L\ntemplate<class\
    \ S, \n        auto op,\n        auto e,\n        class F,\n        auto mapping>\n\
    #else\n    template<class S,\n        S (*op)(S, S),\n        S (*e)(),\n    \
    \    class F,\n        S (*mapping)(S, F)>\n#endif\nstruct SegmentTree {\n#if\
    \ __cplusplus >= 201703L\n    static_assert(is_convertible_v<decltype(op), function<S(S,\
    \ S)>>, \"op must be function<S(S, S)>\");\n    static_assert(is_convertible_v<decltype(e),\
    \ function<S()>>, \"e must be function<S()>\");\n    static_assert(is_convertible_v<decltype(mapping),\
    \ function<S(S, F)>>, \"mapping must be function<S(S, F)>\");\n#endif\n    long\
    \ long N, _N, height;\n    vector<S> node;\n\n    SegmentTree(ll _N) : _N(_N)\
    \ {\n        height = 1;\n        N = 1;\n\n        while (N < _N) {\n       \
    \     N *= 2;\n            height++;\n        }\n\n        node.resize(2 * N,\
    \ e());\n        repd(i, 1, N) update(i);\n    }\n\n    void build() {\n     \
    \   repd(i, 1, N) update(i);\n    }\n\n    void apply(long long p, S f, bool no_update=false)\
    \ {\n        assert(0 <= p and p < _N);\n\n        long long k = p + N;\n    \
    \    node[k] = mapping(node[k], f);\n        if (!no_update) rep(i, 1, height)\
    \ update(k >> i);\n    }\n\n    S get(long long p) {\n        assert(0 <= p and\
    \ p < _N);\n\n        long long k = p + N;\n        return node[k];\n    }\n\n\
    \    S prod(long long l, long long r) {\n        assert(0 <= l && l <= r && r\
    \ <= _N);\n\n        l += N;\n        r += N;\n\n        S sml = e(), smr = e();\n\
    \        while (l < r) {\n            if (l & 1) sml = op(sml, node[l++]);\n \
    \           if (r & 1) smr = op(node[--r], smr);\n            l >>= 1;\n     \
    \       r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S prod_all()\
    \ {\n        return node[1];\n    }\n\nprivate:\n    void update(long long k)\
    \ {\n        assert(1 <= k and k <= N - 1);\n\n        node[k] = op(node[k * 2],\
    \ node[k * 2 + 1]);\n    }\n};\n\n// \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\
    \n// 2\u9802\u70B9\u9593\u306E\u30D1\u30B9\u306B\u5BFE\u3057\u3066\uFF0C\u9006\
    \u5143\u3092\u6301\u3064\u6F14\u7B97(sum, xor\u306A\u3069)\u304C\u53EF\u80FD\n\
    #if __cplusplus >= 201703L\ntemplate<class S, \n        auto op,\n        auto\
    \ inv,\n        auto e,\n        class F,\n        auto mapping>\n#else\n    template<class\
    \ S,\n        S (*op)(S, S),\n        S (*inv)(S),\n        S (*e)(),\n      \
    \  class F,\n        S (*mapping)(S, F)>\n#endif\nstruct EulerTourPath {\n#if\
    \ __cplusplus >= 201703L\n    static_assert(is_convertible_v<decltype(op), function<S(S,\
    \ S)>>, \"op must be function<S(S, S)>\");\n    static_assert(is_convertible_v<decltype(inv),\
    \ function<S(S)>>, \"inv must be function<S(S)>\");\n    static_assert(is_convertible_v<decltype(e),\
    \ function<S()>>, \"e must be function<S()>\");\n    static_assert(is_convertible_v<decltype(mapping),\
    \ function<S(S, F)>>, \"mapping must be function<S(S, F)>\");\n#endif\n\n    struct\
    \ Edge {\n        long long from;\n        long long to;\n        long long idx;\n\
    \        \n        explicit Edge(long long u = -1, long long v = -1, long long\
    \ i = -1) : from(u), to(v), idx(i) {};\n\n        bool operator < (const Edge&\
    \ other) const {\n            if (from == other.from) return to < other.to;\n\
    \            else return from < other.from;\n        }\n\n        friend ostream&\
    \ operator << (ostream& os, const Edge& edge) {\n            return os << edge.to;\n\
    \        }\n    };\n\n    using pll = pair<long long, long long>;\n\n    long\
    \ long V;\n    vector<vector<Edge>> G;\n    vector<bool> seen;\n\n    vector<S>\
    \ weights;\n\n    long long time;\n    vector<long long> pre_order, post_order;\n\
    \    vector<long long> visited_order;\n    vector<pll> visited_depth;\n\n    long\
    \ long edge_index;\n    bool built = false;\n\n    SegmentTree<S, op, e, F, mapping>\
    \ seg;\n    SegmentTree<pll, [](pll x, pll y){return (x.first < y.first ? x :\
    \ y);}, [](){return pll(inf64, -1);}, pll, [](pll x, pll f){return f;}> seg_depth;\n\
    \n    EulerTourPath(long long N) : V(N), G(V), seg(4 * N - 2), seg_depth(4 * N\
    \ - 2) {\n        init();\n    };\n\n    void init() {\n        time = 0;\n  \
    \      seen.assign(V, false);\n\n        weights.resize(2 * V - 1, e());\n   \
    \     pre_order.assign(2 * V - 1, -1);\n        post_order.assign(2 * V - 1, -1);\n\
    \n        edge_index = 0;\n    }\n\n    void connect(long long from, long long\
    \ to) {\n        connect(from, to, e());\n    }\n\n    void connect(long long\
    \ from, long long to, S weight) {\n        assert(0 <= from and from < V);\n \
    \       assert(0 <= to and to < V);\n        assert(!built);\n\n        G[from].emplace_back(from,\
    \ to, edge_index);\n        G[to].emplace_back(to, from, edge_index);\n\n    \
    \    weights[V + edge_index] = weight;\n\n        edge_index++;\n    }\n\n   \
    \ void set_vertex_weight(long long v, S w) {\n        assert(0 <= v and v < V);\n\
    \        assert(!built);\n\n        weights[v] = w;\n    }\n\n    void build(long\
    \ long root) {\n        assert(0 <= root and root < V);\n\n        dfs(root, 0);\n\
    \n        rep(i, visited_order.size()) {\n            if (visited_order[i] >=\
    \ 0) {\n                long long v = visited_order[i];\n                seg.node[seg.N\
    \ + i] = weights[v];\n                seg_depth.node[seg_depth.N + i] = visited_depth[i];\n\
    \            }\n            else {\n                long long v = ~visited_order[i];\n\
    \                seg.node[seg.N + i] = inv(weights[v]);\n                seg_depth.node[seg_depth.N\
    \ + i] = visited_depth[i];\n            }\n        }\n\n        seg.build();\n\
    \        seg_depth.build();\n\n        built = true;\n    }\n\n    void apply_vertex(long\
    \ long v, S f) {\n        assert(0 <= v and v < V);\n        assert(built);\n\n\
    \        weights[v] = mapping(weights[v], f);\n\n        long long pre = pre_order[v];\n\
    \        seg.apply(pre, f);\n\n        long long post = post_order[v];\n     \
    \   seg.apply(post, inv(f));\n    }\n\n    void apply_edge(long long i, S f) {\n\
    \        assert(0 <= i and i < edge_index);\n        assert(built);\n\n      \
    \  weights[V + i] = mapping(weights[V + i], f);\n\n        long long pre = pre_order[V\
    \ + i];\n        seg.apply(pre, f);\n\n        long long post = post_order[V +\
    \ i];\n        seg.apply(post, inv(f));\n    }\n\n    long long lca(long long\
    \ u, long long v) {\n        assert(0 <= min(u, v) and max(u, v) < V);\n     \
    \   assert(built);\n\n        long long l = pre_order[u];\n        long long r\
    \ = pre_order[v];\n        if (l > r) swap(l, r);\n        return seg_depth.prod(l,\
    \ r + 1).second;\n    }\n\n    S prod(long long v) {\n        assert(0 <= v and\
    \ v < V);\n        assert(built);\n\n        ll r = post_order[v];\n        return\
    \ seg.prod(0, r);\n    }\n\n    S prod(long long u, long long v) {\n        assert(0\
    \ <= min(u, v) and max(u, v) < V);\n        assert(built);\n\n        ll pu =\
    \ post_order[u];\n        ll pv = post_order[v];\n        ll a = lca(u, v);\n\
    \        ll pa = post_order[a];\n        return seg.prod(0, pu) + seg.prod(0,\
    \ pv) - 2 * seg.prod(0, pa) + seg.get(pre_order[a]);\n    }\n\n    S get_vertex(long\
    \ long v) {\n        assert(0 <= v and v < V);\n        assert(built);\n\n   \
    \     return weights[v];\n    }\n\n    S get_edge(long long i) {\n        assert(0\
    \ <= i and i < edge_index);\n        assert(built);\n\n        return weights[V\
    \ + i];\n    }\n\nprivate:\n    void dfs(long long v, long long d) {\n       \
    \ seen[v] = true;\n\n        visited_order.push_back(v);\n        visited_depth.push_back({d,\
    \ v});\n        pre_order[v] = time++;\n\n        for (auto& edge : G[v]) {\n\
    \            if (seen[edge.to]) continue;\n\n            visited_order.push_back(V\
    \ + edge.idx);\n            visited_depth.push_back({d + 1, edge.to});\n     \
    \       pre_order[V + edge.idx] = time++;\n\n            dfs(edge.to, d + 1);\n\
    \n            visited_order.push_back(~(V + edge.idx));\n            visited_depth.push_back({d,\
    \ v});\n            post_order[V + edge.idx] = time++;\n        }\n\n        visited_order.push_back(~v);\n\
    \        visited_depth.push_back({d, v});\n        post_order[v] = time++;\n \
    \   }\n};\n"
  dependsOn:
  - base.cpp
  isVerificationFile: false
  path: tree/euler-tour-path-query-with-segment-tree.cpp
  requiredBy: []
  timestamp: '2025-11-16 20:40:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/euler-tour-path-query-with-segment-tree/yosupo-vertex-add-path-sum.test.cpp
  - test/tree/euler-tour-path-query-with-segment-tree/atcoder-abc294-g.test.cpp
  - test/tree/euler-tour-path-query-with-segment-tree/yosupo-lowest-common-ancestor.test.cpp
documentation_of: tree/euler-tour-path-query-with-segment-tree.cpp
layout: document
redirect_from:
- /library/tree/euler-tour-path-query-with-segment-tree.cpp
- /library/tree/euler-tour-path-query-with-segment-tree.cpp.html
title: tree/euler-tour-path-query-with-segment-tree.cpp
---
