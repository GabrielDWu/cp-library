---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/polynomial/number-theoretic-transform.hpp
    title: library/polynomial/number-theoretic-transform.hpp
  - icon: ':question:'
    path: library/polynomial/polynomial.hpp
    title: library/polynomial/polynomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "\n\n\nnamespace NTT {\n\nint bsf(unsigned int x) { return __builtin_ctz(x);\
    \ }\nint bsf(unsigned long long x) { return __builtin_ctzll(x); }\n\ntemplate\
    \ <class Mint> void nft(bool type, std::vector<Mint>& a) {\n\tint n = int(a.size()),\
    \ s = 0;\n\twhile ((1 << s) < n) s++;\n\tassert(1 << s == n);\n\tstatic std::vector<Mint>\
    \ ep, iep;\n\twhile (int(ep.size()) <= s) {\n\t\tep.push_back(pow(Mint::rt(),\
    \ Mint(-1).v / (1 << ep.size())));\n\t\tiep.push_back(1 / ep.back());\n\t}\n\t\
    std::vector<Mint> b(n);\n\tfor (int i = 1; i <= s; i++) {\n\t\tint w = 1 << (s\
    \ - i);\n\t\tMint base = type ? iep[i] : ep[i], now = 1;\n\t\tfor (int y = 0;\
    \ y < n / 2; y += w) {\n\t\t\tfor (int x = 0; x < w; x++) {\n\t\t\t\tauto l =\
    \ a[y << 1 | x];\n\t\t\t\tauto r = now * a[y << 1 | x | w];\n\t\t\t\tb[y | x]\
    \ = l + r;\n\t\t\t\tb[y | x | n >> 1] = l - r;\n\t\t\t}\n\t\t\tnow *= base;\n\t\
    \t}\n\t\tswap(a, b);\n\t}\n}\n\ntemplate <class Mint> std::vector<Mint> multiply_nft(const\
    \ std::vector<Mint>& a, const std::vector<Mint>& b) {\n\tint n = int(a.size()),\
    \ m = int(b.size());\n\tif (!n || !m) return {};\n\tif (min(n, m) <= 8) {\n\t\t\
    std::vector<Mint> ans(n + m - 1);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfor\
    \ (int j = 0; j < m; j++) ans[i + j] += a[i] * b[j];\n\t\treturn ans;\n\t}\n\t\
    int lg = 0;\n\twhile ((1 << lg) < n + m - 1) lg++;\n\tint z = 1 << lg;\n\tauto\
    \ a2 = a, b2 = b;\n\ta2.resize(z);\n\tb2.resize(z);\n\tnft(false, a2);\n\tnft(false,\
    \ b2);\n\tfor (int i = 0; i < z; i++) a2[i] *= b2[i];\n\tnft(true, a2);\n\ta2.resize(n\
    \ + m - 1);\n\tMint iz = 1 / Mint(z);\n\tfor (int i = 0; i < n + m - 1; i++) a2[i]\
    \ *= iz;\n\treturn a2;\n}\n\n// Cooley-Tukey: input -> butterfly -> bit reversing\
    \ -> output \n// bit reversing\ntemplate <class Mint> void butterfly(bool type,\
    \ std::vector<Mint>& a) {\n\tint n = int(a.size()), h = 0;\n\twhile ((1 << h)\
    \ < n) h++;\n\tassert(1 << h == n);\n\tif (n == 1) return;\n\n\tstatic std::vector<Mint>\
    \ snow, sinow;\n\tif (snow.empty()) {\n\t\tMint sep = Mint(1), siep = Mint(1);\n\
    \t\tunsigned int mod = Mint(-1).v;\n\t\tunsigned int di = 4;\n\t\twhile (mod %\
    \ di == 0) {\n\t\t\tMint ep = pow(Mint::rt(), mod / di);\n\t\t\tMint iep = 1 /\
    \ ep;\n\t\t\tsnow.push_back(siep * ep);\n\t\t\tsinow.push_back(sep * iep);\n\t\
    \t\tsep *= ep;\n\t\t\tsiep *= iep;\n\t\t\tdi *= 2;\n\t\t}\n\t}\n\tif (!type) {\n\
    \t\t// fft\n\t\tfor (int ph = 1; ph <= h; ph++) {\n\t\t\tint w = 1 << (ph - 1),\
    \ p = 1 << (h - ph);\n\t\t\tMint now = Mint(1);\n\t\t\tfor (int s = 0; s < w;\
    \ s++) {\n\t\t\t\tint offset = s << (h - ph + 1);\n\t\t\t\tfor (int i = 0; i <\
    \ p; i++) {\n\t\t\t\t\tauto l = a[i + offset];\n\t\t\t\t\tauto r = a[i + offset\
    \ + p] * now;\n\t\t\t\t\ta[i + offset] = l + r;\n\t\t\t\t\ta[i + offset + p] =\
    \ l - r;\n\t\t\t\t}\n\t\t\t\tint u = bsf(~(unsigned int)(s));\n\t\t\t\tnow *=\
    \ snow[u];\n\t\t\t}\n\t\t}\n\t} else {\n\t\t// ifft\n\t\tfor (int ph = h; ph >=\
    \ 1; ph--) {\n\t\t\tint w = 1 << (ph - 1), p = 1 << (h - ph);\n\t\t\tMint inow\
    \ = Mint(1);\n\t\t\tfor (int s = 0; s < w; s++) {\n\t\t\t\tint offset = s << (h\
    \ - ph + 1);\n\t\t\t\tfor (int i = 0; i < p; i++) {\n\t\t\t\t\tauto l = a[i +\
    \ offset];\n\t\t\t\t\tauto r = a[i + offset + p];\n\t\t\t\t\ta[i + offset] = l\
    \ + r;\n\t\t\t\t\ta[i + offset + p] = (l - r) * inow;\n\t\t\t\t}\n\t\t\t\tint\
    \ u = bsf(~(unsigned int)(s));\n\t\t\t\tinow *= sinow[u];\n\t\t\t}\n\t\t}\n\t\
    }\n}\n\ntemplate <class Mint> std::vector<Mint> multiply(const std::vector<Mint>&\
    \ a, const std::vector<Mint>& b) {\n\tint n = int(a.size()), m = int(b.size());\n\
    \tif (!n || !m) return {};\n\tif (min(n, m) < 8) {\n\t\tstd::vector<Mint> ans(n\
    \ + m - 1);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (int j = 0; j < m; j++)\
    \ ans[i + j] += a[i] * b[j];\n\t\treturn ans;\n\t}\n\tint lg = 0;\n\twhile ((1\
    \ << lg) < n + m - 1) lg++;\n\tint z = 1 << lg;\n\tauto a2 = a;\n\ta2.resize(z);\n\
    \tbutterfly(false, a2);\n\tif (a == b) {\n\t\tfor (int i = 0; i < z; i++) a2[i]\
    \ *= a2[i];\n\t} else {\n\t\tauto b2 = b;\n\t\tb2.resize(z);\n\t\tbutterfly(false,\
    \ b2);\n\t\tfor (int i = 0; i < z; i++) a2[i] *= b2[i];\n\t}\n\tbutterfly(true,\
    \ a2);\n\ta2.resize(n + m - 1);\n\tMint iz = 1 / Mint(z);\n\tfor (int i = 0; i\
    \ < n + m - 1; i++) a2[i] *= iz;\n\treturn a2;\n}\n\n}\n\ntemplate <class D> struct\
    \ Poly {\n\tstd::vector<D> v;\n\tPoly(const std::vector<D>& _v = {}) : v(_v) {\
    \ shrink(); }\n\n\tvoid shrink() {\n\t\twhile (v.size() && !v.back()) v.pop_back();\n\
    \t}\n\n\tvoid resize(int n) { v.resize(n); }\n\tvoid assign(int n, D& x) { v.assign(n,\
    \ x); }\n\tvoid push_back(const D& x) { v.push_back(x); }\n\tvoid pop_back() {\
    \ v.pop_back(); }\n\t\n\tint size() const { return int(v.size()); }\n\n\tD freq(int\
    \ p) const { return (p < size()) ? v[p] : D(0); }\n\tD& operator[] (int index)\
    \ { return v[index]; }\n\t\n\tPoly operator+(const Poly& r) const {\n\t\tauto\
    \ n = max(size(), r.size());\n\t\tstd::vector<D> res(n);\n\t\tfor (int i = 0;\
    \ i < n; i++) res[i] = freq(i) + r.freq(i);\n\t\treturn res;\n\t}\n\t\n\tPoly\
    \ operator-(const Poly& r) const {\n\t\tint n = max(size(), r.size());\n\t\tstd::vector<D>\
    \ res(n);\n\t\tfor (int i = 0; i < n; i++) res[i] = freq(i) - r.freq(i);\n\t\t\
    return res;\n\t}\n\t\n\tPoly operator*(const Poly& r) const { return {NTT::multiply(v,\
    \ r.v)}; }\n\t\n\tPoly operator*(const D& r) const {\n\t\tint n = size();\n\t\t\
    std::vector<D> res(n);\n\t\tfor (int i = 0; i < n; i++) res[i] = v[i] * r;\n\t\
    \treturn res;\n\t}\n\n\tPoly operator/(const D &r) const{ return *this * (1 /\
    \ r); }\n\t\n\tPoly operator/(const Poly& r) const {\n\t\tif (size() < r.size())\
    \ return {{}};\n\t\tint n = size() - r.size() + 1;\n\t\treturn (rev().pre(n) *\
    \ r.rev().inv(n)).pre(n).rev(n);\n\t}\n\t\n\tPoly operator%(const Poly& r) const\
    \ { return *this - *this / r * r; }\n\t\n\tPoly operator<<(int s) const {\n\t\t\
    std::vector<D> res(size() + s);\n\t\tfor (int i = 0; i < size(); i++) res[i +\
    \ s] = v[i];\n\t\treturn res;\n\t}\n\t\n\tPoly operator>>(int s) const {\n\t\t\
    if (size() <= s) return Poly();\n\t\tstd::vector<D> res(size() - s);\n\t\tfor\
    \ (int i = 0; i < size() - s; i++) res[i] = v[i + s];\n\t\treturn res;\n\t}\n\t\
    \n\tPoly& operator+=(const Poly& r) { return *this = *this + r; }\n\tPoly& operator-=(const\
    \ Poly& r) { return *this = *this - r; }\n\tPoly& operator*=(const Poly& r) {\
    \ return *this = *this * r; }\n\tPoly& operator*=(const D& r) { return *this =\
    \ *this * r; }\n\tPoly& operator/=(const Poly& r) { return *this = *this / r;\
    \ }\n\tPoly& operator/=(const D &r) {return *this = *this/r;}\n\tPoly& operator%=(const\
    \ Poly& r) { return *this = *this % r; }\n\tPoly& operator<<=(const size_t& n)\
    \ { return *this = *this << n; }\n\tPoly& operator>>=(const size_t& n) { return\
    \ *this = *this >> n; }\n\n\tPoly pre(int le) const { return {{v.begin(), v.begin()\
    \ + min(size(), le)}}; }\n\t\n\tPoly rev(int n = -1) const {\n\t\tstd::vector<D>\
    \ res = v;\n\t\tif (n != -1) res.resize(n);\n\t\treverse(res.begin(), res.end());\n\
    \t\treturn res;\n\t}\n\t\n\tPoly diff() const {\n\t\tstd::vector<D> res(max(0,\
    \ size() - 1));\n\t\tfor (int i = 1; i < size(); i++) res[i - 1] = freq(i) * i;\n\
    \t\treturn res;\n\t}\n\t\n\tPoly inte() const {\n\t\tstd::vector<D> res(size()\
    \ + 1);\n\t\tfor (int i = 0; i < size(); i++) res[i + 1] = freq(i) / (i + 1);\n\
    \t\treturn res;\n\t}\n\n\t// f * f.inv() = 1 + g(x)x^m\n\tPoly inv(int m) const\
    \ {\n\t\tPoly res = Poly({D(1) / freq(0)});\n\t\tfor (int i = 1; i < m; i *= 2)\
    \ {\n\t\t\tres = (res * D(2) - res * res * pre(2 * i)).pre(2 * i);\n\t\t}\n\t\t\
    return res.pre(m);\n\t}\n\t\n\tPoly exp(int n) const {\n\t\tassert(freq(0) ==\
    \ 0);\n\t\tPoly f({1}), g({1});\n\t\tfor (int i = 1; i < n; i *= 2) {\n\t\t\t\
    g = (g * 2 - f * g * g).pre(i);\n\t\t\tPoly q = diff().pre(i - 1);\n\t\t\tPoly\
    \ w = (q + g * (f.diff() - f * q)).pre(2 * i - 1);\n\t\t\tf = (f + f * (*this\
    \ - w.inte()).pre(2 * i)).pre(2 * i);\n\t\t}\n\t\treturn f.pre(n);\n\t}\n\t\n\t\
    Poly log(int n) const {\n\t\tassert(freq(0) == 1);\n\t\tauto f = pre(n);\n\t\t\
    return (f.diff() * f.inv(n - 1)).pre(n - 1).inte();\n\t}\n\n\tPoly pow_mod(long\
    \ long n, const Poly& mod) {\n\t\tPoly x = *this, r = {{1}};\n\t\twhile (n) {\n\
    \t\t\tif (n & 1) r = r * x % mod;\n\t\t\tx = x * x % mod;\n\t\t\tn >>= 1;\n\t\t\
    }\n\t\treturn r;\n\t}\n\n\tPoly pow(int n, long long e) {\n\t\tPoly b = pre(n\
    \ + 1);\n\t\tPoly r({1});\n\t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tr *= b;\n\
    \t\t\t\tr.pre(n + 1);\n\t\t\t}\n\t\t\tb *= b;\n\t\t\tr.pre(n + 1);\n\t\t\te >>=\
    \ 1;\n\t\t}\n\t\treturn r;\n\t}\n\n\tfriend ostream& operator<<(ostream& os, const\
    \ Poly& p) {\n\t\tif (p.size() == 0) return os << \"0\";\n\t\tfor (auto i = 0;\
    \ i < p.size(); i++) {\n\t\t\tif (p.v[i]) {\n\t\t\t\tos << p.v[i] << \"x^\" <<\
    \ i;\n\t\t\t\tif (i != p.size() - 1) os << \"+\";\n\t\t\t}\n\t\t}\n\t\treturn\
    \ os;\n\t}\n};\n\ntemplate <class Mint> struct MultiEval {\n\tusing NP = MultiEval*;\n\
    \tNP l, r;\n\tstd::vector<Mint> que;\n\tint sz;\n\tPoly<Mint> mul;\n\n\tMultiEval(const\
    \ std::vector<Mint>& _que, int off, int _sz) : sz(_sz) {\n\t\tif (sz <= 100) {\n\
    \t\t\tque = {_que.begin() + off, _que.begin() + off + sz};\n\t\t\tmul = {{1}};\n\
    \t\t\tfor (auto x : que) mul *= {{-x, 1}};\n\t\t\treturn;\n\t\t}\n\t\tl = new\
    \ MultiEval(_que, off, sz / 2);\n\t\tr = new MultiEval(_que, off + sz / 2, sz\
    \ - sz / 2);\n\t\tmul = l->mul * r->mul;\n\t}\n\n\tMultiEval(const std::vector<Mint>&\
    \ _que) : MultiEval(_que, 0, int(_que.size())) {}\n\n\tvoid query(const Poly<Mint>&\
    \ _pol, std::vector<Mint>& res) const {\n\t\tif (sz <= 100) {\n\t\t\tfor (auto\
    \ x : que) {\n\t\t\t\tMint sm = 0, base = 1;\n\t\t\t\tfor (int i = 0; i < _pol.size();\
    \ i++) {\n\t\t\t\t\tsm += base * _pol.freq(i);\n\t\t\t\t\tbase *= x;\n\t\t\t\t\
    }\n\t\t\t\tres.push_back(sm);\n\t\t\t}\n\t\t\treturn;\n\t\t}\n\t\tauto pol = _pol\
    \ % mul;\n\t\tl->query(pol, res);\n\t\tr->query(pol, res);\n\t}\n\t\n\tstd::vector<Mint>\
    \ query(const Poly<Mint>& pol) const {\n\t\tstd::vector<Mint> res;\n\t\tquery(pol,\
    \ res);\n\t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n\n#include \"polynomial.hpp\"\n\ntemplate <class Mint> struct\
    \ MultiEval {\n\tusing NP = MultiEval*;\n\tNP l, r;\n\tstd::vector<Mint> que;\n\
    \tint sz;\n\tPoly<Mint> mul;\n\n\tMultiEval(const std::vector<Mint>& _que, int\
    \ off, int _sz) : sz(_sz) {\n\t\tif (sz <= 100) {\n\t\t\tque = {_que.begin() +\
    \ off, _que.begin() + off + sz};\n\t\t\tmul = {{1}};\n\t\t\tfor (auto x : que)\
    \ mul *= {{-x, 1}};\n\t\t\treturn;\n\t\t}\n\t\tl = new MultiEval(_que, off, sz\
    \ / 2);\n\t\tr = new MultiEval(_que, off + sz / 2, sz - sz / 2);\n\t\tmul = l->mul\
    \ * r->mul;\n\t}\n\n\tMultiEval(const std::vector<Mint>& _que) : MultiEval(_que,\
    \ 0, int(_que.size())) {}\n\n\tvoid query(const Poly<Mint>& _pol, std::vector<Mint>&\
    \ res) const {\n\t\tif (sz <= 100) {\n\t\t\tfor (auto x : que) {\n\t\t\t\tMint\
    \ sm = 0, base = 1;\n\t\t\t\tfor (int i = 0; i < _pol.size(); i++) {\n\t\t\t\t\
    \tsm += base * _pol.freq(i);\n\t\t\t\t\tbase *= x;\n\t\t\t\t}\n\t\t\t\tres.push_back(sm);\n\
    \t\t\t}\n\t\t\treturn;\n\t\t}\n\t\tauto pol = _pol % mul;\n\t\tl->query(pol, res);\n\
    \t\tr->query(pol, res);\n\t}\n\t\n\tstd::vector<Mint> query(const Poly<Mint>&\
    \ pol) const {\n\t\tstd::vector<Mint> res;\n\t\tquery(pol, res);\n\t\treturn res;\n\
    \t}\n};\n"
  dependsOn:
  - library/polynomial/polynomial.hpp
  - library/polynomial/number-theoretic-transform.hpp
  isVerificationFile: false
  path: library/polynomial/multipoint-evaluation.hpp
  requiredBy: []
  timestamp: '2021-07-30 23:56:29-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/polynomial/multipoint-evaluation.hpp
layout: document
redirect_from:
- /library/library/polynomial/multipoint-evaluation.hpp
- /library/library/polynomial/multipoint-evaluation.hpp.html
title: library/polynomial/multipoint-evaluation.hpp
---