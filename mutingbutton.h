#ifndef MUTINGBUTTON_H
#define MUTINGBUTTON_H

#include <QPushButton>

class MutingButton : public QPushButton
{
    Q_OBJECT
public:
    MutingButton(const QString & text, QWidget * parent = 0);
    bool getState();
    ~MutingButton();
private:
    bool isOn;
    QColor background_col_on;
    QColor background_col_off;
public slots:
    void change_state();
};

#endif // MUTINGBUTTON_H
