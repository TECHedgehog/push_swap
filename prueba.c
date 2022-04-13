#include <stdio.h>
#include <stdlib.h>


int main (void)
{
	char *str="0 1 2";
	int i=0;

	while (str[i])
	{
		printf("%d", atoi((str + i)));
		i++;
	}
	return 0;
}