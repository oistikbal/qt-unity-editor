#pragma once

#include <QMainWindow>

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
};

