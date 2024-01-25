#include <QtWidgets/QApplication>  // Qt 애플리케이션 객체를 생성하기 위한 헤더 파일
#include <MainWindow.h>  // 메인 창 클래스를 포함한 헤더 파일

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);  // Qt 애플리케이션 객체 생성

    MainWindow mainWindow;  // 메인 창 객체 생성
    mainWindow.show();  // 메인 창을 화면에 표시

    return app.exec();  // 애플리케이션의 메인 이벤트 루프 실행
}
