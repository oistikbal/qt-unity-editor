#pragma once

#include <QGoodWindow>
#include <QGoodCentralWidget>

#include "centralwidget.h"

class EditorWindow : public QGoodWindow
{
    Q_OBJECT
public:
    explicit EditorWindow(QWidget *parent = nullptr);
private:
    CentralWidget* m_central_widget;
    QGoodCentralWidget* m_good_central_widget;
};

