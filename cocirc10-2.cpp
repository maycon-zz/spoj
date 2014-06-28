#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <iostream>
#include <sstream>

using namespace std;

#define REP(i,a,n) for(int i=(int)a;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) (int((x).size()))

const double EPS = 1e-10;

inline int cmp(double x, double y=0, double tol=EPS){
    return (x<=y+tol) ? (x+tol<y) ? -1 : 0 : 1;
}

struct point{
    double x,y;
    point(double x=0, double y=0): x(x), y(y){}
    point operator +(point q){ return point(x+q.x,y+q.y); }
    point operator -(point q){ return point(x-q.x,y-q.y); }
    point operator *(double t){ return point(x+t,y*t); }
    point operator /(double t){ return point(x/t,y/t); }
    double operator *(point q){ return x*q.x+y*q.y; }
    double operator %(point q){ return x*q.y-y*q.x; }

    int cmp(point q) const{
        if(int t= ::cmp(x,q.x)) return t;
            return ::cmp(y,q.y);
    }


    bool operator ==(point q) const { return cmp(q)==0; }
    bool operator !=(point q) const { return cmp(q)!=0; }
    bool operator <(point q) const { return cmp(q)<0; }
    bool operator <=(point q) const { return cmp(q)<=0; }
    friend ostream& operator <<(ostream& o, point p){
        return o << "(" << p.x << ", " << p.y << ")";
    }
    static point pivot;
};

inline int ccw(point p, point q, point r){
    return cmp((p-r)%(q-r));
}

inline point circumcenter(point p, point q, point r){
    point a = p-r, b = q-r, c = point(a*(p+r)/2, b*(q+r)/2);
    return point(c%point(a.y,b.y), point(a.x,b.x)%c)/(a%b);
}

int main(void)
{
    int N;
    int X, Y;
    
    while(scanf("%d", &N) && N) {
        vector<point> pts(N);
        
        REP(i, 0, N) {
            scanf ("%d %d", &X, &Y);
            pts[i] = point((double)X, (double)Y);
        }

        if (N <= 2) {
            printf ("%d\n", N - 1);
            continue;
        }

        int cont, resp = 2, sz;
        REP(i, 0, N - 2) {
            REP(j, i+1, N - 1) {
                vector<point> cc;
                REP(k, j+1, N) {
                    if (ccw(pts[i], pts[j], pts[k]) == 0) continue;
                    cc.push_back(circumcenter(pts[i], pts[j], pts[k]));
                }
                
                sort(ALL(cc));
                sz = SIZE(cc);

                cont = 2;
                if (sz > 1) cont++;

                REP(k,1,sz) {
                    if (cc[k] == cc[k-1])
                        cont++;
                    else
                    {
                        if (resp < cont) resp = cont;
                        cont = 3;
                    }
                }
                if (resp < cont) resp = cont;
            }
        }
        printf ("%d\n", resp);
    }
    return 0;
}

