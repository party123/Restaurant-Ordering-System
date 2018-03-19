// Ddish.cpp: implementation of the CDdish class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "table.h"
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

void CDdish::sql_delete()
{
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from dish where ID=%d",ID);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();

}
