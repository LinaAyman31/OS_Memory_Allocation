#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QMessageBox>

int new_row = 0;
int process_no =0;
vector<Segment> holes;
vector<Segment> process;
vector<Segment> memory;

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
    connect(allocate_button, SIGNAL(clicked()), this, SLOT(allocate_process_button_clicked()));
    connect(dellocate_button, SIGNAL(clicked()), this, SLOT(dellocate_process_button_clicked()));
}

void MainWindow::add_memory_size_button_clicked() {

}

void MainWindow::submit_holes_button_clicked() {
    QString memory_size = lineEdit_for_memory_size ->text();
    if(memory_size.toInt()<=0){
        QMessageBox::warning(this, "Wrong Input", "Please enter positive number");
    }
    int total_size=0;
    Segment h;
    for(int i=0;i<holes_table->rowCount();i++){
        QString starting_address = holes_table->item(i, 0)->text();
        QString size = holes_table->item(i, 1)->text();
        total_size+= size.toInt();
        if(size.toInt()<=0 || starting_address.toInt() <=0){
            QMessageBox::warning(this, "Wrong Input", "Please enter positive number");
        }
        if(total_size > memory_size.toInt() ){
             QMessageBox::warning(this, "Wrong Input", "holes size exceeds the memory size");
        }
        h.starting_address = starting_address.toInt();
        h.size = size.toInt();
        h.finish_address = h.starting_address + h.size;
        h.name = "hole";
        h.type =1;
        h.id =i;
        holes.push_back(h);
    }

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

void MainWindow::allocate_process_button_clicked() {
    Segment p;
    for(int i=0;i<process_table->rowCount();i++){
        QString name = process_table->item(i, 0)->text();
        QString size = process_table->item(i, 1)->text();
        if(size.toInt()<=0){
            QMessageBox::warning(this, "Wrong Input", "Please enter positive number");
        }
        p.size = size.toInt();
        p.name = name;
        p.type =0;
        p.id =process_no;
        process.push_back(p);
    }
    process_no ++;
}

void deAllocate(vector <Segment>& holes, vector <Segment>& memory, int type, int id)
{
    for (int i = 0; i < memory.size(); i++)
    {
        if (memory[i].type == type && memory[i].id == id)
        {
            memory[i].name = "hole";
            memory[i].type = 1;
            memory[i].id = i;
            holes.push_back(memory[i]);
        }
    }
}

void MainWindow::dellocate_process_button_clicked() {
    QString deallocate_process = lineEdit_for_process_number ->text();
    if(deallocate_process.toInt()<=0) {
        QMessageBox::warning(this, "Wrong Input", "Please enter positive number");
    }
}

void MainWindow::manage_holes(vector<Segment>& holes, int &numberOfHoles) {
    for (int i = 0; i < numberOfHoles; i++) {
        holes[i].id = i;
        for (int j = i + 1; j < numberOfHoles; j++) {
            if (holes[j].starting_address < holes[i].finish_address && holes[j].size >= holes[i].starting_address) {
                if (holes[i].finish_address < holes[j].finish_address) {
                    holes[i].finish_address = holes[j].finish_address;
                    holes[i].size = holes[i].finish_address - holes[i].starting_address;
                }
                if (holes[i].starting_address > holes[j].starting_address) {
                    holes[i].starting_address = holes[j].starting_address;
                    holes[i].size += holes[j].size;
                }
                holes.erase(holes.begin() + j);
                j--;
                numberOfHoles--;
            }
            else if (holes[j].starting_address == holes[i].finish_address) {
                holes[i].finish_address = holes[j].finish_address;
                holes[i].size = holes[i].finish_address - holes[i].starting_address;
                holes.erase(holes.begin() + j);
                j--;
                numberOfHoles--;
            }
        }
    }
}

void MainWindow::fill_memory(vector<Segment>& memory, vector<Segment> holes, int numberOfHoles, int finishOfMemory) {
    Segment min_hole;
    bool flag = true;
    int index;
    while (!holes.empty()) {
        min_hole.starting_address = 10000000;
        for (int i = 0; i < numberOfHoles; i++) {
            if (holes[i].starting_address <= min_hole.starting_address) {
                min_hole = holes[i];
                index = i;
            }
        }
        if (min_hole.starting_address != 0 && flag) {
            Segment first;
            first.starting_address = 0;
            first.finish_address = min_hole.starting_address;
            first.size = first.finish_address;
            first.type = 0;
            first.name = "Old process";
            memory.push_back(first);
            memory.push_back(min_hole);
            flag = false;
        }
        else if(min_hole.starting_address != 0) {
            Segment hole;
            Segment temp;
            temp = memory.back();
            hole.starting_address = temp.finish_address;
            hole.size = min_hole.starting_address - temp.finish_address;
            hole.finish_address = hole.size + hole.starting_address;
            hole.type = 0;
            hole.name = "Old Process";
            memory.push_back(hole);
            memory.push_back(min_hole);
        }
        else if (min_hole.starting_address == 0) {
            memory.push_back(min_hole);
            flag = false;
        }
        holes.erase(holes.begin() + index);
        numberOfHoles--;
    }
    Segment last = memory.back();
    if (last.finish_address != finishOfMemory) {
        last.starting_address = last.finish_address;
        last.finish_address = finishOfMemory;
        last.size = last.finish_address - last.starting_address;
        last.type = 0;
        last.name = "Old process";
        memory.push_back(last);
    }
}

void MainWindow::first_fit_algorithm(vector<Segment> &memory, vector<Segment> process, vector<Segment> &holes){
    Segment temp_hole;
        vector<Segment> temp_memory;
        temp_memory = memory;
        int hole_index;
        for (int i = 0; i < process.size(); i++) {
            for (int j = 0; j < temp_memory.size(); j++) {
                if (process[i].size < temp_memory[j].size && temp_memory[j].type == 1) {
                    process[i].starting_address = temp_memory[j].starting_address;
                    process[i].finish_address = process[i].starting_address + process[i].size;
                    temp_hole = temp_memory[j];
                    //take index of the hole vector
                    hole_index = temp_memory[j].id;

                    temp_memory.erase(temp_memory.begin() + j);
                    temp_memory.insert(temp_memory.begin() + j, process[i]);
                    process[i].is_fit_in_memory = true;
                    temp_hole.starting_address = process[i].finish_address;
                    temp_hole.size = temp_hole.finish_address - temp_hole.starting_address;
                    //edit in the holes vector
                    holes[hole_index] = temp_hole;

                    temp_memory.insert(temp_memory.begin() + j + 1, temp_hole);
                    break;
                }
                else if (process[i].size == temp_memory[j].size && temp_memory[j].type == 1) {
                    process[i].starting_address = temp_memory[j].starting_address;
                    process[i].finish_address = process[i].starting_address + process[i].size;
                    //edit in the holes vector
                    hole_index = temp_memory[j].id;
                    holes.erase(holes.begin() + hole_index);

                    temp_memory.erase(temp_memory.begin() + j);
                    temp_memory.insert(temp_memory.begin() + j, process[i]);
                    process[i].is_fit_in_memory = true;
                    break;
                }
            }
        }
        for (int i = 0; i < process.size(); i++) {
            if (!process[i].is_fit_in_memory) {
                //scout << "Process can not fit.";
                return;
            }
        }
        memory = temp_memory;
}



class compare
{
public:
    bool operator()(Segment x, Segment y)
    {
        return x.size> y.size;
    }
};
class compare2
{
public:
    bool operator()(Segment x, Segment y)
    {
        return x.starting_address > y.starting_address;
    }
};


vector <Segment> total_memory(vector <Segment>const &holes_after_allocation, vector <Segment>const &old_memory, vector <Segment>const &allocated)
{
    priority_queue<Segment, vector<Segment>, compare2> memory;
    for (int i = 0; i < holes_after_allocation.size() || i < allocated.size() || i < old_memory.size(); i++)
    {
        if (i < holes_after_allocation.size())memory.push(holes_after_allocation[i]);
        if (i < allocated.size())memory.push(allocated[i]);
        if (i < old_memory.size())memory.push(old_memory[i]);
    }
    vector<Segment> m;
    while (!memory.empty())
    {
        m.push_back(memory.top());
        memory.pop();
    }
    return m;
}
vector <Segment> MainWindow::best_fit_algorithm(vector <Segment> &holes, vector <Segment> &old_memory, vector <Segment> &process ){
    for (int i = 0; i < old_memory.size(); i++)
    {
        if (old_memory[i].type == 1)
        {
            old_memory.erase(old_memory.begin() + i);
        }
    }
    priority_queue<Segment, vector<Segment>, compare> x;
    priority_queue<Segment, vector<Segment>, compare> y;
    vector<Segment> allocated;
    vector<Segment> holes_after_allocation;
    for (int i = 0; i < holes.size(); i++)
    {
        x.push(holes[i]);
    }
    for (int i = 0; i < process.size(); i++)
    {
        y.push(process[i]);
    }
    Segment top_y, top_x;
    while (!y.empty())
    {
        if (x.empty())
        {
            allocated.clear();
            holes_after_allocation = holes;
            break;
        }
        top_y = y.top();
        top_x = x.top();
        if (top_y.size <=top_x.size)
        {
            allocated.push_back(Segment{top_y.id ,top_y.name ,top_x.starting_address ,top_y.size ,top_y.type});
            x.pop();
            y.pop();
            top_x.size -= top_y.size;
            if (top_x.size) {
                top_x.starting_address += top_y.size;
                x.push(top_x);
            }
        }
        else
        {
            holes_after_allocation.push_back(top_x);
            x.pop();
        }
    }
    while(!x.empty())
    {
        holes_after_allocation.push_back(x.top());
        x.pop();
    }
    holes = holes_after_allocation;
    return total_memory(holes_after_allocation, old_memory, allocated);
}

void MainWindow::worst_fit_algorithm(){

}

void MainWindow::shuffle_algorithm(){

}
