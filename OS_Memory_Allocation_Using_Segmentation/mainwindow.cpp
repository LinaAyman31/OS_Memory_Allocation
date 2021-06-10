#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QMessageBox>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsTextItem>
#include <QColor>
#include <QDebug>
int new_row = 0;
int process_no =0;
int holes_total_size=0;
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
    QHBoxLayout *layout_for_add_remove_hole = new QHBoxLayout;
    QVBoxLayout *holes_layout = new QVBoxLayout;
    QVBoxLayout *process_layout = new QVBoxLayout;
    QHBoxLayout *segments_layout = new QHBoxLayout;
    QHBoxLayout *process_method = new QHBoxLayout;
    QHBoxLayout *choose_process_to_dellocate_layout = new QHBoxLayout;
    QHBoxLayout *process_dellocation_layout = new QHBoxLayout;
    QVBoxLayout *process_dellocation_vertical_layout = new QVBoxLayout;
    lineEdit_for_memory_size = new QLineEdit;
    label_for_memory_size = new QLabel;
    //push_button_for_memory_size = new QPushButton;
    add_holes_button = new QPushButton;
    remove_hole_button = new QPushButton;
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
    draw_scene = new QGraphicsScene(this);
    view = new QGraphicsView(draw_scene);
    rectangle = new QGraphicsRectItem;

    // ************** usage of instances ********************
    widget->setLayout(main_layout);
    label_for_memory_size->setText("Enter total size of memory: ");
    //push_button_for_memory_size->setText("Enter");
    add_holes_button->setText("Add new hole");
    remove_hole_button->setText("Clear hole");
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
    //view->setScene(draw_scene);

    // ************** layouts *******************************
    layout_for_memory_size->addWidget(label_for_memory_size);
    layout_for_memory_size->addWidget(lineEdit_for_memory_size);
   // layout_for_memory_size->addWidget(push_button_for_memory_size);
    layout_for_add_remove_hole->addWidget(add_holes_button);
    layout_for_add_remove_hole->addWidget(remove_hole_button);
    holes_layout->addLayout(layout_for_add_remove_hole);
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
    right_layout->addWidget(view);
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
    connect(submit_holes, SIGNAL(clicked()), this, SLOT(submit_holes_button_clicked()));
    connect(add_holes_button, SIGNAL(clicked()), this, SLOT(add_hole_button_clicked()));
    connect(remove_hole_button, SIGNAL(clicked()), this, SLOT(remove_hole_button_clicked()));
    connect(enter_segments, SIGNAL(clicked()), this, SLOT(enter_segments_button_clicked()));
    connect(allocate_button, SIGNAL(clicked()), this, SLOT(allocate_process_button_clicked()));
    connect(dellocate_button, SIGNAL(clicked()), this, SLOT(dellocate_process_button_clicked()));
}


