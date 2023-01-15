#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>

void sortNumbersAscending(int number[], int count);
void sortNumbersDescending(int number[], int count);

int my_printf(char *format_string, char *param){
	for(int i=0; i<strlen(format_string); ++i)
	{
		if((format_string[i] == '#') && (format_string[i+1] == '.') && isdigit((format_string[i+2])) && (format_string[i+3] == 'j'))
		{
			char * end;
			int convertedNumber = (int) (strtol(param, &end, 10));
			if(errno == 0 && *end == '\0') // checking if conversion to number was successful)
			{
				int tmpNumber = convertedNumber;
				int countDigits = 0;
				do
				{
					tmpNumber /= 10;
					++countDigits;
				} while (tmpNumber != 0);
				char arr[countDigits];
				sprintf(arr, "%x", convertedNumber);
				countDigits = strlen(arr);
				int j = 0;
				int howManyDigitsToPrint = format_string[i+2] - '0';
				while(j < countDigits && j < howManyDigitsToPrint)
				{
					char ch = arr[j];
					if(ch == '0')
						printf("o");
					else if(ch == 'a')
						printf("g");
					else if(ch == 'b')
						printf("h");
					else if(ch == 'c')
						printf("i");
					else if(ch == 'd')
						printf("j");
					else if(ch == 'e')
						printf("k");
					else if(ch == 'f')
						printf("l");
					else
						printf("%c", ch);
					++j;
				}
				i += 3;
			}
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

