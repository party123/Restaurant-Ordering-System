// Dtables.cpp: implementation of the CDtables class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "server.h"
#include "Dtables.h"
#include "ADOconn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDtables::CDtables()
{

}

CDtables::~CDtables()
{

}
int CDtables::Getname()
{
	return name;
}
int CDtables::GetID()
{
	return ID;
}
int CDtables::Getstate()
{
	return state;
}
void CDtables::Setname(int NAME)
{
	name=NAME;
}
void CDtables::SetID(int id)
{
	ID=id;
}
void CDtables::Setstate(int STATE)
{
	state=STATE;
}
void CDtables::sql_insert()
{
	ADOconn m_AdoConn;
	_bstr_t vSQL;
	CString strname;
	CString strstate;
	strname.Format("%d",name);
	strstate.Format("%d",state);
	vSQL="INSERT INTO tables(name,state) VALUES('"+strname+"','"+strstate+"')";
	//vSQL="INSERT INTO tables(name) VALUES(name)";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}
void CDtables::sql_delete()
{
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from tables where ID=%d",ID);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
}
