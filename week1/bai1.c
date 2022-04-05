#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARRAY 10000

typedef struct word {
	char str[100];
	int count;
} word;

word wordArr[1000];

void setWordArray()
{
	int i;
	for(i = 0; i < MAX_ARRAY; i++)
		wordArr[i].count = 0;
}

	int max_word = 0;

void search(char *str)
{
	int check=0;
	int i=0;
	for(i=0;i<max_word;i++)
	{
		if ( strcmp(wordArr[i].str,str ) ==1 )
		{
			wordArr[i].count++;
			check=1;
		}
		
	}
	
	if( check == 0)
	{
		strcpy( wordArr[max_word].str , str );
		max_word++;
	}
	
//	printf("%s\n",wordArr[max_word-1].str);
	// printf("%d : ",max_word);
	// printf("%d\n",check);
	
}

	void defineWord(char *str)
	{
		int length = strlen(str);
		int i = 0;
		for(i = 0; i < length; i++) {
			if((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
			{
				str[i] = ' ';
			}
			if((str[i] >= 'A' && str[i] <= 'Z'))
			{
				str[i] = str[i] + 32;
			}
		}
	}

	int main(){
    	char line[100];

	    FILE *fp,*fptr;
	    if((fp = fopen("vanban.txt", "r")) == NULL)
	    {
	        printf("Can not open vanban.txt!\n");
	        return;
	    }

        fptr = fopen("newVanban.txt", "w+");

		while (fscanf(fp, "%s", line) == 1)
		{
			defineWord(line);
			fprintf(fptr, "%s ", line);
			printf("%s\n",line);
		}
		fclose(fptr);
		fclose(fp);
		
		if((fp = fopen("newVanban.txt", "r")) == NULL) {
			printf("Can't not open newVanban.txt!\n");
		}
		
	
	// while (fscanf(fp, "%s", line) == 1)
	// {
	// 	search(line);
	// 	printf("%s , %d\n",line,max_word);
	// }


		return 0;
	}


















