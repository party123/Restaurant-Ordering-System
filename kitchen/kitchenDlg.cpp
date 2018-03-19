// kitchenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "kitchen.h"
#include "kitchenDlg.h"
#include "ADOconn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKitchenDlg dialog

CKitchenDlg::CKitchenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKitchenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKitchenDlg)
	m_name = _T("");
	m_ID = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKitchenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKitchenDlg)
	DDX_Control(pDX, IDC_list, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_type);
	DDX_Text(pDX, IDC_name, m_name);
	DDX_Text(pDX, IDC_EDIT1, m_ID);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CKitchenDlg, CDialog)
	//{{AFX_MSG_MAP(CKitchenDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_cook, Oncook)
	ON_NOTIFY(NM_CLICK, IDC_list, OnClicklist)
	ON_CBN_SELENDOK(IDC_COMBO1, OnSelendokCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKitchenDlg message handlers

BOOL CKitchenDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
    m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"ID",LVCFMT_LEFT,0,0);
	m_list.InsertColumn(1,"菜名",LVCFMT_LEFT,150,1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CKitchenDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKitchenDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKitchenDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CKitchenDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	kitchensock.Create(0,SOCK_STREAM,NULL);
	if(kitchensock.Connect("127.0.0.1",6802)==0)
	{
		AfxMessageBox("连接失败");
		OnCancel();
	}
	else
	{
		AfxMessageBox("连接成功");
		CString mess="厨房客户端$ddd$";
        kitchensock.Send(mess,mess.GetLength());
	  	//AfxMessageBox("消息发送成功！");
		ADOconn m_AdoConn;
	    m_AdoConn.OnInitADOConn();

	//向comobox里加数据
		CString sql2;
	    sql2.Format("select * from dish_type  ");
	    m_AdoConn.GetRecordSet((_bstr_t)sql2);
	    int j=0;
	    while(m_AdoConn.m_pRecordset->adoEOF==0)
		{
			CString s=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name");
		    m_type.AddString(s);	
		    j++;
		    m_AdoConn.m_pRecordset->MoveNext();
		}	
		m_AdoConn.ExitConnect();
    
		
		
	}
}

void CKitchenDlg::Oncook() 
{
	// TODO: Add your control notification handler code here
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
    CString strstate;
	strstate.Format("%d",1);
	_bstr_t vSQL;	
	vSQL="update orders_dish set state='"+strstate+"' where dish_ID='"+m_ID+"' ";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}

void CKitchenDlg::OnClicklist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i=m_list.GetSelectionMark();//获得选中行的行标
	CString s=m_list.GetItemText(i,1);//(行，列)
	CString ss=m_list.GetItemText(i,0);
	m_name=s;
	m_ID=ss;
   

	UpdateData(false);
	*pResult = 0;
}

void CKitchenDlg::OnSelendokCombo1() 
{
	// TODO: Add your control notification handler code here

}
