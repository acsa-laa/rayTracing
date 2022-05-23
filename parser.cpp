//
// Created by marti on 11/05/2022.
//

#include "parser.h"

RunningOptions Parser::parse() {
    RunningOptions ro;
    tinyxml2::XMLDocument doc;
    const char *scene_file_name = "./scene_01.xml";
    std::cout << scene_file_name << std::endl;
    if ( doc.LoadFile( scene_file_name ) != tinyxml2::XML_SUCCESS )
        std::cout<< std::string{"The file "} + scene_file_name + std::string{" either is not available OR contains an invalid RT3 scene provided!"} << std::endl;

    auto RT3 = doc.RootElement();
    std::cout << "dhsudhuhdsu";
    ro.cameraType = RT3->FirstChildElement()->Attribute("type");

    ro.filmType = RT3->FirstChildElement("film")->Attribute("type");
    ro.filmY_res = RT3->FirstChildElement("film")->Attribute("y_res");
    ro.filmFilename = RT3->FirstChildElement("film")->Attribute("filename");
    ro.filmImgtype = RT3->FirstChildElement("film")->Attribute("img_type");
    ro.filmX_res = RT3->FirstChildElement("film")->Attribute("x_res");

    auto background = RT3->FirstChildElement("background");
    ro.backgroundType = background->Attribute("type");
    ro.backgroundMapping = background->Attribute("mapping");
    if (background->Attribute("color")) {
        ro.backgroundColor = background->Attribute("color");
    } else {
        ro.backgroundBl = background->Attribute("bl");
        ro.backgroundBr = background->Attribute("br");
        ro.backgroundTl = background->Attribute("tl");
        ro.backgroundTr = background->Attribute("tr");
    }
    return ro;
}


