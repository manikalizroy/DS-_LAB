#include <stdio.h>
#define size 10

int q[10], f = -1, r = -1,item;
void enque(int item)
{
    if ((r + 1) % size == f)
    {
        printf("q full\n");
        return;
    }
    else
    {
        if (f== -1)
            f=0;
        r=(r+1)%size;
        q[r] = item;
    }
    
}
int deque()
{
    if(f == -1 || f>r)
    {
       printf("q empty");
       return -1;
    }   
        int item = q[f];
        f=(f+1)%size;
        return item;
    
}
int display()
{
    if(f == -1)
        printf("q emty");
    else 
    {
        int i =f;
        while (1) 
        {
            printf("%d ", q[i]);
            if (i == r)
                break;
            i = (i + 1) % size;
        }
        printf("\n");
    }
}
int main() {
    enque(15);
    enque(30);
    enque(45);
    printf("%d\n",deque());
    printf("%d\n",deque());
    printf("%d\n",deque());
    return 0;    
}
