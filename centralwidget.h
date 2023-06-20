#pragma once

#include <QMainWindow>
#include <QPushButton>
#include "hierarchy.h"

class StatusButton : public QPushButton
{
    Q_OBJECT

public:
    explicit StatusButton(QWidget *parent = nullptr, QString iconPath = "")
    {
        setIcon(QIcon(iconPath));
    };
private:
};


namespace Ui {
class CentralWidget;
}

class CentralWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit CentralWidget(QWidget *parent = nullptr);
    ~CentralWidget();

private:
    Ui::CentralWidget *ui;
    StatusButton* modeButton;
    StatusButton* cacheButton;
    StatusButton* lightButton;
    StatusButton* progressButton;
    Hierarchy* hierarchy;
};
