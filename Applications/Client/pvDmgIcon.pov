#include "colors.inc"    // The include files contain
#include "shapes.inc"
#include "transforms.inc"
#include "textures.inc"
#include "math.inc"

#declare VARIANT_TEST=0;    // normal render (for testing)
#declare VARIANT_ALPHA=1;   // alpha render (for foreground)
#declare VARIANT_BKG=2;     // background render (for shadow color)
#declare VARIANT_SHADOW=3;  // shadow render (for shadow shape)

#ifndef (Variant)
  #declare Variant=VARIANT_TEST;
#end

// some dimensions
#declare boxw = 1.8;
#declare boxh = 0.8;
#declare boxd = 5.0;
#declare cornR = boxh/3;
#declare cornr = cornR/3;
#declare groveR = 0.3*cornr;
#declare slotPadd = 0.02;

// make camera positioning easier
#declare lookPt = <0,0,boxd/3>;
#declare camRad = 5.75;
#declare camAng = 60.5;

camera {
  right x
  location lookPt+camRad*<0,sind(camAng),-cosd(camAng)>
  look_at  lookPt
}

light_source {
  <1.1, 13, boxd*2.5>
  color White*0.6
  area_light
  1.2*x 2.2*z 4, 15
  jitter adaptive 1
}

global_settings { ambient_light White*1.5 }

plane { y, -0.0
  texture {
    pigment { color rgb 5 }
    #switch (Variant)
      #case (VARIANT_TEST)
      finish { ambient 0 diffuse 0.5 }
      #break
      #case (VARIANT_ALPHA)
      finish { ambient 0 diffuse 0.5 }
      #break
      #case (VARIANT_BKG)
      finish { ambient 0.05 diffuse 1.05 }
      #break
      #case (VARIANT_SHADOW)
      finish { ambient 0.05 diffuse 1.05 }
      #break
    #end
  }
#if (Variant = VARIANT_ALPHA)
  no_image
#end

}

// a box, centered on <0,0,0> and diagonal vector
// BoxDiag where the edges parallel to x are rounded
// with EdgeR
#macro SinglyRoundedBox( BoxDiag, EdgeR )
  #local w = abs(BoxDiag.x);
  #local h = abs(BoxDiag.y);
  #local d = abs(BoxDiag.z);
  #local Pt1 = <-w/2,-h/2,-d/2>;
  #local Pt2 = Pt1 + <w,h,d>;
  #local Cyl = cylinder {
    Pt1, Pt1 + x*w, EdgeR
  };
  union {
    box {
      Pt1 + z*EdgeR,
      Pt2 - z*EdgeR
    }
    box {
      Pt1 + y*EdgeR,
      Pt2 - y*EdgeR
    }
    object { Cyl translate<0,EdgeR,EdgeR> }
    object { Cyl translate<0,h-EdgeR,EdgeR> }
    object { Cyl translate<0,EdgeR,d-EdgeR> }
    object { Cyl translate<0,h-EdgeR,d-EdgeR> }
  }
#end

// The long edges (parallel to z) of the box
#declare longEdge = object {
  Round_Cylinder(
    <0,0,0>,
    <0,0,boxd>,
    cornR,
    cornr,
    true
  )
};

// the box
#declare roundedBox = union {
  object {
    longEdge
    translate <-boxw,cornR,0>
  }
  object {
    longEdge
    translate <boxw,cornR,0>
  }
  object {
    longEdge
    translate <-boxw,boxh-cornR,0>
  }
  object {
    longEdge
    translate <boxw,boxh-cornR,0>
  }
  object {
    SinglyRoundedBox( <2*boxw,boxh,boxd>, cornr )
    translate <0,boxh/2,boxd/2>
  }
  object {
    SinglyRoundedBox( <2*boxw,boxh,boxd>, cornr )
    translate <0,boxh/2,boxd/2>
  }
  object {
    SinglyRoundedBox( <boxh-2*cornR,2*(boxw+cornR),boxd>, cornr )
    rotate <0,0,90>
    translate <0,boxh/2,boxd/2>
  }
};

// for the grove we need a quarter torus
#declare quarterTorus = difference {
  torus {
    cornR
    groveR
  }
  box {
    1.1*<-cornR,-groveR,-cornR>
    1.1*<0,groveR,cornR>
  }
  box {
    1.1*<-0.1,-groveR,-cornR>
    1.1*<cornR,groveR,0>
  }
  rotate <-90,0,0>
}

