//
// Created by marti on 11/05/2022.
//

#include "parser.h"

struct RunningOptions Parser::parse() {
    struct RunningOptions ro;
    tinyxml2::XMLDocument doc;
    doc.LoadFile("scene_01.xml");
    auto RT3 = doc.RootElement();
    if(RT3->FirstChildElement())

    ro.cameraType = RT3->FirstChildElement("camera")->Attribute("type");

    ro.filmType = RT3->FirstChildElement("film")->Attribute("type");
    ro.filmX_res = RT3->FirstChildElement("film")->Attribute("x_res");
    ro.filmY_res = RT3->FirstChildElement("film")->Attribute("y_res");
    ro.filmFilename = RT3->FirstChildElement("film")->Attribute("filename");
    ro.filmImgtype = RT3->FirstChildElement("film")->Attribute("img_type");

    auto background = RT3->FirstChildElement("background");
    ro.backgroundType = background->Attribute("type");
    ro.backgroundMapping = background->Attribute("mapping");
    if (background->Attribute("color")) {
        ro.backgroundColor = background->Attribute("color");
        ro.backgroundBl = background->Attribute("color");
        ro.backgroundBr = background->Attribute("color");
        ro.backgroundTl = background->Attribute("color");
        ro.backgroundTr = background->Attribute("color");
    } else {
        ro.backgroundBl = background->Attribute("bl");
        ro.backgroundBr = background->Attribute("br");
        ro.backgroundTl = background->Attribute("tl");
        ro.backgroundTr = background->Attribute("tr");
    }
    return ro;
}

void Parser::toString(const struct RunningOptions &ro) {
    {
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
}

