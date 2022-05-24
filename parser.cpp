//
// Created by 70386312419 on 12/05/2022.
//

#include <vector>
#include "parser.h"
#include "sphere.h"

struct RunningOptions Parser::parse() {
    RunningOptions ro;
    const char *scene_file_name = "scene_04.xml";

    tinyxml2::XMLDocument doc;

    if (doc.LoadFile(scene_file_name) != tinyxml2::XML_SUCCESS)
        std::cout << std::string{"The file "} + scene_file_name +
                     std::string{" either is not available OR contains an invalid RT3 scene provided!"} << std::endl;

    auto RT3 = doc.RootElement();

    ro.cameraType = RT3->FirstChildElement("camera")->Attribute("type");
    if (std::strcmp(ro.cameraType.c_str(), "perspective") == 0) {
        try {
            ro.fovy = std::stoi(RT3->FirstChildElement("camera")->Attribute("fovy"));
        } catch (std::exception &e) {
            std::cout << "Unable to determine fovy. Setting to default" << std::endl;
        }
    } else if (std::strcmp(ro.cameraType.c_str(), "orthographic") == 0) {
        std::string sScreen_window = RT3->FirstChildElement("camera")->Attribute(
                "screen_window");
        const char *token = std::strtok(const_cast<char *>(sScreen_window.c_str()), " ");
        int i = 0;
        while (token != nullptr) {
            try {
                ro.screen_window[i] = std::stoi(token);
                token = std::strtok(nullptr, " ");
                i++;
            } catch (std::exception &e) {
                std::cout << "Unable to retrieve screen window coordinates. Setting to default."
                          << std::endl;
            }
        }
    }
    ro.filmType = RT3->FirstChildElement("film")->Attribute("type");
    try {
        ro.filmX_res = std::stoi(RT3->FirstChildElement("film")->Attribute("x_res"));
    } catch (std::exception &e) {
        std::cout
                << "Unable to read x_res field in field tag from Scene File, setting to default value"
                << std::endl;
        ro.filmX_res = 800;
    }
    try {
        ro.filmY_res = std::stoi(RT3->FirstChildElement("film")->Attribute("y_res"));
    } catch (std::exception &e) {
        std::cout
                << "Unable to read y_res field in field tag from Scene File, setting to default value"
                << std::endl;
        ro.filmY_res = 600;
    }
    ro.filmFilename = RT3->FirstChildElement("film")->Attribute("filename");
    ro.filmImgtype = RT3->FirstChildElement("film")->Attribute("img_type");

    auto background = RT3->FirstChildElement("background");
    ro.backgroundType = background->Attribute("type");
    if (background->Attribute("mapping"))
        ro.backgroundMapping = background->Attribute("mapping");
    else
        std::cout << "Unable to retrieve background mapping. Setting to default." << std::endl;
    if (background->Attribute("color")) {
        std::string aux = background->Attribute("color");
        color c(0, 0, 0);
        char *token = std::strtok(const_cast<char *>(aux.c_str()), " ");
        int i = 0;
        while (token != nullptr) {
            try {
                c[i] = std::stoi(token);
                token = std::strtok(nullptr, " ");
                i++;
            } catch (std::exception &e) {
                std::cout << "Failed to retrieve color vector. Setting to default value"
                          << std::endl;
            }
        }
        ro.backgroundColor = c;
        ro.backgroundBl = c;
        ro.backgroundBr = c;
        ro.backgroundTl = c;
        ro.backgroundTr = c;
    } else {
        std::string auxbl = background->Attribute("bl"), auxbr = background->Attribute(
                "br"), auxtl = background->Attribute("tl"), auxtr = background->Attribute("tr");
        color bl(0, 0, 0), tl(0, 0, 0), br(0, 0, 0), tr(0, 0, 0);
        std::vector<std::string> tokensBl, tokensBr, tokensTl, tokensTr;
        std::stringstream sstreamBl(auxbl), sstreamBr(auxbr), sstreamTl(auxtl), sstreamTr(
                auxtr);
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

    //Material
    if (RT3->FirstChildElement("material")) {
        if (RT3->FirstChildElement("material")->Attribute("type"))
            ro.materialType = RT3->FirstChildElement("material")->Attribute("type");
        else
            std::cout << "No material type retrieved. Setting to default" << std::endl;
        if (RT3->FirstChildElement("material")->Attribute("color")) {
            std::string aux = RT3->FirstChildElement("material")->Attribute("color");
            color c(0, 0, 0);
            char *token = std::strtok(const_cast<char *>(aux.c_str()), " ");
            int i = 0;
            while (token != nullptr) {
                try {
                    c[i] = std::stof(token);
                    token = std::strtok(nullptr, " ");
                    i++;
                } catch (std::exception &e) {
                    std::cout << "Failed to retrieve color vector. Setting to default value"
                              << std::endl;
                }
            }

            ro.materialColor = c;
        }
        //Objects
        if (RT3->FirstChildElement("object")) {
            auto object = RT3->FirstChildElement("object");
            while (object->NextSiblingElement() != nullptr) {
                std::string objectType;
                if (object->Attribute("type")) {
                    objectType = object->Attribute("type");
                } else {
                    std::cout << "Object type not defined. Creating sphere." << std::endl;
                    objectType = "sphere";
                }
                if (std::strcmp(objectType.c_str(), "sphere") == 0) {
                    double radius = 1;
                    point3 center(0, 0, 0);
                    if (object->Attribute("radius"))
                        radius = std::stod(object->Attribute("radius"));
                    else
                        std::cout << "No radius specified. Setting to default." << std::endl;
                    if (object->Attribute("center")) {
                        std::string aux = object->Attribute("center");
                        point3 p(0, 0, 0);
                        char *token = std::strtok(const_cast<char *>(aux.c_str()), " ");
                        int i = 0;
                        while (token != nullptr) {
                            try {
                                p[i] = std::stod(token);
                                token = std::strtok(nullptr, " ");
                                i++;
                            } catch (std::exception &e) {
                                std::cout
                                        << "Failed to retrieve sphere center. Setting to default value"
                                        << std::endl;
                            }
                        }
                        center = p;
                    } else {
                        std::cout << "Failed to retrieve sphere center. Setting to default values"
                                  << std::endl;
                    }
                    auto *s = new Sphere(center, radius, ro.materialColor);
                    ro.objects.push_back(s);
                }
                object = object->NextSiblingElement();
            }
        }
    }
        return ro;
    }
