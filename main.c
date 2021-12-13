#include <stdio.h>
#include <string.h>
#include "str.h"



int main()
{
	char my_string[4] = "bee"; 
	char txt[] = "vvrmyvvy~";
	char str[] = "vvrmvvy~";
	memset(str,0,strlen(str));
	int length = strlen(my_string);
	for(int i = 0 ; i < length ; i++)
	{
		printf("temp : %c\n",my_string[i]);
	}
	func2(my_string,txt);
	/*
	for(int i = 0 ; i < length ; i++)
	{
		printf("temp : %c\n",my_string[i]);
	}
	*/
	return 0;
}
	


