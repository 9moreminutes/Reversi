#include "guiboard.h"
#include "ui_guiboard.h"

GUIBoard::GUIBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUIBoard)
{
    ui->setupUi(this);
}

GUIBoard::~GUIBoard()
{
    delete ui;
}
