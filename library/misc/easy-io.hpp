#pragma once

using namespace std;

inline namespace Helpers {
	//////////// is_iterable
	// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
	// this gets used only when we can call begin() and end() on that type
	template <class T, class = void> struct is_iterable : false_type {};
	template <class T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
									  decltype(end(declval<T>()))
									 >
						   > : true_type {};
	template <class T> constexpr bool is_iterable_v = is_iterable<T>::value;

	//////////// is_readable
	template <class T, class = void> struct is_readable : false_type {};
	template <class T> struct is_readable<T,
			typename std::enable_if_t<
				is_same_v<decltype(cin >> declval<T&>()), istream&>
			>
		> : true_type {};
	template <class T> constexpr bool is_readable_v = is_readable<T>::value;

	//////////// is_printable
	// // https://nafe.es/posts/2020-02-29-is-printable/
	template <class T, class = void> struct is_printable : false_type {};
	template <class T> struct is_printable<T,
			typename std::enable_if_t<
				is_same_v<decltype(cout << declval<T>()), ostream&>
			>
		> : true_type {};
	template <class T> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
	template <class T> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	template <class T, class ...U> void re(T &t, U &...u);
	template <class T, class U> void re(pair<T, U> &p); // pairs

	// re: read
	template <class T> typename enable_if<is_readable_v<T>, void>::type re(T &x) { cin >> x; } // default
	template <class T> void re(complex<T> &c) { T a, b; re(a, b); c = {a, b}; } // complex
	template <class T> typename enable_if<needs_input_v<T>, void>::type re(T &i); // ex. vectors, arrays
	template <class T, class U> void re(pair<T, U> &p) { re(p.first, p.second); }
	template <class T> typename enable_if<needs_input_v<T>, void>::type re(T &i) {
		for (auto &x : i) re(x); }
	template <class T, class ...U> void re(T &t, U &...u) { re(t); re(u...); } // read multiple

	// rv: resize and read vectors
	void rv(std::size_t) {}
	template <class T, class ...U> void rv(std::size_t N, vector<T> &t, U &...u);
	template <class...U> void rv(std::size_t, std::size_t N2, U &...u);
	template <class T, class ...U> void rv(std::size_t N, vector<T> &t, U &...u) {
		t.resize(N); re(t);
		rv(N, u...); }
	template <class...U> void rv(std::size_t, std::size_t N2, U &...u) {
		rv(N2, u...); }

	// dumb shortcuts to read in ints
	void decrement() {} // subtract one from each
	template <class T, class ...U> void decrement(T &t, U &...u) { --t; decrement(u...); }
	#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
	#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
	template <class T> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

	// ts: string representation to print
	template <class T> typename enable_if<is_printable_v<T>, string>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } // default
	template <class T> string bit_vec(T t) { // bit vector to string
		string res = "{"; for (int i = 0; i < (int)t.size(); ++i) res += ts(t[i]);
		res += "}"; return res; }
	string ts(vector<bool> v) { return bit_vec(v); }
	template <std::size_t SZ> string ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
	template <class T, class U> string ts(pair<T, U> p); // pairs
	template <class T> typename enable_if<needs_output_v<T>, string>::type ts(T v); // vectors, arrays
	template <class T, class U> string ts(pair<T, U> p) { return "(" + ts(p.first) + ", " + ts(p.second) + ")"; }
	template <class T> typename enable_if<is_iterable_v<T>, string>::type ts_sep(T v, string sep) {
		// convert container to string w/ separator sep
		bool fst = 1; string res = "";
		for (const auto &x : v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	template <class T> typename enable_if<needs_output_v<T>, string>::type ts(T v) {
		return "{" + ts_sep(v, ", ") + "}"; }

	// for nested DS
	template <int, class T> typename enable_if<!needs_output_v<T>, vector<string>>::type 
	  ts_lev(const T &v) { return {ts(v)}; }
	template <int lev, class T> typename enable_if<needs_output_v<T>, vector<string>>::type 
	  ts_lev(const T &v) {
		if (lev == 0 || !(int)v.size()) return {ts(v)};
		vector<string> res;
		for (const auto &t : v) {
			if ((int)res.size()) res.back() += ",";
			vector<string> tmp = ts_lev<lev - 1>(t);
			res.insert(res.end(), tmp.begin(), tmp.end());
		}
		for (int i = 0; i < (int)res.size(); ++i) {
			string bef = " "; if (i == 0) bef = "{";
			res[i] = bef + res[i];
		}
		res.back() += "}";
		return res;
	}
}

inline namespace Output {
	template <class T> void pr_sep(ostream &os, string, const T &t) { os << ts(t); }
	template <class T, class... U> void pr_sep(ostream &os, string sep, const T &t, const U &...u) {
		pr_sep(os, sep, t); os << sep; pr_sep(os, sep, u...); }
	// print w/ no spaces
	template <class ...T> void pr(const T &...t) { pr_sep(cout, "", t...); } 
	// print w/ spaces, end with newline
	void ps() { cout << "\n"; }
	template <class ...T> void ps(const T &...t) { pr_sep(cout, " ", t...); ps(); } 
	// debug to cerr
	template <class ...T> void dbg_out(const T &...t) {
		pr_sep(cerr, " | ", t...); cerr << endl; }
	void loc_info(int line, string names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template <int lev, class T> void dbgl_out(const T &t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t), "\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__, #__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev, x) loc_info(__LINE__, #x), dbgl_out<lev>(x)
	#else // don't actually submit with this
		#define dbg(...) 0
		#define dbgl(lev, x) 0
	#endif
}

inline namespace FileIO {
	void set_in(string s)  { freopen(s.c_str(), "r", stdin); }
	void set_out(string s) { freopen(s.c_str(), "w", stdout); }
	void setIO(string s = "") {
		cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
		// cin.exceptions(cin.failbit);
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (!s.empty()) set_in(s + ".in"), set_out(s + ".out"); // for old USACO
	}
}
