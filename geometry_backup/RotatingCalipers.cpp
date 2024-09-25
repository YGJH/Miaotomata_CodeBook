int RotatingCalipers(vector<PT> &hull) { // 最遠點對 回傳距離平方
    int n = hull.size();
    int ret = 0;
    if (hull.size() <= 2) {
        return (hull[0] - hull[1]).length2();
    }
    for (int i = 0, j = 2; i < n; i++) {
        PT a = hull[i], b = hull[(i + 1) % n];
        while(ori(hull[j],a,b) <
             (ori(hull[(j + 1) % n],a,b)))
            j = (j + 1) % n;
        ret = max(ret, (a - hull[j]).length2());
        ret = max(ret, (b - hull[j]).length2());
    }
    return ret;
}