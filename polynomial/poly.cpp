using poly = vector<i64>;
poly operator * (poly A, poly B){
    return convolution<mod,G>(A,B);
}
poly operator - (i64 r,poly A){
    r %= mod;
    r = (r + mod) % mod;
    for(auto &c:A){
        c %= mod;
        c = (mod - c) % mod;
    }
    A[0] = (A[0] + r) % mod;
    return A;
}
poly operator + (i64 r, poly A){
    r %= mod;
    r = (r + mod) % mod;
    A[0] = (A[0] + r) % mod;
    return A;
}
poly operator * (i64 r, poly A){
    for(auto &c:A){
        c = r * c % mod;
        c = (c + mod) % mod;
    }
    return A;
}
poly operator - (poly A, poly B){
    int n = max(A.size(),B.size());
    A.resize(n),B.resize(n);
    for(int i = 0; i < n;++i){
        A[i] = (A[i] - B[i]) % mod;
        A[i] = (A[i] + mod) % mod;
    }
    return A;
}
poly operator + (poly A, poly B){
    int n = max(A.size(),B.size());
    A.resize(n),B.resize(n);
    for(int i = 0; i < n;++i){
        A[i] = (A[i] + B[i]) % mod;
        A[i] = (A[i] + mod) % mod;
    }
    return A;
}
poly operator % (poly A,int n){
    A.resize(n);
    return A;
}

poly derive(poly P){
    if(!P.size()) return P;
    for(int i = 0; i < P.size();++i){
        P[i] = i * P[i] % mod;
        P[i] = (P[i] + mod) % mod;
    }
    P.erase(P.begin());
    return P;
}
poly integr(poly P){
    if(!P.size()) return P;
    for(int i = 0; i < P.size();++i){
        P[i] = P[i] * inv(i + 1) % mod;
        P[i] = (P[i] + mod) % mod;
    }
    P.insert(P.begin(),0);
    return P;
}