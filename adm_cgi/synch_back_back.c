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



#define UDP_PORT 8000
#define TCP_PORT 8001
int main(int argc, char* argv[])
{
    char buff[1024] = {"8001"};
    char buff_end[100] = {0};
    char path_file[100]={0};
    char *path[] = {"/home/jiesse/upload/MediaFile/","/home/jiesse/upload/PicFile/","/home/jiesse/upload/TextFile/","/home/jiesse/upload/OtherFile/"};
    //udp
    int s;
    int optval = 1;
    struct sockaddr_in addr;
    //tcp    


    int i, len, n, fd;
    int on = 1;
    int server_sock, client_sock;
    socklen_t client_len;
    struct sockaddr_in server, client;
    struct in_addr in;

    //directory
    DIR *dp;
    struct dirent *filename;

    printf("Content-Type: text/html\n\n");

    printf("\
    <meta http-equiv=\"Content-Type\" content=\"text/html;charset=utf-8\">\
    \n") ;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(UDP_PORT);
    addr.sin_addr.s_addr = inet_addr("255.255.255.255");

    s = socket(AF_INET, SOCK_DGRAM, 0);
    setsockopt(s, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval));
    sendto(s, buff, strlen(buff), 0, (struct sockaddr*)&addr, sizeof(addr));

    if((server_sock = socket(AF_INET, SOCK_STREAM, 0))<0)
    {
        perror("socket") ;
        exit(-1);
    }
    else
    {
        //printf("socket ok\n");
    }
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(TCP_PORT);
    server.sin_addr.s_addr = htons(INADDR_ANY);


    if((setsockopt(server_sock,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)))<0)
    {
         printf("set socket fail");
    }
    if(bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {

        perror("bind");
        exit(-1);

    }
    else
    {
        //printf("bind ok\n");
    }

    if((listen(server_sock, 5))<0)
    {
        perror("listen") ;
        exit(-1);

    }
    else
    {
        //printf("listen ok\n");
    }


    client_len = sizeof(client) ;
    if((client_sock = accept(server_sock,(struct sockaddr *)&client, &client_len)) < 0)
    {
        close(server_sock) ;
        perror("accept");
        exit(-1);

    }
    else
    {

        //printf("accept ok\n");
        in.s_addr = client.sin_addr.s_addr;

    }

    for(i=0;i<4;i++)
    {
        dp = opendir(path[i]);
        sendto(s, "directory", 9, 0, (struct sockaddr*)&addr, sizeof(addr));    //udp fa song directory
        while(filename=readdir(dp))
        {
            if(filename->d_type == DT_DIR )    //DT_DIR == 4
            {
                continue;  
            }
            //printf("filename: %s\n",filename->d_name) ;
            usleep(100);
            sendto(s, filename->d_name, strlen(filename->d_name), 0, (struct sockaddr*)&addr, sizeof(addr));  //fa song  filename
            usleep(100);

            sprintf(path_file,"%s%s",path[i],filename->d_name);  //path + filename
            //printf("%s\n",path_file);

            fd = open(path_file,O_RDONLY,0664);
            if(fd < 0)
            {

                printf("open error\n");
            }
            if(0==i)
            {
                while((len = read(fd,buff,500))>0)
                {
                    write(client_sock,buff,len);
                    //printf("%d\n",len);
                }
                usleep(100);
            }
            else
            {
                while((len = read(fd,buff,20))>0)
                {
                    write(client_sock,buff,len);
                    //printf("%d\n",len);
                }
                usleep(100);
            }
            close(fd);

        }
        usleep(100);
        sendto(s, "the_end", 7, 0, (struct sockaddr*)&addr, sizeof(addr));       //  udp fa song end

        closedir(dp);
        usleep(100);

    }
        sendto(s, "all_end", 7, 0, (struct sockaddr*)&addr, sizeof(addr));       //  udp fa song end

    read(client_sock,buff_end,20);                                            //tcp jie shou client end
    //len = recv(client_sock,buff_end,20,0);
    printf("Synch  %s\n",buff_end);

    close(s);

    close(client_sock);

    close(server_sock);
    return 0;
}
