
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>


	int main(){

    char line[200];
	    char word[400][10];
	    char mean[100000];
	    FILE *fp;
	    if((fp = fopen("vanban.txt", "r")) == NULL)
	    {
	        printf("Can not open vanban.txt!\n");
	        return;
	    }
	    int i;
	    int first_word_flag = 0;
	    int word_count = 0;
        
	    /*do
	    {


	    } */
        while((fgets(line, 100, fp)) != NULL){
            // printf("%s\n", line);
				int j=0,k=0,l=0;

			for(i = 0; i < sizeof(line); i++){

				if(  line[i] != ' ' && line[i] != '\n' && line[i] !=',' && line[i] !='.' && ( line[i] < '0' || line[i] > '9' ) && line[i] != '(' && line[i] != ')' ){

						word[j][k] = line[i];
						k++;
	    				first_word_flag = 1;
					
				}
				else{
					if( first_word_flag==1){
						j++;
						first_word_flag = 0;
					}
					k=0;

				}



			}

			for(l = 0; l < j ; l++){
				printf("%s\n", word[l]);
			}



        };

	    fclose(fp);

	}


















