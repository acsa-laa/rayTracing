//
// Created by marti on 11/05/2022.
//

#ifndef RAYTRACING_RUNNINGOPTIONS_H
#define RAYTRACING_RUNNINGOPTIONS_H

#include <iostream>

class RunningOptions{
public:
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
    const std::string &getCameraType() const {
        return cameraType;
    }

    void setCameraType(const std::string &cameraType) {
        RunningOptions::cameraType = cameraType;
    }

    const std::string &getFilmType() const {
        return filmType;
    }

    void setFilmType(const std::string &filmType) {
        RunningOptions::filmType = filmType;
    }

    const std::string &getFilmXRes() const {
        return filmX_res;
    }

    void setFilmXRes(const std::string &filmXRes) {
        filmX_res = filmXRes;
    }

    const std::string &getFilmYRes() const {
        return filmY_res;
    }

    void setFilmYRes(const std::string &filmYRes) {
        filmY_res = filmYRes;
    }

    const std::string &getFilmFilename() const {
        return filmFilename;
    }

    void setFilmFilename(const std::string &filmFilename) {
        RunningOptions::filmFilename = filmFilename;
    }

    const std::string &getFilmImgtype() const {
        return filmImgtype;
    }

    void setFilmImgtype(const std::string &filmImgtype) {
        RunningOptions::filmImgtype = filmImgtype;
    }

    const std::string &getBackgroundType() const {
        return backgroundType;
    }

    void setBackgroundType(const std::string &backgroundType) {
        RunningOptions::backgroundType = backgroundType;
    }

    const std::string &getBackgroundMapping() const {
        return backgroundMapping;
    }

    void setBackgroundMapping(const std::string &backgroundMapping) {
        RunningOptions::backgroundMapping = backgroundMapping;
    }

    const std::string &getBackgroundColor() const {
        return backgroundColor;
    }

    void setBackgroundColor(const std::string &backgroundColor) {
        RunningOptions::backgroundColor = backgroundColor;
    }

    const std::string &getBackgroundBl() const {
        return backgroundBl;
    }

    void setBackgroundBl(const std::string &backgroundBl) {
        RunningOptions::backgroundBl = backgroundBl;
    }

    const std::string &getBackgroundBr() const {
        return backgroundBr;
    }

    void setBackgroundBr(const std::string &backgroundBr) {
        RunningOptions::backgroundBr = backgroundBr;
    }

    const std::string &getBackgroundTl() const {
        return backgroundTl;
    }

    void setBackgroundTl(const std::string &backgroundTl) {
        RunningOptions::backgroundTl = backgroundTl;
    }

    const std::string &getBackgroundTr() const {
        return backgroundTr;
    }

    void setBackgroundTr(const std::string &backgroundTr) {
        RunningOptions::backgroundTr = backgroundTr;
    }
};

#endif //RAYTRACING_RUNNINGOPTIONS_H
