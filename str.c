#include <stdio.h>
#include <string.h>
#include "str.h"
#define TXT 1024
#define WORD 30 


//func 1 :

/*
char my_string[4] = "bee"; 
char txt[] = "vvrmyvvy~";
*/
//Ezer:
void B(char *s, char *t){
	int k = 0; 
	int key = 0;
	int i = 0 , j =0;
	char str[]= "";
	while (t[i] != '~')
	{
		if(strlen(str) == strlen(s))
		{
			for(int i = 0 ; i < strlen(str) ; i++)
			{
			 printf("your str: %c\n",str[i]);	
			}
			memset(str,0,strlen(str));
			j=0 , key = 0 , k=0;
		}
	 	if(s[j] == t[i])
		{
			if (strlen(str) == 0 || key == 0)
			{
				str[k] = t[i];
				k++;
				j++;
				key = 0;
		
			}
		}	
		else if(s[strlen(s)-1-j] == t[i] && strlen(s) > j && j >= 0)
		{
			if(strlen(str) == 0 || key == 1)
			{
				str[k] = t[i];
				k++;
				j++;
				key = 1;
			}
		}
		else
		{
			memset(str,0,strlen(str));
			k=0;
			key = 0;
			j=0;
		}
		printf("%d/n",j);
		i++;
	}
	return;
}



//func 2:
void func2(char *s,char *t)
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
			j = a - s[i] ; 
			s[i] = z + j ;
		}
		else if(s[i] >= A && s[i] <= Z)
		{
			j = A - s[i] ;
			s[i] = Z + j ;	
		}
	}
	B(s,t);
	return;
}

//func 3:



