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

/*! \file image.h
    \brief Declaration of the class Image.

*/

#if !defined(imebraImage__INCLUDED_)
#define imebraImage__INCLUDED_

#ifndef SWIG

#include <memory>
#include <string>
#include "definitions.h"
#include "readingDataHandlerNumeric.h"
#include "writingDataHandlerNumeric.h"

namespace imebra
{
namespace implementation
{
class image;
}
}
#endif

namespace imebra
{

class CodecFactory;
class Transform;
class VOILUT;
class DataSet;
class DrawBitmap;


///
/// \brief Represents a DICOM image.
///
/// The class manages an uncompressed DICOM image. Images are compressed
/// when they are inserted into the DataSet via DataSet::setImage() and are
/// decompressed when they are referenced by the Image class.
///
/// The image is stored in a contiguous area of memory: each channel's value
/// can occupy 1, 2 or 4 bytes, according to the Image's data type.
///
/// Channels' values are always interleaved in the Image class, regardless
/// of how they are stored in the DataSet object.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API Image
{
    Image(const Image&) = delete;
    Image& operator=(const Image&) = delete;

#ifndef SWIG
    friend class CodecFactory;
    friend class Transform;
    friend class VOILUT;
    friend class DataSet;
    friend class DrawBitmap;

private:
    Image(std::shared_ptr<imebra::implementation::image> pImage);
#endif

public:

    /// \brief Constructor.
    ///
    /// The memory for the image is not allocated by the constructor but only when
    /// a WritingDataHandler is requested with getWritingDataHandler().
    ///
    /// \param width      the image width, in pixels
    /// \param height     the image height, in pixels
    /// \param depth      the channel values data types
    /// \param colorSpace the Image's color space
    /// \param highBit    the highest bit occupied by the channels' values
    ///
    ///////////////////////////////////////////////////////////////////////////////
    Image(
        std::uint32_t width,
        std::uint32_t height,
        bitDepth_t depth,
        const std::string& colorSpace,
        std::uint32_t highBit);

    /// \brief Destructor.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~Image();

    /// \brief Retrieve the image's width, in millimiters
    ///
    /// \return the image's width, in millimiters
    ///
    ///////////////////////////////////////////////////////////////////////////////
    double getWidthMm() const;

    /// \brief Retrieve the image's height, in millimiters
    ///
    /// \return the image's height, in millimiters
    ///
    ///////////////////////////////////////////////////////////////////////////////
    double getHeightMm() const;

    /// \brief Set the image's size, in millimiters.
    ///
    /// \param width   the image's width, in millimiters
    /// \param height  the image's height, in millimiters
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void setSizeMm(double width, double height);

    /// \brief Retrieve the image's width, in pixels.
    ///
    /// \return the image's width, in pixels
    ///
    ///////////////////////////////////////////////////////////////////////////////
    std::uint32_t getWidth() const;

    /// \brief Retrieve the image's height, in pixels.
    ///
    /// \return the image's height, in pixels
    ///
    ///////////////////////////////////////////////////////////////////////////////
    std::uint32_t getHeight() const;

    /// \brief Retrieve a ReadingDataHandlerNumeric object referencing the Image's
    ///        memory (read only).
    ///
    /// The memory referenced by ReadingDataHandlerNumeric contains all the image's
    /// values. The color channels are interleaved.
    ///
    /// \return a ReadingDataHandlerNumeric object referencing the Image's memory
    ///         in read-only mode
    ///
    ///////////////////////////////////////////////////////////////////////////////
    ReadingDataHandlerNumeric* getReadingDataHandler() const;

    /// \brief Retrieve a WritingDataHandlerNumeric object referencing the Image's
    ///        memory (mutable).
    ///
    /// The memory referenced by the WritingDataHandlerNumeric object is
    /// uninitialized.
    ///
    /// When the WritingDataHandlerNumeric is destroyed then the memory managed
    /// by the WritingDataHandlerNumeric object replaces the old Image's memory.
    ///
    /// \return a WritingDataHandlerNumeric object referencing an uninitialized
    ///         memory buffer that the client has to fill the the image's data
    ///
    ///////////////////////////////////////////////////////////////////////////////
    WritingDataHandlerNumeric* getWritingDataHandler();

    /// \brief Retrieve the Image's color space
    ///
    /// \return the Image's color space
    ///
    ///////////////////////////////////////////////////////////////////////////////
    std::string getColorSpace() const;

    /// \brief Return the number of color channels contained by the image
    ///
    /// \return the number of color channel contained by the image
    ///
    ///////////////////////////////////////////////////////////////////////////////
    std::uint32_t getChannelsNumber() const;

    /// \brief Return the type of the channels' values.
    ///
    /// \return the type of the channels' values
    ///
    ///////////////////////////////////////////////////////////////////////////////
    bitDepth_t getDepth() const;

    /// \brief Return the highest bit occupied by the channels' values.
    ///
    /// \return the highest bit occupied by the channels' values
    ///
    ///////////////////////////////////////////////////////////////////////////////
    std::uint32_t getHighBit() const;

#ifndef SWIG
protected:
    std::shared_ptr<implementation::image> m_pImage;
#endif

};

}

#endif // !defined(imebraImage__INCLUDED_)
