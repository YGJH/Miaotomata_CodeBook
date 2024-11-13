int n, q;
int anc[MAXN][25], in[MAXN], out[MAXN];
vector<int> edge[MAXN];
int timing = 1;
void dfs(int cur, int fa) {
    anc[cur][0] = fa;
    in[cur] = timing++;
    for (int nex : edge[cur]) {
        if (nex == fa) continue;
        dfs(nex, cur);
    }
    out[cur] = timing++;
}
void init() {
    dfs(1, 0);
    for (int i = 1; i < 25; i++) {
        for (int cur = 1; cur <= n; cur++) {
            anc[cur][i] = anc[anc[cur][i - 1]][i - 1];
        }
    }
}
bool isanc(int u, int v) { return (in[u] <= in[v] && out[v] <= out[u]); }
int lca(int a, int b) {
    if (isanc(a, b)) return a;
    if (isanc(b, a)) return b;
    for (int i = 24; i >= 0; i--) {
        if (anc[a][i] == 0) continue;
        if (!isanc(anc[a][i], b)) a = anc[a][i];
    }

    return anc[a][0];
}



int t = 0,tt = 0;
vector<int> dfn(n),in(n),out(n),dep(n);
vector anc(n,vector<int>(20));
auto pdfs = [&](auto &&self,int x,int f,int d = 0) -> void {
    in[x] = ++t;
    anc[x][0] = f;
    dep[x] = d;
    dfn[x] = ++tt;
    for(auto u:E[x]){
        if(u == f) continue;
        self(self,u,x,d+1);
    }
    out[x] = ++t;
};
pdfs(pdfs,0,0);
for(int k = 1; k < 20;++k){
    for(int i = 0; i < n;++i){
        anc[i][k] = anc[anc[i][k-1]][k-1];
    }
}
auto isanc = [&](int u,int v){
    return in[u] <= in[v] && out[v] <= out[u];
};
auto lca = [&](int x,int y){
    if(isanc(x,y)) return x;
    if(isanc(y,x)) return y;
    for(int i = 19; i >= 0; --i){
        if(!isanc(anc[x][i],y)) x = anc[x][i];
    }
    return anc[x][0];
};