int l = 1,r = 100;
while(l < r) {
    int lmid = l + (r - l) / 3; // l + 1/3区间大小
    int rmid = r - (r - l) / 3;  // r - 1/3区间大小
    lans = cal(lmid),rans = cal(rmid);
    // 求凹函数的极小值
    if(lans <= rans) r = rmid - 1;
    else l = lmid + 1;
}