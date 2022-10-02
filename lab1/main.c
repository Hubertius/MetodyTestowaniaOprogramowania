#include <stdio.h>
#include <ctype.h>
#include <string.h>


int my_printf(char *format_string, char *param){
	for(int i=0; i<strlen(format_string); ++i)
	{
		if((format_string[i] == '#') && (format_string[i+1] == 'k'))
		{
			i++;
			for(int j=0;i<strlen(param);j++)
			{
				if(isalpha(param[j]))
				{
					if(islower(param[j]))
						param[j] = (char) tolower(param[j]);
					else
						param[j] = (char) toupper(param[j]);
				}
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
