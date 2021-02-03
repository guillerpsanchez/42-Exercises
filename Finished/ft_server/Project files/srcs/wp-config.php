<?php

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'user' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '%d#b?M-REJ]sCY1>^(_O,mIU;KsvXzy1 XKxX1*-f>p}HACdqjM% ip@:)9(Ej|T');
define('SECURE_AUTH_KEY',  '-el/G!XUr.,TdYC_2wN0v$PL.}qxc5sm!+7IM<86VF;!R!nKw==Wwfp#*o_)!OjT');
define('LOGGED_IN_KEY',    '+;+*2{BPJk5~d&Hc4EUI({.%h$pV%]Xl1jqk3ZP1+>8 E-zb58;^$7%2$e!xvjgz');
define('NONCE_KEY',        '2+s.&E!n9|tx#0b<f>FW[!tzO)W [#gRnfK5Q-rP^x+WS76c[br1-s3-+x+)D16W');
define('AUTH_SALT',        'kW%{aMEJYC@#mKg,cxf8PJ wFDXGeW`M=%yuX9b3uy-.W%;}tY?#4s4++2RCVNch');
define('SECURE_AUTH_SALT', 'C8UnG3.sWI;r^TEDRQDG;T@e<LR/;hsJ&PG%f{j-=W1iN|[nR|Th;:bE;lPE/g 0');
define('LOGGED_IN_SALT',   '-pLU;3T,W&/t=ZR(nksM80Hw>XZz!v)8A``.Pt]-YWM}|6d5$v0g]^adO&Ll>#NK');
define('NONCE_SALT',       '=+=FqG|wF=.#?*mU4}Zbw#Mp*2H6 {V/]M C`!M%V^P)5%0.}9FaAy3BZ}xl-X_.');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';