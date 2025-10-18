void z_value_pal(const string &input, vector<int> &z)
{
    // 幹你娘Miaotomata 你是不會用動態分配的陣列喔 他媽的害我一直runtime error
    int len = input.size();
    string s; s.reserve((len << 1) + 1);
    for (int i = 0; i < len; ++i)
    {
        s.push_back('@');
        s.push_back(input[i]);
    }
    s.push_back('@');

    int n = s.size();
    z.assign(n, 1);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        z[i] = (i < r ? min(z[l + l - i], r - i) : 1);
        while (i - z[i] >= 0 && i + z[i] < n && s[i - z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r) l = i, r = i + z[i];
    }
}
