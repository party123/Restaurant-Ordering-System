// tables.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
#include "tables.h"
#include "Dtables.h"
#include "ADOconn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ctables dialog


Ctables::Ctables(CWnd* pParent /*=NULL*/)
	: CDialog(Ctables::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ctables)
	m_name = _T("");
	m_ID = _T("");
	//}}AFX_DATA_INIT
}


void Ctables::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ctables)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_ID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ctables, CDialog)
	//{{AFX_MSG_MAP(Ctables)
	ON_BN_CLICKED(IDC_add, Onadd)
	ON_BN_CLICKED(IDC_delete, Ondelete)
	ON_BN_CLICKED(IDC_flash, Onflash)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ctables message handlers

void Ctables::Onadd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CDtables table;
	table.Setname(_ttoi(m_name));
	table.Setstate(0);
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
	vSQL="select * from tables  where name='"+m_name+"' ";
    m_AdoConn.GetRecordSet(vSQL);
	if(!m_AdoConn.m_pRecordset->adoEOF )
	{
		AfxMessageBox("该桌号已存在！");
		return;
	}
	if(IDYES==AfxMessageBox("是否保存添加?",MB_YESNO))
		table.sql_insert();
	this->Onflash();
}

void Ctables::Ondelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CDtables table;
	table.SetID(_ttoi(m_ID));
	if(IDYES==AfxMessageBox("是否删除该桌号?",MB_YESNO))
	{	
		
		table.sql_delete();
	}	
	this->Onflash();
}

void Ctables::Onflash() 
{
	// TODO: Add your control notification handler code here
	m_name="";
	m_ID="";
	UpdateData(false);
	m_list.DeleteAllItems();
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from tables ");
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

void Ctables::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
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

BOOL Ctables::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"ID",LVCFMT_LEFT,0,0);
	m_list.InsertColumn(1,"桌号",LVCFMT_LEFT,150,1);

	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from tables ");
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
