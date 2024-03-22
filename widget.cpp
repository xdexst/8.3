#include "widget.h"
#include "machine.h"
#include <string>
#include <QMessageBox>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int i=0;
Machine cars[4];

Widget::Widget(QWidget *parent):QWidget(parent) {
    srand(time(NULL));
    for (int var = 0; var < 4; var++) {
        cars[var].X=25 + rand() % (99 - 25 + 1);
        cars[var].V=25 + rand() % (99 - 25 + 1);
        cars[var].P=25 + rand() % (99 - 25 + 1);
        std::cout << "[" << var << "]"
                  << " X= " << cars[var].X
                  << " V= " << cars[var].V
                  << " P= " << cars[var].P
                  << std::endl;
    }

    this->setFixedWidth(200);
    nextbtn = new QPushButton("Next");
    backbtn = new QPushButton("Back");
    aboutcar = new QLabel("Car " + QString::fromStdString(std::to_string(i+1)) + ": X="
                          + QString::fromStdString(std::to_string(cars[i].X))
                          + " V=" + QString::fromStdString(std::to_string(cars[i].V))
                          + " P=" + QString::fromStdString(std::to_string(cars[i].P))
                          + " [" + QString::fromStdString(std::to_string(i)) + "]");

    qvbl = new QVBoxLayout(this);
    qvbl->addWidget(aboutcar);
    qvbl->addWidget(nextbtn);
    qvbl->addWidget(backbtn);

    connect(nextbtn, &QPushButton::clicked, this, &Widget::nextCar);
    connect(backbtn, &QPushButton::clicked, this, &Widget::backCar);
}

Widget::~Widget() {}

void Widget::nextCar() {
    if(i+1>3) return;
    i++;
    aboutcar->setText("Car " + QString::fromStdString(std::to_string(i+1)) + ": X="
                      + QString::fromStdString(std::to_string(cars[i].X))
                      + " V=" + QString::fromStdString(std::to_string(cars[i].V))
                      + " P=" + QString::fromStdString(std::to_string(cars[i].P))
                      + " [" + QString::fromStdString(std::to_string(i)) + "]");
}

void Widget::backCar() {
    if(i-1<0) return;
    i--;
    aboutcar->setText("Car " + QString::fromStdString(std::to_string(i+1)) + ": X="
                      + QString::fromStdString(std::to_string(cars[i].X))
                      + " V=" + QString::fromStdString(std::to_string(cars[i].V))
                      + " P=" + QString::fromStdString(std::to_string(cars[i].P))
                      + " [" + QString::fromStdString(std::to_string(i)) + "]");
}
