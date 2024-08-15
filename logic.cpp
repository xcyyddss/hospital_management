#include "logic.h"

logic::logic(QWidget *parent) : QWidget(parent)
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    now_date = QString::number(currentDateTime.date().year())+"-"+QString::number(currentDateTime.date().month())+"-"+QString::number(currentDateTime.date().day());
    for(int i{};i<100;i++)opwindow[i]=nullptr;
    this->setFixedSize(800,800);
    database_init();
    init_manager();
    for(int i{};i<100;i++)opwindow[i]=nullptr;
    stackedWidget = new QStackedWidget(this);
    stackedWidget->setFixedSize(800,800);
    QString type = "write_and_press";
    QLinkedList<QString> list;
    list<<QString("2")<<QString("登录");
    opwindow[0] = new OperationWindow(this,type,list);
    connect(opwindow[0],SIGNAL(button_signal(int)),this,SLOT(solve_1(int)));
    stackedWidget->addWidget(opwindow[0]);
    stackedWidget->show();
    stackedWidget->setCurrentWidget(opwindow[0]);
}

void logic::solve_1(int _){
    QString ID = opwindow[0]->line[0]->text();
    QString key = opwindow[0]->line[1]->text();
    QString table_name = "Person";
    QString condition = "ID = '"+ID+"' AND key = '"+key+"'";
    QLinkedList<QLinkedList<QString>> account = read_data(table_name,condition);
    if(account.size() == 0){
        QMessageBox::information(this, "信息", "ID或密码错误！", QMessageBox::Ok);
    }
    else{
        QLinkedList<QString> person_list = account.takeFirst();
        QString ID = person_list.takeFirst();
        QString name = person_list.takeFirst();
        QString phoneNumber = person_list.takeFirst();
        QString address = person_list.takeFirst();
        QString identity = person_list.takeFirst();
        QString key = person_list.takeFirst();
        QString status = person_list.takeFirst();
        QLinkedList<QString> _list;
        _list<<ID<<name<<phoneNumber<<address<<identity<<key<<status;
        if(identity == "patient"){
            patient = new Patient(_list);
            QString type = "press";
            QLinkedList<QString> list;
            list<<"预约"<<"查看病历"<<"查看处方"<<"查看预约记录"<<"返回";
            if(opwindow[1]==nullptr){
                opwindow[1] = new OperationWindow(this,type,list);
                connect(opwindow[1],SIGNAL(button_signal(int)),this,SLOT(solve_p_1(int)));
                stackedWidget->addWidget(opwindow[1]);
            }
            stackedWidget->setCurrentWidget(opwindow[1]);
        }
        if(identity == "doctor"){
            doctor = new Doctor(_list);
            QString type = "press";
            QLinkedList<QString> list;
            list<<"查看日程"<<"接诊"<<"查看处方"<<"返回";
            if(opwindow[11]==nullptr){
                opwindow[11] = new OperationWindow(this,type,list);
                connect(opwindow[11],SIGNAL(button_signal(int)),this,SLOT(solve_d_1(int)));
                stackedWidget->addWidget(opwindow[11]);
            }
            stackedWidget->setCurrentWidget(opwindow[11]);
        }
        if(identity == "pharmacist"){
            pharmacist = new Pharmacist(_list);
            QString type = "press";
            QLinkedList<QString> list;
            list<<"查看日程"<<"查看处方"<<"返回";
            if(opwindow[21]==nullptr){
                opwindow[21] = new OperationWindow(this,type,list);
                connect(opwindow[21],SIGNAL(button_signal(int)),this,SLOT(solve_ph_1(int)));
                stackedWidget->addWidget(opwindow[21]);
            }
            stackedWidget->setCurrentWidget(opwindow[21]);
        }
        if(identity == "manager"){
            manager = new Manager(_list);
            QString type = "press";
            QLinkedList<QString> list;
            list<<"注册"<<"删除"<<"修改信息"<<"制定/修改日程"<<"查询"<<"返回";
            if(opwindow[31]==nullptr){
                opwindow[31] = new OperationWindow(this,type,list);
                connect(opwindow[31],SIGNAL(button_signal(int)),this,SLOT(solve_m_1(int)));
                stackedWidget->addWidget(opwindow[31]);
            }
            stackedWidget->setCurrentWidget(opwindow[31]);
        }
    }
}

