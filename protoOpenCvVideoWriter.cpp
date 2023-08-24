// protoOpenCvVideoWriter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>


int main()
{
	using namespace std;
	

	cout << "Test openCV codecs and some frame sizes" << endl << endl;
	
	vector<string> availableCodec = { "DIVX", "XVID", /*"X264",*/ "WMV1", "WMV2", "FMP4",
				  "mp4v", /*"avc1",*/ "I420", "IYUV", "mpg1", /*"H264"*/ };

	vector<cv::Size> availableSizes;
	
	cv::Size sizeTypical(640, 480); availableSizes.push_back(sizeTypical);

	cv::Size sizeWide(320, 64); availableSizes.push_back(sizeWide);
	cv::Size sizeTall(1280, 16); availableSizes.push_back(sizeTall);


	string fileName = "D:/test.avi";

	for (auto& iterSize : availableSizes)
	{ 
		cout << "Testing image size: " << iterSize.width << "x" << iterSize.height << endl;

		for (auto& iterCodec : availableCodec)
		{
			const char* codec = iterCodec.c_str();
			int32_t fourCc = cv::VideoWriter::fourcc(codec[0], codec[1], codec[2], codec[3]);

			cv::VideoWriter cvVideoWriter = cv::VideoWriter::VideoWriter();
			if (cvVideoWriter.open(fileName, fourCc, 20, iterSize, false))
			{
				cout << " \t VideoWriter passed codec: " << iterCodec << endl;
				cvVideoWriter.release();
			}
			else
			{
				cout << " \t VideoWriter failed codec: " << iterCodec << endl;
			}
		}

		cout << endl;

	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
