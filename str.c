#include <stdio.h>
#include <string.h>
#include "str.h"
#define TXT 1024
#define WORD 30 


int gimat(char c)
{
    int ans=0;
    if(c<=90 && c>=65)
    {
        ans=c-'A'+1;
    }
    else if(c<=122 && c>=97)
    {
        ans=c-'a'+1;
    }
    return ans;
}

void print(char *str,int key)
{
    if(key!=0)
    {
        printf("~");
    }
    for(int i = 0 ; i < strlen(str) ; i++)
    {
        int ans = gimat(str[i]);
        if(i==0 && ans==0)
        {
            continue;
        }
        if(i==strlen(str)-1 && ans==0)
        {
            continue;
        }
        printf("%c",str[i]);
    }
    
}


//1 :
    void func1(char *word,char *txt)
    {
        int sum=0;
        int i=0;
        while(i<strlen(word))
        {
            if(word[i]<=90 && word[i]>=65)
            {
                sum+=word[i]-'A'+1;
            }
            else if (word[i]<=122 && word[i]>=97)
            {
                sum+=word[i]-'a'+1;
            }
            i++;
        } // bee =12 ;sum = 12 ;
        i=0;
        int j=0;
        int k=0;
        int count=0;
        int key=0;
        char s[1024];
        memset(s,0,strlen(s));
        while (txt[i]!='~')
        {
            int ans = gimat(txt[i]);
            int temp = count;
            if(temp+ans<sum) //0+ 12
            {
                if(strlen(s)==0 && txt[i]!='~')
                {
                    int m=0;
                    if(ans==0)
                    {
                        m=i+2;
                    }
                    else
                    {
                     m=i+1;
                    }
                    while (txt[m]!='~')
                    {
                        int ans2=gimat(txt[m]);
                        if(ans2!=0)
                        {
                            k=m;
                            break;
                        }
                        m++;
                    }
                }
                count+=ans;
                s[j]=txt[i];
                j++;
                i++;
            }
             else if(ans==sum)
            {
                memset(s,0,strlen(s));
                s[0]=txt[i];
                print(s,key);
                key++;
                memset(s,0,strlen(s));
                count=0;
                j=0;
                i++;
            }
             else if(temp+ans==sum)
            {
                s[j]=txt[i];
                print(s,key);
                key++;
                memset(s,0,strlen(s));
                count=0;
                j=0;
                i=k;
            }
            else if(ans>sum)
            {
                memset(s,0,strlen(s));
                count=0;
                j=0;
                i++;
            }
            else if(temp+ans>sum)
            {
                memset(s,0,strlen(s));
                count=0;
                j=0;
                if(txt[i+1]=='~')
                {
                    i++;
                }
                else
                {
                    i=k;
                }
            }
        }
        printf("\n");
    
}


///////////////////////2//////////////////////////

/*
char my_string[] = "bee"; 
char txt[] = "vvrmyvvy~";
*/

int Z(char *s){
	int ans = 0 ; 
	int i = 0 ;
	for(i = 0 ; i < strlen(s) ; i++){
		if(s[i] >= 97 && s[i] <= 122)
		{
			ans++;
		}
		else if(s[i] >= 65 && s[i] <= 90)
		{
			ans++;	
		}
	}
	return ans;	
}

//Ezer:
void B(char *s, char *t)
{
	printf("temp : %d\n",2);
	int k = 0; 
	int key = 0;
	int i = 0 , j =0;
	char str[1024];
	memset(str,0,strlen(str));
	int leg =  strlen(s);
	printf("temp : %d\n",3);
	while (t[i] != '~')
	{
		printf("KEY : %d\n",key);
		if(Z(str) == leg)
		{	
			print(str,0);
			printf("\n");	
			memset(str,0,strlen(str));
			j=0 , key = 0 , k=0;
		}
		if(s[j] == t[i] && key == 0)
		{
			printf("temp : %d\n",4);
			printf("str : %ld\n",strlen(str));
			printf("KEY : %d\n",key);
			if (str[0] == 0 || key == 0)
			{
				printf("temp : %d\n",44);
				str[k] = t[i];
				k++;
				j++;
				key = 0;	
			}
		}	
		else if(s[leg-1-j] == t[i])
		{
			printf("temp : %d\n",5);
			printf("str : %ld\n",strlen(str));
			if(str[0] == 0 || key == 1)
			{
				printf("temp : %d\n",55);
				str[k] = t[i];
				k++;
				j++;
				key = 1;
			}
		}		
		else
		{
			if(t[i] == ' ' && str[0] != 0)
			{
				printf("temp : %d\n",9);
				str[k] = t[i];
				k++;	
			}
			else
			{
				printf("temp : %d\n",6);
				memset(str,0,strlen(str));
				k = 0;
				key = 0;
				j=0;	
			}
		}
		i++;
	}
	if(Z(str) == leg)
	{
		print(str,0);
		printf("\n");
	}
	return;
}

//func 21:
void func2(char *s,char *t)
{
	int i , j;
	for(i = 0 ; i < WORD ;i++)
	{
		if(s[i] >= 97 && s[i] <= 122)
		{
			j = 97 - s[i] ; 
			s[i] = 122 + j ;
		}
		else if(s[i] >= 65 && s[i] <= 90)
		{
			j = 65 - s[i] ;
			s[i] = 90 + j ;	
		}
	} 
	B(s,t);
}

/*
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
	} // bee == yvv 
	char ans[2*length+1];
	int h =0;
	for(int j = 0 ; j < length;j++){
		ans[j] = s[j]; 
		h=j;
	}
	h++;
	ans[h] = ' ';
	h++;
	int k = length-1;
	while(h<=2*length && k >= 0){
		ans[h] = s[k];
		h++;
		k--; 
	}
	printf("%s\n" , ans );
	/*
	ans[0] == s ;
	char str[]= "";
	for(int j = 0 ; j < length ;j++){
		str[j] == s[length-1-j];
	}
	ans[1] == str;
	printf("%s\n" , ans );
	B(ans,t);
	return;
	
}
*/


//func 3:



