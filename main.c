#include <stdio.h>
#include <string.h>
#include "str.h"



int main()
{
	
	//char txt[] = "I’m bringing home my baby bumble bee Won’t my Mommy be so proud of me I’m bringing home my baby bumble bee – OUCH!! It stung me!!~";
	char my_string[] = "bee"; 
	//func1(my_string,txt);
	
	
	char txt[] = "vvrv yv yvvm vvy~";
	int length = strlen(my_string);
	//printf("your str: %c\n",my_string[0]);
	/*
	for(int i = 0 ; i < length ; i++)
	{
		printf("temp : %c\n",my_string[i]);
	}
	*/
	printf("%s\n",txt);
	func2(my_string,txt);
	/*
	for(int i = 0 ; i < length ; i++)
	{
		printf("temp : %c\n",my_string[i]);
	}
	*/
	return 0;
}
	


