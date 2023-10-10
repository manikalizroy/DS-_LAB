#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define size 25

char s[25];
int top = -1;

void push(char item)
{
    if(top==size - 1)
        printf("overflow\n");
    else
    {
        top++;
        s[top] = item;
    }
    
char pop()
{
    if(top== -1)
    {
        printf("empty\n");
      //  return '\0';
    }    
    else
    {
        int item;
        item = s[top];
        top -=1;
        return item;
    }
}  

int isp(char ch)
{
    switch (ch)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;
        case '(': return 0;
    }

}

int icp(char ch)
{
    switch (ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6;
        case '(': return 7;
        case ')': return 0;
    }
}

int i = 0;
//while(ch[i]!='\0')
{
void infixToPostfix(char exp[],char post[])
{
    int postind = 0;
    int i=0;
    char item,op;
    push('(');
    //strcat(exp,')');
    
    while(exp[i]!= '\0')
    {
        item = exp[i];
        op = s[top];
        
        if((item >='a'&& item <= 'z') || (item >='A'&& item <= 'Z') || (item >='0'&& item <= '9' ))
        {
            post[postind++] = item;
         }
        else if(item == '(')
        {
            push(item);
        }
        else if(item == ')')
        {
            while(op != '(')
            {
               post[postind++] = op;
            }
        pop();
        }
        
        else
        {
            while(isp(item)>=isp(op))
            {
                op = pop();
                post[postind++] = op;
            }
        push(item);    
        }
        i++;
    }
    
    while(top >= 0 && s[top] != '(')
    {
        post[postind++] = pop();
    }
    post[postind] = '\0';
    
}

int evaluate(char post[])
{
    char s[25];
    int i = 0,top= -1;
    
    while(post[i]!='\0')
    {
        char item = post[i];
        if(isdigit(item))
        {
            push(item - 0);
        }
        else if(isoperator(item))
        {
            int op2 = pop();
            int op1 = pop();
            switch (item)
            {
                case '+': push(op1 + op2);
                        : break;
                case '-': push(op1 - op2);
                        : break;
                case '*': push(op1 * op2);
                        : break;
                case '/': push(op1 / op2);
                        : break;
                case '^': push(op1 ^ op2);
                        : break;
            }
        }i++;
    }
    
    return pop();
}
    

int main()
{
    char exp[25],post[25];
    int result;
    
    printf("enter infix exp: \n");
    scanf("%[^\n]",exp);
    
    infixToPostfix(exp,post);
    printf("postfix exp is : %s\n",post);
    
    result = evaluate(post);
    printf("result: %d\n",post);
    
    return 0;
}

