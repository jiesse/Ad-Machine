#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BROADCAST_PORT 9988
char path[] = "/adm";

int listenfd = -1;
char* files[1024];
int max_files = 0;

void send_file(int fd, char* filename)
{
	int len = strlen(filename)+1;
	int filelen;
	struct stat filestat;
	int filefd;
	char buf[1024];
	int ret;

	stat(filename, &filestat);
	filelen = filestat.st_size;
	
	send(fd, &len, sizeof(len), 0);
	send(fd, filename, len, 0);
	printf("%s\n", filename);
	send(fd, &filelen, sizeof(filelen), 0);

	filefd = open(filename, O_RDONLY);
	while(1)
	{
		ret = read(filefd, buf, sizeof(buf));
		if(ret == 0)
			break;
		send(fd, buf, ret, 0);
	}
	close(filefd);
}
void search_files(char* path)
{
	DIR* dir;
	struct dirent* entry;
	char* filename;
	
	dir = opendir(path);
	while(1)
	{
		entry = readdir(dir);
		if(entry == NULL)
			break;
	
		if(*entry->d_name == '.')
			continue;
		filename = malloc(256);
		strcpy(filename, path);
		strcat(filename, "/");
		strcat(filename, entry->d_name);

		if(entry->d_type == DT_REG)
		{
			//send_file(fd, filename);
			files[max_files++] = filename;
		}
		else if(entry->d_type == DT_DIR)
		{
			search_files(filename);
			free(filename);			
		}
		else
		{
			printf("something terreble\n");
		}
	}
}

void* send_func(void*p)
{
	int fd = (int)p;
	int end = 0xffffffff;
	int i;
	pthread_t id = pthread_self();
	printf("ready send %d\n", (int)id);

	for(i=0; i<max_files; i++)
	{
		send_file(fd, files[i]);
	}
	send(fd, &end, sizeof(end), 0);

	printf("end send %d\n", (int)id);
	close(fd);
}

int accept_client()
{
	fd_set set;
	struct timeval tv;
	int ret;
	int fd;
	pthread_t threads[1024];
	int thread_count = 0;
	search_files("/adm");

	FD_ZERO(&set);
	while(1)
	{
		FD_SET(listenfd, &set);
		tv.tv_sec = 10;
		tv.tv_usec = 0;

		ret = select(listenfd+1, &set, NULL, NULL, &tv);
		if(ret < 0)
		{
			printf("select error\n");
			exit(1);
		}
		else if(ret == 0)
		{
			break;
		}
		else
		{
			fd = accept(listenfd, NULL, NULL);
			if(fd > 0)
			{	
				pthread_create(&threads[thread_count++], NULL, send_func, (void*)fd);
				printf("thread counts : %d\n", thread_count);
			}
		}
	}

	// wait threads
	for(ret=0; ret<thread_count; ret++)
	{
		pthread_join(threads[ret], NULL);
	}

	for(ret=0; ret<max_files; ret++)
	{
		free(files[ret]);
	}
	close(listenfd);
}

int get_listenport()
{
	int ret;
	struct sockaddr_in addr;
	int socklen = sizeof(addr);
	ret = getsockname(listenfd, (struct sockaddr*)&addr, &socklen);
	if(ret != 0)
	{
		printf("get listenport error\n");
		exit(1);
	}

	return ntohs(addr.sin_port);
}

int send_broadcast()
{
	int ret = 0;
	int optval = 1;
	int broadfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in addr;
	int addr_len = sizeof(addr);
	int listen_port = get_listenport();

	if(broadfd <= 0)
	{
		printf("socket error\n");
		return -1;
	}

	ret = setsockopt(broadfd, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval));	
	if(ret != 0)
	{
		return ret;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(BROADCAST_PORT);
	addr.sin_addr.s_addr = inet_addr("255.255.255.255");

	ret = sendto(broadfd, &listen_port, sizeof(listen_port), 0, (struct sockaddr*)&addr, addr_len);
	if(ret < 0)
	{
		return -1;
	}

	close(broadfd);
	
}

int create_server()
{
	int ret = 0;
	
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd <= 0)
	{
		printf("socket error\n");
		return -1;
	}
	
	ret = listen(listenfd, 5);
	if(ret != 0)
	{
		printf("listen error\n");
	}
	return ret;
}

int main(int argc, char* argv[])
{
	int ret;
	// create server
	ret = create_server();
	if(ret != 0)
	{
		printf("create server error\n");
		return -1;
	}

	// send broad cast
	ret = send_broadcast();
	if(ret != 0)
	{
		printf("send broadcast error\n");
		return -2;
	}

	// accept client
	ret = accept_client();
	if(ret != 0)
	{
		printf("accept_client error\n");
		return -3;
	}

	return 0;
}
