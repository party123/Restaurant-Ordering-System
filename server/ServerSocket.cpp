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
	//接受客户请求并建立一个本地子套接口（用Accept（……）函数实现）和客户套接口通信的消息处理函数。
	for(int i=0;i<30;i++)
	{
		int bj=pSocket[i].m_hSocket;//m_hSocket是pSocket[i]的句柄，是个整数，当本地子套接口关闭空闲时，其值为-1
		if(bj==-1)
		{
			if(!Accept(pSocket[i]))//Accept(pSocket[i])接受客户请求并建立一个子套接口。与消息处理函数OnAccept区别
			{
				AfxMessageBox("Accept fail!");
			}
			break;
		}	  	  
	}

	CAsyncSocket::OnAccept(nErrorCode);
}

void CServerSocket::OnSubSocketClose()//关闭所有本地子套接口
{
	for(int i=0;i<30;i++)
	{
		int bj2=pSocket[i].m_hSocket;
		if(bj2!=-1)
		{
			pSocket[i].Close();//关闭相应活动本地子套接口
		}
	}

}

void CServerSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	int iBytesRead;//每次接收到的实际数据长度（字节为单位）。
	iBytesRead=Receive(Rdata_buf,sizeof(Rdata_buf)-1);//从一个本地子套接口接受数据
	Rdata_buf[iBytesRead]='\0';//让Rdata_buf中接受的数据的下一个元素为'\0'（字符串的标记），使程序能将接受的数据认作为字符串。
    CString str2=Rdata_buf;
    if(str2.Left(10)!="餐桌客户端"&str2.Left(10)!="厨房客户端")//是从客户端发出的信息段的标示符
	{
		AfxMessageBox("收到非法数据！");
		return;
	}
	//CString mess="提交订单$服务终端";
	//Send(mess,mess.GetLength());
     CString aaa[10];////从信息段中把信息单位一个个分拆出来，存入字符型（CString）数组aaa。，从客户端来的信息段结构为：餐桌客户端$信息单位1$信息单位2$……$，"$"为信息单位标示符，，Find（……）是CString类的成员函数，作用是在一个字符串中寻找某个字符或子字符串的位置，如果没找到就返回值-1。 ，Mid（……）是CString类的成员函数，作用是从一字符串中取出一部分。
     int jj=str2.Find( '$' );
     for(int i=0;jj!=-1;i++)
	 {  
		 aaa[i]=str2.Mid(0,jj);
		 str2=str2.Mid(jj+1);
		 jj=str2.Find( '$' );
	 }
	 if (aaa[1]=="开桌")
	 {
		 CString hao=aaa[2];
          AfxMessageBox(hao+"号桌开桌！");
		  
	 }
	 else if(aaa[1]=="提交订单")
	 {
		CString mess="提交订单$"+aaa[2]+"$服务终端";
	    Send(mess,mess.GetLength());
	    //AfxMessageBox("消息发送成功！");
	 }
	 else if(aaa[1]="ddd")
	 {
		CString mess="ddd$服务终端";
	    Send(mess,mess.GetLength());
	    //AfxMessageBox("消息发送成功！");
		 
	 }
	 


	CAsyncSocket::OnReceive(nErrorCode);
}

void CServerSocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	//Close();// Close()作用是关闭一个服务端子套接口。
	CAsyncSocket::OnClose(nErrorCode);
}




