// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "server.h"
#include "ServerSocket.h"
#include "serverDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket

CServerSocket pSocket[30];

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions

void CServerSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	//���ܿͻ����󲢽���һ���������׽ӿڣ���Accept������������ʵ�֣��Ϳͻ��׽ӿ�ͨ�ŵ���Ϣ��������
	for(int i=0;i<30;i++)
	{
		int bj=pSocket[i].m_hSocket;//m_hSocket��pSocket[i]�ľ�����Ǹ����������������׽ӿڹرտ���ʱ����ֵΪ-1
		if(bj==-1)
		{
			if(!Accept(pSocket[i]))//Accept(pSocket[i])���ܿͻ����󲢽���һ�����׽ӿڡ�����Ϣ������OnAccept����
			{
				AfxMessageBox("Accept fail!");
			}
			break;
		}	  	  
	}

	CAsyncSocket::OnAccept(nErrorCode);
}

void CServerSocket::OnSubSocketClose()//�ر����б������׽ӿ�
{
	for(int i=0;i<30;i++)
	{
		int bj2=pSocket[i].m_hSocket;
		if(bj2!=-1)
		{
			pSocket[i].Close();//�ر���Ӧ��������׽ӿ�
		}
	}

}

void CServerSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	int iBytesRead;//ÿ�ν��յ���ʵ�����ݳ��ȣ��ֽ�Ϊ��λ����
	iBytesRead=Receive(Rdata_buf,sizeof(Rdata_buf)-1);//��һ���������׽ӿڽ�������
	Rdata_buf[iBytesRead]='\0';//��Rdata_buf�н��ܵ����ݵ���һ��Ԫ��Ϊ'\0'���ַ����ı�ǣ���ʹ�����ܽ����ܵ���������Ϊ�ַ�����
    CString str2=Rdata_buf;
    if(str2.Left(10)!="�����ͻ���"&str2.Left(10)!="�����ͻ���")//�Ǵӿͻ��˷�������Ϣ�εı�ʾ��
	{
		AfxMessageBox("�յ��Ƿ����ݣ�");
		return;
	}
	//CString mess="�ύ����$�����ն�";
	//Send(mess,mess.GetLength());
     CString aaa[10];////����Ϣ���а���Ϣ��λһ�����ֲ�����������ַ��ͣ�CString������aaa�����ӿͻ���������Ϣ�νṹΪ�������ͻ���$��Ϣ��λ1$��Ϣ��λ2$����$��"$"Ϊ��Ϣ��λ��ʾ������Find����������CString��ĳ�Ա��������������һ���ַ�����Ѱ��ĳ���ַ������ַ�����λ�ã����û�ҵ��ͷ���ֵ-1�� ��Mid����������CString��ĳ�Ա�����������Ǵ�һ�ַ�����ȡ��һ���֡�
     int jj=str2.Find( '$' );
     for(int i=0;jj!=-1;i++)
	 {  
		 aaa[i]=str2.Mid(0,jj);
		 str2=str2.Mid(jj+1);
		 jj=str2.Find( '$' );
	 }
	 if (aaa[1]=="����")
	 {
		 CString hao=aaa[2];
          AfxMessageBox(hao+"����������");
		  
	 }
	 else if(aaa[1]=="�ύ����")
	 {
		CString mess="�ύ����$"+aaa[2]+"$�����ն�";
	    Send(mess,mess.GetLength());
	    //AfxMessageBox("��Ϣ���ͳɹ���");
	 }
	 else if(aaa[1]="ddd")
	 {
		CString mess="ddd$�����ն�";
	    Send(mess,mess.GetLength());
	    //AfxMessageBox("��Ϣ���ͳɹ���");
		 
	 }
	 


	CAsyncSocket::OnReceive(nErrorCode);
}

void CServerSocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	//Close();// Close()�����ǹر�һ����������׽ӿڡ�
	CAsyncSocket::OnClose(nErrorCode);
}




