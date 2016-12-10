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

/*! \file VOILUT.h
    \brief Declaration of the class VOILUT.

*/

#if !defined(imebraVOILUT__INCLUDED_)
#define imebraVOILUT__INCLUDED_

#include "transform.h"
#include "definitions.h"

namespace imebra
{

class DataSet;
class LUT;

///
/// \brief A VOILUT transform enhances the visibility of a specific range of
///        brightness in an image.
///
/// The client can use VOILUT in three ways:
/// - by declaring the minimum and maximum values of the pixels that must be
///   visible via the method setCenterWidth()
/// - by declaring a LUT via the method setLUT()
/// - by letting the transform calculate the most appropriate center/width
///   values via the method applyOptimalVOI()
///
/// The DataSet may already supply suitable values for the methods
/// setCenterWidth() and setLUT().
///
/// In order to retrieve from the DataSet the suggested center/width values,
/// call DataSet.getVOIs().
///
/// To get from the DataSet a list of LUTs that can be used with the VOILUT
/// transform use DataSet.getLUT(TagId(tagId_t::VOILUTSequence_0028_3010), X)
/// where X is a 0 base index (the DataSet may provide more than one LUT for
/// the VOILUT transform).
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API VOILUT: public Transform
{
    VOILUT(const VOILUT&) = delete;
    VOILUT& operator=(const VOILUT&) = delete;

public:
    /// \brief Constructor.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    VOILUT();

    virtual ~VOILUT();

    /// \brief Find the optimal VOI settings for a specific image's area and apply
    ///        it with setCenterWidth().
    ///
    /// \param inputImage   the image to analyze
    /// \param topLeftX     the horizontal coordinate of the top-left angle of the
    ///                     area to analyze
    /// \param topLeftY     the vertical coordinate of the top-left angle of the
    ///                     area to analyze
    /// \param width        the width of the area to analyze
    /// \param height       the height of the area to analyze
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void applyOptimalVOI(const Image& inputImage, std::uint32_t topLeftX, std::uint32_t topLeftY, std::uint32_t width, std::uint32_t height);

    /// \brief Set the VOI settings applied by the transform.
    ///
    /// \param center the VOI center
    /// \param width  the VOI width
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void setCenterWidth(double center, double width);

    /// \brief Set the LUT that will be used by the transform to enhance the
    ///        contrast.
    ///
    /// The LUTs to be used for the VOILUT transform are stored in the DataSet's
    /// sequence tagId_t::VOILUTSequence_0028_3010 (group 0x0028, tag 0x3010).
    /// Each item in the sequence stores a single LUT.
    ///
    /// Use DataSet::getLUT() to retrieve the LUT from the DataSet.
    ///
    /// \param lut  the LUT to apply
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void setLUT(const LUT& lut);

    /// \brief Retrieve the VOI center applied by the transform.
    ///
    /// \return the VOI center applied by the transform
    ///
    ///////////////////////////////////////////////////////////////////////////////
    double getCenter() const;

    /// \brief Retrieve the VOI width applied by the transform.
    ///
    /// \return the VOI width applied by the transform
    ///
    ///////////////////////////////////////////////////////////////////////////////
    double getWidth() const;


};

}

#endif // imebraVOILUT__INCLUDED_
