#include "mainwindow.h"
#include <QFormLayout>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QDebug>
#include <QMessageBox>
#include <QKeyEvent>
#include <QKeySequence>



MainWindow::MainWindow(Controller& c, QWidget *parent) :
    c(c), QWidget(parent) {
    setupUI();
    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddPressed);
}

MainWindow::~MainWindow() {
}

void MainWindow::setupUI() {
    this->resize(600, 400);
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QFormLayout *layout = new QFormLayout();
    artist = new QLineEdit(this);
    layout->addRow("Artist: ", artist);
    title = new QLineEdit(this);
    layout->addRow("Title: ", title);
    duration = new QLineEdit(this);
    layout->addRow("Duration: ", duration);
    type = new QComboBox(this);
    type->addItem("VIDEO");
    type->addItem("SONG");
    layout->addRow("Type: ", type);
    mainLayout->addLayout(layout);


    table = new QTableWidget(0, 4, this);
    table->setHorizontalHeaderLabels({"Artist", "Title", "Duration", "URL"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setSortingEnabled(true);
    mainLayout->addWidget(table);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    addButton = new QPushButton("Add");
    removeButton = new QPushButton("Remove");
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(removeButton);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
}

void MainWindow::onAddPressed() {
    qDebug() << "AddPressed";
    QString title1 = title->text();
    QString artist1 = artist->text();
    QString duration1 = duration->text();
    try {
        c.addItem("", title1.toStdString(), duration1.toInt(), artist1.toStdString());
    }catch(...) {
        QMessageBox::critical(this, "Error", QString("Error in adding item"));
    }

    populateTable();
}

void MainWindow::populateTable() {
    table->clearContents();
    for (int i = 0; i < c.getMediaRepository().size(); ++i) {
        table->insertRow(i);
        table->setItem(i, 0, new QTableWidgetItem(QString("Artist") + QString::number(i)));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(c.getMediaRepository()[i]->getTitle())));
        table->setItem(i, 2, new QTableWidgetItem(QString::number(c.getMediaRepository()[i]->getDuration())));
        table->setItem(i, 3, new QTableWidgetItem(""));
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    qDebug() << "keyPressEvent";
    QKeySequence sequence = event->modifiers() | event->key();
    if (sequence == QKeySequence::Undo) {
        qDebug() << "Key_Pressed";
    }
}
