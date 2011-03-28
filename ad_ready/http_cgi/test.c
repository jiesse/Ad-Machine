#include <stdio.h>
#include <stdlib.h>

extern char** environ;
 
int main()
{
	char buf[4096];
	int ret;
	char** var;

	printf("Content-Type: text/plain\n\n");

	for(var = environ; *var!= NULL; ++var)
		printf("%s\n", *var);
	
	ret = fread(buf, 1, sizeof(buf), stdin);
	printf("read %d len\n", ret);
	printf("%s", buf);
	
	return 0;
}
