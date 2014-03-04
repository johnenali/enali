/*
 * =====================================================================================
 *
 *       Filename:  NavFunc.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/03/2013 09:34:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enali (Li), johnenali2011@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
void salt(cv::Mat &image, int n);
void colorReduce(const cv::Mat &image, cv::Mat &result, int div);
void sharpen(const cv::Mat &image, cv::Mat &result);
class colorDect;
