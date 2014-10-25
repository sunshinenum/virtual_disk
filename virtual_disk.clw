; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=dlg_create_disk
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "virtual_disk.h"

ClassCount=5
Class1=CVirtual_diskApp
Class2=CVirtual_diskDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_DIALOG_CREATE_DISK
Resource2=IDR_MAINFRAME
Resource3=IDD_VIRTUAL_DISK_DIALOG
Resource4=IDD_ABOUTBOX
Class4=dlg_create_folder
Class5=dlg_create_disk
Resource5=IDD_DIALOG_CREATE_FOLDER

[CLS:CVirtual_diskApp]
Type=0
HeaderFile=virtual_disk.h
ImplementationFile=virtual_disk.cpp
Filter=N

[CLS:CVirtual_diskDlg]
Type=0
HeaderFile=virtual_diskDlg.h
ImplementationFile=virtual_diskDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTON_COPY

[CLS:CAboutDlg]
Type=0
HeaderFile=virtual_diskDlg.h
ImplementationFile=virtual_diskDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_VIRTUAL_DISK_DIALOG]
Type=1
Class=CVirtual_diskDlg
ControlCount=52
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_DISK_NAME,edit,1350633600
Control6=IDC_EDIT_DISK_TOTAL,edit,1350633600
Control7=IDC_EDIT_DISK_REMAIN,edit,1350633600
Control8=IDC_BUTTON_DISK_IMPORT,button,1342242816
Control9=IDC_BUTTON_DISK_SAVE,button,1342242816
Control10=IDC_TREE_FILES,SysTreeView32,1350635559
Control11=IDC_BUTTON_CREATE_FILE,button,1342242816
Control12=IDC_BUTTON_CREATE_INDEX,button,1342242816
Control13=IDC_EDIT_NEW_NAME,edit,1350631552
Control14=IDC_BUTTON_RENAME,button,1342242816
Control15=IDC_BUTTON_DELETE,button,1342242816
Control16=IDC_BUTTON_FORMAT,button,1342242816
Control17=IDC_BUTTON_COPY,button,1342242816
Control18=IDC_BUTTON_CUT,button,1342242816
Control19=IDC_BUTTON_PASTE,button,1342242816
Control20=IDC_STATIC,static,1342308352
Control21=IDC_EDIT_PASTE_PAD,edit,1352730692
Control22=IDC_STATIC,static,1342308352
Control23=IDC_EDIT_CURRENT_FOLDER,edit,1352730692
Control24=IDC_EDIT_CURRENT_FILE,edit,1352730692
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,button,1342177287
Control27=IDC_STATIC,button,1342177287
Control28=IDC_STATIC,button,1342177287
Control29=IDC_STATIC,button,1342177287
Control30=IDC_BUTTON_CREATE_DISK,button,1342242817
Control31=IDC_STATIC,button,1342177287
Control32=IDC_STATIC,static,1342308352
Control33=IDC_EDIT_FCB_INDEX,edit,1350633600
Control34=IDC_STATIC,static,1342308352
Control35=IDC_EDIT_FILE_SIZE,edit,1350633600
Control36=IDC_STATIC,static,1342308352
Control37=IDC_EDIT_FILE_OFFSET,edit,1350633600
Control38=IDC_STATIC,static,1342308352
Control39=IDC_STATIC,static,1342308352
Control40=IDC_STATIC,static,1342308352
Control41=IDC_STATIC,static,1342308352
Control42=IDC_STATIC,button,1342177287
Control43=IDC_STATIC,static,1342308352
Control44=IDC_EDIT_TEST_CURRENT_OP,edit,1350633600
Control45=IDC_STATIC,static,1342308352
Control46=IDC_EDIT_TEST_LOG,edit,1352728644
Control47=IDC_BUTTON_TEST_START,button,1342242816
Control48=IDC_STATIC,static,1342308352
Control49=IDC_EDIT_FILE_UPDATE_TIME,edit,1350633600
Control50=IDC_STATIC,static,1342308352
Control51=IDC_EDIT_FILE_CREATE_TIME,edit,1350633600
Control52=IDC_BUTTON_STOP_TEST,button,1342242816

[DLG:IDD_DIALOG_CREATE_DISK]
Type=1
Class=dlg_create_disk
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_DISK_SIZE,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BUTTON_CREATE_DISK,button,1342242817
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_DISK_NAME,edit,1350631552

[DLG:IDD_DIALOG_CREATE_FOLDER]
Type=1
Class=dlg_create_folder
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_FOLDER_NAME,edit,1350631552
Control3=IDC_BUTTON_CREATE,button,1342242817

[CLS:dlg_create_folder]
Type=0
HeaderFile=dlg_create_folder.h
ImplementationFile=dlg_create_folder.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=dlg_create_folder

[CLS:dlg_create_disk]
Type=0
HeaderFile=dlg_create_disk.h
ImplementationFile=dlg_create_disk.cpp
BaseClass=CDialog
Filter=D
LastObject=dlg_create_disk
VirtualFilter=dWC

