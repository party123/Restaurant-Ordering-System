// dish_type.cpp: implementation of the Cdish_type class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "server.h"
#include "dish_type.h"
#include "ADOconn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Cdish_type::Cdish_type()
{

}

Cdish_type::~Cdish_type()
{

}
CString Cdish_type::Getname()
{
	return name;
}
int Cdish_type::GetID()
{
	return ID;
}
void Cdish_type::Setname(CString NAME)
{
	name=NAME;
}
void Cdish_type::SetID(int id)
{
	ID=id;
}
void Cdish_type::sql_insert()
{
	ADOconn m_AdoConn;
	_bstr_t vSQL;
	vSQL="INSERT INTO dish_type(name) VALUES('"+name+"')";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}
void Cdish_type::sql_delete()
{
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from dish_type where ID=%d",ID);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();

}
void Cdish_type::sql_update()
{
	ADOconn m_AdoConn;
	//m_AdoConn.OnInitADOConn();
	//CString sql;
	//sql.Format("update dish_type set name='%s' where ID=%d",name,ID);
	//m_AdoConn.ExecuteSQL((_bstr_t)sql);
	CString strID;
	strID.Format("%d",ID);
	_bstr_t vSQL;
	vSQL="update dish_type set name='"+name+"' where ID='"+strID+"' ";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}