void logic::solve_p_1(int index){
    if(index == 0){
        QString type = "write_and_show_and_press";
        QLinkedList<QString> write_list;
        write_list<<"3"<<"搜索关键词"<<"预约医生ID"<<now_date;
        QLinkedList<QString> press_list;
        press_list<<"搜索医生"<<"确定预约"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[2]==nullptr){
            opwindow[2] = new OperationWindow(this,type,list);
            connect(opwindow[2],SIGNAL(button_signal(int)),this,SLOT(solve_p_2(int)));
            stackedWidget->addWidget(opwindow[2]);
        }
        stackedWidget->setCurrentWidget(opwindow[2]);
    }
    if(index == 1){
        QString type = "write_and_show_and_press";
        QLinkedList<QString> write_list;
        write_list<<"1"<<now_date;
        QLinkedList<QString> press_list;
        press_list<<"查找"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[3]==nullptr){
            opwindow[3] = new OperationWindow(this,type,list);
            connect(opwindow[3],SIGNAL(button_signal(int)),this,SLOT(solve_p_3(int)));
            stackedWidget->addWidget(opwindow[3]);
        }
        stackedWidget->setCurrentWidget(opwindow[3]);
    }
    if(index == 2){
        QString type = "write_and_show_and_press";
        QLinkedList<QString> write_list;
        write_list<<"1"<<now_date;
        QLinkedList<QString> press_list;
        press_list<<"查找"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[4]==nullptr){
            opwindow[4] = new OperationWindow(this,type,list);
            connect(opwindow[4],SIGNAL(button_signal(int)),this,SLOT(solve_p_4(int)));
            stackedWidget->addWidget(opwindow[4]);
        }
        stackedWidget->setCurrentWidget(opwindow[4]);
    }
    if(index == 3){
        QString type = "write_and_show_and_press";
        QLinkedList<QString> write_list;
        write_list<<"1"<<now_date;
        QLinkedList<QString> press_list;
        press_list<<"查找"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[5]==nullptr){
            opwindow[5] = new OperationWindow(this,type,list);
            connect(opwindow[5],SIGNAL(button_signal(int)),this,SLOT(solve_p_5(int)));
            stackedWidget->addWidget(opwindow[5]);
        }
        stackedWidget->setCurrentWidget(opwindow[5]);
    }
    if(index == 4){
        delete patient;
        stackedWidget->setCurrentWidget(opwindow[0]);
    }
}
void logic::solve_p_2(int index){
    if(index == 0){
        QString word = opwindow[2]->line[0]->text();
        patient->check_doctor();
        QLinkedList<QLinkedList<QString>> list = patient->get_doctor(word);
        QString text_str = list_to_str(list,1);
        opwindow[2]->text->setText(text_str);
    }
    if(index == 1){
        if(!check_id(opwindow[2]->line[1]->text(),"Person","identity = 'doctor'")){
            QMessageBox::information(opwindow[2], "警告", "ID不存在或ID非医生！", QMessageBox::Ok);
            return;
        }
        QString doctorId = opwindow[2]->line[1]->text();
        QString date = opwindow[2]->line[2]->text();
        patient->make_appointment(date,doctorId);
        QMessageBox::information(opwindow[2], "信息", "预约成功！", QMessageBox::Ok);
    }
    if(index == 2){
        stackedWidget->setCurrentWidget(opwindow[1]);
    }
}
void logic::solve_p_3(int index){
    if(index == 0){
        QString date = opwindow[3]->line[0]->text();
        patient->check_diagnosis();
        QLinkedList<QLinkedList<QString>> list = patient->get_diagnosis(date);
        QString text_str = list_to_str(list,3);
        opwindow[3]->text->setText(text_str);
    }
    if(index == 1){
        stackedWidget->setCurrentWidget(opwindow[1]);
    }
}
void logic::solve_p_4(int index){
    if(index == 0){
        QString date = opwindow[4]->line[0]->text();
        patient->check_prescription();
        QLinkedList<QLinkedList<QString>> list = patient->get_prescription(date);
        QString text_str = list_to_str(list,4);
        opwindow[4]->text->setText(text_str);
    }
    if(index == 1){
        stackedWidget->setCurrentWidget(opwindow[1]);
    }
}
void logic::solve_p_5(int index){
    if(index == 0){
        QString date = opwindow[5]->line[0]->text();
        patient->check_appointment();
        QLinkedList<QLinkedList<QString>> list = patient->get_appointment(date);
        QString text_str = list_to_str(list,2);
        opwindow[5]->text->setText(text_str);
    }
    if(index == 1){
        stackedWidget->setCurrentWidget(opwindow[1]);
    }
}

