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

extern char** environ;
#define UDP_PORT 8000
 
int main()
{
    //udp
    int s;
    int optval = 1;
    struct sockaddr_in addr;

	char buf[4096];
	char name[10];
	char opra[10];
    char *k;
	int ret;
	char** var;

//udp
    

    addr.sin_family = AF_INET;
    addr.sin_port = htons(UDP_PORT);
    addr.sin_addr.s_addr = inet_addr("255.255.255.255");

    s = socket(AF_INET, SOCK_DGRAM, 0);
    setsockopt(s, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval));





//udp
    printf("Content-Type: text/html\n\n");
	
        printf("\
        <meta http-equiv=\"Refresh\" content=\"0;URL=http://10.1.14.122/state.html\" >\
        ");


        ret = fread(buf, 1, sizeof(buf), stdin);
    sscanf(buf,"log=%s",opra);
    if(!strcmp("on",opra))
    {
        sendto(s, "kk", 2, 0, (struct sockaddr*)&addr, sizeof(addr));

    }
    else if(!strcmp("off",opra))
    {
        sendto(s, "kkk", 3, 0, (struct sockaddr*)&addr, sizeof(addr));

    }

	
	return 0;
}
