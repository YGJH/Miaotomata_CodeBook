struct pSeg{
    struct node{
        int v;
        node *l,*r;
    };
    int n;
    vector<node*> ver;
    node* build(int l,int r){
        node* x = new node();
        if(l == r){
            x->v = 0;
            return x;
        }
        int m = (l+r)/2;
        x->l = build(l,m);
        x->r = build(m+1,r);
        x->v = x->l->v + x->r->v;
        return x;
    }
    void init(int _n){
        n = _n+2;
        ver.PB(build(0,n-1));
    }
    int qry(node* now,int l,int r,int ql,int qr){
        if(ql <= l && r <= qr){
            return now->v;
        }
        int m = (l+r)/2,ret = 0;
        if(ql <= m)ret += qry(now->l,l,m,ql,qr);
        if(qr > m )ret += qry(now->r,m+1,r,ql,qr);
        return ret;
    }
    node* upd(node* prv,int l,int r,int p,int v){
        node* x = new node();
        if(l == r){
            x->v = prv->v + v; //累加
            return x;
        }
        int m = (l+r)/2;
        if(p <= m) {
            x->l = upd(prv->l,l,m,p,v);
            x->r = prv->r;
        }else{
            x->l = prv->l;
            x->r = upd(prv->r,m+1,r,p,v);
        }
        x->v = x->l->v + x->r->v;
        return x;
    }
    void addver(int p,int v){
        ver.PB(upd(ver.back(),0,n-1,p,v));
    }
    //(a,b] kth //用segTree統計出現次數 //版本當區間 //第 i 個版本為前 區間 [0,i] 有統計
    int qurey(node* a,node* b,int l,int r,int k){
        if(l == r) return l;
        int m = (l+r)/2;
        int num = b->l->v - a->l->v;
        if(num >= k) return qurey(a->l,b->l,l,m,k);// 左邊大往左搜
        else return qurey(a->r,b->r,m+1,r,k-num);
    }
}; 