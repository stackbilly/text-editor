/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHelps;
    QAction *actionNew;
    QAction *actionNew_Window;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionSend_Feedback;
    QAction *actionAbout_TextEdit;
    QAction *actionExit;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionView_Feedback;
    QAction *actionGetFeedback;
    QAction *actionAbout_Text_Edit;
    QAction *actionZoom_in;
    QAction *actionZoom_out;
    QAction *actionRestore_default_zoom;
    QAction *actionUndo_2;
    QAction *actionCut_2;
    QAction *actionCopy_2;
    QAction *actionPaste_2;
    QAction *actionDelete_2;
    QAction *actionPrint;
    QAction *actionExit_2;
    QAction *actionWord_count;
    QAction *actionFont;
    QAction *actionRedo;
    QAction *actionFind;
    QAction *actionClear;
    QAction *actionSelect_All;
    QAction *actionFind_Sensitive;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEditor;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuFormat;
    QMenu *menuView;
    QMenu *menuHelp;
    QMenu *menuZoom;
    QMenu *menuHelp_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        actionHelps = new QAction(MainWindow);
        actionHelps->setObjectName("actionHelps");
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        actionNew_Window = new QAction(MainWindow);
        actionNew_Window->setObjectName("actionNew_Window");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave->setMenuRole(QAction::MenuRole::ApplicationSpecificRole);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName("actionSaveAs");
        actionSend_Feedback = new QAction(MainWindow);
        actionSend_Feedback->setObjectName("actionSend_Feedback");
        actionAbout_TextEdit = new QAction(MainWindow);
        actionAbout_TextEdit->setObjectName("actionAbout_TextEdit");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionExit->setCheckable(false);
        actionExit->setMenuRole(QAction::MenuRole::QuitRole);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName("actionCut");
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName("actionDelete");
        actionView_Feedback = new QAction(MainWindow);
        actionView_Feedback->setObjectName("actionView_Feedback");
        actionGetFeedback = new QAction(MainWindow);
        actionGetFeedback->setObjectName("actionGetFeedback");
        actionAbout_Text_Edit = new QAction(MainWindow);
        actionAbout_Text_Edit->setObjectName("actionAbout_Text_Edit");
        actionZoom_in = new QAction(MainWindow);
        actionZoom_in->setObjectName("actionZoom_in");
        actionZoom_out = new QAction(MainWindow);
        actionZoom_out->setObjectName("actionZoom_out");
        actionRestore_default_zoom = new QAction(MainWindow);
        actionRestore_default_zoom->setObjectName("actionRestore_default_zoom");
        actionUndo_2 = new QAction(MainWindow);
        actionUndo_2->setObjectName("actionUndo_2");
        actionCut_2 = new QAction(MainWindow);
        actionCut_2->setObjectName("actionCut_2");
        actionCopy_2 = new QAction(MainWindow);
        actionCopy_2->setObjectName("actionCopy_2");
        actionPaste_2 = new QAction(MainWindow);
        actionPaste_2->setObjectName("actionPaste_2");
        actionDelete_2 = new QAction(MainWindow);
        actionDelete_2->setObjectName("actionDelete_2");
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName("actionPrint");
        actionExit_2 = new QAction(MainWindow);
        actionExit_2->setObjectName("actionExit_2");
        actionWord_count = new QAction(MainWindow);
        actionWord_count->setObjectName("actionWord_count");
        actionFont = new QAction(MainWindow);
        actionFont->setObjectName("actionFont");
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName("actionFind");
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName("actionClear");
        actionSelect_All = new QAction(MainWindow);
        actionSelect_All->setObjectName("actionSelect_All");
        actionFind_Sensitive = new QAction(MainWindow);
        actionFind_Sensitive->setObjectName("actionFind_Sensitive");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        textEditor = new QTextEdit(centralwidget);
        textEditor->setObjectName("textEditor");
        textEditor->setStyleSheet(QString::fromUtf8("border: none;\n"
""));

        verticalLayout->addWidget(textEditor);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuFormat = new QMenu(menuBar);
        menuFormat->setObjectName("menuFormat");
        menuView = new QMenu(menuBar);
        menuView->setObjectName("menuView");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        menuZoom = new QMenu(menuHelp);
        menuZoom->setObjectName("menuZoom");
        menuHelp_2 = new QMenu(menuBar);
        menuHelp_2->setObjectName("menuHelp_2");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuFormat->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuHelp_2->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionExit_2);
        menuFormat->addAction(actionRedo);
        menuFormat->addAction(actionUndo_2);
        menuFormat->addSeparator();
        menuFormat->addAction(actionCut_2);
        menuFormat->addAction(actionCopy_2);
        menuFormat->addAction(actionPaste_2);
        menuFormat->addSeparator();
        menuFormat->addAction(actionFind);
        menuFormat->addAction(actionFind_Sensitive);
        menuFormat->addAction(actionClear);
        menuFormat->addAction(actionSelect_All);
        menuView->addAction(actionWord_count);
        menuView->addAction(actionFont);
        menuHelp->addAction(menuZoom->menuAction());
        menuHelp->addAction(actionSend_Feedback);
        menuZoom->addSeparator();
        menuZoom->addAction(actionZoom_in);
        menuZoom->addAction(actionZoom_out);
        menuHelp_2->addAction(actionView_Feedback);
        menuHelp_2->addAction(actionGetFeedback);
        menuHelp_2->addAction(actionAbout_Text_Edit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "StackEdit", nullptr));
        actionHelps->setText(QCoreApplication::translate("MainWindow", "Helps", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New                                    Ctrl + N", nullptr));
        actionNew_Window->setText(QCoreApplication::translate("MainWindow", "New Window", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open                                  Ctrl + O", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save                                   Ctrl + S", nullptr));
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "Save As                             Ctrl + Shift + S", nullptr));
        actionSend_Feedback->setText(QCoreApplication::translate("MainWindow", "Status Bar", nullptr));
        actionAbout_TextEdit->setText(QCoreApplication::translate("MainWindow", "About TextEdit", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionCut->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        actionDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        actionView_Feedback->setText(QCoreApplication::translate("MainWindow", "View Help", nullptr));
        actionGetFeedback->setText(QCoreApplication::translate("MainWindow", "Get Feedback", nullptr));
        actionAbout_Text_Edit->setText(QCoreApplication::translate("MainWindow", "About Text Edit", nullptr));
        actionZoom_in->setText(QCoreApplication::translate("MainWindow", "Zoom in", nullptr));
        actionZoom_out->setText(QCoreApplication::translate("MainWindow", "Zoom out", nullptr));
        actionRestore_default_zoom->setText(QCoreApplication::translate("MainWindow", "Restore default zoom", nullptr));
        actionUndo_2->setText(QCoreApplication::translate("MainWindow", "Undo                                           Ctrl + Z", nullptr));
        actionCut_2->setText(QCoreApplication::translate("MainWindow", "Cut                                              Ctrl + X", nullptr));
        actionCopy_2->setText(QCoreApplication::translate("MainWindow", "Copy                                           Ctrl + C", nullptr));
        actionPaste_2->setText(QCoreApplication::translate("MainWindow", "Paste                                           Ctrl + V", nullptr));
        actionDelete_2->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        actionPrint->setText(QCoreApplication::translate("MainWindow", "Print                                  Ctrl + P", nullptr));
        actionExit_2->setText(QCoreApplication::translate("MainWindow", "Exit                                    Ctrl + Q", nullptr));
        actionWord_count->setText(QCoreApplication::translate("MainWindow", "Word count", nullptr));
        actionFont->setText(QCoreApplication::translate("MainWindow", "Font                    Alt + F", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo                                            Ctrl + Y", nullptr));
        actionFind->setText(QCoreApplication::translate("MainWindow", "Find                                            Ctrl + F", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "Clear                                          Ctrl + Shift + C", nullptr));
        actionSelect_All->setText(QCoreApplication::translate("MainWindow", "Select All                                   Ctrl + L", nullptr));
        actionFind_Sensitive->setText(QCoreApplication::translate("MainWindow", "Find Sensitive                           Ctrl + F + S", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuFormat->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "Format", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuZoom->setTitle(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        menuHelp_2->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
