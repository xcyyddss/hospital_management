#include "operationwindow.h"
#include<QThread>

OperationWindow::~OperationWindow(){
    for(int i{};i<button_num;i++){
        delete button[i];
    }
    for(int i{};i<line_num;i++){
        delete line[i];
    }
    delete button_mapper;
    delete text;
}

OperationWindow::OperationWindow(QWidget *parent, QString type, QLinkedList<QString> list) : QWidget(parent){
    button_num = 0;
    line_num = 0;
    button = nullptr;
    button_mapper = nullptr;
    text = nullptr;
    line = nullptr;
    QVBoxLayout *box = new QVBoxLayout(this);
    if(type == "press"){
        button_mapper = new QSignalMapper(this);
        button_num = list.size();
        button = new QPushButton* [button_num];
        for(int i{};i<button_num;i++){
            button[i] = new QPushButton(list.takeFirst(),this);
            QHBoxLayout *horizontalLayout = new QHBoxLayout;
            horizontalLayout->addWidget(button[i]);
            horizontalLayout->setAlignment(Qt::AlignHCenter);
            box->addLayout(horizontalLayout);
            button[i]->setMinimumHeight(70);
            button[i]->setFixedWidth(200);
            connect(button[i],SIGNAL(clicked()),button_mapper,SLOT(map()));
            button_mapper->setMapping(button[i],i);
        }
        connect(button_mapper, SIGNAL(mapped(int)), this, SLOT(button_receve(int)));
    }
    if(type == "show_and_press"){
        line_num = list.takeFirst().toInt();
        line = new QLineEdit* [line_num];
        for(int i{};i<line_num;i++){
            line[i] = new QLineEdit(this);
            line[i]->setMinimumHeight(40);
            line[i]->setReadOnly(true);
            line[i]->setText(list.takeFirst());
            box->addWidget(line[i]);
        }
        button_mapper = new QSignalMapper(this);
        button_num = list.size();
        button = new QPushButton* [button_num];
        for(int i{};i<button_num;i++){
            button[i] = new QPushButton(list.takeFirst(),this);
            QHBoxLayout *horizontalLayout = new QHBoxLayout;
            horizontalLayout->addWidget(button[i]);
            horizontalLayout->setAlignment(Qt::AlignHCenter);
            box->addLayout(horizontalLayout);
            button[i]->setMinimumHeight(70);
            button[i]->setFixedWidth(200);
            connect(button[i],SIGNAL(clicked()),button_mapper,SLOT(map()));
            button_mapper->setMapping(button[i],i);
        }
        connect(button_mapper, SIGNAL(mapped(int)), this, SLOT(button_receve(int)));
    }
    if(type == "write_and_press"){
        line_num = list.takeFirst().toInt();
        line = new QLineEdit* [line_num];
        for(int i{};i<line_num;i++){
            line[i] = new QLineEdit(this);
            line[i]->setMinimumHeight(40);
            box->addWidget(line[i]);
        }
        button_mapper = new QSignalMapper(this);
        button_num = list.size();
        button = new QPushButton* [button_num];
        for(int i{};i<button_num;i++){
            button[i] = new QPushButton(list.takeFirst(),this);
            QHBoxLayout *horizontalLayout = new QHBoxLayout;
            horizontalLayout->addWidget(button[i]);
            horizontalLayout->setAlignment(Qt::AlignHCenter);
            box->addLayout(horizontalLayout);
            button[i]->setMinimumHeight(70);
            button[i]->setFixedWidth(200);
            connect(button[i],SIGNAL(clicked()),button_mapper,SLOT(map()));
            button_mapper->setMapping(button[i],i);
        }
        connect(button_mapper, SIGNAL(mapped(int)), this, SLOT(button_receve(int)));
    }
    this->setLayout(box);
}

void OperationWindow::add_line(){
    line[line_num] = new QLineEdit(line[line_num-1]->text(),this);
    line[line_num]->setMinimumHeight(40);
    this_box->insertWidget(line_num,line[line_num]);
    line_num++;
}

