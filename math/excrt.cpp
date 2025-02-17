i128 exgcd(i128 a, i128 b, i128 &x, i128 &y){
    if (b == 0) return x=1, y=0, a;
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
// as -> 算式答案 x
// ns -> 模數 MOD
i128 CRT(vector<i64> as, vector<i64> ns) {
    i32 n = as.size();
    i128 a1, a2, n1, n2;
    bool flag = false;
    auto china = [&]() {
        i128 d = a2 - a1;
        i128 x, y;
        i128 g = exgcd(n1, n2, x, y);
        if (d % g == 0) {
            x = ((x * d / g) % (n2 / g) + (n2 / g)) % (n2 / g);
            a1 = x * n1 + a1;
            n1 = (n1 * n2) / g;
        } else {
            flag = true;
        }
    };

    a1 = as[0], n1 = ns[0];
    for (i32 i = 1; i < n; i++) {
        a2 = as[i], n2 = ns[i];
        china();
        if (flag) return -1;
    }
    return a1;
}