// the grove
#declare grove = union {
  cylinder {
    <-1.01*boxw,boxh,1.5*cornR>
    < 1.01*boxw,boxh,1.5*cornR>
    groveR
  }
  cylinder {
    <-1.01*boxw,0,1.5*cornR>
    < 1.01*boxw,0,1.5*cornR>
    groveR
  }
  cylinder {
    <-boxw-cornR,0.99*cornR,1.5*cornR>
    <-boxw-cornR,boxh-0.99*cornR,1.5*cornR>
    groveR
  }
  cylinder {
    <boxw+cornR,0.99*cornR,1.5*cornR>
    <boxw+cornR,boxh-0.99*cornR,1.5*cornR>
    groveR
  }
  object {
    quarterTorus
    translate <boxw,boxh-cornR,1.5*cornR>
  }
  object {
    quarterTorus
    rotate <0,0,90>
    translate <-boxw,boxh-cornR,1.5*cornR>
  }
  object {
    quarterTorus
    rotate <0,0,-90>
    translate <boxw,cornR,1.5*cornR>
  }
  object {
    quarterTorus
    rotate <0,0,180>
    translate <-boxw,cornR,1.5*cornR>
  }
};

// the slot
#declare slot = box {
  <-0.85*boxw,0.35*boxh,0>
  < 0.85*boxw,0.65*boxh,3>
  texture { pigment { color rgbt<0,1,0,0.5> } }
};

// the padding in the slot
#declare slotPadding = object {
  SinglyRoundedBox(
    < 2, (0.65-0.35+2*slotPadd)*boxh, 2*(0.85+slotPadd)*boxw >,
    cornr
  )
  rotate <0,90,0>
  translate <0,boxh/2,0.99>
  texture { pigment { color Gray } }
};

// a single paraview logo stripe, with color stripeColor
#macro logoStripe( stripeColor )
  #local a = 3.742; #local h = 0.10;
  #local z2 = 9/10*3.2; #local z3 = 1/10*3.2;
  #local x2 = z2/a; #local x3 = z3/a;

  #local B11=<0+0.86,0,1*3.2>; #local B12=<1/3+0.86,0,1*3.2>; //
  #local B13=<2/3+0.86,0,1*3.2>; #local B14=<1+0.86,0,1*3.2>; // row 1

  #local B21=<0+x2,0,z2>; #local B22=<1/6+x2,h,z2>; //
  #local B23=<5/6+x2,h,z2>; #local B24=<1+x2,0,z2>; // row 2

  #local B31=<0+x3,0,z3>; #local B32=<1/6+x3,h,z3>; //
  #local B33=<5/6+x3,h,z3>; #local B34=<1+x3,0,z3>; // row 3

  #local B41=<0,0,0*3.2>; #local B42=<1/3,0,0*3.2>; //
  #local B43=<2/3,0,0*3.2>; #local B44=<1,0,0*3.2>; // row 4

  #local logoBasicPatch = bicubic_patch {
    type 1 flatness 0.001
    u_steps 4 v_steps 4
    B11, B12, B13, B14
    B21, B22, B23, B24
    B31, B32, B33, B34
    B41, B42, B43, B44
  };

  #local logoStripeBorder = object {
    logoBasicPatch
    pigment { color Black }
    scale <1,0.0000000001,1>
  };

  #local logoStripePatch = object {
    object { logoBasicPatch }
    scale <1-0.08/(B14.x-B11.x), 1, 1-0.08/(B11.z-B41.z)>
    translate <0.04,0,0.04>
  };

  union {
    object {
      logoStripePatch
      texture {
        pigment { color stripeColor }
      }
      finish {phong 0.6 phong_size 25 ambient 0.3}
    }
    object {
      logoStripeBorder
    }
  }
#end

// the full paraview logo
#declare logo = union {
  object{
    logoStripe( rgb<0.808,0,0.086> )
  }
  object{
    logoStripe( rgb<0.02,0.588,0.208> )
    translate <1.28,0,0>
  }
  object{
    logoStripe( rgb<0.024,0.231,0.533> )
    translate <2*1.28,0,0>
  }
};

// the full thing
#if ((Variant=VARIANT_ALPHA) | (Variant = VARIANT_TEST))
union {
  difference {
    object { roundedBox }
    object { grove }
    object { slotPadding }
    object { slot scale <1.01,1.01,1> }
    texture {
      Chrome_Metal
      //normal {
      //  bumps +0.01
      //  scale <0.0001,0.0001,0.0001>
      //}
      normal {
        bump_map {
          png "label.png"
          once
          bump_size -1.4
        }
        scale <3.9,1,1>*0.9
        rotate <90,0,0>
        translate <-0.97*boxw,boxh,boxd/9>
      }
    }
  }
  difference {
    object { slotPadding }
    object { slot }
  }
  object {
    logo
    scale 0.8
    translate<-0.97*boxw,boxh,boxd*2/6>
  }
}
#else
  // for the shadow only use the roundedBox with no_image attribute.
  // can't use the grove, because somehow povray doesn't like differences
  // when creating shadows for objects with no_image...
  object{ roundedBox no_image }
#end
