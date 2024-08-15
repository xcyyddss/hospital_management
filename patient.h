#ifndef PATIENT_H
#define PATIENT_H
#include<person.h>

class Patient: protected Person
{
private:
    int diagnosis_num;
    int prescription_num;
    int appointment_num;
    int doctor_num;
    Diagnosis** diagnosis;
    Appointment** appointment;
    Person** doctor;
    Prescription** prescription;
public:
    ~Patient();
    Patient(){}
    Patient(QString _ID, QString _name, QString _phoneNumber,QString _address,QString _id,QString _key,QString _status):Person(_ID, _name, _phoneNumber, _address, _id, _key, _status)
      ,diagnosis(nullptr),appointment(nullptr),doctor(nullptr),prescription(nullptr){}
    Patient(QLinkedList<QString> details):Person(details),diagnosis(nullptr),appointment(nullptr),doctor(nullptr),prescription(nullptr){}
    void make_appointment(QString date, QString doctorId);
    void check_diagnosis();
    void check_prescription();
    void check_appointment();
    void check_doctor();
    QLinkedList<QLinkedList<QString>> get_diagnosis(QString date = "");
    QLinkedList<QLinkedList<QString>> get_prescription(QString date = "");
    QLinkedList<QLinkedList<QString>> get_appointment(QString date = "");
    QLinkedList<QLinkedList<QString>> get_doctor(QString word = "");
};

#endif // PATIENT_H
