#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QRadioButton>
#include <vector>
#include <queue>
#include <algorithm>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

using namespace std;

const int Rectangle_Width=120;
const double Rectangle_Height=0.7;

struct Segment {
    int id;
    QString name;
    int starting_address;
    int finish_address;
    int size  ;
    int type;
    int index;
    bool is_fit_in_memory;
};

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
    vector <Segment> best_fit_algorithm(vector <Segment> &holes, vector <Segment> &old_memory, vector <Segment> &process);
    void first_fit_algorithm(std::vector<Segment> &memory, std::vector<Segment> process, std::vector<Segment> &holes);
    void worst_fit_algorithm(vector<Segment> procces,vector<Segment> &holes, vector<Segment> &all);
    vector <Segment> shuffle_algorithm(vector<Segment> &memory, vector<Segment> &process);
    void manage_holes(std::vector<Segment>& holes);
    void fill_memory(vector<Segment>& memory, vector<Segment> holes, int finishOfMemory);
    void draw_memory(vector<Segment> memory);
    void manage_holes_id(vector<Segment> &memory);

private slots:
    void submit_holes_button_clicked();
    void add_hole_button_clicked();
    void remove_hole_button_clicked();
    void enter_segments_button_clicked();
    void allocate_process_button_clicked();
    void dellocate_process_button_clicked();

private:
    Ui::MainWindow *ui;
    QLineEdit *lineEdit_for_memory_size;
    QLabel *label_for_memory_size;
    //QPushButton *push_button_for_memory_size;
    QPushButton *add_holes_button;
    QPushButton *remove_hole_button;
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
    QPushButton *dellocate_button;
    QTableWidget *process_table;
    QPushButton *allocate_button;
    QGraphicsScene *draw_scene;
    QGraphicsView *view;
    QGraphicsRectItem *rectangle;
};
#endif // MAINWINDOW_H
