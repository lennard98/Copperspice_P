#include <QtCore>
#include <QtGui>
#include <iostream>

class MainWindow : public QWidget
{
private:
    //Anlegen der buttons
    QLineEdit   *display;
    QGridLayout *layout;
    QPushButton *button_add;
    QPushButton *button_equals;
    QPushButton *button_clear;
    QPushButton *button_str_pb;

    //Definition der Zahlen und Operationen
    double zahl_1;
    double zahl_2;
    double ergebnis;
    char operation;

    //Anlegen der Methoden (Funktionen in einer Klasse)
    void display_setText();
    void button_add_clicked();
    void button_equals_clicked();
    void button_clear_clicked();
    
public:
    MainWindow();
};

MainWindow::MainWindow()
{
    setMinimumSize(1000, 500);

    

    //Erstellen der Buttons
    
    
    button_add = new QPushButton("+", this);
    button_equals = new QPushButton("=",this);
    button_clear = new QPushButton("Löschen",this);
    
    
    display = new QLineEdit();

    //Layout der Buttons
    layout = new QGridLayout(this);
    layout->addWidget(display, 0, 1, 1, 3);
    layout->addWidget(button_clear, 0, 0);
    
    layout->addWidget(button_equals, 4, 2);
    layout->addWidget(button_add, 4, 3);
    

    setLayout(layout);

    //Verbinden der Buttons mit ihren Funktionen
    
    
    connect(button_add, &QPushButton::clicked, this, &MainWindow::button_add_clicked);
    connect(button_equals, &QPushButton::clicked, this, &MainWindow::button_equals_clicked);
    connect(button_clear, &QPushButton::clicked, this, &MainWindow::button_clear_clicked);
    connect(display, &QLineEdit::returnPressed, this, &MainWindow::display_setText);
    
}

//Funktionen der Buttons

void MainWindow::display_setText()
{
   bool ok;

   QString data = QInputDialog::getText(this, "string","Text",QLineEdit::Normal,QDir::home() .dirName(), &ok);

   if (ok && !data.isEmpty()){
    display->setText(data);
   } 
}

void MainWindow::button_add_clicked()
{
    zahl_1 = display->text().toDouble();
    operation = '+';
    display->clear();
}

void MainWindow::button_equals_clicked()
{
    zahl_2 = display->text().toDouble();

    if(operation == '+')
    {
        ergebnis = zahl_1 + zahl_2;
    }
    

    display->setText(QString::number(ergebnis));
}

void MainWindow::button_clear_clicked()
{
    display->clear();
    display->setText("0");
    zahl_1 = 0;
    zahl_2 = 0;
    ergebnis = 0;
}





int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow *window = new MainWindow();
    window->show();

    return app.exec();
}