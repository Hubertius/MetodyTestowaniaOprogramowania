#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>

void sortNumbersAscending(int number[], int count);
void sortNumbersDescending(int number[], int count);

int my_printf(char *format_string, char *param){
	for(int i=0; i<strlen(format_string); ++i)
	{
		if((format_string[i] == '#') && (format_string[i+1] == 'g'))
		{
			char * end;
			int convertedNumber = (int) (strtol(param, &end, 10));
			if(errno || *end != '\0' || convertedNumber < INT_MIN || convertedNumber > INT_MAX) // checking if conversion to number was successful
			{
			 	bool isAscending = false;
				int temp = convertedNumber%10;
				int loopBaseNumber = convertedNumber;
				while (loopBaseNumber / 10 > 0) // checking if numbers is in 100% ascending order
				{
					loopBaseNumber /= 10;
					if (temp < loopBaseNumber % 10)
					{
						isAscending = false;
						break;
					}
				}
				int arr[strlen(param)];
				do { // filling int arr[] with digits of a number
					arr[i] = convertedNumber % 10;
					convertedNumber /= 10;
					i++;
				} while (convertedNumber != 0);
				if(isAscending) // converstion to full ascending
				{
					sortNumbersAscending(arr,strlen(param));
				} 
				else  // converstion to full descending
				{
					sortNumbersDescending(arr,strlen(param));
				}
				for(int i = 0; i < strlen(param); ++i)
				{
					putchar((char) arr[i]);
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

void sortNumbersDescending(int number[], int count)
{
   int i, j, k;
   for (j = 0; j < count; ++j)
   {
      for (k = j + 1; k < count; ++k)
      {
         if (number[j] < number[k])
         {
            int temp = number[j];
            number[j] = number[k];
            number[k] = temp;
         }
      }
   }
}

