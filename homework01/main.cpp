#include<QDebug>
#include<QList>
#include<QCoreApplication>

typedef quint32 word;
typedef quint8 byte;

#define i 0x12345678
#define _STR(s) #s
#define STR(s) _STR(s)
#define HHI(xxx) ((byte)(((word)(xxx)>>24)))
#define LHI(xxx) ((byte)(((word)(xxx)>>16)&0xFF))
#define HLI(xxx) ((byte)(((word)(xxx)>>8)&0xFF))
#define LLI(xxx) ((byte)(((word)(xxx)&0xFF)))
#define MAX(x,y) (((x)>(y))?(x):(y))
#define MIN(x,y) (((x)<(y))?(x):(y))

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"原始值："<<STR(i)<<"=="<<i;
    QList <quint8> Values;
    Values<<HHI(i)<<LHI(i)<<HLI(i)<<LLI(i);
    qDebug("0x%x==%d    0x%x==%d    0x%x==%d    0x%x==%d",Values.at(0),Values.at(0),
           Values.at(1),Values.at(1),Values.at(2),Values.at(2),Values.at(3),Values.at(3));
    qDebug("最高8位和次高8位最大值：0x%x<%d>",MAX(Values.at(0),Values.at(1)),MAX(Values.at(0),Values.at(1)));
    qDebug("次低8位和最低8位最大值：0x%x<%d>",MIN(Values.at(0),Values.at(1)),MIN(Values.at(2),Values.at(2)));

    int _i=(Values.at(2)<<24)+(Values.at(0)<<16)+(Values.at(3)<<8)+Values.at(1);
    qDebug("重新组合后数值：0x%x<%d>",_i,_i);
    qDebug()<<"排序前："<<Values;
    std::sort(Values.begin(),Values.end(),[](int x,int y){return x>y;});
    qDebug()<<"排序后："<<Values;
    return a.exec();
}
