#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include<QString>
#include<QLinkedList>
#include<QDebug>

class Appointment
{
private:
    QString ID;
    QString time;
    QString patientId;
    QString doctorId;
    bool finished;
public:
    Appointment(){}
    Appointment(QString _ID,QString _time,QString _patientId,QString _doctorId,bool _finished):ID(_ID),time(_time),patientId(_patientId),doctorId(_doctorId),finished(_finished){}
    Appointment(QLinkedList<QString>);
    QLinkedList<QString> get_details();
    QString get_ID(){return ID;}
    QString get_time(){return time;}
};

#endif // APPOINTMENT_H
