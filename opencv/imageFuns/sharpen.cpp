/*
 * =====================================================================================
 *
 *       Filename:  sharpen2D.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/04/2013 07:44:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enali (Li), johnenali2011@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

void sharpen(const Mat& image, Mat& result)
{
    result.create(image.size(), image.type());
    Mat kernel(3, 3, CV_32F, Scalar(0));
    kernel.at<float>(1, 1) = 5;
    kernel.at<float>(0, 1) = -1;
    kernel.at<float>(1, 0) = -1;
    kernel.at<float>(1, 2) = -1;
    kernel.at<float>(2, 1) = -1;
    filter2D(image, result, image.depth(), kernel);
}
