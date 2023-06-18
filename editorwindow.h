#pragma once

#include <QGoodWindow>
#include <QGoodCentralWidget>

class EditorWindow : public QGoodWindow
{
    Q_OBJECT
public:
    EditorWindow();
private:
    QGoodCentralWidget* m_gcw;
};

