#include "database.h"

QSqlDatabase db;

void database_init(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./hospital.db");
    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return;
    }
    QSqlQuery query1;
    if (!query1.exec("CREATE TABLE IF NOT EXISTS Person (ID INTEGER PRIMARY KEY,name TEXT,phoneNumber TEXT,address TEXT,identity TEXT,key TEXT,status TEXT)")) {
        qDebug() << "Table creation failed:" << query1.lastError().text();
        return;
    }
    QSqlQuery query2;
    if (!query2.exec("CREATE TABLE IF NOT EXISTS Appointment (ID INTEGER PRIMARY KEY,time TEXT,patientId TEXT,doctorId TEXT,finished TEXT)")) {
        qDebug() << "Table creation failed:" << query2.lastError().text();
        return;
    }
    QSqlQuery query3;
    if (!query3.exec("CREATE TABLE IF NOT EXISTS Diagnosis (ID INTEGER PRIMARY KEY,date TEXT,patientId TEXT,doctorId TEXT,content TEXT)")) {
        qDebug() << "Table creation failed:" << query3.lastError().text();
        return;
    }
    QSqlQuery query4;
    if (!query4.exec("CREATE TABLE IF NOT EXISTS Prescription (ID INTEGER PRIMARY KEY,date TEXT,patientId TEXT,doctorId TEXT,content TEXT)")) {
        qDebug() << "Table creation failed:" << query4.lastError().text();
        return;
    }
    QSqlQuery query5;
    if (!query5.exec("CREATE TABLE IF NOT EXISTS Schedule (ID INTEGER PRIMARY KEY,personId TEXT,Monday TEXT,Tuesday TEXT,Wednesday TEXT,Thursday TEXT,Friday TEXT,Saturday TEXT,Sunday TEXT)")) {
        qDebug() << "Table creation failed:" << query5.lastError().text();
        return;
    }
}

void init_manager(){
    QLinkedList<QLinkedList<QString>> if_exist = read_data("Person","ID = '1'");
    if(if_exist.size()!=0)return;
    QLinkedList<QString> manager_list;
    manager_list<<"manager01"<<"110"<<"仙林栖霞"<<"manager"<<"123"<<"无";
    insert_data("Person",manager_list);
}

void insert_data(QString table_name,QLinkedList<QString> data){
    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return;
    }
    db.transaction();
    QSqlQuery query;
    if(table_name=="Person"){
        query.prepare("INSERT INTO Person (name, phoneNumber,address,identity,key,status) VALUES (?, ?, ?, ?, ?, ?)");
        query.bindValue(0, data.takeFirst());
        query.bindValue(1, data.takeFirst());
        query.bindValue(2, data.takeFirst());
        query.bindValue(3, data.takeFirst());
        query.bindValue(4, data.takeFirst());
        query.bindValue(5, data.takeFirst());
    }
    if(table_name=="Appointment"){
        query.prepare("INSERT INTO Appointment (time, patientId,doctorId,finished) VALUES (?, ?, ?, ?)");
        query.bindValue(0, data.takeFirst());
        query.bindValue(1, data.takeFirst());
        query.bindValue(2, data.takeFirst());
        query.bindValue(3, data.takeFirst());
    }
    if(table_name=="Diagnosis"){
        query.prepare("INSERT INTO Diagnosis (date, patientId,doctorId,content) VALUES (?, ?, ?, ?)");
        query.bindValue(0, data.takeFirst());
        query.bindValue(1, data.takeFirst());
        query.bindValue(2, data.takeFirst());
        QString content = QString();
        for(const QString &str : data){
            content+=(str+QString("|"));
        }
        content.remove(content.length() - 1, 1);
        query.bindValue(3, content);
    }
    if(table_name=="Prescription"){
        query.prepare("INSERT INTO Prescription (date, patientId,doctorId,content) VALUES (?, ?, ?, ?)");
        query.bindValue(0, data.takeFirst());
        query.bindValue(1, data.takeFirst());
        query.bindValue(2, data.takeFirst());
        QString content = QString();
        while(data.size()!=0){
            content+=(data.takeFirst()+QString("*")+data.takeFirst()+QString("*")+data.takeFirst()+QString("*")+data.takeFirst()+QString("|"));
        }
        content.remove(content.length() - 1, 1);
        query.bindValue(3, content);
    }
    if(table_name=="Schedule"){
        query.prepare("INSERT INTO Schedule (personId, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
        query.bindValue(0, data.takeFirst());
        query.bindValue(1, data.takeFirst());
        query.bindValue(2, data.takeFirst());
        query.bindValue(3, data.takeFirst());
        query.bindValue(4, data.takeFirst());
        query.bindValue(5, data.takeFirst());
        query.bindValue(6, data.takeFirst());
        query.bindValue(7, data.takeFirst());
    }
    if (!query.exec()) {
        qDebug() << "Error inserting data:" << query.lastError().text();
        db.rollback(); // 回滚事务
        return;
    }
    db.commit();
    qDebug() << "Data inserted successfully";
}

