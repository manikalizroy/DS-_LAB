#include <stdio.h>
#include <string.h>


int longsub(char* s)
{
    int len = strlen(s);
    int maxlen = 0,start = 0,i;
    int charindex[128];
    int startindex=0;
    
    for(i = 0;i < 128;i++)
    {
        charindex[i] = -1;
    }
    
    for(i = 0;i < len;i++)
    {
        if(charindex[s[i]] >= start)
 //Check if the character s[i] has been encountered before within the current substring. This is done by comparing charindex[s[i]] with the current start index. If charindex[s[i]] is greater than or equal to start, it means the character s[i] has been encountered again within the current substring.
        {
            start = charindex[s[i]] + 1;
//If a repeating character is found, update the start index to charindex[s[i]] + 1. This effectively shifts the starting point of the current substring just after the last occurrence of the repeating character, ensuring there are no repeating characters in the current substring.
            
        }
        charindex[s[i]] = i;
        //Update charindex[s[i]] to the current index i to keep track of the last index at which the character was encountered.
        int currentlen = i-start+1;
        //Calculate the length of the current substring with no repeating characters as i - start + 1.
        if(currentlen > maxlen)
        {
            maxlen = currentlen;
            startindex = start;
        }
    }
    printf("Longest substring with no repeating characters: ");
    for (i = startindex; i < startindex + maxlen; i++) 
    {
        printf("%c", s[i]);
    }
    printf("\n");
    return maxlen;
}

int main() 
{
    char s[20];
    printf("enter a string\n");
    scanf("%s",s);
    int result = longsub(s);
    printf("Length of longest substring with no repeating characters: %d\n", result);

    return 0;
}
