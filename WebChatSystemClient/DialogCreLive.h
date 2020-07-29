#ifndef DIALOGCRELIVE_H
#define DIALOGCRELIVE_H

#include <QDialog>
#include "Live.h"

namespace Ui {
class DialogCreLive;
}

class DialogCreLive : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreLive(QWidget *parent = nullptr);
    ~DialogCreLive();

signals:
    void sendCre(const QString&);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DialogCreLive *ui;
};

#endif // DIALOGCRELIVE_H
