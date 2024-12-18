#include "mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    connect(actionSave,SIGNAL(triggered(bool)),this,SLOT(saveFile()));
    connect(actionClose,SIGNAL(triggered(bool)),this,SLOT(close()));
}

MainWindow::~MainWindow() {}
void MainWindow::saveFile()
{
    // 彈出儲存檔案的對話框，讓使用者選擇檔案名稱和位置
    QString fileName = QFileDialog::getSaveFileName(this, tr("儲存檔案"), "", tr("Text Files (*.txt);;All Files (*)"));

    // 如果使用者取消儲存對話框，直接返回
    if (fileName.isEmpty()) {
        return;
    }

    // 嘗試打開指定的檔案
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("錯誤"), tr("無法打開檔案進行寫入：\n%1").arg(file.errorString()));
        return;
    }

    // 寫入 QTextEdit 的內容到檔案
    QTextStream out(&file);
    out << textEdit->toPlainText(); // 將 `textEdit` 的文字轉為純文字寫入
    file.close(); // 關閉檔案

    // 提示使用者檔案儲存成功
    QMessageBox::information(this, tr("成功"), tr("檔案已成功儲存至：\n%1").arg(fileName));
}