void logic::solve_d_1(int index){
    if(index == 0){
        QString type = "show_and_press";
        doctor->check_schedule();
        QLinkedList<QString> list;
        list<<"8"<<doctor->get_schedule();
        list<<"返回";
        if(opwindow[12]==nullptr){
            opwindow[12] = new OperationWindow(this,type,list);
            connect(opwindow[12],SIGNAL(button_signal(int)),this,SLOT(solve_d_2(int)));
            stackedWidget->addWidget(opwindow[12]);
        }
        list.takeFirst();
        for(int i{};i<8;i++){
            opwindow[12]->line[i]->setText(list.takeFirst());
        }
        stackedWidget->setCurrentWidget(opwindow[12]);
    }
    if(index == 1){
        QString type = "press";
        QLinkedList<QString> list;
        list<<"查看预约"<<"诊断/开处方"<<"查看病历"<<"办理住院/出院"<<"返回";
        if(opwindow[13]==nullptr){
            opwindow[13] = new OperationWindow(this,type,list);
            connect(opwindow[13],SIGNAL(button_signal(int)),this,SLOT(solve_d_3(int)));
            stackedWidget->addWidget(opwindow[13]);
        }
        stackedWidget->setCurrentWidget(opwindow[13]);
    }
    if(index == 2){
        QString type = "write_and_show_and_press";
        QLinkedList<QString> write_list;
        write_list<<"1"<<now_date;
        QLinkedList<QString> press_list;
        press_list<<"查找"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[14]==nullptr){
            opwindow[14] = new OperationWindow(this,type,list);
            connect(opwindow[14],SIGNAL(button_signal(int)),this,SLOT(solve_d_4(int)));
            stackedWidget->addWidget(opwindow[14]);
        }
        stackedWidget->setCurrentWidget(opwindow[14]);
    }
    if(index == 3){
        delete doctor;
        stackedWidget->setCurrentWidget(opwindow[0]);
    }
}

void logic::solve_d_2(int){
    stackedWidget->setCurrentWidget(opwindow[11]);
}

void logic::solve_d_3(int index){
    if(index == 0){
        QString type = "write_and_show_and_press";
        QLinkedList<QString> write_list;
        write_list<<"1"<<now_date;
        QLinkedList<QString> press_list;
        press_list<<"查找"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[15]==nullptr){
            opwindow[15] = new OperationWindow(this,type,list);
            connect(opwindow[15],SIGNAL(button_signal(int)),this,SLOT(solve_d_5(int)));
            stackedWidget->addWidget(opwindow[15]);
        }
        stackedWidget->setCurrentWidget(opwindow[15]);
    }
    if(index == 1){
        QString type = "multiple_write_and_press";
        QLinkedList<QString> write_list;
        write_list<<"4"<<"patientId"<<"appointmentId"<<"诊断结果（用逗号分隔）"<<"处方（药剂名 用法 用量 总量）";
        QLinkedList<QString> press_list;
        press_list<<"添加一行"<<"完成"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[16]==nullptr){
            opwindow[16] = new OperationWindow(this,type,list);
            connect(opwindow[16],SIGNAL(button_signal(int)),this,SLOT(solve_d_6(int)));
            stackedWidget->addWidget(opwindow[16]);
        }
        stackedWidget->setCurrentWidget(opwindow[16]);
    }
    if(index == 2){
        QString type = "write_and_show_and_press";
        QLinkedList<QString> write_list;
        write_list<<"2"<<now_date<<"patientId";
        QLinkedList<QString> press_list;
        press_list<<"查找"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[17]==nullptr){
            opwindow[17] = new OperationWindow(this,type,list);
            connect(opwindow[17],SIGNAL(button_signal(int)),this,SLOT(solve_d_7(int)));
            stackedWidget->addWidget(opwindow[17]);
        }
        stackedWidget->setCurrentWidget(opwindow[17]);
    }
    if(index == 3){
        QString type = "write_and_show_and_press";
        QLinkedList<QString> write_list;
        write_list<<"1"<<"patientId";
        QLinkedList<QString> press_list;
        press_list<<"办理住院"<<"办理出院"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[18]==nullptr){
            opwindow[18] = new OperationWindow(this,type,list);
            connect(opwindow[18],SIGNAL(button_signal(int)),this,SLOT(solve_d_8(int)));
            stackedWidget->addWidget(opwindow[18]);
        }
        stackedWidget->setCurrentWidget(opwindow[18]);
    }
    if(index == 4){
        stackedWidget->setCurrentWidget(opwindow[11]);
    }
}

