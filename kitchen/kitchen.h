// kitchen.h : main header file for the KITCHEN application
//

#if !defined(AFX_KITCHEN_H__E1A10014_AD25_4FF4_9821_C697F11EBAD0__INCLUDED_)
#define AFX_KITCHEN_H__E1A10014_AD25_4FF4_9821_C697F11EBAD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKitchenApp:
// See kitchen.cpp for the implementation of this class
//

class CKitchenApp : public CWinApp
{
public:
	CKitchenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKitchenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CKitchenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KITCHEN_H__E1A10014_AD25_4FF4_9821_C697F11EBAD0__INCLUDED_)
