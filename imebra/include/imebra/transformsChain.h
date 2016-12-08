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

/*! \file transformsChain.h
    \brief Declaration of TransformsChain.

*/

#if !defined(imebraTransformsChain__INCLUDED_)
#define imebraTransformsChain__INCLUDED_

#ifndef SWIG

#include <memory>
#include "definitions.h"
#include "transform.h"

namespace imebra
{
namespace implementation
{
namespace transforms
{
class transformsChain;
}
}
}

#endif

namespace imebra
{

class DrawBitmap;

///
/// \brief The TransformsChain applies a series of Transforms to the input
///        image.
///
/// Transforms can be added to the chain by using addTransform().
///
///////////////////////////////////////////////////////////////////////////////

class IMEBRA_API TransformsChain: public Transform
{
    TransformsChain(const TransformsChain&) = delete;
    TransformsChain& operator=(const TransformsChain&) = delete;

public:
    /// \brief Constructor.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    TransformsChain();

    virtual ~TransformsChain();

    /// \brief Add a transform to the chain of transforms that will be applied to
    ///        the input image.
    ///
    /// \param transform the Transform to add to the chain of transforms
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void addTransform(const Transform& transform);
};

}

#endif // imebraTransformsChain__INCLUDED_
