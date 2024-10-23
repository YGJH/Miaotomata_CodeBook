//count zeros on segmentTree
struct segTree{
    #define cl (i<<1)
    #define cr ((i<<1)+1)
    pp seg[MXN*4];
    int tag[MXN*4];
    pp comb(pp a,pp b){
        if(a.ff < b.ff) return a;
        if(a.ff > b.ff) return b;
        return pp{a.ff,a.ss+b.ss};
    }
    void push(int i,int l,int r){
        if(tag[i]){
            seg[i].ff += tag[i];
            if(r - l > 1){
                tag[cl] += tag[i];
                tag[cr] += tag[i];
            }
            tag[i] = 0;
        }
    }
    void pull(int i,int l,int r){
        int m = (r-l)/2 + l;
        push(cl,l,m);
        push(cr,m,r);
        seg[i] = comb(seg[cl],seg[cr]);
    }
    void build(int i,int l,int r){
        if(r - l <= 1){
            seg[i] = pp{0,1};
            return;
        }
        int m = (r-l)/2 + l;
        build(cl,l,m);
        build(cr,m,r);
        pull(i,l,r);
    }
    void upd(int i,int l,int r,int ql,int qr,int x){
        push(i,l,r);
        if(ql <= l && r <= qr){
            tag[i] += x;
            return;
        }
        int m = (r-l)/2 + l;
        if(ql < m) upd(cl,l,m,ql,qr,x);
        if(qr > m) upd(cr,m,r,ql,qr,x);
        pull(i,l,r);
    }
    int qry(){
        //count zero
        if(seg[1].ff == 0) return seg[1].ss;
        return 0;
    }
    void upd(int l,int r,int x){
        upd(1,0,MXN,l,r,x);
    }
}st;