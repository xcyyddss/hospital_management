#include "prescription.h"

Prescription::Prescription(QString _ID,QString _date,QString _patientId,QString _doctorId,QLinkedList<QString> _content)
{
    ID = _ID;
    date = _date;
    patientId = _patientId;
    doctorId = _doctorId;
    for(const QString &str: _content){
        content<<str;
    }
}

Prescription::Prescription(QLinkedList<QString> details){
    if(details.size()>=4){
        ID = details.takeFirst();
        date = details.takeFirst();
        patientId = details.takeFirst();
        doctorId = details.takeFirst();
    }
    else{
        qDebug()<<"Error: Insufficient elements in the list.";
    }
    for(const QString &str : details){
        content<<str;
    }
}

QLinkedList<QString> Prescription::get_details(){
    QLinkedList<QString> list;
    list<<ID<<date<<patientId<<doctorId;
    for(const QString &str: content){
        list<<str;
    }
    return list;
}
