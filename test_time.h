class CSpendTime
{
public:
	CSpendTime()
	{
		m_dSpendTime = 0.0;

		QueryPerformanceFrequency(&m_lgiFrequency);
	}

	virtual ~CSpendTime()
	{
	}

	// ��ʼ
	void Start()
	{
		QueryPerformanceCounter(&m_lgiCounterStart);
	}

	// ����
	double End() // ����ֵ����ʱ����λ�����룩
	{
		QueryPerformanceCounter(&m_lgiCounterEnd);

		m_dSpendTime = (double)(m_lgiCounterEnd.QuadPart - m_lgiCounterStart.QuadPart) * 1000.0 / m_lgiFrequency.QuadPart;

		return m_dSpendTime;
	}

	//CString EndS()
	//{
	//	double dTime = End();
	//	CString strTime;
	//	strTime.Format(_T("  %.3f ms "), dTime);
	//	return strTime;
	//}


	// ��ú�ʱ����λ�����룩
	int GetMillisecondInt()
	{
		return (int)(m_dSpendTime);
	}

	// ��ú�ʱ����λ�����룩
	double GetMillisecondDouble()
	{
		return (m_dSpendTime);
	}

protected:

	LARGE_INTEGER m_lgiCounterStart;
	LARGE_INTEGER m_lgiCounterEnd;
	LARGE_INTEGER m_lgiFrequency;
	double m_dSpendTime;
};