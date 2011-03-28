#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
extern char** environ;
 
int rscallback(void *p,int argc,char**argv,char **argvv)
{
#if 0
    int i;
    *(int*)p = 0;

    for (i = 0; i < argc; i++) 
    {
        printf("%s =%s\t",argvv[i],argv[i]?argv[i]:"NULL");
    }
    putchar('\n');
#endif

    return 5;

}
char* findstr(char*a,char*b)
{

    while(*a != '&') 
    {
        *b = *a;
        a++;
        b++;
        if(*a == '\0')
        break;
    }
    return a+1;
}
int main()
{
	char buf[4096];
    char s[256]="";
    char user[20] ="";
    char password[20]="";
    char submit[20]= "";
    char *p;
    char *q;
	int ret = 7;
	char** var;
    char *err = 0;
    int empty = 1;

    sqlite3 *db;

    
	printf("Content-Type: text/html\n\n");
    printf("<HTML><BODY>\n");

	ret = fread(buf, 1, sizeof(buf), stdin);

    p = buf;
    p +=5;

    q = user;
    p = findstr(p,q);

    q = password;
    p += 9;
    p = findstr(p,q);

    q = submit;
    p += 7;
    p = findstr(p,q);

    p = NULL;
    q = NULL;

    
    sqlite3_open("/sqlite/longin.db",&db);

// Register
    if(!strcmp(submit,"Register"))
    {
        sprintf(s,"select *from longin2 where name='%s';",user);
        ret = sqlite3_exec(db,s,rscallback,&empty,&err);  

        if(ret == SQLITE_OK)
        {
            strcpy(s,"");
            if(!strcmp(password,""))
            {
                 printf("Password cannot be null\n");
                 exit(1);
            }
            sprintf(s,"insert into longin2 values('%s','%s');",user,password);
            sqlite3_exec(db,s,NULL,&empty,&err);
            printf("Create Name Succeed\n");
        
        }
        else
        {
            printf("This Name Existing\n");
            exit(1);
        
        }



    }
//login
    else
    {
         sprintf(s,"select *from longin2 where name='%s'and password='%s';",user,password);
   
         ret = sqlite3_exec(db,s,rscallback,&empty,&err);  //call :return 4   not call :return 0
         if(ret == SQLITE_OK) //SQLITE_OK == 0
         {
            printf("Incorrect  Password\n");
            printf("Try Again\n");
            exit(1);
         }
         else      //ret == 4
         {
             printf("Login Succeed\n");
             printf("<meta http-equiv=\"refresh\" content=\"2;url=http://10.1.14.122/index.html\">\n");
             exit(1);
         }
    }


    printf("</BODY></HTML>\n");
    sqlite3_close(db);
	return 0;
}
