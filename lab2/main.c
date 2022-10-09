#include <stdio.h>
#include <ctype.h>
#include <string.h>


int my_printf(char *format_string, char *param){
	for(int i=0; i<strlen(format_string); ++i)
	{
		if((format_string[i] == '#') && (format_string[i+1] == '.') && isdigit((format_string[i+2])) && (format_string[i+3]) == 'k')
		{
			i += 3;
			putchar('1');
			int howMuchCharacters = (int) format_string[i+2] > strlen(param) ? (int) strlen(param) : (int) format_string[i+2];
			putchar((char) howMuchCharacters);
			for(int j=0; j < howMuchCharacters; j++)
			{
				putchar('2');
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
				putchar('1');
				putchar(param[j]);
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

