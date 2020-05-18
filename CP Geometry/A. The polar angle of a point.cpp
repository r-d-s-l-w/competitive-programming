#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

constexpr double EPS = 1e-9;
constexpr double PI = acos(-1.0);

struct pt{
	double x, y;
	pt() {}
	pt(double x, double y): x(x), y(y) {}
	pt operator+(pt p) {return {x+p.x, y+p.y};}
	pt operator-(pt p) {return {x-p.x, y-p.y};}
	pt operator*(double k) {return {x*k, y*k};}
	pt operator/(double k) {return {x/k, y/k};} 
};
bool eq(double a, double b) {return abs(a - b) < EPS;}
bool operator==(pt p, pt q) {return eq(p.x, q.x) && eq(p.y, q.y);}
bool operator!=(pt p, pt q) {return !(p == q);}
ostream& operator<<(ostream& os, pt p) {return os << '(' << p.x << ", " << p.y << ')';}
double det(pt v, pt w) {return v.x*w.y - v.y*w.x;}
double dot(pt v, pt w) {return v.x*w.x + v.y*w.y;}
double norm(pt v) {return dot(v, v);}
double len(pt v) {return sqrt(norm(v));}
double sine(pt v, pt w) {return det(v, w) / len(v) / len(w);}
double cosinus(pt v, pt w) {return dot(v, w) / len(v) / len(w);}
double convexAngle(pt v, pt w) {return acos(cosinus(v, w));}
double toDeg(double angle) {return angle * 180.0 / PI;}
double directedAngle(pt v) {
	pt zero = {1, 0};
	double res;
	sine(zero, v) < 0 ? res = 2*PI - convexAngle(zero, v) : res = convexAngle(zero, v); 
	return res;
}
double GetPolarAngle(double x, double y){
    double res = atan2(y,x);
    if (res < 0) res += 2*PI;
    return res;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(6);
	freopen("angle1.in", "r", stdin);
	freopen("angle1.out", "w", stdout);
	double a, b;
	cin >> a >> b;
	pt x(a,b);
	cout << directedAngle(x) << '\n';
}
