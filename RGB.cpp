#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void showColorspace(const Mat& image, const String& colorspaceName, int conversionCode) {
    Mat colorspace;
    cvtColor(image, colorspace, conversionCode);
    namedWindow(colorspaceName, WINDOW_NORMAL);
    imshow(colorspaceName, colorspace);
}

int main() {
    Mat image = imread("C:/Users/Nuta/Documents/Open CV/Практика 2/RGB.jpg");

    if (image.empty()) {
        cout << "Error" << endl;
        return -1;
    }

    namedWindow("Original", WINDOW_NORMAL);
    imshow("Original", image);

    showColorspace(image, "Grayscale", COLOR_BGR2GRAY);
    showColorspace(image, "HSV", COLOR_BGR2HSV);
    showColorspace(image, "Lab", COLOR_BGR2Lab);
    showColorspace(image, "YUV", COLOR_BGR2YUV);
    showColorspace(image, "YCrCb", COLOR_BGR2YCrCb);
    showColorspace(image, "XYZ", COLOR_BGR2XYZ);
    showColorspace(image, "HLS", COLOR_BGR2HLS);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
