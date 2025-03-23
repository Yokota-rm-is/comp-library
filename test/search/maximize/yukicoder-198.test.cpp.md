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
    PROBLEM: https://yukicoder.me/problems/no/198
    links:
    - https://yukicoder.me/problems/no/198
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
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/198\"\n\n#include \"../../../search/maximize.cpp\"\
    \n\nint main() {\n    ll B, N;\n    cin >> B >> N;\n\n    vll C(N);\n    rep(i,\
    \ N) cin >> C[i];\n\n    auto f = [&](ll x) {\n        ll ret = 0;\n        rep(i,\
    \ N) {\n            ret += abs(C[i] - x);\n        }\n        return -ret;\n \
    \   };\n\n    ll right = (accumulate(C) + B) / N;\n\n    ll x = maximize(f, 0ll,\
    \ right);\n\n    cout << -f(x) << endl;\n\n    return 0;\n} \n"
  dependsOn:
  - search/maximize.cpp
  - base.cpp
  isVerificationFile: true
  path: test/search/maximize/yukicoder-198.test.cpp
  requiredBy: []
  timestamp: '2025-03-23 19:21:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/search/maximize/yukicoder-198.test.cpp
layout: document
redirect_from:
- /verify/test/search/maximize/yukicoder-198.test.cpp
- /verify/test/search/maximize/yukicoder-198.test.cpp.html
title: test/search/maximize/yukicoder-198.test.cpp
---
