
// CircleGradientDisplayDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "CircleGradientDisplay.h"
#include "CircleGradientDisplayDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCircleGradientDisplayDlg 대화 상자



CCircleGradientDisplayDlg::CCircleGradientDisplayDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CIRCLEGRADIENTDISPLAY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCircleGradientDisplayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCircleGradientDisplayDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


void CCircleGradientDisplayDlg::ShowGrid()
{
	m_image_dc.SelectObject(&m_grid_pen);
	m_image_dc.MoveTo(m_center_pos.x, 0);
	m_image_dc.LineTo(m_center_pos.x, m_rect.bottom);

	m_image_dc.MoveTo(0, m_center_pos.y);
	m_image_dc.LineTo(m_rect.right, m_center_pos.y);
}

// CCircleGradientDisplayDlg 메시지 처리기

BOOL CCircleGradientDisplayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	GetClientRect(m_rect);
	m_center_pos = m_rect.CenterPoint();

	m_image.Create(m_rect.Width(), m_rect.Height(), 32);
	m_image_dc.Attach(m_image.GetDC());

	m_grid_pen.CreatePen(PS_DOT, 1, RGB(168, 168, 168));
	m_green_pen.CreatePen(PS_SOLID, 2, RGB(100, 255, 100));
	SetBackgroundColor(RGB(0, 0, 0));

	m_image_dc.SetBkColor(RGB(0, 0, 0));

	ShowGrid();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCircleGradientDisplayDlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	if (IsIconic())
	{
		

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
		m_image.Draw(dc, 0, 0);
		// CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCircleGradientDisplayDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCircleGradientDisplayDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	m_image_dc.Detach();
	m_image.ReleaseDC();
	
	m_grid_pen.DeleteObject();
	m_green_pen.DeleteObject();
}
