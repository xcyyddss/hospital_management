#ifndef CHECKINPUT_H
#define CHECKINPUT_H

#include<QString>
#include<QLinkedList>
#include<database.h>

bool check_in(QString str,QLinkedList<QString> str_list);
bool check_id(QString id, QString table_name ,QString status);

#endif // CHECKINPUT_H
