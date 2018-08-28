
// kongjiantestDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "CmyListCtrlNew.h"
#include "afxwin.h"
#include <dbt.h>
#include "GPIB_VisaDlg.h"


// CkongjiantestDlg 对话框
class CkongjiantestDlg : public CDialogEx
{
// 构造
public:
	CkongjiantestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_KONGJIANTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	
public:
	CmyListCtrlNew m_FacLogCtl;
	CEdit m_MESState;
	afx_msg void OnBnClickedButton1();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnMyDeviceChange(WPARAM wParam, LPARAM lParam);
	int GetSystemPorts(CString *pNameList, CString *pPortList);
	bool Battery_Volt_Cal();
	CGPIB_VisaDlg GPIB_visa;
	CTabCtrl m_tab;
	afx_msg void OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit mEdit;

	CEdit m_Edit;
	int e_Item;
	int e_SubItem;
	bool haveeditcreate;
	void createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat);
	void distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem);
};
