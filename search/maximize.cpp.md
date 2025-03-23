---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: base.cpp
    title: base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/search/maximize/yukicoder-198.test.cpp
    title: test/search/maximize/yukicoder-198.test.cpp
  - icon: ':x:'
    path: test/search/maximize/yukicoder-306.test.cpp
    title: test/search/maximize/yukicoder-306.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ search/maximize.cpp: line 3: #pragma once found in a non-first line\n"
  code: "\n\n#pragma once\n#include \"../base.cpp\"\n\n// main\u306Bf\u3092\u304A\u304F\
    \n// auto f = [&](auto x){return A[x];};\n\n// \u4E09\u5206\u63A2\u7D22\u306B\u3088\
    \u308B\u6700\u5927\u5316\n// \u7BC4\u56F2: [left, right]\n// \u8A08\u7B97\u91CF\
    : O(log(right - left))\nlong long maximize(auto f, long long left, long long right)\
    \ {\n    while (right - left > 2ll) {\n        long long m_left = (left * 2 +\
    \ right) / 3;\n        long long m_right = (left + right * 2) / 3;\n\n       \
    \ if (f(m_left) < f(m_right)) {\n            left = m_left;\n        } \n    \
    \    else {\n            right = m_right;\n        }\n    }\n\n    long long ret\
    \ = (f(left) > f(right)) ? left : right;\n    return (f(midpoint(left, right))\
    \ > f(ret)) ? midpoint(left, right) : ret;\n}\n\ndouble maximize(auto f, double\
    \ left, double right) {\n    rep(i, 165) {\n        double m_left = (left * 2\
    \ + right) / 3;\n        double m_right = (left + right * 2) / 3;\n\n        if\
    \ (f(m_left) < f(m_right)) {\n            left = m_left;\n        } \n       \
    \ else {\n            right = m_right;\n        }\n    }\n\n    double ret = (f(left)\
    \ > f(right)) ? left : right;\n    return (f(midpoint(left, right)) > f(ret))\
    \ ? midpoint(left, right) : ret;\n}\n\nlong double maximize(auto f, long double\
    \ left, long double right) {\n    rep(i, 165) {\n        long double m_left =\
    \ (left * 2 + right) / 3;\n        long double m_right = (left + right * 2) /\
    \ 3;\n\n        if (f(m_left) < f(m_right)) {\n            left = m_left;\n  \
    \      } \n        else {\n            right = m_right;\n        }\n    }\n\n\
    \    long double ret = (f(left) > f(right)) ? left : right;\n    return (f(midpoint(left,\
    \ right)) > f(ret)) ? midpoint(left, right) : ret;\n}"
  dependsOn:
  - base.cpp
  isVerificationFile: false
  path: search/maximize.cpp
  requiredBy: []
  timestamp: '2025-03-23 19:21:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/search/maximize/yukicoder-306.test.cpp
  - test/search/maximize/yukicoder-198.test.cpp
documentation_of: search/maximize.cpp
layout: document
redirect_from:
- /library/search/maximize.cpp
- /library/search/maximize.cpp.html
title: search/maximize.cpp
---
