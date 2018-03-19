// caipinleixing.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
#include "caipinleixing.h"
#include "dish_type.h"
#include "ADOconn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ccaipinleixing dialog


Ccaipinleixing::Ccaipinleixing(CWnd* pParent /*=NULL*/)
	: CDialog(Ccaipinleixing::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ccaipinleixing)
	m_keyword = _T("");
	m_name = _T("");
	m_ID = _T("");
	//}}AFX_DATA_INIT
}


void Ccaipinleixing::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ccaipinleixing)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_update, m_update);
	DDX_Control(pDX, IDC_search, m_search);
	DDX_Control(pDX, IDC_flash, m_flash);
	DDX_Control(pDX, IDC_delete, m_delete);
	DDX_Control(pDX, IDC_add, m_add);
	DDX_Text(pDX, IDC_EDIT1, m_keyword);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT4, m_ID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ccaipinleixing, CDialog)
	//{{AFX_MSG_MAP(Ccaipinleixing)
	ON_BN_CLICKED(IDC_add, Onadd)
	ON_BN_CLICKED(IDC_delete, Ondelete)
	ON_BN_CLICKED(IDC_flash, Onflash)
	ON_BN_CLICKED(IDC_search, Onsearch)
	ON_BN_CLICKED(IDC_update, Onupdate)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ccaipinleixing message handlers

void Ccaipinleixing::Onadd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	Cdish_type dish;
	dish.Setname(m_name);
	m_name.TrimLeft();
	m_name.TrimRight();
	
	if(m_name=="")
	{
		AfxMessageBox("您尚未填写信息");
		return;
	}
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t vSQL;
	vSQL="select * from dish_type  where name='"+m_name+"' ";
    m_AdoConn.GetRecordSet(vSQL);
	if(!m_AdoConn.m_pRecordset->adoEOF )
	{
		AfxMessageBox("该菜品类型已存在！");
		return;
	}
	if(IDYES==AfxMessageBox("是否保存添加?",MB_YESNO))
		dish.sql_insert();
	this->Onflash();			
}

void Ccaipinleixing::Ondelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	Cdish_type dish;
	dish.SetID(_ttoi(m_ID));
	if(IDYES==AfxMessageBox("是否删除该菜品类型?",MB_YESNO))
	{	
		//int bh=dish.GetID();		
		dish.sql_delete();
	}	
	this->Onflash();
}

void Ccaipinleixing::Onflash() 
{
	// TODO: Add your control notification handler code here
	m_name="";
	m_ID="";
	m_keyword="";
	UpdateData(false);
	m_list.DeleteAllItems();
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from dish_type ");
	m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i=0;
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		
		m_list.InsertItem(i,"");
		m_list.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ID"));
		m_list.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name"));
		i++;
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
	
}

void Ccaipinleixing::Onsearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_keyword=="")
	{
		AfxMessageBox("请输入查询关键词");
		return;
	}
	m_list.DeleteAllItems();
	ADOconn m_AdoConn;
	_bstr_t vSQL;
	
	vSQL="select * from dish_type  where name like '%"+m_keyword+"%' ";
	//m_AdoConn.ExecuteSQL(vSQL);
    m_AdoConn.GetRecordSet(vSQL);
	int i=0;
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		
		m_list.InsertItem(i,"");
		m_list.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ID"));
		m_list.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name"));
		i++;
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
}

void Ccaipinleixing::Onupdate() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	Cdish_type dish;
	dish.SetID(_ttoi(m_ID));
	dish.Setname(m_name);
	m_name.TrimLeft();
	m_name.TrimRight();
	
	if(m_name=="")
	{
		AfxMessageBox("您尚未填写信息");
		return;
	}
	if(IDYES==AfxMessageBox("是否保存修改?",MB_YESNO))		
	{
		dish.sql_update();
	}
	this->Onflash();

}

BEGIN_EVENTSINK_MAP(Ccaipinleixing, CDialog)
    //{{AFX_EVENTSINK_MAP(Ccaipinleixing)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()


BOOL Ccaipinleixing::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"ID",LVCFMT_LEFT,0,0);
	m_list.InsertColumn(1,"类型名称",LVCFMT_LEFT,180,1);

	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from dish_type ");
	m_AdoConn.GetRecordSet((_bstr_t)sql);
	int i=0;
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		
		m_list.InsertItem(i,"");
		m_list.SetItemText(i,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("ID"));
		m_list.SetItemText(i,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name"));
		i++;
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
	return true;
}

void Ccaipinleixing::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
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
