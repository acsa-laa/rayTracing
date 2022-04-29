
#ifndef PARCER_H
#define PARCER_H

#include <string>
#include <iostream>
#include "tinyxml2.h"

struct ReadXML{
    std::string cameraType;
    //lista std::string film(Type, X_res, Y_res, Filename,Imgtype);
    //lista std::string background(Type, Mapping, Color, Bl, Br, Tl, Tr);
    std::string background;
} ReadXML;

class Parser{
public:
    static struct ReadXML parse(int argc, char* argv[]){
        if(argc < 2 or argc > 8){
            throw std::exception();
        }else{
            struct ReadXML ro;
            switch(argc){
                case 2:
                    if(strcmp(argv[1],"--help") == 0 or strcmp(argv[1],"--quick") == 0 or strcmp(argv[1],"--cropWindow") == 0 or strcmp(argv[1], "--outfile") == 0){
                        throw std::exception();
                    }else{
                        tinyxml2::XMLDocument doc;
                        doc.LoadFile(argv[1]);
                        auto RT3 = doc.RootElement();

                        ro.cameraType = RT3->FirstChildElement("camera")->Attribute("type");

                        auto background = RT3->FirstChildElement("background");
                        
                        if(background->Attribute("color")){
                            //ro.background[2] = background->Attribute("color");
                            
                        }else {
                            //ro.background[3] = background->Attribute("bl");
                        }
                        return ro;
                    }
                default:
                    break;
            }
        }
    }

    static void toString(const struct ReadXML& ro){
        std::cout << "cameraType;" << ro.cameraType << "\n" << std::endl;
    }
};

#endif //PARCER_H