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
			bool wasNegative = false;
			if(convertedNumber < 0)
			{
				convertedNumber *= -1;
				wasNegative = true;
			}
			if(errno == 0 && *end == '\0') // checking if conversion to number was successful
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
				int j = 0;
				do { // filling int arr[] with digits of a converted number
					arr[j] = convertedNumber % 10;
					convertedNumber /= 10;
					j++;
				} while (convertedNumber != 0);
				if(wasNegative)
				{
					printf("-");
					for(j = 0; j < (strlen(param)-1); j++)
					{
						printf("%d", arr[j]);
					}
				}
				else 
				{
					for(j = 0; j < strlen(param); j++)
					{
						printf("%d", arr[j]);
					}
				}
			}
			else 
			{
				printf("ERROR, not a number to convert");
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

