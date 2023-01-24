
// TEST2Dlg.h : 헤더 파일
//

#pragma once
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") //console창띄우기

#define GRAY 80
#define MIN_RADIUS 0
#define MAX_RADIUS 240
struct S_CIRCLE
{
	int nCx;
	int nCy;

};




// CTEST2Dlg 대화 상자
class CTEST2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CImage m_image;

	S_CIRCLE sCircle;



	CTEST2Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
