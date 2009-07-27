//=========================================================================
//
//  Program:   ParaView
//  Module:    $RCSfile: vtkVisibleLinesPainter_fs.glsl,v $
//
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.
//
//     This software is distributed WITHOUT ANY WARRANTY; without even
//     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//     PURPOSE.  See the above copyright notice for more information.
//
//=========================================================================
// Id: $Id: vtkVisibleLinesPainter_fs.glsl,v 1.1 2009-07-27 13:04:13 utkarsh Exp $


uniform sampler2D texDepth;
uniform vec2 uViewSize;
varying vec4 vColor;

const vec2 threshold = vec2(0.00001, 0.005);
void main (void)
{
  float surfaceDepth = texture2D(texDepth, gl_FragCoord.xy/uViewSize).x;
  
  // tolerance increases as depth increases, this ensures that the lines appear
  // smooth and continuous.
  float tolerance = threshold.x + (1.0 - gl_FragCoord.z) * (threshold.y - threshold.x);
  if (surfaceDepth+tolerance < gl_FragCoord.z)
    {
    discard;
    }
  gl_FragColor = vColor;
}