void logic::solve_d_4(int index){
    if(index == 0){
        QString date = opwindow[14]->line[0]->text();
        doctor->check_prescription();
        QLinkedList<QLinkedList<QString>> list = doctor->get_prescription(date);
        QString text_str = list_to_str(list,4);
        opwindow[14]->text->setText(text_str);
    }
    if(index == 1){
        stackedWidget->setCurrentWidget(opwindow[11]);
    }
}

void logic::solve_d_5(int index){
    if(index == 0){
        QString date = opwindow[15]->line[0]->text();
        doctor->check_appointment();
        QLinkedList<QLinkedList<QString>> list = doctor->get_appointment(date);
        QString text_str = list_to_str(list,2);
        opwindow[15]->text->setText(text_str);
    }
    if(index == 1){
        stackedWidget->setCurrentWidget(opwindow[13]);
    }
}

void logic::solve_d_6(int index){
    if(index == 1){
        if(!check_id(opwindow[16]->line[0]->text(),"Person","identity = 'patient'")){
            QMessageBox::information(opwindow[16], "警告", "ID不存在或ID非病人！", QMessageBox::Ok);
            return;
        }
        if(!check_id(opwindow[16]->line[1]->text(),"Appointment","patientId = '"+opwindow[16]->line[0]->text()+"' AND doctorId = '"+doctor->get_id()+"' AND finished = 'not_finished'")){
            QMessageBox::information(opwindow[16], "警告", "预约ID无效（可能已完成、可能与病人ID不对应、可能与医生ID不对应）！", QMessageBox::Ok);
            return;
        }
        QLinkedList<QString> diagnosis_content;
        QLinkedList<QString> prescription_content;
        QString patientId = opwindow[16]->line[0]->text();
        QString appointmentId = opwindow[16]->line[1]->text();
        QString content_1 = opwindow[16]->line[2]->text();
        QStringList content_1_list = content_1.split(QRegExp("[,，]"), QString::SkipEmptyParts);
        for (const QString& str : content_1_list) {
            diagnosis_content<<str;
        }
        for(int i{3};i<opwindow[16]->line_num;i++){
            QString content_2 = opwindow[16]->line[i]->text();
            QStringList content_2_list = content_2.split(' ', QString::SkipEmptyParts);
            if(content_2_list.size()!=4){
                QMessageBox::information(opwindow[16], "警告", "请输入正确的处方格式！", QMessageBox::Ok);
                return;
            }
            for (const QString& str : content_2_list) {
                prescription_content<<str;
            }
        }
        doctor->make_diagnosis(now_date,patientId,diagnosis_content);
        doctor->make_prescription(now_date,patientId,prescription_content);
        doctor->finish_appointment(appointmentId);
        QMessageBox::information(opwindow[16], "信息", "操作成功！", QMessageBox::Ok);
    }
    if(index == 2){
        stackedWidget->setCurrentWidget(opwindow[13]);
    }
}

void logic::solve_d_7(int index){
    if(index == 0){
        QString date = opwindow[17]->line[0]->text();
        QString patientId = opwindow[17]->line[1]->text();
        doctor->check_diagnosis(patientId);
        QLinkedList<QLinkedList<QString>> list = doctor->get_diagnosis(date);
        QString text_str = list_to_str(list,3);
        opwindow[17]->text->setText(text_str);
    }
    if(index == 1){
        stackedWidget->setCurrentWidget(opwindow[13]);
    }
}

