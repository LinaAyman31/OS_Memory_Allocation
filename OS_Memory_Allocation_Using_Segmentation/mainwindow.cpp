#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

int new_row = 0;

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
    QVBoxLayout *holes_layout = new QVBoxLayout;
    QVBoxLayout *process_layout = new QVBoxLayout;
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
    dellocate_button = new QPushButton;
    process_table = new QTableWidget;
    QStringList horizontal_process_labels;
    //QStringList vertical_process_labels;
    allocate_button = new QPushButton;

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
    dellocate_button->setText("Dellocate");
    //process table
    process_table->setColumnCount(2);
    //process_table->setRowCount(1);
    horizontal_process_labels << "Name" << "Size";
    //vertical_process_labels << "1";
    process_table->setHorizontalHeaderLabels(horizontal_process_labels);
    //process_table->setVerticalHeaderLabels(vertical_process_labels);
    process_table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    process_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    allocate_button->setText("Allocate Process");

    // ************** layouts *******************************
    layout_for_memory_size->addWidget(label_for_memory_size);
    layout_for_memory_size->addWidget(lineEdit_for_memory_size);
    layout_for_memory_size->addWidget(push_button_for_memory_size);
    holes_layout->addWidget(add_holes_button);
    holes_layout->addWidget(holes_table);
    holes_layout->addWidget(submit_holes);
    segments_layout->addWidget(label_for_number_of_segments);
    segments_layout->addWidget(lineEdit_for_segments);
    segments_layout->addWidget(enter_segments);
    process_method->addWidget(method_for_process);
    process_method->addWidget(first_fit);
    process_method->addWidget(best_fit);
    process_method->addWidget(worst_fit);
    process_method->addWidget(shuffle);
    process_layout->addWidget(process_table);
    process_layout->addWidget(allocate_button);
    choose_process_to_dellocate_layout->addWidget(process_dellocation);
    choose_process_to_dellocate_layout->addWidget(old_process);
    choose_process_to_dellocate_layout->addWidget(new_process);
    process_dellocation_layout->addWidget(label_for_process_number);
    process_dellocation_layout->addWidget(lineEdit_for_process_number);
    process_dellocation_layout->addWidget(dellocate_button);
    process_dellocation_vertical_layout->addLayout(choose_process_to_dellocate_layout);
    process_dellocation_vertical_layout->addLayout(process_dellocation_layout);
    left_layout->addLayout(layout_for_memory_size);
    left_layout->addLayout(holes_layout);
    left_layout->addLayout(segments_layout);
    left_layout->addLayout(process_method);
    left_layout->addLayout(process_layout);
    right_layout->addLayout(process_dellocation_vertical_layout);
    main_layout->addLayout(left_layout);
    main_layout->addLayout(right_layout);

    setCentralWidget(widget);

    connect_buttons_function();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connect_buttons_function() {
    connect(push_button_for_memory_size, SIGNAL(clicked), this, SLOT(add_memory_size_button_clicked()));
    connect(submit_holes, SIGNAL(clicked()), this, SLOT(submit_holes_button_clicked()));
    connect(add_holes_button, SIGNAL(clicked()), this, SLOT(add_hole_button_clicked()));
    connect(enter_segments, SIGNAL(clicked()), this, SLOT(enter_segments_button_clicked()));
    connect(allocate_button, SIGNAL(clicked()), this, SLOT(allocate_process_button_clicked*()));
    connect(dellocate_button, SIGNAL(clicked()), this, SLOT(dellocate_process_button_clicked()));
}

void MainWindow::add_memory_size_button_clicked() {

}

void MainWindow::submit_holes_button_clicked() {

}

void MainWindow::add_hole_button_clicked() {
    add_holes_button->setText("Add new hole");
    new_row++;
    holes_table->insertRow(new_row);
}

void MainWindow::enter_segments_button_clicked() {
    QStringList vertical_process_labels;
    QString segments_number = lineEdit_for_segments->text();
    process_table->setRowCount(segments_number.toInt());
    for (int i = 0; i < segments_number.toInt(); i++) {
        vertical_process_labels << QString::number(i + 1);
    }
}

void MainWindow::allocate_process__button_clicked() {

}

void MainWindow::dellocate_process_button_clicked() {

}
