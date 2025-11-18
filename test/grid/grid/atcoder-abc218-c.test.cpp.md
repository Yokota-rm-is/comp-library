---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../grid/grid.cpp:\
    \ line -1: no such header\n"
  code: "#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/abc218/tasks/abc218_c\"\
    \n\n#include \"../../../grid/grid.cpp\"\n\nint main() {\n    ll N;\n    cin >>\
    \ N;\n\n    vector<string> S(N), T(N);\n    rep(i, N) cin >> S[i];\n    rep(i,\
    \ N) cin >> T[i];\n\n    Grid<char> gridS(S), gridT(T);\n    rep(r, 4) {\n   \
    \     rep(i, N) {\n            rep(j, N) {\n                debug(gridS);\n  \
    \              if (gridS == gridT) {\n                    cout << \"Yes\" << endl;\n\
    \                    return 0;\n                }\n                gridS.translate({0,\
    \ 1});\n            }\n            gridS.translate({1, 0});\n        }\n     \
    \   gridS.rotate_90_clockwise();\n    } \n\n    cout << \"No\" << endl;\n\n  \
    \  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/grid/grid/atcoder-abc218-c.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/grid/grid/atcoder-abc218-c.test.cpp
layout: document
redirect_from:
- /verify/test/grid/grid/atcoder-abc218-c.test.cpp
- /verify/test/grid/grid/atcoder-abc218-c.test.cpp.html
title: test/grid/grid/atcoder-abc218-c.test.cpp
---
