#if !defined(AFX_TABLESOCKET_H__0F49CACE_0CD9_4670_A9EB_CC6074D6C338__INCLUDED_)
#define AFX_TABLESOCKET_H__0F49CACE_0CD9_4670_A9EB_CC6074D6C338__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TableSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CTableSocket command target

class CTableSocket : public CSocket  
{
// Attributes
public:

// Operations
public:
	CTableSocket();
	virtual ~CTableSocket();

// Overrides
public:
	char Rdata_buf[1024];
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTableSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CTableSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABLESOCKET_H__0F49CACE_0CD9_4670_A9EB_CC6074D6C338__INCLUDED_)
