; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTableDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "table.h"

ClassCount=4
Class1=CTableApp
Class2=CTableDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CTableSocket
Resource3=IDD_TABLE_DIALOG

[CLS:CTableApp]
Type=0
HeaderFile=table.h
ImplementationFile=table.cpp
Filter=N

[CLS:CTableDlg]
Type=0
HeaderFile=tableDlg.h
ImplementationFile=tableDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_tijiao

[CLS:CAboutDlg]
Type=0
HeaderFile=tableDlg.h
ImplementationFile=tableDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TABLE_DIALOG]
Type=1
Class=CTableDlg
ControlCount=17
Control1=IDC_kaizhuo,button,1342242816
Control2=IDC_COMBO1,combobox,1344340226
Control3=IDC_LIST1,SysListView32,1350631425
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO3,combobox,1344340226
Control7=IDC_tijiao,button,1476460544
Control8=IDC_LIST2,SysListView32,1350631425
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT3,edit,1350631552
Control11=IDC_checai,button,1342242816
Control12=IDC_btdiancai,button,1342242816
Control13=IDC_EDIT1,edit,1216413824
Control14=IDC_EDIT2,edit,1216413824
Control15=IDC_EDIT4,edit,1216413824
Control16=IDC_EDIT5,edit,1216413824
Control17=IDC_EDIT6,edit,1216413824

[CLS:CTableSocket]
Type=0
HeaderFile=TableSocket.h
ImplementationFile=TableSocket.cpp
BaseClass=CSocket
Filter=N
LastObject=CTableSocket
VirtualFilter=uq

