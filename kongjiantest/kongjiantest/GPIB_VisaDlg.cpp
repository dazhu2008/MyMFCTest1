#include "stdafx.h"
#include "GPIB_VisaDlg.h"

#define CHECK(A)	if(!(A)) return false;

ViSession g_defaultRM = 0;
ViSession g_instr = 0;

CGPIB_VisaDlg::CGPIB_VisaDlg(void)
{
}

CGPIB_VisaDlg::~CGPIB_VisaDlg(void)
{
}

//extern CVRTestDlg::eGPIBSetting m_GPIBSetting;

bool CGPIB_VisaDlg::m_PowerCurrCal()
{
	return true;
}
bool CGPIB_VisaDlg::m_StandbyCurrentTest()
{
	return true;
}
bool CGPIB_VisaDlg::m_BatteryOffsetTest(double dfVoltage)
{
	return true;
}
bool CGPIB_VisaDlg::m_ChargeCurrentTest()
{
	return true;
}
bool CGPIB_VisaDlg::m_ChargeCurrentTest_new()
{
	return true;
}
bool CGPIB_VisaDlg::m_PowerOnCurrentTest()
{
	return true;
}
bool CGPIB_VisaDlg::m_LeakCurrentTest()
{
	return true;
}
bool CGPIB_VisaDlg::m_SetCurrRange(int nRange)
{
	return true;
}
bool CGPIB_VisaDlg::m_SetPowerVoltCurr(int powerType, int nCH, double dfVolt, double dfCurr)
{
	//1 AGILENT_663XX
	//2 KEITHLEY2304
	//3.KEITHLEY2306
	//4.AGILENT_E363XX
	CString strRet, str1;
	//powerType = m_GPIBSetting.PowerType;
	char pCmd1[128] = {0};
	char pCmd2[128] = {0};

	if (1 == powerType)
	{
		if (nCH == 1)//1路电压电流
		{
			//设置电压/电流 
			sprintf(pCmd1, "VOLTage %.2f;*OPC?", dfVolt);
			//设置电流 
			sprintf(pCmd2, "CURR %.2f;*OPC?", dfCurr);
		}
		else if (nCH == 2)//2路电压电流设置
		{
			//设置电压/电流 
			sprintf(pCmd1, "VOLT2 %.2f;*OPC?", dfVolt);
			//设置电流 
			sprintf(pCmd2, "CURR2 %.2f;*OPC?", dfCurr);
		}
	}
	else if (3 == powerType || 2 == powerType)
	{
		if (nCH == 1)//1路电压电流
		{
			//设置电压/电流 
			sprintf(pCmd1, "VOLTage %.2f;*OPC?", dfVolt);
			//设置电流 
			sprintf(pCmd2, "CURR %.2f;*OPC?", dfCurr);
		}
		else if (nCH == 2)//2路电压电流设置
		{
			//设置电压/电流 
			sprintf(pCmd1, "SOUR2:VOLTage %.2f;*OPC?", dfVolt);
			//设置电流 
			sprintf(pCmd2, "SOUR2:CURR %.2f;*OPC?", dfCurr);
		}

	}
	m_GPIB_Query(pCmd1, strRet);
	CHECK(m_GPIB_Query(pCmd1, strRet));
	if (1 != atoi(strRet))
	{
		str1.Format("Set path %d current fail.", nCH);
		return false;
	}	
	m_GPIB_Query(pCmd2, strRet);
	CHECK(m_GPIB_Query(pCmd2, strRet));
 	if (1 != atoi(strRet))
 	{
 		str1.Format("Set path %d current fail.", nCH);
 		return false;
 	}
	return true;
}
bool CGPIB_VisaDlg::m_OpenPowerOutput(int powerType, int nCH,bool bOpen)
{
	CString strRet, str1;
	//powerType = m_GPIBSetting.PowerType;

	char pVolt[128] = {0};
	if (1 == powerType)
	{
		sprintf(pVolt, "OUTPut%d:STAT %d;*OPC?", nCH, bOpen);
	}
	else if (3 == powerType)
	{
		sprintf(pVolt, "OUTPut%d:STAT %d;*OPC?", nCH, bOpen);
	}

	CHECK(m_GPIB_Query(pVolt, strRet));
	if (1 != atoi(strRet))
	{
		if (bOpen)
		{
			str1.Format("Open power Pass.");
		}
		else
		{
			str1.Format("Open power fail.");
		}

		// 		m_static2.SetWindowText(str1);
		//m_savelog(str1);
		return false;
	}
	return true;
}
bool CGPIB_VisaDlg::m_ReadPowerVoltage(double &dfVolt)
{
	return true;
}
bool CGPIB_VisaDlg::m_CloseGPIB()
{
	return true;
}
bool CGPIB_VisaDlg::m_connectGPIB(int powerType, char* GPIBAddr)
{
	CString strRet, str1;
	//powerType = m_GPIBSetting.PowerType;

	//CString str1;
 	char ptemp[128] = {0};
	ViStatus status = 0;
	static BOOL bFlag = FALSE;

	status = viOpenDefaultRM(&g_defaultRM);
	if (status != VI_SUCCESS)
	{
		return FALSE;
	}

	sprintf(ptemp, "%s", GPIBAddr);
	// GPIB<controller>::<primary address>::<secondary address>::INSTR
	status = viOpen(g_defaultRM, ptemp, VI_NULL, VI_NULL, &g_instr);
	if (status != VI_SUCCESS)
	{
		return false;
	}

	//if (FALSE == bFlag)
	//{
	//	// 复位电源
	//	CHECK(m_GPIB_Query("*RST;*OPC?", str1));//这里获取的电流单位是A
	//	if (atoi(str1) != 1)
	//	{
	//		str1.Format("Fail: Reset");
	//		return false;
	//	}
	//	Sleep(500);

	//	// 
	//	CHECK(m_GPIB_Query("*CLS;*OPC?", str1));//这里获取的电流单位是A
	//	if (atoi(str1) != 1)
	//	{
	//		str1.Format("Fail: Reset");
	//		return false;
	//	}

	//	Sleep(200);

	//	bFlag = true;
	//}

	//if (FALSE == m_OpenPowerOutput(FALSE))
	//{
	//	return false;
	//}
	return true;
}
bool CGPIB_VisaDlg::m_GPIB_Write(char* cmd)
{
	return true;
}
bool CGPIB_VisaDlg::m_GPIB_Query(char* cmd, CString &strRet)
{
	CString str1;
	ViStatus status = 0;
	char ptemp[256] = {0};

	char ptemp2222[256] = {0};

	sprintf(ptemp, "%s\n", cmd);

	//status = viQueryf(g_instr, ptemp, "%s", strRet);
	status = viQueryf(g_instr, ptemp, "%s", ptemp2222);

	strRet = ptemp2222;

	if (status != VI_SUCCESS)
	{
		str1.Format("Fail: viQueryf(%s)", cmd);
		return FALSE;
	}
	return true;
}