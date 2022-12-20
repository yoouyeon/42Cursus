FROM debian:buster
# 데비안 이미지에서 이미지 생성 시작
COPY ./tools/setup.sh /setup.sh
# 설치 스크립트 복사
EXPOSE 9000
# 9000 port open

RUN apt-get update && apt-get -y upgrade && apt-get install -y php7.3-fpm php-mysql mariadb-client curl && \
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp && \
	mkdir -p /var/www/html/wordpress /run/php && \
	chmod +x setup.sh && \
	usermod -G www-data -a www-data && chown -R www-data:www-data /var/www/
# 필요한 패키지 설치, wp-cli 설치, 권한설정
# php : wordpress를 이루는 언어, DB의 데이터를 활용하는 등 동적으로 html 파일을 구성한다.
# php7.3-fpm : php를 fastCGI 모드로 등작할 수 있게 함.
# php-mysql : php와 mysql(MariaDB)를 연동하기 위한 패키지
# wp-cli : wordpress 설정을 cli로 할 수 있게 해 주는 유틸

COPY ./conf/php-fpm.conf /etc/php/7.3/fpm/pool.d/www.conf
# php 설정파일 복사
WORKDIR /var/www/html/wordpress
# /var/www/html/ : nginx 기본 홈 디렉토리
ENTRYPOINT ["sh", "/setup.sh"]