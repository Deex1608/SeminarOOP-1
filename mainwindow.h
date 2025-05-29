//
// Created by Deea on 29-May-25.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include "Controller.h"


class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(Controller& c, QWidget *parent = nullptr);
    ~MainWindow() override;
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void onAddPressed();


private:
    Controller& c;
    QPushButton *addButton;
    QPushButton *removeButton;
    QTableWidget *table;
    QComboBox *type;
    QLineEdit *title;
    QLineEdit *artist;
    QLineEdit *duration;

    void setupUI();
    void populateTable();
};


#endif //MAINWINDOW_H
