constexpr i64 power(i64 a, i64 b, i64 m) {
    i64 ret = 1;
    for (; b; b >>= 1, a = a * a % m)
        if (b & 1) ret = ret * a % m;
    return ret;
};
template<i64 M, i64 root>
struct NTT {
	static const int Log = 21;
    array<i64, Log + 1> e{}, ie{};
    NTT() {
		static_assert(__builtin_ctz(M - 1) >= Log);
        e[Log] = power(root, (M - 1) >> Log, M);
        ie[Log] = power(e[Log], M - 2, M);
        for (int i = Log - 1; i >= 0; i--) {
            e[i] = e[i + 1] * e[i + 1] % M;
            ie[i] = ie[i + 1] * ie[i + 1] % M;
        }
    }
    void operator()(vector<i64> &v, bool inv) {
        int n = v.size();
        for (int i = 0, j = 0; i < n; i++) {
            if (i < j) swap(v[i], v[j]);
            for (int k = n / 2; (j ^= k) < k; k /= 2);
        }
        for (int m = 1; m < n; m *= 2) {
            i64 w = (inv ? ie : e)[__lg(m) + 1];
            for (int i = 0; i < n; i += m * 2) {
                i64 cur = 1;
                for (int j = i; j < i + m; j++) {
                    i64 g = v[j], t = cur * v[j + m] % M;
                    v[j] = (g + t) % M;
                    v[j + m] = (g - t + M) % M;
                    cur = cur * w % M;
                }
            }
        }
        if (inv) {
            i64 in = power(n, M - 2, M);
            for (int i = 0; i < n; i++) v[i] = v[i] * in % M;
        }
    }
};
template<int M, int G> //nlogn f*g
vector<i64> convolution(vector<i64> f, vector<i64> g) {
	static NTT<M, G> ntt;
    int n = ssize(f) + ssize(g) - 1;
    int len = bit_ceil(1ull * n);
    f.resize(len);
    g.resize(len);
    ntt(f, 0), ntt(g, 0);
    for (int i = 0; i < len; i++) {
        (f[i] *= g[i]) %= M;
    }
    ntt(f, 1);
    f.resize(n);
    return f;
}