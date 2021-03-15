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
  Canny(gray, edges, 200, 250, 3);

  Mat res;
  cvtColor(edges, res, COLOR_GRAY2BGR);

  Mat resP;
  resP = res.clone();


  vector<Vec4i> linesP;
  HoughLinesP(edges, linesP, 1, CV_PI/180, 50, 50, 10);

  for( size_t i = 0; i < linesP.size(); i++ )
  {
    Vec4i l = linesP[i];
    line( resP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, LINE_AA);
  }

  imshow("Detected Lines (in red) - Probabilistic Line Transform", resP);
  if (argc == 3)
    imwrite(argv[2], resP);


  /*Mat dst;
    Mat thr;
    Mat result;      // création des différentes images dont on va avoir besoin
    Mat new_;
    Mat edges;
    Mat res;
    imshow("image",image);   // affichage de la premiere image

    cvtColor(image, new_ , COLOR_BGR2HSV,0);// conversion de l'espace colorimétrique en HSV
    imshow("new",new_);

    cvtColor(image,dst, COLOR_BGR2GRAY,0); // image en niveau de gris
    imshow("gray", dst);

    inRange(new_, Scalar(0,0,200), Scalar(120,120,255),thr);  // filtrer la couleur blanche dans l'image HSV et stocker l'image résultat dans thr


    imshow("testtt", thr);   // affichage de l'image avec la couleur que l'on cherchait ( image bianire avec couleur que l'on recherche en blanc)

    Canny(thr,edges, 75, 175);  // a partir d'ici c est trouvé sur le net , détection de contour avec transformation de Hough, j ia juste testé, pas regarder comment sa fonctionne encore
    imshow("edges", edges);

    cvtColor(edges,res, COLOR_GRAY2RGB);
    vector<Vec2f> lines;
    HoughLines(edges,lines,1, CV_PI/180, 150,0,0,0,CV_PI);   // transformée de Hough pour détection de ligne dans l'image

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

    imshow(" res", res);*/
  waitKey(0);  // programme tourne tant que les images ne sont pas fermées

  return 0;
}
