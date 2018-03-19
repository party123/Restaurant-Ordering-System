#include <iostream>   
#include <cstdio>   
#include <Winsock2.h>   
  
using namespace std;  
  
int main()  
{  
// ����socket��̬���ӿ�(dll)   
    WORD wVersionRequested;  
    WSADATA wsaData;    // ��ṹ�����ڽ���Wjndows Socket�Ľṹ��Ϣ��   
    int err;  
       
    wVersionRequested = MAKEWORD( 1, 1 );   // ����1.1�汾��WinSock��   
       
    err = WSAStartup( wVersionRequested, &wsaData );  
    if ( err != 0 ) {  
        return -1;          // ����ֵΪ���ʱ���Ǳ�ʾ�ɹ�����WSAStartup   
    }  
       
    if ( LOBYTE( wsaData.wVersion ) != 1 || HIBYTE( wsaData.wVersion ) != 1 ) {  
        // ���������ֽ��ǲ���1�����ֽ��ǲ���1��ȷ���Ƿ������������1.1�汾   
        // ����Ļ�������WSACleanup()�����Ϣ����������   
        WSACleanup( );  
        return -1;   
    }  
      
// ����socket������������ʽ�׽��֣������׽��ֺ�sockClient   
    // SOCKET socket(int af, int type, int protocol);   
    // ��һ��������ָ����ַ��(TCP/IPֻ����AF_INET��Ҳ��д��PF_INET)   
    // �ڶ�����ѡ���׽��ֵ�����(��ʽ�׽���)�����������ض���ַ�������Э�飨0Ϊ�Զ���   
    SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);  
  
// ���׽���sockClient��Զ����������   
    // int connect( SOCKET s,  const struct sockaddr* name,  int namelen);   
    // ��һ����������Ҫ�������Ӳ������׽���   
    // �ڶ����������趨����Ҫ���ӵĵ�ַ��Ϣ   
    // ��������������ַ�ĳ���   
    SOCKADDR_IN addrSrv;  
    addrSrv.sin_addr.S_un.S_addr = inet_addr("219.230.82.50");      // ���ػ�·��ַ��127.0.0.1;    
    addrSrv.sin_family = AF_INET;  
    addrSrv.sin_port = htons(6000);  
    connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));  
  
    char recvBuf[100];  
    recv(sockClient, recvBuf, 100, 0);  
    printf("%s\n", recvBuf);  
  
    send(sockClient, "Attention: A Client has enter...\n", strlen("Attention: A Client has enter...\n")+1, 0);  
  
    printf("���ǿ�������仰");  
    closesocket(sockClient);  
    WSACleanup();   // ��ֹ���׽��ֿ��ʹ��   
  
    printf("\n");  
    system("pause");  
    return 0;  
}  
