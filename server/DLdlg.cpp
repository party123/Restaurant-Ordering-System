// DLdlg.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
#include "DLdlg.h"
#include "ADOconn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLdlg dialog


CDLdlg::CDLdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDLdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLdlg)
	m_usr = _T("");
	m_pwd = _T("");
	//}}AFX_DATA_INIT
}


void CDLdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLdlg)
	DDX_Text(pDX, IDC_EDIT1, m_usr);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLdlg, CDialog)
	//{{AFX_MSG_MAP(CDLdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLdlg message handlers

void CDLdlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	m_usr.TrimLeft();
	m_usr.TrimRight();
	m_pwd.TrimLeft();
	m_pwd.TrimRight();
	if(m_usr=="")
	{
		AfxMessageBox("用户名不能为空");
		return;
	}
	else if(m_pwd=="")
	{
		AfxMessageBox("密码不能为空");
		return;
	}
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t vSQL;
	vSQL="select * from admin  where usr='"+m_usr+"' and pwd='"+m_pwd+"' ";
    m_AdoConn.GetRecordSet(vSQL);
	
	if(m_AdoConn.m_pRecordset->adoEOF)
	{
		AfxMessageBox("用户名与密码不匹配，请重新输入！");
	    m_usr="";
		m_pwd="";
		UpdateData(false);
		return;
		 
	}
	m_AdoConn.ExitConnect();
	CDialog::OnOK();
}
