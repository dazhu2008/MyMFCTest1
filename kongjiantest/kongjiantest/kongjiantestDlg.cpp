
// kongjiantestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "kongjiantest.h"
#include "kongjiantestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

CkongjiantestDlg::CkongjiantestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CkongjiantestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CkongjiantestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_FacLogCtl);
	DDX_Control(pDX, IDC_EDIT_TIME, m_MESState);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_EDIT1, mEdit);
}

BEGIN_MESSAGE_MAP(CkongjiantestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CkongjiantestDlg::OnBnClickedButton1)
	ON_WM_CTLCOLOR()
	ON_MESSAGE(WM_DEVICECHANGE, OnMyDeviceChange)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &CkongjiantestDlg::OnNMDblclkList)
END_MESSAGE_MAP()


// CkongjiantestDlg 消息处理程序

BOOL CkongjiantestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	int iColsWidth[12] = {72, 50, 60, 50, 37, 50, 50, 70, 35, 36, 45, 100};
	int iColsWidthTrace[6] = {90, 80, 80, 50, 60, 120};
	m_FacLogCtl.InsertColumn(0, _T("ItemCode"), LVCFMT_RIGHT, iColsWidth[1]);
	m_FacLogCtl.InsertColumn(1, _T("Band"), LVCFMT_LEFT, iColsWidth[2]);
	m_FacLogCtl.InsertColumn(2, _T("Channel"), LVCFMT_LEFT, iColsWidth[3]);
	m_FacLogCtl.InsertColumn(3, _T("ErrorCode"), LVCFMT_RIGHT, iColsWidth[4]);
	m_FacLogCtl.InsertColumn(4, _T("UpperBound"), LVCFMT_RIGHT, iColsWidth[5]);
	m_FacLogCtl.InsertColumn(5, _T("LowerBound"), LVCFMT_RIGHT, iColsWidth[6]);
	m_FacLogCtl.InsertColumn(6, _T("EvaluatedValue"), LVCFMT_RIGHT, iColsWidth[7]);
	m_FacLogCtl.InsertColumn(7, _T("Unit"), LVCFMT_RIGHT, iColsWidth[8]);
	m_FacLogCtl.InsertColumn(8, _T("Pass/Fail"), LVCFMT_CENTER, iColsWidth[9]);
	m_FacLogCtl.InsertColumn(10, _T("Message"), LVCFMT_LEFT, iColsWidth[11]);
	m_FacLogCtl.InsertColumn(9, _T("Time"), LVCFMT_LEFT, iColsWidth[0]);
	m_FacLogCtl.SetColumnWidth(10, LVSCW_AUTOSIZE_USEHEADER);
	m_FacLogCtl.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_FacLogCtl.InsertItem(0, LPCTSTR("-"));
	m_FacLogCtl.SetItemText(0, 1, LPCTSTR("-"));
	m_FacLogCtl.SetItemText(0, 2, LPCTSTR("-"));
	m_FacLogCtl.SetItemText(0, 3, LPCTSTR("-"));
// 	m_FacLogCtl.SetItemText(0, 4, LPCTSTR("-"));
// 	m_FacLogCtl.SetItemText(0, 5, LPCTSTR("-"));
// 	m_FacLogCtl.SetItemText(0, 6, LPCTSTR("-"));
// 	m_FacLogCtl.SetItemText(0, 7, LPCTSTR("-"));
// 	m_FacLogCtl.SetItemText(0, 8, LPCTSTR("-"));
// 	m_FacLogCtl.SetItemText(0, 9, LPCTSTR("-"));
	m_FacLogCtl.SetItemColor(0,RGB(50, 255, 28));

	m_tab.InsertItem(0, _T("测试1"));  
	m_tab.InsertItem(1, _T("测试2")); 

	return FALSE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CkongjiantestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CkongjiantestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
