#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


char covertUpperLower(char param);


int my_printf(char *format_string, char *param){
	for(int i=0; i<strlen(format_string); ++i)
	{
		if((format_string[i] == '#') && (format_string[i+1] == 'g'))
		{
			if(strtol(param, NULL, 10))
			{

			}
			else 
			{
				printf("Passing #g as number failed due to \"param\" %s not being convertable to number! Ending program!", param);
				return 1;
			}
			i++;
		}
		else
			putchar(format_string[i]);
	}
	puts("");
}

int main(int argc, char *argv[]){
	char buf[1024],buf2[1024];
	while(gets(buf)){
		gets(buf2);
		my_printf(buf,buf2);
	}
	return 0;
}

void sortNumbersAscending(int number[], int count)
{
   int i, j, k;
   for (j = 0; j < count; ++j)
   {
      for (k = j + 1; k < count; ++k)
      {
         if (number[j] > number[k])
         {
            int temp = number[j];
            number[j] = number[k];
            number[k] = temp;
         }
      }
   }
}


