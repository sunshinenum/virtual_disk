// dlg_create_folder.cpp : implementation file
//

#include "stdafx.h"
#include "virtual_disk.h"
#include "dlg_create_folder.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// dlg_create_folder dialog


dlg_create_folder::dlg_create_folder(CWnd* pParent /*=NULL*/)
	: CDialog(dlg_create_folder::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(dlg_create_folder)
	m_folder_name = _T("");
	//}}AFX_DATA_INIT
}


void dlg_create_folder::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void dlg_create_folder::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(dlg_create_folder)
	DDX_Text(pDX, IDC_EDIT_FOLDER_NAME, m_folder_name);
	DDV_MaxChars(pDX, m_folder_name, 32);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(dlg_create_folder, CDialog)
	//{{AFX_MSG_MAP(dlg_create_folder)
	ON_BN_CLICKED(IDC_BUTTON_CREATE, OnButtonCreate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(dlg_create_folder, CDialog)
	//{{AFX_DISPATCH_MAP(dlg_create_folder)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_Idlg_create_folder to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {E7F6A2E2-9BB7-412B-B28B-24CAF29DDDE6}
static const IID IID_Idlg_create_folder =
{ 0xe7f6a2e2, 0x9bb7, 0x412b, { 0xb2, 0x8b, 0x24, 0xca, 0xf2, 0x9d, 0xdd, 0xe6 } };

BEGIN_INTERFACE_MAP(dlg_create_folder, CDialog)
	INTERFACE_PART(dlg_create_folder, IID_Idlg_create_folder, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// dlg_create_folder message handlers

void dlg_create_folder::OnButtonCreate() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	g_folder_name=m_folder_name;
	EndDialog(0);
}
