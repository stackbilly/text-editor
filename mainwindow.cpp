#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentFilePath = "";

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
    connect(ui->actionFind_Sensitive, &QAction::triggered, this, &MainWindow::onFindSensitiveActionTriggered);
    connect(ui->actionFont, &QAction::triggered, this, &MainWindow::onFontActionTriggered);


    QShortcut* undoShortCut = new QShortcut(QKeySequence("Ctrl+Z"), this);
    connect(undoShortCut, &QShortcut::activated, ui->textEditor, &QTextEdit::undo);

    QShortcut* redoShortCut = new QShortcut(QKeySequence("Ctrl+Y"), this);
    connect(redoShortCut, &QShortcut::activated, ui->textEditor, &QTextEdit::redo);

    QShortcut* selectAllShortCut = new QShortcut(QKeySequence("Ctrl+L"), this);
    connect(selectAllShortCut, &QShortcut::activated, ui->textEditor, &QTextEdit::selectAll);

    QShortcut* saveShortcut = new QShortcut(QKeySequence("Ctrl+S"), this);
    connect(saveShortcut, &QShortcut::activated, this, &MainWindow::onSaveActionClicked);

    QShortcut* saveAsShortcut = new QShortcut(QKeySequence("Ctrl+Shift+S"), this);
    connect(saveAsShortcut, &QShortcut::activated, this, &MainWindow::onSaveAsActionTriggered);

    QShortcut* openShortcut = new QShortcut(QKeySequence("Ctrl+O"), this);
    connect(openShortcut, &QShortcut::activated, this, &MainWindow::onOpenActionClicked);

    QShortcut* printShortcut = new QShortcut(QKeySequence("Ctrl+P"), this);
    connect(printShortcut, &QShortcut::activated, this, &MainWindow::onPrintActionTriggered);

    QShortcut* exitShortcut = new QShortcut(QKeySequence("Ctrl+Q"), this);
    connect(exitShortcut, &QShortcut::activated, this, &MainWindow::onExitActionClicked);

    QShortcut* clearShortcut = new QShortcut(QKeySequence("Ctrl+Shift+C"), this);
    connect(clearShortcut, &QShortcut::activated, ui->textEditor, &QTextEdit::clear);

    QShortcut* zoomInShortCut = new QShortcut(QKeySequence("Ctrl++"), this);
    connect(zoomInShortCut, &QShortcut::activated, this, &MainWindow::onZoomInActionTriggered);

    QShortcut* zoomOutShortcut = new QShortcut(QKeySequence("Ctrl+-"), this);
    connect(zoomOutShortcut, &QShortcut::activated, this, &MainWindow::onZoomOutActionTriggered);

    QShortcut* findShortCut = new QShortcut(QKeySequence("Ctrl+F"), this);
    connect(findShortCut, &QShortcut::activated, this, &MainWindow::onFindActionTriggered);

    QShortcut* newShortCut = new QShortcut(QKeySequence("Ctrl+N"), this);
    connect(newShortCut, &QShortcut::activated, this, &MainWindow::onNewActionClicked);

    QShortcut* findSensitiveShortcut = new QShortcut(QKeySequence("Ctrl+F+S"), this);
    connect(findSensitiveShortcut, &QShortcut::activated, this, &MainWindow::onFindSensitiveActionTriggered);

    QShortcut* fontShortcut = new QShortcut(QKeySequence("Alt+F"), this);
    connect(fontShortcut, &QShortcut::activated, this, &MainWindow::onFontActionTriggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCurrentFilePath(const QString &filepath)
{
    this->currentFilePath = filepath;
    if(this->getCurrentFilePath().isEmpty())
    {
        this->setWindowTitle("StackEdit");
    }else
    {
        this->setWindowTitle(this->getCurrentFilePath().split("/").last() + " - StackEdit");
    }
}

QString MainWindow::getCurrentFilePath() const
{
    return this->currentFilePath;
}

void MainWindow::saveToFile(const QString& filepath, const QString& contents)
{
    if(filepath.isEmpty())
    {
        qDebug() << "Empty file path @ line 107";
        return;
    }
    if(!filepath.isEmpty())
    {
        QFile file(filepath);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, "StackEdit","Cannot open file for writing.");
            return;
        }
        QTextStream out(&file);
        out << contents;
        file.close();

        this->setCurrentFilePath(filepath);
    }
}

void MainWindow::onSaveActionClicked()
{   
    if(this->getCurrentFilePath().isEmpty() && !ui->textEditor->toPlainText().isEmpty())
    {
        QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);; All Files (*)");
        if(!fileName.isEmpty())
        {
            QString text = ui->textEditor->toPlainText();
            saveToFile(fileName, text);
            QMessageBox::information(this, "StackEdit", "File saved successfully");
        }
    }
    if(this->getCurrentFilePath().isEmpty() && ui->textEditor->toPlainText().isEmpty())
    {
        QMessageBox::warning(this, "StackEdit", "Can't save an empty file");
    }
    if(!this->currentFilePath.isEmpty())
    {
        saveToFile(currentFilePath, ui->textEditor->toPlainText());
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
    this->setCurrentFilePath(filename);
    this->setWindowTitle(filename.split("/").last().append(" - StackEdit"));

    file.close();
}