void logic::solve_d_8(int index){
    if(index == 0){
        if(!check_id(opwindow[18]->line[0]->text(),"Person","identity = 'patient'")){
            QMessageBox::information(opwindow[18], "警告", "ID不存在或ID非病人！", QMessageBox::Ok);
            return;
        }
        QString patientId = opwindow[18]->line[0]->text();
        doctor->hospitalize(patientId);
        QMessageBox::information(opwindow[18], "信息", "操作成功！", QMessageBox::Ok);
    }
    if(index == 1){
        if(!check_id(opwindow[18]->line[0]->text(),"Person","identity = 'patient'")){
            QMessageBox::information(opwindow[18], "警告", "ID不存在或ID非病人！", QMessageBox::Ok);
            return;
        }
        QString patientId = opwindow[18]->line[0]->text();
        doctor->discharge(patientId);
        QMessageBox::information(opwindow[18], "信息", "操作成功！", QMessageBox::Ok);
    }
    if(index == 2){
        stackedWidget->setCurrentWidget(opwindow[13]);
    }
}

void logic::solve_ph_1(int index){
    if(index == 0){
        QString type = "show_and_press";
        pharmacist->check_schedule();
        QLinkedList<QString> list;
        list<<"8"<<pharmacist->get_schedule();
        list<<"返回";
        if(opwindow[22]==nullptr){
            opwindow[22] = new OperationWindow(this,type,list);
            connect(opwindow[22],SIGNAL(button_signal(int)),this,SLOT(solve_ph_2(int)));
            stackedWidget->addWidget(opwindow[22]);
        }
        stackedWidget->setCurrentWidget(opwindow[22]);
    }
    if(index == 1){
        QString type = "write_and_show_and_press";
        QLinkedList<QString> write_list;
        write_list<<"1"<<now_date;
        QLinkedList<QString> press_list;
        press_list<<"查找"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[23]==nullptr){
            opwindow[23] = new OperationWindow(this,type,list);
            connect(opwindow[23],SIGNAL(button_signal(int)),this,SLOT(solve_ph_3(int)));
            stackedWidget->addWidget(opwindow[23]);
        }
        stackedWidget->setCurrentWidget(opwindow[23]);
    }
    if(index == 2){
        delete pharmacist;
        stackedWidget->setCurrentWidget(opwindow[0]);
    }
}

void logic::solve_ph_2(int index){
    stackedWidget->setCurrentWidget(opwindow[21]);
}

void logic::solve_ph_3(int index){
    if(index == 0){
        QString date = opwindow[23]->line[0]->text();
        pharmacist->check_prescription(date);
        QLinkedList<QLinkedList<QString>> list = pharmacist->get_prescription();
        QString text_str = list_to_str(list,4);
        opwindow[23]->text->setText(text_str);
    }
    if(index == 1){
        stackedWidget->setCurrentWidget(opwindow[21]);
    }
}

