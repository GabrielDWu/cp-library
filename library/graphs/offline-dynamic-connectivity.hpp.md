---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graphs/dsu-rollback.hpp
    title: library/graphs/dsu-rollback.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/spoj/spoj-DYNACON2.test.cpp
    title: verify/spoj/spoj-DYNACON2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\n\nstruct DSURollBack {\n\tstd::vector<int> e;\n\t\n\tvoid init(int\
    \ n) {\n\t\te = std::vector<int>(n, -1);\n\t}\n\n\tint get(int x) {\n\t\treturn\
    \ e[x] < 0 ? x : get(e[x]);\n\t}\n\n\tbool same_set(int a, int b) {\n\t\treturn\
    \ get(a) == get(b);\n\t}\n\n\tint size(int x) {\n\t\treturn -e[get(x)];\n\t}\n\
    \n\tstd::vector<std::array<int, 4>> mod;\n\t\n\tbool unite(int x, int y) {\n\t\
    \tx = get(x), y = get(y);\n\t\tif (x == y) {\n\t\t\tmod.push_back({-1, -1, -1,\
    \ -1});\n\t\t\treturn 0;\n\t\t}\n\t\tif (e[x] > e[y]) std::swap(x, y);\n\t\tmod.push_back({x,\
    \ y, e[x], e[y]});\n\t\te[x] += e[y], e[y] = x;\n\t\treturn true;\n\t}\n\n\tvoid\
    \ rollback() {\n\t\tauto a = mod.back();\n\t\tmod.pop_back();\n\t\tif (a[0] !=\
    \ -1) {\n\t\t\te[a[0]] = a[2];\n\t\t\te[a[1]] = a[3];\n\t\t}\n\t}\n};\n\nstruct\
    \ OfflineDynamicConnectivity {\n\tDSURollBack dsu;\n\tint sz;\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> seg;\n\tstd::vector<std::vector<std::pair<int, int>>> queries;\n\tstd::vector<int>\
    \ ans;\n\n\tvoid upd(int l, int r, std::pair<int, int> p) {\n\t\t// add edge p\
    \ from time [l, r]\n\t\tfor (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {\n\t\
    \t\tif (l & 1) seg[l++].push_back(p);\n\t\t\tif (r & 1) seg[--r].push_back(p);\n\
    \t\t}\n\t}\n\n\tvoid process(int ind) {\n\t\tfor (auto &t : seg[ind]) {\n\t\t\t\
    dsu.unite(t.first, t.second);\n\t\t}\n\t\tif (ind >= sz) {\n\t\t\t// Process the\
    \ queries at time ti\n\t\t\t// Do stuff with D\n\t\t\tint ti = ind - sz; \n\t\t\
    \tfor (auto &qq : queries[ti]) {\n\t\t\t\tans.push_back(dsu.same_set(qq.first,\
    \ qq.second));\n\t\t\t}\n\t\t} else {\n\t\t\tprocess(2 * ind); process(2 * ind\
    \ + 1);\n\t\t}\n\t\tfor (auto &t : seg[ind]) {\n\t\t\tdsu.rollback();\n\t\t}\n\
    \t}\n\n\tvoid init(int n, int max_time) {\n\t\tsz = 1;\n\t\twhile (sz < max_time)\
    \ sz *= 2;\n\t\tseg.assign(2 * sz, {});\n\t\tqueries.assign(sz, {});\n\t\tdsu.init(n);\n\
    \t}\n\n\tvoid add_query(int ti, int u, int v) {\n\t\tqueries[ti].emplace_back(u,\
    \ v);\n\t}\n\t\n\tstd::vector<int> solve() {\n\t\tprocess(1);\n\t\treturn ans;\n\
    \t}\n};\n"
  code: "#pragma once\n\n#include \"dsu-rollback.hpp\"\n\nstruct OfflineDynamicConnectivity\
    \ {\n\tDSURollBack dsu;\n\tint sz;\n\tstd::vector<std::vector<std::pair<int, int>>>\
    \ seg;\n\tstd::vector<std::vector<std::pair<int, int>>> queries;\n\tstd::vector<int>\
    \ ans;\n\n\tvoid upd(int l, int r, std::pair<int, int> p) {\n\t\t// add edge p\
    \ from time [l, r]\n\t\tfor (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {\n\t\
    \t\tif (l & 1) seg[l++].push_back(p);\n\t\t\tif (r & 1) seg[--r].push_back(p);\n\
    \t\t}\n\t}\n\n\tvoid process(int ind) {\n\t\tfor (auto &t : seg[ind]) {\n\t\t\t\
    dsu.unite(t.first, t.second);\n\t\t}\n\t\tif (ind >= sz) {\n\t\t\t// Process the\
    \ queries at time ti\n\t\t\t// Do stuff with D\n\t\t\tint ti = ind - sz; \n\t\t\
    \tfor (auto &qq : queries[ti]) {\n\t\t\t\tans.push_back(dsu.same_set(qq.first,\
    \ qq.second));\n\t\t\t}\n\t\t} else {\n\t\t\tprocess(2 * ind); process(2 * ind\
    \ + 1);\n\t\t}\n\t\tfor (auto &t : seg[ind]) {\n\t\t\tdsu.rollback();\n\t\t}\n\
    \t}\n\n\tvoid init(int n, int max_time) {\n\t\tsz = 1;\n\t\twhile (sz < max_time)\
    \ sz *= 2;\n\t\tseg.assign(2 * sz, {});\n\t\tqueries.assign(sz, {});\n\t\tdsu.init(n);\n\
    \t}\n\n\tvoid add_query(int ti, int u, int v) {\n\t\tqueries[ti].emplace_back(u,\
    \ v);\n\t}\n\t\n\tstd::vector<int> solve() {\n\t\tprocess(1);\n\t\treturn ans;\n\
    \t}\n};"
  dependsOn:
  - library/graphs/dsu-rollback.hpp
  isVerificationFile: false
  path: library/graphs/offline-dynamic-connectivity.hpp
  requiredBy: []
  timestamp: '2021-07-28 18:32:54-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/spoj/spoj-DYNACON2.test.cpp
documentation_of: library/graphs/offline-dynamic-connectivity.hpp
layout: document
redirect_from:
- /library/library/graphs/offline-dynamic-connectivity.hpp
- /library/library/graphs/offline-dynamic-connectivity.hpp.html
title: library/graphs/offline-dynamic-connectivity.hpp
---