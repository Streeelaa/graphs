//#include "pch.h"
//#include "graphsView.h"
//
//void CgraphsView::DrawAxes(CDC* pDC)
//{
//    // Получаем размер окна
//    CRect rect;
//    GetClientRect(&rect);
//
//    // Центр координат
//    int centerX = rect.Width() / 2;
//    int centerY = rect.Height() / 2;
//
//    // Фиксированная длина осей
//    int axisLength = min(rect.Width(), rect.Height()) / 2 - 50;
//
//    // Перо для рисования осей
//    CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
//    CPen* pOldPen = pDC->SelectObject(&pen);
//
//    // Рисуем ось X
//    pDC->MoveTo(centerX - axisLength, centerY);
//    pDC->LineTo(centerX + axisLength, centerY);
//
//    // Рисуем ось Y
//    pDC->MoveTo(centerX, centerY + axisLength);
//    pDC->LineTo(centerX, centerY - axisLength);
//
//    // Добавляем стрелки на концах осей
//    // Ось X
//    pDC->MoveTo(centerX + axisLength, centerY);
//    pDC->LineTo(centerX + axisLength - 10, centerY - 5);
//    pDC->MoveTo(centerX + axisLength, centerY);
//    pDC->LineTo(centerX + axisLength - 10, centerY + 5);
//
//    // Ось Y
//    pDC->MoveTo(centerX, centerY - axisLength);
//    pDC->LineTo(centerX - 5, centerY - axisLength + 10);
//    pDC->MoveTo(centerX, centerY - axisLength);
//    pDC->LineTo(centerX + 5, centerY - axisLength + 10);
//
//    // Подписи осей
//    pDC->TextOut(centerX + axisLength + 7, centerY - 7, _T("X"));
//    pDC->TextOut(centerX + 10, centerY - axisLength - 17, _T("Y"));
//
//    // Отрисовка делений и подписей
//    CString str;
//    for (int i = -10; i <= 10; i++) {
//        if (i == 0) continue;
//
//        str.Format(_T("%d"), i * 2);
//
//        // Деления и подписи на оси X
//        int xPos = centerX + i * 20;
//        pDC->MoveTo(xPos, centerY - 5);
//        pDC->LineTo(xPos, centerY + 5);
//        pDC->TextOut(xPos - 5, centerY + 10, str);
//
//        // Деления и подписи на оси Y
//        int yPos = centerY - i * 20;
//        pDC->MoveTo(centerX - 5, yPos);
//        pDC->LineTo(centerX + 5, yPos);
//        pDC->TextOut(centerX + 10, yPos - 5, str);
//    }
//
//    // Вернуть старое перо
//    pDC->SelectObject(pOldPen);
//}
