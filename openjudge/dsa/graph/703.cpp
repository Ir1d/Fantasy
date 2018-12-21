#include <stdio.h>
#include <queue>
using namespace std;
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF&&n)
	{
		queue<long long> q;
		q.push(1);
		while (true)
		{
			long long f=q.front();
			q.pop();
			if (f%n==0)
			{
				printf("%lld\n",f);
				break;
			}
			q.push(f*10);
			q.push(f*10+1);
		}
	}
	return 0;
}
