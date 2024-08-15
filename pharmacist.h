#ifndef PHARMACIST_H
#define PHARMACIST_H


#include<person.h>

class Pharmacist: protected Person
{
private:
    Schedule* schedule;
    int prescription_num;
    Prescription** prescription;
public:
    ~Pharmacist();
    Pharmacist(){}
    Pharmacist(QString _ID, QString _name, QString _phoneNumber,QString _address,QString _id,QString _key,QString _status):Person(_ID,_name, _phoneNumber,_address,_id,_key,_status),prescription(nullptr),schedule(nullptr){}
    Pharmacist(QLinkedList<QString> details):Person(details),prescription(nullptr),schedule(nullptr){}
    void check_schedule();
    void check_prescription(QString date = "");
    QLinkedList<QString> get_schedule();
    QLinkedList<QLinkedList<QString>> get_prescription();
};

#endif // PHARMACIST_H
