// Dadmin.cpp: implementation of the CDadmin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "server.h"
#include "Dadmin.h"
#include "ADOconn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDadmin::CDadmin()
{

}

CDadmin::~CDadmin()
{

}
CString CDadmin::Getname()
{
	return name;
}
int CDadmin::GetID()
{
	return ID;
}
CString CDadmin::Getusr()
{
	return usr;
}
CString CDadmin::Getpwd()
{
	return pwd;
}
void CDadmin::Setname(CString NAME)
{
	name=NAME;
}
void CDadmin::SetID(int id)
{
	ID=id;
}
void CDadmin::Setusr(CString USR)
{
	usr=USR;
}
void CDadmin::Setpwd(CString PWD)
{
	pwd=PWD;
}
void CDadmin::sql_insert()
{
	ADOconn m_AdoConn;
	_bstr_t vSQL;
	vSQL="INSERT INTO admin(name,usr,pwd) VALUES('"+name+"','"+usr+"','"+pwd+"')";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}
void CDadmin::sql_delete()
{
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from admin where ID=%d",ID);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();

}
void CDadmin::sql_update()
{
	ADOconn m_AdoConn;

	CString strID;
	strID.Format("%d",ID);
	_bstr_t vSQL;
	vSQL="update admin set name='"+name+"',usr='"+usr+"',pwd='"+pwd+"' where ID='"+strID+"' ";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}
