// virtual_diskDlg.h : header file
//

#if !defined(AFX_VIRTUAL_DISKDLG_H__ECC0BF90_AC12_4432_880E_69829DF6557F__INCLUDED_)
#define AFX_VIRTUAL_DISKDLG_H__ECC0BF90_AC12_4432_880E_69829DF6557F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVirtual_diskDlg dialog

class CVirtual_diskDlg : public CDialog
{
// Construction
public:
	void formatVDISK();
	void OnUpdateMyData();
	void test_del_file();
	void test_add_folder();
	void test_add_file();
	bool judege_repeat_name(CString fname);
	CString get_node_string(HTREEITEM node);
	void expand_dir(index folder,HTREEITEM dir);
	void update_disk_tree();
	void update_show_disk_info();
	void update_file_tree();
	void tree_add_file(CString filename,CString filepath);
	void get_item_path();
	void set_itempath(CString f_path,HTREEITEM& node);
	void update_disk_info();
	CVirtual_diskDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVirtual_diskDlg)
	enum { IDD = IDD_VIRTUAL_DISK_DIALOG };
	CTreeCtrl	m_tree;
	CString	m_current_file_path;
	CString	m_current_folder_path;
	CString	m_disk_name;
	UINT	m_disk_remain_space;
	UINT	m_disk_dotal_space;
	CString	m_new_name;
	CString	m_paste_pad;
	UINT	m_fcb_index;
	UINT	m_current_file_offset;
	UINT	m_current_file_size;
	CString	m_current_option;
	CString	m_test_log;
	CString	m_file_update_time;
	CString	m_file_create_time;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVirtual_diskDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVirtual_diskDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonCreateFile();
	afx_msg void OnSelchangedTreeFiles(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonCreateDisk();
	afx_msg void OnButtonFormat();
	afx_msg void OnButtonCreateIndex();
	afx_msg void OnButtonDiskSave();
	afx_msg void OnButtonDiskImport();
	afx_msg void OnButtonRename();
	afx_msg void OnButtonCopy();
	afx_msg void OnButtonCut();
	afx_msg void OnButtonPaste();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonTestStart();
	afx_msg void OnButtonStopTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CImageList m_image_list;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIRTUAL_DISKDLG_H__ECC0BF90_AC12_4432_880E_69829DF6557F__INCLUDED_)
