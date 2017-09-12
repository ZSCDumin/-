#include<opencv2\core\core.hpp>
#include<opencv2\highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void onMouse(int event,int x,int y,int flags,void *param)
{
	if(event==CV_EVENT_LBUTTONDOWN)
	{
		Mat *pImag=(Mat *)param;
		if(pImag->channels()==1)
		{
			cout<<"ͼ���λ�����꣺"<<x <<"*"<<y <<",ͼ��ĻҶ�ֵ��"<<(int) pImag->at<uchar>(y,x) <<endl;
		}
		else if(pImag->channels()==3)
		{
			Vec3b p=pImag->at<Vec3b>(y,x);
			cout<<"ͼ���λ�����꣺"<<x <<"*"<<y <<",ͼ��ĻҶ�ֵ��"<<"R "<<(int) p[2]<<",G "<<(int) p[1]<<",B "<<(int) p[0] <<endl;
		}
	}

}

int main()
{
	Mat image,result;
	image= imread("puppy.jpg");
	if(image.empty())
	{
		cout<<"ͼ���ȡʧ�ܣ�"<<endl;
	}
	else
	{
		circle(image,Point(386, 325),300,0,3);
		putText(image,"I am not a dog!",Point(600, 592),FONT_HERSHEY_PLAIN,2.0,255,2);

		namedWindow("ԭʼͼ��");
		imshow("ԭʼͼ��",image);
		setMouseCallback("ԭʼͼ��",onMouse,&image);
		cout<< image.rows<<"*"<<image.cols<<endl;

		flip(image,result,2);
		imwrite("result.jpg",result);
		namedWindow("���ͼ��");
		imshow("���ͼ��",result);
		cout<< result.rows<<"*"<<result.cols<<endl;

	}
	waitKey(0);
	return 0;
}
