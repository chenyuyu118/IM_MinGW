#include "mydatabase.h"
#include <QMessageBox>
#include <QFile>

MyDatabase::MyDatabase() {

}

MyDatabase::MyDatabase(QString name)
{
    DB = QSqlDatabase::addDatabase("QSQLITE"); // 设置引擎
    QFile file(name);
    DB.setDatabaseName(name); // 设置数据库名称
    if (!DB.open()) {
        // 数据库打开失败
        qDebug() << "数据库打开失败";


        //
    } else {
        initTable();
    }
}

void MyDatabase::initTable() {

    msgs = new QSqlTableModel(Q_NULLPTR, DB);
    relations = new QSqlTableModel(Q_NULLPTR, DB);
    users = new QSqlTableModel(Q_NULLPTR, DB);
    msgs->setTable("t_chatmsg");
    relations->setTable("t_user_relationship");
    users->setTable("t_user");

    msgs->setEditStrategy(QSqlTableModel::OnManualSubmit); // 设置更新策略为手动
    relations->setEditStrategy(QSqlTableModel::OnManualSubmit);
    users->setEditStrategy(QSqlTableModel::OnManualSubmit);

    if (!msgs->select()) {
        qDebug() << "消息数据表打开失败";
    }
    if (!relations->select())
        qDebug() << "关系数据表打开失败";

    if (!users->select())
        qDebug() << "用户数据表打开失败";
}

void MyDatabase::setFile(QString fileName)
{
    DB = DB.addDatabase("QSQLITE", "user");
    DB = DB.database("user");
    DB.setDatabaseName(fileName);
    if (DB.open()) {
        qDebug() << "打开成功";
        // qDebug() << DB.tables();
        if (DB.tables().length() == 0) {
            // 表为空，执行建表语句


            //
        }

    } else {
        qDebug() << "打开失败";  
    }
}


void MyDatabase::showAllUser()
{
    QSqlQueryModel queryMode;
    queryMode.setQuery("select * from t_user");
    for (int i = 0; i < queryMode.rowCount(); ++i) {
        QSqlRecord red = queryMode.record(i);
        QString s;
        for (int j = 0; j < red.count(); ++j) {
            s += red.value(j).toString() + "  ";
        }
        qDebug() << s;
    }
}

void MyDatabase::creatUser(QByteArray profile, QString id, QString username, QString pwd, QString gender, QString birthday)
{
    // 创建用户
    QSqlQuery query;
    query.prepare("insert into t_user(f_user_id, f_username, f_password, f_profile, f_gender, f_birthday) values (?, ?, ?, ?, ?, ?)");
    // query.bindValue(":id", id.toLongLong());
    query.bindValue(0, id.toLongLong());
    query.bindValue(1, username);
    query.bindValue(2, pwd);
    query.bindValue(3, profile);
    query.bindValue(4, gender);
    query.bindValue(5, birthday.toLongLong());
    query.exec();
    if (query.isActive())
        qDebug() << "执行成功";
    else {
        qDebug() << "失败";
        qDebug() << query.lastError();
    }
}

bool MyDatabase::verifyUser(QString id, QString pwd)
{
    QSqlQuery query;
    query.prepare("select *\
                  from t_user\
                  where f_user_id=:id and f_password=:pwd");
    query.bindValue(":id", id);
    query.bindValue(":pwd", pwd);
    query.exec();
    if (query.isActive())
    {
        qDebug() << "成功查询登陆";
        query.first();
        QSqlQueryModel queryMode;
        queryMode.setQuery(query);
        if (!queryMode.record().isNull("f_user_id")) {
            // 登陆成功

            // 查询个人信息
            query.prepare("select *\
                          from t_user\
                          where f_user_id = :id");
            query.bindValue(":id", id);
            query.exec();
            if (query.isActive()) {
                qDebug() << "查询个人信息成功";

            }

            // 查询好友列表
            query.prepare("select  f_user1_teamname groupName, f_user_id2 id, f_user1_markname nickName, tu.f_username name\
                          from t_user_relationship join t_user tu on t_user_relationship.f_user_id2 = tu.f_user_id\
                          where f_user_id1=:id1\
                          union\
                          select  f_user2_teamname groupName, f_user_id1 id, f_user2_markname nickName, tu.f_username name\
                          from t_user_relationship join t_user tu on t_user_relationship.f_user_id1 = tu.f_user_id\
                          where f_user_id2=:id2;");
            query.bindValue(":id1", id);
            query.bindValue(":id2", id);
            query.exec();
            if (query.isActive()) {
                qDebug() << "成功查询好友列表";
                query.first();
                queryMode.setQuery(query);
                for(int i = 0; i < queryMode.rowCount(); ++i) {
                    // 查询到好友的所有信息
                    QSqlRecord recd = queryMode.record(i);
                    QString groupName = recd.value("groupName").toString();
                    QString user_id = recd.value("id").toString();
                    QString nickName = recd.value("nickName").toString();
                    QString name = recd.value("name").toString();

                }
            }
        }

    } else {
        qDebug() << query.lastError();
    }
    return true;
}

void MyDatabase::showAllQuery(QSqlQuery &query)
{
    QSqlRecord red = query.record();
    for (int i = 0; i < red.count(); ++i) {
        qDebug() << red.value(i);
    }
}

