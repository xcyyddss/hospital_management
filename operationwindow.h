#ifndef OPERATIONWINDOW_H
#define OPERATIONWINDOW_H

#include <QWidget>
#include <QString>
#include<QPushButton>
#include<QString>
#include<QLinkedList>
#include <QTextEdit>
#include<QLineEdit>
#include <QScrollBar>
#include <QSignalMapper>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include<QDebug>



class OperationWindow : public QWidget
{
    Q_OBJECT
private:
    int button_num;
public:
    int line_num;
    QPushButton** button;
    QSignalMapper* button_mapper;
    QTextEdit* text;
    QLineEdit** line;
    QVBoxLayout* this_box;
    explicit OperationWindow(QWidget *parent = nullptr){}
    explicit OperationWindow(QWidget *parent = nullptr, QString type = "", QLinkedList<QString> list
                             = QLinkedList<QString>());
    explicit OperationWindow(QWidget *parent = nullptr, QString type = "", QLinkedList<QLinkedList<QString>>
                             list = QLinkedList<QLinkedList<QString>>());
    ~OperationWindow();

signals:
    void button_signal(int index);
public slots:
    void button_receve(int index){
        emit button_signal(index);
    }
    void add_line();
};

#endif // OPERATIONWINDOW_H
