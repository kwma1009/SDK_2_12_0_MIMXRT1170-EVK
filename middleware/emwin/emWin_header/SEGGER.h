/*********************************************************************
*                SEGGER Microcontroller GmbH                         *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2021  SEGGER Microcontroller GmbH                *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V6.24 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The software has been licensed to  NXP Semiconductors USA, Inc.  whose
registered  office  is  situated  at 411 E. Plumeria Drive, San  Jose,
CA 95134, USA  solely for  the  purposes  of  creating  libraries  for
NXPs M0, M3/M4 and  ARM7/9 processor-based  devices,  sublicensed  and
distributed under the terms and conditions of the NXP End User License
Agreement.
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
Licensing information
Licensor:                 SEGGER Microcontroller Systems LLC
Licensed to:              NXP Semiconductors, 1109 McKay Dr, M/S 76, San Jose, CA 95131, USA
Licensed SEGGER software: emWin
License number:           GUI-00186
License model:            emWin License Agreement, dated August 20th 2011 and Amendment No. 1, dated October 17th 2017 and Amendment No. 2, dated December 18th 2018
Licensed platform:        NXP's ARM 7/9, Cortex-M0, M3, M4, M7, A7, M33
----------------------------------------------------------------------
Support and Update Agreement (SUA)
SUA period:               2011-08-19 - 2022-09-02
Contact to extend SUA:    sales@segger.com
----------------------------------------------------------------------
File    : SEGGER.h
Purpose : Global types etc & general purpose utility functions
Revision: $Rev: 6176 $
---------------------------END-OF-HEADER------------------------------
*/

#ifndef SEGGER_H            // Guard against multiple inclusion
#define SEGGER_H

#include <stdarg.h>
#include "Global.h"         // Type definitions: U8, U16, U32, I8, I16, I32

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       Keywords/specifiers
*
**********************************************************************
*/

#ifndef INLINE
  #ifdef _WIN32
    //
    // Microsoft VC6 and newer.
    // Force inlining without cost checking.
    //
    #define INLINE  __forceinline
  #else
    #if (defined(__GNUC__))
      //
      // Force inlining with GCC
      //
      #define INLINE inline __attribute__((always_inline))
    #elif (defined(__ICCARM__) || defined(__CC_ARM) || defined(__RX) || defined(__ICCRX__))
      //
      // Other known compilers.
      //
      #define INLINE  inline
    #else
      //
      // Unknown compilers.
      //
      #define INLINE
    #endif
  #endif
#endif

/*********************************************************************
*
*       Function-like macros
*
**********************************************************************
*/

#define SEGGER_COUNTOF(a)          (sizeof((a))/sizeof((a)[0]))
#define SEGGER_MIN(a,b)            (((a) < (b)) ? (a) : (b))
#define SEGGER_MAX(a,b)            (((a) > (b)) ? (a) : (b))

#ifndef   SEGGER_USE_PARA                   // Some compiler complain about unused parameters.
  #define SEGGER_USE_PARA(Para) (void)Para  // This works for most compilers.
#endif

#define SEGGER_ADDR2PTR(Type, Addr)  (/*lint -e(923) -e(9078)*/((Type*)((PTR_ADDR)(Addr))))    // Allow cast from address to pointer.
#define SEGGER_PTR2ADDR(p)           (/*lint -e(923) -e(9078)*/((PTR_ADDR)(p)))                // Allow cast from pointer to address.
#define SEGGER_PTR2PTR(Type, p)      (/*lint -e(740) -e(826) -e(9079) -e(9087)*/((Type*)(p)))  // Allow cast from one pointer type to another (ignore different size).
#define SEGGER_PTR_DISTANCE(p0, p1)  (SEGGER_PTR2ADDR(p0) - SEGGER_PTR2ADDR(p1))


/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

#define SEGGER_PRINTF_FLAG_ADJLEFT    (1 << 0)
#define SEGGER_PRINTF_FLAG_SIGNFORCE  (1 << 1)
#define SEGGER_PRINTF_FLAG_SIGNSPACE  (1 << 2)
#define SEGGER_PRINTF_FLAG_PRECEED    (1 << 3)
#define SEGGER_PRINTF_FLAG_ZEROPAD    (1 << 4)
#define SEGGER_PRINTF_FLAG_NEGATIVE   (1 << 5)

/*********************************************************************
*
*       Types
*
**********************************************************************
*/

typedef struct {
  char* pBuffer;
  int   BufferSize;
  int   Cnt;
} SEGGER_BUFFER_DESC;

