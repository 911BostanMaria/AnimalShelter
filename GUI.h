#pragma once
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <qwidget.h>
#include "Service.h"


class GUI: public QWidget {
Q_OBJECT;
public:
    GUI(Service &s , Repository &r , QWidget *parent = nullptr);
    ~GUI() override = default;
private:
    Repository &r;
    Service &s;
    std::vector <Shelter> shelter_list;
    QListWidget *admin_data;
    QListWidget *user_data;
    QListWidget *filtered;
    QLineEdit *breedEdit;
    QLineEdit *nameEdit;
    QLineEdit *ageEdit;
    QLineEdit *linkEdit;
    QPushButton *add;
    QPushButton *remove;
    QPushButton *update;
    QLineEdit *filter;
    QPushButton *addDog;
    QPushButton *removeDog;
    QPushButton *seeDogs;

    void initGui();
    void populate();
};
