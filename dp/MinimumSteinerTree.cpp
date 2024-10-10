int dp[MXN][(1<<11)],vis[MXN];
//dp[i][S] -> 選了前K個點 以第i個點為第K+1個點的 生成(1..K+1)的最小生成數
rep(s,0,(1<<K)) forr(i,N) dp[i][s] = INF;
	rep(j,0,K) dp[j+1][(1<<j)] = 0;
	rep(s,0,(1<<K)){
		forr(i,N){
			for(int a = s; a ; a=(a-1)&s)
			dp[i][s] = min(dp[i][s],dp[i][s^a] + dp[i][a]); // node
		}
		FZ(vis);
		priority_queue<pp,vector<pp>,greater<pp>> Q;
		forr(i,N) Q.emplace(dp[i][s],i);
		while(Q.size()){
			auto [d,u] = Q.top();Q.pop();
			if(vis[u]) continue;
			vis[u] = 1;
			for(auto [v,w]:E[u]){
				if(dp[u][s]+w < dp[v][s]) {
					dp[v][s] = dp[u][s]+w;
					Q.emplace(dp[v][s],v);
				}
			}
		}
	}
rep(i,K+1,N+1) cout << dp[i][(1<<K)-1] <<'\n';