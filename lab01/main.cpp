#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <algorithm>
#include <QList>
#include <iostream>
using namespace std;

struct students{
    int num;
    int class1;
    int class2;
    QString name;
};

void Students(QList<students> &student,int num,QString name, int class1, int class2){
    students stu;
    stu.num=num;
    stu.name=name;
    stu.class1=class1;
    stu.class2=class2;
    student.push_back(stu);
}
bool sortname(const students &s1,const students &s2){
    return s1.name > s2.name;
}
bool sortclass1(const students &s1,const students &s2){
    return s1.class1 > s2.class1;
}
bool sortclass2(const students &s1,const students &s2){
    return s1.class2 > s2.class2;
}
int main(){
    QList<students> student;
    Students(student,1403130209,"鲁智深",80,72);
    Students(student,1403140101,"林冲",82,76);
    Students(student,1403140102,"宋江",76,85);
    Students(student,1403140103,"武松",88,80);
    qDebug()<< "排序前:" << endl;
    for(QList<students>::iterator iter = student.begin(); iter != student.end(); ++iter){
        qDebug()<<(*iter).num<<" "<< (*iter).name<<" "<< (*iter).class1<< " "<< (*iter).class2 << endl;
    }
    std::sort(student.begin(),student.end(),sortname);
    qDebug()<< "按姓名排序后:" << endl;
    for(QList<students>::iterator iter = student.begin(); iter != student.end(); ++iter){
        qDebug()<<(*iter).num<<" "<< (*iter).name<<" "<< (*iter).class1<< " "<< (*iter).class2 << endl;
    }
    std::sort(student.begin(),student.end(),sortclass1);
    qDebug()<<"按课程1成绩降序排序后:"<< endl;
    for(QList<students>::iterator iter = student.begin(); iter != student.end(); ++iter){
        qDebug()<<(*iter).num<<" "<< (*iter).name<<" "<< (*iter).class1<< " "<< (*iter).class2 << endl;
    }
    std::sort(student.begin(),student.end(),sortclass2);
    qDebug()<< "按课程2成绩降序排序后:" << endl;
    for(QList<students>::iterator iter = student.begin(); iter != student.end(); ++iter){
        qDebug()<<(*iter).num<<" "<< (*iter).name<<" "<< (*iter).class1<< " "<< (*iter).class2 << endl;
    }
}
