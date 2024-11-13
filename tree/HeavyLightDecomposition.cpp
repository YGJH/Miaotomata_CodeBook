int t = 0;
vector<int> dep(n+1),p(n+1),sz(n+1),dfn(n+1),son(n+1);
auto dfs = [&](auto &&self,int x,int f,int d = 0) -> void {
    ++sz[x],dep[x] = d,p[x] = f;
    for(auto u:E[x]){
        if(u == f) continue;
        self(self,u,x,d+1);
        sz[x] += sz[u];
        if(!son[x] || sz[u] > sz[son[x]]) son[x] = u;
    }
};
vector<int> top(n+1);
auto dfsa = [&](auto &&self,int x,int f,int now) -> void {
    dfn[x] = ++t;
    top[x] = now;
    if(son[x]) self(self,son[x],x,now);
    for(auto u:E[x]){
        if(u == f || u == son[x]) continue;
        self(self,u,x,u);
    }
};
dfs(dfs,1,1);
dfsa(dfsa,1,1,1);
auto lca = [&](int x,int y){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x,y);
        x = p[top[x]];
    }
    return dep[x] < dep[y] ? x : y ;
};
// 如果要開線段樹 要每個鏈都開一顆 (比較快)