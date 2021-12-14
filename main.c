#include <stdio.h>
#include <string.h>
#include "str.h"


int main()
{
    char word[30];
    memset(word,0,strlen(word));
    scanf("%c",&word[0]);
    int i=1;
    while(i<30)
    {
        scanf("%c",&word[i]);
        if(word[i]==' ' || word[i]=='\n' || word[i]=='\t')
        {
            break;
        }
        i++;
    }
     char txt[1024];
    memset(txt,0,strlen(txt));
    scanf("%c",&txt[0]);
    i=1;
    while (i<1024)
    {
        scanf("%c",&txt[i]);
        if(txt[i]=='~')
        {
            break;
        }
        i++;
    }
    printf("Gematria Sequences:");
    func1("bee","I’m bringing home my baby bumble bee Won’t my Mommy be so proud of me I’m bringing home my baby bumble bee – OUCH!! It stung me!!~");
    printf("Atbash Sequences:");
    //func2("bee","vvrv yv yvvm vvy~");
    printf("Anagram Sequences:");
    //func3(word,txt);
    
    return 0;
}

	


