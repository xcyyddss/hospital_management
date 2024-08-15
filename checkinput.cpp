#include "checkinput.h"

bool check_in(QString str,QLinkedList<QString> str_list){
    while(str_list.size()>0){
        QString tmp = str_list.takeFirst();
        if(str == tmp)return true;
    }
    return false;
}

bool check_id(QString id, QString table_name ,QString status){
    QString condition = "ID = '"+id+"'";
    if(status!="")condition = condition + "AND "+status;
    QLinkedList<QLinkedList<QString>> _list = read_data(table_name,condition);
    if(_list.empty())return false;
    return true;
}
