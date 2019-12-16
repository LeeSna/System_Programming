#include <stdio.h>
#include <stdlib.h>
#include "/usr/include/mysql/mysql.h"

void main() {   
  
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
  
   char *server = "localhost";
   char *user = "root";
   char *password = "rader3479!";
   char *database = "test";

   conn = mysql_init(NULL);
  
   if (!mysql_real_connect(conn, server, user, password, database, 3306, (char *)NULL, 0)) {   
      fprintf(stderr, "%s\n", mysql_error(conn));   
      exit(1);   
   }   

   res = mysql_use_result(conn);
   mysql_query(conn, "select * from ex09;");   

   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {   
      fprintf(stderr, "%s\n", mysql_error(conn));   
      exit(1);   
   }   
}
