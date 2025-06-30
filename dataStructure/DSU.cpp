struct DSU {
    vector<i32> f, sz;
    DSU(i32 n) : f(n), sz(n) {
        for (i32 i = 0; i < n; i++) {
            f[i] = i;
            sz[i] = 1;
        }
    }
    i32 find(i32 x) {
        if (x == f[x]) return x;
        f[x] = find(f[x]);
        return f[x];
    }
    void merge(i32 x, i32 y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y])
            swap(x, y);
        sz[x] += sz[y];
        f[y] = x;
    }
    bool same(i32 a, i32 b) { return (find(a) == find(b)); }
};