#pragma once
#include"pugixml.hpp"
#include<opencv2\core.hpp>
#include<opencv2\video.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgcodecs.hpp>
#include<opencv2\imgproc.hpp>
#include<math.h>

class Extractor
{
public:
	Extractor();
	void Load_configs();
	void Extract_frames();
	~Extractor();
private:
	std::string video_path;
	std::string output_dir ="";
	std::string prefix;
	int frame_index = 0;
	int frame_rate = 0;
	int capture_interval = 0;
};

