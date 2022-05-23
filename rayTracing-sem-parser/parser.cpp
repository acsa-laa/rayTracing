//
// Created by 70386312419 on 12/05/2022.
//

#include <vector>
#include "parser.h"

struct RunningOptions Parser::parse() {
    RunningOptions ro;
    const char *scene_file_name = "scene_02.xml";

    tinyxml2::XMLDocument doc;

    if (doc.LoadFile(scene_file_name) != tinyxml2::XML_SUCCESS)
        std::cout << std::string{"The file "} + scene_file_name +
                     std::string{" either is not available OR contains an invalid RT3 scene provided!"} << std::endl;

    auto RT3 = doc.RootElement();

    ro.cameraType = RT3->FirstChildElement("camera")->Attribute("type");

    ro.filmType = RT3->FirstChildElement("film")->Attribute("type");
    try {
        ro.filmX_res = std::stoi(RT3->FirstChildElement("film")->Attribute("x_res"));
    } catch(std::exception& e) {
        std::cout<<"Unable to read x_res field in field tag from Scene File, setting to default value" << std::endl;
        ro.filmX_res = 800;
    }
    ro.filmY_res = std::stoi(RT3->FirstChildElement("film")->Attribute("y_res"));
    ro.filmFilename = RT3->FirstChildElement("film")->Attribute("filename");
    ro.filmImgtype = RT3->FirstChildElement("film")->Attribute("img_type");

    auto background = RT3->FirstChildElement("background");
    ro.backgroundType = background->Attribute("type");
    ro.backgroundMapping = background->Attribute("mapping");
    if (background->Attribute("color")) {
        std::string aux = background->Attribute("color");
        color color(0, 0, 0);
        char *token = std::strtok(const_cast<char *>(aux.c_str()), " ");
        int i = 0;
        while (token != nullptr) {
            try {
                color[i] = std::stoi(token);
                token = std::strtok(nullptr, " ");
                i++;
            } catch (std::exception &e) {
                std::cout << "Failed to convert color vector. Setting default value" << std::endl;
            }
        }
        ro.backgroundColor, ro.backgroundBl, ro.backgroundBr, ro.backgroundTl, ro.backgroundTr = color;

    } else {
        std::string auxbl = background->Attribute("bl"), auxbr = background->Attribute(
                "br"), auxtl = background->Attribute("tl"), auxtr = background->Attribute("tr");
        color bl(0, 0, 0), tl(0, 0, 0), br(0, 0, 0), tr(0, 0, 0);
        std::vector<std::string> tokensBl, tokensBr, tokensTl, tokensTr;
        std::stringstream sstreamBl(auxbl), sstreamBr(auxbr), sstreamTl(auxtl), sstreamTr(auxtr);
        std::string interBl, interBr, interTl, interTr;
        while (std::getline(sstreamBl, interBl, ' '))
            tokensBl.push_back(interBl);
        while (std::getline(sstreamBr, interBr, ' '))
            tokensBr.push_back(interBr);
        while (std::getline(sstreamTl, interTl, ' '))
            tokensTl.push_back(interTl);
        while (std::getline(sstreamTr, interTr, ' '))
            tokensTr.push_back(interTr);
        for (int i = 0; i < 3; i++) {
            try {
                bl[i] = std::stoi(tokensBl[i]);
                br[i] = std::stoi(tokensBr[i]);
                tl[i] = std::stoi(tokensTl[i]);
                tr[i] = std::stoi(tokensTr[i]);
            } catch (std::exception &e) {
                std::cout << "Unable to process colors, setting default color" << std::endl;
                return ro;
            }
        }
        ro.backgroundBl = bl;
        ro.backgroundBr = br;
        ro.backgroundTl = tl;
        ro.backgroundTr = tr;
    }
    return ro;
};