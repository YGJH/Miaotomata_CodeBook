template<class T>
struct segTree{
    #define cl (i<<1)
    #define cr ((i<<1)+1)
    int n;
    T inf;
    vector<T> seg,tag;
    segTree(int _n,int val = 0)
    : n(_n)
    ,seg(_n * 4,val)
    ,tag(_n * 4,val)
    ,inf(val) {}
 
    segTree(vector<T> &_a,int val = 0)
    : n(_a.size())
    ,seg(_a.size() * 4,val)
    ,tag(_a.size() * 4,val)
    ,inf(val){
        build(1,0,n,_a);
    }
    void add(T& a,T b){
        a = max(a,b);
    }
    T comb(T a,T b){
        return max(a,b);
    }
    void push(int i,int l,int r){
        if(tag[i] != inf){
            add(seg[i],(tag[i]));
            // seg[i] = tag[i];
            if(r - l > 1){
                add(tag[cl],tag[i]);
                add(tag[cr],tag[i]);
            }
            tag[i] = inf;
        }
    }
    void pull(int i,int l,int r){
        int m = (l+r)/2;
        push(cl,l,m);
        push(cr,m,r);
        seg[i] = comb(seg[cl],seg[cr]);
    }
    void build(int i,int l,int r,vector<T> &a){
        if(r - l <= 1) {
            seg[i] = a[l];
            return;
        }
        int m = (l+r)/2;
        build(cl,l,m,a);
        build(cr,m,r,a);
        pull(i,l,r);
    }
 
    void upd(int i,int l,int r,int ql,int qr,int x){
        push(i,l,r);
        if(ql <= l && r <= qr){
            add(tag[i],x);
            return;
        }
        int m = (l+r)/2;
        if(ql < m) upd(cl,l,m,ql,qr,x);
        if(qr > m) upd(cr,m,r,ql,qr,x);
        pull(i,l,r);
    }
    T qry(int i,int l,int r,int ql,int qr){
        push(i,l,r);
        if(ql <= l && r <= qr){
            return seg[i];
        }
        int m = (l+r)/2;
        T ret = inf;
        if(ql < m) add(ret,qry(cl,l,m,ql,qr));
        if(qr > m) add(ret,qry(cr,m,r,ql,qr));
        return ret;
    }
    T qry(int l,int r){
        return qry(1,0,n,l,r);
    }
    void upd(int l,int r,int x){
        upd(1,0,n,l,r,x);
    }
};