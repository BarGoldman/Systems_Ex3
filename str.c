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

void print(char *str,int len,int key)
{
	int m=0;
    if(key!=0)
    {
        printf("~");
    }
    for(int i = 0 ; i < len ; i++)
    {
        int ans = gimat(str[i]);
        if(m==0 && ans==0)
        {
            continue;
        }
        printf("%c",str[i]);
		m=1;
    }
	return;
}
    
int len(char *s,int len)
{
	int count=0;
	for(int i=0;i<len;i++)
	{
		if(gimat(s[i])==0)
		{
			continue;
		}
		count++;
	}
	return count;
}

void func1(char *word,int len_w,char *txt,int len_t)
{
	int sum=0;
	int i=0;
    while(i<len_w)
    {
		sum+=gimat(word[i]);
		i++;
    }
    i=0;
    int j=0;
    int k=0;
    int count=0;
    int key=0;
    char s[TXT];
	memset(s,0,strlen(s));
    while (txt[i]!='~')
    {
        int ans=gimat(txt[i]);
        int temp=count;
        if(temp+ans<sum)
        {
	        if(strlen(s)==0 && txt[i+1]!='~')
            {
				int m=i;
				while(txt[m]!='~')
				{
					if(gimat(txt[m])!=0 )
					{
						k=m+1;
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
			s[1]='\0';
            print(s,strlen(s),key);
            key++;
            memset(s,0,strlen(s));
            count=0;
            j=0;
            i++;
        }
         else if(temp+ans==sum)
        {
            s[j]=txt[i];
			s[j+1]='\0';
            print(s,strlen(s),key);
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

}

void func2(char *w,int len_w,char *txt,int len_t)
{
	int i;
	char word[len_w];
	memset(word,0,len_w);
	for(i = 0 ; i < len_w ;i++)
	{
		if(w[i] >= 'a' && w[i] <= 'z')
		{
			char temp = w[i];
			word[i] = 'z'-temp+'a';
		}
		else if(w[i] >= 'A' && w[i] <= 'Z')
		{
			char temp = w[i];
			word[i] = 'Z'-temp+'A';	
		}
	}
	char str[WORD];
	memset(str,0,strlen(str));
	int key=0;
	i=0;
	int j=0;
	int k=0;
	int r=0;
	int ind=0;
	int wo=0;
	while(txt[i]!='~')
	{
		ind=0;
		if(strlen(str)==0)
        {
			int m=i+1;
			while(txt[m]!='~')
			{
				if(gimat(txt[m])!=0)
				{
					r=m;
					break;
				}
				m++;
			}
			if(txt[m]=='~')
			{
				r=m;
			}
		}	
		if(len(str,strlen(str))==len_w)
	 	{
			str[j]='\0';
			print(str,strlen(str),k);
			memset(str,0,strlen(str));
			k++;
			j=0;
			i=r;
		}
		else if(txt[i]==word[wo] || txt[i]==word[len_w-wo-1])
		{
			if(txt[i]==word[wo])
			{
				if(strlen(str)==0)
				{
					ind=1;
					str[j]=txt[i];
					i++;
					j++;
					key=0;
					wo++;
				}
				else if(key==0)
				{
					ind=1;
					str[j]=txt[i];
					i++;
					j++;
					wo++;
				}
				if(len(str,strlen(str))==len_w)
				{
					str[j]='\0';
					print(str,strlen(str),k);
					memset(str,0,strlen(str));
					k++;
					j=0;
					i=r;
					wo=0;
				}
			}
			if(txt[i]==word[len_w-wo-1])
			{
				if(strlen(str)==0)
				{
					ind=1;
					str[j]=txt[i];
					i++;
					j++;
					wo++;
					key=1;
				}
				else if(key==1)
				{
					ind=1;
					str[j]=txt[i];
					i++;
					j++;
					wo++;
					key=1;
				}
				if(len(str,strlen(str))==len_w)
				{
					str[j]='\0';
					print(str,strlen(str),k);
					memset(str,0,strlen(str));
					k++;
					j=0;
					i=r;
					wo=0;
				}
			}
			if(ind==0)
			{
				i=r;
				memset(str,0,strlen(str));
				j=0;
				wo=0;
			}
		}
		else if(gimat(txt[i])==0 && strlen(str)!=0)
		{
			str[j]=txt[i];
			i++;
			j++;
			
		}
		else
		{
			i=r;
			memset(str,0,strlen(str));
			j=0;
			wo=0;
		}

	}
	
}

int contain(char *word,int len,char c)
{
	for(int i=0;i<len;i++)
	{
		if(word[i]==c)
		{
			return 1;
		}
	}
	return 0;
}

int how_many(char *word,int len,char c)
{
	int count=0;
	for(int i=0;i<len;i++)
	{
		if(word[i]==c)
		{
			count++;
		}
	}
	return count;
}

void func3(char *word,int len_w,char *txt,int len_t)
{
	char s[WORD];
	memset(s,0,strlen(s));
	int i=0;
	int j=0;
	int r=0;
	int key=0;
	while(txt[i]!='~')
	{
		if(strlen(s)==0)
        {
			int m=i;
			while(txt[m]!='~')
			{
				if(gimat(txt[m])!=0)
				{
					r=m+1;
					break;
				}
				m++;
			}
			if(txt[m]=='~')
			{
				r=m;
			}
		}	
		if(len(s,strlen(s))<len_w)
		{
			if(contain(word,len_w,txt[i])==1 || txt[i]==' ')
			{
				int c1=how_many(word,len_w,txt[i]);
				int c2=how_many(s,strlen(s),txt[i]);
				if(c2<c1)
				{
					s[j]=txt[i];
					if(len(s,strlen(s))==len_w)
					{
						s[j+1]='\0';
						print(s,strlen(s),key);
						key++;
						j=0;
						i=r;
						memset(s,0,strlen(s));
					}
					else
					{
						i++;
						j++;
					}
				}
				else if(txt[i]== ' ')
				{
					s[j]=txt[i];
					i++;
					j++;
				}
				else
				{
					i=r;
					memset(s,0,strlen(s));
					j=0;
				}
			}
			else if(strlen(s)==0)
			{
				j=0;
				i++;
				memset(s,0,strlen(s));
			}
			else
			{
				i=r;
				memset(s,0,strlen(s));
				j=0;
			}
		}
		else if(len(s,strlen(s))==len_w)
		{
			s[j]='\0';
			print(s,strlen(s),key);
			key++;
			j=0;
			i=r;
			memset(s,0,strlen(s));
		}
		else
		{
			j=0;
			i=r;
			memset(s,0,strlen(s));
		}
	}		
	
}