
// CircleGradientDisplayDlg.h: 헤더 파일
//

#pragma once


// CCircleGradientDisplayDlg 대화 상자
class CCircleGradientDisplayDlg : public CDialogEx
{
private:
	CImage m_image;
	CDC m_image_dc;

	CRect m_rect;
	CPoint m_center_pos;

	CPen m_grid_pen, m_green_pen;
	

// 생성입니다.
public:
	CCircleGradientDisplayDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CIRCLEGRADIENTDISPLAY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	void ShowGrid();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
