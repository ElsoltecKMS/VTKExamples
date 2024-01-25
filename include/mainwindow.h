#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vtkGenericOpenGLRenderWindow.h>  // VTK의 OpenGL 렌더 윈도우 헤더 파일
#include <vtkRenderer.h>  // VTK의 렌더러 헤더 파일
#include <QVTKInteractor.h>  // VTK와 Qt 간의 상호 작용을 위한 인터랙터 헤더 파일
#include <vtkInteractorStyle.h>  // VTK의 상호 작용 스타일 헤더 파일

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;  // Qt Designer에서 생성된 UI 클래스의 포인터

    vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow;  // VTK의 OpenGL 렌더 윈도우를 사용하기 위한 스마트 포인터
    vtkSmartPointer<vtkRenderer> mRenderer;  // VTK의 렌더러를 사용하기 위한 스마트 포인터
    vtkSmartPointer<QVTKInteractor> mInteractor;  // VTK의 상호 작용을 위한 Qt 인터랙터를 사용하기 위한 스마트 포인터
    vtkSmartPointer<vtkInteractorStyle> mInteractorStyle;  // VTK의 상호 작용 스타일을 사용하기 위한 스마트 포인터

public:
    explicit MainWindow(QWidget* parent = nullptr);  // 부모 위젯을 받는 생성자
    ~MainWindow();  // 소멸자

public slots:
    void onDrawSphereClick();  // 구 그리기 버튼 클릭 시 호출되는 슬롯

};

#endif // MAINWINDOW_H
