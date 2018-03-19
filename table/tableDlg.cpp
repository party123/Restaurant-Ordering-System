// tableDlg.cpp : implementation file
//

#include "stdafx.h"
#include "table.h"
#include "tableDlg.h"
#include "ADOconn.h"
#include "Dorders.h"

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
// CTableDlg dialog

CTableDlg::CTableDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTableDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTableDlg)
	m_chename = _T("");
	m_name = _T("");
	m_price = _T("");
	m_ID = _T("");
	m_cheID = _T("");
	m_cheprice = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTableDlg)
	DDX_Control(pDX, IDC_tijiao, m_tijiao);
	DDX_Control(pDX, IDC_COMBO3, m_type);
	DDX_Control(pDX, IDC_COMBO1, m_zhuohao);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Text(pDX, IDC_EDIT3, m_chename);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_price);
	DDX_Text(pDX, IDC_EDIT4, m_ID);
	DDX_Text(pDX, IDC_EDIT5, m_cheID);
	DDX_Text(pDX, IDC_EDIT6, m_cheprice);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTableDlg, CDialog)
	//{{AFX_MSG_MAP(CTableDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_kaizhuo, Onkaizhuo)
	ON_BN_CLICKED(IDC_btdiancai, Onbtdiancai)
	ON_BN_CLICKED(IDC_tijiao, Ontijiao)
	ON_BN_CLICKED(IDC_checai, Onchecai)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, OnClickList2)
	ON_CBN_SELENDOK(IDC_COMBO3, OnSelendokCombo3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTableDlg message handlers

BOOL CTableDlg::OnInitDialog()
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
	//tablesock.Create(0,SOCK_STREAM);

    m_list1.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_FULLROWSELECT);
	m_list1.InsertColumn(0,"ID",LVCFMT_LEFT,0,0);
	m_list1.InsertColumn(1,"菜名",LVCFMT_LEFT,120,1);
	m_list1.InsertColumn(2,"价格",LVCFMT_LEFT,120,2);

    m_list2.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_FULLROWSELECT);
	m_list2.InsertColumn(0,"ID",LVCFMT_LEFT,0,0);
	m_list2.InsertColumn(1,"菜名",LVCFMT_LEFT,120,1);
	m_list2.InsertColumn(2,"价格",LVCFMT_LEFT,120,2);

	//向comobox1里加数据
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql2;
	CString strstate;
	strstate.Format("%d",0);
	sql2.Format("select * from tables where state='"+strstate+"' ");
	m_AdoConn.GetRecordSet((_bstr_t)sql2);
	int j=0;
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		CString s=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name");
		m_zhuohao.AddString(s);	
		
		j++;
		m_AdoConn.m_pRecordset->MoveNext();
	}
		m_AdoConn.ExitConnect();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTableDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTableDlg::OnPaint() 
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
HCURSOR CTableDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTableDlg::Onkaizhuo() 
{
	// TODO: Add your control notification handler code here
	CString str;
	m_zhuohao.GetWindowText(str);
		//int nIndex =m_zhuohao.GetCurSel();
		//m_zhuohao.GetLBText( nIndex, str);
	if(str=="")
	{
		AfxMessageBox("开桌前请先选桌号");
		return;
	}
	tablesock.Create(0,SOCK_STREAM);
	if(tablesock.Connect("127.0.0.1",6802)==0)//从客户端程序的本地套接口向服务端程序的本地套接口发起连接动作。
	{
	   AfxMessageBox("连接服务器失败！");
       OnCancel();
	}
	else
	{  
		AfxMessageBox("开桌成功！");
        m_tijiao.EnableWindow(true);
	    CString mess="餐桌客户端$开桌$"+str+"$";
        tablesock.Send(mess,mess.GetLength());
	  	//AfxMessageBox("消息发送成功！");
		ADOconn m_AdoConn;
	    m_AdoConn.OnInitADOConn();

		CString strstate;
	    strstate.Format("%d",1);
	    _bstr_t vSQL;
	    vSQL="update tables set state='"+strstate+"' where name='"+str+"' ";
	    m_AdoConn.ExecuteSQL(vSQL);

	//向comobox2里加数据
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
    
	m_zhuohao.EnableWindow(false);
	}
}

void CTableDlg::Onbtdiancai() 
{
	// TODO: Add your control notification handler code here
	m_list2.InsertItem(0,"");
	m_list2.SetItemText(0,0,m_ID);
	m_list2.SetItemText(0,1,m_name);
	m_list2.SetItemText(0,2,m_price);
}

