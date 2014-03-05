
// Caser_QJT12084124Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Caser_QJT12084124.h"
#include "Caser_QJT12084124Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCaser_QJT12084124Dlg �Ի���




CCaser_QJT12084124Dlg::CCaser_QJT12084124Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCaser_QJT12084124Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCaser_QJT12084124Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITINPUT, m_EditInput);
	DDX_Control(pDX, IDC_EDITOUTPUT, m_EditOutput);
	DDX_Control(pDX, IDC_KEY, m_key);
}

BEGIN_MESSAGE_MAP(CCaser_QJT12084124Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &CCaser_QJT12084124Dlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_ENCRYPT, &CCaser_QJT12084124Dlg::OnBnClickedEncrypt)
	ON_BN_CLICKED(IDC_DECRYPT, &CCaser_QJT12084124Dlg::OnBnClickedDecrypt)
END_MESSAGE_MAP()


// CCaser_QJT12084124Dlg ��Ϣ�������

BOOL CCaser_QJT12084124Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_key.SetLimitText(4);
	m_key.SetWindowText(_T("3"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCaser_QJT12084124Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCaser_QJT12084124Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCaser_QJT12084124Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//�رհ�ť�¼�
void CCaser_QJT12084124Dlg::OnBnClickedExit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ExitProcess(0);
}


void CCaser_QJT12084124Dlg::OnBnClickedEncrypt()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//����CEdit���ָ��ָ�������EDIT CONTROL
	CEdit* pInputEdit;
	CEdit* pOutputEdit;
	CEdit* pKey;

	//����EDIT���
	pInputEdit = (CEdit*)GetDlgItem(IDC_EDITINPUT);
	pOutputEdit = (CEdit*)GetDlgItem(IDC_EDITOUTPUT);
	pKey = (CEdit*)GetDlgItem(IDC_KEY);

	//��ȡ���������
	CString strInput;
	pInputEdit->GetWindowText(strInput);
	CString strKey;
	pKey->GetWindowText(strKey);

	//��CString���͵���ԿתΪint
	int iKey = 0;
	iKey = _ttoi(strKey);

	//������EDIT
	pOutputEdit->SetWindowText(_T(""));
	
	//������Կ
	int iCharKey = iKey % 26;
	int iNumKey = iKey % 10;

	//CStringתΪchar��
	char *szInput;
	szInput = strInput.GetBuffer(strInput.GetLength());
	strInput.ReleaseBuffer();

	//��������м���
	for (int i = 0; i < strInput.GetLength(); i++)
	{
		//�������ֵ�ʱ��Ӧ����λ0-10
		if (szInput[i] >= '0' && szInput[i] <= '9')
		{
			szInput[i] += iNumKey;
			//���������0-9�ķ�Χ����ֱ�Ӽ���10
			if (szInput[i] > 57)
			{
				szInput[i] -= 10;
			}
		}
		//�����ַ���ʱ��
		else if (szInput[i] >= 'a' && szInput[i] <= 'z')
		{
			szInput[i] += iCharKey;
			//���������a-z�ķ�Χ
			if (szInput[i] > 'z')
			{
				szInput[i] -= 26;
			}
		}
		else if (szInput[i] >= 'A' && szInput[i] <= 'Z')
		{
			szInput[i] += iCharKey;
			if ( szInput[i] > 'Z')
			{
				szInput[i] -= 26;
			}
		}
		//�����������ֱ������������
		else continue;
	}

	//char -> CString
	CString strOutput = szInput;
	
	//���������edit
	pOutputEdit->SetWindowText(strOutput);

}


void CCaser_QJT12084124Dlg::OnBnClickedDecrypt()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//����CEdit���ָ��ָ�������EDIT CONTROL
	CEdit* pInputEdit;
	CEdit* pOutputEdit;
	CEdit* pKey;

	//����EDIT���
	pInputEdit = (CEdit*)GetDlgItem(IDC_EDITINPUT);
	pOutputEdit = (CEdit*)GetDlgItem(IDC_EDITOUTPUT);
	pKey = (CEdit*)GetDlgItem(IDC_KEY);

	//��ȡ���������
	CString strInput;
	pInputEdit->GetWindowText(strInput);
	CString strKey;
	pKey->GetWindowText(strKey);

	//��CString���͵���ԿתΪint
	int iKey = 0;
	iKey = _ttoi(strKey);

	//������EDIT
	pOutputEdit->SetWindowText(_T(""));

	//������Կ
	int iCharKey = iKey % 26;
	int iNumKey = iKey % 10;

	//CStringתΪchar��
	char *szInput;
	szInput = strInput.GetBuffer(strInput.GetLength());
	strInput.ReleaseBuffer();

	//��������м���
	for (int i = 0; i < strInput.GetLength(); i++)
	{
		//�������ֵ�ʱ��Ӧ����λ0-10
		if (szInput[i] >= '0' && szInput[i] <= '9')
		{
			szInput[i] -= iNumKey;
			//���������0-9�ķ�Χ����ֱ�Ӽ���10
			if (szInput[i] < '0')
			{
				szInput[i] += 10;
			}
		}
		//�����ַ���ʱ��
		else if (szInput[i] >= 'a' && szInput[i] <= 'z')
		{
			szInput[i] -= iCharKey;
			//���������a-z�ķ�Χ
			if (szInput[i] < 'a')
			{
				szInput[i] += 26;
			}
		}
		else if (szInput[i] >= 'A' && szInput[i] <= 'Z')
		{
			szInput[i] -= iCharKey;
			if ( szInput[i] < 'A')
			{
				szInput[i] += 26;
			}
		}
		//�����������ֱ������������
		else continue;
	}

	//char -> CString
	CString strOutput = szInput;

	//���������edit
	pOutputEdit->SetWindowText(strOutput);




}
