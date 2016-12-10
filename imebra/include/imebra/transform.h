/*

Imebra 4.0.7.1 changeset 108a911a22e1

Imebra: a C++ Dicom library

Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016
by Paolo Brandoli/Binarno s.p.

All rights reserved.

This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License version 2 as published by
 the Free Software Foundation.

This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

-------------------

If you want to use Imebra commercially then you have to buy the commercial
 license available at http://imebra.com

After you buy the commercial license then you can use Imebra according
 to the terms described in the Imebra Commercial License.
A copy of the Imebra Commercial License is available at http://imebra.com.

Imebra is available at http://imebra.com

The author can be contacted by email at info@binarno.com or by mail at
 the following address:
 Binarno s.p., Paolo Brandoli
 Rakuseva 14
 1000 Ljubljana
 Slovenia



*/

/*! \file transform.h
    \brief Declaration of the base class for transforms.

*/

#if !defined(imebraTransform__INCLUDED_)
#define imebraTransform__INCLUDED_

#include <memory>
#include "definitions.h"

#ifndef SWIG

namespace imebra
{
namespace implementation
{
namespace transforms
{
class transform;
}
}
}
#endif

namespace imebra
{

class Image;

///
/// \brief Represents a transform: a transform takes one Image as input,
///        processes it and outputs the processed Image.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API Transform
{
    Transform(const Transform&) = delete;
    Transform& operator=(const Transform&) = delete;

#ifndef SWIG
    friend class TransformsChain;
    friend class DrawBitmap;
    friend class ColorTransformsFactory;
    friend class TransformHighBit;
    friend class ModalityVOILUT;
    friend class VOILUT;

private:
    Transform(std::shared_ptr<imebra::implementation::transforms::transform> pTransform);
#endif


public:

    virtual ~Transform();

    /// \brief Returns true if the transform doesn't perform any processing
    ///        (the output image will be identical to the input one).
    ///
    /// \return true if the Transform doesn't perform any processing
    ///
    ///////////////////////////////////////////////////////////////////////////////
    bool isEmpty() const;

    /// \brief Allocate an image ready to accomodate the result of the
    ///        image processing performed by the runTransform() method.
    ///
    /// \param inputImage the image that will be set as the input of the
    ///                   runTransform() method
    /// \param width      the width of the output image
    /// \param height     the height of the output image
    /// \return an image ready to be passed as outputImage to runTransform()
    ///
    ///////////////////////////////////////////////////////////////////////////////
    Image* allocateOutputImage(const Image& inputImage, std::uint32_t width, std::uint32_t height) const;

    /// \brief Run the processing function of the Transform.
    ///
    /// \param inputImage the image to use as input
    ///
	void runTransform(
            const Image& inputImage,
            std::uint32_t inputTopLeftX, std::uint32_t inputTopLeftY, std::uint32_t inputWidth, std::uint32_t inputHeight,
            Image& outputImage,
            std::uint32_t outputTopLeftX, std::uint32_t outputTopLeftY) const;

#ifndef SWIG
protected:
    std::shared_ptr<imebra::implementation::transforms::transform> m_pTransform;
#endif
};

}

#endif // imebraTransform__INCLUDED_
