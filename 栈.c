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
{printf("           ˳��ջ�ĸ��ֲ���        ");
 printf("\n---------------------------------------");
 printf("\n              1.��ʼ��ջ             "); 
 printf("\n              2.��ջ����             ");
 printf("\n              3.��ջ����             ");
 printf("\n              4��ջ��Ԫ��            ");
 printf("\n              0.����                 ");	
 printf("\n �����룺");
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
  {printf("��nm�����յģ�");
   //д������ 
  }
  
	
}





int Push(SeqStack *s,DataType x)
{//��ջ���� 
  if(FullStack(s))
    {printf("men�����ˡ�����ȥ��");
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
 {printf("�յģ�ɾnmɾ,�����Ӻ�ˣ��");
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
	{printf("�յĿյģ�cnm���˷�����ʱ��");
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
		printf("���ӳ�ʼ�����ˣ�\n");
		break;
		
		
	  case '2':
	    printf("�����뼸����");
		scanf("%d",&n);
		printf("������һ����!");
		for(i=0;i<n;i++)
		  { scanf("%d",&x);
		    flag=Push(&s,x); 	
    	  }	
    	  if(flag==1)
    	    printf("ף��������մ�û����\n");
  	      break;
      case '+':
        printf("\n�ٺٺ�  �㾹Ȼ���˴���----\n");
        Look(&s);
        break;
        		
  	
	  
	  
	  case '3':
	    printf("������һ�����һ��ɾ��������");
	    Sleep(3000);
	    printf("\n     ��һ����ɾ");
	    Sleep(5000);
	    
		printf("\n        ֻ��һ�ι���ɾ����");  
	    scanf("%d",&n);
	    printf("ɾ����Щ������\n");
		for(i=0;i<n;i++)
		  {flag=Pop(&s,&x);
		   printf("%d ",x);
		  	
          } 
	    if(flag==1)
	      printf("\n�Ѿ�������\n");
	  	else
	  	printf("Ŷ��û����\n");
	  	break;
      case '4':
        if(flag=GetTop(&s,&x))
            printf("��:%d",x);
        break;
      
      case '0':
        ch1='n';break;
        
      default:
        printf("\np��������֪���������¸�����ѡ\n");		
	  	
	}
	if(ch2!='0')
	 {printf("\n���س����Լ���������ķ��ز˵���\n");
	   a=getchar();
       if(a!='\xA')
        {
        	getchar();ch1='n';
        }
 		
 	}
  }	
}