---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/graphs/flows/hungarian.hpp
    title: library/graphs/flows/hungarian.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163
  bundledCode: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n/**\n * Another black box algorithm I don't understand\n * But I can use \n\
    \ * O(N^2M) for N jobs and M workers \n * 0-indexed\n * Returns the cost, and\
    \ the assignment\n * job stores the job each worker gets assigned to\n * In the\
    \ example below, they wanted the worker each job got assigned to, so I inverted\
    \ it\n */\n\ntemplate <class C> std::pair<C, std::vector<int>> hungarian(const\
    \ std::vector<std::vector<C>>& a_) {\n\tconst C INF = std::numeric_limits<C>::max();\n\
    \tint n = (int)a_.size();\n\tint m = (int)a_[0].size();\n\tassert(n <= m);\n\t\
    std::vector<std::vector<C>> a(n + 1, std::vector<C>(m + 1, 0));\n\tfor (int i\
    \ = 0; i < n; i++)\n\t\tfor (int j = 0; j < m; j++)\n\t\t\ta[i + 1][j + 1] = a_[i][j];\n\
    \tstd::vector<C> u(n + 1), v(m + 1);\n\tstd::vector<int> job(m + 1);\n\tfor (int\
    \ i = 1; i <= n; i++) {\n\t\tint w = 0;\n\t\tjob[w] = i;\n\t\tstd::vector<C> dist(m\
    \ + 1, INF);\n\t\tstd::vector<int> pre(m + 1, -1);\n\t\tstd::vector<bool> done(m\
    \ + 1);\n\t\twhile (job[w]) {\n\t\t\tdone[w] = 1;\n\t\t\tint j = job[w], nxt;\n\
    \t\t\tC delta = INF;\n\t\t\tfor (int ww = 0; ww <= m; ww++) {\n\t\t\t\tif (!done[ww])\
    \ {\n\t\t\t\t\tif (dist[ww] > a[j][ww] - u[j] - v[ww]) {\n\t\t\t\t\t\tdist[ww]\
    \ = a[j][ww] - u[j] - v[ww];\n\t\t\t\t\t\tpre[ww] = w; \n\t\t\t\t\t}\n\t\t\t\t\
    \tif (delta > dist[ww]) {\n\t\t\t\t\t\tdelta = dist[ww];\n\t\t\t\t\t\tnxt = ww;\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tfor (int ww = 0; ww <= m; ww++) {\n\t\t\
    \t\tif (done[ww]) {\n\t\t\t\t\tu[job[ww]] += delta;\n\t\t\t\t\tv[ww] -= delta;\n\
    \t\t\t\t} else {\n\t\t\t\t\tdist[ww] -= delta;\n\t\t\t\t}\n\t\t\t}\n\t\t\tw =\
    \ nxt;\n\t\t}\n\t\tfor (int ww; w; w = ww) \n\t\t\tjob[w] = job[ww = pre[w]];\n\
    \t}\n\tjob.erase(job.begin());\n\tfor (int i = 0; i < m; i++)\n\t\tjob[i]--;\n\
    \treturn {-v[0], job};\n}\n\nint main() {\n\tios::sync_with_stdio(false);\n\t\
    cin.tie(nullptr);\n\tint m, n;\n\twhile (cin >> m >> n, m) {\n\t\tvector<int>\
    \ b(m);\n\t\tfor (int i = 0; i < m; ++i) {\n\t\t\tcin >> b[i];\n\t\t}\n\t\tvector<int>\
    \ r(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tcin >> r[i];\n\t\t}\n\t\tif\
    \ (m > n) {\n\t\t\tswap(m, n);\n\t\t\tswap(b, r);\n\t\t}\n\t\tvector<vector<int>>\
    \ v(m, vector<int>(n));\n\t\tfor (int i = 0; i < m; ++i) {\n\t\t\tfor (int j =\
    \ 0; j < n; ++j) {\n\t\t\t\tif (gcd(b[i], r[j]) > 1) {\n\t\t\t\t\tv[i][j] = -1;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tcout << -hungarian(v).first << '\\n';\n\t}\n}\n\
    \n// another instance of use below\n\n// int main() {\n// \tusing namespace std;\n\
    // \tint n; cin >> n;\n// \tvector<vector<long long>> a(n, vector<long long>(n));\n\
    // \tfor (int i = 0; i < n; i++)\n// \t\tfor (int j = 0; j < n; j++) cin >> a[i][j];\n\
    // \tauto res = hungarian(a);\n// \tvector<int> loc(n);\n// \tfor (int i = 0;\
    \ i < n; i++) {\n// \t\tloc[res.second[i]] = i;\n// \t}\n// \tcout << res.first\
    \ << '\\n';\n// \tfor (int x : loc) \n// \t\tcout << x << \" \";\n// \tcout <<\
    \ '\\n';\n// \treturn 0;\n// }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163\"\
    \n\n#include \"../library/contest/template-minimal.hpp\"\n#include \"../library/graphs/flows/hungarian.hpp\"\
    \n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint m,\
    \ n;\n\twhile (cin >> m >> n, m) {\n\t\tvector<int> b(m);\n\t\tfor (int i = 0;\
    \ i < m; ++i) {\n\t\t\tcin >> b[i];\n\t\t}\n\t\tvector<int> r(n);\n\t\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\t\tcin >> r[i];\n\t\t}\n\t\tif (m > n) {\n\t\t\tswap(m,\
    \ n);\n\t\t\tswap(b, r);\n\t\t}\n\t\tvector<vector<int>> v(m, vector<int>(n));\n\
    \t\tfor (int i = 0; i < m; ++i) {\n\t\t\tfor (int j = 0; j < n; ++j) {\n\t\t\t\
    \tif (gcd(b[i], r[j]) > 1) {\n\t\t\t\t\tv[i][j] = -1;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t\tcout << -hungarian(v).first << '\\n';\n\t}\n}\n\n// another instance of\
    \ use below\n\n// int main() {\n// \tusing namespace std;\n// \tint n; cin >>\
    \ n;\n// \tvector<vector<long long>> a(n, vector<long long>(n));\n// \tfor (int\
    \ i = 0; i < n; i++)\n// \t\tfor (int j = 0; j < n; j++) cin >> a[i][j];\n// \t\
    auto res = hungarian(a);\n// \tvector<int> loc(n);\n// \tfor (int i = 0; i < n;\
    \ i++) {\n// \t\tloc[res.second[i]] = i;\n// \t}\n// \tcout << res.first << '\\\
    n';\n// \tfor (int x : loc) \n// \t\tcout << x << \" \";\n// \tcout << '\\n';\n\
    // \treturn 0;\n// }"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/graphs/flows/hungarian.hpp
  isVerificationFile: true
  path: test/hungarian.test.cpp
  requiredBy: []
  timestamp: '2021-07-25 00:42:29-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/hungarian.test.cpp
layout: document
redirect_from:
- /verify/test/hungarian.test.cpp
- /verify/test/hungarian.test.cpp.html
title: test/hungarian.test.cpp
---