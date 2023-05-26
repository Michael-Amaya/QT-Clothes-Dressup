#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    void setupMainWindow();
    QWidget* centralWidget;
    QVBoxLayout* centralLayout;
public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow() = default;
};