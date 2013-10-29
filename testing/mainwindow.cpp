#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    c(Client())
{
    ui->setupUi(this);
    c.serverConnect("10.200.43.219");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateButtons()
{
    vector<Tile> grid = c.getGrid();

    if (grid[0] == EMPTY)
        ui->A1->setStyleSheet(QString(""));
    else if (grid[0] == WHITE)
        ui->A1->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->A1->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[8] == EMPTY)
        ui->A2->setStyleSheet(QString(""));
    else if (grid[8] == WHITE)
        ui->A2->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->A2->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[16] == EMPTY)
        ui->A3->setStyleSheet(QString(""));
    else if (grid[16] == WHITE)
        ui->A3->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->A3->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[24] == EMPTY)
        ui->A4->setStyleSheet(QString(""));
    else if (grid[24] == WHITE)
        ui->A4->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->A4->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[32] == EMPTY)
        ui->A5->setStyleSheet(QString(""));
    else if (grid[32] == WHITE)
        ui->A5->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->A5->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[40] == EMPTY)
        ui->A6->setStyleSheet(QString(""));
    else if (grid[40] == WHITE)
        ui->A6->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->A6->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[48] == EMPTY)
        ui->A7->setStyleSheet(QString(""));
    else if (grid[48] == WHITE)
        ui->A7->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->A7->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[56] == EMPTY)
        ui->A8->setStyleSheet(QString(""));
    else if (grid[56] == WHITE)
        ui->A8->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->A8->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[1] == EMPTY)
        ui->B1->setStyleSheet(QString(""));
    else if (grid[1] == WHITE)
        ui->B1->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->B1->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[9] == EMPTY)
        ui->B2->setStyleSheet(QString(""));
    else if (grid[9] == WHITE)
        ui->B2->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->B2->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[17] == EMPTY)
        ui->B3->setStyleSheet(QString(""));
    else if (grid[17] == WHITE)
        ui->B3->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->B3->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[25] == EMPTY)
        ui->B4->setStyleSheet(QString(""));
    else if (grid[25] == WHITE)
        ui->B4->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->B4->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[33] == EMPTY)
        ui->B5->setStyleSheet(QString(""));
    else if (grid[33] == WHITE)
        ui->B5->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->B5->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[41] == EMPTY)
        ui->B6->setStyleSheet(QString(""));
    else if (grid[41] == WHITE)
        ui->B6->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->B6->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[49] == EMPTY)
        ui->B7->setStyleSheet(QString(""));
    else if (grid[49] == WHITE)
        ui->B7->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->B7->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[57] == EMPTY)
        ui->B8->setStyleSheet(QString(""));
    else if (grid[57] == WHITE)
        ui->B8->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->B8->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[2] == EMPTY)
        ui->C1->setStyleSheet(QString(""));
    else if (grid[2] == WHITE)
        ui->C1->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->C1->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[10] == EMPTY)
        ui->C2->setStyleSheet(QString(""));
    else if (grid[10] == WHITE)
        ui->C2->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->C2->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[18] == EMPTY)
        ui->C3->setStyleSheet(QString(""));
    else if (grid[18] == WHITE)
        ui->C3->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->C3->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[26] == EMPTY)
        ui->C4->setStyleSheet(QString(""));
    else if (grid[26] == WHITE)
        ui->C4->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->C4->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[34] == EMPTY)
        ui->C5->setStyleSheet(QString(""));
    else if (grid[34] == WHITE)
        ui->C5->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->C5->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[42] == EMPTY)
        ui->C6->setStyleSheet(QString(""));
    else if (grid[42] == WHITE)
        ui->C6->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->C6->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[50] == EMPTY)
        ui->C7->setStyleSheet(QString(""));
    else if (grid[50] == WHITE)
        ui->C7->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->C7->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[58] == EMPTY)
        ui->C8->setStyleSheet(QString(""));
    else if (grid[58] == WHITE)
        ui->C8->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->C8->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[3] == EMPTY)
        ui->D1->setStyleSheet(QString(""));
    else if (grid[3] == WHITE)
        ui->D1->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->D1->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[11] == EMPTY)
        ui->D2->setStyleSheet(QString(""));
    else if (grid[11] == WHITE)
        ui->D2->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->D2->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[19] == EMPTY)
        ui->D3->setStyleSheet(QString(""));
    else if (grid[19] == WHITE)
        ui->D3->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->D3->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[27] == EMPTY)
        ui->D4->setStyleSheet(QString(""));
    else if (grid[27] == WHITE)
        ui->D4->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->D4->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[35] == EMPTY)
        ui->D5->setStyleSheet(QString(""));
    else if (grid[35] == WHITE)
        ui->D5->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->D5->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[43] == EMPTY)
        ui->D6->setStyleSheet(QString(""));
    else if (grid[43] == WHITE)
        ui->D6->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->D6->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[51] == EMPTY)
        ui->D7->setStyleSheet(QString(""));
    else if (grid[51] == WHITE)
        ui->D7->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->D7->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[59] == EMPTY)
        ui->D8->setStyleSheet(QString(""));
    else if (grid[59] == WHITE)
        ui->D8->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->D8->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[4] == EMPTY)
        ui->E1->setStyleSheet(QString(""));
    else if (grid[4] == WHITE)
        ui->E1->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->E1->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[12] == EMPTY)
        ui->E2->setStyleSheet(QString(""));
    else if (grid[12] == WHITE)
        ui->E2->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->E2->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[20] == EMPTY)
        ui->E3->setStyleSheet(QString(""));
    else if (grid[20] == WHITE)
        ui->E3->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->E3->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[28] == EMPTY)
        ui->E4->setStyleSheet(QString(""));
    else if (grid[28] == WHITE)
        ui->E4->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->E4->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[36] == EMPTY)
        ui->E5->setStyleSheet(QString(""));
    else if (grid[36] == WHITE)
        ui->E5->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->E5->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[44] == EMPTY)
        ui->E6->setStyleSheet(QString(""));
    else if (grid[44] == WHITE)
        ui->E6->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->E6->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[52] == EMPTY)
        ui->E7->setStyleSheet(QString(""));
    else if (grid[52] == WHITE)
        ui->E7->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->E7->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[60] == EMPTY)
        ui->E8->setStyleSheet(QString(""));
    else if (grid[60] == WHITE)
        ui->E8->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->E8->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[5] == EMPTY)
        ui->F1->setStyleSheet(QString(""));
    else if (grid[5] == WHITE)
        ui->F1->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->F1->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[13] == EMPTY)
        ui->F2->setStyleSheet(QString(""));
    else if (grid[13] == WHITE)
        ui->F2->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->F2->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[21] == EMPTY)
        ui->F3->setStyleSheet(QString(""));
    else if (grid[21] == WHITE)
        ui->F3->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->F3->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[29] == EMPTY)
        ui->F4->setStyleSheet(QString(""));
    else if (grid[29] == WHITE)
        ui->F4->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->F4->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[37] == EMPTY)
        ui->F5->setStyleSheet(QString(""));
    else if (grid[37] == WHITE)
        ui->F5->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->F5->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[45] == EMPTY)
        ui->F6->setStyleSheet(QString(""));
    else if (grid[45] == WHITE)
        ui->F6->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->F6->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[53] == EMPTY)
        ui->F7->setStyleSheet(QString(""));
    else if (grid[53] == WHITE)
        ui->F7->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->F7->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[61] == EMPTY)
        ui->F8->setStyleSheet(QString(""));
    else if (grid[61] == WHITE)
        ui->F8->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->F8->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[6] == EMPTY)
        ui->G1->setStyleSheet(QString(""));
    else if (grid[6] == WHITE)
        ui->G1->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->G1->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[14] == EMPTY)
        ui->G2->setStyleSheet(QString(""));
    else if (grid[14] == WHITE)
        ui->G2->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->G2->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[22] == EMPTY)
        ui->G3->setStyleSheet(QString(""));
    else if (grid[22] == WHITE)
        ui->G3->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->G3->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[30] == EMPTY)
        ui->G4->setStyleSheet(QString(""));
    else if (grid[30] == WHITE)
        ui->G4->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->G4->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[38] == EMPTY)
        ui->G5->setStyleSheet(QString(""));
    else if (grid[38] == WHITE)
        ui->G5->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->G5->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[46] == EMPTY)
        ui->G6->setStyleSheet(QString(""));
    else if (grid[46] == WHITE)
        ui->G6->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->G6->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[54] == EMPTY)
        ui->G7->setStyleSheet(QString(""));
    else if (grid[54] == WHITE)
        ui->G7->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->G7->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[62] == EMPTY)
        ui->G8->setStyleSheet(QString(""));
    else if (grid[62] == WHITE)
        ui->G8->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->G8->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[7] == EMPTY)
        ui->H1->setStyleSheet(QString(""));
    else if (grid[7] == WHITE)
        ui->H1->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->H1->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[15] == EMPTY)
        ui->H2->setStyleSheet(QString(""));
    else if (grid[15] == WHITE)
        ui->H2->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->H2->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[23] == EMPTY)
        ui->H3->setStyleSheet(QString(""));
    else if (grid[23] == WHITE)
        ui->H3->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->H3->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[31] == EMPTY)
        ui->H4->setStyleSheet(QString(""));
    else if (grid[31] == WHITE)
        ui->H4->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->H4->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[39] == EMPTY)
        ui->H5->setStyleSheet(QString(""));
    else if (grid[39] == WHITE)
        ui->H5->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->H5->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[47] == EMPTY)
        ui->H6->setStyleSheet(QString(""));
    else if (grid[47] == WHITE)
        ui->H6->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->H6->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[55] == EMPTY)
        ui->H7->setStyleSheet(QString(""));
    else if (grid[55] == WHITE)
        ui->H7->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->H7->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

    if (grid[63] == EMPTY)
        ui->H8->setStyleSheet(QString(""));
    else if (grid[63] == WHITE)
        ui->H8->setStyleSheet(QString("background-color: rgb(0, 0, 0);"));
    else
        ui->H8->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));

}

