
// TEST2Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "TEST2.h"
#include "TEST2Dlg.h"
#include "afxdialogex.h"
#include <iostream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CTEST2Dlg 대화 상자
CTEST2Dlg::CTEST2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST2_DIALOG, pParent)
	, m_nNum(10)
	, m_bInit(false)
{
	// 생성자(클래스이름그대로를가져감) -> 객체 생성시 호출됨
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTEST2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nNum);
}

BEGIN_MESSAGE_MAP(CTEST2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CRT_CIRCLE, &CTEST2Dlg::OnBnClickedCrtCircle)
	ON_BN_CLICKED(IDC_BTN_FIRST, &CTEST2Dlg::OnBnClickedBtnFirst)
	ON_BN_CLICKED(IDC_BTN_CROSS, &CTEST2Dlg::OnBnClickedBtnCross)
	ON_BN_CLICKED(IDC_BTN_EDGE, &CTEST2Dlg::OnBnClickedBtnEdge)
	ON_EN_CHANGE(IDC_EDIT1, &CTEST2Dlg::OnEnChangeEdit1)
END_MESSAGE_MAP()

// CTEST2Dlg 메시지 처리기

BOOL CTEST2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTEST2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTEST2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTEST2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTEST2Dlg::UpdateDisplay()////
{
	CClientDC dc(this); //this는 dialog
	m_image.Draw(dc, 0, 0);
}

void CTEST2Dlg::InitImage()
{
	if (m_bInit == false) {
		int nWidth = 640;
		int nHeight = 480;
		int nBpp = 8;

		m_image.Create(nWidth, -nHeight, nBpp); // 이미지가 반전되기 때문에 - 붙임
		m_bInit = true; // 생성됨

		if (nBpp == 8) {
			static RGBQUAD rgb[256];
			for (int i = 0; i < 256; i++) {
				rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
			}
			m_image.SetColorTable(0, 256, rgb);
		} ////default로 들어가야함

		int nPitch = m_image.GetPitch();
		unsigned char* fm = (unsigned char*)m_image.GetBits();

		memset(fm, 0xff, nWidth * nHeight);

		UpdateDisplay();
	}
}

// 1. 중심점 랜덤생성
void CTEST2Dlg::SetRandPoint()
{
	UpdateData(TRUE);

	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nRadius = m_nNum;

	// 랜덤좌표 생성
	sCircle.nCx = rand() % nWidth;
	sCircle.nCy = rand() % nHeight;

	if (sCircle.nCx < nRadius) {
		sCircle.nCx = nRadius;
	}
	if (sCircle.nCx > nWidth - nRadius) {
		sCircle.nCx = nWidth - nRadius;
	}
	if (sCircle.nCy < nRadius) {
		sCircle.nCy = nRadius;
	}
	if (sCircle.nCy > nHeight - nRadius) {
		sCircle.nCy = nHeight - nRadius;
	}
	
	std::cout << "X 좌표 : " << sCircle.nCx << "  Y 좌표 : " << sCircle.nCy << "  반지름 : " << nRadius << std::endl;
}


// 2. 반지름으로 원그리기
// 2-1. 중심점에서 반지름보다 가까운 점 찾기
bool CTEST2Dlg::IsinCircle(int x, int y, int nCenterX, int nCenterY)
{
	bool bRet = false;
	int nRadius = m_nNum;
	double dX = x - nCenterX;
	double dY = y - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius * nRadius) {
		bRet = true;
	}
	return bRet;
}
// 2-2. 점찍기
void CTEST2Dlg::SetDrawCircle()
{
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	int nRadius = m_nNum;

	memset(fm, 0xff, nWidth * nHeight);

	for (int j = sCircle.nCy - nRadius; j < sCircle.nCy + nRadius; j++) {
		for (int i = sCircle.nCx - nRadius; i < sCircle.nCx + nRadius; i++) {
			if (IsinCircle(i, j, sCircle.nCx, sCircle.nCy)) {
				fm[j * nPitch + i] = GRAY;
			}
		}
	}
	UpdateDisplay();
}

// 3. 중심점에서 십자마크그리기
void CTEST2Dlg::SetDrawCrosshair(int nCenterX, int nCenterY)
{
	CClientDC dc(this);
	CPen pen;
	int nLen = 10;
	pen.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	CPen *oldPen = dc.SelectObject(&pen);

	dc.MoveTo(nCenterX - nLen, nCenterY);
	dc.LineTo(nCenterX + nLen, nCenterY);

	dc.MoveTo(nCenterX, nCenterY - nLen);
	dc.LineTo(nCenterX, nCenterY + nLen);

	//dc.SelectObject(oldPen);
	
}

// 4. 원테두리 그리기
void CTEST2Dlg::SetDrawEdge()
{
	UpdateData(TRUE);
	CClientDC dc(this);
	CBrush brush;
	int nRadius = m_nNum;

	CPen pen;
	pen.CreatePen(PS_DOT, 3, RGB(255, 255, 0));    // 노란색 펜을 생성
	CPen* oldPen = dc.SelectObject(&pen);

	brush.CreateStockObject(NULL_BRUSH);

	CBrush* pOldBrush = dc.SelectObject(&brush);

	dc.Ellipse(sCircle.nCx - nRadius, sCircle.nCy - nRadius, sCircle.nCx + nRadius, sCircle.nCy + nRadius);
	dc.SelectObject(pOldBrush);

	DeleteObject(brush);
}

void CTEST2Dlg::OnBnClickedBtnFirst()
{
	InitImage();

	if (m_bInit) {
		GetDlgItem(IDC_CRT_CIRCLE)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_CROSS)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_EDGE)->EnableWindow(TRUE);
	}
}

void CTEST2Dlg::OnBnClickedCrtCircle()
{
	SetRandPoint();
	SetDrawCircle();
}

void CTEST2Dlg::OnBnClickedBtnCross()
{
	SetDrawCrosshair(sCircle.nCx, sCircle.nCy);
}

void CTEST2Dlg::OnBnClickedBtnEdge()
{
	SetDrawEdge();
}


void CTEST2Dlg::OnEnChangeEdit1()
{
	UpdateData(TRUE);
	int nRadius = m_nNum;

	if (nRadius > MAX_RADIUS) {
		SetDlgItemInt(IDC_EDIT1, 1);
		AfxMessageBox(_T("반지름이 너무 큽니다."));
	}
	if (nRadius <= MIN_RADIUS) {
		SetDlgItemInt(IDC_EDIT1, 1);
		AfxMessageBox(_T("반지름이 너무 작습니다."));
	}
}
