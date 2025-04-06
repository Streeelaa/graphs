
// graphsView.h: интерфейс класса CgraphsView
//

#pragma once
#include <vector>
#include "func.h"
enum GraphType { PARABOLA, LINEAR, SQRT};
class CgraphsView : public CView {
private:
	GraphType currentGraph = PARABOLA;
protected: // создать только из сериализации
	CgraphsView() noexcept;
	DECLARE_DYNCREATE(CgraphsView)

// Атрибуты
public:
	CgraphsDoc* GetDocument() const;

// Операции
public:
	afx_msg void OnParabola();
	afx_msg void OnLinear();
	afx_msg void OnSqrt();
// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
// Реализация
public:
	virtual ~CgraphsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
#ifndef _DEBUG  // версия отладки в graphsView.cpp
inline CgraphsDoc* CgraphsView::GetDocument() const
   { return reinterpret_cast<CgraphsDoc*>(m_pDocument); }
#endif


