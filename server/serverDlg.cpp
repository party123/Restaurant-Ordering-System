// serverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
#include "serverDlg.h"
#include "caipinleixing.h"
#include "ServerSocket.h"
#include "caipin.h"
#include "tables.h"
#include "admin.h"
#include "DLdlg.h"
#include "jiesuan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



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
// CServerDlg dialog

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServerDlg)
	m_testnet = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerDlg)
	DDX_Text(pDX, IDC_EDIT1, m_testnet);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	//{{AFX_MSG_MAP(CServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENUcaipinleixing, OnMENUcaipinleixing)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_close, Onclose)
	ON_COMMAND(ID_MENUabout, OnMENUabout)
	ON_COMMAND(ID_MENUadmin, OnMENUadmin)
	ON_COMMAND(ID_MENUcaipin, OnMENUcaipin)
	ON_COMMAND(ID_MENUtable, OnMENUtable)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_COMMAND(ID_MENUjiesuan, OnMENUjiesuan)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg message handlers

BOOL CServerDlg::OnInitDialog()
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

    
	CDLdlg dl;
	if(dl.DoModal()==IDOK)
	{
	
	}
	else
	{
	OnCancel();
	}
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CServerDlg::OnPaint() 
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
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CServerDlg::OnMENUcaipinleixing() 
{
	// TODO: Add your command handler code here
	Ccaipinleixing cai;
	cai.DoModal();
}

void CServerDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	  CString mess="ddd$服务终端";
	sockListen.Send(mess,mess.GetLength());
	 AfxMessageBox("消息发送成功！");
}

void CServerDlg::Onclose() 
{
	// TODO: Add your control notification handler code here
	sockListen.OnSubSocketClose();
	sockListen.Close();
	m_testnet="已关闭通信功能";
    UpdateData(FALSE);
}

void CServerDlg::OnMENUabout() 
{
	// TODO: Add your command handler code here
	CAboutDlg ab;
	ab.DoModal();
}

void CServerDlg::OnMENUadmin() 
{
	// TODO: Add your command handler code here
	Cadmin ad;
	ad.DoModal();
}

void CServerDlg::OnMENUcaipin() 
{
	// TODO: Add your command handler code here
	Ccaipin cai;
	cai.DoModal();
}

void CServerDlg::OnMENUtable() 
{
	// TODO: Add your command handler code here
	Ctables tab;
	tab.DoModal();
}

void CServerDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	sockListen.Create(6802,SOCK_STREAM);// 建立一个本地套接口。
	sockListen.Listen(30);//启动服务器端本地套接口的等待客户访问状态，
    m_testnet="通信功能启动成功";
    UpdateData(FALSE);
}

void CServerDlg::OnMENUjiesuan() 
{
	// TODO: Add your command handler code here
	Cjiesuan jie;
	jie.DoModal();
}
