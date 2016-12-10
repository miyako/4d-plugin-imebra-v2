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

/*! \file drawBitmap.h
    \brief Declaration of the class DrawBitmap.

*/

#if !defined(imebraDrawBitmap__INCLUDED_)
#define imebraDrawBitmap__INCLUDED_

#include <memory>
#include "definitions.h"
#include "readWriteMemory.h"

#ifndef SWIG
namespace imebra
{
namespace implementation
{
class drawBitmap;
}

}
#endif

namespace imebra
{

class Transform;
class Image;

///
/// \brief DrawBitmap takes care of converting an Image object into an array
///        of bytes that can be displayed by the operating system facilities.
/// 
/// DrawBitmap can apply several transformations to the Image before generating
/// the bitmap.
///
/// DrawBitmap applies automatically the necessary color transform and high
/// bit shift in order to obtain a 8 bits per channel RGB image.
/// 
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API DrawBitmap
{
    DrawBitmap(const DrawBitmap&) = delete;
    DrawBitmap& operator=(const DrawBitmap&) = delete;

public:
    /// \brief Construct a DrawBitmap with no transforms.
    /// 
    /// The getBitmap() method will not apply any Transform to the Image before
    /// generating the bitmap.
    /// 
    ///////////////////////////////////////////////////////////////////////////////
    DrawBitmap();

    /// \brief Construct a DrawBitmap object that always apply the transforms in
    ///        the specified TransformsChain before calculating the bitmap of the
    ///        Image in the getBitmap() method.
    ///
    /// \param transformsChain the transforms to apply to the Image in the
    ///        getBitmap() method
    ///
    ///////////////////////////////////////////////////////////////////////////////
    DrawBitmap(const Transform& transformsChain);

    /// \brief Destructor
    ///
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~DrawBitmap();

    /// \brief Apply the transforms defined in the constructor (if any) to the
    ///        input image, then calculate an array of bytes containing a bitmap
    ///        that can be rendered by the operating system.
    ///
    /// \param image          the image for which the bitmap must be calculated
    /// \param drawBitmapType the type of bitmap to generate
    /// \param rowAlignBytes  the number of bytes on which the bitmap rows are
    ///                       aligned
    /// \param destination    a pointer to the pre-allocated buffer where
    ///                       getBitmap() will store the generated bitmap
    /// \param destinationSize the size of the allocated buffer
    /// \return the number of bytes occupied by the bitmap in the pre-allocated
    ///         buffer. If the number of occupied bytes is bigger than the value
    ///         of the parameter bufferSize then the method doesn't generate
    ///         the bitmap
    ///
    ///////////////////////////////////////////////////////////////////////////////
    size_t getBitmap(const Image& image, drawBitmapType_t drawBitmapType, std::uint32_t rowAlignBytes, char* destination, size_t destinationSize);

    /// \brief Apply the transforms defined in the constructor (if any) to the
    ///        input image, then calculate an array of bytes containing a bitmap
    ///        that can be rendered by the operating system.
    ///
    /// \param image          the image for which the bitmap must be calculated
    /// \param drawBitmapType the type of bitmap to generate
    /// \param rowAlignBytes  the number of bytes on which the bitmap rows are
    ///                       aligned
    /// \return a ReadWriteMemory object referencing the buffer containing the
    ///         generated bitmap
    ///
    ///////////////////////////////////////////////////////////////////////////////
    ReadWriteMemory* getBitmap(const Image& image, drawBitmapType_t drawBitmapType, std::uint32_t rowAlignBytes);

#ifndef SWIG
protected:
    std::shared_ptr<implementation::drawBitmap> m_pDrawBitmap;
#endif

};

}

#endif // !defined(imebraDrawBitmap__INCLUDED_)
