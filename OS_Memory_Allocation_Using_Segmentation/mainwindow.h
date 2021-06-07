#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QRadioButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLineEdit *lineEdit_for_memory_size;
    QLabel *label_for_memory_size;
    QPushButton *push_button_for_memory_size;
    QPushButton *add_holes_button;
    QTableWidget *holes_table;
    QPushButton *submit_holes;
    QLabel *label_for_number_of_segments;
    QLineEdit *lineEdit_for_segments;
    QPushButton *enter_segments;
    QLabel *method_for_process;
    QRadioButton *first_fit;
    QRadioButton *best_fit;
    QRadioButton *worst_fit;
    QRadioButton *shuffle;
    QLabel *process_dellocation;
    QRadioButton *old_process;
    QRadioButton *new_process;
    QLabel *label_for_process_number;
    QLineEdit *lineEdit_for_process_number;
    QPushButton *enter_process_number;
};
#endif // MAINWINDOW_H
