#if !defined(AFX_KITCHENSOCKET_H__006818EB_D122_4EE4_93A6_8AE628BD4BE2__INCLUDED_)
#define AFX_KITCHENSOCKET_H__006818EB_D122_4EE4_93A6_8AE628BD4BE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KitchenSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CKitchenSocket command target

class CKitchenSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CKitchenSocket();
	virtual ~CKitchenSocket();

// Overrides
public:
	char Rdata_buf[1024];
	int nrnum(CString nr,CString bz);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKitchenSocket)
	public:
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CKitchenSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KITCHENSOCKET_H__006818EB_D122_4EE4_93A6_8AE628BD4BE2__INCLUDED_)
