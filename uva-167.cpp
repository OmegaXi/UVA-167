#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int arr[8][8],c[8];
int sum;

void search(int cur, int d)
{
	if(cur==8)
	{
		if(d>sum)
			sum=d;
	}
	else
		for(int i=0;i<8;i++)
		{
		int ok=1;
		c[cur]=i;//尝试把第cur行的皇后放在第i列
		for(int j=0;j<cur;j++)//检查是否与之前的皇后冲突
			if(c[cur]==c[j]||cur-c[cur]==j-c[j]||cur+c[cur]==j+c[j])
			{
				ok=0;
				break;
			}
		if(ok)
		{
			search(cur+1,d+arr[cur][i]);
		}
	}
}

main()
{
	int n;
	cin>>n;
	while(n--)
	{
		sum=0;
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				cin>>arr[i][j];
		search(0, 0);
		printf("%5d\n", sum);
}
}
