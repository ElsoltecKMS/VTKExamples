#include <QtWidgets/QApplication>  // Qt ���ø����̼� ��ü�� �����ϱ� ���� ��� ����
#include <MainWindow.h>  // ���� â Ŭ������ ������ ��� ����

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);  // Qt ���ø����̼� ��ü ����

    MainWindow mainWindow;  // ���� â ��ü ����
    mainWindow.show();  // ���� â�� ȭ�鿡 ǥ��

    return app.exec();  // ���ø����̼��� ���� �̺�Ʈ ���� ����
}