void MainWindow::draw_memory(vector<Segment> memory) {
    QBrush color_brush(QColor("white"));
    QPen blackpen(Qt::black);
    blackpen.setWidth(1);

    rectangle=draw_scene->addRect(QRectF(-200,0,Rectangle_Width,Rectangle_Height*memory[0].size),blackpen, color_brush);
    QString start_address = QString::number(memory[0].starting_address);
    QGraphicsTextItem *txtitem = new QGraphicsTextItem(start_address);
    txtitem->setPos(QPointF(-230, -13));
    draw_scene->addItem(txtitem);
    QString finish_address = QString::number(memory[0].finish_address);
    QGraphicsTextItem *txtitem_2 = new QGraphicsTextItem(finish_address);
    txtitem_2->setPos(QPointF(-240, -13+Rectangle_Height*memory[0].size));
    draw_scene->addItem(txtitem_2);

    //to write inside memory;
    QGraphicsTextItem *text_inside_memory;
    if (memory[0].type == 0) {
        text_inside_memory = new QGraphicsTextItem("P" +QString::number(memory[0].id) + ":" + memory[0].name);
    }
    else {
        text_inside_memory = new QGraphicsTextItem(memory[0].name+QString::number(memory[0].id));
    }
    text_inside_memory->setPos(QPointF(-240 + Rectangle_Width/2, -13+(Rectangle_Height*memory[0].finish_address)/2));
    draw_scene->addItem(text_inside_memory);

    for (int i = 1; i < memory.size(); i++) {
        rectangle=draw_scene->addRect(QRectF(-200, 0 + Rectangle_Height*memory[i - 1].finish_address,Rectangle_Width,Rectangle_Height*memory[i].size),blackpen, color_brush);
        QString start = QString::number(memory[i].finish_address);
        QGraphicsTextItem *txtitem = new QGraphicsTextItem(start);
        txtitem->setPos(QPointF(-240, -13+Rectangle_Height*memory[i].finish_address));
        draw_scene->addItem(txtitem);

        //to write inside memory;
        QGraphicsTextItem *text_inside_memory;
        if (memory[i].type == 0) {
            text_inside_memory = new QGraphicsTextItem("P" +QString::number(memory[i].id) + ":" + memory[i].name);
        }
        else {
            text_inside_memory = new QGraphicsTextItem(memory[i].name+QString::number(memory[i].id));
        }
        text_inside_memory->setPos(QPointF(-240 + Rectangle_Width/2, -13+Rectangle_Height*(memory[i].finish_address-memory[i].size/2)));
        draw_scene->addItem(text_inside_memory);
    }

}

void MainWindow::submit_holes_button_clicked() {

    QString memory_size = lineEdit_for_memory_size ->text();
    if(memory_size.toInt()<=0){

        QMessageBox::warning(this, "Wrong Input", "Please enter positive number");
        return;
    }
    holes_total_size =0;
    Segment h;
    for(int i=0;i<holes_table->rowCount();i++){
        QString starting_address = holes_table->item(i, 0)->text();
        QString size = holes_table->item(i, 1)->text();
        holes_total_size+= size.toInt();
        if(size.toInt()<=0 || starting_address.toInt() <0){

            QMessageBox::warning(this, "Wrong Input", "Please enter positive number");
            while(!holes.empty()) {
               holes.pop_back();
            }
            return;
        }
        if(holes_total_size > memory_size.toInt() ){

             QMessageBox::warning(this, "Wrong Input", "holes size exceeds the memory size");
             while(!holes.empty()) {
                 holes.pop_back();
             }
             return;
        }

        h.starting_address = starting_address.toInt();
        h.size = size.toInt();
        h.finish_address = h.starting_address + h.size;
        h.name = "Hole";
        h.type =1;
        h.id =i;
        holes.push_back(h);


    }

    submit_holes->hide();
    add_holes_button->hide();
    remove_hole_button->hide();
    manage_holes(holes);
    fill_memory(memory, holes, memory_size.toInt());
    draw_memory(memory);

}

void MainWindow::add_hole_button_clicked() {
    //add_holes_button->setText("Add new hole");
    new_row++;
    holes_table->insertRow(new_row);
    if (holes_table->rowCount() > 0) {
        remove_hole_button->show();
    }
}

