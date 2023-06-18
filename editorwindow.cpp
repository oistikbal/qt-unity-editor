#include "editorwindow.h"

EditorWindow::EditorWindow()
{
    m_gcw = new QGoodCentralWidget(this);
    setCentralWidget(m_gcw);
    setWindowIcon(QIcon(":/icon/icons/UnityLogoLarge.png"));
    setWindowTitle("Example Project -  SampleScene - PC, Mac, & Linux Standalone - Unity 2021.3 Personal <DX11>");
    setTabPosition(Qt::LeftDockWidgetArea, QTabWidget::TabPosition::North);
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
}
