#include<stdio.h>
#include<string.h>
#include<time.h>
main()
{
	char s1[10][20],s2[10][20];
	int i,n,l,j,c,k,x;
	char ch,cr,cc;
	
	for(k=0;k<5;k++)
	{
	printf("Enter word : ");
	gets(s1[k]);
	
	}
	y:
	srand(time(0));
	
	x=rand()%5;
	printf("For %d string is %s",x,s1[x]);
	printf("\nEnter its anagram: ");
	gets(s2[x]);
	n=strlen(s1[x]);
	l=strlen(s2[x]);
	c=0;
	if(n==l)
	{ 
	for(i=0;i<n;i++)
	{
		ch=s1[x][i];
		for(j=0;j<n;j++)
		{
			cr=s2[x][j];
			if(ch==cr)
			{
				c++;
				break;
			}
			else
			{
				c=0;
			}
		}
	}
	if(c==0)
	{
		printf("\nThey are not anagram");
	}
	else
	{
		printf("\nThey are anagram");
	}
    }
    else
    {
    	printf("\nThey are not anagram");
	}
	printf("\nDo you want to play again?(Enter Y or N): ");
	scanf("%c",&cc);
	if(cc=='Y' || c=='y')
	goto y;
	else
	printf("\nGAME OVER");
}
