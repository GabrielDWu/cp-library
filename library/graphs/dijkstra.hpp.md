---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/aizu-GRL_1_A.test.cpp
    title: verify/aizu/aizu-GRL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\ntemplate <class C, bool directed> struct Dijkstra {\n\tint SZ; std::vector<C>\
    \ dist;\n\tstd::vector<std::vector<std::pair<int, C>>> adj;\n\n\tvoid init(int\
    \ _SZ) {\n\t\tSZ = _SZ;\n\t\tadj.clear();\n\t\tadj.resize(SZ);\n\t}\n\n\tvoid\
    \ ae(int u, int v, C cost) {\n\t\tadj[u].emplace_back(v, cost);\n\t\tif (!directed)\
    \ adj[v].emplace_back(u, cost);\n\t}\n\n\tvoid gen(int st) {\n\t\tdist = std::vector<C>(SZ,\
    \ std::numeric_limits<C>::max());\n\t\ttypedef std::pair<C, int> T;\n\t\tstd::priority_queue<T,\
    \ std::vector<T>, std::greater<T>> pq;\n\t\tauto ad = [&](int a, C b) {\n\t\t\t\
    if (dist[a] <= b) return;\n\t\t\tpq.push({dist[a] = b, a});\n\t\t};\n\t\tad(st,\
    \ 0);\n\t\twhile (!pq.empty()) {\n\t\t\tauto x = pq.top();\n\t\t\tpq.pop();\n\t\
    \t\tif (dist[x.second] < x.first) continue;\n\t\t\tfor (auto &y: adj[x.second])\
    \ {\n\t\t\t\tad(y.first, x.first + y.second);\n\t\t\t}\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <class C, bool directed> struct Dijkstra {\n\tint\
    \ SZ; std::vector<C> dist;\n\tstd::vector<std::vector<std::pair<int, C>>> adj;\n\
    \n\tvoid init(int _SZ) {\n\t\tSZ = _SZ;\n\t\tadj.clear();\n\t\tadj.resize(SZ);\n\
    \t}\n\n\tvoid ae(int u, int v, C cost) {\n\t\tadj[u].emplace_back(v, cost);\n\t\
    \tif (!directed) adj[v].emplace_back(u, cost);\n\t}\n\n\tvoid gen(int st) {\n\t\
    \tdist = std::vector<C>(SZ, std::numeric_limits<C>::max());\n\t\ttypedef std::pair<C,\
    \ int> T;\n\t\tstd::priority_queue<T, std::vector<T>, std::greater<T>> pq;\n\t\
    \tauto ad = [&](int a, C b) {\n\t\t\tif (dist[a] <= b) return;\n\t\t\tpq.push({dist[a]\
    \ = b, a});\n\t\t};\n\t\tad(st, 0);\n\t\twhile (!pq.empty()) {\n\t\t\tauto x =\
    \ pq.top();\n\t\t\tpq.pop();\n\t\t\tif (dist[x.second] < x.first) continue;\n\t\
    \t\tfor (auto &y: adj[x.second]) {\n\t\t\t\tad(y.first, x.first + y.second);\n\
    \t\t\t}\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/aizu-GRL_1_A.test.cpp
documentation_of: library/graphs/dijkstra.hpp
layout: document
redirect_from:
- /library/library/graphs/dijkstra.hpp
- /library/library/graphs/dijkstra.hpp.html
title: library/graphs/dijkstra.hpp
---