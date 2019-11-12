#include"stdio.h"

int ab(int a,int b,int(*p)(int,int))
  {int c;
  c=(*p)(a,b);
  	printf("%d\n",c);
  }


int max(int a,int b)
{if(a>b)
  return a;
  else 
  return b;
	
}
int min(int a,int b)
{if(a>b)
  return b;
 else 
 return a;
	
}

main()
{int (*p)(int,int);
	
	int a,b;
	scanf("%d%d",&a,&b);
	ab(a,b,max);
	ab(a,b,min);
	
} 
