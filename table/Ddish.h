// Ddish.h: interface for the CDdish class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDISH_H__9C4BF479_9659_4005_A3D5_3FD098B99A64__INCLUDED_)
#define AFX_DDISH_H__9C4BF479_9659_4005_A3D5_3FD098B99A64__INCLUDED_

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
	void sql_delete();
    

};

#endif // !defined(AFX_DDISH_H__9C4BF479_9659_4005_A3D5_3FD098B99A64__INCLUDED_)
