// virtual_disk.h : main header file for the VIRTUAL_DISK application
//

#if !defined(AFX_VIRTUAL_DISK_H__698A6721_E450_42F2_9FB0_5C1056CC4975__INCLUDED_)
#define AFX_VIRTUAL_DISK_H__698A6721_E450_42F2_9FB0_5C1056CC4975__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVirtual_diskApp:
// See virtual_disk.cpp for the implementation of this class
//

class CVirtual_diskApp : public CWinApp
{
public:
	CVirtual_diskApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVirtual_diskApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVirtual_diskApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIRTUAL_DISK_H__698A6721_E450_42F2_9FB0_5C1056CC4975__INCLUDED_)
