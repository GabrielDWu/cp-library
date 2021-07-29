---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-template-short.test.cpp
    title: verify/unit-test/unit-test-template-short.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define f1r(i,\
    \ a, b) for (int i = (a); i < (b); ++i)\n#define f0r(i, a) f1r(i, 0, a)\n#define\
    \ each(t, a) for (auto &t : a)\n\n#define mp make_pair\n#define f first\n#define\
    \ s second\n#define pb push_back\n#define eb emplace_back\n#define sz(x) (int)(x).size()\n\
    #define all(x) begin(x), end(x)\n\ntypedef long long ll;\ntypedef vector<int>\
    \ vi;\ntypedef vector<ll> vl;\ntypedef pair<int, int> pi;\ntypedef pair<ll, ll>\
    \ pl;\ntypedef vector<pi> vpi;\ntypedef vector<pl> vpl;\n\ntemplate <class T>\
    \ bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }\ntemplate <class\
    \ T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }\n\nint main()\
    \ {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define f1r(i, a, b)\
    \ for (int i = (a); i < (b); ++i)\n#define f0r(i, a) f1r(i, 0, a)\n#define each(t,\
    \ a) for (auto &t : a)\n\n#define mp make_pair\n#define f first\n#define s second\n\
    #define pb push_back\n#define eb emplace_back\n#define sz(x) (int)(x).size()\n\
    #define all(x) begin(x), end(x)\n\ntypedef long long ll;\ntypedef vector<int>\
    \ vi;\ntypedef vector<ll> vl;\ntypedef pair<int, int> pi;\ntypedef pair<ll, ll>\
    \ pl;\ntypedef vector<pi> vpi;\ntypedef vector<pl> vpl;\n\ntemplate <class T>\
    \ bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }\ntemplate <class\
    \ T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }\n\nint main()\
    \ {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/contest/template-short.cpp
  requiredBy: []
  timestamp: '2021-07-24 19:43:32-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit-test/unit-test-template-short.test.cpp
documentation_of: library/contest/template-short.cpp
layout: document
redirect_from:
- /library/library/contest/template-short.cpp
- /library/library/contest/template-short.cpp.html
title: library/contest/template-short.cpp
---