#include <MainWindow.h> // MainWindow 클래스 선언이 있는 헤더 파일을 포함

#include "ui_MainWindow.h" // Qt Designer에서 생성된 UI 관련 헤더 파일을 포함

#include <vtkSphereSource.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mRenderWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()), // VTK의 OpenGL 렌더 윈도우를 사용하기 위한 스마트 포인터 초기화
    mRenderer(vtkSmartPointer<vtkRenderer>::New()), // VTK 렌더러를 사용하기 위한 스마트 포인터 초기화
    mInteractor(vtkSmartPointer<QVTKInteractor>::New()), // VTK의 상호 작용을 위한 Qt 인터랙터를 사용하기 위한 스마트 포인터 초기화
    mInteractorStyle(vtkSmartPointer<vtkInteractorStyle>::New()) // VTK의 상호 작용 스타일을 사용하기 위한 스마트 포인터 초기화
{
    ui->setupUi(this); // UI를 설정하는 Qt Designer에서 자동으로 생성된 코드

    // 렌더링 설정 초기화
    mRenderWindow->AddRenderer(mRenderer); // 렌더러를 렌더 윈도우에 추가
    mRenderWindow->SetInteractor(mInteractor); // 렌더 윈도우에 인터랙터 설정
    ui->openGLWidget->SetRenderWindow(mRenderWindow); // Qt의 OpenGL 위젯에 렌더 윈도우 설정
    mInteractor->SetInteractorStyle(mInteractorStyle); // 상호 작용 스타일 설정
    mInteractor->Initialize(); // 인터랙터 초기화

    // 배경색 설정
    mRenderer->SetBackground(1, 0, 0); // 렌더러의 배경색을 빨간색으로 설정

    // UI 연결 설정
    QObject::connect(ui->drawSphere_button, &QPushButton::clicked,
        this, &MainWindow::onDrawSphereClick); // drawSphere_button 버튼의 클릭 이벤트에 대한 연결 설정
}

MainWindow::~MainWindow() {
    delete ui; // Qt의 UI 객체를 삭제
}

void MainWindow::onDrawSphereClick() {
    // 구 생성
    vtkSmartPointer<vtkSphereSource> sphereSource =
        vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->SetRadius(5); // 반지름 설정
    sphereSource->Update(); // 구 업데이트

    // 구를 렌더링할 액터 생성
    vtkSmartPointer<vtkPolyDataMapper> sphereMapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputData(sphereSource->GetOutput()); // 액터에 입력 데이터 설정

    vtkSmartPointer<vtkActor> sphere = vtkSmartPointer<vtkActor>::New();
    sphere->SetMapper(sphereMapper); // 액터에 매퍼 설정

    // 렌더러에 구 액터 추가
    mRenderer->AddViewProp(sphere);
    mRenderer->ResetCamera(); // 카메라 초기화
    mRenderWindow->Render(); // 렌더 윈도우 렌더링
}
