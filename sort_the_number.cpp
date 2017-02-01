//problem statment: https://omegaup.com/arena/problem/AcomodandoOMI#problems

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  int n, num, ans, origin;

  while(scanf("%d",&n) != EOF)
  {
    ans = 0;
    scanf("%d",&origin);

    for(int i = 1; i < n; i++)
    {
      scanf("%d",&num);
      if(num < origin) ans++;
    }

    printf("%d\n",ans);
  }

  return 0;
}