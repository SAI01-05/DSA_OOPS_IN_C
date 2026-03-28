#include<stdio.h>
int linearSearch(int sai[],int size,int element)
{
    for (int i = 0; i < size; i++)
    {
        if (sai[i]==element)
        {
            return i;
        } 
    }
    return -1;
}

int main()
{
    int element=9;
      int sai[5]={5,7,4,8,6};
      int size=sizeof(sai)/sizeof(int);
      int result=linearSearch(sai,size,element);
      printf("The element %d was found at index no %d\n",element,result);
      return 0;
}