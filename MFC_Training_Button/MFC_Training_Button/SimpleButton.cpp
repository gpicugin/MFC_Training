// SimpleButton.cpp : implementation file
//

#include "stdafx.h"
#include "SimpleButton.h"


// SimpleButton

IMPLEMENT_DYNAMIC(CSimpleButton, CButton)

CSimpleButton::CSimpleButton()
{

}

CSimpleButton::~CSimpleButton()
{
}

afx_msg void CSimpleButton::OnRButtonUp(UINT nFlags, CPoint point)
{
}

afx_msg void CSimpleButton::OnLButtonUp(UINT nFlags, CPoint point)
{
}


BEGIN_MESSAGE_MAP(CSimpleButton, CButton)
	ON_WM_LBUTTONDOWN() // ��������� � ������� ���
	ON_WM_RBUTTONDOWN() // ��������� � ������� ���
END_MESSAGE_MAP()



// SimpleButton message handlers


