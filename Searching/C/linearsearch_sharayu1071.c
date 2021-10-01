// Program to implements Linear Search On Array:
#include<stdio.h>
void main()
{
 int a[10]={30,20,30,40,67,30,89,30,12,25};  //input already given
 int item,n=10,pos;
 printf("\nArray elements are..\n");
 for(pos=0;pos<n;pos++)
 printf("%d ",a[pos]);
 printf("\n\nEnter the number to search in the array ");
 scanf("%d",&item);
 pos=0;
 int c=0;
 while(pos<n) //finding number in given array
 {
 if(a[pos]==item){
     c++;
    printf("\n %d is found at %d position",item,pos);
   }
   pos++;
 }
 if(c==0){
 printf("\n%d is not found in the array",item);
 }
  printf("\n %d found %d times in the array",item,c);
}
