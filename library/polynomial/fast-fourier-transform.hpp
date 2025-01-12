#pragma once

#include "../modular-arithmetic/mod-int2.hpp"

namespace FFT {

template <class T> void fft(std::vector<T> &A, bool inv = 0) {
	int n = (int)A.size();
	assert((T::mod - 1) % n == 0);
	std::vector<T> B(n);
	for (int b = n / 2; b; b /= 2, A.swap(B)) {
		T w = pow(T::rt(), (T::mod - 1) / n * b);
		T m = 1;
		for (int i = 0; i < n; i += b * 2, m *= w)
			for (int j = 0; j < b; j++) {
				T u = A[i + j];
				T v = A[i + j + b] * m;
				B[i / 2 + j] = u + v;
				B[i / 2 + j + n / 2] = u - v;
			}
	}
	if (inv) {
		std::reverse(1 + A.begin(), A.end());
		T z = T(1) / T(n);
		for (auto &t : A) 
			t *= z;
	}
}

template <class T> std::vector<T> multiply(std::vector<T> A, std::vector<T> B) {
	int sa = (int)A.size();
	int sb = (int)B.size();
	if (!std::min(sa, sb))
		return {};
	int s = sa + sb - 1;
	int n = 1;
	for (; n < s; n *= 2);
	bool eq = A == B;
	A.resize(n);
	fft(A);
	if (eq) 
		B = A;
	else 
		B.resize(n), fft(B);
	for (int i = 0; i < n; i++)
		A[i] *= B[i];
	fft(A, 1);
	A.resize(s);
	return A;
}

template <class M, class T> std::vector<M> multiply_mod(std::vector<T> x, std::vector<T> y) {
	auto convert = [](const std::vector<T> &v) {
		std::vector<M> w((int)v.size());
		for (int i =  0; i < (int)v.size(); i++)
			w[i] = (int) v[i];
		return w;
	};
	return multiply(convert(x), convert(y));
}

template <class T> std::vector<T> general_multiply(const std::vector<T> &A, const std::vector<T> &B) { 
	// arbitrary modulus
	using m0 = Mint<(119 << 23) + 1, 62>; 
	using m1 = Mint<(5 << 25) + 1, 62>;
	using m2 = Mint<(7 << 26) + 1, 62>;
	auto c0 = multiply_mod<m0>(A, B);
	auto c1 = multiply_mod<m1>(A, B);
	auto c2 = multiply_mod<m2>(A, B);
	int n = (int)c0.size();
	std::vector<T> res(n);
	m1 r01 = 1 / m1(m0::mod);
	m2 r02 = 1 / m2(m0::mod);
	m2 r12 = 1 / m2(m1::mod);
	for (int i = 0; i < n; i++) {
		int a = c0[i].v;
		int b = ((c1[i] - a) * r01).v;
		int c = (((c2[i] - a) * r02 - b) * r12).v;
		res[i] = (T(c) * m1::mod + b) * m0::mod + a;
	}
	return res;
}

} // namespace FFT