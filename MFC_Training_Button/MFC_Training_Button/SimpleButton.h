#include <afxwin.h>
#include "resource.h"
// SimpleButton

class CSimpleButton : public CButton
{
	DECLARE_DYNAMIC(CSimpleButton)

public:
	CSimpleButton();
	~CSimpleButton();

	//afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
};


