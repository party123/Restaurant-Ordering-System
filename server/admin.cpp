// admin.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
#include "admin.h"
#include "ADOconn.h"
#include "Dadmin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cadmin dialog

CString nn;
Cadmin::Cadmin(CWnd* pParent /*=NULL*/)
	: CDialog(Cadmin::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cadmin)
	m_name = _T("");
	m_pwd = _T("");
	m_pwd2 = _T("");
	m_usr = _T("");
	m_ID = _T("");
	//}}AFX_DATA_INIT
}


void Cadmin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cadmin)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_name, m_name);
	DDX_Text(pDX, IDC_pwd, m_pwd);
	DDX_Text(pDX, IDC_pwd2, m_pwd2);
	DDX_Text(pDX, IDC_usr, m_usr);
	DDX_Text(pDX, IDC_EDIT1, m_ID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cadmin, CDialog)
	//{{AFX_MSG_MAP(Cadmin)
	ON_BN_CLICKED(IDC_add, Onadd)
	ON_BN_CLICKED(IDC_delete, Ondelete)
	ON_BN_CLICKED(IDC_flash, Onflash)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_update, Onupdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cadmin message handlers

void Cadmin::Onadd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CDadmin adm;
	adm.Setname(m_name);
	adm.Setusr(m_usr);
	adm.Setpwd(m_pwd);
	m_name.TrimLeft();
	m_name.TrimRight();
	m_usr.TrimLeft();
	m_usr.TrimRight();
	m_pwd.TrimLeft();
	m_pwd.TrimRight();
	m_pwd2.TrimLeft();
	m_pwd2.TrimRight();
	

	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t vSQL;
	vSQL="select * from admin  where usr='"+m_usr+"'  ";
    m_AdoConn.GetRecordSet(vSQL);
	if(!m_AdoConn.m_pRecordset->adoEOF)
	{
		AfxMessageBox("该用户名已存在！");
		return;
	}
	else if(m_name==""|m_usr==""|m_pwd==""|m_pwd2=="")
	{
		AfxMessageBox("请将信息填写完整！");
		return;
	}
	
	else if(m_pwd!=m_pwd2)
	{
		AfxMessageBox("两次密码不一致！");
		return;
	}
	if(IDYES==AfxMessageBox("是否保存添加?",MB_YESNO))
		adm.sql_insert();
	this->Onflash();	
}

void Cadmin::Ondelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CDadmin adm;
	adm.SetID(_ttoi(m_ID));
	if(IDYES==AfxMessageBox("是否删除该用户?",MB_YESNO))
	{	
		
		adm.sql_delete();
	}	
	this->Onflash();
}

void Cadmin::Onflash() 
{
	// TODO: Add your control notification handler code here
	m_name="";
	m_ID="";
	m_usr="";
	m_pwd="";
	m_pwd2="";
	UpdateData(false);
	m_list.DeleteAllItems();
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from admin ");
	m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i=0;
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		
		m_list.InsertItem(i,"");
		m_list.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ID"));
		m_list.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name"));
		m_list.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("usr"));
		//m_list.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("pwd"));
		i++;
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
}

BOOL Cadmin::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"ID",LVCFMT_LEFT,0,0);
	m_list.InsertColumn(1,"姓名",LVCFMT_LEFT,100,1);
	m_list.InsertColumn(2,"用户名",LVCFMT_LEFT,100,2);
	//m_list.InsertColumn(3,"密码",LVCFMT_LEFT,0,3);

	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from admin ");
	m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i=0;	

	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		
		m_list.InsertItem(i,"");
		m_list.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ID"));	
		
		m_list.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name"));
		m_list.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("usr"));
		//m_list.SetItemText(i,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("pwd"));
		
		i++;
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
	return true;
}

void Cadmin::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i=m_list.GetSelectionMark();//获得选中行的行标
	CString s=m_list.GetItemText(i,1);//(行，列)
	CString ss=m_list.GetItemText(i,0);
	CString s2=m_list.GetItemText(i,2);
	
	m_name=s;
	m_ID=ss;
    m_usr=s2;
    nn=m_usr;
	UpdateData(false);
	*pResult = 0;
}

void Cadmin::Onupdate() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	
	CDadmin adm;
	adm.SetID(_ttoi(m_ID));
	adm.Setname(m_name);
	adm.Setusr(m_usr);
	adm.Setpwd(m_pwd);
	m_name.TrimLeft();
	m_name.TrimRight();
	m_usr.TrimLeft();
	m_usr.TrimRight();
	m_pwd.TrimLeft();
	m_pwd.TrimRight();
	m_pwd2.TrimLeft();
	m_pwd2.TrimRight();

    ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t vSQL;
	vSQL="select * from admin  where usr='"+m_usr+"' ";
    m_AdoConn.GetRecordSet(vSQL);
	
  if(m_name==""|m_usr==""|m_pwd==""|m_pwd2=="")
	{
		AfxMessageBox("请将信息填写完整！");
		return;
	}
	
	else if(m_pwd!=m_pwd2)
	{
		AfxMessageBox("两次密码不一致！");
		return;
	}
	if(!m_AdoConn.m_pRecordset->adoEOF )
	{
		if(m_usr!=nn)
		{
			AfxMessageBox("该改后的用户名已存在！");
			return;
		}
		
	}

	if(IDYES==AfxMessageBox("是否保存修改?",MB_YESNO))		
	{
		adm.sql_update();
	}
	this->Onflash();
}
