#include "centralwidget.h"
#include "ui_centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CentralWidget)
{
    //toolbar
    ui->setupUi(this);
    addToolBarBreak(Qt::TopToolBarArea);
    addToolBar(Qt::TopToolBarArea, ui->toolBar);

    //statusbar
    modeButton = new StatusButton(ui->statusbar, ":/icon/icons/d_DebuggerDisabled@2x.png");
    cacheButton = new StatusButton(ui->statusbar, ":/icon/icons/d_CacheServerDisabled@2x.png");
    lightButton = new StatusButton(ui->statusbar, ":/icon/icons/d_AutoLightbakingOn@2x.png");
    progressButton = new StatusButton(ui->statusbar, ":/icon/icons/d_Progress@2x.png");

    ui->statusbar->addPermanentWidget(modeButton);
    ui->statusbar->addPermanentWidget(cacheButton);
    ui->statusbar->addPermanentWidget(lightButton);
    ui->statusbar->addPermanentWidget(progressButton);

    //hierarchy
    hierarchy = new Hierarchy(this);
    addDockWidget(Qt::LeftDockWidgetArea, hierarchy->Dock());
}

CentralWidget::~CentralWidget()
{
    delete ui;
}
