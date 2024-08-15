#include "manager.h"

Manager::~Manager(){
    if(appointment!=nullptr){
        for(int i{};i<appointment_num;i++)delete appointment[i];
    }
    if(diagnosis!=nullptr){
        for(int i{};i<diagnosis_num;i++)delete diagnosis[i];
    }
    if(prescription!=nullptr){
        for(int i{};i<prescription_num;i++)delete prescription[i];
    }
    if(person!=nullptr){
        for(int i{};i<person_num;i++)delete person[i];
    }
    if(schedule!=nullptr){
        for(int i{};i<schedule_num;i++)delete schedule[i];
    }
}

void Manager::register_person(QLinkedList<QString> details){
    insert_data("Person",details);
}

void Manager::delete_person(QString ID){
    delete_data("Person",ID);
}

void Manager::update_person_name(QString ID,QString name){
    QString update_content = "name = '"+name+"'";
    QString condition = "ID = '"+ID+"'";
    update_data("Person",update_content,condition);
}

void Manager::update_person_phoneNumber(QString ID,QString phoneNumber){
    QString update_content = "phoneNumber = '"+phoneNumber+"'";
    QString condition = "ID = '"+ID+"'";
    update_data("Person",update_content,condition);
}

void Manager::update_person_address(QString ID,QString address){
    QString update_content = "address = '"+address+"'";
    QString condition = "ID = '"+ID+"'";
    update_data("Person",update_content,condition);
}

void Manager::update_person_identity(QString ID,QString identity){
    QString update_content = "identity = '"+identity+"'";
    QString condition = "ID = '"+ID+"'";
    update_data("Person",update_content,condition);
}

void Manager::update_person_key(QString ID,QString key){
    QString update_content = "key = '"+key+"'";
    QString condition = "ID = '"+ID+"'";
    update_data("Person",update_content,condition);
}

void Manager::update_person_status(QString ID,QString status){
    QString update_content = "status = '"+status+"'";
    QString condition = "ID = '"+ID+"'";
    update_data("Person",update_content,condition);
}

void Manager::update_schedule(QLinkedList<QString> details){
    QString header[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    QString personId = details.first();
    QLinkedList<QLinkedList<QString>> schedule_list = read_data("Schedule","personId = '"+personId+"'");
    if(schedule_list.size()==0){
        insert_data("Schedule",details);
    }
    else{
        for(int i{};i<7;i++){
            QString update_content = header[i]+" = '"+details.takeFirst()+"'";
            QString condition = "personId = '"+personId+"'";
            update_data("Schedule",update_content,condition);
        }
    }
}

void Manager::check_appointment(QString id_limit){
    if(appointment!=nullptr){
        for(int i{};i<appointment_num;i++)delete appointment[i];
    }
    QLinkedList<QLinkedList<QString>> appointment_list;
    QString condition = "ID < '"+id_limit+"'";
    appointment_list = read_data("Appointment",condition);
    appointment_num = appointment_list.size();
    appointment = new Appointment* [appointment_num];
    int idx = 0;
    for(QLinkedList<QString> &list: appointment_list){
        appointment[idx] = new Appointment(list);
        idx++;
    }
}

void Manager::check_diagnosis(QString id_limit){
    if(diagnosis!=nullptr){
        for(int i{};i<diagnosis_num;i++)delete diagnosis[i];
    }
    QLinkedList<QLinkedList<QString>> diagnosis_list;
    QString condition = "ID < '"+id_limit+"'";
    diagnosis_list = read_data("Diagnosis",condition);
    diagnosis_num = diagnosis_list.size();
    diagnosis = new Diagnosis* [diagnosis_num];
    int idx = 0;
    for(QLinkedList<QString> &list: diagnosis_list){
        diagnosis[idx] = new Diagnosis(list);
        idx++;
    }
}

void Manager::check_person(QString id_limit){
    if(person!=nullptr){
        for(int i{};i<person_num;i++)delete person[i];
    }
    QLinkedList<QLinkedList<QString>> person_list;
    QString condition = "ID < '"+id_limit+"'";
    person_list = read_data("Person",condition);
    person_num = person_list.size();
    person = new Person* [person_num];
    int idx = 0;
    for(QLinkedList<QString> &list: person_list){
        person[idx] = new Person(list);
        idx++;
    }
}

void Manager::check_prescription(QString id_limit){
    if(prescription!=nullptr){
        for(int i{};i<prescription_num;i++)delete prescription[i];
    }
    QLinkedList<QLinkedList<QString>> prescription_list;
    QString condition = "ID < '"+id_limit+"'";
    prescription_list = read_data("Prescription",condition);
    prescription_num = prescription_list.size();
    prescription = new Prescription* [prescription_num];
    int idx = 0;
    for(QLinkedList<QString> &list: prescription_list){
        prescription[idx] = new Prescription(list);
        idx++;
    }
}

void Manager::check_schedule(QString id_limit){
    if(schedule!=nullptr){
        for(int i{};i<schedule_num;i++)delete schedule[i];
    }
    QLinkedList<QLinkedList<QString>> schedule_list;
    QString condition = "ID < '"+id_limit+"'";
    schedule_list = read_data("Schedule",condition);
    schedule_num = schedule_list.size();
    schedule = new Schedule* [schedule_num];
    int idx = 0;
    for(QLinkedList<QString> &list: schedule_list){
        schedule[idx] = new Schedule(list);
        idx++;
    }
}

QLinkedList<QLinkedList<QString>> Manager::get_appointment(){
    QLinkedList<QLinkedList<QString>> out_list;
    for(int i{};i<appointment_num;i++){
        out_list<<appointment[i]->get_details();
    }
    return out_list;
}

QLinkedList<QLinkedList<QString>> Manager::get_diagnosis(){
    QLinkedList<QLinkedList<QString>> out_list;
    for(int i{};i<diagnosis_num;i++){
        out_list<<diagnosis[i]->get_details();
    }
    return out_list;
}

QLinkedList<QLinkedList<QString>> Manager::get_person(){
    QLinkedList<QLinkedList<QString>> out_list;
    for(int i{};i<person_num;i++){
        out_list<<person[i]->get_details();
    }
    return out_list;
}

QLinkedList<QLinkedList<QString>> Manager::get_prescription(){
    QLinkedList<QLinkedList<QString>> out_list;
    for(int i{};i<prescription_num;i++){
        out_list<<prescription[i]->get_details();
    }
    return out_list;
}

QLinkedList<QLinkedList<QString>> Manager::get_schedule(){
    QLinkedList<QLinkedList<QString>> out_list;
    for(int i{};i<schedule_num;i++){
        out_list<<schedule[i]->get_details();
    }
    return out_list;
}
