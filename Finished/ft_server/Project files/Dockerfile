# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpenaran <gpenaran@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 12:48:37 by gpenaran          #+#    #+#              #
#    Updated: 2021/02/02 15:45:54 by gpenaran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

#   This command updates and installs all the necesary packages (nginx, ssl, mysql, php).
RUN apt-get update && apt-get install -y wget\ 
 nginx\ 
 openssl\
 mariadb-server mariadb-client\
 php-fpm php-mysql

#	Moves all the files to the desired locations.
RUN mkdir /temporal
#   PHPMYADMIN
COPY srcs/config.inc.php ./temporal
#   BASH
COPY srcs/configuration.sh ./temporal
#   NGINX
COPY srcs/list.html ./var/www/localhost/
COPY srcs/info.php ./var/www/localhost/
COPY srcs/default ./temporal
#   WP
COPY srcs/wordpress-5.6.tar.gz ./temporal
COPY srcs/wordpress.sql ./temporal
COPY srcs/wp-config.php ./temporal
#   AUTOINDEX
COPY srcs/autoindex.sh ./

#	Open the ports for http and https traffic.
EXPOSE 80 443

#	Runs the configuration.
CMD bash /temporal/configuration.sh
