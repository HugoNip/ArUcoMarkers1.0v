#include "opencv2/aruco.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

int main(int argc, char* argv[])
{
    // Marker Creation
    cv::Mat markerImage;
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    cv::aruco::drawMarker(dictionary, 6, 200, markerImage, 1);
    cv::imwrite("../marker006.png", markerImage);

    return 0;
}