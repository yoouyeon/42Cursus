
FROM debian:buster
COPY ./tools/db_setup.sh /db_setup.sh
EXPOSE 3306
# 필요한 패키지들 설정
# 권한 설정 (mysql 기본 유저 : mysql)
RUN apt-get update && apt-get -y upgrade && \
	apt-get install -y mariadb-server mariadb-client && \
	mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld && \
	chmod +x db_setup.sh

# 설정 파일 복사 (bind-adress, port 설정 수정)
RUN rm -rf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
ENTRYPOINT ["sh", "/db_setup.sh"]