void MainWindow::remove_hole_button_clicked() {
    holes_table->removeRow(holes_table->rowCount() - 1);
    new_row--;
    if (holes_table->rowCount() == 0){
        remove_hole_button->hide();
    }
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
    int p_size=0;
    for(int i=0;i<process_table->rowCount();i++){
        QString name = process_table->item(i, 0)->text();
        QString size = process_table->item(i, 1)->text();
        if(size.toInt()<=0){
            QMessageBox::warning(this, "Wrong Input", "Please enter positive number");
            while(!process.empty()) {
                process.pop_back();
            }
            return;
        }
        p.size = size.toInt();
        p_size += size.toInt();
        p.name = name;
        p.type =0;
        p.id =process_no;
        process.push_back(p);
    }
    if(p_size > holes_total_size){
        QMessageBox::warning(this, "Wrong Input", " this process does not fit");
        while(!process.empty()) {
            process.pop_back();
        }
        return;
    }

    else {
        if(first_fit->isChecked())
        {   process_no++;
            first_fit_algorithm(memory,process,holes);
            manage_holes_id(memory,holes);
            draw_scene->clear();
            view->items().clear();
            draw_memory(memory);
        }
        else if (best_fit->isChecked())
        {  process_no++;
           memory = best_fit_algorithm(holes,memory,process);
           manage_holes_id(memory,holes);
           draw_scene->clear();
           view->items().clear();
           draw_memory(memory);
        }
        else if (worst_fit->isChecked())
        {   process_no++;
            worst_fit_algorithm(process,holes,memory);
            manage_holes_id(memory,holes);
            draw_scene->clear();
            view->items().clear();
            draw_memory(memory);
        }
        else if (shuffle->isChecked())
        {   process_no++;
            memory = shuffle_algorithm(memory,process);
            manage_holes_id(memory,holes);
            draw_scene->clear();
            view->items().clear();
            draw_memory(memory);
        }
        else
            QMessageBox::warning(this, "Wrong Input", " Please choose a method.");
    }
    while(!process.empty()) {
        process.pop_back();
    }
}

void MainWindow::manage_holes_id(vector<Segment> &memory, vector<Segment> &holes) {
    int hole_id = 0;
    for (int i = 0; i < memory.size() - 1; i++){
        if (memory[i].type == 1 && memory[i + 1].type == 1) {
           memory[i].finish_address = memory[i+1].finish_address;
           memory[i].size = memory[i].finish_address - memory[i].starting_address;
           memory.erase(memory.begin() + i + 1);
           i--;
        }
    }
    holes_total_size = 0;
    while(!holes.empty()) {
       holes.pop_back();
    }
    for (int i = 0; i < memory.size(); i++) {
        if (memory[i].type == 1) {
            memory[i].id = hole_id;
            hole_id++;
            holes_total_size += memory[i].size;
            holes.push_back(memory[i]);
        }
    }
}

void deAllocate(vector <Segment>& holes, vector <Segment>& memory, int type, int id)
{
    for (int i = 0; i < memory.size(); i++)
    {
        if (memory[i].type == type && memory[i].id == id)
        {
            memory[i].name = "Hole";
            memory[i].type = 1;
            memory[i].id = holes.size();
            holes.push_back(memory[i]);
        }
    }
}

void MainWindow::dellocate_process_button_clicked() {
    QString deallocate_process = lineEdit_for_process_number ->text();
    int id = deallocate_process.toInt();
    if(deallocate_process.toInt()<0) {
        QMessageBox::warning(this, "Wrong Input", "Please enter positive number");
    }
    int type;
    if (old_process->isChecked()) {
        type = 2;
        deAllocate(holes, memory, type, id);
        manage_holes_id(memory,holes);
        draw_scene->clear();
        view->items().clear();
        draw_memory(memory);
    }
    else if (new_process->isChecked()) {
        type = 0;
        deAllocate(holes, memory, type, id);
        manage_holes_id(memory,holes);
        draw_scene->clear();
        view->items().clear();
        draw_memory(memory);
    }
    else
         QMessageBox::warning(this, "Wrong Input", "Please choose type of process");
}

void MainWindow::manage_holes(vector<Segment>& holes) {
    for (int i = 0; i < holes.size(); i++) {
        holes[i].id = i;
        for (int j = i + 1; j < holes.size(); j++) {
            if (holes[j].starting_address < holes[i].starting_address && holes[j].size >= holes[i].starting_address) {
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
            }
            else if (holes[j].starting_address == holes[i].finish_address) {
                holes[i].finish_address = holes[j].finish_address;
                holes[i].size = holes[i].finish_address - holes[i].starting_address;
                holes.erase(holes.begin() + j);
                j--;
            }
            else if (holes[j].starting_address <= holes[i].finish_address) {
                if (holes[j].finish_address > holes[i].finish_address)
                    holes[i].finish_address = holes[j].finish_address;
                holes.erase(holes.begin() + j);
                j--;
            }
        }
    }
}

