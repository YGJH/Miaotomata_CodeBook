using ld = long double;
template<class T>
struct pt{
	T x,y;
	pt(T _x,T _y):x(_x),y(_y){}
	pt():x(0),y(0){}
	
	pt operator * (T  c){ return pt(x*c,y*c);}
	pt operator / (T  c){ return pt(x/c,y/c);}
	pt operator + (pt a){ return pt(x+a.x,y+a.y);}
	pt operator - (pt a){ return pt(x-a.x,y-a.y);}
	T  operator * (pt a){ return x*a.x + y*a.y;}
	T  operator ^ (pt a){ return x*a.y - y*a.x;}

	auto operator<=>(pt o) const { return (x != o.x) ? x <=> o.x : y <=> o.y; }
	bool operator < (pt a) const { return x < a.x || (x == a.x && y < a.y);};
	bool operator== (pt a) const { return x == a.x and y == a.y;};
	friend T ori(pt a, pt b, pt c) { return (b - a) ^ (c - a); }
	friend T abs2(pt a) { return a * a; }
	friend int dcmp(ld x) { return (x > -eps) - (x < eps); }
	friend ld abs(pt a) { return sqrt(a * a); }
};
using numbers::pi;
const ld eps = 1e-8L;
using Pt = pt<ld>;



istream &operator>>(istream &s, Pt &a) { return s >> a.x >> a.y; }
ostream &operator<<(ostream &s, Pt &a) { return s << "(" << a.x << ", " << a.y << ")";} 

ld pointToSeg(Pt a,Pt b,Pt o){ //distance of ab segment and point o
    if((o-b) * (a-b) < 0) return abs((o-b));
    if((o-a) * (b-a) < 0) return abs((o-a));
    return abs(((b-a)^(o-a))/abs(b-a));
}
bool collinearity(const PT& a, const PT& b, const PT& c) {  // 是否三點共線
    return ((b - a) ^ (c - a)) == 0;
}