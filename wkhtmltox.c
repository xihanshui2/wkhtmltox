/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: krakjoe                                                      |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_wkhtmltox.h"

#include "src/pdf.h"
#include "src/image.h"

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(wkhtmltox)
{
	PHP_MINIT(wkhtmltox_pdf)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(wkhtmltox_image)(INIT_FUNC_ARGS_PASSTHRU);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(wkhtmltox)
{
	PHP_MSHUTDOWN(wkhtmltox_pdf)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MSHUTDOWN(wkhtmltox_image)(INIT_FUNC_ARGS_PASSTHRU);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(wkhtmltox)
{
#if defined(COMPILE_DL_WKHTMLTOX) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(wkhtmltox)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(wkhtmltox)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "wkhtmltox support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ wkhtmltox_functions[]
 */
const zend_function_entry wkhtmltox_functions[] = {
	PHP_FE_END
};
/* }}} */

/* {{{ wkhtmltox_module_entry
 */
zend_module_entry wkhtmltox_module_entry = {
	STANDARD_MODULE_HEADER,
	"wkhtmltox",
	wkhtmltox_functions,
	PHP_MINIT(wkhtmltox),
	PHP_MSHUTDOWN(wkhtmltox),
	PHP_RINIT(wkhtmltox),
	PHP_RSHUTDOWN(wkhtmltox),
	PHP_MINFO(wkhtmltox),
	PHP_WKHTMLTOX_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_WKHTMLTOX
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(wkhtmltox)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */