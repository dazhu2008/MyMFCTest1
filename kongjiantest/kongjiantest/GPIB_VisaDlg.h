#pragma once
#include "afxwin.h"
#include "visa.h"

class CGPIB_VisaDlg :
	public CDialog
{
public:
	CGPIB_VisaDlg(void);
	~CGPIB_VisaDlg(void);
public:
	bool m_PowerCurrCal();
	bool m_StandbyCurrentTest();
	bool m_BatteryOffsetTest(double dfVoltage);
	bool m_ChargeCurrentTest();
	bool m_ChargeCurrentTest_new();
	bool m_PowerOnCurrentTest();
	bool m_LeakCurrentTest();
	bool m_SetCurrRange(int nRange);
	bool m_SetPowerVoltCurr(int powerType, int nCH, double dfVolt, double dfCurr);
	bool m_OpenPowerOutput(int powerType, int nCH, bool bOpen);
	bool m_ReadPowerVoltage(double &dfVolt);
	bool m_CloseGPIB();
	bool m_connectGPIB(int powerType, char* GPIBAddr);
	bool m_GPIB_Write(char* cmd);
	bool m_GPIB_Query(char* cmd, CString &strRet);
};

