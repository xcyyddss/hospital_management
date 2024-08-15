#ifndef DOCTOR_H
#define DOCTOR_H

#include<person.h>

class Doctor: protected Person
{
private:
    Schedule* schedule;
    int appointment_num;
    int diagnosis_num;
    int prescription_num;
    Appointment** appointment;
    Diagnosis** diagnosis;
    Prescription** prescription;
public:
    ~Doctor();
    Doctor(){}
    Doctor(QString _ID, QString _name, QString _phoneNumber,QString _address,QString _id,QString _key,QString _status):Person(_ID,_name, _phoneNumber,_address,_id,_key,_status),appointment(nullptr),diagnosis(nullptr),prescription(nullptr){}
    Doctor(QLinkedList<QString> details):Person(details),appointment(nullptr),diagnosis(nullptr),prescription(nullptr){}
    QString get_id(){return this->get_ID();}
    void check_schedule();
    void check_appointment();
    void check_diagnosis(QString patientId);
    void check_prescription();
    QLinkedList<QString> get_schedule();
    QLinkedList<QLinkedList<QString>> get_appointment(QString date = "");
    QLinkedList<QLinkedList<QString>> get_diagnosis(QString date = "");
    QLinkedList<QLinkedList<QString>> get_prescription(QString date = "");
    void make_diagnosis(QString date,QString patientId,QLinkedList<QString> content);
    void make_prescription(QString date,QString patientId,QLinkedList<QString> content);
    void hospitalize(QString patientId);
    void discharge(QString patientId);
    void finish_appointment(QString ID);
};

#endif // DOCTOR_H
