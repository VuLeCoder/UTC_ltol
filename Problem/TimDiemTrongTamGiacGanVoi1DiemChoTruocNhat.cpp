#include <iostream>
#include <vector>
#include <cmath>
#define x first
#define y second
using namespace std;

double distance(pair<double, double> A, pair<double, double> B)
{
	return sqrt((B.x -A.x) * (B.x -A.x) + (B.y -A.y) * (B.y -A.y));
}

double area(pair<double, double> A, pair<double, double> B, pair<double, double> C)
{
	double res = fabs((B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y));
	return res/2;
}

pair<double, double> point(pair<double, double> A, pair<double, double> B, pair<double, double> M)
{
	double ABx = B.x - A.x;
    double ABy = B.y - A.y;
    double t = ((M.x - A.x) * ABx + (M.y - A.y) * ABy) / (ABx * ABx + ABy * ABy);

    double X = A.x + t * ABx;
    double Y = A.y + t * ABy;

    if (t < 0) return A;
    if (t > 1) return B;
    return {X, Y};
}

pair<double, double> solve(const vector<pair<double, double>> &p)
{
	if(area(p[0],p[1],p[3]) + area(p[0],p[2],p[3]) + area(p[1],p[2],p[3]) == area(p[0],p[1],p[2]))
		return p[3];
	
	pair<double, double> D = point(p[0],p[1],p[3]);
	pair<double, double> E = point(p[0],p[2],p[3]);
	pair<double, double> F = point(p[1],p[2],p[3]);
	
	double KcD = distance(D, p[3]);
	double KcE = distance(E, p[3]);
	double KcF = distance(F, p[3]);
	
	double min_dis = (KcD < KcE? KcD : KcE) < KcF ? (KcD < KcE? KcD : KcE) : KcF;
	if(min_dis == KcD) return D;
	if(min_dis == KcE) return E;
	return F;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int q; cin>>q;
	while(q--)
	{
		vector<pair<double, double>> p(4);
		for(int i=0; i<4; ++i)
			cin>>p[i].x>>p[i].y;
		pair<double, double> ans = solve(p);
		printf("%.3lf %.3lf\n",ans.x, ans.y);
	}
}