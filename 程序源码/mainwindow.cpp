#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建小球
    ball = new QPushButton(ui->frame);
    ball->resize(20,20);
    ball->move(190,290);
    ball->setStyleSheet("background-color:rgb(100,100,100);"
                        "border-radius:5px;");

    //获取Ball的坐标
    ui->label_1->setText(QString::number(ball->x() / 20.0));
    ui->label_2->setText(QString::number(ball->y() / 20.0));
    qDebug() << "X:" << ball->x();
    qDebug() << "Y:" << ball->y();

    //在此我犯了一个严重错误，并不是ui->ball 而是我新建的这个对象已经在ui->frame里面了，直接用ball坐标就好


    //创建食物
    food = new QPushButton(ui->frame);
    food->resize(30,30);
    food->move(320,530);
    food->setStyleSheet("background-color:rgb(80,120,90);"
                        "border-radius:10px;"
                         );



    //鼠标初始化
    ui->centralwidget->setMouseTracking(true);
    ui->frame->setMouseTracking(true);
    //ball->setMouseTracking(true);



    //时钟初始化 (获取当前本机时间)
    time = new QTimer(this);
    connect(time, SIGNAL(timeout()), this, SLOT(curtime()));
    time->start(1000);

    //倒计时信号和槽函数连接
    countdown = new QTimer(this);
    connect(countdown,SIGNAL(timeout()),this,SLOT(Time_cntDown()));
    countdown->setInterval(1000);


    ui->label_4->setText("WoW");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_W_clicked()
{
    if(ball->y() < 20) return;
    else ball->move(ball->x(),ball->y() - 20);
    //在他移动之后更新坐标位置
    ui->label_1->setText(QString::number(ball->x() / 5.0));
    ui->label_2->setText(QString::number(ball->y() / 5.0));
}

void MainWindow::on_S_clicked()
{
    if(ball->y() > 560) return;
    else ball->move(ball->x(),ball->y() + 20);
    //在他移动之后更新坐标位置
    ui->label_1->setText(QString::number(ball->x() / 5.0));
    ui->label_2->setText(QString::number(ball->y() / 5.0));
}

void MainWindow::on_A_clicked()
{
    if(ball->x() < 20) return;
    else ball->move(ball->x() - 20,ball->y());
    //在他移动之后更新坐标位置
    ui->label_1->setText(QString::number(ball->x() / 5.0));
    ui->label_2->setText(QString::number(ball->y() / 5.0));
}

void MainWindow::on_D_clicked()
{
    if(ball->x() > 360) return;
    else ball->move(ball->x() + 20,ball->y());
    //在他移动之后更新坐标位置
    ui->label_1->setText(QString::number(ball->x() / 5.0));
    ui->label_2->setText(QString::number(ball->y() / 5.0));
}


//键盘事件
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Press" ;
    if(event->key() == Qt::Key_W)
        Moveup();
    else if(event->key() == Qt::Key_S)
        Movedown();
    else if(event->key() == Qt::Key_A)
        Moveleft();
    else if(event->key() == Qt::Key_D)
        Moveright();
    else if(event->key() == Qt::Key_O)
        UIchange();
    else if(event->key() == Qt::Key_I)
        food_Moveup();
    else if(event->key() == Qt::Key_K)
        food_Movedown();
    else if(event->key() == Qt::Key_J)
        food_Moveleft();
    else if(event->key() == Qt::Key_L)
        food_Moveright();

}
void MainWindow::KeyReleaseEvent(QKeyEvent *re)
{
    qDebug() << "release";
    if(re->key() == Qt::Key_1)
        Moveup();
    if(re->key() == Qt::Key_2)
        Movedown();
    if(re->key() == Qt::Key_3)
        Moveleft();
    if(re->key() == Qt::Key_4)
        Moveright();
}

