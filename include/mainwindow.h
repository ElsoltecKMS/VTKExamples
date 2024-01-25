#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vtkGenericOpenGLRenderWindow.h>  // VTK�� OpenGL ���� ������ ��� ����
#include <vtkRenderer.h>  // VTK�� ������ ��� ����
#include <QVTKInteractor.h>  // VTK�� Qt ���� ��ȣ �ۿ��� ���� ���ͷ��� ��� ����
#include <vtkInteractorStyle.h>  // VTK�� ��ȣ �ۿ� ��Ÿ�� ��� ����

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;  // Qt Designer���� ������ UI Ŭ������ ������

    vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow;  // VTK�� OpenGL ���� �����츦 ����ϱ� ���� ����Ʈ ������
    vtkSmartPointer<vtkRenderer> mRenderer;  // VTK�� �������� ����ϱ� ���� ����Ʈ ������
    vtkSmartPointer<QVTKInteractor> mInteractor;  // VTK�� ��ȣ �ۿ��� ���� Qt ���ͷ��͸� ����ϱ� ���� ����Ʈ ������
    vtkSmartPointer<vtkInteractorStyle> mInteractorStyle;  // VTK�� ��ȣ �ۿ� ��Ÿ���� ����ϱ� ���� ����Ʈ ������

public:
    explicit MainWindow(QWidget* parent = nullptr);  // �θ� ������ �޴� ������
    ~MainWindow();  // �Ҹ���

public slots:
    void onDrawSphereClick();  // �� �׸��� ��ư Ŭ�� �� ȣ��Ǵ� ����

};

#endif // MAINWINDOW_H
