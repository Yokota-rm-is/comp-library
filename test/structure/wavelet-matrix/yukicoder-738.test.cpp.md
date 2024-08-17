---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.cpp
    title: base.cpp
  - icon: ':heavy_check_mark:'
    path: structure/wavelet-matrix.cpp
    title: structure/wavelet-matrix.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/738
    links:
    - https://yukicoder.me/problems/no/738
  bundledCode: "#line 1 \"test/structure/wavelet-matrix/yukicoder-738.test.cpp\"\n\
    #define PROBLEM \"https://yukicoder.me/problems/no/738\"\n\n#line 2 \"base.cpp\"\
    \n\n#include <bits/stdc++.h>\n// #include <atcoder/all>\n#if __has_include(<boost/algorithm/string.hpp>)\n\
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
    const long long inf64 = INF64 / 2;\nconst double EPS = numeric_limits<double>::epsilon();\
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
    template<typename T> using priority_queue_greater = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n// boost\u95A2\u9023\n#if __has_include(<boost/algorithm/cxx11/all_of.hpp>)\n\
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
    \ v.end(), key); }\ntemplate <typename T> inline typename set<T>::iterator find_greater_than_or_equal(set<T>&\
    \ st, T key) { return st.lower_bound(key); }\n// \u30AD\u30FC\u3092\u8D85\u3048\
    \u308B\u6700\u5C0F\u306E\u8981\u7D20\u3092\u898B\u3064\u3051\u308B\u30A4\u30C6\
    \u30EC\u30FC\u30BF\u3092\u8FD4\u3059\u95A2\u6570\ntemplate <typename T> inline\
    \ typename vector<T>::iterator find_greater_than(vector<T>& v, T key) { return\
    \ upper_bound(v.begin(), v.end(), key); }\ntemplate <typename T> inline typename\
    \ set<T>::iterator find_greater_than(set<T>& st, T key) { return st.upper_bound(key);\
    \ }\n// \u30AD\u30FC\u4EE5\u4E0B\u306E\u6700\u5927\u306E\u8981\u7D20\u3092\u898B\
    \u3064\u3051\u308B\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u8FD4\u3059\u95A2\u6570\
    , \u306A\u3044\u5834\u5408\u306Fend\u3092\u8FD4\u3059\ntemplate <typename T> inline\
    \ typename vector<T>::iterator find_less_than_or_equal(vector<T>& v, T key) {\
    \ auto it = upper_bound(v.begin(), v.end(), key); return it == v.begin() ? v.end()\
    \ : --it;}\ntemplate <typename T> inline typename set<T>::iterator find_less_than_or_equal(set<T>&\
    \ st, T key) { auto it = st.upper_bound(key); return it == st.begin() ? st.end()\
    \ : --it;}\n// \u30AD\u30FC\u672A\u6E80\u306E\u6700\u5927\u306E\u8981\u7D20\u3092\
    \u898B\u3064\u3051\u308B\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u8FD4\u3059\u95A2\
    \u6570, \u306A\u3044\u5834\u5408\u306Fend\u3092\u8FD4\u3059\ntemplate <typename\
    \ T> inline typename vector<T>::iterator find_less_than(vector<T>& v, T key) {\
    \ auto it = lower_bound(v.begin(), v.end(), key); return it == v.begin() ? v.end()\
    \ : --it; }\ntemplate <typename T> inline typename set<T>::iterator find_less_than(set<T>&\
    \ st, T key) { auto it = st.lower_bound(key); return it == st.begin() ? st.end()\
    \ : --it;}\n\ntemplate <typename T> auto operator+(const vector<T>& A, const T\
    \ x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i] = A[i] + x; return ret;\
    \ }\ntemplate <typename T> auto operator-(const vector<T>& A, const T x) { vector<T>\
    \ ret(A.size()); rep(i, A.size()) ret[i] = A[i] - x; return ret; }\ntemplate <typename\
    \ T> auto operator*(const vector<T>& A, const T x) { vector<T> ret(A.size());\
    \ rep(i, A.size()) ret[i] = A[i] * x; return ret; }\ntemplate <typename T> auto\
    \ operator/(const vector<T>& A, const T x) { vector<T> ret(A.size()); rep(i, A.size())\
    \ ret[i] = A[i] / x; return ret; }\ntemplate <typename T> auto operator%(const\
    \ vector<T>& A, const T x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i]\
    \ = A[i] % x; return ret; }\ntemplate <typename T> auto binpow(const vector<T>&\
    \ A, const T x) { vector<T> ret(A.size()); rep(i, A.size()) ret[i] = binpow(A[i],\
    \ x); return ret; }\n\ntemplate <typename R> auto& operator++(R& a) { for (auto&\
    \ x : a) ++x; return a; }\ntemplate <typename R> auto operator++(R& a, int) {\
    \ auto temp = a; for (auto& x : a) x++; return temp; }\ntemplate <typename R>\
    \ auto& operator--(R& a) { for (auto& x : a) --x; return a; }\ntemplate <typename\
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
    \    return result;\n}\n#line 3 \"structure/wavelet-matrix.cpp\"\n\nstruct BitVector\
    \ {\n    using ull = unsigned long long;\n    using uint = uint16_t;\n\n    ull\
    \ N;    // \u30D3\u30C3\u30C8\u30D9\u30AF\u30C8\u30EB\u306E\u30B5\u30A4\u30BA\n\
    \    ull blockBitNum = 16;\n    ull LEVEL_L = 512;\n    ull LEVEL_S = 16;\n\n\
    \    vector<ull> L;   // \u5927\u30D6\u30ED\u30C3\u30AF\n    vector<uint> S; \
    \  // \u5C0F\u30D6\u30ED\u30C3\u30AF\n    vector<uint> B;   // \u30D3\u30C3\u30C8\
    \u30D9\u30AF\u30C8\u30EB\n\n    ull ones, zeros = 0; // 1bit\u306E\u6570, 0bit\u306E\
    \u6570\n\n    BitVector(ull n) : N(n) {\n        const ull s = (n + blockBitNum\
    \ - 1) / blockBitNum + 1;   // ceil(n, blockSize)\n        B.assign(s, 0);\n \
    \       L.assign(n / LEVEL_L + 1, 0);\n        S.assign(n / LEVEL_S + 1, 0);\n\
    \    }\n\n    // B[pos] = bit\n    void set(const ull bit, const ull pos){\n \
    \       assert(bit == 0 or bit == 1);\n        assert(pos < N);\n\n        const\
    \ ull blockPos = pos / blockBitNum;\n        const ull offset = pos % blockBitNum;\n\
    \        if (bit == 1) B[blockPos] |= (1ull << offset);\n        else B[blockPos]\
    \ &= (~(1ull << offset));\n    }\n\n    // B[pos]\n    ull access(const ull pos)\
    \ {\n        assert(pos < N);\n        const ull blockPos = pos / blockBitNum;\n\
    \        const ull offset   = pos % blockBitNum;\n        return ((B[blockPos]\
    \ >> offset) & 1);\n    }\n\n    void build() {\n        ull num = 0;\n      \
    \  for (ull i = 0; i <= N; i++){\n            if (i % LEVEL_L == 0) L[i / LEVEL_L]\
    \ = num;\n            if (i % LEVEL_S == 0) S[i / LEVEL_S] = num - L[i / LEVEL_L];\n\
    \            if (i != N and i % blockBitNum == 0) {\n                num += bit_count(B[i\
    \ / blockBitNum]);\n            }\n        }\n        ones = num;\n        zeros\
    \ = N - ones;\n    }\n\n    // B[0, pos)\u306Ebit\u306E\u6570\n    ull rank(const\
    \ ull bit, const ull pos) {\n        assert(bit == 0 or bit == 1);\n        assert(pos\
    \ <= N);\n\n        if (bit == 1) {\n            return L[pos / LEVEL_L] + S[pos\
    \ / LEVEL_S] + bit_count(B[pos / blockBitNum] & ((1ull << (pos % blockBitNum))\
    \ - 1));\n        }\n        else return pos - rank(1, pos);\n    }\n\n    //\
    \ k\u756A\u76EE(1-indexed)\u306Ebit\u306E\u4F4D\u7F6E(0-indexed)\u3092\u8FD4\u3059\
    \n    // \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306FN\u3092\u8FD4\u3059\n\
    \    ull select(const ull bit, const ull k) {\n        assert(bit == 0 or bit\
    \ == 1);\n        assert(k > 0);\n\n        if (bit == 0 and k > zeros) return\
    \ N;\n        if (bit == 1 and k > ones) return N;\n\n        // \u5927\u30D6\u30ED\
    \u30C3\u30AFL\u5185\u3092\u691C\u7D22\n        ull large_idx = 0;\n        {\n\
    \            ull left = 0;\n            ull right = L.size();\n            while\
    \ (right - left > 1) {\n                ull mid = (left + right) / 2;\n      \
    \          ull rank;\n                if (bit == 1) rank = L[mid];\n         \
    \       else rank = mid * LEVEL_L - L[mid];\n\n                if (rank < k) {\n\
    \                    left = mid;\n                    large_idx = mid;\n     \
    \           } \n                else right = mid;\n            }\n        }\n\n\
    \        // \u5C0F\u30D6\u30ED\u30C3\u30AFS\u5185\u3092\u691C\u7D22\n        ull\
    \ small_idx = (large_idx * LEVEL_L) / LEVEL_S;\n        {\n            ull left\
    \ = (large_idx * LEVEL_L) / LEVEL_S;\n            ull right = min(((large_idx\
    \ + 1) * LEVEL_L) / LEVEL_S, (ull)S.size());\n            while (right - left\
    \ > 1) {\n                ull mid = (left + right) / 2;\n                ull rank;\n\
    \                if (bit == 1) rank = L[large_idx] + S[mid];\n               \
    \ else rank = mid * LEVEL_S - (L[large_idx] + S[mid]);\n\n                if (rank\
    \ < k) {\n                    left = mid;\n                    small_idx = mid;\n\
    \                } \n                else right = mid;\n            }\n      \
    \  }\n\n        // B\u3092\u30D6\u30ED\u30C3\u30AF\u5358\u4F4D\u3067\u9806\u756A\
    \u306B\u63A2\u7D22\n        ull rank_pos = 0;\n        {\n            const ull\
    \ begin_block_idx = (small_idx * LEVEL_S) / blockBitNum;\n            ull total_bit;\n\
    \            if (bit == 1) total_bit = L[large_idx] + S[small_idx];\n        \
    \    else total_bit = small_idx * LEVEL_S - (L[large_idx] + S[small_idx]);\n\n\
    \            for (ull i = 0;; ++i) {\n                ull b;\n               \
    \ if (bit == 1) b = bit_count(B[begin_block_idx + i]);\n                else b\
    \ = blockBitNum - bit_count(B[begin_block_idx + i]);\n\n                if (total_bit\
    \ + b >= k) {\n                    ull block;\n                    if (bit ==\
    \ 1) block = B[begin_block_idx + i];\n                    else block = ~B[begin_block_idx\
    \ + i];\n\n                    rank_pos = (begin_block_idx + i) * blockBitNum\
    \ + select_in_block(block, k - total_bit);\n                    break;\n     \
    \           }\n\n                total_bit += b;\n            }\n        }\n\n\
    \        return rank_pos;\n    }\n\n    ull size() {\n        return N;\n    }\n\
    \n    ull select_in_block(ull x, ull k) {\n        ull x1 = x - ((x & 0xAAAAAAAAAAAAAAAALLU)\
    \ >> 1);\n        ull x2 = (x1 & 0x3333333333333333LLU) + ((x1 >> 2) & 0x3333333333333333LLU);\n\
    \        ull x3 = (x2 + (x2 >> 4)) & 0x0F0F0F0F0F0F0F0FLLU;\n\n        ull pos\
    \ = 0;\n        for (;; pos += 8){\n            ull k_next = (x3 >> pos) & 0xFFLLU;\n\
    \            if (k <= k_next) break;\n            k -= k_next;\n        }\n\n\
    \        ull v2 = (x2 >> pos) & 0xFLLU;\n        if (k > v2) {\n            k\
    \ -= v2;\n            pos += 4;\n        }\n\n        ull v1 = (x1 >> pos) & 0x3LLU;\n\
    \        if (k > v1){\n            k -= v1;\n            pos += 2;\n        }\n\
    \n        ull v0  = (x >> pos) & 0x1LLU;\n        if (v0 < k){\n            k\
    \ -= v0;\n            pos += 1;\n        }\n\n        return pos;\n    }\n\n \
    \   friend ostream& operator<< (ostream& os, BitVector& bv) {\n        os << \"\
    L: \";\n        rep(i, bv.L.size()) {\n            os << bv.L[i] << \", \";\n\
    \        }\n        os << endl;\n        os << \"S: \";\n        rep(i, bv.S.size())\
    \ {\n            os << bv.S[i] << \", \";\n        }\n        os << endl;\n\n\
    \        return os;\n    }\n};\n\ntemplate <typename T>\nstruct Node {\n    T\
    \ val;\n    ull index;\n\n    Node(T val, ull index) : val(val), index(index)\
    \ {}\n\n    operator T() const { return val; }\n    friend ostream& operator<<\
    \ (ostream& os, Node& node) {\n        return os << node.val;\n    }\n};\n\ntemplate\
    \ <typename T>\nstruct WaveletMatrix {\n    using ull = unsigned long long;\n\
    \    using S = Node<T>;\n\n    vector<BitVector> bit_vectors;\n    unordered_map<ull,\
    \ ull> begin_indices;   // \u6700\u5F8C\u306E\u30BD\u30FC\u30C8\u3055\u308C\u305F\
    \u914D\u5217\u3067\u5404\u6587\u5B57\u306E\u958B\u59CB\u4F4D\u7F6E\n    vector<vector<T>>\
    \ cumulative_sum;\n    T min_val, max_val;\n\n    ull N;  // \u4E0E\u3048\u3089\
    \u308C\u305F\u914D\u5217\u306E\u30B5\u30A4\u30BA\n    ull bit_size;   // \u6587\
    \u5B57\u3092\u8868\u3059\u306E\u306B\u5FC5\u8981\u306Abit\u6570\n\n    T NOTFOUND\
    \ = numeric_limits<T>::max() / 2;\n\n    WaveletMatrix (const vector<T> &A) {\n\
    \        build(A);\n    }\n\n    void build(const vector<T> &A) {\n        assert(A.size()\
    \ > 0);\n        fore(a, A) assert(a >= 0);\n\n        N = A.size();\n       \
    \ bit_size = 0;\n        max_val = *max_element(begin(A), end(A));\n        min_val\
    \ = *min_element(begin(A), end(A));\n        while (T(1ull << bit_size) <= max_val\
    \ + 1) ++bit_size;\n\n        bit_vectors.assign(bit_size, BitVector(N));\n  \
    \      cumulative_sum.assign(bit_size, vector<T>(N + 1, 0));\n\n        vector<T>\
    \ cur = A;\n        vector<T> nxt(N);\n        repd(h, bit_size) {\n         \
    \   rep(i, N) if ((cur[i] >> h) & 1) bit_vectors[h].set(1, i);\n            bit_vectors[h].build();\n\
    \n            auto it0 = nxt.begin();\n            auto it1 = nxt.begin() + bit_vectors[h].zeros;\n\
    \n            rep(i, N) {\n                if (bit_vectors[h].access(i) == 1)\
    \ {\n                    *it1 = cur[i];\n                    ++it1;\n        \
    \        }\n                else {\n                    *it0 = cur[i];\n     \
    \               ++it0;\n                }\n            }\n\n            rep(i,\
    \ N) {\n                cumulative_sum[h][i + 1] = cumulative_sum[h][i] + cur[i];\n\
    \            }\n            \n            swap(cur, nxt);\n        }\n\n     \
    \   repd(i, N) {\n            begin_indices[cur[i]] = i;\n        }\n    }\n\n\
    \    // v[pos]\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    T access(ull\
    \ pos) {\n        assert(pos < N);\n\n        T val = 0;\n        repd(h, bit_size)\
    \ {\n            ull bit = bit_vectors[h].access(pos);   // \u3082\u3068\u306E\
    \u6570\u5024\u306Ei\u756A\u76EE\u306Ebit\n            if (bit == 1) {\n      \
    \          val |= (1ull << h);\n                pos = bit_vectors[h].rank(1, pos)\
    \ + bit_vectors[h].zeros;\n            }\n            else pos = bit_vectors[h].rank(0,\
    \ pos);\n        }\n        return val;\n    }\n\n    // k\u756A\u76EE(1-indexed)\u306E\
    val\u306E\u4F4D\u7F6E(0-indexed)\u3092\u8FD4\u3059\n    // \u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u306FN\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n\
    \    ull select(T val, ull k) {\n        assert(k > 0);\n        if (!begin_indices.contains(val))\
    \ return N;\n        if (k == 1) return begin_indices[val];\n\n        ull index\
    \ = begin_indices[val] + k;\n        rep(h, bit_size){\n            ull bit =\
    \ ((val >> h) & 1); // \u4E0B\u304B\u3089i\u756A\u76EE\u306Ebit\n            if\
    \ (bit == 1) index -= bit_vectors[h].zeros;\n            \n            index =\
    \ bit_vectors[h].select(bit, index) + 1;\n        }\n        return index;\n \
    \   }\n\n    // v[l, r)\u3067k\u756A\u76EE\u306B\u5927\u304D\u3044\u6570\u5024\
    \u3068index\u3092\u8FD4\u3059(k\u306F1-indexed)\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n\
    \    S kth_max(ull l, ull r, ull k) {\n        assert(l < r and r <= N and 0 <\
    \ k and k <= r - l);\n        return quantile(l, r, r - l - k);\n    }\n\n   \
    \ // v[l, r)\u3067k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u6570\u5024\u3068index\u3092\
    \u8FD4\u3059(k\u306F1-indexed)\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n\
    \    S kth_min(ull l, ull r, ull k) {\n        assert(l < r and r <= N and 0 <\
    \ k and k <= r - l);\n        return quantile(l, r, k - 1);\n    }\n\n    // v[l,\
    \ r)\u306E\u4E2D\u592E\u5024(\u5C0F\u3055\u3044\u65B9)\u3068\u4E2D\u592E\u5024\
    (\u5927\u304D\u3044\u65B9)\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n\
    \    pair<T, T> median(ull l, ull r) {\n        assert(l < r and r <= N);\n  \
    \      T median_floor = quantile(l, r, floor(r - l + 1, 2) - 1).val;\n       \
    \ T median_ceil = quantile(l, r, ceil(r - l + 1, 2) - 1).val;\n\n        return\
    \ {median_floor, median_ceil};\n    }\n\n    // v[l, r)\u3067k\u756A\u76EE(0-indexed)\u306B\
    \u5C0F\u3055\u3044\u6570\u5024\u3068index(0-indexed)\u3092\u8FD4\u3059\n    //\
    \ \u5C0F\u3055\u3044\u9806\u306B\u4E26\u3079\u3066k\u756A\u76EE\u306E\u5024\n\
    \    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    S quantile(ull l, ull r, ull\
    \ k) {\n        assert(l < r and r <= N and k < r - l);\n\n        ull val = 0;\n\
    \        repd(h, bit_size) {\n            const ull zeros_l = bit_vectors[h].rank(0,\
    \ l);\n            const ull zeros_r = bit_vectors[h].rank(0, r);\n          \
    \  const ull zeros = zeros_r - zeros_l;    // l\u304B\u3089end\u307E\u3067\u306B\
    \u3042\u308B0\u306E\u6570\n            const ull bit = (k >= zeros);   // k\u756A\
    \u76EE\u306E\u5024\u306E\u4E0A\u304B\u3089i\u756A\u76EE\u306Ebit\u304C0\u304B\
    1\u304B\n\n            if (bit == 1) {\n                k -= zeros;\n        \
    \        l = bit_vectors[h].zeros + l - zeros_l;\n                r = bit_vectors[h].zeros\
    \ + r - zeros_r;\n            }\n            else {\n                l = zeros_l;\n\
    \                r = zeros_l + zeros;\n            }\n\n            val = (val\
    \ << 1) | bit;\n        }\n\n        return S(val, select(val, r - begin_indices[val]));\n\
    \    }\n\n    // v[0, pos)\u306Eval\u306E\u6570\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n\
    \    ull rank(T val, ull pos) {\n        assert(pos <= N);\n        if (pos ==\
    \ 0) return 0;\n        if (!begin_indices.contains(val)) return 0;\n\n      \
    \  repd(h, bit_size) {\n            ull bit = (val >> h) & 1;  // \u4E0A\u304B\
    \u3089i\u756A\u76EE\u306Ebit\n            pos = bit_vectors[h].rank(bit, pos);\
    \         // c\u306Ei\u756A\u76EE\u306Ebit\u3068\u540C\u3058\u6570\u5024\u306E\
    \u6570\n            if (bit == 1) pos += bit_vectors[h].zeros;\n        }\n\n\
    \        ull l = begin_indices[val];\n        return pos - l;\n    }\n\n    //\
    \ v[l, r)\u306Eval\u306E\u6570\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n\
    \    ull rank(T val, ull l, ull r) {\n        assert(l <= r and r <= N);\n   \
    \     if (l == r) return 0;\n        if (!begin_indices.contains(val)) return\
    \ 0;\n\n        return rank(val, r) - rank(val, l);\n    }\n\n    // v[0, pos)\u306E\
    val\u306E\u6570\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    ull count(ull\
    \ l, ull r, T val) {\n        return rank(val, l, r);\n    }\n\n    // v[l, r)\u3067\
    val\u3088\u308A\u5C0F\u3055\u3044\u5024\u306E\u6570\u3092\u8FD4\u3059\n    //\
    \ \u8A08\u7B97\u91CF: O(log(bit_size))\n    ull count_less_than(ull l, ull r,\
    \ T val) {\n        assert(l <= r and r <= N);\n\n        if (val <= min_val)\
    \ return 0;\n        if (val > max_val) return r - l;\n\n        ull ret = 0;\n\
    \        repd(h, bit_size) {\n            if (l >= r) break;\n            const\
    \ ull bit = (val >> h) & 1;\n\n            const ull rank0_l = bit_vectors[h].rank(0,\
    \ l);\n            const ull rank0_r = bit_vectors[h].rank(0, r);\n          \
    \  const ull rank1_l = l - rank0_l;\n            const ull rank1_r = r - rank0_r;\n\
    \n            if (bit == 1) {\n                ret += (rank0_r - rank0_l);   \
    \ // i\u756A\u76EE\u306Ebit\u304C0\u306E\u3082\u306E\u306F\u9664\u5916\u3055\u308C\
    \u308B\n                l = bit_vectors[h].zeros + rank1_l;\n                r\
    \ = bit_vectors[h].zeros + rank1_r;\n            } \n            else {\n    \
    \            l = rank0_l;\n                r = rank0_r;\n            }\n     \
    \   }\n\n        return ret;\n    }\n\n    // v[0, pos)\u3067val\u3088\u308A\u5C0F\
    \u3055\u3044\u5024\u306E\u6570\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n\
    \    ull count_less_than(ull pos, T val) {\n        assert(pos <= N);\n\n    \
    \    return count_less_than(0, pos, val);\n    }\n\n    // v[l, r)\u3067val\u3088\
    \u308A\u5927\u304D\u3044\u5024\u306E\u6570\u3092\u8FD4\u3059\n    // \u8A08\u7B97\
    \u91CF: O(log(bit_size))\n    ull count_more_than(ull l, ull r, T val) {\n   \
    \     assert(l <= r and r <= N);\n\n        if (val >= max_val) return 0;\n  \
    \      if (val < min_val) return r - l;\n\n        ull ret = 0;\n        repd(h,\
    \ bit_size) {\n            const ull bit = (val >> h) & 1;\n\n            const\
    \ ull rank0_l = bit_vectors[h].rank(0, l);\n            const ull rank0_r = bit_vectors[h].rank(0,\
    \ r);\n            const ull rank1_l = l - rank0_l;\n            const ull rank1_r\
    \ = r - rank0_r;\n\n            if (bit == 1) {\n                l = bit_vectors[h].zeros\
    \ + rank1_l;\n                r = bit_vectors[h].zeros + rank1_r;\n          \
    \  }\n            else {\n                ret += (rank1_r - rank1_l);    // i\u756A\
    \u76EE\u306Ebit\u304C1\u306E\u3082\u306E\u306F\u9664\u5916\u3055\u308C\u308B\n\
    \                l = rank0_l;\n                r = rank0_r;\n            } \n\
    \        }\n\n        return ret;\n    }\n\n    // v[0, pos)\u3067val\u3088\u308A\
    \u5927\u304D\u3044\u5024\u306E\u6570\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF\
    : O(log(bit_size))\n    ull count_more_than(ull pos, T val) {\n        assert(pos\
    \ <= N);\n        return count_more_than(0, pos, val);\n    }\n\n    // v[l, r)\u3067\
    [lower, upper)\u306B\u5165\u308B\u5024\u306E\u500B\u6570\u3092\u8FD4\u3059\n \
    \   ull count_in_range(ull l, ull r, T lower, T upper) {\n        assert(l <=\
    \ r and r <= N and lower <= upper);\n        if (l == r) return 0;\n        if\
    \ (lower == upper) return 0;\n\n        return count_less_than(l, r, upper) -\
    \ count_less_than(l, r, lower);\n    }\n\n    // v[l, r)\u3067\u983B\u5EA6\u304C\
    \u9AD8\u3044\u9806\u306Bk\u500B\u306E(\u5024\uFF0C\u983B\u5EA6)\u3092\u8FD4\u3059\
    \n    // \u8A08\u7B97\u91CF: O(min(r - l, k)log(bit_size) * {priority_queue\u306E\
    log})\n    // priority_queue\u306Elog\u304C\u91CD\u305D\u3046\n    vector<pair<T,\
    \ ull>> top_k(ull l, ull r, ull k) {\n        // (\u983B\u5EA6\uFF0C\u6DF1\u3055\
    \uFF0C\u5024)\u306E\u9806\u3067\u30BD\u30FC\u30C8\n        auto comp = [](const\
    \ tuple<ull, ull, ull, ull, T> &left, const tuple<ull, ull, ull, ull, T> &right)\
    \ {\n            // width\n            if (get<0>(left) != get<0>(right)) {\n\
    \                return get<0>(left) < get<0>(right);\n            }\n       \
    \     // depth\n            if (get<3>(left) != get<3>(right)) {\n           \
    \     return get<3>(left) > get<3>(right);\n            }\n            // value\n\
    \            if (get<4>(left) != get<4>(right)) {\n                return get<4>(left)\
    \ > get<4>(right);\n            }\n            return true;\n        };\n\n  \
    \      return top_k(l, r, k, comp);\n    }\n\n    // v[l, r)\u3067\u5024\u304C\
    \u5927\u304D\u3044\u9806\u306Bk\u500B\u306E(\u5024\uFF0C\u983B\u5EA6)\u3092\u8FD4\
    \u3059\n    // \u8A08\u7B97\u91CF: O(min(r - l, k)log(bit_size) * {priority_queue\u306E\
    log})\n    // priority_queue\u306Elog\u304C\u91CD\u305D\u3046\n    vector<pair<T,\
    \ ull>> max_k(ull l, ull r, ull k) {\n        // (\u5024\uFF0C\u983B\u5EA6)\u306E\
    \u9806\u3067\u30BD\u30FC\u30C8\n        auto comp = [](const tuple<ull, ull, ull,\
    \ ull, T> &left, const tuple<ull, ull, ull, ull, T> &right) {\n            //\
    \ value\n            if (get<4>(left) != get<4>(right)) {\n                return\
    \ get<4>(left) < get<4>(right);\n            }\n            // width\n       \
    \     if (get<0>(left) != get<0>(right)) {\n                return get<0>(left)\
    \ < get<0>(right);\n            }\n            // depth\n            if (get<3>(left)\
    \ != get<3>(right)) {\n                return get<3>(left) > get<3>(right);\n\
    \            }\n            return true;\n        };\n\n        return top_k(l,\
    \ r, k, comp);\n    }\n\n    // v[l, r)\u3067\u5024\u304C\u5C0F\u3055\u3044\u9806\
    \u306Bk\u500B\u306E(\u5024\uFF0C\u983B\u5EA6)\u3092\u8FD4\u3059\n    // \u8A08\
    \u7B97\u91CF: O(min(r - l, k)log(bit_size) * {priority_queue\u306Elog})\n    //\
    \ priority_queue\u306Elog\u304C\u91CD\u305D\u3046\n    vector<pair<T, ull>> min_k(ull\
    \ l, ull r, ull k) {\n        // (\u5024\uFF0C\u983B\u5EA6)\u306E\u9806\u3067\u30BD\
    \u30FC\u30C8\n        auto comp = [](const tuple<ull, ull, ull, ull, T> &left,\
    \ const tuple<ull, ull, ull, ull, T> &right) {\n            // value\n       \
    \     if (get<4>(left) != get<4>(right)) {\n                return get<4>(left)\
    \ > get<4>(right);\n            }\n            // width\n            if (get<0>(left)\
    \ != get<0>(right)) {\n                return get<0>(left) < get<0>(right);\n\
    \            }\n            // depth\n            if (get<3>(left) != get<3>(right))\
    \ {\n                return get<3>(left) > get<3>(right);\n            }\n   \
    \         return true;\n        };\n\n        return top_k(l, r, k, comp);\n \
    \   }\n\n    // T[l, r)\u3067\u51FA\u73FE\u56DE\u6570\u304C\u591A\u3044\u9806\u306B\
    k\u500B\u306E(\u5024\uFF0C\u983B\u5EA6)\u3092\u8FD4\u3059\n    // \u983B\u5EA6\
    \u304C\u540C\u3058\u5834\u5408\u306F\u5024\u304C\u5C0F\u3055\u3044\u3082\u306E\
    \u304C\u512A\u5148\u3055\u308C\u308B\n    // \u8A08\u7B97\u91CF: O(min(r - l,\
    \ k)log(bit_size) * {priority_queue\u306Elog})\n    // priority_queue\u306Elog\u304C\
    \u91CD\u305D\u3046\n    vector<pair<T, ull>> top_k(ull l, ull r, ull k, auto comp)\
    \ {\n        assert(l <= r and r <= N);\n        vector<pair<T, ull>> result;\n\
    \n        priority_queue<tuple<ull, ull, ull, ull, T>, vector<tuple<ull, ull,\
    \ ull, ull, T>>, decltype(comp)> que(comp);  // width, height, value, left, right\n\
    \        que.emplace(r - l, l, r, 0, 0);\n\n        while (!que.empty()) {\n \
    \           auto element = que.top(); que.pop();\n            ull width, left,\
    \ right, depth;\n            T value;\n            tie(width, left, right, depth,\
    \ value) = element;\n\n            if (depth >= bit_size) {\n                result.emplace_back(value,\
    \ right - left);\n                if (result.size() >= k) break;\n           \
    \     \n                continue;\n            }\n\n            ull height = bit_size\
    \ - depth - 1;\n\n            // 0\n            const ull left0 = bit_vectors[height].rank(0,\
    \ left);\n            const ull right0 = bit_vectors[height].rank(0, right);\n\
    \            if (left0 < right0) {\n                que.emplace(right0 - left0,\
    \ left0, right0, depth + 1, value);\n            }\n\n            // 1\n     \
    \       const ull left1 = bit_vectors[height].zeros + bit_vectors[height].rank(1,\
    \ left);\n            const ull right1 = bit_vectors[height].zeros + bit_vectors[height].rank(1,\
    \ right);\n            if (left1 < right1) {\n                que.emplace(right1\
    \ - left1, left1, right1, depth + 1, value | (1ull << height));\n            }\n\
    \        }\n\n        return result;\n    };\n\n    // T[l, r)\u3067\u51FA\u73FE\
    \u56DE\u6570\u304C\u591A\u3044\u9806\u306Bk\u500B\u306E(\u5024\uFF0C\u983B\u5EA6\
    )\u306E\u548C\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF: O(min(r - l, k)log(bit_size)\
    \ * {priority_queue\u306Elog})\n    // priority_queue\u306Elog\u304C\u91CD\u305D\
    \u3046\n    T sum_top_k(ull l, ull r, ull k) {\n        assert(l <= r and r <=\
    \ N);\n        assert(k <= r - l);\n\n        auto topk = top_k(l, r, k);\n  \
    \      T ret = 0;\n        for (auto [val, freq] : topk) {\n            ret +=\
    \ val * freq;\n        }\n        return ret;\n    }\n\n    // T[l, r)\u3067\u5024\
    \u304C\u6700\u5927\u306E\u3082\u306E\u304B\u3089k\u756A\u76EE\u306E\u5024\u306E\
    \u548C\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    T sum_max_k(ull\
    \ l, ull r, ull k) {\n        assert(l <= r and r <= N);\n        assert(k <=\
    \ r - l);\n\n        T kth_val = kth_max(l, r, k).val;\n        ull kth_val_count\
    \ = k - count_more_than(l, r, kth_val);\n        return sum_more_than(l, r, kth_val)\
    \ + kth_val * kth_val_count;\n    }\n\n    // T[l, r)\u3067\u5024\u304C\u6700\u5C0F\
    \u306E\u3082\u306E\u304B\u3089k\u756A\u76EE\u306E\u5024\u306E\u548C\u3092\u8FD4\
    \u3059\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    T sum_min_k(ull l, ull\
    \ r, ull k) {\n        assert(l <= r and r <= N);\n        assert(k <= r - l);\n\
    \n        T kth_val = kth_min(l, r, k).val;\n        ull kth_val_count = k - count_less_than(l,\
    \ r, kth_val);\n        return sum_less_than(l, r, kth_val) + kth_val * kth_val_count;\n\
    \    }\n\n    // T[l, r)\u3067[lower, upper)\u306B\u5165\u308B\u5024\u306E\u548C\
    \u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF: O(1)\n    T sum(ull l, ull r) {\n\
    \        return cumulative_sum[bit_size - 1][r] - cumulative_sum[bit_size - 1][l];\n\
    \    }\n\n    // T[l, r)\u3067val\u306E\u548C\u3092\u8FD4\u3059\n    // \u8A08\
    \u7B97\u91CF: O(log(bit_size))\n    T sum(ull l, ull r, T val) {\n        assert(l\
    \ <= r and r <= N);\n        if (!begin_indices.contains(val)) return 0;\n\n \
    \       return count(l, r, val) * val;\n    }\n\n    // T[l, r)\u3067val\u672A\
    \u6E80\u306E\u5024\u306E\u548C\u3092\u8FD4\u3059\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n\
    \    T sum_less_than(ull l, ull r, T val) {\n        assert(l <= r and r <= N);\n\
    \        if (val <= min_val) return 0;\n        if (val > max_val) return sum(l,\
    \ r);\n\n        return range_sum(l, r, 0, 0, min_val, val);\n    }\n\n    //\
    \ T[l, r)\u3067val\u3088\u308A\u5927\u304D\u3044\u5024\u306E\u548C\u3092\u8FD4\
    \u3059\n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    T sum_more_than(ull l,\
    \ ull r, T val) {\n        assert(l <= r and r <= N);\n        if (val >= max_val)\
    \ return 0;\n        if (val < min_val) return sum(l, r);\n\n        return range_sum(l,\
    \ r, 0, 0, val + 1, max_val + 1);\n    }\n\n    // T[l, r)\u3067lower <= val <\
    \ upper\u3092\u6E80\u305F\u3059val\u306E\u548C\u3092\u8FD4\u3059\n    // \u8A08\
    \u7B97\u91CF: O(log(bit_size))\n    T sum_in_range(ull l, ull r, T lower, T upper)\
    \ {\n        assert(l <= r and r <= N);\n        assert(lower <= upper);\n   \
    \     if (lower <= min_val and max_val < upper) return sum(l, r);\n\n        return\
    \ range_sum(l, r, 0, 0, lower, upper);\n    }\n\n    // T[l, r)\u3067lower <=\
    \ val < upper\u3092\u6E80\u305F\u3059\u6700\u5927\u306Eval\u3092\u8FD4\u3059\n\
    \    // \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306FNOTFOUND\u3092\u8FD4\u3059\
    \n    // \u8A08\u7B97\u91CF: O(log(bit_size))\n    T prev_value(ull l, ull r,\
    \ T lower, T upper) {\n        assert(l <= r and r <= N);\n\n        if (l ==\
    \ r) return NOTFOUND;\n        if (lower >= upper) return NOTFOUND;\n        if\
    \ (lower > max_val) return NOTFOUND;\n        if (upper <= min_val) return NOTFOUND;\n\
    \n        --upper; // lower <= val <= upper\u306B\u3059\u308B\n\n        if (upper\
    \ > max_val) upper = max_val;\n\n        stack<tuple<ull, ull, ull, T, bool>>\
    \ st;   // (l, r, depth, val, tight)\n        st.emplace(l, r, 0, 0, true);\n\n\
    \        while (!st.empty()) {\n            ull l, r, depth;\n            T val;\n\
    \            bool tight;\n            tie(l, r, depth, val, tight) = st.top();\
    \ st.pop();\n\n            if (depth == bit_size) {\n                if (val >=\
    \ lower) return val;\n                \n                continue;\n          \
    \  }\n\n            ull height = bit_size - depth - 1;\n\n            const ull\
    \ bit = (upper >> height) & 1;\n\n            const ull rank0_l = bit_vectors[height].rank(0,\
    \ l);\n            const ull rank0_r = bit_vectors[height].rank(0, r);\n     \
    \       const ull rank1_l = l - rank0_l;\n            const ull rank1_r = r -\
    \ rank0_r;\n\n            // d\u756A\u76EE\u306Ebit\u304C0\u306E\u3082\u306E\u3092\
    \u4F7F\u3046\n            const ull l0 = rank0_l;\n            const ull r0 =\
    \ rank0_r;\n            if (l0 != r0) { // \u7BC4\u56F2\u304C\u3064\u3076\u308C\
    \u3066\u306A\u3044\n                const T val0 = val << 1;\n               \
    \ st.emplace(l0, r0, depth + 1, val0, tight and bit == 0);\n            }\n\n\
    \            // d\u756A\u76EE\u306Ebit\u304C1\u306E\u3082\u306E\u3092\u4F7F\u3046\
    \n            const ull l1 = bit_vectors[height].zeros + rank1_l;\n          \
    \  const ull r1 = bit_vectors[height].zeros + rank1_r;\n            if (l1 !=\
    \ r1) {\n                if (!tight or bit == 1) {\n                    const\
    \ T val1 = ((val << 1) | 1);\n                    st.emplace(l1, r1, depth + 1,\
    \ val1, tight);\n                }\n            }\n        }\n\n        return\
    \ NOTFOUND;\n    }\n\n    // T[l, r)\u3067lower <= val < upper\u3092\u6E80\u305F\
    \u3059\u6700\u5C0F\u306Eval\u3092\u8FD4\u3059\n    T next_value(ull l, ull r,\
    \ ull lower, ull upper) {\n        assert(l <= r and r <= N);\n\n        if (l\
    \ == r) return NOTFOUND;\n        if (lower >= upper) return NOTFOUND;\n     \
    \   if (lower > max_val) return NOTFOUND;\n        if (upper <= min_val) return\
    \ NOTFOUND;\n\n        stack<tuple<ull, ull, ull, T, bool>> st;   // (l, r, depth,\
    \ val, tight)\n        st.emplace(l, r, 0, 0, true);\n\n        while (!st.empty())\
    \ {\n            ull l, r, depth;\n            T val;\n            bool tight;\n\
    \            tie(l, r, depth, val, tight) = st.top(); st.pop();\n\n          \
    \  if (depth == bit_size) {\n                if (val < upper) return val;\n\n\
    \                continue;\n            }\n\n            ull height = bit_size\
    \ - depth - 1;\n\n            const ull bit = (lower >> height) & 1;\n\n     \
    \       const ull rank0_l = bit_vectors[height].rank(0, l);\n            const\
    \ ull rank0_r = bit_vectors[height].rank(0, r);\n            const ull rank1_l\
    \ = l - rank0_l;\n            const ull rank1_r = r - rank0_r;\n\n           \
    \ // d\u756A\u76EE\u306Ebit\u304C1\u306E\u3082\u306E\u3092\u4F7F\u3046\n     \
    \       const ull l1 = bit_vectors[height].zeros + rank1_l;\n            const\
    \ ull r1 = bit_vectors[height].zeros + rank1_r;\n            if (l1 != r1) {\n\
    \                const T val1 = ((val << 1) | 1);\n                st.emplace(l1,\
    \ r1, depth + 1, val1, tight and bit == 1);\n            }\n\n            // d\u756A\
    \u76EE\u306Ebit\u304C0\u306E\u3082\u306E\u3092\u4F7F\u3046\n            const\
    \ ull l0 = rank0_l;\n            const ull r0 = rank0_r;\n            if (l0 !=\
    \ r0) {\n                if (!tight or bit == 0) {\n                    const\
    \ T val0 = val << 1;\n                    st.emplace(l0, r0, depth + 1, val0,\
    \ tight);\n                }\n            }\n        }\n\n        return NOTFOUND;\n\
    \    }\n\n    // T[l, r)\u3067val < upper\u3092\u6E80\u305F\u3059\u6700\u5927\u306E\
    val\u3092\u8FD4\u3059\n    T prev_value(ull l, ull r, T upper) {\n        return\
    \ prev_value(l, r, min_val, upper);\n    }\n\n    // T[l, r)\u3067lower <= val\u3092\
    \u6E80\u305F\u3059\u6700\u5C0F\u306Eval\u3092\u8FD4\u3059\n    T next_value(ull\
    \ l, ull r, T lower) {\n        return next_value(l, r, lower, max_val + 1);\n\
    \    }\n\n    // T[l1, r1)\u3068T[l2, r2)\u306B\u5171\u901A\u3057\u3066\u51FA\u73FE\
    \u3059\u308B\u8981\u7D20\u3092\u6C42\u3081\u308B\n    vector<tuple<ull, ull, ull>>\
    \ intersect(ull l1, ull r1, ull l2, ull r2) {\n        assert(l1 <= r1 and r1\
    \ <= N);\n        assert(l2 <= r2 and r2 <= N);\n\n        vector<tuple<ull, ull,\
    \ ull>> intersection;\n\n        queue<tuple<ull, ull, ull, ull, ull, ull>> que;\
    \ // l1, r1, l2, r2, height, value\n        que.emplace(l1, r1, l2, r2, bit_size\
    \ - 1, 0);\n        while (!que.empty()) {\n            auto element = que.front();\
    \ que.pop();\n            ull l1, r1, l2, r2, height, value;\n            tie(l1,\
    \ r1, l2, r2, height, value) = element;\n\n            if (height == 0) {\n  \
    \              intersection.emplace_back(value, r1 - l1, r2 - l2);\n         \
    \       continue;\n            }\n\n            // 0\n            ull l1_0 = bit_vectors[height].rank(0,\
    \ l1);\n            ull r1_0 = bit_vectors[height].rank(0, r1);\n            ull\
    \ l2_0 = bit_vectors[height].rank(0, l2);\n            ull r2_0 = bit_vectors[height].rank(0,\
    \ r2);\n\n            if (l1_0 != r1_0 and l2_0 != r2_0) {\n                que.emplace(l1_0,\
    \ r1_0, l2_0, r2_0, height - 1, value);\n            }\n\n            // 1\n \
    \           ull l1_1 = bit_vectors[height].zeros + bit_vectors[height].rank(1,\
    \ l1);\n            ull r1_1 = bit_vectors[height].zeros + bit_vectors[height].rank(1,\
    \ r1);\n            ull l2_1 = bit_vectors[height].zeros + bit_vectors[height].rank(1,\
    \ l2);\n            ull r2_1 = bit_vectors[height].zeros + bit_vectors[height].rank(1,\
    \ r2);\n\n            if (l1_1 != r1_1 and l2_1 != r2_1) {\n                que.emplace(l1_1,\
    \ r1_1, l2_1, r2_1, height - 1, value | (1ull << height));\n            }\n  \
    \      }\n\n        return intersection;\n    }\n\nprivate:\n    T range_sum(const\
    \ ull l, const ull r, const ull depth, const T val, const T lower, const T upper)\
    \ {\n        if (l == r) return 0;\n\n        if (depth == bit_size) {\n     \
    \       if (lower <= val and val < upper) {\n                return val * (r -\
    \ l);   // \u5024 * \u983B\u5EA6\n            }\n            return 0;\n     \
    \   }\n\n        const ull height = bit_size - depth - 1;\n\n        const T next_val\
    \ = (1ull << height) | val;                   // \u4E0A\u304B\u3089height\u756A\
    \u76EE\u306Ebit\u3092\u7ACB\u3066\u308B\n        const T all_one_val = ((1ull\
    \ << height) - 1) | next_val;     // height\u4EE5\u964D\u306Ebit\u3092\u305F\u3066\
    \u308B(\u3053\u308C\u4EE5\u964D\u5168\u90E81\u3092\u9078\u3093\u3060\u3068\u304D\
    \u306E\u5024)\n        if(all_one_val < lower or upper <= val) return 0;\n\n \
    \       // [l, pos)\u306E\u3059\u3079\u3066\u306E\u8981\u7D20\u306F[lower, upper)\n\
    \        if (lower <= val and all_one_val < upper) {\n            return cumulative_sum[height][r]\
    \ - cumulative_sum[height][l];\n        }\n\n        const ull rank0_l = bit_vectors[height].rank(0,\
    \ l);\n        const ull rank0_r = bit_vectors[height].rank(0, r);\n        const\
    \ ull rank1_l = l - rank0_l;\n        const ull rank1_r = r - rank0_r;\n\n   \
    \     return range_sum(rank0_l, rank0_r, depth + 1, val, lower, upper) +\n   \
    \            range_sum(bit_vectors[height].zeros + rank1_l, bit_vectors[height].zeros\
    \ + rank1_r, depth + 1, next_val, lower, upper);\n    }\n};\n#line 4 \"test/structure/wavelet-matrix/yukicoder-738.test.cpp\"\
    \n\nint main() {\n    ll N, K;\n    cin >> N >> K;\n\n    vll A(N);\n    rep(i,\
    \ N) cin >> A[i];\n\n    WaveletMatrix<ll> wm(A);\n\n    ll ans = inf64;\n   \
    \ rep(i, N - K + 1) {\n        auto [median_floor, median_ceil] = wm.median(i,\
    \ i + K);\n\n        {\n            ll a = median_floor;\n            ll count_upper\
    \ = wm.count_more_than(i, i + K, a);\n            ll sum_upper = wm.sum_more_than(i,\
    \ i + K, a);\n            ll cost_upper = sum_upper - count_upper * a;\n\n   \
    \         ll count_lower = wm.count_less_than(i, i + K, a);\n            ll sum_lower\
    \ = wm.sum_less_than(i, i + K, a);\n            ll cost_lower = count_lower *\
    \ a - sum_lower;\n\n            chmin(ans, cost_upper + cost_lower);\n       \
    \ }\n\n        if (median_ceil != median_floor) {\n            ll a = median_ceil;\n\
    \            ll count_upper = wm.count_more_than(i, i + K, a);\n            ll\
    \ sum_upper = wm.sum_more_than(i, i + K, a);\n            ll cost_upper = sum_upper\
    \ - count_upper * a;\n\n            ll count_lower = wm.count_less_than(i, i +\
    \ K, a);\n            ll sum_lower = wm.sum_less_than(i, i + K, a);\n        \
    \    ll cost_lower = count_lower * a - sum_lower;\n\n            chmin(ans, cost_upper\
    \ + cost_lower);\n        }\n    }\n\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/738\"\n\n#include \"../../../structure/wavelet-matrix.cpp\"\
    \n\nint main() {\n    ll N, K;\n    cin >> N >> K;\n\n    vll A(N);\n    rep(i,\
    \ N) cin >> A[i];\n\n    WaveletMatrix<ll> wm(A);\n\n    ll ans = inf64;\n   \
    \ rep(i, N - K + 1) {\n        auto [median_floor, median_ceil] = wm.median(i,\
    \ i + K);\n\n        {\n            ll a = median_floor;\n            ll count_upper\
    \ = wm.count_more_than(i, i + K, a);\n            ll sum_upper = wm.sum_more_than(i,\
    \ i + K, a);\n            ll cost_upper = sum_upper - count_upper * a;\n\n   \
    \         ll count_lower = wm.count_less_than(i, i + K, a);\n            ll sum_lower\
    \ = wm.sum_less_than(i, i + K, a);\n            ll cost_lower = count_lower *\
    \ a - sum_lower;\n\n            chmin(ans, cost_upper + cost_lower);\n       \
    \ }\n\n        if (median_ceil != median_floor) {\n            ll a = median_ceil;\n\
    \            ll count_upper = wm.count_more_than(i, i + K, a);\n            ll\
    \ sum_upper = wm.sum_more_than(i, i + K, a);\n            ll cost_upper = sum_upper\
    \ - count_upper * a;\n\n            ll count_lower = wm.count_less_than(i, i +\
    \ K, a);\n            ll sum_lower = wm.sum_less_than(i, i + K, a);\n        \
    \    ll cost_lower = count_lower * a - sum_lower;\n\n            chmin(ans, cost_upper\
    \ + cost_lower);\n        }\n    }\n\n    cout << ans << endl;\n}"
  dependsOn:
  - structure/wavelet-matrix.cpp
  - base.cpp
  isVerificationFile: true
  path: test/structure/wavelet-matrix/yukicoder-738.test.cpp
  requiredBy: []
  timestamp: '2024-08-18 02:50:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/wavelet-matrix/yukicoder-738.test.cpp
layout: document
redirect_from:
- /verify/test/structure/wavelet-matrix/yukicoder-738.test.cpp
- /verify/test/structure/wavelet-matrix/yukicoder-738.test.cpp.html
title: test/structure/wavelet-matrix/yukicoder-738.test.cpp
---