// 		dc.DrawIcon(x, y, m_hIcon);
// 		CRect   rect;  
// 		CPaintDC   dc(this);  
// 		GetClientRect(rect);  
// 		dc.FillSolidRect(rect, RGB(50, 255, 28));
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CkongjiantestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CkongjiantestDlg::OnBnClickedButton1()
{
	int iIndex = m_FacLogCtl.GetItemCount();
	m_FacLogCtl.InsertItem(iIndex, LPCTSTR("-"));
	m_FacLogCtl.SetItemText(iIndex, 1, LPCTSTR("-"));
	m_FacLogCtl.SetItemText(iIndex, 2, LPCTSTR("-"));
	m_FacLogCtl.SetItemText(0, 3, LPCTSTR("+"));
	// 	m_FacLogCtl.SetItemText(0, 4, LPCTSTR("-"));
	// 	m_FacLogCtl.SetItemText(0, 5, LPCTSTR("-"));
	// 	m_FacLogCtl.SetItemText(0, 6, LPCTSTR("-"));
	// 	m_FacLogCtl.SetItemText(0, 7, LPCTSTR("-"));
	// 	m_FacLogCtl.SetItemText(0, 8, LPCTSTR("-"));
	// 	m_FacLogCtl.SetItemText(0, 9, LPCTSTR("-"));
	m_FacLogCtl.SetItemColor(iIndex,RGB(50, 255, 28));
	CString str1[100];
	CString str2[100];
	Battery_Volt_Cal();
	GetSystemPorts(str1, str2);

	WNDCLASS mwndclass;
	HINSTANCE hInstance= GetModuleHandle (0);
	mwndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	mwndclass.hCursor = LoadCursor(NULL, IDC_CROSS);
	mwndclass.hIcon = LoadIcon(NULL, IDI_ERROR);
	mwndclass.hInstance = hInstance;
	mwndclass.lpfnWndProc = (WNDPROC)OnMyDeviceChange(1,1);
	mwndclass.lpszClassName = "zhuchun";
	mwndclass.lpszMenuName = NULL;

	mwndclass.style = CS_HREDRAW | CS_VREDRAW;
	mwndclass.cbClsExtra = 0;
	mwndclass.cbWndExtra = 0;
	RegisterClass(&mwndclass);
	HWND hwnd;
	hwnd = CreateWindow("zhuchun", "hehehehehehehe",
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL,hInstance,NULL);
	ShowWindow(SW_SHOW);


}

HBRUSH CkongjiantestDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd-> GetDlgCtrlID()==IDC_EDIT_TIME)     //GetDlgCtrlID()会遍历窗口中所有的控件，返回ID
	{
		pDC-> SetTextColor(RGB(255,0,0));        //设置字体颜色
		pDC-> SetBkMode(RGB(0, 0, 255));         //设置字体背景为透明
		return (HBRUSH)::GetStockObject(BLACK_BRUSH);     // 设置背景色
	}
	else
		return hbr;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	
}

LRESULT CkongjiantestDlg::OnMyDeviceChange(WPARAM wParam, LPARAM lParam)
{
	if ( DBT_DEVICEARRIVAL == wParam || DBT_DEVICEREMOVECOMPLETE == wParam ) {
		PDEV_BROADCAST_HDR pHdr = (PDEV_BROADCAST_HDR)lParam;
		switch( pHdr->dbch_devicetype ) 
		{
		case DBT_DEVTYP_DEVICEINTERFACE:
			{
				PDEV_BROADCAST_DEVICEINTERFACE pDevInf = (PDEV_BROADCAST_DEVICEINTERFACE)pHdr;
			// do something...
				break;
			}
		case DBT_DEVTYP_HANDLE:
			{
				PDEV_BROADCAST_HANDLE pDevHnd = (PDEV_BROADCAST_HANDLE)pHdr;
			// do something...
			break;
			}
		case DBT_DEVTYP_OEM:
			{
				PDEV_BROADCAST_OEM pDevOem = (PDEV_BROADCAST_OEM)pHdr;
			// do something...
			break;
			}
		case DBT_DEVTYP_PORT:
			{
				PDEV_BROADCAST_PORT pDevPort = (PDEV_BROADCAST_PORT)pHdr;
				CString str1[100];
				CString str2[100];
				GetSystemPorts(str1, str2);
			break;
			}
		case DBT_DEVTYP_VOLUME:
			{
				PDEV_BROADCAST_VOLUME pDevVolume = (PDEV_BROADCAST_VOLUME)pHdr;
			// do something...
			break;
			}
		default:
			break;
		}
	}
	return 0;
}

