//
// Created by 70386312419 on 12/05/2022.
//

#ifndef RT_PARCER_H
#define RT_PARCER_H

#include <string>
#include "tinyxml2.h"
#include <iostream>

struct RunningOptions{
    std::string cameraType;
    std::string filmType;
    std::string filmX_res;
    std::string filmY_res;
    std::string filmFilename;
    std::string filmImgtype;
    std::string backgroundType;
    std::string backgroundMapping;
    std::string backgroundColor;
    std::string backgroundBl;
    std::string backgroundBr;
    std::string backgroundTl;
    std::string backgroundTr;
} ;

class Parser{
public:
    static struct RunningOptions parse(){
        RunningOptions ro;
        const char *scene_file_name = "scene_01.xml";
        FILE * file = fopen(scene_file_name, "rt");
        if(file == nullptr){
            std::cout << scene_file_name << std::endl;
        }
        tinyxml2::XMLDocument doc;

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

    static void toString(const struct RunningOptions& ro){
        std::cout << "cameraType;" << ro.cameraType << "\n" <<
                  "filmType;\n" << ro.filmType << "\n" <<
                  "filmX_res;\n"<< ro.filmX_res << "\n" <<
                  "filmY_res;\n"<< ro.filmY_res << "\n" <<
                  "filmFilename;\n"<< ro.filmFilename << "\n" <<
                  "filmImgtype;\n"<< ro.filmImgtype << "\n" <<
                  "backgroundType;\n"<< ro.backgroundType << "\n" <<
                  "backgroundMapping;\n"<< ro.backgroundMapping << "\n" <<
                  "backgroundColor;\n"<< ro.backgroundColor << "\n" <<
                  "backgroundBl;\n"<< ro.backgroundBl << "\n" <<
                  "backgroundBr;\n"<< ro.backgroundBr << "\n" <<
                  "backgroundTl;\n"<< ro.backgroundTl << "\n" <<
                  "backgroundTr;"<< ro.backgroundTr << "\n" << std::endl;
    }
};

#endif //RT_PARCER_H