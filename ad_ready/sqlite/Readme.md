

#this is the usage of sqlite3

    sudo apt-atitude install libsqlite3-0,libsqlite3-dev,sqlite3,sqlite3-doc

    ~$ sqlite3 test.db

    sqlite>

        create table employee(id integer primary key, name text, gender text, age integer);
        drop table employee    //delete the table

        .tables

        insert into employee values(1,'name','male',18);

        select *from employee;

        .help

        seclect *from employee where id=1 and name ='jiesse';
        delete *from employee where id=1 and name ='jiesse';

        update employee set name ='name' where id =1;    //alter

        .import data.txt employee

        .schema employee

        
#Note

        gcc -o test.cgi test.c -lsqlite3

        typedef int (*sqlite_callback)(void *pArg,int argc, char **argv, char **argvv);

        int sqlite3_exec(sqlite3 *db, const char *zSql,sqlite_callback xCallback,void *pArg,char **pzErrMsg);   //if the zSql command succeed ,but more ,every one result line,run one xCallback;

        argc :column counts, id,name,age ,so argc =3;
        argv : argv[0] =id ,argv[1] = name
        argvv : argvv[0] = 1; argvv[1]  = jiesse


        www.sqlite.com.cn






