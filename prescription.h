#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include<QString>
#include<QLinkedList>
#include<QDebug>


class Prescription
{
private:
    QString ID;
    QString date;
    QString patientId;
    QString doctorId;
    QLinkedList<QString> content;
public:
    Prescription(){}
    Prescription(QString _ID,QString _date,QString _patientId,QString _doctorId,QLinkedList<QString> _content);
    Prescription(QLinkedList<QString>);
    QLinkedList<QString> get_details();
    QString get_ID(){return ID;}
    QString get_date(){return date;}
};

#endif // PRESCRIPTION_H
