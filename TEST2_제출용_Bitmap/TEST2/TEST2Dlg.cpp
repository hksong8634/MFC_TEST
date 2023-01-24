
// TEST2Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "TEST2.h"
#include "TEST2Dlg.h"
#include "afxdialogex.h"
#include <iostream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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

// CTEST2Dlg ��ȭ ����
CTEST2Dlg::CTEST2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST2_DIALOG, pParent)
	, m_nNum(10)
	, m_bInit(false)
{
	// ������(Ŭ�����̸��״�θ�������) -> ��ü ������ ȣ���
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

// CTEST2Dlg �޽��� ó����

BOOL CTEST2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CTEST2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CTEST2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTEST2Dlg::UpdateDisplay()////
{
	CClientDC dc(this); //this�� dialog
	m_image.Draw(dc, 0, 0);
}

void CTEST2Dlg::InitImage()
{
	if (m_bInit == false) {
		int nWidth = 640;
		int nHeight = 480;
		int nBpp = 8;

		m_image.Create(nWidth, -nHeight, nBpp); // �̹����� �����Ǳ� ������ - ����
		m_bInit = true; // ������

		if (nBpp == 8) {
			static RGBQUAD rgb[256];
			for (int i = 0; i < 256; i++) {
				rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
			}
			m_image.SetColorTable(0, 256, rgb);
		} ////default�� ������

		int nPitch = m_image.GetPitch();
		unsigned char* fm = (unsigned char*)m_image.GetBits();

		memset(fm, 0xff, nWidth * nHeight);

		UpdateDisplay();
	}
}

// 1. �߽��� ��������
void CTEST2Dlg::SetRandPoint()
{
	UpdateData(TRUE);

	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nRadius = m_nNum;

	// ������ǥ ����
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
	
	std::cout << "X ��ǥ : " << sCircle.nCx << "  Y ��ǥ : " << sCircle.nCy << "  ������ : " << nRadius << std::endl;
}


// 2. ���������� ���׸���
// 2-1. �߽������� ���������� ����� �� ã��
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
// 2-2. �����
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

// 3. �߽������� ���ڸ�ũ�׸���
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

// 4. ���׵θ� �׸���
void CTEST2Dlg::SetDrawEdge()
{
	UpdateData(TRUE);
	CClientDC dc(this);
	CBrush brush;
	int nRadius = m_nNum;

	CPen pen;
	pen.CreatePen(PS_DOT, 3, RGB(255, 255, 0));    // ����� ���� ����
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
		AfxMessageBox(_T("�������� �ʹ� Ů�ϴ�."));
	}
	if (nRadius <= MIN_RADIUS) {
		SetDlgItemInt(IDC_EDIT1, 1);
		AfxMessageBox(_T("�������� �ʹ� �۽��ϴ�."));
	}
}
