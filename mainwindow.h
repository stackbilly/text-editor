#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QShortcut>
#include <QDialog>
#include <QInputDialog>
#include <QFontDialog>
#include <QFont>
#include <QCloseEvent>

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
    // void saveFile(const QString& filename, const QString& text);
    void saveToFile(const QString& filepath, const QString& contents);
    void setCurrentFilePath(const QString &filepath);
    QString getCurrentFilePath() const;

protected:
    void closeEvent(QCloseEvent* event) override;

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
    void onZoomInActionTriggered();
    void onZoomOutActionTriggered();
    void onSaveAsActionTriggered();
    void onFindSensitiveActionTriggered();
    void onFontActionTriggered();

private:
    Ui::MainWindow *ui;
    QString currentFilePath;
};
#endif // MAINWINDOW_H
