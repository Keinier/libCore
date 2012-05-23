#ifndef __PLATAFORM_H__
#define __PLATAFORM_H__
/**********************************************************************
 * File Name: Plataform.h
 * File Description: Configure data type and common macros for compiler
 * File Autor: Keinier Caboverde <Keinier@gmail.com> 
 * Skype: Keinier Caboverde <keiniercab>
 * Twitter: @Keinier

 * */
#	if defined(WIN32)
#		include<windows.h>
#		define Object HANDLE
// Todo lo que va para windows
#	else
// Todo lo que va para linux
#		define Object void*
		typedef void            VOID;       /* Void data type             */
		typedef int	        BOOL;       /* Boolean data type          */
		typedef signed char     CHAR;       /*  8-bit signed data type    */
		typedef unsigned char   BYTE;       /*  8-bit unsigned data type  */
		typedef int		INT;        /* 16-bit signed data type    */
		typedef unsigned short  WORD;       /* 16-bit unsigned data type  */
		typedef signed long     LONG;       /* 32-bit signed data type    */
		typedef unsigned long   DWORD;      /* 32-bit unsigned data type  */
		typedef unsigned int	UINT;
		typedef unsigned long	ULONG;
		typedef ULONG*		PULONG;
		typedef unsigned short	USHORT;
		typedef USHORT*		PUSHORT;
		typedef unsigned char	UCHAR;
		typedef UCHAR*		PUCHAR;
		typedef char*		PSZ;
		typedef WORD*	PWORD;
		typedef WORD*	LPWORD;
		typedef UINT		WPARAM;
		typedef LONG		LPARAM;
		typedef LONG		LRESULT;
#	endif

#	if defined(USE_STL)
// Librerias pertenecientes a STL
#		include<string>
#		include<iostream>
#		include<cstdio>
#		include<cstdlib>
#		define String string
using namespace std;
#	else
// Librerias pertenecientes a las bbliotecas estandar de windows que NO son STL
#		include<string.h>
#		include<stdio.h>
#		include<stdlib.h>
#		define near /* nothing */
#		define far /* nothing */
#		define String char*
#	endif


#	include <stddef.h>                 /* Standard ANSI definitions  */
#	include <limits.h>

#	define FALSE           0           /* FALSE boolean data value   */
#	define TRUE            !FALSE      /* TRUE boolean data value    */


                
/*
**  A variety of macros used to tear down and build up words of data.
*/
#	define LOBYTE(w)       ((BYTE) (w))
#	define HIBYTE(w)       ((BYTE) ((0x00FF & (WORD) ((w) >>  8))))
#	define LOWORD(d)       ((WORD) (d))
#	define HIWORD(d)       ((WORD) ((0xFFFF & (DWORD)((d) >> 16))))
#	define MAKEWORD(h,l)   (((WORD)  ((WORD)  (h) <<  8)) | (WORD) ((BYTE) (l)))
#	define MAKEDWORD(h,l)  (((DWORD) ((DWORD) (h) << 16)) | (DWORD)((WORD) (l)))

/*
**  A variety of macros used to test/flip bits within words of data.
*/
/* Flip the specified bit to 0 */
#	define BITCLEAR(field, bit)  ((field) & ~(bit))
/* Flip the specified bit to 1 */
#	define BITSET(field, bit)    ((field) | (bit))
/* Flip the specified bit to its inverse state */
#	define BITTOG(field, bit)    ((field) ^ (bit))
/* Create a string of 0 bits from n to m */
#	define BITSON(n, m)          (~(~0 << (m) << 0) & (~0 << (n)))
/* Create a string of 1 bits from n to m */
#	define BITSOFF(n, m)         (~(~0 << (m) << 1) & (~0 << (n)))


/* Structure copy macro */
#	if defined(__STDC__)
#		define assignstruct(a, b)  ((a) = (b))
#	else
#		define assignstruct(a, b)  (memcpy((char*)&(a), (char *)&(b),sizeof(a)))
#	endif

#	if !defined(offsetof)
#		define offsetof(s, m)  ((size_t)&(((s *)0)->m))
#	endif

#	if !defined(max)
#		define max(a,b)        (((a) > (b)) ? (a) : (b))
#	endif

#	if !defined(min)
#		define min(a,b)        (((a) < (b)) ? (a) : (b))
#	endif

#	if defined(__SHARED__)
#		if defined(WIN32)
#			if defined(USRDLL)
#				define APIEXPORT __declspec(dllexport)
#			else
#				define APIEXPORT __declspec(dllimport)
#			endif
#		else
#			define APIEXPORT
#		endif
#	else
#			define APIEXPORT 
#	endif


#endif // __PLATAFORM_H__