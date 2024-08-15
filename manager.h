#ifndef MANAGER_H
#define MANAGER_H

#include<person.h>

class Manager: protected Person
{
private:
    int appointment_num;
    int diagnosis_num;
    int person_num;
    int prescription_num;
    int schedule_num;
    Appointment** appointment;
    Diagnosis** diagnosis;
    Person** person;
    Prescription** prescription;
    Schedule** schedule;
public:
    ~Manager();
    Manager(){}
    Manager(QString _ID, QString _name, QString _phoneNumber,QString _address,QString _id,QString _key,QString _status):Person(_ID,_name, _phoneNumber,_address,_id,_key,_status)
      ,appointment(nullptr),diagnosis(nullptr),person(nullptr),prescription(nullptr),schedule(nullptr){}
    Manager(QLinkedList<QString> details):Person(details),appointment(nullptr),diagnosis(nullptr),person(nullptr),prescription(nullptr),schedule(nullptr){}
    void register_person(QLinkedList<QString> details);
    void delete_person(QString ID);
    void update_person_name(QString ID,QString name);
    void update_person_phoneNumber(QString ID,QString phoneNumber);
    void update_person_address(QString ID,QString address);
    void update_person_identity(QString ID,QString identity);
    void update_person_key(QString ID,QString key);
    void update_person_status(QString ID,QString status);
    void update_schedule(QLinkedList<QString> details);
    void check_appointment(QString id_limit = "99999999");
    void check_diagnosis(QString id_limit = "99999999");
    void check_person(QString id_limit = "99999999");
    void check_prescription(QString id_limit = "99999999");
    void check_schedule(QString id_limit = "99999999");
    QLinkedList<QLinkedList<QString>> get_appointment();
    QLinkedList<QLinkedList<QString>> get_diagnosis();
    QLinkedList<QLinkedList<QString>> get_person();
    QLinkedList<QLinkedList<QString>> get_prescription();
    QLinkedList<QLinkedList<QString>> get_schedule();
};

#endif // MANAGER_H
