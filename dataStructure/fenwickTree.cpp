struct fenwick {
    // [0, n]
	#define lowbit(x) (x & -x)
	int n;
	vector<i64> v;
	fenwick(i32 _n) : n(_n + 1), v(_n + 2, 0) {}
	void _add(i32 x, i64 u){
		for(;x <= n; x += lowbit(x)) v[x] += u;
	}
	i64 _qry(i32 x){
		int ret = 0;
		for(; x ; x -= lowbit(x)) ret += v[x];
		return ret;
	}
    i32 _lowerbound(i64 k) {
        i64 sum = 0;
        i32 p = 0;
        for (i32 i = (1 << __lg(n)); i; i >>= 1) {
            i32 nxt = p + i;
            if (nxt <= n && sum + v[nxt] < k) {
                sum += v[nxt];
                p = nxt;
            }
        }
        if (p + 1 > n) return -1;
        return p;
    }
    void add(i32 x, i64 v) { _add(x + 1, v); }
    i64 qry(i32 x) { return _qry(x + 1); }
	i64 qry(i32 l,i32 r) { return qry(r) - qry(l - 1); }
    i32 lower_bound(i64 k) { return _lowerbound(k); }
};