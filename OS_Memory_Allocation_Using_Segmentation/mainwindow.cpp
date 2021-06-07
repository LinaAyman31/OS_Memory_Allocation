#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // *************** initiate_instances *******************
    QWidget *widget = new QWidget;
    QHBoxLayout *main_layout = new QHBoxLayout;
    QVBoxLayout *left_layout = new QVBoxLayout;
    QVBoxLayout *right_layout = new QVBoxLayout;
    QHBoxLayout *layout_for_memory_size = new QHBoxLayout;
    QVBoxLayout *holes_processes_layout = new QVBoxLayout;
    QHBoxLayout *segments_layout = new QHBoxLayout;
    QHBoxLayout *process_method = new QHBoxLayout;
    QHBoxLayout *choose_process_to_dellocate_layout = new QHBoxLayout;
    QHBoxLayout *process_dellocation_layout = new QHBoxLayout;
    QVBoxLayout *process_dellocation_vertical_layout = new QVBoxLayout;
    lineEdit_for_memory_size = new QLineEdit;
    label_for_memory_size = new QLabel;
    push_button_for_memory_size = new QPushButton;
    add_holes_button = new QPushButton;
    holes_table = new QTableWidget;
    QStringList vertical_holes_labels;
    QStringList horizontal_holes_labels;
    submit_holes = new QPushButton;
    label_for_number_of_segments = new QLabel;
    lineEdit_for_segments = new QLineEdit;
    enter_segments = new QPushButton;
    method_for_process = new QLabel;
    first_fit = new QRadioButton;
    best_fit = new QRadioButton;
    worst_fit = new QRadioButton;
    shuffle = new QRadioButton;
    process_dellocation = new QLabel;
    old_process = new QRadioButton;
    new_process = new QRadioButton;
    label_for_process_number = new QLabel;
    lineEdit_for_process_number = new QLineEdit;
    enter_process_number = new QPushButton;

    // ************** usage of instances ********************
    widget->setLayout(main_layout);
    label_for_memory_size->setText("Enter total size of memory: ");
    push_button_for_memory_size->setText("Enter");
    add_holes_button->setText("Add Hole");
    holes_table->setColumnCount(2);
    holes_table->setRowCount(1);
    horizontal_holes_labels << "Starting Address" << "Size";
    holes_table->setHorizontalHeaderLabels(horizontal_holes_labels);
    holes_table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    holes_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    vertical_holes_labels << "1";
    holes_table->setVerticalHeaderLabels(vertical_holes_labels);
    submit_holes->setText("Submit");
    label_for_number_of_segments->setText("Enter number of segments: ");
    enter_segments->setText("Enter");
    method_for_process->setText("Choose method: ");
    first_fit->setText("First Fit");
    best_fit->setText("Best Fit");
    worst_fit->setText("Worst Fit");
    shuffle->setText("Shuffle");
    process_dellocation->setText("Choose process to dellocate: ");
    old_process->setText("Old Process");
    new_process->setText("New Process");
    label_for_process_number->setText("Enter process number: ");
    enter_process_number->setText("Dellocate");

    // ************** layouts *******************************
    layout_for_memory_size->addWidget(label_for_memory_size);
    layout_for_memory_size->addWidget(lineEdit_for_memory_size);
    layout_for_memory_size->addWidget(push_button_for_memory_size);
    holes_processes_layout->addWidget(add_holes_button);
    holes_processes_layout->addWidget(holes_table);
    holes_processes_layout->addWidget(submit_holes);
    segments_layout->addWidget(label_for_number_of_segments);
    segments_layout->addWidget(lineEdit_for_segments);
    segments_layout->addWidget(enter_segments);
    process_method->addWidget(method_for_process);
    process_method->addWidget(first_fit);
    process_method->addWidget(best_fit);
    process_method->addWidget(worst_fit);
    process_method->addWidget(shuffle);
    choose_process_to_dellocate_layout->addWidget(process_dellocation);
    choose_process_to_dellocate_layout->addWidget(old_process);
    choose_process_to_dellocate_layout->addWidget(new_process);
    process_dellocation_layout->addWidget(label_for_process_number);
    process_dellocation_layout->addWidget(lineEdit_for_process_number);
    process_dellocation_layout->addWidget(enter_process_number);
    process_dellocation_vertical_layout->addLayout(choose_process_to_dellocate_layout);
    process_dellocation_vertical_layout->addLayout(process_dellocation_layout);
    left_layout->addLayout(layout_for_memory_size);
    left_layout->addLayout(holes_processes_layout);
    left_layout->addLayout(segments_layout);
    left_layout->addLayout(process_method);
    right_layout->addLayout(process_dellocation_vertical_layout);
    main_layout->addLayout(left_layout);
    main_layout->addLayout(right_layout);

    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

