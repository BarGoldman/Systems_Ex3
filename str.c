#include <stdio.h>
#define TXT 1024
#define WORD 30 
#include <string.h>
#include "Str.h"


//func 1 :



//Ezer:




//func 2:
void func2(char *s)
{
	int i , j;
	int a = 97;
	int z = 122;
	int A = 65;
	int Z = 90; 
	int length = strlen(s);
	for(i = 0 ; i < length ;i++)
	{
		if(s[i] >= a && s[i] <= z)
		{
		j = a - s[i] ; //-4
		s[i] = z + j ;
		}
		else if(s[i] >= A && s[i] <= Z)
		{
		j = A - s[i] ; //-4
		s[i] = Z + j ;	
		}
		printf("your 2 temp : %c\n",s[i]);
	}

	return;
}

//func 3:


int main()
{
	char my_string[4] = "BEE"; 
	int length = strlen(my_string);
	for(int i = 0 ; i < length ; i++){
		printf("temp : %c\n",my_string[i]);
	}
	func2(my_string);
	for(int i = 0 ; i < length ; i++){
		printf("temp : %c\n",my_string[i]);
	}
	return 0;
}

