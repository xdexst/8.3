#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *nextbtn;
    QPushButton *backbtn;
    QLabel *aboutcar;
    QVBoxLayout *qvbl;

private slots:
    void nextCar();
    void backCar();
};

#endif
