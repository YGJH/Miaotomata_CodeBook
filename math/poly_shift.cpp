// nlogn f(x) -> f(x + k)
auto shift = [&](vector<i64> f,i64 k) {
    k %= mod;
    k += mod;
    k %= mod;
    int n = f.size() - 1;
    vector<i64> g(n+1);
    for(int i = 0; i <= n;++i){
        f[i] = f[i] * fac[i] % mod;
        g[n - i] = fpow(k,i) * inv(fac[i]) % mod;
        //x^(-n) -> x^(0) 
    }
    auto h = convolution<mod,3>(f,g);
    h.erase(h.begin(),h.begin()+n);
    for(int i = 0; i <= n;++i) h[i] = h[i] * inv(fac[i]) % mod;
    return h;
};