void MainWindow::onExitActionClicked()
{
    if(this->getCurrentFilePath().isEmpty() && !ui->textEditor->toPlainText().isEmpty())
    {
        if(QMessageBox::question(this, "StackEdit", "Do you want to save changes to Untitled?")
            == QMessageBox::No)
        {
            this->setCurrentFilePath("");
            ui->textEditor->clear();
            this->close();
        }
        else
        {
            QString filename = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)");
            if(!filename.isEmpty())
            {
                QString text = ui->textEditor->toPlainText();
                saveToFile(filename, text);
                this->setCurrentFilePath("");
                ui->textEditor->clear();
                this->close();
            }
        }
    }
    if(!this->getCurrentFilePath().isEmpty())
    {
        QString title = this->windowTitle().split("-").first();
        if(QMessageBox::question(this, "StackEdit", "Do you want to save the changes to "+title)
            == QMessageBox::No)
        {
            this->setCurrentFilePath("");
            ui->textEditor->clear();
            this->close();
        }
        else
        {
            saveToFile(this->getCurrentFilePath(), ui->textEditor->toPlainText());
            this->setCurrentFilePath("");
            ui->textEditor->clear();
            this->close();
        }
    }
    else{
        this->setCurrentFilePath("");
        ui->textEditor->clear();
        this->close();
    }
}

void MainWindow::onNewActionClicked()
{
    if(this->getCurrentFilePath().isEmpty() && ui->textEditor->toPlainText().isEmpty()){
        this->show();
        this->setCurrentFilePath("");
    }
    if(this->getCurrentFilePath().isEmpty() && !ui->textEditor->toPlainText().isEmpty())
    {
        if(QMessageBox::question(this, "StackEdit", "Do you want to save changes to Untitled?")
            == QMessageBox::Yes)
        {
            QString filename = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);; All Files (*)");
            saveToFile(filename, ui->textEditor->toPlainText());
            this->setCurrentFilePath(filename);
            this->windowTitle() = "StackEdit";
            ui->textEditor->clear();
        }
        else
        {
            ui->textEditor->clear();
            this->windowTitle() = "StackEdit";
            this->setCurrentFilePath("");
        }
    }
    if(!this->getCurrentFilePath().isEmpty())
    {
        qDebug() << currentFilePath;
        saveToFile(this->getCurrentFilePath(), ui->textEditor->toPlainText());
        this->windowTitle() = "StackEdit";
        ui->textEditor->clear();
        this->setCurrentFilePath("");
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
    bool ok;
    QString key = QInputDialog::getText(this, "Find", "Enter value to find", QLineEdit::Normal, "", &ok);
    if(ok && !key.isEmpty()){
        bool found = ui->textEditor->find(key);
        if(!found)
        {
            ui->textEditor->moveCursor(QTextCursor::Start);
            found = ui->textEditor->find(key);
        }
        qDebug()<<found;
    }
    else
    {
        QMessageBox::information(this, "Information", "Task failed!");
    }
}

void MainWindow::onFindSensitiveActionTriggered()
{
    bool ok;
    QString key = QInputDialog::getText(this, "Find Case Sensitive",
                                        "Enter value to find", QLineEdit::Normal, "", &ok);
    if(ok && !key.isEmpty())
    {
        bool found = ui->textEditor->find(key, QTextDocument::FindCaseSensitively | QTextDocument::FindBackward);
        if(!found){
            ui->textEditor->moveCursor(QTextCursor::End);
            ui->textEditor->find(key, QTextDocument::FindCaseSensitively | QTextDocument::FindBackward);
        }
    }
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
    ui->textEditor->zoomIn();
}

void MainWindow::onZoomOutActionTriggered()
{
    ui->textEditor->zoomOut();
}

void MainWindow::onSaveAsActionTriggered()
{
    if(this->getCurrentFilePath().isEmpty() && ui->textEditor->toPlainText().isEmpty())
    {
        QMessageBox::warning(this, "StackEdit", "Cannot save an empty file");
        return;
    }
    if(!this->getCurrentFilePath().isEmpty() && ui->textEditor->toPlainText().isEmpty())
    {
        QString filename = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*txt);;All Files (*)");

        saveToFile(filename, ui->textEditor->toPlainText());
    }
    if(this->getCurrentFilePath().isEmpty() && !ui->textEditor->toPlainText().isEmpty())
    {
        QString filename = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*txt);;All Files (*)");

        saveToFile(filename, ui->textEditor->toPlainText());
    }
}


void MainWindow::onFontActionTriggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok)
        ui->textEditor->setFont(font);
}


void MainWindow::closeEvent(QCloseEvent* event)
{
    if(this->getCurrentFilePath().isEmpty() && ui->textEditor->toPlainText().isEmpty()) event->accept();
    if(this->getCurrentFilePath().isEmpty() && !ui->textEditor->toPlainText().isEmpty())
    {
        if(QMessageBox::question(this, "StackEdit", "Save changes made to Untitled?")
            ==QMessageBox::Yes)
        {
            QString filepath = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)");
            saveToFile(filepath, ui->textEditor->toPlainText());
            this->setCurrentFilePath("");
            event->accept();
        }else{
            event->accept();
        }
    }
    if(!this->getCurrentFilePath().isEmpty())
    {
        if(QMessageBox::question(this, "StackEdit", "Are you sure you want to exit?")
            == QMessageBox::Yes)
        {
            saveToFile(this->getCurrentFilePath(), ui->textEditor->toPlainText());
            qDebug() << "Data";
            event->accept();
        }else{
            event->ignore();
        }
    }
}