void MainWindow::fill_memory(vector<Segment>& memory, vector<Segment> holes, int finishOfMemory) {
    Segment min_hole;
    bool flag = true;
    int index;
    int old_process_index = 0;
    while (!holes.empty()) {
        min_hole.starting_address = 10000000;
        for (int i = 0; i < holes.size(); i++) {
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
            first.type = 2;
            first.name = "Old Process";
            first.id = old_process_index;
            old_process_index++;
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
            hole.type = 2;
            hole.name = "Old Process";
            hole.id = old_process_index;
            old_process_index++;
            memory.push_back(hole);
            memory.push_back(min_hole);
        }
        else if (min_hole.starting_address == 0) {
            memory.push_back(min_hole);
            flag = false;
        }
        holes.erase(holes.begin() + index);
    }
    Segment last = memory.back();
    if (last.finish_address != finishOfMemory) {
        last.starting_address = last.finish_address;
        last.finish_address = finishOfMemory;
        last.size = last.finish_address - last.starting_address;
        last.type = 2;
        last.name = "Old process";
        last.id = old_process_index;
        old_process_index++;
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
                //int idx = 0;
                for (int i = 0; i < holes.size(); i++) {
                    for (int j=0; j < temp_memory.size(); j++) {
                    if (holes[i].id == temp_memory[j].id && temp_memory[i].type == 1) {
                        temp_memory[j].id = i;
                    }
                    }
                }

                temp_memory.erase(temp_memory.begin() + j);
                temp_memory.insert(temp_memory.begin() + j, process[i]);
                process[i].is_fit_in_memory = true;
                break;
            }
        }
    }
    for (int i = 0; i < process.size(); i++) {
        if (!process[i].is_fit_in_memory) {
            QMessageBox::warning(this, "Wrong Input", " this process does not fit");
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

vector<Segment> total_memory(vector <Segment>const &holes_after_allocation, vector <Segment>const &old_memory, vector <Segment>const &allocated)
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
vector<Segment> MainWindow::best_fit_algorithm(vector <Segment> &holes, vector <Segment> &old_memory, vector <Segment> &process ){
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
            allocated.push_back(Segment{top_y.id ,top_y.name ,top_x.starting_address ,top_x.starting_address+top_y.size,top_y.size ,top_y.type});
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

vector<Segment> sort_hole(vector<Segment> holes) {

     for (int i = 0; i < holes.size(); i++) {

         for (int j = i + 1; j < holes.size(); j++) {
             if (holes[i].size < holes[j].size) {
                 swap(holes[i], holes[j]);
             }
         }
     }
     return holes;
 }
void index_hole(vector<Segment>& holes, vector<Segment> all) {
    for (int i = 0; i < all.size(); i++) {

        if (all[i].type == 1) {
            for (int j = 0; j < holes.size(); j++) {
                if (holes[j].id == all[i].id) {
                    holes[j].index = i;
                    break;
                }
            }
        }
    }
}
void MainWindow::worst_fit_algorithm (vector<Segment> procces,vector<Segment> &holes, vector<Segment> &all){
         vector<Segment> all_trial;
         all_trial = all;
         holes = sort_hole( holes);
         index_hole(holes,all);
         for (int i = 0; i < procces.size(); i++) {
             if (procces[i].size < holes.front().size)
             {
                 procces[i].starting_address = holes.front().starting_address;
                 procces[i].finish_address = procces[i].starting_address + procces[i].size;
                 holes.front().size -= procces[i].size;
                 holes.front().starting_address = procces[i].finish_address;
                 holes.front().finish_address = holes.front().starting_address + holes.front().size;
                 all.erase(all.begin() + holes.front().index);
                 all.insert(all.begin() + holes.front().index, holes.front());
                 all.insert(all.begin() + holes.front().index, procces[i]);
                 holes = sort_hole(holes);
                 index_hole(holes, all);
             }
             else if (procces[i].size == holes.front().size) {
                 procces[i].starting_address = holes.front().starting_address;
                 procces[i].finish_address = procces[i].starting_address + procces[i].size;
                 all.erase(all.begin() + holes.front().index);
                 all.insert(all.begin() + holes.front().index, procces[i]);
                 holes.erase(holes.begin());

             }
             else {

                 all=all_trial;
                 QMessageBox::warning(this, "Wrong Input", " this process does not fit");
                 break;
             }
         }
     }

vector<Segment> MainWindow::shuffle_algorithm(vector<Segment> &memory, vector<Segment> &process){
    double holes_total_size = 0, process_total_size = 0;
    double start_old = memory[0].starting_address;
        vector<Segment> total_memory;
        Segment h, p, pro, temp_pro, arr_h, t;

        for (int i = 0; i < memory.size(); i++)
        {
            for (int j = i + 1; j < memory.size(); j++) {
                if (memory[i].starting_address > memory[j].starting_address) {
                    swap(memory[i], memory[j]);
                }
            }
        }

        for(int i=0 ; i<process.size(); i++)
        {
                process_total_size += process[i].size;
        }

        for(int i=0; i<memory.size(); i++)
        {
            if(memory[i].type == 2)
            {
                t.starting_address = start_old;
                t.size = memory[i].size;
                t.finish_address = t.starting_address + t.size;
                t.type = memory[i].type;
                t.name = memory[i].name;
                t.id = memory[i].id;
                total_memory.push_back(t);
                start_old = t.finish_address;
            }
        }
        double start_new = start_old, pro_id = 0, flag = 0;
        for(int i=0; i<memory.size(); i++)
        {
            if(memory[i].type == 0)
            {
                flag = 1;
                t.starting_address = start_new;
                t.size = memory[i].size;
                t.finish_address = t.starting_address + t.size;
                t.type = memory[i].type;
                t.name = memory[i].name;
                t.id = memory[i].id;
                total_memory.push_back(t);
                start_new = t.finish_address;
                pro_id = t.id;
            }
        }
        if(flag == 1)
        {
            pro_id++;
        }

        for(int i=0; i<memory.size(); i++)
        {
            if(memory[i].type == 1)
            {
                holes_total_size += memory[i].size;
            }
        }
        t.starting_address = start_new;
        t.size = holes_total_size;
        t.finish_address = t.starting_address + t.size;
        t.type = 1;
        t.name = "Hole";
        t.id = 0;
        total_memory.push_back(t);

        double total_mem_size =t.finish_address;

        // allocating new processes
        double start = start_new;
        if(process_total_size < holes_total_size)
        {
            total_memory.pop_back();
            for(int i=0 ; i<process.size(); i++)
            {
                temp_pro.name = process[i].name;
                temp_pro.size = process[i].size;
                temp_pro.starting_address = start;
                temp_pro.finish_address = temp_pro.starting_address + temp_pro.size;
                temp_pro.id = pro_id;
                temp_pro.type = 0;
                total_memory.push_back(temp_pro);
                start = start + temp_pro.size;
            }
            holes_total_size = total_mem_size - start;
            if(holes_total_size > 0)
            {
                    h.name = "Hole";
                    h.size = holes_total_size;
                    h.starting_address = total_mem_size - holes_total_size;
                    h.finish_address = total_mem_size;
                    h.id = 0;
                    h.type = 1;
                    total_memory.push_back(h);
            }
            pro_id++;
        }
        else if(process_total_size == holes_total_size)
        {
            total_memory.pop_back();
            for(int i=0 ; i<process.size(); i++)
            {
                temp_pro.name = process[i].name;
                temp_pro.size = process[i].size;
                temp_pro.starting_address = start;
                temp_pro.finish_address = temp_pro.starting_address + temp_pro.size;
                temp_pro.id = pro_id;
                temp_pro.type = 0;
                total_memory.push_back(temp_pro);
                start = start + temp_pro.size;
            }
            holes_total_size = total_mem_size - start;
            pro_id++;
        }
        else if(process_total_size > holes_total_size)
        {
           QMessageBox::warning(this, "Wrong Input", " this process does not fit");
        }
        memory = total_memory;
        return total_memory;
}
