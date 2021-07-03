---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/dsu_adjacent_intervals.cpp\"\n#include <bits/stdc++.h>\n\
    \n/**\n * Call unite to join interval with right endpoint x and left endpoint\
    \ y\n * It is assumed that x + 1 = y\n * get_interval finds the interval element\
    \ x is in\n */\n\nstruct IntervalJoin {\n\tstd::vector<int> e;\n\tstd::vector<std::pair<int,\
    \ int>> interval;\n\n\tvoid init(int n) {\n\t\te = std::vector<int>(n, -1);\n\t\
    \tinterval.resize(n);\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tinterval[i].first\
    \ = interval[i].second = i;\n\t\t}\n\t}\n\n\tint get(int x) {\n\t\treturn e[x]\
    \ < 0 ? x : e[x] = get(e[x]);\n\t}\n\n\tbool same_set(int a, int b) {\n\t\treturn\
    \ get(a) == get(b);\n\t}\n\n\tint size(int x) {\n\t\treturn -e[get(x)];\n\t}\n\
    \n\tbool unite(int x, int y) {\n\t\tx = get(x), y = get(y);\n\t\tif (x == y) return\
    \ false;\n\t\tif (e[x] > e[y]) std::swap(x, y);\n\t\tinterval[x].first = std::min(interval[x].first,\
    \ interval[y].first);\n\t\tinterval[x].second = std::max(interval[x].second, interval[y].second);\n\
    \t\te[x] += e[y]; e[y] = x;\n\t\treturn true;\n\t}\n\t\n\tstd::pair<int, int>\
    \ get_interval(int x) {\n\t\tx = get(x);\n\t\treturn interval[x];\n\t}\n};\n\n\
    int main() {\n\treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * Call unite to join interval with right\
    \ endpoint x and left endpoint y\n * It is assumed that x + 1 = y\n * get_interval\
    \ finds the interval element x is in\n */\n\nstruct IntervalJoin {\n\tstd::vector<int>\
    \ e;\n\tstd::vector<std::pair<int, int>> interval;\n\n\tvoid init(int n) {\n\t\
    \te = std::vector<int>(n, -1);\n\t\tinterval.resize(n);\n\t\tfor (int i = 0; i\
    \ < n; i++) {\n\t\t\tinterval[i].first = interval[i].second = i;\n\t\t}\n\t}\n\
    \n\tint get(int x) {\n\t\treturn e[x] < 0 ? x : e[x] = get(e[x]);\n\t}\n\n\tbool\
    \ same_set(int a, int b) {\n\t\treturn get(a) == get(b);\n\t}\n\n\tint size(int\
    \ x) {\n\t\treturn -e[get(x)];\n\t}\n\n\tbool unite(int x, int y) {\n\t\tx = get(x),\
    \ y = get(y);\n\t\tif (x == y) return false;\n\t\tif (e[x] > e[y]) std::swap(x,\
    \ y);\n\t\tinterval[x].first = std::min(interval[x].first, interval[y].first);\n\
    \t\tinterval[x].second = std::max(interval[x].second, interval[y].second);\n\t\
    \te[x] += e[y]; e[y] = x;\n\t\treturn true;\n\t}\n\t\n\tstd::pair<int, int> get_interval(int\
    \ x) {\n\t\tx = get(x);\n\t\treturn interval[x];\n\t}\n};\n\nint main() {\n\t\
    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dsu_adjacent_intervals.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:36:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/dsu_adjacent_intervals.cpp
layout: document
redirect_from:
- /library/library/graphs/dsu_adjacent_intervals.cpp
- /library/library/graphs/dsu_adjacent_intervals.cpp.html
title: library/graphs/dsu_adjacent_intervals.cpp
---