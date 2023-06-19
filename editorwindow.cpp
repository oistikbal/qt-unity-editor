#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>
#include <QtGui>

#include "editorwindow.h"


EditorWindow::EditorWindow(QWidget *parent) : QGoodWindow(parent)
{
    m_central_widget = new CentralWidget(this);
    m_central_widget->setWindowFlags(Qt::Widget);

    m_good_central_widget = new QGoodCentralWidget(this);

    setCentralWidget(m_central_widget);


//macOS uses global menu bar
#ifndef Q_OS_MAC
    QMenuBar *menu_bar = m_central_widget->menuBar();

    //Set font of menu bar
    QFont font = menu_bar->font();
    font.setPixelSize(12);
#ifdef Q_OS_WIN
    font.setFamily("Segoe UI");
#else
    font.setFamily(qApp->font().family());
#endif
    menu_bar->setFont(font);

    QTimer::singleShot(0, this, [=]{
        menu_bar->setFixedWidth(menu_bar->sizeHint().width());
        const int title_bar_height = m_good_central_widget->titleBarHeight();
        menu_bar->setStyleSheet(QString("QMenuBar {height: %0px;}").arg(title_bar_height));
    });

    m_good_central_widget->setLeftTitleBarWidget(menu_bar);
#endif


    m_good_central_widget->setCentralWidget(m_central_widget);
    setCentralWidget(m_good_central_widget);

    setWindowIcon(QIcon(":/icon/icons/UnityLogoLarge.png"));
    setWindowTitle("Example Project - SampleScene - PC, Mac, & Linux Standalone - Unity 2021.3 Personal <DX11>");
    setTabPosition(Qt::LeftDockWidgetArea, QTabWidget::TabPosition::North);
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);



    move(QGuiApplication::primaryScreen()->availableGeometry().center() - rect().center());
}
