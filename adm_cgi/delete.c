#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

#include <dirent.h>

#define PATH_MEDIA "/home/jiesse/upload/MediaFile/"
#define PATH_PIC "/home/jiesse/upload/PicFile/"
#define PATH_TEXT "/home/jiesse/upload/TextFile/"
#define PATH_OTHER "/home/jiesse/upload/OtherFile/"

char *change(char *s)
{
     char *new_name = malloc(25);
     char z[3] = {0};
     char a;
     char *p;
     char *m;
     int i = 0;
     int k;
     char c;
     p = s;
     while(*p)
     {
         if(*p == '%')
         {
             z[0] = *(p+1);
             z[1] = *(p+2);
             sscanf(z,"%x",&k);
             new_name[i++] = k;
             p = p+3;
         }
         else if(*p == '+')
         {
             new_name[i++] = ' ';
             p++;
         }
         else
         {
             new_name[i++] = *p;
            p++;
         }
     }
     return new_name;
 }

int main(int argc, char* argv[])
{
	char buf[200] = {0};
    char path[100] = {0};
    char pathf[100] = {0};
    char file[20][200] = {0};
    int ret;
    int i = 0;
    int j = 0;

    char *k;
    //directory
    DIR *dp;
    struct dirent *filename;

    printf("Content-Type: text/html\n\n");

    printf("\
    <meta http-equiv=\"Content-Type\" content=\"text/html;charset=utf-8\">\
    \n") ;

    printf("\
    <form action=\"../cgi-bin/test\" method=\"post\">\
    \n") ;

    ret = fread(buf, 1, sizeof(buf), stdin);
    //printf("receive %d byte\n",ret);
    //printf("<br>\n");


     k = strstr(buf,"&log");
     printf("<br>\n");
     printf("%s\n",k);
     printf("<br>\n");
     if(!strcmp(k+1,"log1=delete"))
     {
        strcat(path,PATH_MEDIA);
     }
     if(!strcmp(k+1,"log2=delete"))
     {
        strcat(path,PATH_PIC);
     }
     if(!strcmp(k+1,"log3=delete"))
     {
        strcat(path,PATH_TEXT);
     }
     if(!strcmp(k+1,"log4=delete"))
     {
        strcat(path,PATH_OTHER);
     }
     *k = 0;
      k = buf;
   
      while(1)
      {
           sscanf(k,"check=%s",file[i++]);
           k = strstr(file[i-1],"&");
           if(k == NULL)
           break;
           *k = 0;
           k++;
      }
      printf("<br>\n");
      for (j = 0; j < i; j++)
      {
          
          strcpy(pathf,path);
          strcat(pathf,change(file[j]));
          //strcat(pathf,file[j]);
          //printf("%s\n",pathf);
          if(remove(pathf))
              printf("failed\n");
          else
          {
                printf("remove success\n");
          }
          printf("<br>\n");
      }



    return 0;

}
