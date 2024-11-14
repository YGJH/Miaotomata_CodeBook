pair<ld, pair<i32, i32>> ClosestPair(vector<Pt> &P) {
    // ans = dis * dis  !!注意ans overflow問題
    // Pt非整數點ans記得改double
    i64 ans = INT64_MAX; pair<i32, i32> ansi;
    auto upd = [&](const Pt &a, const Pt &b) {
        i64 dis = abs2(a - b); // Pt非整數點i64記得改double
        if (dis < ans) ans = dis, ansi.FF = a.id, ansi.SS = b.id;
    };
    auto cmpy = [](const Pt &a, const Pt &b) { return a.y < b.y; };

    vector<Pt> t(P.size() + 1);
    function<void(i32, i32)> rec = [&](i32 l, i32 r) {
        if (r - l <= 3) {
            for (i32 i = l; i <= r; i++)
                for (i32 j = i + 1; j <= r; j++) upd(P[i], P[j]);
            sort(P.begin() + l, P.begin() + r + 1, cmpy);
            return;
        }

        i32 m = (l + r) >> 1;
        i64 midx = P[m].x; // Pt非整數點i64記得改double
        rec(l, m), rec(m + 1, r);
        i32 tsz = 0;
        inplace_merge(P.begin() + l, P.begin() + m + 1, P.begin() + r + 1, cmpy);
        for (i32 i = l; i <= r; i++) {
            if (abs(P[i].x - midx) * abs(P[i].x - midx) >= ans) continue;
            for (i32 j = tsz - 1; j >= 0 && (P[i].y - t[j].y) * (P[i].y - t[j].y) < ans; j--) upd(P[i], t[j]);
            t[tsz++] = P[i];
        }
    };
    sort(all(P));
    rec(0, P.size() - 1);
    return make_pair(sqrt(ans), ansi);
}