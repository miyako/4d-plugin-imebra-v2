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

/*! \file colorTransformsFactory.h
    \brief Declaration of the class ColorTransformsFactory.

*/

#if !defined(imebraColorTransformsFactory__INCLUDED_)
#define imebraColorTransformsFactory__INCLUDED_

#include <string>
#include "transform.h"
#include "definitions.h"

namespace imebra
{

///
/// \brief ColorTransformsFactory has the knowledge about the color spaces
///        supported by the library: it can construct Transform objects
///        that transform images' content from one color space to another and
///        can return specific information about the supported color spaces.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API ColorTransformsFactory
{

public:

    /// \brief Normalize the name of a color space.
    ///
    /// DICOM color spaces may contain additional information like the subsampling
    /// factor.
    ///
    /// This method removes the additional information contained in the color space
    /// name and makes it upper-case, so it can be compared with other normalized
    /// color space names.
    ///
    /// \param colorSpace the color space name to normalize
    /// \return the normalized color space name
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static std::string normalizeColorSpace(const std::string& colorSpace);

    /// \brief Returns true if the specified color space name represents a
    ///        monochromatic color space.
    ///
    /// The method takes care of normalizing the color space before analyzing it.
    ///
    /// \param colorSpace the color space to test
    /// \return true if the normalized color space name represents a monochromatic
    ///         color space
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static bool isMonochrome(const std::string& colorSpace);

    /// \brief Returns true if the specified color space name contains additional
    ///        information that specifies that the pixels are subsampled
    ///        horizontally.
    ///
    /// \param colorSpace the color space to test for additional information about
    ///                   horizontal subsampling
    /// \return true if the color space name specifies that each pixel is
    ///              subsampled horizontally
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static bool isSubsampledX(const std::string& colorSpace);

    /// \brief Returns true if the specified color space name contains additional
    ///        information that specifies that the pixels are subsampled
    ///        vertically.
    ///
    /// \param colorSpace the color space to test for additional information about
    ///                   vertical subsampling
    /// \return true if the color space name specifies that each pixel is
    ///              subsampled vertically
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static bool isSubsampledY(const std::string& colorSpace);

    /// \brief Returns true if the specified color space name supports
    ///        subsampling information.
    ///
    /// \param colorSpace the color space to test
    /// \return true if subsampling information can be added to the specified color
    ///              space name
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static bool canSubsample(const std::string& colorSpace);

    /// \brief Add subsampling information to the specified color space name.
    ///
    /// \param colorSpace  the color space to which the subsampling information must
    ///                    be added
    /// \param bSubsampleX true if the pixels are subsampled horizontally
    /// \param bSubsampleY true if the pixels are subsampled vertically
    /// \return the specified color space name with additional information about
    ///         the pixels subsampling
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static std::string makeSubsampled(const std::string& colorSpace, bool bSubsampleX, bool bSubsampleY);

    /// \brief Returns the number of color channels necessary for the specified
    ///        color space.
    ///
    /// \param colorSpace  the color space name
    /// \return the number of color channels necessary to the specified color space
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static std::uint32_t getNumberOfChannels(const std::string& colorSpace);

    /// \brief Returns a Transform object able to transform an image's content from
    ///        one color space to another one.
    ///
    /// \param startColorSpace the color space of the input image's content
    /// \param endColorSpace   the color space of the output image's content
    /// \return a Transform object able to transform the image's content from
    ///         input color space to output one
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static Transform* getTransform(const std::string& startColorSpace, const std::string& endColorSpace);

};

}

#endif // imebraColorTransformsFactory__INCLUDED_
