#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
 
  /*VideoCapture cap("test.mp4");
  
  Mat vid;
  
  while(true){
  
  	cap.read(vid);
  	
  	imshow("Image", vid);
  	waitKey(1);*/ 
  
  
  /*Mat image;
  image = imread("index.jpeg" ,IMREAD_GRAYSCALE); // IMREAD_COLOR
  
  
  
  if(! image.data ) {
      cout <<  "Image not found or unable to open" << endl ;
      return -1;
    }
  
  namedWindow( "Techawarey:OpenCV Test Program", WINDOW_AUTOSIZE );
  imshow( "Techawarey:OpenCV Test Program", image );
  
  waitKey(0); // pas fermer tant qu 'on appui pas sur la croix de l'image
  return 0;*/
  
  int main(int argc, char* argv[])
  
{


    Mat image;
    image = imread("bad1.jpg" ); // IMREAD_COLOR
    Mat dst;
    Mat thr;
    Mat result;
    Mat new_;
    Mat edges;
    Mat res;
    imshow("image",image);
    
    cvtColor(image, new_ , COLOR_BGR2HSV,0);
    imshow("new",new_);
  
  cvtColor(image,dst, COLOR_BGR2GRAY,0);
  imshow("gray", dst);
  
  inRange(new_, Scalar(0,0,200), Scalar(120,120,255),thr);
  
  
  imshow("testtt", thr);
  
  Canny(thr,edges, 75, 175);
  imshow("edges", edges);
  
  cvtColor(edges,res, COLOR_GRAY2RGB);
  vector<Vec2f> lines;
  HoughLines(edges,lines,1, CV_PI/180, 150,0,0,0,CV_PI);
  
  for(size_t i=0; i<lines.size();i++)
  {
  	float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 1000*(-b));
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*(a));
        line( res, pt1, pt2, Scalar(0,0,255), 3, LINE_AA);
    }
  
  imshow(" res", res);
  
  
  /*if(! image.data ) {
      cout <<  "Image not found or unable to open" << endl ;
      return -1;
    }
  
  namedWindow( "Bad", WINDOW_AUTOSIZE );
  imshow( "Bad", image );
  
  waitKey(0); // pas fermer tant qu 'on appui pas sur la croix de l'image
  
  Mat image_X;
 
  Sobel(image, image_X, CV_8UC1, 1, 0);
  imshow("Sobel Image", image_X);
  waitKey(0);
  
  Mat image_Y;
  
  Sobel(image, image_Y, CV_8UC1, 0, 1);
  imshow("Sobel Image", image_Y);
  waitKey(0);
  
  Mat Sobel = image_X + image_Y;
  
  imshow("Sobel", Sobel);*/
  waitKey(0);
  
  
  
  
  
  return 0;
    
    
    
    /*VideoCapture cap("test.mp4");
  
  Mat vid;
  
  while(true){
  
  	cap.read(vid);
  	
  	imshow("Image", vid);
  	waitKey(1);*/
}