void logic::solve_m_1(int index){
    if(index == 0){
        QString type = "write_and_press";
        QLinkedList<QString> write_list;
        write_list<<"6"<<"名字"<<"电话"<<"地址"<<"身份"<<"密码"<<"状态";
        QLinkedList<QString> press_list;
        press_list<<"完成"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[32]==nullptr){
            opwindow[32] = new OperationWindow(this,type,list);
            connect(opwindow[32],SIGNAL(button_signal(int)),this,SLOT(solve_m_2(int)));
            stackedWidget->addWidget(opwindow[32]);
        }
        stackedWidget->setCurrentWidget(opwindow[32]);
    }
    if(index == 1){
        QString type = "write_and_press";
        QLinkedList<QString> write_list;
        write_list<<"1"<<"personID";
        QLinkedList<QString> press_list;
        press_list<<"删除"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[33]==nullptr){
            opwindow[33] = new OperationWindow(this,type,list);
            connect(opwindow[33],SIGNAL(button_signal(int)),this,SLOT(solve_m_3(int)));
            stackedWidget->addWidget(opwindow[33]);
        }
        stackedWidget->setCurrentWidget(opwindow[33]);
    }
    if(index == 2){
        QString type = "write_and_press";
        QLinkedList<QString> write_list;
        write_list<<"3"<<"ID"<<"类型:名字(1), 电话(2), 地址(3), 身份(4), 密码(5), 状态(6)"<<"输入修改后的信息";
        QLinkedList<QString> press_list;
        press_list<<"修改"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[34]==nullptr){
            opwindow[34] = new OperationWindow(this,type,list);
            connect(opwindow[34],SIGNAL(button_signal(int)),this,SLOT(solve_m_4(int)));
            stackedWidget->addWidget(opwindow[34]);
        }
        stackedWidget->setCurrentWidget(opwindow[34]);
    }
    if(index == 3){
        QString type = "write_and_press";
        QLinkedList<QString> write_list;
        write_list<<"8"<<"personID"<<"星期一日程"<<"星期二日程"<<"星期三日程"<<"星期四日程"<<"星期五日程"<<"星期六日程"<<"星期日日程";
        QLinkedList<QString> press_list;
        press_list<<"完成"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[35]==nullptr){
            opwindow[35] = new OperationWindow(this,type,list);
            connect(opwindow[35],SIGNAL(button_signal(int)),this,SLOT(solve_m_5(int)));
            stackedWidget->addWidget(opwindow[35]);
        }
        stackedWidget->setCurrentWidget(opwindow[35]);
    }
    if(index == 4){
        QString type = "write_and_show_and_press";
        QLinkedList<QString> write_list;
        write_list<<"1"<<"类型：person(1), appointment(2), diagnosis(3), prescription(4), schedule(5)";
        QLinkedList<QString> press_list;
        press_list<<"查找"<<"返回";
        QLinkedList<QLinkedList<QString>> list;
        list<<write_list<<press_list;
        if(opwindow[36]==nullptr){
            opwindow[36] = new OperationWindow(this,type,list);
            connect(opwindow[36],SIGNAL(button_signal(int)),this,SLOT(solve_m_6(int)));
            stackedWidget->addWidget(opwindow[36]);
        }
        stackedWidget->setCurrentWidget(opwindow[36]);
    }
    if(index == 5){
        delete manager;
        stackedWidget->setCurrentWidget(opwindow[0]);
    }
}

void logic::solve_m_2(int index){
    if(index == 0){
        QLinkedList<QString> list;
        for(int i{};i<6;i++){
            list<<opwindow[32]->line[i]->text();
            if(i == 3){
                QString str = opwindow[32]->line[i]->text();
                QLinkedList<QString> str_list;
                str_list<<"doctor"<<"patient"<<"pharmacist"<<"manager";
                if(!check_in(str,str_list)){
                    QMessageBox::information(opwindow[32], "警告", "请输入正确的身份信息！", QMessageBox::Ok);
                    return;
                }
            }
        }
        manager->register_person(list);
        QMessageBox::information(opwindow[32], "信息", "注册成功！", QMessageBox::Ok);
    }
    else{
        stackedWidget->setCurrentWidget(opwindow[31]);
    }
}

void logic::solve_m_3(int index){
    if(index == 0){
        if(!check_id(opwindow[33]->line[0]->text(),"Person","")){
            QMessageBox::information(opwindow[33], "警告", "ID不存在！", QMessageBox::Ok);
            return;
        }
        manager->delete_person(opwindow[33]->line[0]->text());
        QMessageBox::information(opwindow[33], "信息", "删除成功！", QMessageBox::Ok);
    }
    else{
        stackedWidget->setCurrentWidget(opwindow[31]);
    }
}

void logic::solve_m_4(int index){
    if(index == 0){
        if(!check_id(opwindow[34]->line[0]->text(),"Person","")){
            QMessageBox::information(opwindow[34], "警告", "ID不存在！", QMessageBox::Ok);
            return;
        }
        QString str = opwindow[34]->line[1]->text();
        QLinkedList<QString> str_list;
        str_list<<"1"<<"2"<<"3"<<"4"<<"5"<<"6";
        if(!check_in(str,str_list)){
            QMessageBox::information(opwindow[34], "警告", "请输入正确的类型（1、2、3、4、5、6）！", QMessageBox::Ok);
            return;
        }
        int idx = opwindow[34]->line[1]->text().toInt();
        QString update_data = opwindow[34]->line[2]->text();
        QString ID = opwindow[34]->line[0]->text();
        if(idx == 1){
            manager->update_person_name(ID,update_data);
        }
        if(idx == 2){
            manager->update_person_phoneNumber(ID,update_data);
        }
        if(idx == 3){
            manager->update_person_address(ID,update_data);
        }
        if(idx == 4){
            QString _str = update_data;
            QLinkedList<QString> _str_list;
            _str_list<<"doctor"<<"patient"<<"pharmacist"<<"manager";
            if(!check_in(_str,_str_list)){
                QMessageBox::information(opwindow[34], "警告", "请输入正确的身份信息！", QMessageBox::Ok);
                return;
            }
            manager->update_person_identity(ID,update_data);
        }
        if(idx == 5){
            manager->update_person_key(ID,update_data);
        }
        if(idx == 6){
            manager->update_person_status(ID,update_data);
        }
        QMessageBox::information(opwindow[34], "信息", "修改成功！", QMessageBox::Ok);
    }
    else{
        stackedWidget->setCurrentWidget(opwindow[31]);
    }
}