QLinkedList<QLinkedList<QString>> read_data(QString table_name,QString condition){
    QLinkedList<QLinkedList<QString>> out_list;
    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return out_list;
    }
    db.transaction();
    QSqlQuery query;
    if(condition == ""){
        query.prepare("SELECT * FROM "+table_name);
    }
    else{
        query.prepare("SELECT * FROM "+table_name+" WHERE "+condition);
    }
    if (query.exec()) {
        if(table_name=="Person"){
            while (query.next()) {
                QLinkedList<QString> tmp_list;
                tmp_list<<query.value("ID").toString()<<query.value("name").toString()<<query.value("phoneNumber").toString()<<query.value("address").toString()<<query.value("identity").toString()<<query.value("key").toString()<<query.value("status").toString();
                out_list<<tmp_list;
            }
        }
        if(table_name=="Appointment"){
            while (query.next()) {
                QLinkedList<QString> tmp_list;
                tmp_list<<query.value("ID").toString()<<query.value("time").toString()<<query.value("patientId").toString()<<query.value("doctorId").toString()<<query.value("finished").toString();
                out_list<<tmp_list;
            }
        }
        if(table_name=="Diagnosis"){
            while (query.next()) {
                QLinkedList<QString> tmp_list;
                tmp_list<<query.value("ID").toString()<<query.value("date").toString()<<query.value("patientId").toString()<<query.value("doctorId").toString();
                QString tmp_str = query.value("content").toString();
                QStringList list = tmp_str.split('|', QString::SkipEmptyParts);
                foreach (const QString &str, list) {
                    tmp_list << str;
                }
                out_list<<tmp_list;
            }
        }
        if(table_name=="Prescription"){
            while (query.next()) {
                QLinkedList<QString> tmp_list;
                tmp_list<<query.value("ID").toString()<<query.value("date").toString()<<query.value("patientId").toString()<<query.value("doctorId").toString();
                QString tmp_str = query.value("content").toString();
                QStringList list = tmp_str.split('|');
                foreach (const QString &str, list) {
                    QStringList list_2 = str.split('*', QString::SkipEmptyParts);
                    foreach (const QString &_str, list_2) {
                        tmp_list << _str;
                    }
                }
                out_list<<tmp_list;
            }
        }
        if(table_name=="Schedule"){
            while (query.next()) {
                QLinkedList<QString> tmp_list;
                tmp_list<<query.value("personId").toString()<<query.value("Monday").toString()<<query.value("Tuesday").toString()<<query.value("Wednesday").toString()<<query.value("Thursday").toString()<<query.value("Friday").toString()<<query.value("Saturday").toString()<<query.value("Sunday").toString();
                out_list<<tmp_list;
            }
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
        db.rollback();
    }
    db.commit();
    return out_list;
}


void update_data(QString table_name,QString update_content,QString condition){
    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return;
    }
    db.transaction();
    QSqlQuery query;
    query.prepare("UPDATE "+table_name+" SET "+update_content+" WHERE "+condition);
    if (query.exec()) {
        qDebug() << "Data updated successfully.";
    }
    else {
        qDebug() << "Error updating data:" << query.lastError().text();
        db.rollback();
    }
    db.commit();
}

void delete_data(QString table_name,QString ID){
    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return;
    }
    db.transaction();
    QSqlQuery query;
    query.prepare("DELETE FROM "+table_name+" WHERE ID = ?");
    query.bindValue(0, ID);
    if (query.exec()) {
        qDebug() << "Data updated successfully.";
    }
    else {
        qDebug() << "Error updating data:" << query.lastError().text();
        db.rollback();
    }
    db.commit();
}
