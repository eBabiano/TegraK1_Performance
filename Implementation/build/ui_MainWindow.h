/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *modifyParametersLayout;
    QHBoxLayout *controlPanelLayout;
    QVBoxLayout *benchmarkLayout;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 540);
        MainWindow->setMinimumSize(QSize(780, 540));
        MainWindow->setMaximumSize(QSize(1024, 768));
        gridLayout_2 = new QGridLayout(MainWindow);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        modifyParametersLayout = new QGridLayout();
        modifyParametersLayout->setObjectName(QStringLiteral("modifyParametersLayout"));

        gridLayout_2->addLayout(modifyParametersLayout, 0, 2, 1, 1);

        controlPanelLayout = new QHBoxLayout();
        controlPanelLayout->setObjectName(QStringLiteral("controlPanelLayout"));

        gridLayout_2->addLayout(controlPanelLayout, 1, 2, 1, 1);

        benchmarkLayout = new QVBoxLayout();
        benchmarkLayout->setObjectName(QStringLiteral("benchmarkLayout"));

        gridLayout_2->addLayout(benchmarkLayout, 0, 0, 2, 2);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
