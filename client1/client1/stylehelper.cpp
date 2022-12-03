#include "stylehelper.h"



QString styleHelper::getStyleTextEdit()
{
    return "QTextEdit{"
           "border: 2px solid #4C2982;"
           "background-color: #202e42;"
           "font-family: Lucida Sans Typewriter;"
           "font-weight: bold;"
           "font-size: 11px;"
           "color: white;"
           "}"
           "QScrollBar:vertical {"
           "width: 3px;"
           "background: none;"
           "background-color:  #d0d2d4;"
           "}";
}

QString styleHelper::getStyleLineEdit()
{
    return "QLineEdit{"
           "border: 2px solid #4C2982;"
           "background-color: #202e42;"
           "font-family: Lucida Sans Typewriter;"
           "font-weight: bold;"
           "font-size: 11px;"
           "color: white;"
           "}"
           "QLineEdit:hover{"
           "border:2px solid #6a39b5;"
           "}";
}

QString styleHelper::getStylePushButton()
{
    return "QPushButton{"
           "background-color:#202e42;"
           "border: 2px solid #4C2982;"
           "border-radius: 5px;"
           "font-family: Lucida Sans Typewriter;"
           "color: white;"
           "font-size: 13px;"
           "}"
           "QPushButton:hover{"
           "background-color:#666666;"
           "border: 2px solid #6a39b5"
           "}"
           "QPushButton:pressed{"
           "background-color:#3a3a33;"
           "}";
}

QString styleHelper::getStyleLabel()
{
    return "QLabel{"
           "font-family: Lucida Sans Typewriter;"
           "color: white;"
           "font-size: 13px;"
           "font-weight: bold"
           "}";
}

QString styleHelper::getStyleLineEdit1()
{
    return "QLineEdit{"
           "background: #7e6f64;"
           "border: 2px solid #4a9893;"
           "font-family: Lucida Sans Typewriter;"
           "color: #e99dfb;"
           "font-size: 13px;"
           "font-weight: bold"
           "}"
           "QLineEdit:hover{"
           "border: 2px solid #1cc6c0"
           "}";
}

QString styleHelper::getStylePushButton1()
{
    return "QPushButton{"
           "background-color:#7e6f64;"
           "border: 2px solid #4a9893;"
           "border-radius: 5px;"
           "font-family: Lucida Sans Typewriter;"
           "color: white;"
           "font-size: 12px;"
           "height: 20px;"
           "}"
           "QPushButton:hover{"
           "background-color:#666666;"
           "}"
           "QPushButton:pressed{"
           "background-color:#3a3a33;"
           "}";
}
