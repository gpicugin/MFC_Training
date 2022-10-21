// TestDialog.cpp : implementation file
//

//#include "pch.h"
#include "afxdialogex.h"
#include "TestDialog.h"


// TestDialog dialog

IMPLEMENT_DYNAMIC(TestDialog, CDialog)

TestDialog::TestDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{
	this->Create(IDD_DIALOG1, nullptr);
}

TestDialog::~TestDialog()
{
}

void TestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TestDialog, CDialog)
END_MESSAGE_MAP()


// TestDialog message handlers
