/********************************************************************************
** Form generated from reading UI file 'FaceDetectionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEDETECTIONWIDGET_H
#define UI_FACEDETECTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceDetectionWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *cpuRadioButton;
    QRadioButton *gpuRadioButton;

    void setupUi(QWidget *FaceDetectionWidget)
    {
        if (FaceDetectionWidget->objectName().isEmpty())
            FaceDetectionWidget->setObjectName(QStringLiteral("FaceDetectionWidget"));
        FaceDetectionWidget->resize(400, 300);
        gridLayout = new QGridLayout(FaceDetectionWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cpuRadioButton = new QRadioButton(FaceDetectionWidget);
        cpuRadioButton->setObjectName(QStringLiteral("cpuRadioButton"));

        horizontalLayout->addWidget(cpuRadioButton);

        gpuRadioButton = new QRadioButton(FaceDetectionWidget);
        gpuRadioButton->setObjectName(QStringLiteral("gpuRadioButton"));

        horizontalLayout->addWidget(gpuRadioButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(FaceDetectionWidget);

        QMetaObject::connectSlotsByName(FaceDetectionWidget);
    } // setupUi

    void retranslateUi(QWidget *FaceDetectionWidget)
    {
        FaceDetectionWidget->setWindowTitle(QApplication::translate("FaceDetectionWidget", "Form", 0));
        cpuRadioButton->setText(QApplication::translate("FaceDetectionWidget", "CPU", 0));
        gpuRadioButton->setText(QApplication::translate("FaceDetectionWidget", "GPU", 0));
    } // retranslateUi

};

namespace Ui {
    class FaceDetectionWidget: public Ui_FaceDetectionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEDETECTIONWIDGET_H