void CTableDlg::Ontijiao() 
{
	// TODO: Add your control notification handler code here
	CString zh;
	m_zhuohao.GetWindowText(zh);
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	
	CString sql3;
	sql3.Format("select * from tables where name='"+zh+"'");
	m_AdoConn.GetRecordSet((_bstr_t)sql3);
    int ii=0;
	CString aa;
    while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		aa=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ID");	
		ii++;
		m_AdoConn.m_pRecordset->MoveNext();
	}   

	CTime t = CTime::GetCurrentTime();
    CDorders order;
	order.Setstate(0);
	order.Settables_ID(_ttoi(aa));
	order.Setorders_time(t);
	order.Setsettle_time(t);

	//算总价
	int he=0;
	int num = m_list2.GetItemCount();
	for(int h=0;h<num;h++)
	{
		CString s=m_list2.GetItemText(h,2);
		int iprice=_ttoi(s);
		 he=iprice+he;		
	}
    order.Settotal_price(he);

	if(IDYES==AfxMessageBox("是否提交订单?",MB_YESNO))
	{
		order.sql_insert();

	//插入order_dish表
	_bstr_t vSQL;	
	vSQL="select * from orders  where tables_ID ='"+zh+"' ";
    m_AdoConn.GetRecordSet(vSQL);
	int i=0;
	CString oid;
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		oid=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ID");
		m_AdoConn.m_pRecordset->MoveNext();
	}
    
    int num2 = m_list2.GetItemCount();
	for(int hh=0;hh<num2;hh++)
	{
		CString dishid=m_list2.GetItemText(hh,0);
		CString price2=m_list2.GetItemText(hh,2);
		_bstr_t dSQL;
	    CString dishstate;
		dishstate.Format("%d",0);
	    dSQL="INSERT INTO orders_dish(dish_ID,orders_ID,price,state) VALUES('"+dishid+"','"+oid+"','"+price2+"','"+dishstate+"')";
	    m_AdoConn.ExecuteSQL(dSQL);
		
		 	
	}

	m_AdoConn.ExitConnect();
	
    //把订单号发给server
	CString mess="餐桌客户端$提交订单$"+oid+"$";
    tablesock.Send(mess,mess.GetLength());
	//AfxMessageBox("成功提交订单！");


	//m_zhuohao.EnableWindow(true);
	}
}

void CTableDlg::Onchecai() 
{
	// TODO: Add your control notification handler code here
	if(m_chename=="")
	{
		return;
	}
	if(IDYES==AfxMessageBox("是否删除该菜品?",MB_YESNO))
	{	
		int i=m_list2.GetSelectionMark();
		m_list2.DeleteItem(i);
		m_chename="";
		UpdateData(false);
	}	
}

void CTableDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i=m_list1.GetSelectionMark();//获得选中行的行标
	CString s=m_list1.GetItemText(i,1);//(行，列)
	CString ss=m_list1.GetItemText(i,0);
	CString s2=m_list1.GetItemText(i,2);
	
	m_name=s;
	m_ID=ss;
    m_price=s2;

	UpdateData(false);
	*pResult = 0;
}

void CTableDlg::OnClickList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i=m_list2.GetSelectionMark();//获得选中行的行标
	CString s=m_list2.GetItemText(i,1);//(行，列)
	CString ss=m_list2.GetItemText(i,0);
	CString s2=m_list2.GetItemText(i,2);
		
	m_chename=s;
	m_cheID=ss;
	m_cheprice=s2;
   

	UpdateData(false);
	*pResult = 0;
}


void CTableDlg::OnSelendokCombo3() 
{
	// TODO: Add your control notification handler code here
	m_list1.DeleteAllItems();
	CString str2;
    int nIndex =m_type.GetCurSel();
	m_type.GetLBText( nIndex, str2);

     	//m_type.GetWindowText(str2);
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
		
	CString sql3;
	sql3.Format("select * from dish_type where name='"+str2+"'");
	m_AdoConn.GetRecordSet((_bstr_t)sql3);
    int ii=0;
	CString aa;
    while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		aa=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ID");	
		ii++;
		m_AdoConn.m_pRecordset->MoveNext();
	}             
	CString sql;
	sql.Format("select * from dish where dish_type_ID='"+aa+"'");
	m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i=0;
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{	
		m_list1.InsertItem(i,"");
		m_list1.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ID"));	
		m_list1.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name"));
		m_list1.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("price"));
		i++;
		m_AdoConn.m_pRecordset->MoveNext();
	}
		m_AdoConn.ExitConnect();
}


