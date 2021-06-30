#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //系统初始化
    systemInit();
    //连接”下一张“按钮，当按下时播放下一张图片
    connect(ui->btn_next,SIGNAL(clicked()),this,SLOT(nextPic()));
    //连接”上一张“按钮，当按下时播放上一张图片
    connect(ui->btn_prev,SIGNAL(clicked()),this,SLOT(prevPic()));
    //连接”获取结果“按钮，当按下时获取测试的结果
    connect(ui->btn_confirm,SIGNAL(clicked()),this,SLOT(onEnter()));
    //连接三个答案按钮，当按下时获取到答案并保存
    connect(ui->btn_a,SIGNAL(clicked()),this,SLOT(setA()));
    connect(ui->btn_b,SIGNAL(clicked()),this,SLOT(setB()));
    connect(ui->btn_c,SIGNAL(clicked()),this,SLOT(setC()));
}



MainWindow::~MainWindow()
{
    delete ui;
}
/*
系统初始化函数
*/
void MainWindow::systemInit()
{
    //初始化索引为0，定位到第一张图片
    index=0;
    //设置图片自动缩放，这样可以填满整个区域，防止因为图片的大小不同而使得显示的区域不相同
    ui->test_img->setScaledContents(true);
    //设置显示第一张图片
    QPixmap start(images[index]);
    ui->test_img->setPixmap(start);
    //设置三个答案按钮的值为当前图片对应的答案
    setAnswer();
    //设置三个答案按钮的样式为默认样式
    setAnswerDefaultStyle();
    //对结果集数组进行初始化，准备存储选择的结果
    resultsInit();
}

/*
设置三个答案按钮的值为当前图片所对应的答案
*/
void MainWindow::setAnswer()
{
    ui->btn_a->setText("A."+answer[index][0]);
    ui->btn_b->setText("B."+answer[index][1]);
    ui->btn_c->setText("C."+answer[index][2]);
}

/*
设置三个答案按钮的样式为默认样式，即未选中状态
*/
void MainWindow::setAnswerDefaultStyle()
{
    ui->btn_a->setStyleSheet(defaultStyle);
    ui->btn_b->setStyleSheet(defaultStyle);
    ui->btn_c->setStyleSheet(defaultStyle);
}

/*
获取索引函数
获取当前图片的索引
flag-标志按下了哪一个按钮
1-按下了下一张按钮，0-按下了上一张按钮
*/
int MainWindow::getIndex(int flag)
{
    if(flag==1)
    {
        if(index>=14)
        index = 0;
        else
        index++;
        return index;
    }
    else
    {
        if(index<=0)
        index = 14;
        else
        index--;
        return index;
    }
}

/*
”下一张“按钮的槽函数，当按下下一张按钮时，调用这个函数
*/
void MainWindow::nextPic()
{
    setAnswerDefaultStyle();
    QPixmap nextp(images[getIndex(1)]);
    ui->test_img->setPixmap(nextp);
    setAnswer();
}
/*
”上一张“按钮的槽函数，当按下上一张按钮时，调用这个函数
*/
void MainWindow::prevPic()
{
    QPixmap prevp(images[getIndex(0)]);
    ui->test_img->setPixmap(prevp);
    setAnswer();
}
/*
获取结果 按钮的槽函数
当按下获取结果按钮，调用这个函数，获取测试的结果并提示给用户
*/
void MainWindow::onEnter()
{
    //通过results数组的结果，求出测试者的分数
    int sum=0;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<3;j++)
            {
            if(answer[i][j]==results[i])
            {
               sum+=j+3;
            }
        }
    }
    //生成提示信息，并通过信息框提示给用户测试的结果
    QString str;
    str.sprintf("这是你的测试结果,你的测试分数为：%d分",sum);
    QMessageBox::information(this,"色盲测试结果",str);
}
//当A答案被按下的函数
void MainWindow::setA()
{
    setAnswerDefaultStyle();
    ui->btn_a->setStyleSheet(selectedStyle);
    results[index]=answer[index][0];
}
//当B答案被按下的函数
void MainWindow::setB()
{
    setAnswerDefaultStyle();
    ui->btn_b->setStyleSheet(selectedStyle);
    results[index]=answer[index][1];
}
//当C答案被按下的函数
void MainWindow::setC()
{
    setAnswerDefaultStyle();
    ui->btn_c->setStyleSheet(selectedStyle);
    results[index]=answer[index][2];
}
//结果数组初始化函数
void MainWindow::resultsInit()
{
    for(int i=0;i<15;i++)
    {
        results[i]=" ";
    }
}

