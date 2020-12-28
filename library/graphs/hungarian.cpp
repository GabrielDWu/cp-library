#include <bits/stdc++.h>
/**
* Another black box algorithm I don't understand
* But I can use 
* O(N^2M) for N jobs and M workers
* 0-indexed
* untested
*/

template <class C> C hunagrian(const std::vector<std::vector<C>>& a_) {
    const C INF = std::numeric_limits<C>::max();
    int n = (int) a_.size();
    int m = (int) a_[0].size();
    assert(n <= m);
    std::vector<std::vector<C>> a(n + 1, std::vector<C>(m + 1, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i + 1][j + 1] = a_[i][j];
    std::vector<C> u(n + 1), v(m + 1);
    std::vector<int> job(m + 1);
    for (int i = 1; i <= n; i++) {
        int w = 0;
        job[w] = i;
        std::vector<C> dist(m + 1, INF);
        std::vector<int> pre(m + 1, -1);
        std::vector<bool> done(m + 1);
        while (job[w]) {
            done[w] = 1;
            int j = job[w], nxt;
            C delta = INF;
            for (int ww = 0; ww <= m; ww++) 
                if (!done[ww]) {
                    if (dist[ww] > a[j][ww] - u[j] - v[ww]) {
                        dist[ww] = a[j][ww] - u[j] - v[ww];
                        pre[ww] = w; 
                    }
                    if (delta > dist[ww]) {
                        delta = dist[ww];
                        nxt = ww;
                    }
                }
            w = nxt;
        }
        for (int ww; w; w = ww) 
            job[w] = job[ww = pre[w]];
    }
    return -v[0];
}

int main() {
    using namespace std;
    return 0;
}