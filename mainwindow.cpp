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

        // Define Frame for Load and Save Buttons
        frame_loadsave_buttons = new QWidget(this);
        frame_loadsave_buttons->setGeometry(QRect(QPoint(10, 800), QSize(270, 155)));

        // Define Background Color of MuteButton-Frame
        frame_loadsave_buttons->setStyleSheet(QString("background-color: %1").arg(QColor::fromRgb(199,199,199).name()));

        // Initialize Load/Save Button
        load_button = new QPushButton("Load", frame_loadsave_buttons);
        load_button->setGeometry(QRect(QPoint(10, 60), QSize(75, 25)));
        connect(load_button, &QPushButton::clicked, this, &MainWindow::LoadProject);

        save_button = new QPushButton("Save", frame_loadsave_buttons);
        save_button->setGeometry(QRect(QPoint(110, 60), QSize(75, 25)));
        save_button->setEnabled(false);
        connect(save_button, &QPushButton::clicked, this, &MainWindow::SaveProject);

        // Initialize SAD-Button
        sad_button= new QPushButton("SAD", frame_loadsave_buttons);
        sad_button->setGeometry(QRect(QPoint(10, 30), QSize(75, 25)));
        connect(sad_button, &QPushButton::clicked, this, &MainWindow::RunSAD);

        // Initialize frame for current and total time labels within load/save-Frame
        frame_current_time = new QWidget(frame_loadsave_buttons);
        frame_current_time->setGeometry(QRect(QPoint(10, 100), QSize(115, 40)));
        frame_current_time->setStyleSheet(QString("background-color: %1").arg(QColor::fromRgb(143,25,44).name()));

        frame_total_time = new QWidget(frame_loadsave_buttons);
        frame_total_time->setGeometry(QRect(QPoint(145, 100), QSize(115, 40)));
        frame_total_time->setStyleSheet(QString("background-color: %1").arg(QColor::fromRgb(87,110,117).name()));

        // Initialize Time and Total Label
        current_time_label = new QLabel(QString("Time:"), frame_current_time);
        current_time_label->setGeometry(QRect(40, 2, 32, 15));
        current_time_label->setStyleSheet(QString("color: %1").arg(QColor::fromRgb(255,255,255).name()));

        total_time_label = new QLabel(QString("Total:"), frame_total_time);
        total_time_label->setGeometry(QRect(40, 2, 32, 15));
        total_time_label->setStyleSheet(QString("color: %1").arg(QColor::fromRgb(255,255,255).name()));

        // Initialize Current and Total Time Label
        current_time = new QLabel(QString("--:--:--:---"), frame_current_time);
        current_time->setGeometry(QRect(5, 22, 105, 16));
        current_time->setStyleSheet(QString("color: %1").arg(QColor::fromRgb(255,255,255).name()));
        current_time->setFont(QFont("Times", 14));
        current_time->setAlignment(Qt::AlignCenter);

        total_time = new QLabel(QString("--:--:--:---"), frame_total_time);
        total_time->setGeometry(QRect(5, 22, 105, 16));
        total_time->setStyleSheet(QString("color: %1").arg(QColor::fromRgb(255,255,255).name()));
        total_time->setFont(QFont("Times", 14));
        total_time->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
}

void MainWindow::updateMutings()
{
    // Check states of each mute/single button and make a decsision which channels are muted
}

void MainWindow::LoadProject()
{
    // TODO: implement to load project folder
}

void MainWindow::SaveProject()
{
    // TODO: implement to save project folder
}

void MainWindow::RunSAD()
{
    // TODO: implement Speaker Activity Detection
}
