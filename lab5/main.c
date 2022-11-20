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
		if((format_string[i] == '#') &&  isdigit((format_string[i+1])) && (format_string[i+2] == 'g'))
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
			}
			else 
			{
				printf("ERROR, not a number to convert");
			}
			i += 2;
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

