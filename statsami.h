#ifndef STATSAMI_H
#define STATSAMI_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class statsami;
}

class statsami : public QWidget
{
    Q_OBJECT

public:
    explicit statsami(QWidget *parent = nullptr);
    ~statsami();
    void makePolt();


private:
    Ui::statsami *ui;
};

#endif // STATSAMI_H
