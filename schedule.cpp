#include "schedule.h"

Schedule::Schedule(QLinkedList<QString> details)
{
    if(details.size()>=8){
        personId = details.takeFirst();
        Monday = details.takeFirst();
        Tuesday = details.takeFirst();
        Wednesday = details.takeFirst();
        Thursday = details.takeFirst();
        Friday = details.takeFirst();
        Saturday = details.takeFirst();
        Sunday = details.takeFirst();
    }
    else{
        qDebug()<<"Error: Insufficient elements in the list.";
    }
}

QLinkedList<QString> Schedule::get_details()
{
    QLinkedList<QString> list;
    list<<personId<<Monday<<Tuesday<<Wednesday<<Thursday<<Friday<<Saturday<<Sunday;
    return list;
}
