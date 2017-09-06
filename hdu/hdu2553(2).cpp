#include <iostream>
#include <cstdio>
using namespace std;
int sum,upperlim,n;
int ans[15];
void queen(int row, int ld, int rd)
{
	int pos,p;
	if(row != upperlim)
	{
		pos = upperlim & (~(row | ld | rd));
		while(pos != 0)
		{
			p = pos & (-pos);
			pos = pos - p;
			queen(row+p, (ld+p)<<1, (rd+p)>>1);
		}
	}
	else
		sum++;
}
int main()
{
	for(int i=1; i<=10; i++)
	{
		upperlim = (1 << i) - 1;
		sum = 0;
		queen(0,0,0);
		ans[i] = sum;
	}
	while(scanf("%d",&n),n)
	{
		cout<<ans[n]<<endl;
	}
	return 0;
}
