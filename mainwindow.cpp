#include "mainwindow.h"
#include "mutingbutton.h"
#include <QPushButton>
#include <QLabel>
#include <QSignalMapper>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Define Background Color of MainWindow
    this->setStyleSheet(QString("background-color: %1").arg(QColor::fromRgb(214,231,238).name()));

    // Define Frame for Mute and Single Buttons
    frame_mute_buttons = new QWidget(this);
    frame_mute_buttons->setGeometry(QRect(QPoint(10, 600), QSize(270, 135)));

    // Define Background Color of MuteButton-Frame
    frame_mute_buttons->setStyleSheet(QString("background-color: %1").arg(QColor::fromRgb(199,199,199).name()));

    // Define all 8 Mute/Single Buttons and Channel Labels
        const int btn_size = 25;
        const int vspace_btn = 5;
        const int hspace_btn = 140;
        for (int i = 0; i < 8; i++)
        {
            ch_labels[i] = new QLabel(QString("Channel %1").arg(i+1), frame_mute_buttons);
            ch_labels[i]->setGeometry(QRect(QPoint(5 + hspace_btn*(i/4), 10 + (btn_size + vspace_btn)*(i%4)), QSize(60, 20)));

            mute_buttons[i] = new MutingButton("M", frame_mute_buttons);
            mute_buttons[i]->setEnabled(false);
            mute_buttons[i]->setGeometry(QRect(QPoint(70 + hspace_btn*(i/4), 10 + (btn_size + vspace_btn)*(i%4)), QSize(btn_size, btn_size)));

            connect(mute_buttons[i], &QPushButton::clicked, mute_buttons[i], &MutingButton::change_state); // Changing state of button
            connect(mute_buttons[i], &QPushButton::clicked, this, &MainWindow::updateMutings); // update Mutings afterwards

            single_buttons[i] = new MutingButton("S", frame_mute_buttons);
            single_buttons[i]->setEnabled(false);
            single_buttons[i]->setGeometry(QRect(QPoint(100 + hspace_btn*(i/4), 10 + (btn_size + vspace_btn)*(i%4)), QSize(btn_size, btn_size)));

            connect(single_buttons[i], &QPushButton::clicked, single_buttons[i], &MutingButton::change_state); // Changing state of button
            connect(single_buttons[i], &QPushButton::clicked, this, &MainWindow::updateMutings); // update Mutings afterwards
        }

}

MainWindow::~MainWindow()
{
}

void MainWindow::updateMutings()
{
    // Check states of each mute/single button and make a decsision which channels are muted
}
