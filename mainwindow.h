#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void saveFile(const QString& filename, const QString& text);

private slots:
    void onSaveActionClicked();
    void onOpenActionClicked();
    void onExitActionClicked();
    void onNewActionClicked();
    void onUndoActionClicked();
    void onCutActionClicked();
    void onCopyActionClicked();
    void onPasteActionClicked();
    void onRedoActionTriggered();
    void onPrintActionTriggered();
    void onClearActionTriggered();
    void onFindActionTriggered();
    void onSelectAllActionTriggered();

private:
    Ui::MainWindow *ui;
    enum FileState{New,Open,Saved, UnSaved};
};
#endif // MAINWINDOW_H