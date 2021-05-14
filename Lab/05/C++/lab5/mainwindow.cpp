#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QBitArray>
#include <QFile>
#include <QTextStream>

bool getBit(const QImage &img, int index) {
    int pixelIndex = index / 3;

    int x = pixelIndex % img.width();
    int y = pixelIndex / img.width();

#ifndef NDEBUG
    if (y >= img.height())
        throw std::out_of_range("индекс бита выходит за пределы картинки");
#endif

    //img.pixel returns #AARRGGBB
    switch (index % 3) {
    case 0:
        return (img.pixel(x, y) >> 16) & 1;
    case 1:
        return (img.pixel(x, y) >> 8) & 1;
    default:
        return img.pixel(x, y) & 1;
    }

    Q_UNREACHABLE();
}

void setBit(QImage &img, int index, bool val) {
    int pixelIndex = index / 3;

    int x = pixelIndex % img.width();
    int y = pixelIndex / img.width();

#ifndef NDEBUG
    if (y >= img.height())
        throw std::out_of_range("выходит за пределы картинки");
#endif

    switch (index % 3) {
    case 0:
        img.setPixel(x, y, (img.pixel(x, y) & ~0x010000) | (val << 16));
    case 1:
        img.setPixel(x, y, (img.pixel(x, y) & ~0x000100) | (val << 8));
    default:
        img.setPixel(x, y, (img.pixel(x, y) & ~0x000001) | val);
    }
}

void writeBytes(QImage& img, size_t begin, QByteArray& byteArray) {
    size_t end = (begin + byteArray.size()) * 8;

#ifndef NDEBUG
    if (static_cast<size_t>(img.width() * img.height() * 8 * 3) <= end)
        throw std::out_of_range("попытка записать биты вне картинки");
#endif

    for (size_t i = begin * 8; i < end; ++i) {
        setBit(img, i, (byteArray[i / 8] >> (7 - i % 8)) & 1);
    }
}

QByteArray readBytes(const QImage& img, size_t begin, size_t length) {
    QByteArray byteArray;
    char buf = 0;

    size_t end = (begin + length) * 8;

#ifndef NDEBUG
    if (static_cast<size_t>(img.width() * img.height() * 8 * 3) <= end)
        throw std::out_of_range("попытка прочитать биты вне картинки");
#endif

    for (size_t i = begin * 8; i < end; ++i) {
        buf = (buf << 1) | getBit(img, i);

        if (i % 8 == 7) {
            byteArray.push_back(buf);
            buf = 0;
        }
    }

    return byteArray;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::loadImage);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::saveImage);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::encodeMsg);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::decodeMsg);

    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::msgChanged);

    imgBytes = -1; // по-умолчанию размер картинки невалидный
    bytes = 0;

    isImgLoaded = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Допустимые форматы (*.png)"));

    if (!img.load(fileName, "PNG")) {
         isImgLoaded = false;

         ui->label->setText("Изображение не загружено");
         return;
      }

    img.convertTo(QImage::Format_ARGB32);

    ui->label->setText("Изображение загружено");
    isImgLoaded = true;
}

void MainWindow::saveImage()
{
    if (!isImgLoaded)
    {
        ui->label->setText("Изображение не загружено");
        return;
    }

    QString path = QFileDialog::getSaveFileName(this, tr("Сохранить картинку"), "", tr("Допустимые форматы (*.png)"));

    if (img.save(path, "PNG"))
    {
        ui->label->setText("Изображение успешно сохранено");
    }
    else
    {
        ui->label->setText("Изображение не сохранено");
    }

}

void MainWindow::encodeMsg()
{
    if (!isImgLoaded)
    {
        ui->label->setText("Изображение не загружено");
        return;
    }

    bytes = ui->plainTextEdit->toPlainText().toUtf8().size();

    if (imgBytes < bytes)
    {
            ui->label->setText("Ошибка. Не достаточно места!");
            return;
        }

    QByteArray byteArray;
    byteArray.push_back(marker);

    for (int i = 3; i >= 0; --i) {
            byteArray.push_back((bytes >> i*8) & 0xff);
        }

        byteArray.push_back(ui->plainTextEdit->toPlainText().toUtf8());

        writeBytes(img, 0, byteArray);

        ui->label->setText("Сообщение добавлено в картинку!");
}

void MainWindow::decodeMsg()
{
    if (!isImgLoaded) {
            ui->label->setText("Изображение не загружена в программу!");
            return;
        }

        int headerSize = marker.size() + 3;
        QByteArray byteArray;

        byteArray = readBytes(img, 0, headerSize);

        for (size_t i = 0; i < marker.size(); ++i) {
            if (marker[i] != byteArray[i]) {
                ui->label->setText("Сообщение не обнаружено");
                return;
            }
        }

        size_t messageSize = 0;
        for (size_t i = marker.size(); i < marker.size() + 3; i++) {
            messageSize = (messageSize << 8) + static_cast<unsigned char>(byteArray[i]);
        }

        if (messageSize > imgBytes) {
            ui->label->setText("Ошибка. Размер сообщения в заголовке превышает размер изображения");
            return;
        }

        byteArray = readBytes(img, headerSize, messageSize);

        QString text = QString::fromUtf8(byteArray);

        ui->plainTextEdit->setPlainText(text);

        ui->label->setText(tr("Присутствует сообщение длиной %1 байт").arg(messageSize));
}

void MainWindow::msgChanged()
{
    if (imgBytes < 0) return;
    bytes = ui->plainTextEdit->toPlainText().toUtf8().size();

    if (imgBytes < bytes) {
        ui->label->setText(tr("Размер сообщения превышен на: %1 байт").arg(bytes - imgBytes));
    }
    else
    {
        ui->label->setText(tr("Ещё можно ввести: %1 байт").arg(imgBytes- bytes));
    }
}
