#if !defined(AFX_DLG_CREATE_DISK_H__03DA48EB_8AFE_44EA_91C8_6E5C111CF8A0__INCLUDED_)
#define AFX_DLG_CREATE_DISK_H__03DA48EB_8AFE_44EA_91C8_6E5C111CF8A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlg_create_disk.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// dlg_create_disk dialog

class dlg_create_disk : public CDialog
{
// Construction
public:
	dlg_create_disk(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(dlg_create_disk)
	enum { IDD = IDD_DIALOG_CREATE_DISK };
	CString	m_disk_name;
	UINT	m_disk_size;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(dlg_create_disk)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(dlg_create_disk)
	afx_msg void OnButtonCreateDisk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_CREATE_DISK_H__03DA48EB_8AFE_44EA_91C8_6E5C111CF8A0__INCLUDED_)
