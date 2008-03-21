// Copyright 2008, Google Inc. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
//
//  1. Redistributions of source code must retain the above copyright notice, 
//     this list of conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//  3. Neither the name of Google Inc. nor the names of its contributors may be
//     used to endorse or promote products derived from this software without
//     specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
// EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef KML_DOM_POLYSTYLE_H__
#define KML_DOM_POLYSTYLE_H__

#include "kml/dom/colorstyle.h"
#include "kml/dom/kml22.h"
#include "kml/util/util.h"

namespace kmldom {

// <PolyStyle>
class PolyStyle : public ColorStyle {
 public:
  virtual ~PolyStyle();
  virtual KmlDomType Type() const { return Type_PolyStyle; }
  virtual bool IsA(KmlDomType type) const {
    return type == Type_PolyStyle || ColorStyle::IsA(type);
  }

  // <fill>
  bool fill() const {
    return fill_;
  }
  bool has_fill() const {
    return has_fill_;
  }
  void set_fill(bool fill) {
    fill_ = fill;
    has_fill_ = true;
  }
  void clear_fill() {
    fill_ = true;
    has_fill_ = false;
  }

  // <outline>
  bool outline() const {
    return outline_;
  }
  bool has_outline() const {
    return has_outline_;
  }
  void set_outline(bool outline) {
    outline_ = outline;
    has_outline_ = true;
  }
  void clear_outline() {
    outline_ = true;
    has_outline_ = false;
  }

 private:
  friend class KmlFactory;
  PolyStyle();
  friend class KmlHandler;
  virtual void AddElement(Element* element);
  friend class Serializer;
  virtual void Serialize(Serializer& serialize) const;
  bool fill_;
  bool has_fill_;
  bool outline_;
  bool has_outline_;
  DISALLOW_EVIL_CONSTRUCTORS(PolyStyle);
};

}  // end namespace kmldom

#endif // KML_DOM_POLYSTYLE_H__
