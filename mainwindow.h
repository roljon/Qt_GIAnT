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

    QWidget *frame_mute_buttons, *frame_loadsave_buttons;
    MutingButton *mute_buttons[8], *single_buttons[8];
    QPushButton *load_button, *save_button, *sad_button;
    QLabel *ch_labels[8], *current_time_label, *total_time_label, *current_time, *total_time;
    QWidget *frame_current_time, *frame_total_time;

    void updateMutings();
    void LoadProject();
    void SaveProject();
    void RunSAD();

private slots:

};
#endif // MAINWINDOW_H
