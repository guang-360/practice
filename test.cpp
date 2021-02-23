#include<iostream>
using namespace std;

class Box{
    private:    
        int length;
        int width;
        int height;

    public:
        Box(int len, int wid, int hei); //构造函数声明
        ~Box(void);     //析构函数声明
        //设置长宽高
        void setLen(int len);
        void setWid(int wid);
        void setHei(int hei);

        int getVolume(void);    //体积
        void enLarge(int times);    //长宽高同时扩大至times倍
        int compare(Box box);   //若本box体积比
};

Box::Box(int len = 6, int wid = 6, int hei = 6){
    length = len;
    width = wid;
    height = hei;
}

Box::~Box(void){
    cout << "Object is being deleted." << endl;
}

void Box::setLen(int len){
    length = len;
}

void Box::setHei(int hei){
    height = hei;
}

void Box::setWid(int wid){
    width = wid;
}

int Box::getVolume(void){
    return length*width*height;
}

void Box::enLarge(int times){
    length *= times;
    width *= times;
    height *= times;
}

int Box::compare(Box box){
    return this->getVolume() > box.getVolume();
}


int main()
{
    Box box1, box2;
    double vol;
    box1.setLen(10);
    box1.setWid(8);
    box1.setHei(5);
    vol = box1.getVolume();
    cout << "box1's volume = " << vol << endl;
    box1.enLarge(2);
    cout << "after enlargement: " << box1.getVolume() << endl;
    cout << "box2's volume = " << box2.getVolume() << endl;
    if(box1.compare(box2))
    {
        cout << "box1 is larger than box2. " << endl;
    }
    else
    {
        cout << "box1 is not larger than box2. " << endl;
    }

    return 0;   
}