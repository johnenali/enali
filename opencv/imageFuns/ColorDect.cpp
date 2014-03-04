/*
 * =====================================================================================
 *
 *       Filename:  colorDect.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/04/2013 09:05:27 PM
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

class ColorDect {
    private:
        int minDist;
        Vec3b colorTarget;
        Mat result;
    public:
        ColorDect() :minDist(100) {
            colorTarget[0] = 0;
            colorTarget[1] = 0;
            colorTarget[2] = 0;
        }

        void setMinDist(int min) {
            minDist = min;
        }
        int getMinDist() {
            return minDist;
        }
        void setColorTarget(Vec3b color) {
            colorTarget = color;
        }
        void setColorTarget(uchar red, uchar green, uchar blue) {
            colorTarget[0] = blue;
            colorTarget[1] = green;
            colorTarget[2] = red;
        }
        Vec3b getColorTarget() {
            return colorTarget;
        }
        Mat process(const Mat& image) const {
            result.create(image.size(), CV_8U);

            Mat_<Vec3b>::const_iterator it = image.begin<Vec3b>();
            Mat_<Vec3b>::const_iterator itend = image.end<Vec3b>();
            Mat_<uchar>::iterator itout = result.begin<uchar>();

            for (; it != itend; ++it, ++itout) {
                dist = static_cast<int>(norm<int, 3>(
                            Vec3i(*it[0] - colorTarget[0],
                                *it[1] - colorTarget[1],
                                *it[2] - colorTarget[1])));
                if (dist < minDist) {
                    *itout = 255;
                }
                else {
                    *itout = 0;
                }
            }
            return result;
        }

};
