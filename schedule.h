#ifndef SCHEDULE_H
#define SCHEDULE_H

#include<QString>
#include<QLinkedList>
#include<QDebug>

class Schedule
{
private:
    QString personId;
    QString Monday;
    QString Tuesday;
    QString Wednesday;
    QString Thursday;
    QString Friday;
    QString Saturday;
    QString Sunday;
public:
    Schedule(){}
    Schedule(QString _personId,QString _Monday,QString _Tuesday,QString _Wednesday,QString _Thursday,QString _Friday,QString _Saturday,QString _Sunday):personId(_personId),Monday(_Monday),Tuesday(_Tuesday),Wednesday(_Wednesday),Thursday(_Thursday),Friday(_Friday),Saturday(_Saturday),Sunday(_Sunday){}
    Schedule(QLinkedList<QString>);
    QLinkedList<QString> get_details();
};

#endif // SCHEDULE_H
