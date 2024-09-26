#include "stdio.h"
#include "conio.h"
int thoa_man(int a, int b, int c, int d);
void muoi_hai(int x, int [20], int&); 
int A[20], B[20], C[20], D[20];
main()
{
  int a,b,c,d, dA, dB, dC, dD;int ma, i;
  printf("\n Nhap a, b, c, d: "); scanf("%d%d%d%d",&a,&b,&c,&d );
  muoi_hai(a, A, dA); 	muoi_hai(b, B, dB);
  muoi_hai(c, C, dC);   muoi_hai(d, D, dD);
  ma = dA; if(ma<dB) ma=dB; if(ma<dC) ma=dC;if(ma<dD) ma=dD; // ma = max(dA,dB,dC,dD)
  int co_nghiem = 1;
  for(i=1;i<=ma;++i) 
    if ( thoa_man(A[i], B[i], C[i], D[i]) == 0)  
        {
        	co_nghiem = 0; break;
		}
  if (co_nghiem == 1)
    printf("Yes\n");
  else
    printf("No\n");
}

void muoi_hai(int x, int X[20], int &dem) // Doi tu he muoi ra he 2
{
	dem=0; 
	while(x>1)
	{
		dem=dem+1;
		X[dem]= x % 2;
		x = x/2;
	}
	dem = dem + 1; X[dem]=1;	
}
int thoa_man(int a, int b, int c, int d)
{
	int dk1,dk2,dk3,dk4;
	dk1 = (a==0)&&(c==0)&&(d==0);
	dk2 = (a==0)&&(c==1)&&(b==d);
	dk3 = (a==1)&&(c==0)&&(b==1)&&(d==0);
	dk4 = (a==1)&&(c==1)&&(b==1);
	if(dk1 || dk2 || dk3 || dk4) 
  	     return 1;
	else
	     return 0;
}