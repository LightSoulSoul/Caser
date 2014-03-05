
// Caser_QJT12084124Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Caser_QJT12084124.h"
#include "Caser_QJT12084124Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CCaser_QJT12084124Dlg 对话框




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


// CCaser_QJT12084124Dlg 消息处理程序

BOOL CCaser_QJT12084124Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_key.SetLimitText(4);
	m_key.SetWindowText(_T("3"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCaser_QJT12084124Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCaser_QJT12084124Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//关闭按钮事件
void CCaser_QJT12084124Dlg::OnBnClickedExit()
{
	// TODO: 在此添加控件通知处理程序代码
	ExitProcess(0);
}


void CCaser_QJT12084124Dlg::OnBnClickedEncrypt()
{
	// TODO: 在此添加控件通知处理程序代码
	//声明CEdit类的指针指向输入的EDIT CONTROL
	CEdit* pInputEdit;
	CEdit* pOutputEdit;
	CEdit* pKey;

	//返回EDIT句柄
	pInputEdit = (CEdit*)GetDlgItem(IDC_EDITINPUT);
	pOutputEdit = (CEdit*)GetDlgItem(IDC_EDITOUTPUT);
	pKey = (CEdit*)GetDlgItem(IDC_KEY);

	//获取输入的内容
	CString strInput;
	pInputEdit->GetWindowText(strInput);
	CString strKey;
	pKey->GetWindowText(strKey);

	//将CString类型的密钥转为int
	int iKey = 0;
	iKey = _ttoi(strKey);

	//清空输出EDIT
	pOutputEdit->SetWindowText(_T(""));
	
	//处理密钥
	int iCharKey = iKey % 26;
	int iNumKey = iKey % 10;

	//CString转为char型
	char *szInput;
	szInput = strInput.GetBuffer(strInput.GetLength());
	strInput.ReleaseBuffer();

	//对输入进行加密
	for (int i = 0; i < strInput.GetLength(); i++)
	{
		//遇到数字的时候，应该移位0-10
		if (szInput[i] >= '0' && szInput[i] <= '9')
		{
			szInput[i] += iNumKey;
			//如果超过了0-9的范围，就直接减掉10
			if (szInput[i] > 57)
			{
				szInput[i] -= 10;
			}
		}
		//遇到字符的时候
		else if (szInput[i] >= 'a' && szInput[i] <= 'z')
		{
			szInput[i] += iCharKey;
			//如果超过了a-z的范围
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
		//其他特殊符号直接跳过不加密
		else continue;
	}

	//char -> CString
	CString strOutput = szInput;
	
	//设置输出的edit
	pOutputEdit->SetWindowText(strOutput);

}


void CCaser_QJT12084124Dlg::OnBnClickedDecrypt()
{
	// TODO: 在此添加控件通知处理程序代码
	//声明CEdit类的指针指向输入的EDIT CONTROL
	CEdit* pInputEdit;
	CEdit* pOutputEdit;
	CEdit* pKey;

	//返回EDIT句柄
	pInputEdit = (CEdit*)GetDlgItem(IDC_EDITINPUT);
	pOutputEdit = (CEdit*)GetDlgItem(IDC_EDITOUTPUT);
	pKey = (CEdit*)GetDlgItem(IDC_KEY);

	//获取输入的内容
	CString strInput;
	pInputEdit->GetWindowText(strInput);
	CString strKey;
	pKey->GetWindowText(strKey);

	//将CString类型的密钥转为int
	int iKey = 0;
	iKey = _ttoi(strKey);

	//清空输出EDIT
	pOutputEdit->SetWindowText(_T(""));

	//处理密钥
	int iCharKey = iKey % 26;
	int iNumKey = iKey % 10;

	//CString转为char型
	char *szInput;
	szInput = strInput.GetBuffer(strInput.GetLength());
	strInput.ReleaseBuffer();

	//对输入进行加密
	for (int i = 0; i < strInput.GetLength(); i++)
	{
		//遇到数字的时候，应该移位0-10
		if (szInput[i] >= '0' && szInput[i] <= '9')
		{
			szInput[i] -= iNumKey;
			//如果超过了0-9的范围，就直接减掉10
			if (szInput[i] < '0')
			{
				szInput[i] += 10;
			}
		}
		//遇到字符的时候
		else if (szInput[i] >= 'a' && szInput[i] <= 'z')
		{
			szInput[i] -= iCharKey;
			//如果超过了a-z的范围
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
		//其他特殊符号直接跳过不加密
		else continue;
	}

	//char -> CString
	CString strOutput = szInput;

	//设置输出的edit
	pOutputEdit->SetWindowText(strOutput);




}
