// history.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
#include "history.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Chistory dialog


Chistory::Chistory(CWnd* pParent /*=NULL*/)
	: CDialog(Chistory::IDD, pParent)
{
	//{{AFX_DATA_INIT(Chistory)
	m_orderid = _T("");
	//}}AFX_DATA_INIT
}


void Chistory::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Chistory)
	DDX_Text(pDX, IDC_EDIT1, m_orderid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Chistory, CDialog)
	//{{AFX_MSG_MAP(Chistory)
	ON_BN_CLICKED(IDC_search, Onsearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Chistory message handlers

void Chistory::Onsearch() 
{
	// TODO: Add your control notification handler code here
	
}
