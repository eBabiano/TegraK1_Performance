/********************************************************************************
** Form generated from reading UI file 'ControlPanelWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANELWIDGET_H
#define UI_CONTROLPANELWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlPanelWidget
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *playButton;
    QPushButton *stopButton;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *secLabel;
    QLabel *minLabel;
    QLabel *milLabel;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *ControlPanelWidget)
    {
        if (ControlPanelWidget->objectName().isEmpty())
            ControlPanelWidget->setObjectName(QStringLiteral("ControlPanelWidget"));
        ControlPanelWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(ControlPanelWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        playButton = new QPushButton(ControlPanelWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(playButton);

        stopButton = new QPushButton(ControlPanelWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(stopButton);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ControlPanelWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        secLabel = new QLabel(ControlPanelWidget);
        secLabel->setObjectName(QStringLiteral("secLabel"));

        gridLayout->addWidget(secLabel, 0, 3, 1, 1);

        minLabel = new QLabel(ControlPanelWidget);
        minLabel->setObjectName(QStringLiteral("minLabel"));

        gridLayout->addWidget(minLabel, 0, 1, 1, 1);

        milLabel = new QLabel(ControlPanelWidget);
        milLabel->setObjectName(QStringLiteral("milLabel"));

        gridLayout->addWidget(milLabel, 0, 5, 1, 1);

        label_5 = new QLabel(ControlPanelWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_6 = new QLabel(ControlPanelWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ControlPanelWidget);

        QMetaObject::connectSlotsByName(ControlPanelWidget);
    } // setupUi

    void retranslateUi(QWidget *ControlPanelWidget)
    {
        ControlPanelWidget->setWindowTitle(QApplication::translate("ControlPanelWidget", "Form", 0));
        playButton->setText(QApplication::translate("ControlPanelWidget", "PLAY", 0));
        stopButton->setText(QApplication::translate("ControlPanelWidget", "STOP", 0));
        label->setText(QApplication::translate("ControlPanelWidget", "Time:", 0));
        secLabel->setText(QApplication::translate("ControlPanelWidget", "00", 0));
        minLabel->setText(QApplication::translate("ControlPanelWidget", "00", 0));
        milLabel->setText(QApplication::translate("ControlPanelWidget", "00", 0));
        label_5->setText(QApplication::translate("ControlPanelWidget", ":", 0));
        label_6->setText(QApplication::translate("ControlPanelWidget", ":", 0));
    } // retranslateUi

};

namespace Ui {
    class ControlPanelWidget: public Ui_ControlPanelWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANELWIDGET_H
