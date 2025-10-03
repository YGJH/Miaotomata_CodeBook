poly log(poly P){
    return integr(derive(P) * inverse(P));
}