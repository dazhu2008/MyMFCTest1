// CmyListCtrlNew.cpp : 实现文件
//

#include "stdafx.h"
#include "kongjiantest.h"
#include "CmyListCtrlNew.h"


// CmyListCtrlNew

IMPLEMENT_DYNAMIC(CmyListCtrlNew, CListCtrl)

CmyListCtrlNew::CmyListCtrlNew()
{

}

CmyListCtrlNew::~CmyListCtrlNew()
{
}


BEGIN_MESSAGE_MAP(CmyListCtrlNew, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnNMCustomdraw)
END_MESSAGE_MAP()



void CmyListCtrlNew::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = CDRF_DODEFAULT;
	NMLVCUSTOMDRAW * lplvdr=(NMLVCUSTOMDRAW*)pNMHDR;
	NMCUSTOMDRAW &nmcd = lplvdr->nmcd;
	switch(lplvdr->nmcd.dwDrawStage)
	{
	case CDDS_PREPAINT:
		{
			*pResult = CDRF_NOTIFYITEMDRAW;
			break;
		}
	case CDDS_ITEMPREPAINT:
		{
			COLORREF ItemColor;
			if(MapItemColor.Lookup(nmcd.dwItemSpec, ItemColor))
			{
				lplvdr->clrTextBk = ItemColor;
				*pResult = CDRF_DODEFAULT;
			}
		}
		break;
	}


}
void CmyListCtrlNew::SetItemColor(DWORD iItem, COLORREF color)
{
	MapItemColor.SetAt(iItem, color);
	this->RedrawItems(iItem, iItem);
	this->SetFocus();
	UpdateWindow();
}