OperationWindow::OperationWindow(QWidget *parent, QString type, QLinkedList<QLinkedList<QString>> list) : QWidget(parent){
    button_num = 0;
    line_num = 0;
    button = nullptr;
    button_mapper = nullptr;
    text = nullptr;
    line = nullptr;
    QVBoxLayout *box = new QVBoxLayout(this);
    if(type == "multiple_write_and_press"){
        this_box = box;
        QLinkedList<QString> write_list = list.takeFirst();
        line_num = write_list.takeFirst().toInt();
        line = new QLineEdit* [15];
        for(int i{};i<line_num;i++){
            if(write_list.size()>0){
                line[i] = new QLineEdit(write_list.takeFirst(),this);
                line[i]->setMinimumHeight(40);
                box->addWidget(line[i]);
            }
            else{
                line[i] = new QLineEdit(this);
                line[i]->setMinimumHeight(40);
                box->addWidget(line[i]);
            }
        }
        QLinkedList<QString> press_list = list.takeFirst();
        button_mapper = new QSignalMapper(this);
        button_num = press_list.size();
        button = new QPushButton* [button_num];
        for(int i{};i<button_num;i++){
            button[i] = new QPushButton(press_list.takeFirst(),this);
            QHBoxLayout *horizontalLayout = new QHBoxLayout;
            horizontalLayout->addWidget(button[i]);
            horizontalLayout->setAlignment(Qt::AlignHCenter);
            box->addLayout(horizontalLayout);
            button[i]->setMinimumHeight(70);
            button[i]->setFixedWidth(200);
            connect(button[i],SIGNAL(clicked()),button_mapper,SLOT(map()));
            button_mapper->setMapping(button[i],i);
        }
        connect(button_mapper, SIGNAL(mapped(int)), this, SLOT(button_receve(int)));
        connect(button[0],SIGNAL(clicked()),this,SLOT(add_line()));
    }
    if(type == "write_and_press"){
        QLinkedList<QString> write_list = list.takeFirst();
        line_num = write_list.takeFirst().toInt();
        line = new QLineEdit* [line_num];
        for(int i{};i<line_num;i++){
            if(write_list.size()>0){
                line[i] = new QLineEdit(write_list.takeFirst(),this);
                line[i]->setMinimumHeight(40);
                box->addWidget(line[i]);
            }
            else{
                line[i] = new QLineEdit(this);
                line[i]->setMinimumHeight(40);
                box->addWidget(line[i]);
            }
        }
        QLinkedList<QString> press_list = list.takeFirst();
        button_mapper = new QSignalMapper(this);
        button_num = press_list.size();
        button = new QPushButton* [button_num];
        for(int i{};i<button_num;i++){
            button[i] = new QPushButton(press_list.takeFirst(),this);
            QHBoxLayout *horizontalLayout = new QHBoxLayout;
            horizontalLayout->addWidget(button[i]);
            horizontalLayout->setAlignment(Qt::AlignHCenter);
            box->addLayout(horizontalLayout);
            button[i]->setMinimumHeight(70);
            button[i]->setFixedWidth(200);
            connect(button[i],SIGNAL(clicked()),button_mapper,SLOT(map()));
            button_mapper->setMapping(button[i],i);
        }
        connect(button_mapper, SIGNAL(mapped(int)), this, SLOT(button_receve(int)));
    }
    if(type == "write_and_show_and_press"){
        QLinkedList<QString> write_list = list.takeFirst();
        line_num = write_list.takeFirst().toInt();
        line = new QLineEdit* [line_num];
        for(int i{};i<line_num;i++){
            if(write_list.size()>0){
                line[i] = new QLineEdit(write_list.takeFirst(),this);
                line[i]->setMinimumHeight(40);
                box->addWidget(line[i]);
            }
            else{
                line[i] = new QLineEdit(this);
                line[i]->setMinimumHeight(40);
                box->addWidget(line[i]);
            }
        }
        QLinkedList<QString> press_list = list.takeLast();
        button_mapper = new QSignalMapper(this);
        button_num = press_list.size();
        button = new QPushButton* [button_num];
        for(int i{};i<button_num;i++){
            button[i] = new QPushButton(press_list.takeFirst(),this);
            QHBoxLayout *horizontalLayout = new QHBoxLayout;
            horizontalLayout->addWidget(button[i]);
            horizontalLayout->setAlignment(Qt::AlignHCenter);
            box->addLayout(horizontalLayout);
            button[i]->setMinimumHeight(70);
            button[i]->setFixedWidth(200);
            connect(button[i],SIGNAL(clicked()),button_mapper,SLOT(map()));
            button_mapper->setMapping(button[i],i);
        }
        connect(button_mapper, SIGNAL(mapped(int)), this, SLOT(button_receve(int)));
        QString text_str = "";
        while(list.size()>0){
            QLinkedList<QString> text_list = list.takeFirst();
            QString type_str = text_list.takeFirst();
            if(type_str == "Person" || type_str == "Schedule" || type_str == "Appointment"){
                for(QString &str:text_list){
                    text_str += (str + " ");
                }
                text_str += "\n";
            }
            if(type_str == "Diagnosis"){
                text_str += (text_list.takeFirst() + " ");
                text_str += (text_list.takeFirst() + " ");
                text_str += (text_list.takeFirst() + " ");
                text_str += (text_list.takeFirst() + "\n");
                for(QString &str:text_list){
                    text_str += ("  "+str + "\n");
                }
            }
            if(type_str == "Prescription"){
                while(text_list.size()>0){
                    text_str += (text_list.takeFirst() + " ");
                    text_str += (text_list.takeFirst() + " ");
                    text_str += (text_list.takeFirst() + " ");
                    text_str += (text_list.takeFirst() + "\n");
                }
            }
        }
        text = new QTextEdit(this);
        text->setReadOnly(true);
        text->setPlainText(text_str);
        box->addWidget(text);
        QScrollBar *scrollBar = new QScrollBar(Qt::Vertical, text);
        text->setVerticalScrollBar(scrollBar);
    }
    this->setLayout(box);
}
