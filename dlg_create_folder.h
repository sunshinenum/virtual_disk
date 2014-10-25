#if !defined(AFX_DLG_CREATE_FOLDER_H__F2DA3D11_3733_4B27_B5BF_51DFD709D60F__INCLUDED_)
#define AFX_DLG_CREATE_FOLDER_H__F2DA3D11_3733_4B27_B5BF_51DFD709D60F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlg_create_folder.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// dlg_create_folder dialog

class dlg_create_folder : public CDialog
{
// Construction
public:
	dlg_create_folder(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(dlg_create_folder)
	enum { IDD = IDD_DIALOG_CREATE_FOLDER };
	CString	m_folder_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(dlg_create_folder)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(dlg_create_folder)
	afx_msg void OnButtonCreate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(dlg_create_folder)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_CREATE_FOLDER_H__F2DA3D11_3733_4B27_B5BF_51DFD709D60F__INCLUDED_)
