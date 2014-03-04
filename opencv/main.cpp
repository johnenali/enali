/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/03/2013 09:03:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enali (Li), johnenali2011@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "imageFuns.hpp"
#include "ImageConfig.h"
using namespace cv;

int main(int argc, char* argv[])
{
    //for (int i = 1; i < argc; i++) {
        Mat image = imread(argv[1]);
//Mat logo = imread(argv[2]);
        Mat result = image.clone();
        //Mat imageRIO = result(Rect(350, 80, logo.cols, logo.rows));
        //addWeighted(imageRIO, 0.5, logo, 0.9, 0., imageRIO);

        //添加函数处理
       // salt(image, 3000);
        colorReduce(image, result, 64);
        //sharpen(image, result);

        //进行结果显示
        //ColorDect cdect;
        //Mat image = imread(argv[1]);
        //if (!image.data) {
        //    return 0;
        //}
        //cdect.setColorTarget(130, 190, 230);
        //Mat result = cdect.process(image);
        namedWindow("Image_src");
        namedWindow("Image_dst");
        imshow("Image_src", image);
        imshow("Image_dst", result);
        waitKey(0);
    //}
    return 0;
}
