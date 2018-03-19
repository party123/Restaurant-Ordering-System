// Dadmin.h: interface for the CDadmin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DADMIN_H__0E611F94_4004_4A72_9C7C_EE9ED5368F46__INCLUDED_)
#define AFX_DADMIN_H__0E611F94_4004_4A72_9C7C_EE9ED5368F46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDadmin  
{
	private:	
	CString name;
	CString usr;
	int ID;
	CString pwd;
public:
	CDadmin();
	virtual ~CDadmin();
	CString Getname();
	int GetID();
	CString Getusr();
	CString Getpwd();
	void Setname(CString NAME);
	void SetID(int id);
	void Setusr(CString usr);
	void Setpwd(CString pwd);
	void sql_insert();
    void sql_delete();
	void sql_update();

};

#endif // !defined(AFX_DADMIN_H__0E611F94_4004_4A72_9C7C_EE9ED5368F46__INCLUDED_)
