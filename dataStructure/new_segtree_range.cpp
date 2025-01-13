// [l, r)
template<class Info, class Tag>
struct segTree {
    inline i32 cl(i32 x) { return x << 1; }
    inline i32 cr(i32 x) { return (x << 1) | 1; }
    i32 n;
    vector<Info> info;
    vector<Tag> tag;
    segTree(): n(0) {}
    segTree(i32 n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    segTree(vector<T> init_) {
        init(init_);
    }
    void init(i32 n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());
        function<void(i32, i32, i32)> build = [&](i32 p, i32 l, i32 r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            i32 m = (l + r) >> 1;
            build(cl(p), l, m);
            build(cr(p), m, r);
            pull(p, l, r);
        };
        build(1, 0, n);
    }
    void pull(i32 p, i32 l, i32 r) {
        i32 m = (l + r) >> 1;
        push(cl(p), l, m);
        push(cr(p), m, r);
        info[p] = info[cl(p)] + info[cr(p)];
    }
    void rangeModify(i32 p, i32 l, i32 r, i32 x, i32 y, const Tag &v) {
        push(p, l, r);
        if (l >= x && r <= y) {
            tag[p] += v;
            return;
        }
        i32 m = (l + r) >> 1;
        if (x < m) rangeModify(cl(p), l, m, x, y, v);
        if (y > m) rangeModify(cr(p), m, r, x, y, v);
        pull(p, l, r);
    }
    Info rangeQuery(i32 p, i32 l, i32 r, i32 x, i32 y) {
        push(p, l, r);
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        i32 m = (l + r)>> 1;
        return rangeQuery(cl(p), l, m, x, y) + rangeQuery(cr(p), m, r, x, y);
    }
    Info rangeQuery(i32 l, i32 r) { return rangeQuery(1, 0, n, l, r); }
    void rangeModify(i32 l, i32 r, const Tag &v) { rangeModify(1, 0, n, l, r, v); }
    void push(i32 p, i32 l, i32 r) { // need compelete
        if (tag[p].add != 0) {
            info[p].v += tag[p].add * (r - l);
            if (r - l != 1) {
                tag[cl(p)].add += tag[p].add;
                tag[cr(p)].add += tag[p].add;
            } 
            tag[p].add = 0;
        }
    }
};