// Ddish.h: interface for the CDdish class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDISH_H__2ED9490B_2905_4D73_A22A_9EC28149BD5E__INCLUDED_)
#define AFX_DDISH_H__2ED9490B_2905_4D73_A22A_9EC28149BD5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDdish  
{
	private:
	
	CString name;
	int ID;
	int price;
	
public:
	
	
	CDdish();
	virtual ~CDdish();

	CString Getname();
	int GetID();
	int Getprice();
	void Setname(CString NAME);
	void SetID(int id);
	void Setprice(int PRICE);
	void sql_insert();
    void sql_delete();
	void sql_update();

};

#endif // !defined(AFX_DDISH_H__2ED9490B_2905_4D73_A22A_9EC28149BD5E__INCLUDED_)
