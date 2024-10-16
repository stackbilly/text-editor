#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::onSaveActionClicked);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::onOpenActionClicked);
    connect(ui->actionExit_2, &QAction::triggered, this, &MainWindow::onExitActionClicked);
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::onNewActionClicked);
    connect(ui->actionUndo_2, &QAction::triggered, this, &MainWindow::onUndoActionClicked);
    connect(ui->actionCopy_2, &QAction::triggered, this, &MainWindow::onCopyActionClicked);
    connect(ui->actionCut_2, &QAction::triggered, this, &MainWindow::onCutActionClicked);
    connect(ui->actionPaste_2, &QAction::triggered, this, &MainWindow::onPasteActionClicked);
    connect(ui->actionRedo, &QAction::triggered, this, &MainWindow::onRedoActionTriggered);
    connect(ui->actionSelect_All, &QAction::triggered, this, &MainWindow::onSelectAllActionTriggered);
    connect(ui->actionFind, &QAction::triggered, this, &MainWindow::onFindActionTriggered);
    connect(ui->actionClear, &QAction::triggered, this, &MainWindow::onClearActionTriggered);
    connect(ui->actionPrint, &QAction::triggered, this, &MainWindow::onPrintActionTriggered);
    connect(ui->actionZoom_in, &QAction::triggered, this, &MainWindow::onZoomInActionTriggered);
    connect(ui->actionZoom_out, &QAction::triggered, this, &MainWindow::onZoomOutActionTriggered);
    connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::onSaveAsActionTriggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveFile(const QString& filename, const QString& text)
{
    QFile file(filename);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << text;
        file.close();
        this->setWindowTitle(filename.split("/").last().append(" - TextEdit"));
    }
    else
    {
        QMessageBox::warning(this, "Error", "Failed to save file");
    }
}

void MainWindow::onSaveActionClicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);; All Files (*)");
    if(!fileName.isEmpty())
    {
        QString text = ui->textEditor->toPlainText();
        saveFile(fileName, text);
        QMessageBox::information(this, "Success", "File Saved Successfully!");
    }
}

void MainWindow::onOpenActionClicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");

    if(filename.isEmpty()) return;

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Cannot open file: "+file.errorString());
        return;
    }
    QTextStream in(&file);
    ui->textEditor->clear();
    ui->textEditor->setText(in.readAll());
    this->setWindowTitle(filename.split("/").last().append(" - TextEdit"));

    file.close();
}

void MainWindow::onExitActionClicked()
{
    if(this->windowTitle() == "TextEdit" && !ui->textEditor->toPlainText().isEmpty())
    {
        if(QMessageBox::question(this, "TextEdit", "Do you want to save changes to Untitled?")
            == QMessageBox::No)
        {
            this->close();
        }
        else
        {
            QString filename = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)");
            if(!filename.isEmpty())
            {
                QString text = ui->textEditor->toPlainText();
                saveFile(filename, text);
                this->close();
            }
        }
    }
    if(this->windowTitle() != "TextEdit")
    {
        QString title = this->windowTitle().split("-").first();
        if(QMessageBox::question(this, "TextEdit", "Do you want to save the changes to "+title)
            == QMessageBox::No)
        {
            this->close();
        }
        else
        {
            QString filename = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);; All Files (*)");
            saveFile(filename, ui->textEditor->toPlainText());
        }
    }
    this->close();
}

void MainWindow::onNewActionClicked()
{
    if(this->windowTitle() == "TextEdit" && ui->textEditor->toPlainText().isEmpty()) this->show();
    else if(this->windowTitle() == "TextEdit" && !ui->textEditor->toPlainText().isEmpty())
    {
        if(QMessageBox::question(this, "TextEdit", "Do you want to save changes to untitled?")
            == QMessageBox::No)
        {
            ui->textEditor->clear();
        }
        else
        {
            QString filename = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);; All Files (*)");
            saveFile(filename, ui->textEditor->toPlainText());
            this->close();
            this->show();
        }
    }
    else
    {
        this->close();
        this->show();
    }
}

void MainWindow::onUndoActionClicked()
{
    ui->textEditor->undo();
}

void MainWindow::onCopyActionClicked()
{
    ui->textEditor->copy();
}

void MainWindow::onCutActionClicked()
{
    ui->textEditor->cut();
}

void MainWindow::onPasteActionClicked()
{
    ui->textEditor->paste();
}

void MainWindow::onRedoActionTriggered()
{
    ui->textEditor->redo();
}

void MainWindow::onSelectAllActionTriggered()
{
    ui->textEditor->selectAll();
}

void MainWindow::onFindActionTriggered()
{
    ui->textEditor->find("", QTextDocument::FindWholeWords);
    qDebug() << ui->textEditor->find("", QTextDocument::FindWholeWords);
}

void MainWindow::onClearActionTriggered()
{
    ui->textEditor->clear();
}

void MainWindow::onPrintActionTriggered()
{
    QPrinter printer;

    QPrintDialog printDialog(&printer, this);
    printDialog.setWindowTitle("Print Document");
    if(printDialog.exec() == QDialog::Accepted && !ui->textEditor->toPlainText().isEmpty())
    {
        ui->textEditor->print(&printer);
    }
}

void MainWindow::onZoomInActionTriggered()
{
    ui->textEditor->zoomIn(10);
}

void MainWindow::onZoomOutActionTriggered()
{
    ui->textEditor->zoomOut(10);
}

void MainWindow::onSaveAsActionTriggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*txt);;All Files (*)");

    saveFile(filename, ui->textEditor->toPlainText());
}
