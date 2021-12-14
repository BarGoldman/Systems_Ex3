#include <stdio.h>
#include <string.h>
#include "str.h"
#define TXT 1024
#define WORD 30 

/*
int main()
{
	
	//char txt[] = "I’m bringing home my baby bumble bee Won’t my Mommy be so proud of me I’m bringing home my baby bumble bee – OUCH!! It stung me!!~";
	char my_string[] = "bee"; 
	//func1(my_string,txt);
	
	
	char txt[] = "vvrv yv yvvm vvy~";
	int length = strlen(my_string);
	//printf("your str: %c\n",my_string[0]);
	
	for(int i = 0 ; i < length ; i++)
	{
		printf("temp : %c\n",my_string[i]);
	}
	

	printf("%s\n",txt);
	func2(my_string,txt);

	
	for(int i = 0 ; i < length ; i++)
	{
		printf("temp : %c\n",my_string[i]);
	}
	
	return 0;
}
*/
int main()
{

	
    // char word[30];
    // memset(word,0,strlen(word));
    // scanf("%c",&word[0]);
    // int i=1;
    // while(i<30)
    // {
    //     scanf("%c",&word[i]);
    //     if(word[i]==' ' || word[i]=='\n' || word[i]=='\t')
    //     {
    //         break;
    //     }
    //     i++;
    // }
    // char txt[1024];
    // memset(txt,0,strlen(txt));
    // scanf("%c",&txt[0]);
    // i=1;
    // while (i<1024)
    // {
    //     scanf("%c",&txt[i]);
    //     if(txt[i]=='~')
    //     {
    //         break;
    //     }
    //     i++;
    // }
    char txt[] = "vvrv yv yvvm vvy~";
    char word[] = "bee"; 
    func2(word,txt, strlen(word), strlen(txt));
    // printf("Gematria Sequences:");
    // func1("bee","I’m bringing home my baby bumble bee Won’t my Mommy be so proud of me I’m bringing home my baby bumble bee – OUCH!! It stung me!!~");
    // printf("Bar\n");
    // char txt[] = "vvrv yv yvvm vvy~";
    // char word[] = "bee";
    // printf("Atbash Sequences:");
    // func2(word,txt);
    // printf("Bar");
    // printf("Anagram Sequences:");
    //func3(word,txt);
    
    return 0;
}

	


