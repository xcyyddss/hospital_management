#include "person.h"

Person::Person(QLinkedList<QString> details)
{
    if(details.size()>=7){
        ID = details.takeFirst();
        name = details.takeFirst();
        phoneNumber = details.takeFirst();
        address = details.takeFirst();
        identity = details.takeFirst();
        key = details.takeFirst();
        status = details.takeFirst();
    }
    else{
        qDebug()<<"Error: Insufficient elements in the list.";
    }
}

QLinkedList<QString> Person::get_details(){
    QLinkedList<QString> list;
    list<<ID<<name<<phoneNumber<<address<<identity<<key<<status;
    return list;
}
