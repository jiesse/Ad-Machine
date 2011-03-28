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

#define PATH_MEDIA "/home/jiesse/upload/MediaFile"
#define PATH_PIC "/home/jiesse/upload/PicFile"
#define PATH_TEXT "/home/jiesse/upload/TextFile"
#define PATH_OTHER "/home/jiesse/upload/OtherFile"

int main(int argc, char* argv[])
{
	char buf[100] = {0};
    int ret;
    //directory
    DIR *dp;
    struct dirent *filename;

    printf("Content-Type: text/html\n\n");

    printf("\
    <meta http-equiv=\"Content-Type\" content=\"text/html;charset=utf-8\">\
    \n") ;

    printf("\
    <form action=\"../cgi-bin/delete\" method=\"post\">\
    \n") ;



    ret = fread(buf, 1, sizeof(buf), stdin);
    if(ret == 9)
    {

        dp = opendir(PATH_MEDIA);
        printf("\
        <font color=\"0xff0000\"><font size=5> MediaFile </font></font>\
        \n") ;
        printf("<br>\n");
        while(filename=readdir(dp))
        {
            if(filename->d_type == DT_DIR )    //DT_DIR == 4
            {
                   continue;  
            }
            printf("\
            <input type=\"checkbox\" value=\"%s\" name=\"check\" />\
            \n",filename->d_name) ;
            printf("%s\n",filename->d_name) ;
            printf("<br>\n");
             
          
        }
        closedir(dp);
        printf("\
        <input type=\"submit\" value=\"delete\" name=\"log1\" style=\" font-size: 50px; background: #CCCCFF\">\
        \n") ;
    }

    if(ret == 11)
    {
        dp = opendir(PATH_PIC);
        printf("\
        <font color=\"0xff0000\"><font size=5> PicFile </font></font>\
        \n") ;
        printf("<br>\n");
        while(filename=readdir(dp))
        {
            if(filename->d_type == DT_DIR )    //DT_DIR == 4
            {
                   continue;  
            }
            printf("\
            <input type=\"checkbox\" value=\"%s\" name=\"check\" />\
            \n",filename->d_name) ;
            printf("%s\n",filename->d_name) ;
            printf("<br>\n");
          
        }
        closedir(dp);
        printf("\
        <input type=\"submit\" value=\"delete\" name=\"log2\" style=\" font-size: 50px; background: #CCCCFF\">\
        \n") ;
    }

    if(ret == 8)
    {

        dp = opendir(PATH_TEXT);
        printf("\
        <font color=\"0xff0000\"><font size=5> TextFile </font></font>\
        \n") ;
        printf("<br>\n");
        while(filename=readdir(dp))
        {
            if(filename->d_type == DT_DIR )    //DT_DIR == 4
            {
                   continue;  
            }
            printf("\
            <input type=\"checkbox\" value=\"%s\" name=\"check\" />\
            \n",filename->d_name) ;
            printf("%s\n",filename->d_name) ;
            printf("<br>\n");
          
        }
        closedir(dp);
        printf("\
        <input type=\"submit\" value=\"delete\" name=\"log3\" style=\" font-size: 50px; background: #CCCCFF\">\
        \n") ;

    }
    if(ret == 10)
    {
        dp = opendir(PATH_OTHER);
        printf("\
        <font color=\"0xff0000\"><font size=5> OtherFile </font></font>\
        \n") ;
        printf("<br>\n");
        while(filename=readdir(dp))
        {
            if(filename->d_type == DT_DIR )    //DT_DIR == 4
            {
                   continue;  
            }
            printf("\
            <input type=\"checkbox\" value=\"%s\" name=\"check\" />\
            \n",filename->d_name) ;
            printf("%s\n",filename->d_name) ;
            printf("<br>\n");
          
        }
        closedir(dp);
        printf("\
        <input type=\"submit\" value=\"delete\" name=\"log4\" style=\" font-size: 50px; background: #CCCCFF\">\
        \n") ;
    }
    return 0;
}
