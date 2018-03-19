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
      
// ����socket������������ʽ�׽��֣������׽��ֺ�sockSrv   
    // SOCKET socket(int af, int type, int protocol);   
    // ��һ��������ָ����ַ��(TCP/IPֻ����AF_INET��Ҳ��д��PF_INET)   
    // �ڶ�����ѡ���׽��ֵ�����(��ʽ�׽���)�����������ض���ַ�������Э�飨0Ϊ�Զ���   
    SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);     
  
// �׽���sockSrv�뱾�ص�ַ����   
    // int bind(SOCKET s, const struct sockaddr* name, int namelen);   
    // ��һ��������ָ����Ҫ�󶨵��׽��֣�   
    // �ڶ���������ָ�����׽��ֵı��ص�ַ��Ϣ���õ�ַ�ṹ�������õ�����Э��Ĳ�ͬ����ͬ   
    // ������������ָ��������Э���ַ�ĳ���   
    // PS: struct sockaddr{ u_short sa_family; char sa_data[14];};   
    //                      sa_familyָ���õ�ַ���壬 sa_data��ռλռ��һ���ڴ������������   
    //     ��TCP/IP�У���ʹ��sockaddr_in�ṹ�滻sockaddr���Է�����д��ַ��Ϣ   
    //    
    //     struct sockaddr_in{ short sin_family; unsigned short sin_port; struct in_addr sin_addr; char sin_zero[8];};   
    //     sin_family��ʾ��ַ�壬����IP��ַ��sin_family��Ա��һֱ��AF_INET��   
    //     sin_portָ����Ҫ������׽��ֵĶ˿ڡ�   
    //     sin_addr�����׽��ֵ�����IP��ַ��   
    //     sin_zero[8]�������������sockaddr_in��sockaddr�ṹ�ĳ���һ����   
    //     ��IP��ַָ��ΪINADDR_ANY�������׽������κη�������ػ�����IP��ַ���ͻ�������ݡ�   
    //     �����ֻ���׽���ʹ�ö��IP�е�һ����ַ����ָ��ʵ�ʵ�ַ����inet_addr()������   
    SOCKADDR_IN addrSrv;  
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); // ��INADDR_ANYת��Ϊ�����ֽ��򣬵��� htonl(long��)��htons(����)   
    addrSrv.sin_family = AF_INET;  
    addrSrv.sin_port = htons(8000);  
  
    bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)); // �ڶ�����Ҫǿ������ת��   
  
// ���׽�������Ϊ����ģʽ���������󣩣� listen()֪ͨTCP������׼���ý�������   
    // int listen(SOCKET s,  int backlog);   
    // ��һ������ָ����Ҫ���õ��׽��֣��ڶ�������Ϊ���ȴ����Ӷ��е���󳤶ȣ�   
    listen(sockSrv, 10);  
  
// accept()���������ӣ��ȴ��ͻ�������   
    // SOCKET accept(  SOCKET s,  struct sockaddr* addr,  int* addrlen);   
    // ��һ������������һ�����ڼ���״̬�µ��׽���   
    // �ڶ���������sockaddr���ڱ���ͻ��˵�ַ����Ϣ   
    // ����������������ָ�������ַ�ĳ���   
    // ���ص��������������״̬�µ��׽���ͨ�ŵ��׽���   
  
// �ͻ������û��˽���ͨ��   
  
    // send(), ���׽����Ϸ�������   
    // int send( SOCKET s,  const char* buf,  int len,  int flags);   
    // ��һ����������Ҫ������Ϣ���׽��֣�   
    // �ڶ�����������������Ҫ�����͵����ݣ�   
    // ������������buffer�����ݳ��ȣ�   
    // ���ĸ�������һЩ���Ͳ���������   
  
    // recv(), ���׽����Ͻ�������   
    // int recv(  SOCKET s,  char* buf,  int len,  int flags);   
    // ��һ���������������Ӻ���׽��֣�   
    // �ڶ�����������������   
    // �������������������ݵĳ��ȣ�   
    // ���ĸ�������һЩ���Ͳ���������   
  
    SOCKADDR_IN  addrClient;  
    int len = sizeof(SOCKADDR);  
  
    while(true){    // ���ϵȴ��ͻ�������ĵ���   
        SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);  
          
        char sendBuf[100];  
        sprintf(sendBuf, "Welcome %s to the server program~ \nNow, let's start talking...\n", inet_ntoa(addrClient.sin_addr));  
        send(sockConn, sendBuf, strlen(sendBuf)+1, 0);  // ������ʾ��ӭ��Ϣ   
  
        char recvBuf[100];  
        recv(sockConn, recvBuf, 100, 0);  
        printf("%s\n", recvBuf);        // ���յ�һ����Ϣ   
  
        char * sockConnName = "Client";  
        closesocket(sockConn);  
    }  
  
    printf("\n");  
    system("pause");  
    return 0;  
}  
