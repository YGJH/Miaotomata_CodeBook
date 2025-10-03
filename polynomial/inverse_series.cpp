poly inverse(poly A){
    int n = A.size();
    int tn = 1;
    poly Q(tn);
    Q[0] = inv(A[0]);
    while(tn < n){
        tn *= 2;
        Q = Q * (2 - A % tn * Q % tn);
        Q = Q % tn;
    }
    return Q;
}