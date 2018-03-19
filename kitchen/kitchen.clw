; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CKitchenDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "kitchen.h"

ClassCount=4
Class1=CKitchenApp
Class2=CKitchenDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CKitchenSocket
Resource3=IDD_KITCHEN_DIALOG

[CLS:CKitchenApp]
Type=0
HeaderFile=kitchen.h
ImplementationFile=kitchen.cpp
Filter=N

[CLS:CKitchenDlg]
Type=0
HeaderFile=kitchenDlg.h
ImplementationFile=kitchenDlg.cpp
Filter=D
LastObject=CKitchenDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=kitchenDlg.h
ImplementationFile=kitchenDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_KITCHEN_DIALOG]
Type=1
Class=CKitchenDlg
ControlCount=7
Control1=IDC_list,SysListView32,1350631425
Control2=IDC_name,edit,1350631552
Control3=IDC_cook,button,1342242816
Control4=IDC_COMBO1,combobox,1344340226
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BUTTON2,button,1342242816
Control7=IDC_EDIT1,edit,1216413824

[CLS:CKitchenSocket]
Type=0
HeaderFile=KitchenSocket.h
ImplementationFile=KitchenSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CKitchenSocket

