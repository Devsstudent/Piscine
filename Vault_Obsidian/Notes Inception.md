
## NGINX Container
Install nginx
Install openssl
No port 80

## WordPress Container
Install wordpress avec le wget la : wget https://wordpress.org/latest.tar.gz
Check WP_SiteURL / WP_HOME / WP_CONTENT_URL to set https://odessein.42.fr
install php-fpm 8.1 : sudo apt install php8.1-fpm

## MariaDb Container
Install mysql
Create db + 2 user : ```
CREATE DATABASE wordpress_db;```

## Compose
Doker network create