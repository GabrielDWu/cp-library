#pragma once

template <class T> struct MaxDeque {
	std::deque<std::pair<T, int>> mx;
	std::deque<int> tmp;

	int l = 0,r = -1;

	int pop_front() {
		if (mx.front().second == l++) mx.pop_front();
		int t = tmp.front();
		tmp.pop_front();
		return t;
	}

	T get() {
		if ((int)mx.size() == 0) return std::numeric_limits<T>::min();
		return mx.front().first;
	}

	void push_back(T x) {
		while ((int)mx.size() && mx.back().first <= x) mx.pop_back();
		mx.push_back({x, ++r});
		tmp.push_back(x);
	}
};
