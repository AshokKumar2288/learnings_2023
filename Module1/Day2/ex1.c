#include<stdio.h>  
  
int biggest(int, int); 
  
int main()  
{  
    int a, b;  
  
    printf("Enter 2 integer numbers\n");  
    scanf("%d%d", &a, &b);  
  
    int c= biggest(a, b);
    printf("Biggest is %d\n",c);  
  
    return 0;  
}  
  
int biggest(int x, int y)  
{  
    if(x>y)
    return x;
    else
    return y;
}  
