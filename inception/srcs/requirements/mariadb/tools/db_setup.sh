#!/bin/sh

# 생성된 데이터베이스는 /var/lib/mysql/ 하위에 디렉토리로 생성.
# 디렉토리가 없다면 데이터베이스가 생성되지 않은 것
if [ ! -d "/var/lib/mysql/$MYSQL_DB" ] ; then
	mysql_install_db --datadir=/var/lib/mysql --auth-root-authentication-method=normal
	mysqld --bootstrap <<EOF
USE mysql;
FLUSH PRIVILEGES;
CREATE DATABASE $MYSQL_DB;
CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DB.* TO '$MYSQL_USER'@'%';
ALTER USER '$MYSQL_ROOT'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
FLUSH PRIVILEGES;
EOF

fi

# mysql_install_db : 데이터 디렉토리를 초기화하고 다시 생성
# mysqld --bootstrap : 테이블 생성 전에 직접 heredoc으로 sql 쿼리 입력 (mysql_install_db와 함께 쓰임)

# run
echo "                                             
 #####    ######     ##     ####     ##  ##  
 ##  ##   ##        ####    ## ##    ##  ##  
 ##  ##   ####     ##  ##   ##  ##    ####   
 #####    ##       ######   ##  ##     ##    
 ## ##    ##       ##  ##   ## ##      ##    
 ##  ##   ######   ##  ##   ####       ##    
                                             "

exec mysqld --datadir=/var/lib/mysql