typedef struct {
  int  CacheLineSize;                                 // 0: No Cache. Most Systems such as ARM9 use a 32 bytes cache line size.
  void (*pfDMB)       (void);                         // Optional DMB function for Data Memory Barrier to make sure all memory operations are completed.
  void (*pfClean)     (void *p, unsigned NumBytes);   // Optional clean function for cached memory.
  void (*pfInvalidate)(void *p, unsigned NumBytes);   // Optional invalidate function for cached memory.
} SEGGER_CACHE_CONFIG;

typedef struct SEGGER_SNPRINTF_CONTEXT_struct SEGGER_SNPRINTF_CONTEXT;

struct SEGGER_SNPRINTF_CONTEXT_struct {
  void*               pContext;                       // Application specific context.
  SEGGER_BUFFER_DESC* pBufferDesc;                    // Buffer descriptor to use for output.
  void (*pfFlush)(SEGGER_SNPRINTF_CONTEXT *);         // Callback executed once the buffer is full. Callback decides if the buffer gets cleared to store more or not.
};

typedef struct {
  void (*pfStoreChar)       (SEGGER_BUFFER_DESC* pBufferDesc, SEGGER_SNPRINTF_CONTEXT* pContext, char c);
  int  (*pfPrintUnsigned)   (SEGGER_BUFFER_DESC* pBufferDesc, SEGGER_SNPRINTF_CONTEXT* pContext, U32 v, unsigned Base, char Flags, int Width, int Precision);
  int  (*pfPrintInt)        (SEGGER_BUFFER_DESC* pBufferDesc, SEGGER_SNPRINTF_CONTEXT* pContext, I32 v, unsigned Base, char Flags, int Width, int Precision);
} SEGGER_PRINTF_API;

typedef void (*SEGGER_pFormatter)(SEGGER_BUFFER_DESC* pBufferDesc, SEGGER_SNPRINTF_CONTEXT* pContext, const SEGGER_PRINTF_API* pApi, va_list* pParamList, char Lead, int Width, int Precision);

typedef struct SEGGER_PRINTF_FORMATTER {
  struct SEGGER_PRINTF_FORMATTER* pNext;              // Pointer to next formatter.
  SEGGER_pFormatter               pfFormatter;        // Formatter function.
  char                            Specifier;          // Format specifier.
} SEGGER_PRINTF_FORMATTER;

/*********************************************************************
*
*       Utility functions
*
**********************************************************************
*/

void SEGGER_ARM_memcpy(void* pDest, const void* pSrc, int NumBytes);
void SEGGER_memcpy    (void* pDest, const void* pSrc, int NumBytes);
void SEGGER_memxor    (void* pDest, const void* pSrc, unsigned NumBytes);

void SEGGER_StoreChar    (SEGGER_BUFFER_DESC* pBufferDesc, char c);
void SEGGER_PrintUnsigned(SEGGER_BUFFER_DESC* pBufferDesc, U32 v, unsigned Base, int Precision);
void SEGGER_PrintInt     (SEGGER_BUFFER_DESC* pBufferDesc, I32 v, unsigned Base, int Precision);
int  SEGGER_snprintf     (char* pBuffer, int BufferSize, const char* sFormat, ...);
int  SEGGER_vsnprintf    (char* pBuffer, int BufferSize, const char* sFormat, va_list ParamList);
int  SEGGER_vsnprintfEx  (SEGGER_SNPRINTF_CONTEXT* pContext, const char* sFormat, va_list ParamList);

int  SEGGER_PRINTF_AddFormatter      (SEGGER_PRINTF_FORMATTER* pFormatter, SEGGER_pFormatter pfFormatter, char c);
void SEGGER_PRINTF_AddDoubleFormatter(void);
void SEGGER_PRINTF_AddIPFormatter    (void);
void SEGGER_PRINTF_AddHTMLFormatter  (void);

int      SEGGER_strncasecmp(const char *sText1, const char *sText2, unsigned Count);
int      SEGGER_strcasecmp (const char *sText1, const char *sText2);
int      SEGGER_tolower    (int c);
unsigned SEGGER_strlen     (const char* s);
int      SEGGER_isalpha    (int c);
int      SEGGER_isalnum    (int c);
int      SEGGER_atoi       (const char* s);

#if defined(__cplusplus)
}                /* Make sure we have C-declarations in C++ programs */
#endif

#endif                      // Avoid multiple inclusion

/*************************** End of file ****************************/
