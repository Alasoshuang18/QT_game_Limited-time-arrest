#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QDateTime>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Moveup();
    void Movedown();
    void Moveleft();
    void Moveright();

    void food_Moveup();
    void food_Movedown();
    void food_Moveleft();
    void food_Moveright();
    void UIchange();
    bool ck_collision();
    void reset();

private slots:
    //键盘事件槽函数
    void on_W_clicked();
    void on_S_clicked();
    void on_A_clicked();
    void on_D_clicked();

    //更新当前事件槽函数
    void curtime();

    //倒计时槽函数
    void Time_cntDown();

    //倒计时按键操作
    void on_start_clicked();

    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton *ball;
    QPushButton *food;
    QTimer *time;
    QTimer *countdown;

    int initnum = 50;

    void keyPressEvent(QKeyEvent *eve);
    void KeyReleaseEvent(QKeyEvent *re);

    void mousePressEvent(QMouseEvent *en);
    void mouseReleaseEvent(QMouseEvent *r);
    void mouseMoveEvent(QMouseEvent *m);
};
#endif // MAINWINDOW_H
