
// graphsView.cpp: реализация класса CgraphsView
//

#include "pch.h"
#include "framework.h"
// graphsView.cpp
#include "func.h"

// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "graphs.h"
#endif

#include "graphsDoc.h"
#include "graphsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;
// CgraphsView

IMPLEMENT_DYNCREATE(CgraphsView, CView)

BEGIN_MESSAGE_MAP(CgraphsView, CView)
	ON_WM_SIZE()
    ON_COMMAND(ID_GRAPH_PARABOLA, &CgraphsView::OnParabola)
    ON_COMMAND(ID_GRAPH_LINEAR, &CgraphsView::OnLinear)
    ON_COMMAND(ID_SQRT, &CgraphsView::OnSqrt)
END_MESSAGE_MAP()

// Создание или уничтожение CgraphsView

CgraphsView::CgraphsView() noexcept
{
	// TODO: добавьте код создания

}

CgraphsView::~CgraphsView()
{
}

BOOL CgraphsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CgraphsView

void CgraphsView::OnDraw(CDC* pDC)
{
    CgraphsDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // Получаем размер окна
    CRect rect;
    GetClientRect(&rect);

    // Центр координат
    int centerX = rect.Width() / 2;
    int centerY = rect.Height() / 2;

    // Фиксированная длина осей 
    int scaleFactor = 20; // 1 единица = 20 пикселей
    int axisLength = 48 * scaleFactor / 2;

    // Перо для рисования осей
    CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
    CPen* pOldPen = pDC->SelectObject(&pen);

    // Рисуем ось X
    pDC->MoveTo(centerX - axisLength, centerY);
    pDC->LineTo(centerX + axisLength, centerY);

    // Рисуем ось Y
    pDC->MoveTo(centerX, centerY + axisLength - 30);
    pDC->LineTo(centerX, centerY - axisLength);

    // Добавляем стрелки на концах осей
    pDC->MoveTo(centerX + axisLength, centerY);
    pDC->LineTo(centerX + axisLength - 10, centerY - 5);
    pDC->MoveTo(centerX + axisLength, centerY);
    pDC->LineTo(centerX + axisLength - 10, centerY + 5);
    pDC->MoveTo(centerX, centerY - axisLength);
    pDC->LineTo(centerX - 5, centerY - axisLength + 10);
    pDC->MoveTo(centerX, centerY - axisLength);
    pDC->LineTo(centerX + 5, centerY - axisLength + 10);

    // Подписи осей
    pDC->TextOut(centerX + axisLength + 7, centerY - 7, _T("X"));
    pDC->TextOut(centerX + 17, centerY - axisLength + 5, _T("Y"));

    // Отрисовка делений и подписей
    CString str;
    for (int i = -20; i <= 20; i++) {
        if (i == 0) continue;

        str.Format(_T("%d"), i);

        // Деления и подписи на оси X
        int xPos = centerX + i * scaleFactor;
        pDC->MoveTo(xPos, centerY - 5);
        pDC->LineTo(xPos, centerY + 5);
        pDC->TextOut(xPos - 5, centerY + 10, str);

        // Деления и подписи на оси Y
        int yPos = centerY - i * scaleFactor;
        pDC->MoveTo(centerX - 5, yPos);
        pDC->LineTo(centerX + 5, yPos);
        pDC->TextOut(centerX + 10, yPos - 5, str);
    }

    IFuncSolver* func = nullptr;
    switch (currentGraph) {
    case PARABOLA:
        func = new SquareFunc(1.0, 2.0, 1.0);
        break;
    case SQRT:
        func = new Sqrt(0, 2.0);
        break;
    case LINEAR:
        func = new LinearFunc(2, 3);
        break;
    }
    if (func) {
        Visualisator v;
        v.Show(*func);
        const std::vector<double>& x_vals = v.getCoorX();
        const std::vector<double>& y_vals = v.getCoorY();

        if (!x_vals.empty() && !y_vals.empty()) {
            double scaleFactor = 20.0;

            CPen graphPen(PS_SOLID, 2, RGB(255, 0, 0));
            CPen* pOldPen = pDC->SelectObject(&graphPen);

            pDC->MoveTo(
                centerX + static_cast<int>(x_vals[0] * scaleFactor),
                centerY - static_cast<int>(y_vals[0] * scaleFactor)
            );

            for (size_t i = 1; i < x_vals.size(); i++) {
                pDC->LineTo(
                    centerX + static_cast<int>(x_vals[i] * scaleFactor),
                    centerY - static_cast<int>(y_vals[i] * scaleFactor)
                );
            }

            pDC->SelectObject(pOldPen);
        }
        delete func;
    }
}


#ifdef _DEBUG
void CgraphsView::AssertValid() const
{
	CView::AssertValid();
}

void CgraphsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CgraphsDoc* CgraphsView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CgraphsDoc)));
	return (CgraphsDoc*)m_pDocument;
}

#endif //_DEBUG


// Обработчики сообщений CgraphsView


void CgraphsView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	Invalidate(TRUE); // Перерисовываем окно при изменении размера
	// TODO: добавьте свой код обработчика сообщений
}
void CgraphsView::OnParabola() {
    currentGraph = PARABOLA;
    Invalidate(); 
}

void CgraphsView::OnLinear() {
    currentGraph = LINEAR;
    Invalidate();
}

void CgraphsView::OnSqrt() {
    currentGraph = SQRT;
    Invalidate();
}

