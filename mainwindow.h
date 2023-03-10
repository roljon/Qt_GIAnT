#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class QWidget;
class QPushButton;
class QLabel;
class MutingButton;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QWidget *frame_mute_buttons;
    MutingButton *mute_buttons[8];
    MutingButton *single_buttons[8];
    QLabel *ch_labels[8];

    void updateMutings();

private slots:

};
#endif // MAINWINDOW_H
