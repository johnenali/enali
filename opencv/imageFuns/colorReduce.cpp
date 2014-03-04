/*
 * =====================================================================================
 *
 *       Filename:  colorReduce.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/04/2013 03:36:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enali (Li), johnenali2011@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <opencv2/core/core.hpp>
#include <math.h>

void colorReduce(const cv::Mat &image, cv::Mat &result, int div)
{
    result.create(image.size(), image.type());
    int nl = image.rows;
    int nc = image.cols;
    if (image.isContinuous()) {
        nc = nc * nl;
        nl = 1;
    }
    int n = static_cast<int>(log(static_cast<double>(div))/log(2.0));
    uchar mask = 0xff<<n;
    for (int j=0; j<nl; j++) {
        const uchar* data_src = image.ptr<const uchar>(j);
        uchar* data_dst = result.ptr<uchar>(j);
        for (int i=0; i<nc; i++){
            *data_dst++ = *data_src++ & mask + div/2;
            *data_dst++ = *data_src++ & mask + div/2;
            *data_dst++ = *data_src++ & mask + div/2;
        }
    }
}
