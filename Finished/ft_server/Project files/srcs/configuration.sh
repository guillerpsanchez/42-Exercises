#	Creates webpage folder and activates it with the custom configuration provided.
rm /etc/nginx/sites-enabled/default
mv ./temporal/default /etc/nginx/sites-available/
ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/

#	Generates a custom local ssl cerificate for the localhost which can only be used on the local machine.
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/C=ES/ST=Spain/L=Madrid/O=42/CN=localhost" -keyout /etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.crt
clear

#	Downloads and installs PHPMyAdmin
wget -q https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz
tar -xzf phpMyAdmin-5.0.4-english.tar.gz
rm phpMyAdmin-5.0.4-english.tar.gz
mv phpMyAdmin-5.0.4-english var/www/localhost/phpmyadmin
mv ./temporal/config.inc.php var/www/localhost/phpmyadmin

#	Installs Wordpress
tar -xf ./temporal/wordpress-5.6.tar.gz
rm ./temporal/wordpress-5.6.tar.gz
mv wordpress /var/www/localhost/
mv ./temporal/wp-config.php /var/www/localhost/wordpress

#   Modify permissions to make everything works.
chown -R www-data /var/www/*
chmod -R 755 /var/www/*
chmod 660 /var/www/localhost/phpmyadmin/config.inc.php
chown -R www-data:www-data /var/www/localhost/phpmyadmin
chown -R www-data.www-data -R /var/www/localhost/wordpress/*

#	Starts the services
service mysql start
service php7.3-fpm start
service nginx start

#   Configures the Database

echo "CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;" | mysql -u root
echo "GRANT ALL ON wordpress.* TO 'user'@'localhost' IDENTIFIED BY 'password';" | mysql -u root
echo "GRANT ALL ON *.* TO 'user'@'localhost' IDENTIFIED BY 'password'" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root
mysql wordpress -u root --password=  < /temporal/wordpress.sql

bash