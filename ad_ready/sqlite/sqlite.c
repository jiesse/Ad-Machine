#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>



int rscallback(void *p,int argc,char**argv,char **argvv)
{
    int i;
    *(int*)p = 0;

    for (i = 0; i < argc; i++) 
    {
        printf("%s =%s",argvv[i],argv[i]?argv[i]:"NULL");
        printf("\t%d",i);
    }
    putchar('\n');
    return 0;

}
int main(void)
{
    sqlite3 *db;
    char *err = 0;
    int ret = 0;
    int empty = 1;
    
    ret = sqlite3_open("./test.db",&db);
    
    ret = sqlite3_exec(db,"select *from emploree;",rscallback,&empty,&err);

    if(empty)
    {
        fputs("table emploree is empty",stderr) ;
        exit(1);

    }
    sqlite3_close(db);

    return 0;
}
