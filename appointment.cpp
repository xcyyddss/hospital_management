#include "appointment.h"

Appointment::Appointment(QLinkedList<QString> details){
    if(details.size()>=5){
        ID = details.takeFirst();
        time = details.takeFirst();
        patientId = details.takeFirst();
        doctorId = details.takeFirst();
        QString tmp = details.takeFirst();
        if(tmp == "finished"){
            finished = true;
        }
        else{
            finished = false;
        }
    }
    else{
        qDebug()<<"Error: Insufficient elements in the list.";
    }
}

QLinkedList<QString> Appointment::get_details()
{
    QLinkedList<QString> list;
    list<<ID<<time<<patientId<<doctorId;
    if(finished){
        list<<QString("finished");
    }
    else{
        list<<QString("not_finished");
    }
    return list;
}
