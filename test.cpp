#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
  if (argc < 2) {
    cerr << "Not enough arguments. Please use \"./output picture_name\"" << endl;
    return 1;
  }
  Mat image;
  image = imread(argv[1]);
  imshow("bad.jpg", image);

  Mat gray;
  cvtColor(image, gray, COLOR_BGR2GRAY);
  imshow("Image en niveau de gris", gray);

  Mat edges;
  Canny(gray, edges, 200, 250, 3); //CANNY best settings
  imshow("edges", edges);

  Mat res;
  cvtColor(edges, res, COLOR_GRAY2BGR);
  imshow("res", res);

  Mat resP;
  resP = res.clone();


  vector<Vec4i> linesP;
  HoughLinesP(edges, linesP, 1, CV_PI/180, 50, 50, 10); // HOUGHLINESP > HOUGHLINES

  for( size_t i = 0; i < linesP.size(); i++ )
  {
    Vec4i l = linesP[i];
    line( resP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, LINE_AA);
  }

  imshow("Detected Lines (in red) - Probabilistic Line Transform", resP);
  if (argc == 3)
    imwrite(argv[2], resP);

  waitKey(0);  // programme tourne tant que les images ne sont pas fermées

  return 0;
}
