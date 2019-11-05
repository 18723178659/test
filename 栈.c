#include"stdio.h"
#include"windows.h"
#define MAXLEN 100
typedef int DataType;
typedef struct
{ DataType data[MAXLEN];
  int top;	
}SeqStack;

void InitStack(SeqStack *s)
{s->top=-1;
	
}

void Menu()
{printf("           顺序栈的各种操作        ");
 printf("\n---------------------------------------");
 printf("\n              1.初始化栈             "); 
 printf("\n              2.入栈操作             ");
 printf("\n              3.出栈操作             ");
 printf("\n              4求栈顶元素            ");
 printf("\n              0.返回                 ");	
 printf("\n 请输入：");
}

int EmptyStack(SeqStack *s)
{ 
  if(s->top==-1)
    return 1;
  else
    return 0;
}


int FullStack(SeqStack *s)
{ if(s->top==MAXLEN-1)
   return 1;
  else
   return 0;	
}


void Look(SeqStack *s)
{SeqStack q=*s;
if(EmptyStack(s))
  {printf("看nm看，空的！");
   //写不来了 
  }
  
	
}





int Push(SeqStack *s,DataType x)
{//入栈操作 
  if(FullStack(s))
    {printf("men出来了。进不去了");
     return 0;
	}
   else
   {s->top++;
   s->data[s->top]=x;
   return 1; 	
   }	
}


int Pop(SeqStack *s,DataType *x)
{if(EmptyStack(s))
 {printf("空的，删nm删,逗老子好耍迈");
  return 0;
 }
 else
 {
 	*x=s->data[s->top];
 	s->top--;
 	return 1;
 	
 }	
}


int GetTop(SeqStack *s,DataType *x)
{if(EmptyStack(s))
	{printf("空的空的，cnm，浪费老子时间");
	return 0;
		
	}
  else
  {*x=s->data[s->top];
  return 1;	
  }
}



main()
{int i,n,flag;
  SeqStack s;
  DataType x;
  char ch1,ch2,a;
  ch1='y';
  while(ch1=='y'||ch1=='Y')
  {
  	Menu();
  	scanf("%c",&ch2);
  	getchar();
  	switch(ch2)
  	{
  	  case '1':
		InitStack (&s);
		printf("老子初始化好了！\n");
		break;
		
		
	  case '2':
	    printf("你想入几个？");
		scanf("%d",&n);
		printf("你输入一哈嘛!");
		for(i=0;i<n;i++)
		  { scanf("%d",&x);
		    flag=Push(&s,x); 	
    	  }	
    	  if(flag==1)
    	    printf("祝贺你哈！勒次没出错。\n");
  	      break;
      case '+':
        printf("\n嘿嘿嘿  你竟然看了代码----\n");
        Look(&s);
        break;
        		
  	
	  
	  
	  case '3':
	    printf("你他妈一会儿加一会删，烦不烦");
	    Sleep(3000);
	    printf("\n     哭一个就删");
	    Sleep(5000);
	    
		printf("\n        只许一次哈。删几个");  
	    scanf("%d",&n);
	    printf("删了勒些。。。\n");
		for(i=0;i<n;i++)
		  {flag=Pop(&s,&x);
		   printf("%d ",x);
		  	
          } 
	    if(flag==1)
	      printf("\n已经除脱了\n");
	  	else
	  	printf("哦豁，没除脱\n");
	  	break;
      case '4':
        if(flag=GetTop(&s,&x))
            printf("是:%d",x);
        break;
      
      case '0':
        ch1='n';break;
        
      default:
        printf("\np哈儿，不知字迈？重新给老子选\n");		
	  	
	}
	if(ch2!='0')
	 {printf("\n按回车可以继续，其余的返回菜单！\n");
	   a=getchar();
       if(a!='\xA')
        {
        	getchar();ch1='n';
        }
 		
 	}
  }	
}