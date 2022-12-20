# wordpress 설치파일 다운로드
wp core download --allow-root
# MariaDB 가 실행되지 않으면 설정 불가 -> 실행 확인
until mysqladmin -h $MYSQL_HOST -u $MYSQL_USER --password=$MYSQL_PASSWORD ping 2> /dev/null ; do
	echo "MariaDB is not ready...."
	sleep 1
done

# make config file
wp config create --dbname=$MYSQL_DB --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$MYSQL_HOST --allow-root
# install
wp core install --url=localhost/wordpress --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
# create user soneone
wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PASSWORD --allow-root

echo "                                             
 #####    ######     ##     ####     ##  ##  
 ##  ##   ##        ####    ## ##    ##  ##  
 ##  ##   ####     ##  ##   ##  ##    ####   
 #####    ##       ######   ##  ##     ##    
 ## ##    ##       ##  ##   ## ##      ##    
 ##  ##   ######   ##  ##   ####       ##    
                                             "

exec /usr/sbin/php-fpm7.3 -F