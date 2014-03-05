
// Caser_QJT12084124Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CCaser_QJT12084124Dlg 对话框
class CCaser_QJT12084124Dlg : public CDialogEx
{
// 构造
public:
	CCaser_QJT12084124Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CASER_QJT12084124_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
	CEdit m_EditInput;
	CEdit m_EditOutput;
	afx_msg void OnBnClickedEncrypt();
	CEdit m_key;
	afx_msg void OnBnClickedDecrypt();
};