void MainWindow::on_A1_clicked()
{
    c.makeMove('1','a');
    updateButtons();
}
void MainWindow::on_A2_clicked()
{
    c.makeMove('2','a');
    updateButtons();
}
void MainWindow::on_A3_clicked()
{
    c.makeMove('3','a');
    updateButtons();
}
void MainWindow::on_A4_clicked()
{
    c.makeMove('4','a');
    updateButtons();
}
void MainWindow::on_A5_clicked()
{
    c.makeMove('5','a');
    updateButtons();
}
void MainWindow::on_A6_clicked()
{
    c.makeMove('6','a');
    updateButtons();
}
void MainWindow::on_A7_clicked()
{
    c.makeMove('7','a');
    updateButtons();
}
void MainWindow::on_A8_clicked()
{
    c.makeMove('8','a');
    updateButtons();
}
void MainWindow::on_B1_clicked()
{
    c.makeMove('1','b');
    updateButtons();
}
void MainWindow::on_B2_clicked()
{
    c.makeMove('2','b');
    updateButtons();
}
void MainWindow::on_B3_clicked()
{
    c.makeMove('3','b');
    updateButtons();
}
void MainWindow::on_B4_clicked()
{
    c.makeMove('4','b');
    updateButtons();
}
void MainWindow::on_B5_clicked()
{
    c.makeMove('5','b');
    updateButtons();
}
void MainWindow::on_B6_clicked()
{
    c.makeMove('6','b');
    updateButtons();
}
void MainWindow::on_B7_clicked()
{
    c.makeMove('7','b');
    updateButtons();
}
void MainWindow::on_B8_clicked()
{
    c.makeMove('8','b');
    updateButtons();
}
void MainWindow::on_C1_clicked()
{
    c.makeMove('1','c');
    updateButtons();
}
void MainWindow::on_C2_clicked()
{
    c.makeMove('2','c');
    updateButtons();
}
void MainWindow::on_C3_clicked()
{
    c.makeMove('3','c');
    updateButtons();
}
void MainWindow::on_C4_clicked()
{
    c.makeMove('4','c');
    updateButtons();
}
void MainWindow::on_C5_clicked()
{
    c.makeMove('5','c');
    updateButtons();
}
void MainWindow::on_C6_clicked()
{
    c.makeMove('6','c');
    updateButtons();
}
void MainWindow::on_C7_clicked()
{
    c.makeMove('7','c');
    updateButtons();
}
void MainWindow::on_C8_clicked()
{
    c.makeMove('8','c');
    updateButtons();
}
void MainWindow::on_D1_clicked()
{
    c.makeMove('1','d');
    updateButtons();
}
void MainWindow::on_D2_clicked()
{
    c.makeMove('2','d');
    updateButtons();
}
void MainWindow::on_D3_clicked()
{
    c.makeMove('3','d');
    updateButtons();
}
void MainWindow::on_D4_clicked()
{
    c.makeMove('4','d');
    updateButtons();
}
void MainWindow::on_D5_clicked()
{
    c.makeMove('5','d');
    updateButtons();
}
void MainWindow::on_D6_clicked()
{
    c.makeMove('6','d');
    updateButtons();
}
void MainWindow::on_D7_clicked()
{
    c.makeMove('7','d');
    updateButtons();
}
void MainWindow::on_D8_clicked()
{
    c.makeMove('8','d');
    updateButtons();
}
void MainWindow::on_E1_clicked()
{
    c.makeMove('1','e');
    updateButtons();
}
void MainWindow::on_E2_clicked()
{
    c.makeMove('2','e');
    updateButtons();
}
void MainWindow::on_E3_clicked()
{
    c.makeMove('3','e');
    updateButtons();
}
void MainWindow::on_E4_clicked()
{
    c.makeMove('4','e');
    updateButtons();
}
void MainWindow::on_E5_clicked()
{
    c.makeMove('5','e');
    updateButtons();
}
void MainWindow::on_E6_clicked()
{
    c.makeMove('6','e');
    updateButtons();
}
void MainWindow::on_E7_clicked()
{
    c.makeMove('7','e');
    updateButtons();
}
void MainWindow::on_E8_clicked()
{
    c.makeMove('8','e');
    updateButtons();
}
void MainWindow::on_F1_clicked()
{
    c.makeMove('1','f');
    updateButtons();
}
void MainWindow::on_F2_clicked()
{
    c.makeMove('2','f');
    updateButtons();
}
void MainWindow::on_F3_clicked()
{
    c.makeMove('3','f');
    updateButtons();
}
void MainWindow::on_F4_clicked()
{
    c.makeMove('4','f');
    updateButtons();
}
void MainWindow::on_F5_clicked()
{
    c.makeMove('5','f');
    updateButtons();
}
void MainWindow::on_F6_clicked()
{
    c.makeMove('6','f');
    updateButtons();
}
void MainWindow::on_F7_clicked()
{
    c.makeMove('7','f');
    updateButtons();
}
void MainWindow::on_F8_clicked()
{
    c.makeMove('8','f');
    updateButtons();
}
void MainWindow::on_G1_clicked()
{
    c.makeMove('1','g');
    updateButtons();
}
void MainWindow::on_G2_clicked()
{
    c.makeMove('2','g');
    updateButtons();
}
void MainWindow::on_G3_clicked()
{
    c.makeMove('3','g');
    updateButtons();
}
void MainWindow::on_G4_clicked()
{
    c.makeMove('4','g');
    updateButtons();
}
void MainWindow::on_G5_clicked()
{
    c.makeMove('5','g');
    updateButtons();
}
void MainWindow::on_G6_clicked()
{
    c.makeMove('6','g');
    updateButtons();
}
void MainWindow::on_G7_clicked()
{
    c.makeMove('7','g');
    updateButtons();
}
void MainWindow::on_G8_clicked()
{
    c.makeMove('8','g');
    updateButtons();
}
void MainWindow::on_H1_clicked()
{
    c.makeMove('1','h');
    updateButtons();
}
void MainWindow::on_H2_clicked()
{
    c.makeMove('2','h');
    updateButtons();
}
void MainWindow::on_H3_clicked()
{
    c.makeMove('3','h');
    updateButtons();
}
void MainWindow::on_H4_clicked()
{
    c.makeMove('4','h');
    updateButtons();
}
void MainWindow::on_H5_clicked()
{
    c.makeMove('5','h');
    updateButtons();
}
void MainWindow::on_H6_clicked()
{
    c.makeMove('6','h');
    updateButtons();
}
void MainWindow::on_H7_clicked()
{
    c.makeMove('7','h');
    updateButtons();
}
void MainWindow::on_H8_clicked()
{
    c.makeMove('8','h');
    updateButtons();
}

void MainWindow::on_actionEASY_triggered()
{
    c.setEasy();
}

void MainWindow::on_actionMEDIUM_triggered()
{
    c.setMedium();
}

void MainWindow::on_actionHARD_triggered()
{
    c.setHard();
}
