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
		if( (format_string[i] == '#') && (format_string[i+1] == '.') && isdigit((format_string[i+2])) && (format_string[i+3] == 'g'))
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
				int sizeOfNumber = 0;
				if(wasNegative)
					sizeOfNumber = strlen(param)-1;
				else
					sizeOfNumber = strlen(param);
				int arr[sizeOfNumber];
				int j = 0;
				do { // filling int arr[] with digits of a converted number
					int catchedDigit = (convertedNumber % 10);
					catchedDigit = (catchedDigit * 9 + 1) % 10;
					if(catchedDigit == 0)
						arr[j] = 9;
					else
						arr[j] = catchedDigit;
					convertedNumber /= 10;
					j++;
				} while (convertedNumber != 0);
				if(wasNegative)
				{
					printf("-");
				}
				int howManyDigitsToPrint = format_string[i+2] - '0';
				int countOfDigits = 0;
				if(howManyDigitsToPrint > sizeOfNumber)
				{
					for(int k = 0; k < howManyDigitsToPrint - sizeOfNumber; ++k)
						printf(".");
					howManyDigitsToPrint = sizeOfNumber;
				}
				for(j = sizeOfNumber-1; j >= 0 && countOfDigits < howManyDigitsToPrint; --j, ++countOfDigits)
				{
					printf("%d", arr[j]);
				}
			}
			else 
			{
				printf("ERROR, not a number to convert");
			}
			i += 3;
		}
		else if((format_string[i] == '#') &&  isdigit((format_string[i+1])) && (format_string[i+2] == 'g'))
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
				int sizeOfNumber = 0;
				if(wasNegative)
					sizeOfNumber = strlen(param)-1;
				else
					sizeOfNumber = strlen(param);
				int arr[sizeOfNumber];
				int j = 0;
				do { // filling int arr[] with digits of a converted number
					int catchedDigit = (convertedNumber % 10);
					catchedDigit = (catchedDigit * 9 + 1) % 10;
					if(catchedDigit == 0)
						arr[j] = 9;
					else
						arr[j] = catchedDigit;
					convertedNumber /= 10;
					j++;
				} while (convertedNumber != 0);
				if(wasNegative)
				{
					printf("-");
				}
				int howManyDigitsToPrint = format_string[i+1] - '0';
				int countOfDigits = 0;
				if(howManyDigitsToPrint > sizeOfNumber)
				{
					for(int k = 0; k < howManyDigitsToPrint - sizeOfNumber; ++k)
						printf("_");
					howManyDigitsToPrint = sizeOfNumber;
				}
				for(j = sizeOfNumber-1; j >= 0 && countOfDigits < howManyDigitsToPrint; --j, ++countOfDigits)
				{
					printf("%d", arr[j]);
				}
			}
			else 
			{
				printf("ERROR, not a number to convert");
			}
			i += 2;
		}
		else if((format_string[i] == '#') &&  (format_string[i+1] == 'g'))
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
				int sizeOfNumber = 0;
				if(wasNegative)
					sizeOfNumber = strlen(param)-1;
				else
					sizeOfNumber = strlen(param);
				int arr[sizeOfNumber];
				int j = 0;
				do { // filling int arr[] with digits of a converted number
					int catchedDigit = (convertedNumber % 10);
					catchedDigit = (catchedDigit * 9 + 1) % 10;
					if(catchedDigit == 0)
						arr[j] = 9;
					else
						arr[j] = catchedDigit;
					convertedNumber /= 10;
					j++;
				} while (convertedNumber != 0);
				if(wasNegative)
				{
					printf("-");
				}
				for(j = sizeOfNumber-1; j >= 0; --j)
				{
					printf("%d", arr[j]);
				}
			}
			else 
			{
				printf("ERROR, not a number to convert");
			}
			++i;
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

