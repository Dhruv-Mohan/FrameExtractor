#include "Extractor.h"



Extractor::Extractor()
{
}

void Extractor::Load_configs()
{
	pugi::xml_document doc;
	doc.load_file("CONFIG.xml");
	auto Ext = doc.child("EXT");
	video_path = Ext.attribute("Video_path").as_string();
	output_dir = Ext.attribute("Output_dir").as_string();
	auto Framerate = Ext.attribute("Framerate").as_int();
	auto cap_inter = Ext.attribute("Capture_interval").as_float(); // capture interval in fraction second
	
	capture_interval = ceil(Framerate * cap_inter);

}


void Extractor::Extract_frames()
{


//OPEN Video via path
auto Video = cv::VideoCapture(video_path.c_str());
cv::Mat frame;

while (Video.read(frame)) { //reading video frames

	if (frame_index % capture_interval == 0) {

		cv::imwrite(output_dir + std::to_string(frame_index) + ".jpg", frame); //Save frame

	}

	frame_index++; //Update frame index 

}

}

Extractor::~Extractor()
{
}
