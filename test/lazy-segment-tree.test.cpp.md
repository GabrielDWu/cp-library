---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/lazy-segment-tree.hpp
    title: library/data-structures/1d-range-queries/lazy-segment-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\ntemplate\
    \ <class T> struct LazySeg {\n\tstd::vector<T> sum, lazy;\n\tint sz;\n\n\tvoid\
    \ init(int sz_) {\n\t\tsz = 1;\n\t\twhile (sz < sz_) sz *= 2;\n\t\tsum.assign(2\
    \ * sz, 0);\n\t\tlazy.assign(2 * sz, 0);\n\t}\n\n\tvoid push(int ind, int L, int\
    \ R) {\n\t\tsum[ind] += (R - L + 1) * lazy[ind];\n\t\tif (L != R) {\n\t\t\tlazy[2\
    \ * ind] += lazy[ind];\n\t\t\tlazy[2 * ind + 1] += lazy[ind];\n\t\t}\n\t\tlazy[ind]\
    \ = 0;\n\t}\n\n\tvoid pull(int ind) {\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind\
    \ + 1];\n\t}\n\n\tvoid build() {\n\t\tfor (int i = sz - 1; i >= 1; i--) {\n\t\t\
    \tpull(i);\n\t\t}\n\t}\n\n\tvoid upd(int lo, int hi, T inc, int ind = 1, int L\
    \ = 0, int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif\
    \ (hi < L || R < lo) return;\n\t\tif (lo <= L && R <= hi) {\n\t\t\tlazy[ind] =\
    \ inc;\n\t\t\tpush(ind, L, R);\n\t\t\treturn;\n\t\t}\n\t\tint M = (L + R) / 2;\n\
    \t\tupd(lo, hi, inc, 2 * ind, L, M);\n\t\tupd(lo, hi, inc, 2 * ind + 1, M + 1,\
    \ R);\n\t\tpull(ind);\n\t}\n\n\tT qsum(int lo, int hi, int ind = 1, int L = 0,\
    \ int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (lo >\
    \ R || L > hi) return 0;\n\t\tif (lo <= L && R <= hi) return sum[ind];\n\t\tint\
    \ M = (L + R) / 2;\n\t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 *\
    \ ind + 1, M + 1, R);\n\t}\n};\n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\
    \tint n, q; \n    cin >> n >> q;\n\tLazySeg<long long> seg;\n    seg.init(n);\n\
    \tfor (int i = 0; i < n; i++) {\n        int x;\n        cin >> x;\n        seg.upd(i,\
    \ i, x);\n    }\n\twhile (q--) {\n        int t;\n        cin >> t;\n        if\
    \ (t == 0) {\n            int p, x;\n            cin >> p >> x;\n            seg.upd(p,\
    \ p, x);\n        } else {\n            int l, r;\n            cin >> l >> r;\n\
    \            --r;\n            cout << seg.qsum(l, r) << '\\n';\n        }\n\t\
    }\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../library/contest/template-minimal.hpp\"\n#include \"../library/data-structures/1d-range-queries/lazy-segment-tree.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\t\
    int n, q; \n    cin >> n >> q;\n\tLazySeg<long long> seg;\n    seg.init(n);\n\t\
    for (int i = 0; i < n; i++) {\n        int x;\n        cin >> x;\n        seg.upd(i,\
    \ i, x);\n    }\n\twhile (q--) {\n        int t;\n        cin >> t;\n        if\
    \ (t == 0) {\n            int p, x;\n            cin >> p >> x;\n            seg.upd(p,\
    \ p, x);\n        } else {\n            int l, r;\n            cin >> l >> r;\n\
    \            --r;\n            cout << seg.qsum(l, r) << '\\n';\n        }\n\t\
    }\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/lazy-segment-tree.hpp
  isVerificationFile: true
  path: test/lazy-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2021-07-24 21:20:09-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lazy-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/test/lazy-segment-tree.test.cpp
- /verify/test/lazy-segment-tree.test.cpp.html
title: test/lazy-segment-tree.test.cpp
---