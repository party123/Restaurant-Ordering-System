// KitchenSocket.cpp : implementation file
//

#include "stdafx.h"
#include "kitchen.h"
#include "KitchenSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKitchenSocket

CKitchenSocket::CKitchenSocket()
{
}

CKitchenSocket::~CKitchenSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CKitchenSocket, CSocket)
	//{{AFX_MSG_MAP(CKitchenSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CKitchenSocket member functions

void CKitchenSocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	AfxMessageBox("�������ر�ͨ�ţ�");
	AfxGetApp()->m_pMainWnd->DestroyWindow();
	CSocket::OnClose(nErrorCode);
}

void CKitchenSocket::OnReceive(int nErrorCode) 
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
		//AfxMessageBox("�յ�fuwuqi���ݣ�");
        //CString mess="�����ͻ���$ddd$";
        //Send(mess,mess.GetLength());
		
		int aaanum=nrnum(str2,'$');
        CString *aaa;
        aaa=new CString [aaanum];
        int j=str2.Find( '$' );
        for(int i=0;j!=-1;i++)
	{   
		aaa[i]=str2.Mid(0,j) ;
		str2=str2.Mid(j+1);
		j=str2.Find( '$' );
	}
	if(aaa[0]=="�ύ����")
	{
		AfxMessageBox("�յ����������ݣ�");


	}
	delete[] aaa;
      //AfxMessageBox("�յ�fuwuqi���ݣ�");
        CString mess="�����ͻ���$ddd$";
        Send(mess,mess.GetLength());  
		
	}

	
	CSocket::OnReceive(nErrorCode);
}

int CKitchenSocket::nrnum(CString nr, CString bz)
{
	int j=nr.Find(bz);
	int i;
    for(i=0;j!=-1;i++)
	{   
	  nr=nr.Mid(j+bz.GetLength());
	  j=nr.Find(bz);
	}
    return i;

}
