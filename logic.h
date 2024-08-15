#ifndef LOGIC_H
#define LOGIC_H

#include <QWidget>
#include<operationwindow.h>
#include<QStackedWidget>
#include<doctor.h>
#include<manager.h>
#include<patient.h>
#include<pharmacist.h>
#include<checkinput.h>
#include<QMessageBox>
#include <QDateTime>
#include <QRegExp>

class logic : public QWidget
{
    Q_OBJECT
private:
    QStackedWidget* stackedWidget;
    OperationWindow* opwindow[100];
    Doctor* doctor;
    Patient* patient;
    Manager* manager;
    Pharmacist* pharmacist;
    QString now_date;
public:
    explicit logic(QWidget *parent = nullptr);

signals:

public slots:
    void solve_1(int);
    void solve_p_1(int);
    void solve_p_2(int);
    void solve_p_3(int);
    void solve_p_4(int);
    void solve_p_5(int);
    void solve_d_1(int);
    void solve_d_2(int);
    void solve_d_3(int);
    void solve_d_4(int);
    void solve_d_5(int);
    void solve_d_6(int);
    void solve_d_7(int);
    void solve_d_8(int);
    void solve_ph_1(int);
    void solve_ph_2(int);
    void solve_ph_3(int);
    void solve_m_1(int);
    void solve_m_2(int);
    void solve_m_3(int);
    void solve_m_4(int);
    void solve_m_5(int);
    void solve_m_6(int);
};
QString list_to_str(QLinkedList<QLinkedList<QString>> list,int index);

#endif // LOGIC_H
