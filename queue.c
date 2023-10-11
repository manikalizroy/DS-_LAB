#include <stdio.h>
#define size 10

int q[10], f = -1, r = -1,item;
void enque(int item)
{
    if (r == size - 1)
    {
        printf("q full\n");
        return;
    }
    else
    {
        if (f== -1)
            f=0;
        r++;
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
    else
    {
        int item = q[f];
        f++;
        return item;
        
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
