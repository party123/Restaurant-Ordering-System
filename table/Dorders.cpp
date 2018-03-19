// Dorders.cpp: implementation of the CDorders class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "table.h"
#include "Dorders.h"
#include "ADOconn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDorders::CDorders()
{

}

CDorders::~CDorders()
{

}

int CDorders::GetID()
{
	return ID;
}

int CDorders::Gettables_ID()
{
	return tables_ID;
}

int CDorders::Gettotalprice()
{
	return total_price;
}

CTime CDorders::Getorders_time()
{
	return orders_time;
}

CTime CDorders::Getsettle_time()
{
return settle_time;
}

int CDorders::Getstate()
{
	return state;

}

void CDorders::sql_insert()
{
	ADOconn m_AdoConn;
	_bstr_t vSQL;
	CString strprice;	
	strprice.Format("%d",total_price);
	CString strtableID;
	strtableID.Format("%d",tables_ID);
	CString strstate;
	strstate.Format("%d",state);
	CString FyTime;
    FyTime.Format("%02i-%02i-%02i %02i:%02i:%02i",orders_time.GetYear(),orders_time.GetMonth(),orders_time.GetDay(),orders_time.GetHour(), orders_time.GetMinute(),orders_time.GetSecond()); 
	vSQL="INSERT INTO orders(tables_ID,total_price,state,orders_time) VALUES('"+strtableID+"','"+strprice+"','"+strstate+"','"+FyTime+"')";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}

void CDorders::SetID(int id)
{
 ID=id;
}

void CDorders::Settables_ID(int id)
{
tables_ID=id;
}

void CDorders::Setorders_time(CTime t)
{
orders_time=t;
}

void CDorders::Setsettle_time(CTime t)
{
settle_time=t;
}

void CDorders::Setstate(int s)
{
state=s;
}

void CDorders::Settotal_price(int p)
{
total_price=p;
}
