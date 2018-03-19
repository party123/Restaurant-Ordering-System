// Dtables.h: interface for the CDtables class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DTABLES_H__312079AB_F0B5_4A3E_A3A7_5B9A8E36DEC5__INCLUDED_)
#define AFX_DTABLES_H__312079AB_F0B5_4A3E_A3A7_5B9A8E36DEC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDtables  
{
	private:
	int name;
	int ID;
	int state;
public:
	CDtables();
	virtual ~CDtables();

    int Getname();
	int GetID();
	int Getstate();
	void Setname(int NAME);
	void SetID(int id);
	void Setstate(int STATE);
	void sql_insert();
    void sql_delete();
};

#endif // !defined(AFX_DTABLES_H__312079AB_F0B5_4A3E_A3A7_5B9A8E36DEC5__INCLUDED_)
