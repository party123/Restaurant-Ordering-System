; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Cjiesuan
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "server.h"

ClassCount=11
Class1=CServerApp
Class2=CServerDlg
Class3=CAboutDlg

ResourceCount=11
Resource1=IDD_caipin
Resource2=IDR_MAINFRAME
Resource3=IDD_jiesuanDlg
Resource4=IDD_ABOUTBOX
Class4=Ccaipinleixing
Class5=CServerSocket
Resource5=IDD_DLdlg
Class6=Cadmin
Resource6=IDD_caipinleixingDlg
Class7=Ccaipin
Resource7=IDD_SERVER_DIALOG
Class8=Ctables
Resource8=IDD_tableDlg
Class9=CDLdlg
Resource9=IDD_chazhang
Class10=Cjiesuan
Resource10=IDD_adminDlg
Class11=Chistory
Resource11=IDR_MENU1

[CLS:CServerApp]
Type=0
HeaderFile=server.h
ImplementationFile=server.cpp
Filter=N
LastObject=CServerApp

[CLS:CServerDlg]
Type=0
HeaderFile=serverDlg.h
ImplementationFile=serverDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CServerDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=serverDlg.h
ImplementationFile=serverDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SERVER_DIALOG]
Type=1
Class=CServerDlg
ControlCount=4
Control1=IDC_BUTTON1,button,1208025088
Control2=IDC_close,button,1342242816
Control3=IDC_BUTTON2,button,1342242816
Control4=IDC_EDIT1,edit,1484849280

[MNU:IDR_MENU1]
Type=1
Class=CServerDlg
Command1=ID_MENUcaipinleixing
Command2=ID_MENUcaipin
Command3=ID_MENUadmin
Command4=ID_MENUtable
Command5=ID_MENUjiesuan
Command6=ID_MENUchazhang
Command7=ID_MENUabout
CommandCount=7

[DLG:IDD_caipinleixingDlg]
Type=1
Class=Ccaipinleixing
ControlCount=12
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_search,button,1342242816
Control5=IDC_flash,button,1342242816
Control6=IDC_add,button,1342242816
Control7=IDC_delete,button,1342242816
Control8=IDC_update,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT2,edit,1350631552
Control11=IDC_LIST1,SysListView32,1350631425
Control12=IDC_EDIT4,edit,1216413824

[CLS:Ccaipinleixing]
Type=0
HeaderFile=caipinleixing.h
ImplementationFile=caipinleixing.cpp
BaseClass=CDialog
Filter=D
LastObject=Ccaipinleixing
VirtualFilter=dWC

[CLS:CServerSocket]
Type=0
HeaderFile=ServerSocket.h
ImplementationFile=ServerSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CServerSocket
VirtualFilter=q

[DLG:IDD_adminDlg]
Type=1
Class=Cadmin
ControlCount=16
Control1=IDCANCEL,button,1342242816
Control2=IDC_LIST1,SysListView32,1350631425
Control3=IDC_name,edit,1350631552
Control4=IDC_usr,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_pwd,edit,1350631584
Control10=IDC_pwd2,edit,1350631584
Control11=IDC_add,button,1342242816
Control12=IDC_update,button,1342242816
Control13=IDC_delete,button,1342242816
Control14=IDC_STATIC,static,1342308352
Control15=IDC_flash,button,1342242816
Control16=IDC_EDIT1,edit,1216413824

[CLS:Cadmin]
Type=0
HeaderFile=admin.h
ImplementationFile=admin.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=Cadmin

[DLG:IDD_caipin]
Type=1
Class=Ccaipin
ControlCount=15
Control1=IDCANCEL,button,1342242816
Control2=IDC_LIST1,SysListView32,1350631425
Control3=IDC_add,button,1342242816
Control4=IDC_update,button,1342242816
Control5=IDC_delete,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_keyword,edit,1350631552
Control8=IDC_search,button,1342242816
Control9=IDC_flash,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_name,edit,1350631552
Control13=IDC_price,edit,1350631552
Control14=IDC_EDIT1,edit,1216413824
Control15=IDC_EDIT2,edit,1216413824

[CLS:Ccaipin]
Type=0
HeaderFile=caipin.h
ImplementationFile=caipin.cpp
BaseClass=CDialog
Filter=D
LastObject=Ccaipin
VirtualFilter=dWC

[DLG:IDD_tableDlg]
Type=1
Class=Ctables
ControlCount=7
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_add,button,1342242816
Control5=IDC_delete,button,1342242816
Control6=IDC_flash,button,1342242816
Control7=IDC_EDIT2,edit,1216413824

[CLS:Ctables]
Type=0
HeaderFile=tables.h
ImplementationFile=tables.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST1
VirtualFilter=dWC

[DLG:IDD_DLdlg]
Type=1
Class=CDLdlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_EDIT2,edit,1350631584

[CLS:CDLdlg]
Type=0
HeaderFile=DLdlg.h
ImplementationFile=DLdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDLdlg

[DLG:IDD_jiesuanDlg]
Type=1
Class=Cjiesuan
ControlCount=7
Control1=IDC_Btjiesuan,button,1342242816
Control2=IDC_COMBO1,combobox,1344340226
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1484849280
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BUTTON1,button,1342242816

[CLS:Cjiesuan]
Type=0
HeaderFile=jiesuan.h
ImplementationFile=jiesuan.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT2
VirtualFilter=dWC

[DLG:IDD_chazhang]
Type=1
Class=Chistory
ControlCount=3
Control1=IDC_search,button,1342242816
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_STATIC,static,1342308352

[CLS:Chistory]
Type=0
HeaderFile=history.h
ImplementationFile=history.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

