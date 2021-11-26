#ifndef MYDATABASE_H
#define MYDATABASE_H
#include <QtSql>

class MyDatabase
{
public:
    MyDatabase();
    MyDatabase(QString id);

private:
    QSqlDatabase DB;
    QSqlTableModel *msgs, *relations, *users;

    void initTable(); // 初始化表
public:
    void setFile(QString); // 为数据库设定对应文件
    void showAllUser(); // 显示所有用户
    void creatUser(QByteArray profile, QString id, QString username, QString pwd, QString gender, QString birthday); // 创建用户
    bool verifyUser(QString id, QString pwd); // 验证用户
    void showAllQuery(QSqlQuery &); // 显示语句执行的完全结果
};

#endif // MYDATABASE_H
