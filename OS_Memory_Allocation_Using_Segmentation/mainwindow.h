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
    void connect_buttons_function();

private slots:
    void add_memory_size_button_clicked();
    void submit_holes_button_clicked();
    void add_hole_button_clicked();
    void enter_segments_button_clicked();
    void allocate_process__button_clicked();

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
    QTableWidget *process_table;
    QPushButton *allocate_button;
};
#endif // MAINWINDOW_H
