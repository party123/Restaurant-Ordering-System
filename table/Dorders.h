// Dorders.h: interface for the CDorders class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DORDERS_H__677AB74F_3AD4_4B4B_A6E3_D08DFC788B36__INCLUDED_)
#define AFX_DORDERS_H__677AB74F_3AD4_4B4B_A6E3_D08DFC788B36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDorders  
{
	private:

	int ID;
	int tables_ID;
	int total_price;
	CTime orders_time;
	CTime settle_time;
	int state;

	
public:
	void Settotal_price(int p);
	void Setstate(int s);
	void Setsettle_time(CTime t);
	void Setorders_time(CTime t);
	void Settables_ID(int id);
	void SetID(int id);
	void sql_insert();
	int Getstate();
	CTime Getsettle_time();
	CTime Getorders_time();
	int Gettotalprice();
	int Gettables_ID();
	int GetID();
	CDorders();
	virtual ~CDorders();

    //void sql_delete();
	//void sql_update();

};

#endif // !defined(AFX_DORDERS_H__677AB74F_3AD4_4B4B_A6E3_D08DFC788B36__INCLUDED_)
