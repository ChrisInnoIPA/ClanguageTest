#ifndef _LIBSAMPLE_
#define _LIBSAMPLE_

enum ERROR_CODE{
	OK,
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

extern "C"{
	void 		down(void);
}
#else
extern	void            down(void);
#endif
#endif
