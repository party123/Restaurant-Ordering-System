// jiesuan.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
#include "jiesuan.h"
#include "ADOconn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cjiesuan dialog


Cjiesuan::Cjiesuan(CWnd* pParent /*=NULL*/)
	: CDialog(Cjiesuan::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cjiesuan)
	m_price = _T("");
	//}}AFX_DATA_INIT
}


void Cjiesuan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cjiesuan)
	DDX_Control(pDX, IDC_COMBO1, m_name);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cjiesuan, CDialog)
	//{{AFX_MSG_MAP(Cjiesuan)
	ON_BN_CLICKED(IDC_Btjiesuan, OnBtjiesuan)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cjiesuan message handlers

void Cjiesuan::OnBtjiesuan() 
{
	// TODO: Add your control notification handler code here
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
    CString strstate;
	strstate.Format("%d",0);
	_bstr_t vSQL;
	CString str;
	m_name.GetWindowText(str);
	vSQL="update tables set state='"+strstate+"' where name='"+str+"' ";
	m_AdoConn.ExecuteSQL(vSQL);
		
	CString sql3;
	sql3.Format("select * from tables where name='"+str+"'");
	m_AdoConn.GetRecordSet((_bstr_t)sql3);
    int ii=0;
	CString aa;
    while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		aa=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ID");	
		ii++;
		m_AdoConn.m_pRecordset->MoveNext();
	}  
	CString sql4;
	sql4.Format("select * from orders where tables_ID='"+str+"' and state='"+strstate+"'");
	m_AdoConn.GetRecordSet((_bstr_t)sql4);
    
	CString aac;
	//CString orders;
	//CString settle;
    while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		aac=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("total_price");
		//orders=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("orders_time");
		//settle=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("settle_time");
		m_price=aac;
		//m_settle=settle;
		//m_orders=orders;
		UpdateData(false);
		m_AdoConn.m_pRecordset->MoveNext();
	}   

    

	_bstr_t vSQL2;
	CString strstate2;
	strstate2.Format("%d",1);
	CString strstate3;
	strstate3.Format("%d",0);
	CTime t = CTime::GetCurrentTime();
	CString FyTime;
    FyTime.Format("%02i-%02i-%02i %02i:%02i:%02i",t.GetYear(),t.GetMonth(),t.GetDay(),t.GetHour(), t.GetMinute(),t.GetSecond()); 
    vSQL2="update orders set settle_time='"+FyTime+"',state='"+strstate2+"' where tables_ID='"+str+"' and state='"+strstate3+"' ";
	m_AdoConn.ExecuteSQL(vSQL2);
	m_AdoConn.ExitConnect();

	//AfxMessageBox("结算成功");
	//this->flash();
}

BOOL Cjiesuan::OnInitDialog()
{
	CDialog::OnInitDialog();
	//m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_FULLROWSELECT);
	//m_list.InsertColumn(0,"ID",LVCFMT_LEFT,0,0);
	//m_list.InsertColumn(1,"菜名",LVCFMT_LEFT,120,1);
	//m_list.InsertColumn(2,"价格",LVCFMT_LEFT,120,2);


	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql2;
	CString strstate;
	strstate.Format("%d",1);
	sql2.Format("select * from tables where state='"+strstate+"' ");
	m_AdoConn.GetRecordSet((_bstr_t)sql2);
	int j=0;
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		CString s=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name");
		m_name.AddString(s);	
		
		j++;
		m_AdoConn.m_pRecordset->MoveNext();
	}
		m_AdoConn.ExitConnect();
		
		return true;
}


void Cjiesuan::flash()
{
	m_name.ResetContent();
	m_price="";
	UpdateData(false);
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql2;
	CString strstate;
	strstate.Format("%d",1);
	sql2.Format("select * from tables where state='"+strstate+"' ");
	m_AdoConn.GetRecordSet((_bstr_t)sql2);
	int j=0;
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		CString s=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name");
		m_name.AddString(s);	
		
		j++;
		m_AdoConn.m_pRecordset->MoveNext();
	}
		m_AdoConn.ExitConnect();
}

void Cjiesuan::OnButton1() 
{
	// TODO: Add your control notification handler code here
	this->flash();
}
