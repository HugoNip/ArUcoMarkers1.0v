#include "opencv2/aruco.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

int main(int argc, char* argv[])
{
    // Basic Marker Detection
    cv::VideoCapture inputVideo;
    inputVideo.open(0);
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    while (inputVideo.grab()) {
        cv::Mat image, imageCopy;
        inputVideo.retrieve(image);
        image.copyTo(imageCopy);
        std::vector<int> ids;
        std::vector<std::vector<cv::Point2f> > corners;
        cv::aruco::detectMarkers(image, dictionary, corners, ids);
        // if at least one marker detected
        if (ids.size() > 0)
            cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
        cv::imshow("out", imageCopy);
        char key = (char) cv::waitKey(30);
        if (key == 27)
            break;
    }

    return 0;
}
