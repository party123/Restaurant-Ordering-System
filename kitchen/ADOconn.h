// ADOconn.h: interface for the ADOconn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__7096CB9A_4B94_4391_AA4A_E00D676EE0C9__INCLUDED_)
#define AFX_ADOCONN_H__7096CB9A_4B94_4391_AA4A_E00D676EE0C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ADOconn  
{
public:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	
public:
	ADOconn();
	virtual ~ADOconn();

	void OnInitADOConn();
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	void ExitConnect();


};

#endif // !defined(AFX_ADOCONN_H__7096CB9A_4B94_4391_AA4A_E00D676EE0C9__INCLUDED_)
