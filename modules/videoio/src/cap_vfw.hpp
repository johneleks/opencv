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

#ifndef _CAP_VFW_HPP_
#define _CAP_VFW_HPP_

#include "precomp.hpp"

#ifdef HAVE_VFW

#include <vfw.h>

namespace cv
{

class CvCaptureAVI_VFW : public IVideoCapture
{
public:
    CvCaptureAVI_VFW(const String& filename);
    virtual ~CvCaptureAVI_VFW();

    virtual double getProperty(int);
    virtual bool setProperty(int, double);
    virtual bool grabFrame();
    virtual bool retrieveFrame(int, cv::OutputArray);
    virtual int getCaptureDomain() { return CV_CAP_VFW; } // Return the type of the capture object: CV_CAP_VFW, etc...
    virtual bool goToFrame(int index);

    bool isOpened() const;

protected:
    void init();
    void open();
    void close();

    String              filename;
    PAVIFILE            avifile;
    PAVISTREAM          avistream;
    PGETFRAME           getframe;
    AVISTREAMINFO       aviinfo;
    BITMAPINFOHEADER  * bmih;
    CvSlice             film_range;
    double              fps;
    int                 pos;
    IplImage*           frame;
    CvSize              size;
};


}

#endif //HAVE_VFW
#endif //_CAP_VFW_HPP_