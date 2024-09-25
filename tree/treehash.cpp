map<vector<int>,int> id; //rooted
int dfs(int x,int f){
    vector<int> s;
    for(int u:E[x]){
        if(u == f) continue;
        s.PB(dfs(u,x));
    }
    sort(all(s));
    if(!id.count(s)) id[s] = id.size();
    return id[s];
}

const i64 mask = std::chrono::steady_clock::now().time_since_epoch().count();
//13 17 5
//13 17 7
i64 shift(i64 x) { // XOR shift (1-1 func)
  x ^= mask;
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  x ^= mask;
  return x;
}

int dfs(int x,int f){
    int ret = 1; // 需要常數
     for(int u:E[x]){
        if(u == f) continue;
        ret += shift(dfs(u,x));
    }
    // ret ^= rand_mask //如果xor hash被卡
    return ret;
}