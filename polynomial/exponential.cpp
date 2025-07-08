poly exp(poly P){
    int n = P.size();
    int tn = 1;
    poly Q(tn);
    Q[0] = 1;
    while(tn < n){
        tn *= 2;
        Q = Q * (1 + P % tn - log(Q) % tn);
        Q = Q % tn;
    }
    return Q;
}