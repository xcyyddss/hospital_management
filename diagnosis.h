#ifndef DIAGNOSIS_H
#define DIAGNOSIS_H

#include<QString>
#include<QLinkedList>
#include<QDebug>

class Diagnosis
{
private:
    QString ID;
    QString date;
    QString patientId;
    QString doctorId;
    QLinkedList<QString> content;
public:
    Diagnosis(){}
    Diagnosis(QString _ID,QString _date,QString _patientId,QString _doctorId,QLinkedList<QString> _content);
    Diagnosis(QLinkedList<QString>);
    QLinkedList<QString> get_details();
    QString get_ID(){return ID;}
    QString get_date(){return date;}
};

#endif // DIAGNOSIS_H
