#include <QApplication>
#include <QPushButton>
#include "Gui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repository r("readFrom");
    Service s(r);
    GUI g(s , r);
    g.show();
    return QApplication::exec();
}
