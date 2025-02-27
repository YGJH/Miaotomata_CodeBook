struct hungarian {
    int L, R;
    vector<bool> vis;
    vector<int> match;
    vector<vector<int>> E;
    hungarian(int l, int r): //左邊有幾個，右邊有幾個
    L(l), R(r),
    vis(l+r+1),
    match(l+r+1,-1),
    E(l+r+1){}
    void add_edge(int l, int r){//左側第幾個(1-base) ,右側第幾個(1-base)
        r = L+r;
        E[l].push_back(r);
        E[r].push_back(l);
    }
    bool dfs(int u){
        for(int i : E[u]){
            if(vis[i]) continue; // 有連通且未拜訪
            vis[i] = true; // 紀錄是否走過
            if(match[i] == -1 || dfs(match[i])){  
                match[i] = u; match[u] = i; // 紀錄匹配
                return true;
            }
        }
        return false;
    }
    int solve(){
        int ans = 0;
        for(int i = 1; i <= L; i++){
            fill(all(vis),0);
            if(dfs(i)) ans++;
        }
        return ans;
    }
};
