// sine_graph.h
#pragma once
#include "afxdialogex.h"

// Диалоговое окно sine_graph
class sine_graph : public CDialogEx
{
    DECLARE_DYNAMIC(sine_graph)

public:
    sine_graph(CWnd* pParent = nullptr);   // стандартный конструктор
    virtual ~sine_graph();

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedButtonChangeAxis();  // Обработчик кнопки
    afx_msg void OnDraw(CDC* pDC);  // Метод рисования (объявление)

private:
    bool m_bAxesSwitched;  // Флаг, который будет менять оси
};

