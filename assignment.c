#define MAX 30
#include<stdio.h>
void create(int set[]);
void print(int set[]);
void Union(int array1[],int array2[],int array3[]);
void intersection(int array1[],int array2[],int array3[]);
void difference(int array1[],int array2[],int array3[]);
void symmdiff(int array1[],int array2[],int array3[]);
int member(int set[],int x);


int main()
{ int array1[MAX],array2[MAX],array3[MAX];
  int x,op;
  array1[0]=0;array2[0]=0;array3[0]=0;
  printf("\nEnter set1:");
  create(array1);
  print(array1);
  printf("\nEnter set2:");
  create(array2);
  print(array2);


  do
   { printf("\n1)Union\n2)Intersection\n3)Difference");
     printf("\n4)Symmetrec Difference \n5)Quit");
     printf("\nEnter Your Choice:");
     scanf("%d",&op);
     switch(op)
      {
    case 1:
     Union(array1,array2,array3);
     print(array3);
     break;
    case 2: 
    intersection(array1,array2,array3);
    print(array3);
    break;
    case 3: 
    difference(array1,array2,array3);
    print(array3);
    break;
    case 4: 
    symmdiff(array1,array2,array3);
    print(array3);
    break;
     }
  }while(op!=5);
 }

 

 void create(int set[])
   {   int n,i,x;
       set[0]=0;
       printf("\n No. of elements in the set:");
       scanf("%d",&n);
       printf("\n enter set elements :");
       for(i=1;i<=n;i++)
       scanf("%d",&set[i]);
       set[0]=n; 

   }

 void  print(int set[])
  { int i,n;
    n=set[0];
    printf("\nMembers of the set :-->");
    printf("{");
    for(i=1;i<=n;i++)
       printf("%d  ",set[i]);
    printf("}");
  }

void Union(int array1[],int array2[],int array3[])
  { int i,n;
    array3[0]=0;
    n=array1[0];
    
    for(i=0;i<=n;i++)
    {array3[i]=array1[i];}

    n=array2[0];
    for(i=1;i<=n;i++)
    {
       if(!member(array3,array2[i]))
      {  array3[++array3[0]]=array2[i];}
    }  
   }

 int member(int set[],int x)
  { int i,n;
    n=set[0]; 
    for(i=1;i<=n;i++)
    {
    if(x==set[i])
     {
       return(1);
     }
    }

     return(0);
  }
void intersection(int array1[],int array2[],int array3[])
     {
    int i,n;
    array3[0]=0;
    n=array1[0];
    for(i=1;i<=n;i++)
      {
        if(member(array2,array1[i])) 
          {
             array3[++array3[0]]=array1[i]; 
          } 
      }
     }



void difference(int array1[],int array2[],int array3[])
      { int i,n;
    n=array1[0];
    array3[0]=0;
    for(i=1;i<=n;i++)
    {
       if(!member(array2,array1[i]))
       {
         array3[++array3[0]]=array1[i]; 
        }
     }
      }

 void symmdiff(int array1[],int array2[],int array3[])
      { int i,n;
    n=array1[0];
    array3[0]=0;
    for(i=1;i<=n;i++)
       {if(!member(array2,array1[i]))
       array3[++array3[0]]=array1[i];
       }  
    n=array2[0];
    for(i=1;i<=n;i++)
    {
       if(!member(array1,array2[i]))
         array3[++array3[0]]=array2[i];
    }

      }
