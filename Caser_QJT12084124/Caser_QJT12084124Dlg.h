
// Caser_QJT12084124Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CCaser_QJT12084124Dlg �Ի���
class CCaser_QJT12084124Dlg : public CDialogEx
{
// ����
public:
	CCaser_QJT12084124Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CASER_QJT12084124_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
