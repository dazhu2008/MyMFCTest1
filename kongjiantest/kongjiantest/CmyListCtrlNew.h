#pragma once


// CmyListCtrlNew

class CmyListCtrlNew : public CListCtrl
{
	DECLARE_DYNAMIC(CmyListCtrlNew)

public:
	CmyListCtrlNew();
	virtual ~CmyListCtrlNew();
	void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	void SetItemColor(DWORD iItem, COLORREF color);
	CMap<DWORD , DWORD& , COLORREF , COLORREF&> MapItemColor;

protected:
	DECLARE_MESSAGE_MAP()
	
};


