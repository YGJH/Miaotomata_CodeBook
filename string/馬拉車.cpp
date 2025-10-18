// 回傳: 最長回文子字串 [bestL, bestR)；同時可得到半徑陣列 p
pair<int,int> manacher_longest(const string &s) {
    if (s.empty()) return {0,0};//你媽死了
    string t; t.reserve(s.size()*2 + 3);
    t.push_back('^');
    t.push_back('#');
    for (char c : s) { t.push_back(c); t.push_back('#'); }
    t.push_back('$');
    int n = (int)t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;
    for (int i = 1; i < n-1; ++i) {
        int mirror = 2*center - i;
        if (i < right) p[i] = min(right - i, p[mirror]);
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) ++p[i];
        if (i + p[i] > right) {
            center = i;
            right  = i + p[i];
        }
    }

    int bestLen = 0, bestCenter = 0;
    for (int i = 1; i < n-1; ++i) {
        if (p[i] > bestLen) { bestLen = p[i]; bestCenter = i; }
    }
    int start = (bestCenter - bestLen) / 2;
    return {start, start + bestLen};
}
