#ifndef __LIBDOWN_H__
#define __LIBDOWN_H__

enum ERROR_CODE
{
    OK              = 0,
	INVALID_ARG,
	FAILED,
};

/****************************************
 *
 * APIs of Library
 *
 ****************************************/
typedef void (*CALLBACK_LOG_FUNC)(char *szMsg);

#ifdef __cplusplus     
extern "C"
{
    bool down(const char *url);
}
#else
    bool down(const char *url);
#endif
#endif
