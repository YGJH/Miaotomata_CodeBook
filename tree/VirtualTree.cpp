//求關鍵點的虛樹
//thm1 : 照dfn (dfs序) 排序後的 "相鄰點" 求lca可求出全點對的lca
auto virTree = [&](vector<int> key){ 
    auto cmp = [&](int a,int b){return dfn[a] < dfn[b];};
    sort(all(key),cmp);
    auto res = vector<int>(all(key));
    for(int i = 1; i < key.size();++i){
        res.PB(lca(key[i-1],key[i]));
    }
    sort(all(res),cmp);
    res.erase(unique(all(res)),res.end());
    return res; // res : 全點對lca集 + 關鍵點集
};
//詢問
for(int i = 1; i < ret.size(); ++i){
    int LCA = lca(ret[i-1],ret[i]);
    query(LCA,ret[i]); // 2. LCA -> ret[i] 是一條virTree的邊
    //query : 路徑詢問
    //且會全部算到
}