void logic::solve_m_5(int index){
    if(index == 0){
        if(!check_id(opwindow[35]->line[0]->text(),"Person","identity != 'patient'")){
            QMessageBox::information(opwindow[35], "警告", "ID不存在或ID非工作人员！", QMessageBox::Ok);
            return;
        }
        QLinkedList<QString> list;
        for(int i{};i<8;i++){
            list<<opwindow[35]->line[i]->text();
        }
        manager->update_schedule(list);
        QMessageBox::information(opwindow[35], "信息", "修订成功！", QMessageBox::Ok);
    }
    else{
        stackedWidget->setCurrentWidget(opwindow[31]);
    }
}

void logic::solve_m_6(int index){
    if(index == 0){
        QString str = opwindow[36]->line[0]->text();
        QLinkedList<QString> str_list;
        str_list<<"1"<<"2"<<"3"<<"4"<<"5";
        if(!check_in(str,str_list)){
            QMessageBox::information(opwindow[36], "警告", "请输入正确的类型（1、2、3、4、5）！", QMessageBox::Ok);
            return;
        }
        int idx = opwindow[36]->line[0]->text().toInt();
        QString text_str = QString();
        QLinkedList<QLinkedList<QString>> list;
        if(idx == 1){
            manager->check_person();
            list = manager->get_person();
        }
        if(idx == 2){
            manager->check_appointment();
            list = manager->get_appointment();
        }
        if(idx == 3){
            manager->check_diagnosis();
            list = manager->get_diagnosis();
        }
        if(idx == 4){
            manager->check_prescription();
            list = manager->get_prescription();
        }
        if(idx == 5){
            manager->check_schedule();
            list = manager->get_schedule();
        }
        text_str = list_to_str(list,idx);
        opwindow[36]->text->setPlainText(text_str);
        QScrollBar *scrollBar = new QScrollBar(Qt::Vertical, opwindow[36]->text);
        opwindow[36]->text->setVerticalScrollBar(scrollBar);
    }
    else{
        stackedWidget->setCurrentWidget(opwindow[31]);
    }
}


QString list_to_str(QLinkedList<QLinkedList<QString>> list, int idx){
    QString text_str = QString();
    if(idx == 1){
        for(QLinkedList<QString> &_list:list){
            QString str_last = _list.takeLast();
            for(QString & str:_list){
                text_str+=(str+" ");
            }
            text_str+="\n    "+str_last;
            text_str+="\n";
        }
    }
    if(idx == 2){
        for(QLinkedList<QString> &_list:list){
            for(QString & str:_list){
                text_str+=(str+" ");
            }
            text_str+="\n";
        }
    }
    if(idx == 3){
        for(QLinkedList<QString> _list:list){
            for(int i{};i<4;i++){
                text_str += (_list.takeFirst()+" ");
            }
            text_str += "\n";
            while(_list.size()>0){
                text_str += ("     "+_list.takeFirst()+"\n");
            }
        }
    }
    if(idx == 4){
        for(QLinkedList<QString> _list:list){
            for(int i{};i<4;i++){
                text_str += (_list.takeFirst()+" ");
            }
            text_str += "\n";
            while(_list.size()>0){
                text_str += ("     "+_list.takeFirst()+" ");
                text_str += (_list.takeFirst()+" ");
                text_str += (_list.takeFirst()+" ");
                text_str += (_list.takeFirst()+"\n");
            }
        }
    }
    if(idx == 5){
        for(QLinkedList<QString> &_list:list){
            for(QString & str:_list){
                text_str+=(str+" ");
            }
            text_str+="\n";
        }
    }
    return text_str;
}
