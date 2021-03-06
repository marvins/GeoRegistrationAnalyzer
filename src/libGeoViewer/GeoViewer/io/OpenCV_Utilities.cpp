/**
 * @file    OpenCV_Utilities.cpp
 * @author  Marvin Smith
 * @date    6/3/2017
 */
#include "OpenCV_Utilities.hpp"


/*********************************************************/
/*          Convert OpenCV Depth Type to String          */
/*********************************************************/
std::string OpenCV_Depth_Type_To_String( const int& cv_type )
{
    switch(cv_type)
    {
        case CV_8UC1:
            return "CV_8UC1";
        case CV_8UC2:
            return "CV_8UC2";
        case CV_8UC3:
            return "CV_8UC3";
        default:
            return "UNKNOWN (value: " + std::to_string(cv_type) + ")";
    }
    return "UNKNOWN";
}
