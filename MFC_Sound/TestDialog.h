#pragma once
#include "afxdialogex.h"
#include "resource.h"

// TestDialog dialog

class TestDialog : public CDialog
{
	DECLARE_DYNAMIC(TestDialog)

public:
	TestDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~TestDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
