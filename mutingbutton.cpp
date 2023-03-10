#include "mutingbutton.h"

MutingButton::MutingButton(const QString & text, QWidget * parent) : QPushButton(text, parent)
{
    isOn = false;
    if (text == 'M') // if Mutebutton
    {
        background_col_off = QColor::fromRgb(255,0,0);
        background_col_on = QColor::fromRgb(0,255,0);
    }
    else if (text == 'S') // if Singlebutton
    {
        background_col_off = QColor::fromRgb(0,0,255);
        background_col_on = QColor::fromRgb(255,255,0);
    }
    else
        assert("Wether Mute nor Single Button");
}

void MutingButton::change_state()
{
    if (isOn)
        isOn = false;
    else
        isOn = true;
    if (isOn)
        this->setStyleSheet(QString("background-color: %1").arg(background_col_off.name()));
    else
        this->setStyleSheet(QString("background-color: %1").arg(background_col_on.name()));
}


MutingButton::~MutingButton()
{

}
