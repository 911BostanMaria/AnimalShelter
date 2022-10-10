#include "GUI.h"
#include <vector>


GUI::GUI(Service &s , Repository &r , QWidget *parent): s{s} , r {r} {
    this -> initGui();
    this -> populate();
}

void GUI::initGui() {
    //window layout
    auto *layout = new QHBoxLayout(this);
    this->admin_data = new QListWidget{};
    this->admin_data->setSelectionMode(QAbstractItemView::SingleSelection);
    auto* allEventsLabel = new QLabel{ "All dogs" };
    auto* leftSide = new QWidget{};
    auto* leftLayout = new QVBoxLayout{leftSide};

    leftLayout->addWidget(allEventsLabel);
    leftLayout->addWidget(this->admin_data);

    auto* formLayout = new QWidget{};
    auto* eventLayout = new QFormLayout{ formLayout };

    this -> breedEdit = new QLineEdit();
    this -> nameEdit = new QLineEdit();
    this -> ageEdit = new QLineEdit();
    this -> linkEdit = new QLineEdit();


    QFont f("Script" , 10);
    auto *breedLabel = new QLabel("Breed: ");
    breedLabel ->setBuddy(this -> breedEdit);
    auto *nameLabel = new QLabel("Name: ");
    nameLabel ->setBuddy(this -> nameEdit);
    auto *ageLabel = new QLabel("Age ");
    ageLabel ->setBuddy(this -> ageEdit);
    auto *linkLabel = new QLabel("Link: ");
    linkLabel ->setBuddy(linkEdit);
    setWindowTitle("GUI Homework");

    breedLabel ->setFont(f);
    nameLabel-> setFont(f);
    ageLabel -> setFont(f);

    this -> breedEdit -> setFont(f);
    this -> nameEdit -> setFont(f);
    this -> ageEdit -> setFont(f);
    this -> linkEdit -> setFont(f);

    eventLayout -> addRow(breedLabel , this -> breedEdit);
    eventLayout -> addRow(nameLabel , this -> nameEdit);
    eventLayout -> addRow(ageLabel , this -> ageEdit);
    eventLayout ->addRow(linkLabel , this -> linkEdit);


    leftLayout ->addWidget(formLayout);

    auto* buttonsWidget = new QWidget{};
    auto* gridLayout = new QGridLayout{buttonsWidget};

    this -> add = new QPushButton("Add");
    this -> add ->setFont(f);
    this -> remove = new QPushButton("Remove");
    this -> remove ->setFont(f);
    this -> update = new QPushButton("Update");
    this -> update ->setFont(f);

    gridLayout ->addWidget(this -> add , 0 , 0);
    gridLayout ->addWidget(this -> remove , 0 , 1);
    gridLayout->addWidget(this->update, 0 ,2);
    // gridLayout ->addWidget(this ->filter , 0 , 0);


    leftLayout ->addWidget(buttonsWidget);
    layout ->addWidget(leftSide);


    auto *right = new QWidget();
    auto *rightLayout = new QVBoxLayout(right);

    this -> user_data = new QListWidget();
    this -> user_data ->setSelectionMode(QAbstractItemView::SingleSelection);
    auto *UserEvents = new QLabel("Dogs adopted by user: ");

    rightLayout ->addWidget(UserEvents);
    rightLayout ->addWidget(this -> user_data);

    auto *buttonsUser = new QWidget();
    auto *gridUser = new QGridLayout(buttonsUser);

    this -> addDog = new QPushButton("Add");
    this -> addDog ->setFont(f);
    this -> seeDogs = new QPushButton("See all dogs");
    this -> seeDogs ->setFont(f);

    gridUser ->addWidget(this -> addDog , 0 , 0);
    gridUser ->addWidget(this -> seeDogs , 0 , 1);

    rightLayout ->addWidget(buttonsUser);

    layout ->addWidget(right);


}

void GUI::populate() {
    this -> admin_data->clear();
    std::vector <Shelter> all = this -> s.getData();
    for(Shelter &e : all){
        std::string result = e.get_breed() + " " + e.get_name() +" "+ std::to_string(e.get_age()) + " "+ e.get_link();
        this -> admin_data ->addItem(QString ::fromStdString(result));
    }
}
