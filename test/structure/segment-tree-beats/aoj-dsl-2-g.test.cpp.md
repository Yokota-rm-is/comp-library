---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.cpp
    title: base.cpp
  - icon: ':heavy_check_mark:'
    path: structure/segment-tree-beats.cpp
    title: structure/segment-tree-beats.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&
  bundledCode: "#line 1 \"test/structure/segment-tree-beats/aoj-dsl-2-g.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&\"\
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
    #define fored(i, I) for (auto& i: (I) | views::reverse)\n#define ALL(A) A.begin(),\
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
    \ os;}\n\n// \u30C7\u30D0\u30C3\u30B0\u7528\ntemplate<typename T> void dump(T\
    \ a) { cerr << a;}\nvoid dump(vector<string>& a) { cerr << '\\n' << a;}\ntemplate<typename\
    \ T> void dump(vector<vector<T>>& a) { cerr << '\\n' << a;}\ntemplate<typename\
    \ T> void dump(vector<stack<T>>& a) { cerr << '\\n' << a;}\ntemplate<typename\
    \ T> void dump(vector<queue<T>>& a) { cerr << '\\n' << a;}\ntemplate<typename\
    \ T> void dump(vector<deque<T>>& a) { cerr << '\\n' << a;}\n\n// input\ntemplate<typename\
    \ T> inline void input(T& a) {cin >> a;}\ntemplate<typename T, typename... Args>\
    \ inline void input(T& a, Args&&... args) { cin >> a; input(args...);}\ntemplate<typename\
    \ T> inline void input(vector<T>& A) { rep(i, A.size()) cin >> A[i];}\ntemplate<typename\
    \ T> inline void input(vector<T>& A, vector<T>& B) { assert(A.size() == B.size());rep(i,\
    \ A.size()) cin >> A[i] >> B[i];}\ntemplate<typename T> inline void input(vector<T>&\
    \ A, vector<T>& B, vector<T>& C) { assert(A.size() == B.size() and A.size() ==\
    \ C.size()); rep(i, A.size()) cin >> A[i] >> B[i] >> C[i];}\ntemplate<typename\
    \ T> inline void input(const long long N, vector<T>& A) { A.resize(N); rep(i,\
    \ N) cin >> A[i];}\ntemplate<typename T> inline void input(const long long N,\
    \ vector<T>& A, vector<T>& B) { A.resize(N); B.resize(N); rep(i, N) cin >> A[i]\
    \ >> B[i];}\ntemplate<typename T> inline void input(const long long N, vector<T>&\
    \ A, vector<T>& B, vector<T>& C) { A.resize(N); B.resize(N); C.resize(N); rep(i,\
    \ A.size()) cin >> A[i] >> B[i] >> C[i];}\ntemplate<typename T> inline void input(const\
    \ long long N, set<T>& A) {rep(i, N) { T a; cin >> a; A.insert(a);}}\ntemplate<typename\
    \ T> inline void input(const long long N, set<T>& A, set<T>& B) { rep(i, N) {T\
    \ a, b; cin >> a >> b; A.insert(a); B.insert(b);}}\ntemplate<typename T> inline\
    \ void input(const long long N, set<T>& A, set<T>& B, set<T>& C) { rep(i, N) {T\
    \ a, b, c; cin >> a >> b >> c; A.insert(a); B.insert(b); C.insert(c);}}\ntemplate<typename\
    \ T> inline void input(vector<vector<T>>& A) { rep(i, A.size()) input(A[i]);}\n\
    \ninline string YESNO(bool flag) { return flag ? \"YES\" : \"NO\";}\ninline string\
    \ yesno(bool flag) { return flag ? \"yes\" : \"no\";}\ninline string YesNo(bool\
    \ flag) { return flag ? \"Yes\" : \"No\";}\ninline string POSSIBLE(bool flag)\
    \ { return flag ? \"POSSIBLE\" : \"IMPOSSIBLE\";}\ninline string Possible(bool\
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
    \ / y, (x % y + y) % y));}\ninline long long binpow(long long x, long long n,\
    \ long long m = 0) {\n    long long ret = 1;\n    while (n > 0) {\n        if\
    \ (n & 1) ret *= x;  // n \u306E\u6700\u4E0B\u4F4Dbit\u304C 1 \u306A\u3089\u3070\
    \ x^(2^i) \u3092\u304B\u3051\u308B\n        x *= x;\n        if (m > 0) {ret %=\
    \ m; x %= m;};\n        n >>= 1;  // n \u30921bit \u5DE6\u306B\u305A\u3089\u3059\
    \n    }\n    return ret;\n}\n// mod. m \u3067\u306E a \u306E\u9006\u5143 a^{-1}\
    \ \u3092\u8A08\u7B97\u3059\u308B\ntemplate<typename T> T modinv(T a, T m) {\n\
    \    T b = m, u = 1, v = 0;\n    while (b) {\n        T t = a / b;\n        a\
    \ -= t * b; swap(a, b);\n        u -= t * v; swap(u, v);\n    }\n    u %= m;\n\
    \    if (u < 0) u += m;\n    return u;\n}\n// combination\u3092\u6C42\u3081\u308B\
    \nlong long nCr(long long n, long long k, long long m = 0) {\n    if (n < k) return\
    \ 0;\n    if (n - k < k) k = n - k;\n    long long ret = 1;\n    rep(i, k) {\n\
    \        ret *= (n - i);\n        if (m > 0) ret %= m;\n    }\n    rep(i, 1, k\
    \ + 1) {\n        if (m > 0) {\n            ret *= modinv(i, m);\n           \
    \ ret %= m;\n        } \n        else ret /= i;\n    }\n    return ret;\n}\n\n\
    // \u6700\u5927\u516C\u7D04\u6570\u3092\u6C42\u3081\u308B\nlong long gcd(const\
    \ vector<long long> &A) {\n    long long ret = 0;\n    rep(i, A.size()) ret =\
    \ gcd(ret, A[i]);\n    return ret;\n}\n// \u6700\u5C0F\u516C\u500D\u6570\u3092\
    \u6C42\u3081\u308B\nlong long lcm(const vector<long long> &A, const long long\
    \ m = 0) { \n    long long ret = 1;\n    rep(i, A.size()) { ret = lcm(ret, A[i]);\
    \ if (m > 0) ret %= m;}\n    return ret;\n}\n// \u62E1\u5F35\u30E6\u30FC\u30AF\
    \u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\ntuple<long long, long long, long long>\
    \ extGCD(long long a, long long b) {\n    if (b == 0) return {a, 1, 0};\n    auto\
    \ [g, x, y] = extGCD(b, a % b);\n    return {g, y, x - (a / b) * y};\n}\n\n//\
    \ string\u95A2\u4FC2\ninline string lltos(long long x) { return to_string(x);}\n\
    inline int ctoi(char x) { return int(x - '0');}\ninline char itoc(int x) { return\
    \ (char)(x + '0');}\n#if __has_include(<boost/algorithm/string.hpp>)\ninline string\
    \ to_upper(string& S) { return boost::to_upper_copy(S);}\ninline string to_lower(string&\
    \ S) { return boost::to_lower_copy(S);}\n#endif\ninline bool is_lower(char c)\
    \ { return (c >= 'a') and (c <= 'z');}\ninline bool is_upper(char c) { return\
    \ (c >= 'A') and (c <= 'Z');}\ninline char to_upper(char c) { if (is_upper(c))\
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
    \ T> RULD(T x, T y, char c) { return {((c == 'R') ? x + 1 : ((c == 'L') ? x -\
    \ 1 : x)), ((c == 'U') ? y + 1 : ((c == 'D') ? y - 1 : y))};}\ntemplate <typename\
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
    \ find_greater_than_or_equal(const vector<T>& v, T key) { return lower_bound(v.begin(),\
    \ v.end(), key); }\ntemplate <typename T> inline typename set<T>::iterator find_greater_than_or_equal(const\
    \ set<T>& st, T key) { return st.lower_bound(key); }\n// \u30AD\u30FC\u3092\u8D85\
    \u3048\u308B\u6700\u5C0F\u306E\u8981\u7D20\u3092\u898B\u3064\u3051\u308B\u30A4\
    \u30C6\u30EC\u30FC\u30BF\u3092\u8FD4\u3059\u95A2\u6570\ntemplate <typename T>\
    \ inline typename vector<T>::iterator find_greater_than(const vector<T>& v, T\
    \ key) { return upper_bound(v.begin(), v.end(), key); }\ntemplate <typename T>\
    \ inline typename set<T>::iterator find_greater_than(const set<T>& st, T key)\
    \ { return st.upper_bound(key); }\n// \u30AD\u30FC\u4EE5\u4E0B\u306E\u6700\u5927\
    \u306E\u8981\u7D20\u3092\u898B\u3064\u3051\u308B\u30A4\u30C6\u30EC\u30FC\u30BF\
    \u3092\u8FD4\u3059\u95A2\u6570, \u306A\u3044\u5834\u5408\u306Fend\u3092\u8FD4\u3059\
    \ntemplate <typename T> inline typename vector<T>::iterator find_less_than_or_equal(const\
    \ vector<T>& v, T key) { auto it = upper_bound(v.begin(), v.end(), key); return\
    \ it == v.begin() ? v.end() : --it;}\ntemplate <typename T> inline typename set<T>::iterator\
    \ find_less_than_or_equal(const set<T>& st, T key) { auto it = st.upper_bound(key);\
    \ return it == st.begin() ? st.end() : --it;}\n// \u30AD\u30FC\u672A\u6E80\u306E\
    \u6700\u5927\u306E\u8981\u7D20\u3092\u898B\u3064\u3051\u308B\u30A4\u30C6\u30EC\
    \u30FC\u30BF\u3092\u8FD4\u3059\u95A2\u6570, \u306A\u3044\u5834\u5408\u306Fend\u3092\
    \u8FD4\u3059\ntemplate <typename T> inline typename vector<T>::iterator find_less_than(const\
    \ vector<T>& v, T key) { auto it = lower_bound(v.begin(), v.end(), key); return\
    \ it == v.begin() ? v.end() : --it; }\ntemplate <typename T> inline typename set<T>::iterator\
    \ find_less_than(const set<T>& st, T key) { auto it = st.lower_bound(key); return\
    \ it == st.begin() ? st.end() : --it;}\n\ntemplate <typename T> auto operator+(const\
    \ vector<T>& A, const T x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i]\
    \ = A[i] + x; return ret; }\ntemplate <typename T> auto operator-(const vector<T>&\
    \ A, const T x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i] = A[i] - x;\
    \ return ret; }\ntemplate <typename T> auto operator*(const vector<T>& A, const\
    \ T x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i] = A[i] * x; return ret;\
    \ }\ntemplate <typename T> auto operator/(const vector<T>& A, const T x) { vector<T>\
    \ ret(A.size()); rep(i, A.size()) ret[i] = A[i] / x; return ret; }\ntemplate <typename\
    \ T> auto operator%(const vector<T>& A, const T x) { vector<T> ret(A.size());\
    \ rep(i, A.size()) ret[i] = A[i] % x; return ret; }\ntemplate <typename T> auto\
    \ binpow(const vector<T>& A, const T x) { vector<T> ret(A.size()); rep(i, A.size())\
    \ ret[i] = binpow(A[i], x); return ret; }\n\ntemplate <typename R> auto& operator++(R&\
    \ a) { for (auto& x : a) ++x; return a; }\ntemplate <typename R> auto operator++(R&\
    \ a, int) { auto temp = a; for (auto& x : a) x++; return temp; }\ntemplate <typename\
    \ R> auto& operator--(R& a) { for (auto& x : a) --x; return a; }\ntemplate <typename\
    \ R> auto operator--(R& a, int) { auto temp = a; for (auto& x : a) x--; return\
    \ temp; }\n\ntemplate <typename T, typename U> auto operator+(const pair<T, U>&\
    \ p, const T x) { return pair<T, U>(p.first + x, p.second + x); }\ntemplate <typename\
    \ T, typename U> auto operator-(const pair<T, U>& p, const T x) { return pair<T,\
    \ U>(p.first - x, p.second - x); }\ntemplate <typename T, typename U> auto operator*(const\
    \ pair<T, U>& p, const T x) { return pair<T, U>(p.first * x, p.second * x); }\n\
    template <typename T, typename U> auto operator/(const pair<T, U>& p, const T\
    \ x) { return pair<T, U>(p.first / x, p.second / x); }\ntemplate <typename T,\
    \ typename U> auto operator%(const pair<T, U>& p, const T x) { return pair<T,\
    \ U>(p.first % x, p.second % x); }\ntemplate <typename T, typename U> auto binpow(const\
    \ pair<T, U>& p, const T x) { return pair<T, U>(binpow(p.first, x), binpow(p.second,\
    \ x)); }\n\ntemplate <typename T, typename U> auto operator+(const pair<T, U>&\
    \ p, const pair<T, U>& q) { return pair<T, U>(p.first + q.first, p.second + q.second);\
    \ }\ntemplate <typename T, typename U> auto operator-(const pair<T, U>& p, const\
    \ pair<T, U>& q) { return pair<T, U>(p.first - q.first, p.second - q.second);\
    \ }\ntemplate <typename T, typename U> auto operator*(const pair<T, U>& p, const\
    \ pair<T, U>& q) { return pair<T, U>(p.first * q.first, p.second * q.second);\
    \ }\ntemplate <typename T, typename U> auto operator/(const pair<T, U>& p, const\
    \ pair<T, U>& q) { return pair<T, U>(p.first / q.first, p.second / q.second);\
    \ }\ntemplate <typename T, typename U> auto operator%(const pair<T, U>& p, const\
    \ pair<T, U>& q) { return pair<T, U>(p.first % q.first, p.second % q.second);\
    \ }\n\ntemplate <typename T, typename U> auto& operator++(pair<T, U>& p) { ++p.first;\
    \ ++p.second; return p; }\ntemplate <typename T, typename U> auto operator++(pair<T,\
    \ U>& p, int) { auto temp = p; ++p.first; ++p.second; return temp; }\ntemplate\
    \ <typename T, typename U> auto& operator--(pair<T, U>& p) { --p.first; --p.second;\
    \ return p; }\ntemplate <typename T, typename U> auto operator--(pair<T, U>& p,\
    \ int) { auto temp = p; --p.first; --p.second; return temp; }\n\ntemplate<typename\
    \ T, typename U> vector<pair<T, U>> to_pair(const vector<T>& vec1, const vector<U>&\
    \ vec2) {\n    size_t n = min(vec1.size(), vec2.size());\n    vector<pair<T, U>>\
    \ result(n);\n    for(size_t i = 0; i < n; ++i) result.emplace_back(vec1[i], vec2[i]);\n\
    \    return result;\n}\n#line 3 \"structure/segment-tree-beats.cpp\"\n\n// Segment\
    \ Tree Beats\n// https://tjkendev.github.io/procon-library/cpp/range_query/segment_tree_beats_2.html\n\
    // - l<=i<r \u306B\u3064\u3044\u3066\u3001 A_i \u306E\u5024\u3092 min(A_i, x)\
    \ \u306B\u66F4\u65B0\n// - l<=i<r \u306B\u3064\u3044\u3066\u3001 A_i \u306E\u5024\
    \u3092 max(A_i, x) \u306B\u66F4\u65B0\n// - l<=i<r \u306E\u4E2D\u306E A_i \u306E\
    \u6700\u5927\u5024\u3092\u6C42\u3081\u308B\n// - l<=i<r \u306E\u4E2D\u306E A_i\
    \ \u306E\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\n// - l<=i<r \u306E A_i \u306E\
    \u548C\u3092\u6C42\u3081\u308B\n// - l<=i<r \u306B\u3064\u3044\u3066\u3001 A_i\
    \ \u306E\u5024\u306B x \u3092\u52A0\u3048\u308B\n// - l<=i<r \u306B\u3064\u3044\
    \u3066\u3001 A_i \u306E\u5024\u3092 x \u306B\u66F4\u65B0\n\ntemplate<typename\
    \ T>\nclass SegmentTreeBeats {\n    const T inf = 1e18;\n    int n, n0;\n\n  \
    \  vector<T> max_v, smax_v, max_c;\n    vector<T> min_v, smin_v, min_c;\n    vector<T>\
    \ sum;\n    vll len;\n    vector<T> ladd, lval;\n\n    void update_node_max(int\
    \ k, T x) {\n        sum[k] += (x - max_v[k]) * max_c[k];\n\n        if (max_v[k]\
    \ == min_v[k]) { \n            max_v[k] = min_v[k] = x;\n        } \n        else\
    \ if (max_v[k] == smin_v[k]) {\n            max_v[k] = smin_v[k] = x;\n      \
    \  } \n        else {\n            max_v[k] = x;\n        }\n\n        if (lval[k]\
    \ != inf && x < lval[k]) {\n            lval[k] = x;\n        }\n    }\n\n   \
    \ void update_node_min(int k, T x) {\n        sum[k] += (x - min_v[k]) * min_c[k];\n\
    \n        if (max_v[k] == min_v[k]) {\n            max_v[k] = min_v[k] = x;\n\
    \        } \n        else if (smax_v[k] == min_v[k]) {\n            min_v[k] =\
    \ smax_v[k] = x;\n        } \n        else {\n            min_v[k] = x;\n    \
    \    }\n\n        if (lval[k] != inf && lval[k] < x) {\n            lval[k] =\
    \ x;\n        }\n    }\n\n    void push(int k) {\n        if (n0 - 1 <= k) return;\n\
    \n        if (lval[k] != inf) {\n            updateall(2 * k + 1, lval[k]);\n\
    \            updateall(2 * k + 2, lval[k]);\n            lval[k] = inf;\n    \
    \        return;\n        }\n\n        if (ladd[k] != 0) {\n            addall(2\
    \ * k + 1, ladd[k]);\n            addall(2 * k + 2, ladd[k]);\n            ladd[k]\
    \ = 0;\n        }\n\n        if (max_v[k] < max_v[2 * k + 1]) {\n            update_node_max(2\
    \ * k + 1, max_v[k]);\n        }\n        if (min_v[2 * k + 1] < min_v[k]) {\n\
    \            update_node_min(2 * k + 1, min_v[k]);\n        }\n\n        if (max_v[k]\
    \ < max_v[2 * k + 2]) {\n            update_node_max(2 * k + 2, max_v[k]);\n \
    \       }\n        if (min_v[2 * k + 2] < min_v[k]) {\n            update_node_min(2\
    \ * k + 2, min_v[k]);\n        }\n    }\n\n    void update(int k) {\n        sum[k]\
    \ = sum[2 * k + 1] + sum[2 * k + 2];\n\n        if (max_v[2 * k + 1] < max_v[2\
    \ * k + 2]) {\n            max_v[k] = max_v[2 * k + 2];\n            max_c[k]\
    \ = max_c[2 * k + 2];\n            smax_v[k] = max(max_v[2 * k + 1], smax_v[2\
    \ * k + 2]);\n        } \n        else if (max_v[2 * k + 1] > max_v[2 * k + 2])\
    \ {\n            max_v[k] = max_v[2 * k + 1];\n            max_c[k] = max_c[2\
    \ * k + 1];\n            smax_v[k] = max(smax_v[2 * k + 1], max_v[2 * k + 2]);\n\
    \        } \n        else {\n            max_v[k] = max_v[2 * k + 1];\n      \
    \      max_c[k] = max_c[2 * k + 1] + max_c[2 * k + 2];\n            smax_v[k]\
    \ = max(smax_v[2 * k + 1], smax_v[2 * k + 2]);\n        }\n\n        if (min_v[2\
    \ * k + 1] < min_v[2 * k + 2]) {\n            min_v[k] = min_v[2 * k + 1];\n \
    \           min_c[k] = min_c[2 * k + 1];\n            smin_v[k] = min(smin_v[2\
    \ * k + 1], min_v[2 * k + 2]);\n        } \n        else if (min_v[2 * k + 1]\
    \ > min_v[2 * k + 2]) {\n            min_v[k] = min_v[2 * k + 2];\n          \
    \  min_c[k] = min_c[2 * k + 2];\n            smin_v[k] = min(min_v[2 * k + 1],\
    \ smin_v[2 * k + 2]);\n        } \n        else {\n            min_v[k] = min_v[2\
    \ * k + 1];\n            min_c[k] = min_c[2 * k + 1] + min_c[2 * k + 2];\n   \
    \         smin_v[k] = min(smin_v[2 * k + 1], smin_v[2 * k + 2]);\n        }\n\
    \    }\n\n    void _apply_chmin(T x, int a, int b, int k, int l, int r) {\n  \
    \      if (b <= l || r <= a || max_v[k] <= x) {\n            return;\n       \
    \ }\n        if (a <= l && r <= b && smax_v[k] < x) {\n            update_node_max(k,\
    \ x);\n            return;\n        }\n\n        push(k);\n        _apply_chmin(x,\
    \ a, b, 2 * k + 1, l, (l + r) / 2);\n        _apply_chmin(x, a, b, 2 * k + 2,\
    \ (l + r) / 2, r);\n        update(k);\n    }\n\n      void _apply_chmax(T x,\
    \ int a, int b, int k, int l, int r) {\n        if (b <= l || r <= a || x <= min_v[k])\
    \ {\n            return;\n        }\n        if (a <= l && r <= b && x < smin_v[k])\
    \ {\n            update_node_min(k, x);\n            return;\n        }\n\n  \
    \      push(k);\n        _apply_chmax(x, a, b, 2 * k + 1, l, (l + r) / 2);\n \
    \       _apply_chmax(x, a, b, 2 * k + 2, (l + r) / 2, r);\n        update(k);\n\
    \    }\n\n    void addall(int k, T x) {\n        max_v[k] += x;\n        if (smax_v[k]\
    \ != -inf) smax_v[k] += x;\n        min_v[k] += x;\n        if (smin_v[k] != inf)\
    \ smin_v[k] += x;\n\n        sum[k] += len[k] * x;\n        if (lval[k] != inf)\
    \ {\n            lval[k] += x;\n        } \n        else {\n            ladd[k]\
    \ += x;\n        }\n    }\n\n    void updateall(int k, T x) {\n        max_v[k]\
    \ = x;\n        smax_v[k] = -inf;\n        min_v[k] = x;\n        smin_v[k] =\
    \ inf;\n        max_c[k] = min_c[k] = len[k];\n\n        sum[k] = x * len[k];\n\
    \        lval[k] = x;\n        ladd[k] = 0;\n    }\n\n    void _apply_add(T x,\
    \ int a, int b, int k, int l, int r) {\n        if (b <= l || r <= a) {\n    \
    \        return;\n        }\n        if (a <= l && r <= b) {\n            addall(k,\
    \ x);\n            return;\n        }\n\n        push(k);\n        _apply_add(x,\
    \ a, b, 2 * k + 1, l, (l + r) / 2);\n        _apply_add(x, a, b, 2 * k + 2, (l\
    \ + r) / 2, r);\n        update(k);\n    }\n\n    void _apply_set(T x, int a,\
    \ int b, int k, int l, int r) {\n        if (b <= l || r <= a) {\n           \
    \ return;\n        }\n        if (a <= l && r <= b) {\n            updateall(k,\
    \ x);\n            return;\n        }\n\n        push(k);\n        _apply_set(x,\
    \ a, b, 2 * k + 1, l, (l + r) / 2);\n        _apply_set(x, a, b, 2 * k + 2, (l\
    \ + r) / 2, r);\n        update(k);\n    }\n\n    T _prod_max(int a, int b, int\
    \ k, int l, int r) {\n        if (b <= l || r <= a) {\n            return -inf;\n\
    \        }\n        if (a <= l && r <= b) {\n            return max_v[k];\n  \
    \      }\n        push(k);\n        T lv = _prod_max(a, b, 2 * k + 1, l, (l +\
    \ r) / 2);\n        T rv = _prod_max(a, b, 2 * k + 2, (l + r) / 2, r);\n     \
    \   return max(lv, rv);\n    }\n\n    T _prod_min(int a, int b, int k, int l,\
    \ int r) {\n        if (b <= l || r <= a) {\n            return inf;\n       \
    \ }\n        if (a <= l && r <= b) {\n            return min_v[k];\n        }\n\
    \        push(k);\n        T lv = _prod_min(a, b, 2 * k + 1, l, (l + r) / 2);\n\
    \        T rv = _prod_min(a, b, 2 * k + 2, (l + r) / 2, r);\n        return min(lv,\
    \ rv);\n    }\n\n    T _prod_sum(int a, int b, int k, int l, int r) {\n      \
    \  if (b <= l || r <= a) {\n            return 0;\n        }\n        if (a <=\
    \ l && r <= b) {\n            return sum[k];\n        }\n        push(k);\n  \
    \      ll lv = _prod_sum(a, b, 2 * k + 1, l, (l + r) / 2);\n        ll rv = _prod_sum(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n        return lv + rv;\n    }\n\npublic:\n\
    \    SegmentTreeBeats(int n) { \n        vector<T> A(n, 0);\n        init(n, A);\n\
    \    }\n\n    SegmentTreeBeats(int n, T a) {\n        vector<T> A(n, a);\n   \
    \     init(n, A);\n    }\n\n    SegmentTreeBeats(vector<T> &A) : n(A.size()) {\n\
    \        init(n, A);\n    }\n\n    void init(int n, vector<T> &A) {\n        max_v.resize(4\
    \ * n);\n        smax_v.resize(4 * n);\n        max_c.resize(4 * n);\n       \
    \ min_v.resize(4 * n);\n        smin_v.resize(4 * n);\n        min_c.resize(4\
    \ * n);\n        sum.resize(4 * n);\n        len.resize(4 * n);\n        ladd.resize(4\
    \ * n);\n        lval.resize(4 * n);\n\n        n0 = 1;\n        while (n0 < n)\
    \ n0 <<= 1;\n\n        for (int i = 0; i < 2 * n0; ++i) ladd[i] = 0, lval[i] =\
    \ inf;\n        len[0] = n0;\n        for (int i = 0; i < n0 - 1; ++i) len[2 *\
    \ i + 1] = len[2 * i + 2] = (len[i] >> 1);\n\n        for (int i = 0; i < n; ++i)\
    \ {\n            max_v[n0 - 1 + i] = min_v[n0 - 1 + i] = sum[n0 - 1 + i] = A[i];\n\
    \            smax_v[n0 - 1 + i] = -inf;\n            smin_v[n0 - 1 + i] = inf;\n\
    \            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 1;\n        }\n\n       \
    \ for (int i = n; i < n0; ++i) {\n            max_v[n0 - 1 + i] = smax_v[n0 -\
    \ 1 + i] = -inf;\n            min_v[n0 - 1 + i] = smin_v[n0 - 1 + i] = inf;\n\
    \            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 0;\n        }\n        for\
    \ (int i = n0 - 2; i >= 0; i--) {\n            update(i);\n        }\n    }\n\n\
    \    // range minimize query\n    void apply_chmin(long long l, long long r, T\
    \ x) {\n         _apply_chmin(x, l, r, 0, 0, n0); \n    }\n\n    void apply_chmin(int\
    \ p, T x) {\n        apply_chmin(p, p + 1, x);\n    }\n\n    // range maximize\
    \ query\n    void apply_chmax(long long l, long long r, T x) { \n        _apply_chmax(x,\
    \ l, r, 0, 0, n0); \n    }\n\n    void apply_chmax(int p, T x) {\n        apply_chmax(p,\
    \ p + 1, x);\n    }\n\n    // range add query\n    void apply_add(long long l,\
    \ long long r, T x) { \n        _apply_add(x, l, r, 0, 0, n0); \n    }\n\n   \
    \ void apply_add(int p, T x) {\n        apply_add(p, p + 1, x);\n    }\n\n   \
    \ // range update query\n    void apply_set(long long l, long long r, T x) {\n\
    \        _apply_set(x, l, r, 0, 0, n0); \n    }\n\n    void apply_set(int p, T\
    \ x) {\n        apply_set(p, p + 1, x);\n    }\n\n    // range maximum query\n\
    \    T prod_max(long long l, long long r) { \n        return _prod_max(l, r, 0,\
    \ 0, n0); \n    }\n\n    // range minimum query\n    T prod_min(long long l, long\
    \ long r) { \n        return _prod_min(l, r, 0, 0, n0); \n    }\n\n    // range\
    \ sum query\n    T prod_sum(long long l, long long r) { \n        return _prod_sum(l,\
    \ r, 0, 0, n0);\n    }\n\n    T get(int p) {\n        return prod_sum(p, p + 1);\n\
    \    }\n};\n#line 4 \"test/structure/segment-tree-beats/aoj-dsl-2-g.test.cpp\"\
    \n\nint main() {\n    ll n, q;\n    cin >> n >> q;\n\n    SegmentTreeBeats<ll>\
    \ tree(n, 0);\n    while (q--) {\n        ll t;\n        cin >> t;\n\n       \
    \ if (t == 0) {\n            ll s, t, x;\n            cin >> s >> t >> x;\n  \
    \          tree.apply_add(s - 1, t, x);\n        }\n        else {\n         \
    \   ll s, t;\n            cin >> s >> t;\n            cout << tree.prod_sum(s\
    \ - 1, t) << endl;\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&\"\
    \n\n#include \"../../../structure/segment-tree-beats.cpp\"\n\nint main() {\n \
    \   ll n, q;\n    cin >> n >> q;\n\n    SegmentTreeBeats<ll> tree(n, 0);\n   \
    \ while (q--) {\n        ll t;\n        cin >> t;\n\n        if (t == 0) {\n \
    \           ll s, t, x;\n            cin >> s >> t >> x;\n            tree.apply_add(s\
    \ - 1, t, x);\n        }\n        else {\n            ll s, t;\n            cin\
    \ >> s >> t;\n            cout << tree.prod_sum(s - 1, t) << endl;\n        }\n\
    \    }\n\n    return 0;\n}"
  dependsOn:
  - structure/segment-tree-beats.cpp
  - base.cpp
  isVerificationFile: true
  path: test/structure/segment-tree-beats/aoj-dsl-2-g.test.cpp
  requiredBy: []
  timestamp: '2024-06-23 10:33:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/segment-tree-beats/aoj-dsl-2-g.test.cpp
layout: document
redirect_from:
- /verify/test/structure/segment-tree-beats/aoj-dsl-2-g.test.cpp
- /verify/test/structure/segment-tree-beats/aoj-dsl-2-g.test.cpp.html
title: test/structure/segment-tree-beats/aoj-dsl-2-g.test.cpp
---
