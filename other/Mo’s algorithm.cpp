int unit; // 块的大小
struct node {
    int l, r, id;
    bool operator < (const node &x) const {
        return l / unit == x.l / unit ? (r == x.r ? 0 : ((l / unit) & 1) ^ (r < x.r)) : l < x.l;
    } // 奇偶排序
};

void solve() {
  unit = int(ceil(pow(n, 0.5)));
  sort(querys, querys + m);
  for (int i = 0; i < m; ++i) {
    const query &q = querys[i];
    while (l > q.l) // calc
    while (r < q.r) // calc
    while (l < q.l) // calc
    while (r > q.r) // calc
    ans[q.id] = nowAns;
  }
}