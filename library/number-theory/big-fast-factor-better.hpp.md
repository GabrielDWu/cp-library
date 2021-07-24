---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "\nnamespace FactorBig {\n\nlong long gcd(long long _a, long long _b)\
    \ {\n\tunsigned long long a = abs(_a), b = abs(_b);\n\tif (a == 0) return b;\n\
    \tif (b == 0) return a;\n\tauto bsf = [](unsigned long long x) -> int {\n\t\t\
    return __builtin_ctzll(x);\n\t};\n\tint shift = bsf(a | b);\n\ta >>= bsf(a);\n\
    \tdo {\n\t\tb >>= bsf(b);\n\t\tif (a > b) \n\t\t\tstd::swap(a, b);\n\t\tb -= a;\n\
    \t} while (b);\n\treturn (a << shift);\n}\n\ntemplate <class T, class U> T pow_mod(T\
    \ x, U n, T md) {\n\tT r = 1 % md;\n\tx %= md;\n\twhile (n) {\n\t\tif (n & 1)\
    \ r = (r * x) % md;\n\t\tx = (x * x) % md;\n\t\tn >>= 1;\n\t}\n\treturn r;\n}\n\
    \nbool is_prime(long long n) {\n\tif (n <= 1) return false;\n\tif (n == 2) return\
    \ true;\n\tif (n % 2 == 0) return false;\n\tlong long d = n - 1;\n\twhile (d %\
    \ 2 == 0) d /= 2;\n\tfor (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,\
    \ 37}) {\n\t\tif (n <= a) break;\n\t\tlong long t = d;\n\t\tlong long y = pow_mod<__int128_t>(a,\
    \ t, n);  // over\n\t\twhile (t != n - 1 && y != 1 && y != n - 1) {\n\t\t\ty =\
    \ __int128_t(y) * y % n;  // flow\n\t\t\tt <<= 1;\n\t\t}\n\t\tif (y != n - 1 &&\
    \ t % 2 == 0) {\n\t\t\treturn false;\n\t\t}\n\t}\n\treturn true;\n}\n\nlong long\
    \ pollard_single(long long n) {\n\tauto f = [&](long long x) { return (__int128_t(x)\
    \ * x + 1) % n; };\n\tif (is_prime(n)) return n;\n\tif (n % 2 == 0) return 2;\n\
    \tlong long st = 0;\n\twhile (true) {\n\t\tst++;\n\t\tlong long x = st, y = f(x);\n\
    \t\twhile (true) {\n\t\t\tlong long p = gcd((y - x + n), n);\n\t\t\tif (p == 0\
    \ || p == n) break;\n\t\t\tif (p != 1) return p;\n\t\t\tx = f(x);\n\t\t\ty = f(f(y));\n\
    \t\t}\n\t}\n}\n\nstd::vector<long long> pollard(long long n) {\n\tif (n == 1)\
    \ return {};\n\tlong long x = pollard_single(n);\n\tif (x == n) return {x};\n\t\
    std::vector<long long> le = pollard(x);\n\tstd::vector<long long> ri = pollard(n\
    \ / x);\n\tle.insert(le.end(), ri.begin(), ri.end());\n\treturn le;\n}\n\n}\n\n\
    int main() {\n\tusing namespace std;\n\tusing namespace FactorBig;\n\tint q;\n\
    \tscanf(\"%d\", &q);\n\tmap<long long, vector<long long>> cache;\n\tfor (int i\
    \ = 0; i < q; i++) {\n\t\tlong long a;\n\t\tscanf(\"%lld\", &a);\n\t\tif (!cache.count(a))\
    \ {\n\t\t\tauto v = pollard(a);\n\t\t\tsort(v.begin(), v.end());\n\t\t\tcache[a]\
    \ = v;\n\t\t}\n\t\tauto v = cache[a];\n\t\tprintf(\"%d\", (int)v.size());\n\t\t\
    for (auto d: v) printf(\" %lld\", d);\n\t\tprintf(\"\\n\");\n\t}\n\treturn 0;\n\
    }\n"
  code: "#pragma once\n\nnamespace FactorBig {\n\nlong long gcd(long long _a, long\
    \ long _b) {\n\tunsigned long long a = abs(_a), b = abs(_b);\n\tif (a == 0) return\
    \ b;\n\tif (b == 0) return a;\n\tauto bsf = [](unsigned long long x) -> int {\n\
    \t\treturn __builtin_ctzll(x);\n\t};\n\tint shift = bsf(a | b);\n\ta >>= bsf(a);\n\
    \tdo {\n\t\tb >>= bsf(b);\n\t\tif (a > b) \n\t\t\tstd::swap(a, b);\n\t\tb -= a;\n\
    \t} while (b);\n\treturn (a << shift);\n}\n\ntemplate <class T, class U> T pow_mod(T\
    \ x, U n, T md) {\n\tT r = 1 % md;\n\tx %= md;\n\twhile (n) {\n\t\tif (n & 1)\
    \ r = (r * x) % md;\n\t\tx = (x * x) % md;\n\t\tn >>= 1;\n\t}\n\treturn r;\n}\n\
    \nbool is_prime(long long n) {\n\tif (n <= 1) return false;\n\tif (n == 2) return\
    \ true;\n\tif (n % 2 == 0) return false;\n\tlong long d = n - 1;\n\twhile (d %\
    \ 2 == 0) d /= 2;\n\tfor (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,\
    \ 37}) {\n\t\tif (n <= a) break;\n\t\tlong long t = d;\n\t\tlong long y = pow_mod<__int128_t>(a,\
    \ t, n);  // over\n\t\twhile (t != n - 1 && y != 1 && y != n - 1) {\n\t\t\ty =\
    \ __int128_t(y) * y % n;  // flow\n\t\t\tt <<= 1;\n\t\t}\n\t\tif (y != n - 1 &&\
    \ t % 2 == 0) {\n\t\t\treturn false;\n\t\t}\n\t}\n\treturn true;\n}\n\nlong long\
    \ pollard_single(long long n) {\n\tauto f = [&](long long x) { return (__int128_t(x)\
    \ * x + 1) % n; };\n\tif (is_prime(n)) return n;\n\tif (n % 2 == 0) return 2;\n\
    \tlong long st = 0;\n\twhile (true) {\n\t\tst++;\n\t\tlong long x = st, y = f(x);\n\
    \t\twhile (true) {\n\t\t\tlong long p = gcd((y - x + n), n);\n\t\t\tif (p == 0\
    \ || p == n) break;\n\t\t\tif (p != 1) return p;\n\t\t\tx = f(x);\n\t\t\ty = f(f(y));\n\
    \t\t}\n\t}\n}\n\nstd::vector<long long> pollard(long long n) {\n\tif (n == 1)\
    \ return {};\n\tlong long x = pollard_single(n);\n\tif (x == n) return {x};\n\t\
    std::vector<long long> le = pollard(x);\n\tstd::vector<long long> ri = pollard(n\
    \ / x);\n\tle.insert(le.end(), ri.begin(), ri.end());\n\treturn le;\n}\n\n}\n\n\
    int main() {\n\tusing namespace std;\n\tusing namespace FactorBig;\n\tint q;\n\
    \tscanf(\"%d\", &q);\n\tmap<long long, vector<long long>> cache;\n\tfor (int i\
    \ = 0; i < q; i++) {\n\t\tlong long a;\n\t\tscanf(\"%lld\", &a);\n\t\tif (!cache.count(a))\
    \ {\n\t\t\tauto v = pollard(a);\n\t\t\tsort(v.begin(), v.end());\n\t\t\tcache[a]\
    \ = v;\n\t\t}\n\t\tauto v = cache[a];\n\t\tprintf(\"%d\", (int)v.size());\n\t\t\
    for (auto d: v) printf(\" %lld\", d);\n\t\tprintf(\"\\n\");\n\t}\n\treturn 0;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/big-fast-factor-better.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/number-theory/big-fast-factor-better.hpp
layout: document
redirect_from:
- /library/library/number-theory/big-fast-factor-better.hpp
- /library/library/number-theory/big-fast-factor-better.hpp.html
title: library/number-theory/big-fast-factor-better.hpp
---