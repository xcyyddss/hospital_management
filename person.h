#ifndef PERSON_H
#define PERSON_H
#include<QString>
#include<QLinkedList>
#include<QDebug>
#include<database.h>
class Person
{
private:
    QString ID;
    QString name;
    QString phoneNumber;
    QString address;
    QString identity;
    QString key;
    QString status;
public:
    Person(){}
    Person(QString _ID, QString _name, QString _phoneNumber,QString _address,QString _identity,QString _key,QString _status):ID(_ID),name(_name),phoneNumber(_phoneNumber),address(_address),identity(_identity),key(_key),status(_status){}
    Person(QLinkedList<QString>);
    QLinkedList<QString> get_details();
    QString get_ID(){return ID;}
    QString get_status(){return status;}
};

#endif // PERSON_H
