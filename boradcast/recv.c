#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>


int main(int argc, char* argv[])
{
	int s = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in addr;
	char buf[32];
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9900);
	addr.sin_addr.s_addr = INADDR_ANY;
	bind(s, (struct sockaddr*)&addr, sizeof(addr));

	recv(s, buf, sizeof(buf), 0);

	printf("%s\n", buf); 
	return 0;
}
