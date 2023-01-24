
// TEST2Dlg.h : ��� ����
//

#pragma once
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") //consoleâ����

#define GRAY 80
#define MIN_RADIUS 0
#define MAX_RADIUS 240
struct S_CIRCLE
{
	int nCx;
	int nCy;

};




// CTEST2Dlg ��ȭ ����
class CTEST2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CImage m_image;

	S_CIRCLE sCircle;



	CTEST2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	int m_nNum;
	bool m_bInit;
	bool IsinCircle(int x, int y, int nCenterX, int nCenterY);

	void UpdateDisplay(); ////
	void InitImage(); 
	void SetRandPoint(); ////

	void SetDrawCircle(); ////

	void SetDrawCrosshair(int nCenterX, int nCenterY); ////

	void SetDrawEdge(); ////


	afx_msg void OnBnClickedCrtCircle();
	afx_msg void OnBnClickedBtnFirst();
	
	afx_msg void OnBnClickedBtnCross();
	afx_msg void OnBnClickedBtnEdge();
	afx_msg void OnEnChangeEdit1();
};
