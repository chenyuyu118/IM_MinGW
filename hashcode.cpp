#include "hashcode.h"
#include <QDateTime>

QString Hashcode::getHashCode(int length)
{
    // 字符集
    const char chrs[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$_+=";
    int chrs_size = sizeof(chrs);

    char* ch = new char[length + 1];
    memset(ch, 0, length + 1);
    int randomx = 0;
    for (int i = 0; i < length; ++i)
    {
        randomx= rand() % (chrs_size - 1);
        ch[i] = chrs[randomx];
    }

    QString ret(ch);
    delete[] ch;
    return ret;
}

Hashcode::Hashcode()
{

}
