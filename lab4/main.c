#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char covertUpperLower(char param);


int my_printf(char *format_string, char *param){
	for(int i=0; i<strlen(format_string); ++i)
	{
		if((format_string[i] == '#') && (format_string[i+1] == 'g'))
		{
			if(strtol(param, NULL, 10))
			{
			 	bool isAscending = false;
				int baseNumber = (int) (strtol(param, NULL, 10));
				int temp = baseNumber%10;
				int loopBaseNumber = baseNumber;
				while (loopBaseNumber / 10 > 0)
				{
					loopBaseNumber /= 10;
					if (temp < loopBaseNumber % 10)
					{
						isAscending = false;
						break;
					}
				}
				int arr[strlen(param)];
				do {
					arr[i] = baseNumber % 10;
					baseNumber /= 10;
					i++;
				} while (baseNumber != 0);
				if(isAscending) 
				{
					sortNumbersAscending(arr,strlen(param));
				} 
				else 
				{
					sortNumbersDescending(arr,strlen(param));
				}
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


