/*M///////////////////////////////////////////////////////////////////////////////////////
//
// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.
//
// Copyright (C) 2014, Itseez, Inc., all rights reserved.
// Third party copyrights are property of their respective owners.
//
//M*/

#ifndef _CAP_FFMPEG_HPP_
#define _CAP_FFMPEG_HPP_

#include "precomp.hpp"

namespace cv
{

class VideoCapture_FFMPEG :
    public IVideoCapture
{
public:

    VideoCapture_FFMPEG(const String& filename);
    virtual ~VideoCapture_FFMPEG() ;
    virtual double getProperty(int propId);
    virtual bool setProperty(int propId, double value);
    virtual bool goToFrame(int index);
    virtual int getFrameCount();
    virtual int getCurrentFrameIndex();
    virtual bool grabFrame();
    virtual bool retrieveFrame(int, OutputArray frame);
    virtual int getCaptureDomain() { return CAP_ANY; } // Return the type of the capture object: CAP_VFW, etc...

    bool isOpened() const;

protected:
    void* ffmpegCapture;
};

} // cv

#endif // _CAP_FFMPEG_HPP_
