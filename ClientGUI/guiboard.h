#ifndef GUIBOARD_H
#define GUIBOARD_H

#include <QWidget>

namespace Ui {
class GUIBoard;
}

class GUIBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GUIBoard(QWidget *parent = 0);
    ~GUIBoard();

private:
    Ui::GUIBoard *ui;
};

#endif // GUIBOARD_H
