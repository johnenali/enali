/*
 * =====================================================================================
 *
 *       Filename:  sharpen.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/04/2013 06:11:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enali (Li), johnenali2011@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <opencv2/core/core.hpp>
using namespace cv;
void sharpen(const Mat &image, Mat &result)
{
    result.create(image.size(), image.type());
    int nl = image.rows;
    int nc = image.cols;
    int pxsz = image.elemSize();
    for (int i = 1; i < nl-1; i++) {
        const uchar* cur = image.ptr<const uchar>(i);
        const uchar* pre = image.ptr<const uchar>(i - 1);
        const uchar* nxt = image.ptr<const uchar>(i + 1);
        uchar* out = result.ptr<uchar>(i);
        for (int j = 1; j < (nc - 1)*pxsz; j++) {
                out[j] = saturate_cast<uchar>(
                     5 * cur[j] - cur[j-pxsz] - cur[j+pxsz] - pre[j] - nxt[j]);
        }
    } 
    /* :TODO:11/04/2013 07:37:52 PM:Li:  如何处理单通道。及Scalar的统一变量*/
    result.row(0).setTo(Scalar(0, 0, 0));
    result.row(nl-1).setTo(Scalar(0, 0, 0));
    result.col(0).setTo(Scalar(0, 0, 0));
    result.col(nc-1).setTo(Scalar(0, 0, 0));
}
