// TableSocket.cpp : implementation file
//

#include "stdafx.h"
#include "table.h"
#include "TableSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTableSocket

CTableSocket::CTableSocket()
{
}

CTableSocket::~CTableSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CTableSocket, CSocket)
	//{{AFX_MSG_MAP(CTableSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CTableSocket member functions

void CTableSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	int iBytesRead;
    iBytesRead=Receive(Rdata_buf,sizeof(Rdata_buf)-1);//��һ�������׽ӿڽ��ܷ���˳����������ݡ�
    Rdata_buf[iBytesRead] ='\0';
    CString str2=Rdata_buf;
    if(str2.Right(8)!="�����ն�")
	{
		AfxMessageBox("�յ��Ƿ����ݣ�");
		return;
	}
	else
	{
		AfxMessageBox("�������ѽ��գ�");
		return;
	}

	//int aaanum=nrnum(str2,'$');
    //CString *aaa;
    //aaa=new CString [aaanum];
	/*CString aaa[10];
    int j=str2.Find( '$' );
    for(int i=0;j!=-1;i++)
	{   
		aaa[i]=str2.Mid(0,j) ;
		str2=str2.Mid(j+1);
		j=str2.Find( '$' );
	}
	if(aaa[0]=="")
	{
		AfxMessageBox("�յ����ݣ�");
	}
	//else if(aaa[0]=
	//delete[] aaa;*/
	
	CSocket::OnReceive(nErrorCode);
}

void CTableSocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
    AfxMessageBox("�������ر�ͨ�ţ�");
	AfxGetApp()->m_pMainWnd->DestroyWindow();
	CSocket::OnClose(nErrorCode);
}

/*int CTableSocket::nrnum(CString nr,CString bz)//�����Ϣ���е���Ϣ��λ����Ŀ
{
int j=nr.Find(bz);
int i;
for(i=0;j!=-1;i++)
{   
	nr=nr.Mid(j+bz.GetLength());
	j=nr.Find(bz);
}
return i;

}*/
