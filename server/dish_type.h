// dish_type.h: interface for the Cdish_type class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DISH_TYPE_H__62F36DEB_C1ED_4E2B_A81E_2F754BE0897F__INCLUDED_)
#define AFX_DISH_TYPE_H__62F36DEB_C1ED_4E2B_A81E_2F754BE0897F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Cdish_type  
{
private:
	
	CString name;
	int ID;
public:
	Cdish_type();
	virtual ~Cdish_type();

	CString Getname();
	int GetID();
	void Setname(CString NAME);
	void SetID(int id);
	void sql_insert();
    void sql_delete();
	void sql_update();
	//int HaveId(int iDWbh);

};

#endif // !defined(AFX_DISH_TYPE_H__62F36DEB_C1ED_4E2B_A81E_2F754BE0897F__INCLUDED_)
