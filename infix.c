#include <stdio.h>

void push(char x)
{
    stack[++top] = x;
}

void pop(char x)
{
    int store;
    store = c[top];.
    top -=1;
}

int precedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '\': return 2;
        case'^' : return 3;        
    }
    return -1;
}

int len,i = 0;
int findlen(char ch)
{
    while(ch[i]!='\0')
        len++;
}


    

int main()
{
    char exp[25] = "a*(b+c)*d";
    
    
    
    
}
