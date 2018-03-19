// Ddish.cpp: implementation of the CDdish class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "server.h"
#include "Ddish.h"
#include "ADOconn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDdish::CDdish()
{

}

CDdish::~CDdish()
{

}
CString CDdish::Getname()
{
	return name;
}
int CDdish::GetID()
{
	return ID;
}
int CDdish::Getprice()
{
	return price;
}
void CDdish::Setname(CString NAME)
{
	name=NAME;
}
void CDdish::SetID(int id)
{
	ID=id;
}
void CDdish::Setprice(int PRICE)
{
	price=PRICE;
}
void CDdish::sql_insert()
{
	ADOconn m_AdoConn;
	_bstr_t vSQL;
	CString strprice;
	strprice.Format("%d",price);
	vSQL="INSERT INTO dish(name,price) VALUES('"+name+"','"+strprice+"')";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}
void CDdish::sql_delete()
{
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from dish where ID=%d",ID);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();

}
void CDdish::sql_update()
{
	ADOconn m_AdoConn;

	CString strID;
	strID.Format("%d",ID);
	CString strprice;
	strprice.Format("%d",price);
	_bstr_t vSQL;
	vSQL="update dish set name='"+name+"',price='"+strprice+"' where ID='"+strID+"' ";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}

