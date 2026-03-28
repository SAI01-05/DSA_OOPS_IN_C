#include <stdio.h>
#include <stdlib.h>
struct saiarray
{
      int total_size;
      int used_size;
      int *ptr;
};

void createArray(struct saiarray *s,int tsize,int usize)
{
     (*s).total_size=tsize;
     (*s).used_size=usize;
     (*s).ptr=(int *)malloc(tsize*sizeof(int));
}

void setdata(struct saiarray *s)
{ 
      
      for (int i = 0; i < s->used_size; i++)
      {
            printf("Enter the values of index %d\n",i);
            scanf("%d",&s->ptr[i]);
            
      }
      
}

void printdata(struct saiarray *t)
{
      for (int i = 0; i < t->used_size; i++)
      {
            printf("The values at index %d are %d\n",i,t->ptr[i]);
      }
      
}

int main()
{
      struct saiarray sai;
      createArray(&sai,10,3);
      setdata(&sai);
      printdata(&sai);
      return 0;
}