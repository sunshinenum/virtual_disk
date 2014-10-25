// dlg_create_disk.cpp : implementation file
//

#include "stdafx.h"
#include "virtual_disk.h"
#include "dlg_create_disk.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// dlg_create_disk dialog


dlg_create_disk::dlg_create_disk(CWnd* pParent /*=NULL*/)
	: CDialog(dlg_create_disk::IDD, pParent)
{
	//{{AFX_DATA_INIT(dlg_create_disk)
	m_disk_name = _T("hd01");
	m_disk_size = 100;
	//}}AFX_DATA_INIT
}


void dlg_create_disk::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(dlg_create_disk)
	DDX_Text(pDX, IDC_EDIT_DISK_NAME, m_disk_name);
	DDV_MaxChars(pDX, m_disk_name, 12);
	DDX_Text(pDX, IDC_EDIT_DISK_SIZE, m_disk_size);
	DDV_MinMaxUInt(pDX, m_disk_size, 4, 4096);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(dlg_create_disk, CDialog)
	//{{AFX_MSG_MAP(dlg_create_disk)
	ON_BN_CLICKED(IDC_BUTTON_CREATE_DISK, OnButtonCreateDisk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// dlg_create_disk message handlers

void dlg_create_disk::OnButtonCreateDisk() 
{
	// TODO: Add your control notification handler code here
	// TODO: 申请内存空间并置零
	UpdateData(TRUE);
	disk_start=new char[1024*1024*m_disk_size];
	memset(disk_start,0,1024*1024*m_disk_size);
	
	//磁盘名
	int c_str_len=m_disk_name.GetLength();
	memcpy(disk_name,m_disk_name.GetBuffer(c_str_len),c_str_len);
	disk_name[c_str_len]=0;
	
	disk_size=m_disk_size*1024*1024;
	MessageBox("磁盘创建成功。");
}
