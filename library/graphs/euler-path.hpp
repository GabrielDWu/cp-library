#pragma once

/**
 * Finds Euler path in O(N + M) from a starting vertex
 * To find which vertex to start, use parities
 */

template <bool directed> struct Euler {
	int n;
	std::vector<std::vector<std::pair<int, int>>> adj;
	std::vector<std::vector<std::pair<int, int>>::iterator> its;
	std::vector<bool> used;

	void init(int _n) {
		n = _n;
		adj.resize(n);
	}

	void ae(int u, int v) {
		int m = (int)used.size();
		used.push_back(false);
		adj[u].emplace_back(v, m);
		if (!directed) {
			adj[v].emplace_back(u, m);
		}
	}

	std::vector<std::pair<int, int>> euler_path() {
		int cnt = 0;
		for (int i = 0; i < n; i++) 
			cnt += (int)adj[i].size() % 2;
		if (cnt == 2) {
			for (int i = 0; i < n; i++) 
				if ((int)adj[i].size() % 2) 
					return get_path(i);
		} else if (cnt == 0) {
			return get_path(0);
		}
		return {};
	}
	
	std::vector<std::pair<int, int>> get_path(int src = 0) {
		its.resize(n);
		std::vector<std::pair<int, int>> ans, s{{src, -1}};
		for (int i = 0; i < n; i++) {
			its[i] = adj[i].begin();
		}
		int lst = -1;
		while ((int)s.size()) {
			int x = s.back().first;
			auto &it = its[x];
			auto en = adj[x].end();
			while (it != en && used[it->second]) {
				++it;
			}
			if (it == en) {
				if (lst != -1 && lst != x) {
					return {};
				}
				ans.push_back(s.back());
				s.pop_back();
				if ((int)s.size()) {
					lst = s.back().first;
				}
			} else {
				s.push_back(*it);
				used[it->second] = 1;
			}
		}
		if ((int)ans.size() != (int)used.size() + 1) {
			return {};
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
