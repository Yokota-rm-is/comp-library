---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: base.cpp
    title: base.cpp
  - icon: ':x:'
    path: search/maximize.cpp
    title: search/maximize.cpp
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
    - https://yukicoder.me/problems/no/306
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ search/maximize.cpp: line 3: #pragma once found in a non-first line\n"
  code: "#define IGNORE\n#define PROBLEM \"https://yukicoder.me/problems/no/306\"\n\
    \n#include \"../../../search/maximize.cpp\"\n\nint main() {\n    double xa, ya,\
    \ xb, yb;\n    cin >> xa >> ya >> xb >> yb;\n\n    long double xa2 = xa * xa;\n\
    \    long double xb2 = xb * xb;\n\n    auto f = [&](double y) {\n        return\
    \ -sqrt(xa2 + (ya - y) * (ya - y)) + sqrt(xb2 + (yb - y) * (yb - y));\n    };\n\
    \n    double y = maximize(f, 0., 1000.);\n    cout << fixed << setprecision(10);\n\
    \    cout << y << endl;\n\n    return 0;\n} \n"
  dependsOn:
  - search/maximize.cpp
  - base.cpp
  isVerificationFile: true
  path: test/search/maximize/yukicoder-306.test.cpp
  requiredBy: []
  timestamp: '2025-03-23 19:21:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/search/maximize/yukicoder-306.test.cpp
layout: document
redirect_from:
- /verify/test/search/maximize/yukicoder-306.test.cpp
- /verify/test/search/maximize/yukicoder-306.test.cpp.html
title: test/search/maximize/yukicoder-306.test.cpp
---
