/*
 * =====================================================================================
 *
 *       Filename:  func.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/03/2013 08:55:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enali (Li), johnenali2011@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <math.h>
#include <opencv2/core/core.hpp>

void salt(cv::Mat &image, int n)
{
    for (int k=0; k<n; k++)
    {
        int i = rand() % image.cols;
        int j = rand() % image.rows;
        if (image.channels() == 1)
        {
            image.at<uchar>(j, i) = 255;
        }
        else if (image.channels() == 3)
        {
            image.at<cv::Vec3d>(j, i)[0] = 255;
            image.at<cv::Vec3d>(j, i)[1] = 255;
            image.at<cv::Vec3d>(j, i)[2] = 255;
        }
    }
}
