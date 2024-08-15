#ifndef DATABASE_H
#define DATABASE_H
#include<appointment.h>
#include<diagnosis.h>
#include<person.h>
#include<prescription.h>
#include<schedule.h>
#include <QtSql>
#include <QStringList>

void database_init();
void init_manager();
void insert_data(QString table_name,QLinkedList<QString> data);
QLinkedList<QLinkedList<QString>> read_data(QString table_name,QString condition = "");
void update_data(QString table_name,QString update_content,QString conditon);
void delete_data(QString table_name,QString ID);

#endif // DATABASE_H
