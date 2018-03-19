// caipin.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
#include "caipin.h"
#include "ADOconn.h"
#include "Ddish.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ccaipin dialog


Ccaipin::Ccaipin(CWnd* pParent /*=NULL*/)
	: CDialog(Ccaipin::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ccaipin)
	m_keyword = _T("");
	m_name = _T("");
	m_type = _T("");
	m_ID = _T("");
	m_price = _T("");
	//}}AFX_DATA_INIT
}


void Ccaipin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ccaipin)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_keyword, m_keyword);
	DDX_Text(pDX, IDC_name, m_name);
    DDX_Text(pDX, IDC_EDIT2, m_type);
	DDX_Text(pDX, IDC_EDIT1, m_ID);
	DDX_Text(pDX, IDC_price, m_price);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ccaipin, CDialog)
	//{{AFX_MSG_MAP(Ccaipin)
	ON_BN_CLICKED(IDC_add, Onadd)
	ON_BN_CLICKED(IDC_delete, Ondelete)
	ON_BN_CLICKED(IDC_flash, Onflash)
	ON_BN_CLICKED(IDC_search, Onsearch)
	ON_BN_CLICKED(IDC_update, Onupdate)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ccaipin message handlers

BOOL Ccaipin::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"ID",LVCFMT_LEFT,0,0);
	//m_list.InsertColumn(1,"菜品类型",LVCFMT_LEFT,80,1);
	m_list.InsertColumn(1,"菜名",LVCFMT_LEFT,120,1);
	m_list.InsertColumn(2,"价格",LVCFMT_LEFT,120,2);

	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from dish ");
	m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i=0;
	

	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		
		m_list.InsertItem(i,"");
		m_list.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ID"));	
		
		//m_list.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("dish_type_ID"));

		m_list.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name"));
		m_list.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("price"));
		i++;
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
	return true;
}

void Ccaipin::Onadd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CDdish dish;
	dish.Setname(m_name);
	dish.Setprice(_ttoi(m_price));
	m_name.TrimLeft();
	m_name.TrimRight();
	m_price.TrimLeft();
	m_price.TrimRight();

	if(m_name==""|m_price=="")
	{
		AfxMessageBox("信息未填写完整！");
		return;
	}
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t vSQL;
	vSQL="select * from dish  where name='"+m_name+"' ";
    m_AdoConn.GetRecordSet(vSQL);
	if(!m_AdoConn.m_pRecordset->adoEOF )
	{
		AfxMessageBox("该菜品名已存在！");
		return;
	}
	if(IDYES==AfxMessageBox("是否保存添加?",MB_YESNO))
		dish.sql_insert();
	this->Onflash();		
}

void Ccaipin::Ondelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CDdish dish;
	dish.SetID(_ttoi(m_ID));
	if(IDYES==AfxMessageBox("是否删除该菜品?",MB_YESNO))
	{	
		
		dish.sql_delete();
	}	
	this->Onflash();
}

void Ccaipin::Onflash() 
{
	// TODO: Add your control notification handler code here
	m_name="";
	m_ID="";
	m_keyword="";
	m_price="";

	UpdateData(false);
	m_list.DeleteAllItems();
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from dish ");
	m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i=0;
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		
		m_list.InsertItem(i,"");
		m_list.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ID"));
		m_list.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name"));
		m_list.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("price"));
		i++;
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
}

void Ccaipin::Onsearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_keyword=="")
	{
		AfxMessageBox("请填写查询关键字！");
	}
	m_list.DeleteAllItems();
	ADOconn m_AdoConn;
	_bstr_t vSQL;
	
	vSQL="select * from dish  where name like '%"+m_keyword+"%' ";
    m_AdoConn.GetRecordSet(vSQL);
	int i=0;
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		
		m_list.InsertItem(i,"");
		m_list.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ID"));
		m_list.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name"));
		m_list.SetItemText(i,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("price"));
		i++;
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
}

void Ccaipin::Onupdate() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CDdish dish;
	dish.SetID(_ttoi(m_ID));
	dish.Setname(m_name);
	dish.Setprice(_ttoi(m_price));
	m_name.TrimLeft();
	m_name.TrimRight();
	m_price.TrimLeft();
	m_price.TrimRight();
	if(m_name==""|m_price=="")
	{
		AfxMessageBox("信息未填写完整！");
		return;
	}
	if(IDYES==AfxMessageBox("是否保存修改?",MB_YESNO))		
	{
		dish.sql_update();
	}
	this->Onflash();
}

void Ccaipin::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i=m_list.GetSelectionMark();//获得选中行的行标
	CString s=m_list.GetItemText(i,1);//(行，列)
	CString ss=m_list.GetItemText(i,0);
	CString s2=m_list.GetItemText(i,2);
	
	m_name=s;
	m_ID=ss;
    m_price=s2;

	/*ADOconn m_AdoConn;
	_bstr_t vSQL;
	vSQL="select * from dish  where name ='"+m_name+"' ";
    m_AdoConn.GetRecordSet(vSQL);
	CString typeID=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("dish_type_ID");
    _bstr_t vSQLL;
	vSQLL="select * from dish_type  where ID ='"+typeID+"' ";
	m_AdoConn.GetRecordSet(vSQLL);
	m_type=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name");*/

	UpdateData(false);
	*pResult = 0;
}
