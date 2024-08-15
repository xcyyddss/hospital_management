#include "pharmacist.h"

Pharmacist::~Pharmacist(){
    if(prescription!=nullptr){
        for(int i{};i<prescription_num;i++)delete prescription[i];
    }
}

void Pharmacist::check_schedule(){
    QString condition = "personId = '"+this->get_ID()+"'";
    QLinkedList<QLinkedList<QString>> schedule_list = read_data("Schedule",condition);
    if(schedule_list.size()!=0){
        schedule = new Schedule(schedule_list.takeFirst());
    }
    else{
        schedule = new Schedule(this->get_ID(),"星期一日程","星期二日程","星期三日程","星期四日程","星期五日程","星期六日程","星期日日程");
    }
}

void Pharmacist::check_prescription(QString date){
    if(prescription!=nullptr){
        for(int i{};i<prescription_num;i++)delete prescription[i];
    }
    QLinkedList<QLinkedList<QString>> prescription_list;
    QString condition = QString();
    if(date!=""){
        condition = "date = '"+date+"'";
    }
    prescription_list = read_data("Prescription",condition);
    prescription_num = prescription_list.size();
    prescription = new Prescription* [prescription_num];
    int idx = 0;
    for(QLinkedList<QString> &list: prescription_list){
        prescription[idx] = new Prescription(list);
        idx++;
    }
}

QLinkedList<QString> Pharmacist::get_schedule(){
    return schedule->get_details();
}

QLinkedList<QLinkedList<QString>> Pharmacist::get_prescription(){
    QLinkedList<QLinkedList<QString>> out_list;
    for(int i{};i<prescription_num;i++){
        out_list<<prescription[i]->get_details();
    }
    return out_list;
}
