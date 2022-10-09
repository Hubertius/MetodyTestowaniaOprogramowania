#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int my_printf(char *format_string, char *param){
	for(int i=0; i<strlen(format_string); ++i)
	{
		if((format_string[i] == '#') && (format_string[i+1] == 'k'))
		{
			for(int j=0; j<strlen(param); j++)
			{
				if(isalpha(param[j]))
				{
					if(islower(param[j]))
					{
						param[j] = (char) toupper(param[j]);
					}
					else
					{
						param[j] = (char) tolower(param[j]);
					}
				}
				putchar(param[j]);
			} 
			i++;
		}
		else if((format_string[i] == '#') && (format_string[i+1] == '.') && isdigit((format_string[i+2])) && (format_string[i+3]) == 'k')
		{
			char forAtoiConvertion[2] = {format_string[i+2], '\0'};
			int howMuchCharacters =  atoi(forAtoiConvertion) < strlen(param) ? atoi(forAtoiConvertion) : strlen(param);

			for(int j= 0; j < howMuchCharacters; j++)
			{
				if(isalpha(param[j]))
				{
					if(islower(param[j]))
					{
						param[j] = (char) toupper(param[j]);
					}
					else
					{
						param[j] = (char) tolower(param[j]);
					}
				}
				putchar(param[j]);
			}
			i += 3;
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

