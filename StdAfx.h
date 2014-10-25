// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__7B15EB95_5450_4E28_8675_784D76BD48D4__INCLUDED_)
#define AFX_STDAFX_H__7B15EB95_5450_4E28_8675_784D76BD48D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__7B15EB95_5450_4E28_8675_784D76BD48D4__INCLUDED_)

#include "file_system.h"
//全局磁盘起始指针
extern char* disk_start;
extern char disk_name[12];
extern disk v_disk;
extern unsigned long disk_size;

extern unsigned long fcb_number;

extern FCB file_fcb;
extern FCB folder_fcb;

extern unsigned long file_start;

extern index t_index;

extern unsigned long file_offset;//文件相对于起始的偏移量

extern CString g_folder_name;
extern bool g_is_copy;
extern bool g_is_test_stop;