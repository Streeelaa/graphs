//#include "pch.h"
//#include "graphsView.h"
//
//void CgraphsView::DrawAxes(CDC* pDC)
//{
//    // �������� ������ ����
//    CRect rect;
//    GetClientRect(&rect);
//
//    // ����� ���������
//    int centerX = rect.Width() / 2;
//    int centerY = rect.Height() / 2;
//
//    // ������������� ����� ����
//    int axisLength = min(rect.Width(), rect.Height()) / 2 - 50;
//
//    // ���� ��� ��������� ����
//    CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
//    CPen* pOldPen = pDC->SelectObject(&pen);
//
//    // ������ ��� X
//    pDC->MoveTo(centerX - axisLength, centerY);
//    pDC->LineTo(centerX + axisLength, centerY);
//
//    // ������ ��� Y
//    pDC->MoveTo(centerX, centerY + axisLength);
//    pDC->LineTo(centerX, centerY - axisLength);
//
//    // ��������� ������� �� ������ ����
//    // ��� X
//    pDC->MoveTo(centerX + axisLength, centerY);
//    pDC->LineTo(centerX + axisLength - 10, centerY - 5);
//    pDC->MoveTo(centerX + axisLength, centerY);
//    pDC->LineTo(centerX + axisLength - 10, centerY + 5);
//
//    // ��� Y
//    pDC->MoveTo(centerX, centerY - axisLength);
//    pDC->LineTo(centerX - 5, centerY - axisLength + 10);
//    pDC->MoveTo(centerX, centerY - axisLength);
//    pDC->LineTo(centerX + 5, centerY - axisLength + 10);
//
//    // ������� ����
//    pDC->TextOut(centerX + axisLength + 7, centerY - 7, _T("X"));
//    pDC->TextOut(centerX + 10, centerY - axisLength - 17, _T("Y"));
//
//    // ��������� ������� � ��������
//    CString str;
//    for (int i = -10; i <= 10; i++) {
//        if (i == 0) continue;
//
//        str.Format(_T("%d"), i * 2);
//
//        // ������� � ������� �� ��� X
//        int xPos = centerX + i * 20;
//        pDC->MoveTo(xPos, centerY - 5);
//        pDC->LineTo(xPos, centerY + 5);
//        pDC->TextOut(xPos - 5, centerY + 10, str);
//
//        // ������� � ������� �� ��� Y
//        int yPos = centerY - i * 20;
//        pDC->MoveTo(centerX - 5, yPos);
//        pDC->LineTo(centerX + 5, yPos);
//        pDC->TextOut(centerX + 10, yPos - 5, str);
//    }
//
//    // ������� ������ ����
//    pDC->SelectObject(pOldPen);
//}
