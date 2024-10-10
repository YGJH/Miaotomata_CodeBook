auto add = [&](int u,int v,int w){
    E[u].EB(v,w);
    E[v].EB(u,w);
};
//A : 橫槓(n*(m-1)); B : 直槓((n-1)*m); C : 斜槓((n-1)*(m-1));
//n 列 m 行平面圖 (1-base) S起點 (左上) T 終點 (右下)
forr(s,(n-1)){
    int M = (m-1)*2;
    forr(i,M){
        int id = i + (s-1)*M;
        if(i&1){
            int u = (s < n-1) ? ((i+1) + s*M) : T;
            int e = (i > 1) ? id - 1 : T;
            add(id,e,B[s-1][(i-1)/2]);
            add(id,u,A[s][(i-1)/2]);
        }else{
            if(i == M) add(id,S,B[s-1][m-1]);
            if(s == 1) add(id,S,A[s-1][i/2-1]);
            int w = C[s-1][i/2-1];
            add(id,id-1,w);
        }
    }
}