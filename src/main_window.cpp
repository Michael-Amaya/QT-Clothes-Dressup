#include "main_window.h"
// #include <iostream>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
// #include <QDesktopWidget>

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent) {
    // Resize window
    this->resize(1080, 720);

    centralWidget = new QWidget(this);
    centralLayout = new QVBoxLayout(centralWidget);
    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);
    setupMainWindow();
}

void MainWindow::setupMainWindow() {
    // std::cout << "Hello world!" << std::endl;
    QLabel* label = new QLabel("Testing!", centralWidget);
    QPushButton* btn = new QPushButton("Submit", centralWidget);
    
    centralLayout->addWidget(label);
    centralLayout->addWidget(btn);
}