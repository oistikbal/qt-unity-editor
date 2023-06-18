#include <QApplication>
#include <QGoodWindow>
#include <QGoodCentralWidget>
#include "editorwindow.h"

int main(int argc, char *argv[])
{
    QGoodWindow::setup();

    QApplication app(argc, argv);
    EditorWindow editorWindow;
    editorWindow.show();
    QGoodWindow::setAppDarkTheme();
    return app.exec();
}
