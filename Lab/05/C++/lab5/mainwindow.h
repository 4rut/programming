#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <array>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void loadImage();
    void saveImage();
    void encodeMsg();
    void decodeMsg();
    void msgChanged();

private:
    QImage img;
    bool isImgLoaded = false;
    size_t bytes;
    size_t imgBytes=0;
    const std::array<char, 3> marker {
            static_cast<char>(0b11100010),
            static_cast<char>(0b10011101),
            static_cast<char>(0b10100100)
        };
};

#endif // MAINWINDOW_H
