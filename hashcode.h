#ifndef HASHCODE_H
#define HASHCODE_H

#include <QString>

/**
 * @brief The Hashcode class
 * 产生一个固定长度的随机文件名（实际上并不是hash，是有概率重复的）
 */
class Hashcode
{
public:
    static QString getHashCode(int len);
    Hashcode();
};

#endif // HASHCODE_H
