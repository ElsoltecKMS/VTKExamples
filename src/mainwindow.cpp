#include <MainWindow.h> // MainWindow Ŭ���� ������ �ִ� ��� ������ ����

#include "ui_MainWindow.h" // Qt Designer���� ������ UI ���� ��� ������ ����

#include <vtkSphereSource.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mRenderWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()), // VTK�� OpenGL ���� �����츦 ����ϱ� ���� ����Ʈ ������ �ʱ�ȭ
    mRenderer(vtkSmartPointer<vtkRenderer>::New()), // VTK �������� ����ϱ� ���� ����Ʈ ������ �ʱ�ȭ
    mInteractor(vtkSmartPointer<QVTKInteractor>::New()), // VTK�� ��ȣ �ۿ��� ���� Qt ���ͷ��͸� ����ϱ� ���� ����Ʈ ������ �ʱ�ȭ
    mInteractorStyle(vtkSmartPointer<vtkInteractorStyle>::New()) // VTK�� ��ȣ �ۿ� ��Ÿ���� ����ϱ� ���� ����Ʈ ������ �ʱ�ȭ
{
    ui->setupUi(this); // UI�� �����ϴ� Qt Designer���� �ڵ����� ������ �ڵ�

    // ������ ���� �ʱ�ȭ
    mRenderWindow->AddRenderer(mRenderer); // �������� ���� �����쿡 �߰�
    mRenderWindow->SetInteractor(mInteractor); // ���� �����쿡 ���ͷ��� ����
    ui->openGLWidget->SetRenderWindow(mRenderWindow); // Qt�� OpenGL ������ ���� ������ ����
    mInteractor->SetInteractorStyle(mInteractorStyle); // ��ȣ �ۿ� ��Ÿ�� ����
    mInteractor->Initialize(); // ���ͷ��� �ʱ�ȭ

    // ���� ����
    mRenderer->SetBackground(1, 0, 0); // �������� ������ ���������� ����

    // UI ���� ����
    QObject::connect(ui->drawSphere_button, &QPushButton::clicked,
        this, &MainWindow::onDrawSphereClick); // drawSphere_button ��ư�� Ŭ�� �̺�Ʈ�� ���� ���� ����
}

MainWindow::~MainWindow() {
    delete ui; // Qt�� UI ��ü�� ����
}

void MainWindow::onDrawSphereClick() {
    // �� ����
    vtkSmartPointer<vtkSphereSource> sphereSource =
        vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->SetRadius(5); // ������ ����
    sphereSource->Update(); // �� ������Ʈ

    // ���� �������� ���� ����
    vtkSmartPointer<vtkPolyDataMapper> sphereMapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputData(sphereSource->GetOutput()); // ���Ϳ� �Է� ������ ����

    vtkSmartPointer<vtkActor> sphere = vtkSmartPointer<vtkActor>::New();
    sphere->SetMapper(sphereMapper); // ���Ϳ� ���� ����

    // �������� �� ���� �߰�
    mRenderer->AddViewProp(sphere);
    mRenderer->ResetCamera(); // ī�޶� �ʱ�ȭ
    mRenderWindow->Render(); // ���� ������ ������
}