int CkongjiantestDlg::GetSystemPorts(CString *pNameList, CString *pPortList)   
{   
	CRegKey RegKey;   
	int nCount = 0;   

	if(RegKey.Open(HKEY_LOCAL_MACHINE, "Hardware\\DeviceMap\\SerialComm") == ERROR_SUCCESS)   
	{   
		while(true)   
		{   
			char ValueName[_MAX_PATH];   
			unsigned char ValueData[_MAX_PATH];   
			DWORD nValueSize = _MAX_PATH;   
			DWORD nDataSize = _MAX_PATH;   
			DWORD nType;   

			if(::RegEnumValue(HKEY(RegKey), nCount, ValueName, &nValueSize, NULL, &nType, ValueData, &nDataSize) == ERROR_NO_MORE_ITEMS)   
			{   
				break;   
			}   

			if(pNameList)   
				pNameList[nCount] = ValueName;   

			if(pPortList)   
				pPortList[nCount] = ValueData;   

			nCount++;   
		}   
	}   

	return nCount;   
} 
bool CkongjiantestDlg::Battery_Volt_Cal()
{
	CString SendCMD = "";
	CString ReceiveData = "";
	CString strTmp = "";
	int i_Result,iExceptPower;
	double VRead1,VRead2,VRead3,VRead4;
	double k, b;

	//system("D:\\zhuchun\\桌面\\tmp\\tempTool\\Getlog_Ver3_60\\Getlog_Ver3_60.bat");
	//GPIB_visa.m_connectGPIB(3, "GPIB0::5::INSTR");
	//GPIB_visa.m_OpenPowerOutput(3, 2, true);
	//GPIB_visa.m_SetPowerVoltCurr(3, 1, 2.8, 2.00);
	//GPIB_visa.m_SetPowerVoltCurr(3, 2, 4.2, 2.00);
	//GPIB_visa.m_SetPowerVoltCurr(3, 1, 3.8, 2.00);
	//GPIB_visa.m_SetPowerVoltCurr(3, 1, 4, 2.00);

	return true;
}

void CkongjiantestDlg::OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;

	int m_item, m_subitem;
	m_item = pNMItemActivate->iItem;
	m_subitem = pNMItemActivate->iSubItem;
	if (m_item == -1)
	{
		return;
	}

	if (haveeditcreate == true)
	{
		if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))
		{
			distroyEdit(&m_FacLogCtl, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
			createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);
		}
		else
		{
			m_Edit.SetFocus();
		}
	}
	else
	{
		e_Item = pEditCtrl->iItem;
		e_SubItem = pEditCtrl->iSubItem;
		createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);
	}
	*pResult = 0;
}

void CkongjiantestDlg::createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat)
{
	Item = pEditCtrl->iItem;
	SubItem = pEditCtrl->iSubItem;
	createdit->Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN,
		CRect(0, 0, 0, 0), this, IDC_EDIT1);
	havecreat = true;
	createdit->SetFont(this->GetFont(), FALSE);
	createdit->SetParent(&m_FacLogCtl);
	CRect  EditRect;
	m_FacLogCtl.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);
	EditRect.SetRect(EditRect.left+1, EditRect.top+1, EditRect.left + m_FacLogCtl.GetColumnWidth(e_SubItem)-1, EditRect.bottom-1);
	CString strItem = m_FacLogCtl.GetItemText(e_Item, e_SubItem);
	createdit->SetWindowText(strItem);
	createdit->MoveWindow(&EditRect);
	createdit->ShowWindow(SW_SHOW);
	createdit->SetFocus(); 
	createdit->SetSel(-1);
}

void CkongjiantestDlg::distroyEdit(CListCtrl *list,CEdit* distroyedit, int &Item, int &SubItem)
{
	CString meditdata;
	distroyedit->GetWindowText(meditdata);
	list->SetItemText(Item, SubItem, meditdata);
	distroyedit->DestroyWindow();
}