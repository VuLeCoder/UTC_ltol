#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct SinhVien{
	string ten = "";
	string khoa = "";
	int diem = 0;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n; cin>>n;
	cin.ignore();
	
	SinhVien a[n];
	for(int i=0; i<n; ++i)
	{
		string info; getline(cin, info);
		
		int index = info.length()-1, pos;
		for(int j=index; j>=0; --j)
		{
			if(info[j] == ' ') {pos = j-1; break;}
			a[i].khoa += info[j];
		}
	
		index = pos;
		int cnt = 0;
		for(int j=index; j>=0; --j)
		{
			if(info[j] == ' ') {pos = j-1; break;}
			a[i].diem += (info[j] - '0') * pow(10, cnt);
			cnt++;
		}
		
		for(int j=0; j<=pos; ++j) a[i].ten += info[j];
	}
	
	sort(a, a+n, [](SinhVien &x, SinhVien &y){
		return x.diem > y.diem;
	});
	
	int cnt = 0;
	for(int i=0; i<n; ++i)
	{
		if(a[i].khoa == "TDD")
		{
			switch(cnt)
			{
				case 0:
					cout << "Giai nhat :" << a[i].ten << "\n";
					break;
					
				case 1:
					cout << "Giai nhi :" << a[i].ten << "\n";
					break;
				
				case 2:
					cout << "Giai ba :" << a[i].ten << "\n";
					break;
			}
			cnt++;
		}
		if(cnt == 3) break;
	}
	
	for(int i=0; i<n; ++i)
		if(a[i].khoa != "TDD")
		{
			cout << "Giai giao luu :" << a[i].ten;
			break;
		}
	
	return 0;
}
