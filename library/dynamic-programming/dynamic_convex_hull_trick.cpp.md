---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/dynamic-programming/dynamic_convex_hull_trick.cpp\"\
    \n#include<bits/stdc++.h>\n\nconst long long INF = 1e18;\n\nstruct ConvexHullTrick\
    \ {\n\t// modified for minimums\n\tstruct line {\n\t\tlong long m, b; long double\
    \ x, val;\n\t\tbool is_query;\n\n\t\tline(long long _m = 0, long long _b = 0)\
    \ {\n\t\t\tm = _m, b = _b, val = 0, x = -INF, is_query = false;\n\t\t}\n\n\t\t\
    long long eval(long long x) const { return m * x + b; }\n\t\tbool parallel(const\
    \ line &l) const { return m == l.m; }\n\t\tlong double intersect(const line &l)\
    \ const {\n\t\t\treturn parallel(l) ? INF : 1.0 * (l.b - b) / (m - l.m);\n\t\t\
    }\n\n\t\tbool operator<(const line &l) const {\n\t\t\tif (l.is_query) return x\
    \ < l.val;\n\t\t\telse return m < l.m;\n\t\t}\n\t};\n\n\tstd::set<line> hull;\n\
    \n\tbool hull_prev(std::set<line>::iterator it) { return it != hull.begin(); }\n\
    \tbool hull_next(std::set<line>::iterator it) { return it != hull.end() && next(it)\
    \ != hull.end(); }\n\tbool bad(const line &l1, const line &l2, const line &l3)\
    \ { return l1.intersect(l3) <= l1.intersect(l2); }\n\tbool bad(std::set<line>::iterator\
    \ it) { return hull_prev(it) && hull_next(it) && bad(*prev(it), *it, *next(it));\
    \ }\n\n\tstd::set<line>::iterator update(std::set<line>::iterator it) {\n\t\t\
    if (!hull_prev(it)) return it;\n\t\tlong double x = it->intersect(*prev(it));\n\
    \t\tline tmp(*it); tmp.x = x;\n\t\tit = hull.erase(it);\n\t\treturn hull.insert(it,\
    \ tmp);\n\t}\n\n\tvoid add_line(long long m, long long b) {\n\t\tm = -m, b = -b;\n\
    \t\tline l(m, b);\n\t\tstd::set<line>::iterator it = hull.lower_bound(l);\n\t\t\
    if (it != hull.end() && l.parallel(*it)) {\n\t\t\tif(it->b < b) it = hull.erase(it);\n\
    \t\t\telse return;\n\t\t}\n\t\tit = hull.insert(it, l);\n\t\tif (bad(it)) return\
    \ (void) hull.erase(it);\n\t\twhile (hull_prev(it) && bad(prev(it))) hull.erase(prev(it));\n\
    \t\twhile (hull_next(it) && bad(next(it))) hull.erase(next(it));\n\t\tit = update(it);\n\
    \t\tif (hull_prev(it)) update(prev(it));\n\t\tif (hull_next(it)) update(next(it));\n\
    \t}\n\t\n\tlong long query(long long x) const {\n\t\tif (hull.empty()) return\
    \ INF;\n\t\tline q; q.val = x, q.is_query = 1;\n\t\tstd::set<line>::iterator it\
    \ = --hull.lower_bound(q);\n\t\treturn -(it->eval(x));\n\t}\n};\n\nint main()\
    \ {\n\treturn 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\nconst long long INF = 1e18;\n\nstruct ConvexHullTrick\
    \ {\n\t// modified for minimums\n\tstruct line {\n\t\tlong long m, b; long double\
    \ x, val;\n\t\tbool is_query;\n\n\t\tline(long long _m = 0, long long _b = 0)\
    \ {\n\t\t\tm = _m, b = _b, val = 0, x = -INF, is_query = false;\n\t\t}\n\n\t\t\
    long long eval(long long x) const { return m * x + b; }\n\t\tbool parallel(const\
    \ line &l) const { return m == l.m; }\n\t\tlong double intersect(const line &l)\
    \ const {\n\t\t\treturn parallel(l) ? INF : 1.0 * (l.b - b) / (m - l.m);\n\t\t\
    }\n\n\t\tbool operator<(const line &l) const {\n\t\t\tif (l.is_query) return x\
    \ < l.val;\n\t\t\telse return m < l.m;\n\t\t}\n\t};\n\n\tstd::set<line> hull;\n\
    \n\tbool hull_prev(std::set<line>::iterator it) { return it != hull.begin(); }\n\
    \tbool hull_next(std::set<line>::iterator it) { return it != hull.end() && next(it)\
    \ != hull.end(); }\n\tbool bad(const line &l1, const line &l2, const line &l3)\
    \ { return l1.intersect(l3) <= l1.intersect(l2); }\n\tbool bad(std::set<line>::iterator\
    \ it) { return hull_prev(it) && hull_next(it) && bad(*prev(it), *it, *next(it));\
    \ }\n\n\tstd::set<line>::iterator update(std::set<line>::iterator it) {\n\t\t\
    if (!hull_prev(it)) return it;\n\t\tlong double x = it->intersect(*prev(it));\n\
    \t\tline tmp(*it); tmp.x = x;\n\t\tit = hull.erase(it);\n\t\treturn hull.insert(it,\
    \ tmp);\n\t}\n\n\tvoid add_line(long long m, long long b) {\n\t\tm = -m, b = -b;\n\
    \t\tline l(m, b);\n\t\tstd::set<line>::iterator it = hull.lower_bound(l);\n\t\t\
    if (it != hull.end() && l.parallel(*it)) {\n\t\t\tif(it->b < b) it = hull.erase(it);\n\
    \t\t\telse return;\n\t\t}\n\t\tit = hull.insert(it, l);\n\t\tif (bad(it)) return\
    \ (void) hull.erase(it);\n\t\twhile (hull_prev(it) && bad(prev(it))) hull.erase(prev(it));\n\
    \t\twhile (hull_next(it) && bad(next(it))) hull.erase(next(it));\n\t\tit = update(it);\n\
    \t\tif (hull_prev(it)) update(prev(it));\n\t\tif (hull_next(it)) update(next(it));\n\
    \t}\n\t\n\tlong long query(long long x) const {\n\t\tif (hull.empty()) return\
    \ INF;\n\t\tline q; q.val = x, q.is_query = 1;\n\t\tstd::set<line>::iterator it\
    \ = --hull.lower_bound(q);\n\t\treturn -(it->eval(x));\n\t}\n};\n\nint main()\
    \ {\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/dynamic-programming/dynamic_convex_hull_trick.cpp
  requiredBy: []
  timestamp: '2021-06-09 19:36:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/dynamic-programming/dynamic_convex_hull_trick.cpp
layout: document
redirect_from:
- /library/library/dynamic-programming/dynamic_convex_hull_trick.cpp
- /library/library/dynamic-programming/dynamic_convex_hull_trick.cpp.html
title: library/dynamic-programming/dynamic_convex_hull_trick.cpp
---