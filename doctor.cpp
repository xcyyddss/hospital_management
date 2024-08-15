#include "doctor.h"

Doctor::~Doctor(){
    if(appointment!=nullptr){
        for(int i{};i<appointment_num;i++)delete appointment[i];
    }
    if(diagnosis!=nullptr){
        for(int i{};i<diagnosis_num;i++)delete diagnosis[i];
    }
    if(prescription!=nullptr){
        for(int i{};i<prescription_num;i++)delete prescription[i];
    }
}

void Doctor::check_schedule(){
    QString condition = "personId = '"+this->get_ID()+"'";
    QLinkedList<QLinkedList<QString>> schedule_list = read_data("Schedule",condition);
    if(schedule_list.size()!=0){
        schedule = new Schedule(schedule_list.takeFirst());
    }
    else{
        schedule = new Schedule(this->get_ID(),"星期一日程","星期二日程","星期三日程","星期四日程","星期五日程","星期六日程","星期日日程");
    }
}

void Doctor::check_appointment(){
    if(appointment!=nullptr){
        for(int i{};i<appointment_num;i++)delete appointment[i];
    }
    QLinkedList<QLinkedList<QString>> appointment_list;
    QString condition = "doctorId = '"+this->get_ID()+"'";
    appointment_list = read_data("Appointment",condition);
    appointment_num = appointment_list.size();
    appointment = new Appointment* [appointment_num];
    int idx = 0;
    for(QLinkedList<QString> &list: appointment_list){
        appointment[idx] = new Appointment(list);
        idx++;
    }
}

void Doctor::check_diagnosis(QString patientId){
    if(diagnosis!=nullptr){
        for(int i{};i<diagnosis_num;i++)delete diagnosis[i];
    }
    QLinkedList<QLinkedList<QString>> diagnosis_list;
    QString condition = "patientId = '"+patientId+"'";
    diagnosis_list = read_data("Diagnosis",condition);
    diagnosis_num = diagnosis_list.size();
    diagnosis = new Diagnosis* [diagnosis_num];
    int idx = 0;
    for(QLinkedList<QString> &list: diagnosis_list){
        diagnosis[idx] = new Diagnosis(list);
        idx++;
    }
}

void Doctor::check_prescription(){
    if(prescription!=nullptr){
        for(int i{};i<prescription_num;i++)delete prescription[i];
    }
    QLinkedList<QLinkedList<QString>> prescription_list;
    QString condition = "doctorId = '"+this->get_ID()+"'";
    prescription_list = read_data("Prescription",condition);
    prescription_num = prescription_list.size();
    prescription = new Prescription* [prescription_num];
    int idx = 0;
    for(QLinkedList<QString> &list: prescription_list){
        prescription[idx] = new Prescription(list);
        idx++;
    }
}

QLinkedList<QString> Doctor::get_schedule(){
    return schedule->get_details();
}

QLinkedList<QLinkedList<QString>> Doctor::get_appointment(QString date){
    QLinkedList<QLinkedList<QString>> out_list;
    if(date == ""){
        for(int i{};i<appointment_num;i++){
            out_list<<appointment[i]->get_details();
        }
    }
    else{
        for(int i{};i<appointment_num;i++){
            if(appointment[i]->get_time().contains(date)){
                out_list<<appointment[i]->get_details();
            }
        }
    }
    return out_list;
}

QLinkedList<QLinkedList<QString>> Doctor::get_diagnosis(QString date){
    QLinkedList<QLinkedList<QString>> out_list;
    if(date == ""){
        for(int i{};i<diagnosis_num;i++){
            out_list<<diagnosis[i]->get_details();
        }
    }
    else{
        for(int i{};i<diagnosis_num;i++){
            if(diagnosis[i]->get_date() == date){
                out_list<<diagnosis[i]->get_details();
            }
        }
    }
    return out_list;
}

QLinkedList<QLinkedList<QString>> Doctor::get_prescription(QString date){
    QLinkedList<QLinkedList<QString>> out_list;
    if(date == ""){
        for(int i{};i<prescription_num;i++){
            out_list<<prescription[i]->get_details();
        }
    }
    else{
        for(int i{};i<prescription_num;i++){
            if(prescription[i]->get_date() == date){
                out_list<<prescription[i]->get_details();
            }
        }
    }
    return out_list;
}

void Doctor::make_diagnosis(QString date,QString patientId,QLinkedList<QString> content){
    QLinkedList<QString> data;
    data<<date<<patientId<<this->get_ID();
    for(const QString &str: content){
        data<<str;
    }
    insert_data("Diagnosis",data);
    check_prescription();
}

void Doctor::make_prescription(QString date,QString patientId,QLinkedList<QString> content){
    QLinkedList<QString> data;
    data<<date<<patientId<<this->get_ID();
    for(const QString &str: content){
        data<<str;
    }
    insert_data("Prescription",data);
    check_prescription();
}

void Doctor::hospitalize(QString patientId){
    QString update_content = "status = 'hospitalized'";
    QString condition = "ID = '"+patientId+"'";
    update_data("Person",update_content,condition);
}

void Doctor::discharge(QString patientId){
    QString update_content = "status = 'discharged'";
    QString condition = "ID = '"+patientId+"'";
    update_data("Person",update_content,condition);
}

void Doctor::finish_appointment(QString ID){
    QString update_content = "finished = 'finished'";
    QString condition = "ID = '"+ID+"'";
    update_data("Appointment",update_content,condition);
}