void MainWindow::Moveup()
{
    if(ball->y() > 20)
        ball->move(ball->x(),ball->y() - 20);
    ui->label_1->setText(QString::number(ball->x() / 5.0));
    ui->label_2->setText(QString::number(ball->y() / 5.0));
}

void MainWindow::Movedown()
{
    if(ball->y() < 570)
        ball->move(ball->x(),ball->y() + 20);
    ui->label_1->setText(QString::number(ball->x() / 5.0));
    ui->label_2->setText(QString::number(ball->y() / 5.0));
}
void MainWindow::Moveleft()
{
    if(ball->x() > 20)
        ball->move(ball->x() - 20,ball->y());
    ui->label_1->setText(QString::number(ball->x() / 5.0));
    ui->label_2->setText(QString::number(ball->y() / 5.0));
}

void MainWindow::Moveright()
{
    if(ball->x() < 370)
        ball->move(ball->x() + 20,ball->y());
    ui->label_1->setText(QString::number(ball->x() / 5.0));
    ui->label_2->setText(QString::number(ball->y() / 5.0));
}

void MainWindow::food_Moveup()
{
    if(food->y() > 15)
        food->move(food->x(),food->y() - 20);

}

void MainWindow::food_Movedown()
{
    if(food->y() < 570)
        food->move(food->x(),food->y() + 20);

}
void MainWindow::food_Moveleft()
{
    if(food->x() > 15)
        food->move(food->x() - 20,food->y());

}

void MainWindow::food_Moveright()
{
    if(food->x() < 358)
        food->move(food->x() + 20,food->y());

}
void MainWindow::UIchange()
{
    ball->setText("hah");
    int num = qrand() % 4;
    switch(num)
    {
       case 0: ball->setText("oh");
            break;
       case 1: ball->setText("op");
            break;
       case 2: ball->setText("tr");
            break;
       case 3:ball->setText("ty");
            break;
    default: ball->setText("nb");
    }
}


//鼠标控件功能
void MainWindow::mousePressEvent(QMouseEvent *en)
{
    qDebug() << "Mouse Press";
    if(en->button() == Qt::RightButton)
        qDebug() << "Rightbutton";
    else if(en->button() == Qt::LeftButton)
        qDebug() << "Leftbutton";

}

void MainWindow::mouseReleaseEvent(QMouseEvent *r)
{
    qDebug() << "Mouse Realse";
    if(r->button() == Qt::MidButton)
        qDebug() << "MidButton";
}
void MainWindow::mouseMoveEvent(QMouseEvent *m)
{
    qDebug() << "Move sucesess";
    setMouseTracking(true);
    ui->pos->setText(QString::number(m->x()) + "," + QString::number(m->y()));
}

//更新当前时间
void MainWindow::curtime()
{
    QDateTime datetime = QDateTime::currentDateTime();
    ui->time->setText(datetime.toString("yyyy.MM.dd hh:mm:ss dddd"));
}

//倒计时功能实现
void MainWindow::Time_cntDown()
{
    int num = ui->lcdNumber->value();
    num -= 1;
    ui->lcdNumber->display(num);

    if(ck_collision())
    {
        ui->label_4->setText("Success");
        countdown->stop();
    }
    else if(num == 0 && !ck_collision())
        ui->label_4->setText("Please try again!");

}

void MainWindow::on_start_clicked()
{
    countdown->start(1000);
}

//通过用碰撞检测来 判断 是否相交
bool MainWindow::ck_collision()
{
    QRect ballRect = ball->geometry();
    QRect foodRect = food->geometry();

    return ballRect.intersects(foodRect);
}


void MainWindow::on_clear_clicked()
{
    reset();
}

//上面冗杂内容多，我直接把上面复位的放进函数中
void MainWindow::reset()
{
    ui->lcdNumber->display(initnum);
    ball->move(190,290);
    ui->label_4->setText("WoW");
    ui->label_1->setText(QString::number(ball->x() / 20.0));
    ui->label_2->setText(QString::number(ball->y() / 20.0));

    food->move(320,530);

}
