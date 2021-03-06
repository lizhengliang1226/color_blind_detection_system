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
    connect(ui->btn_next, SIGNAL(clicked()), this, SLOT(onClickNextPic()));
    //连接”上一张“按钮，当按下时播放上一张图片
    connect(ui->btn_prev, SIGNAL(clicked()), this, SLOT(onClickPrevPic()));
    //连接”获取结果“按钮，当按下时获取测试的结果
    connect(ui->btn_confirm, SIGNAL(clicked()), this, SLOT(onClickGetResult()));
    //连接三个答案按钮，当按下时获取到答案并保存
    connect(ui->btn_a, SIGNAL(clicked()), this,SLOT(onClickA()));
    connect(ui->btn_b, SIGNAL(clicked()), this,SLOT(onClickB()));
    connect(ui->btn_c, SIGNAL(clicked()), this,SLOT(onClickC()));
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
    index = 0;
    //设置开始点为(0,0);
    start_point=QPoint();
    //设置切换标志位为false
    img_chang=false;
    //设置图片自动缩放，这样可以填满整个区域，防止因为图片的大小不同而使得显示的区域不相同
    ui->test_img->setScaledContents(true);
    //设置显示第一张图片
    QPixmap first(images[index]);
    ui->test_img->setPixmap(first);
    //设置三个答案按钮的值为当前图片对应的答案
    setAnswerBtnValue();
    //设置三个答案按钮的样式为默认样式
    setAnswerBtnDefaultStyle();
    //设置问题编号
    setQId();
    //对结果集数组进行初始化，准备存储选择的结果
    resultsInit();
}

/*
设置三个答案按钮的值为当前图片所对应的答案
*/
void MainWindow::setAnswerBtnValue()
{
    ui->btn_a->setText("A."+answer[index][0]);
    ui->btn_b->setText("B."+answer[index][1]);
    ui->btn_c->setText("C."+answer[index][2]);
}

/*
设置三个答案按钮的样式为默认样式，即未选中状态
*/
void MainWindow::setAnswerBtnDefaultStyle()
{
    ui->btn_a->setStyleSheet(defaultStyle);
    ui->btn_b->setStyleSheet(defaultStyle);
    ui->btn_c->setStyleSheet(defaultStyle);
}

/*
设置题目的序号
*/
void MainWindow::setQId()
{
    QString str;
    str.sprintf("%d/15题",index+1);
    ui->label_show->setText(str);
}

/*
设置答案按钮的样式，当点击上一张和下一张按钮时
判断是不是已经答过的题目，若是，则把答案按钮的样式设置为选中状态
*/
void MainWindow::setAnswerBtnStyle()
{
    if(results[index]!="")
    {
        for(int i=0;i<3;i++)
        {
            if(answer[index][i]==results[index])
            {
                if(i==0)
                {
                    setAnswerBtnDefaultStyle();
                    ui->btn_a->setStyleSheet(selectedStyle);
                }else if(i==1)
                {
                    setAnswerBtnDefaultStyle();
                    ui->btn_b->setStyleSheet(selectedStyle);
                }else{
                    setAnswerBtnDefaultStyle();
                    ui->btn_c->setStyleSheet(selectedStyle);
                }
                break;
            }
        }
    }else{
        setAnswerBtnDefaultStyle();
    }
}

/*
”下一张“按钮的槽函数，当按下下一张按钮时，调用这个函数
*/
void MainWindow::onClickNextPic()
{

    if(index>=14) QMessageBox::information(this,"提示信息","已经是最后一题了！");
    else index++;
    QPixmap nextp(images[index]);
    ui->test_img->setPixmap(nextp);
    setAnswerBtnStyle();
    setAnswerBtnValue();
    setQId();
}
/*
”上一张“按钮的槽函数，当按下上一张按钮时，调用这个函数
*/
void MainWindow::onClickPrevPic()
{
    if(index<=0) QMessageBox::information(this,"提示信息","这是第一道题！");
    else index--;
    QPixmap prevp(images[index]);
    ui->test_img->setPixmap(prevp);
    setAnswerBtnStyle();
    setAnswerBtnValue();
    setQId();
}
/*
获取结果 按钮的槽函数
当按下获取结果按钮，调用这个函数，获取测试的结果并提示给用户
*/
void MainWindow::onClickGetResult()
{
    for(int i=0;i<15;i++)
    {
        if(results[i]==""){
            QMessageBox::warning(this,"提示信息","请答完所有题目再获取结果!");
            return;
        }
    }
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
    systemInit();
    //生成提示信息，并通过信息框提示给用户测试的结果
    QString str;
    str.sprintf("这是你的测试结果,你的测试分数为：%d分",sum);
    QMessageBox::information(this,"色盲测试结果",str);
}
//当A答案被按下的函数
void MainWindow::onClickA()
{
    setAnswerBtnDefaultStyle();
    ui->btn_a->setStyleSheet(selectedStyle);
    results[index]=answer[index][0];
}
//当B答案被按下的函数
void MainWindow::onClickB()
{
    setAnswerBtnDefaultStyle();
    ui->btn_b->setStyleSheet(selectedStyle);
    results[index]=answer[index][1];
}
//当C答案被按下的函数
void MainWindow::onClickC()
{
    setAnswerBtnDefaultStyle();
    ui->btn_c->setStyleSheet(selectedStyle);
    results[index]=answer[index][2];
}

/*
鼠标按下函数
当鼠标按下，记录按下的位置，然后判断是否在图片区域内
若是则置标志位为真
*/
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //获取label所在矩形区域
    QRect rect=ui->test_img->frameRect();
    //坐标平移，使鼠标和rect处于同一坐标系
    rect.translate(ui->test_img->pos());
    //判断鼠标点击的位置是否包含在矩形范围当中
    if(rect.contains(event->pos()))
    {
        //置切换为真，让图片可以切换
        img_chang=true;
        //保存开始点
        start_point=event->pos();
    }
}

/*
鼠标弹起函数
当鼠标弹起，记录相对位置去判断是向右滑还是向左滑
然后切换图片
*/
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    //当切换标志为真则进行切换操作
    if(img_chang)
    {
        //保存结束点
        QPoint end_point = event->pos();
        //开始点和结束点相减得到相对位置
        QPoint m_pos = end_point-start_point;
        //当x坐标小于0说明向左滑
        if(m_pos.x()<0)
        {
            //向左划相当于点击下一张
            onClickNextPic();
            //置标志位为false
            img_chang=false;
        }else if(m_pos.x()>=0)//大于0，右滑
        {
            //向右划相当于点击上一张
            onClickPrevPic();
            //切换后置标志位为false
            img_chang=false;
        }
    }

}

//结果数组初始化函数
void MainWindow::resultsInit()
{
    for(int i=0;i<15;i++)
    {
        results[i]="";
    }
}

