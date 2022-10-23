#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


char covertUpperLower(char param);


int my_printf(char *format_string, char *param){
	for(int i=0; i<strlen(format_string); ++i)
	{
		if((format_string[i] == '#') && (format_string[i+1] == 'k'))
		{
			for(int j=0; j<strlen(param); j++)
			{
				putchar(covertUpperLower(param[j]));
			} 
			i++;
		}
		else if((format_string[i] == '#') && (format_string[i+1] == '.') && isdigit((format_string[i+2])) && (format_string[i+3]) == 'k')
		{
			char forAtoiConvertion[2] = {format_string[i+2], '\0'};
			int howMuchCharacters =  atoi(forAtoiConvertion) < strlen(param) ? atoi(forAtoiConvertion) : strlen(param);

			for(int j= 0; j < howMuchCharacters; j++)
			{
				putchar(covertUpperLower(param[j]));
			}
			i += 3;
		}
		else if((format_string[i] == '#') && (format_string[i+1] == '.') && isdigit((format_string[i+2])) && (format_string[i+3]) == 'k')
		{

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

char covertUpperLower(char param)
{
	if(isalpha(param))
	{
		if(islower(param))
		{
			param = (char) toupper(param);
		}
		else
		{
			param = (char) tolower(param);
		}
	} 
	return param;
}

